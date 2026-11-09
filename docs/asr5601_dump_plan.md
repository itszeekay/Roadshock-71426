# ASR5601S dump plan

MCU: **ASR5601S** (QFN-48) — button panel main controller. This plan dumps the ASR, not either STM8S003.

Status: Phase 0 is complete. The protocol is known well enough to run on the
bench, but nothing has been read from the ASR yet. The remaining unknowns are
behavioral, not structural:

1. Does the ASR5601S download monitor accept `coredump flash all`?
2. Does the stream use the `:<label><hex>$` framing that DOGO parses?

Both are answered with non-destructive traffic.

## What Phase 0 established

The DOGO tool is a Python 3.5 PyInstaller build. Its entry module is
`pyserial_demo.pyc`; its chip database is `data.pyc` inside `PYZ-00.pyz`.
The database contains an explicit `5601S` entry, so `config/config.ini` is
**not** required for the ASR part. The tool's default `config.ini` only stores
language and last-used file paths; missing it produces a dialog, not a missing
chip table.

Key values from the embedded `5601S` entry:

| Item | Value |
|---|---|
| Handshake string | `AsrIot560x` (ASCII, sent with a trailing space, no CRLF) |
| Bench default baud | 115200 (manual) |
| Entry high-speed baud | 921600 (chip table) |
| Bootloader base | `0x10000000` |
| BLE ROM base | `0x1000D000` |
| App base | `0x10048000` |
| ATE base | `0x100F0000` |
| OTA tag address | `0x10008000` |
| Bootloader size | 32768 bytes |

What the code actually does:

- `update_bootloader` sends `b"AsrIot560x "` once and waits for `3D00` in the
  reply.
- `data_receive` treats any reply containing `3D00` as "download mode ready".
- The prompt string in the binary is `welcome to download\r\n>>>`.
- Commands are ASCII with CRLF. The host builds `get_chip_type`,
  `init <baud>`, `erase <addr> <size>`, `burn <addr> <size>` and
  `boot <type> <size>`.
- `get_chip_type` is answered with `CT:` followed by a hex chip ID.
- `read_image` is a host capture flag, not a device command. `data_receive`
  appends everything to `flash_image_data.txt`, and `gen_flash_bin` parses
  `$<hex>$` blocks into `flash_image_bin.bin`.
- The separate coredump capture parses `:<10-char label><hex>$` lines and writes
  one `.bin` per label under `recev_data/coredump/`.

The read command itself is documented by ASR, not hardcoded in DOGO. The
ASR582X FAQ says:

> create `recev_data/coredump`, check Coredump and ReceiveFile, enter
> `coredump flash all`, wait for completion, then collect the bin files.

That is the command this plan uses. It is documented for the same DOGO tool and
the same UART1 monitor, but it has not been proven on the 5601S.

The layout note from ASR's public 560X transparent-transmission image confirms
the flash bootloader is `ASRBOOTLOADER-560X-MX-V2.0.3` and that `COREDUMP` is a
partition name. ASR publishes the image, which contains the bootloader, BLE ROM
and app. The image contains no CLI command strings, which suggests the `>>>`
monitor and its commands live in mask ROM, not in the flash bootloader. If the
ROM monitor does not implement `coredump flash all`, the fallback is the same
command to the running app on UART1.

## Exact traffic

Bench bring-up, download mode:

| Direction | Bytes | Notes |
|---|---|---|
| chip to host | `1F2E3D00` | printed after reset when SEL0 is high |
| host to chip | `\r\n` | optional, asks for the prompt |
| chip to host | `welcome to download\r\n>>>` | text monitor is ready |
| host to chip | `get_chip_type\r\n` | identity check |
| chip to host | `CT:0x...` | chip ID |
| host to chip | `coredump flash all\r\n` | the read request |
| chip to host | `:<label><hex>$` lines | one line per block |

The host does not need to send the `AsrIot560x ` handshake if the banner already
arrived. DOGO sends it before a burn; its role outside that flow is not
documented.

The label is ten characters in DOGO's parser. `0x10000000` is ten characters,
so the likely shape is `:0x10000000<hex>$`. The parser accepts any ten-character
label and groups by label, so a partition name works too.

## Hardware

Already available:

| Item | Use |
|---|---|
| Feather RP2040 DVI (CircuitPython) | UART bridge to J3, appears as a COM port, handles 921600 |
| ST-Link V2 | SWD fallback only |
| 12 V bench supply | run the panel as built |
| Multimeter | continuity on PZ20 and J2 |
| Scope | optional, verify idle levels |

