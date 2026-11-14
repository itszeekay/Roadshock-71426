# ASR5601S dump

Record of what was needed and what happened while reading the ASR5601S flash.
The result is in [`dumps/asr/`](../dumps/asr/); the procedure is in
[asr5601_swd_dump.md](asr5601_swd_dump.md); the firmware analysis is in
[asr5601_firmware.md](asr5601_firmware.md).

## Result

| Item | Value |
|---|---|
| Image | 1 MB from `0x10000000` |
| SHA-256 | `b7b92dab982a262b6e2dc295bf7b2781ce070091b58d6b82c5a0596a9ba163fb` |
| Reads | two, byte-identical |
| Programmed content | `0x00000` to `0x5BA14`, then `0xFF` |
| Bootloader | `ASRBOOTLOADER-560X-MX-V2.0.2` |
| BLE stack | `ASONATA_BLE_NONOS_V1.4.1` (`rom-asr-1.00`) |
| Application | `app-1.0.2-20240319.1000` |

Layout:

| Offset | Contents |
|---|---|
| `0x00000` | bootloader |
| `0x08000` | OTA tag |
| `0x0A000` | NVDS, tag only |
| `0x0C000` | coredump area, empty |
| `0x0D000` | BLE stack ROM |
| `0x48000` | application |
| `0xF0000` | ATE partition, blank |

## Why SWD first, and why J3 is enough now

SWD was used for the first read for one reason: at that point there was no way
to read bulk flash over UART. The ROM monitor has no read command, and the
application console rejects text. SWD gave a fast, verified 1 MB image, which
was required before any write, because the part has no factory restore file.

That constraint no longer applies. The monitor can load a RAM image with
`boot`, and a RAM stub runs with full access to the chip. The write path was
proven over J3 alone: erase and program of the ATE sector, verified by
read-back.

So for any future unit, including another variant of this panel, the intended
minimum connection is **J3 only**:

| J3 pad | Use |
|---|---|
| `GND` | common ground |
| `+3.3` | sense only, the panel powers itself |
| `TX` / `RX` | ROM monitor at 115200 |
| `SEL0` | held high to enter the monitor |
| `RST` | not used; the strap is sampled at power-on, so a power cycle replaces it |

The sequence is: hold `SEL0` high, power-cycle, talk to the monitor at 115200,
then `boot` a RAM stub for whatever is needed.

Status of each operation over J3 alone:

| Operation | Status |
|---|---|
| Enter the ROM monitor | proven |
| Read and write single words (`rdreg`, `wrreg`) | proven |
| Run a RAM stub (`boot`) | proven |
| Erase and program flash | proven on the ATE sector |
| Full flash dump | designed, not yet exercised: a RAM stub reads the whole part and streams it over UART1 |

A J3-only dump is slower than SWD, because it shares the 115200 monitor link,
but it removes the soldering step. SWD remains the faster fallback and the
method used for the verified image in `dumps/asr/`.

## What was required

| Item | Use |
|---|---|
| Panel powered at 3.3 V through J2 | the panel powers itself; no base board |
| ST-Link V2 | SWD adapter, firmware V2J24 or newer |
| Two fine wires | soldered to the vias on the traces from U1 pins 36 and 37 |
| Ground wire | board ground |
| Jumper | J3 `SEL0` to J3 `+3.3`, to stay in the ROM monitor |
| Multimeter | continuity and idle level checks |
| OpenOCD 0.12 | `winget install xpack-dev-tools.openocd-xpack` |
| Python 3 | `tools/asr5601_swd_dump.py` |

## What happened with the UART first

The panel's J3 header is the ASR's UART1, and on this firmware UART1 is a
921600 log port. The 2400 base link is a different UART (UART0 on P02/P03), so
J3 never carried the product protocol.

Bench results:

| Link | Result |
|---|---|
| ROM monitor, `SEL0` high, 115200 | prints `1F2E3D00`; accepts `init`; rejects `get_chip_type`, `help`, `version` and `coredump` with status `87` |
| Application console, `SEL0` low, 921600 | answers `ERROR` to every text command tried, including bare CRLF |

The ROM monitor implements `init`, `boot`, `wrreg` and `rdreg`, with no bulk
flash read command. The application console rejects all text input. That closed
the bulk UART read path.

The read command `coredump flash all` comes from ASR's ASR582X FAQ and is issued
on the application's UART1 log port. It was tried on both links here and was
not accepted.

## Bench findings that changed the approach

- The J3 pad labeled `RST` is not the ASR reset. With the wire off it reads
  0 V and has no pull-up, unlike `RSTN` pin 44. No reset wire was used.
- The J3 pad labeled `SEL0` is the real boot strap. Tying it to `+3.3` stops
  the application from starting, which is how the ROM monitor was reached.
- P06 and P07 are SWD at reset. The application repurposes them in its pin
  setup, so SWD only works while the application is not running, which the
  `SEL0` strap guarantees. The display link is not involved; UART3 is on
  P13/P14.
- `PZ20`, previously assumed to be a possible SWD header, is a 6-pin part
  marked `331`, a 330 ohm resistor network. It has no continuity to pins 36 or
  37. The SWD wires go to the vias on those two traces.
- ST-Link reports target voltage 3.2 V and DPIDR `0x0bc11477` (Cortex-M0+ r0p1).
  Adapter speed settles at 950 kHz. A full 1 MB read takes about 48 seconds.

## Vendor tool notes

The DOGO tool is a Python 3.5 PyInstaller build. Its embedded chip table has an
explicit `5601S` entry:

| Item | Value |
|---|---|
| Handshake | `AsrIot560x` (ASCII, trailing space, no CRLF) |
| Entry baud | 921600 |
| Bootloader base | `0x10000000` |
| BLE ROM base | `0x1000D000` |
| App base | `0x10048000` |
| ATE base | `0x100F0000` |
| OTA tag address | `0x10008000` |
| Bootloader size | 32768 bytes |

The host side parses `:<10-char label><hex>$` lines for the coredump path and
`$<hex>$` blocks for the read-image path. None of that applies here.

The ROM monitor itself was dumped later. It implements only `init`, `boot`,
`wrreg` and `rdreg`, with a line protocol. `rdreg` and `wrreg` give 32-bit read
and write to almost any address over J3 alone. `boot` loads a RAM image and
jumps to it. The details are in [asr5601_monitor.md](asr5601_monitor.md).

## What is still open

- Application region programming. Erase and program are proven on the ATE
  sector; the same stub has not been pointed at the application region yet.
- Runtime pinout: read `0x40110068` to `0x40110074` after pin mux init.
- BLE services: the advertising name is known, the service list needs a live
  scan.

There is no factory restore image for this chip. The verified dump in
[`dumps/asr/`](../dumps/asr/) is the restore path, so do not erase or program
anything with an untested image.