Still needed:

| Item | Why | Notes |
|---|---|---|
| 6-pin header or pogo block for J3 | the only physical connection required | measure the pitch first; the J3 pads look about 1.27 mm, not 0.1 inch. A 6-pin pogo strip held by hand is enough for a read-only session |
| Dupont jumpers, 3.3 V | J3 to bridge | five wires: TX, RX, GND, RST, SEL0. Leave J3 +3.3 unconnected if the panel is powered |
| CP2102 or FT232 USB-UART | alternative to the Feather | avoid CH340 at 921600; DOGO's high mode drops frames on it |
| 0.1 to 0.2 mm magnet wire and a fine iron | SWD only, and only if PZ20 fails | 0.4 mm pitch, three wires |

No level shifting. The ASR is a 3.3 V part here. No flash clip, socket or decap.

## Phase 0: static work (done)

Deliverables:

| File | Contents |
|---|---|
| `reference/asr560x/drive/DOGO_extract/dump_path.dis.txt` | annotated disassembly of the receive and bin-generation path |
| `reference/asr560x/drive/DOGO_extract/pyserial_demo.pyc` | entry module |
| `reference/asr560x/drive/DOGO_extract/data.pyc` | embedded chip database, added with this phase |
| `reference/asr560x/drive/DOGO_extract/chip_table.txt` | readable dump of the chip entries |
| `tools/asr5601_dump.py` | read-only probe, capture and parser |
| `tools/asr5601_fake_monitor.py` | socket-backed test monitor |
| `tools/extract_pyz.py` | reproducible PYZ extraction helper |

The parser handles both stream shapes: `:<label><hex>$` and `$<hex>$`. It
rebuilds a flat `flash.bin` when every label is an eight-digit address, fills
gaps with `0xFF`, writes `flash.hex`, and writes a `SHA256SUMS` file for all
generated images.

The full path has been exercised on the desk against
`tools/asr5601_fake_monitor.py`, a socket-backed monitor that speaks the same
banner, commands and frame shape. That test covers the link, the command
sequence, the parser and the flat-image rebuild. It does not prove anything
about the real chip.

## Phase 1: handshake on the bench, non-destructive

1. Power the panel and disconnect J2 so the base's STM8 cannot drive the line.
2. Wire J3: `TX` to bridge RX, `RX` to bridge TX, `GND` to GND, `RST` and
   `SEL0` to two free GPIOs. Do not connect +3.3.
3. Check the idle level on J3 TX, about 3.3 V, before connecting anything.
4. Start at **115200 8N1**. Assert `SEL0 = 1` (pad P00), pulse `RST` low,
   release. `SEL1` (P01) has no pad and its internal pull-down holds it at 0,
   which is the required download strap. Allow for the datasheet's 8 ms startup
   delay after VBATB reaches 1.7 V; the probe already waits longer.
5. Run `python tools/asr5601_dump.py --port COM7 --probe`.
6. If there is no banner, rerun with `--baud 921600` and repeat.
7. Stop if the only reply is silence. Do not send anything but the probe
   commands.

`1F2E3D00` proves the electrical path and the monitor. `1F2E3D81` means a
communication error: check wiring, then baud.

Exit criterion: `1F2E3D00` and the `>>>` prompt received.

## Phase 2: probe the text prompt

1. Send a bare CRLF. Expect `welcome to download\r\n>>>`.
2. Send `get_chip_type`, then `help`, then `?`, one at a time.
3. Capture the replies verbatim. Do not paste a script.
4. Do not send anything containing `erase`, `burn`, `boot` or `write`.
5. Record whether the monitor lists a read or dump verb.

Exit criterion: the command vocabulary, or clear evidence that the monitor has
no help text.

## Phase 3: first read

Run:

```
python tools/asr5601_dump.py --port COM7 --baud 115200 --dump dumps/asr
```

The tool sends the read command `coredump flash all\r\n` after the monitor is
awake; before that it may send the handshake or a bare CRLF. It captures until
the line has been idle for ten seconds, retries once if nothing arrives, writes
the raw text, then parses it.

Order of attempts:

1. Download monitor at 115200, `coredump flash all`.
2. If rejected or silent, the same at 921600.
3. If the monitor has no such command, boot the app (`SEL0 = 0`), open UART1 at
   115200 (or the app's log baud), and send `coredump flash all` again.

A plausible first block has a stack pointer around `0x2000xxxx` and a reset
vector into flash. A block of all `0xFF` means the wrong region or a protected
region.

If the first block looks right, read the full part twice, in separate power
cycles, to two directories. The read streams the whole part. The ASR560X family
ships with 1 MB or 512 KB of flash; if a 512 KB part returns a 1 MB image with a
`0xFF` tail, trim the tail.

Exit criterion: two captures whose parsed `flash.bin` files are the same size
and have identical SHA-256, covering the full part.

## Phase 4: verify and archive

1. Compare the two reads. Any difference means retry; do not rationalize it.
2. Check the vector table at `0x10000000` and carve the partitions using
   `docs/asr5601_reference_archive.md`, the Memory Layout page, and the
   peripheral map in `docs/asr5601_datasheet.md`. The offsets have not been
   confirmed on hardware yet. The layout note from ASR's public test image
   confirms the same boundaries on a known-good build; see
   `reference/asr560x/drive/ASR560X_test_image_layout.md`.
3. Run a string scan for BLE names and UUIDs to confirm this is real code and
   not `0xFF` padding. Then scan for accesses to UART2 (`0x4000_2000`), UART3
   (`0x4001_8000`), KEYPAD (`0x4001_5000`) and GPIO (`0x4003_0000`) to identify
   the display link and button scan pins.
4. Commit `dumps/asr/flash.bin`, `.hex`, `SHA256SUMS` and a short
   `dumps/asr/README.md`. Exclude the ASR BLE stack ROM range if the dump is
   published.

Exit criterion: a committed, reproducible image. Only then does the ASR become
flashable, and it still has no factory restore file.

## Phase 5: SWD fallback

Only if Phases 2 and 3 fail.

1. Board unpowered. Beep J3 TX against the PZ20 pads. If it beeps, PZ20 is on
   the ASR side; map all six pads.
2. Beep PZ20 against QFN pins 36 and 37. If either connects, SWD costs a wire,
   not a rework.
3. OpenOCD with the ST-Link: `cortex_m` target, connect-under-reset,
   `dump_image asr.bin 0x10000000 0x100000` for the 1 MB part, or `0x80000` for
   the 512 KB part.
4. If reads return zeros or fault, the debug port is locked. Stop. That is
   decap territory and out of scope.

## Decision table

| Situation | Call |
|---|---|
| No banner at 115200 | try 921600, then swap TX/RX, then check SEL0 and reset |
| Banner but no prompt | send CRLF; if still silent, send `AsrIot560x ` and read again |
| `coredump flash all` echoes but no data | wait longer; the dump may be slow, then retry at 921600 |
| Monitor rejects `coredump` | boot the app and send the same command on UART1 |
| Capture has `:<label><hex>$` | normal; the tool rebuilds `flash.bin` |
| Capture has only `$<hex>$` | normal for the ReadImage path; the tool writes `readimage.bin` |
| Read returns all `0xFF` | wrong base address or a protected region; try the app base `0x10048000` |
| Read is clean for 512 KB, then all `0xFF` | the part is the 512 KB version; trim the tail |
| Only one clean read, second differs | treat it as no dump; the ASR has no restore image |
| SWD locked, UART has no read | stop and reassess; no cheap path left |
| CLI help lists erase but no read | do not experiment with erase; the restore image does not exist |

## Definition of done

Two byte-identical full-flash images, their SHA-256, a carved partition map, and
a note in `docs/` describing exactly how they were read. That matches the
standard used for the STM8 dumps.

Phases 1 to 3 are an afternoon if the monitor accepts the command. If it does
not, Phase 5 is a short detour only when PZ20 reaches the SWD pads.

## Risks

- There is no factory restore image for the ASR. Do not run `Flash Erase` or
  `Burn` before a verified dump exists.
- The text monitor commands are destructive by nature. Type one command at a
  time and read the echo. The host tool refuses anything containing erase, burn,
  boot, write or program.
- `coredump flash all` is documented for the 582X family. Treat it as a strong
  candidate for the 5601S, not as a confirmed command. It is described as a
  capture, not an erase. If the monitor prints an erase or write message, stop
  and power down.
- The ASR560X datasheet is still gated, so the memory map comes from the
  Peripheral User's Guide, the Memory Layout page and the binary constants.
