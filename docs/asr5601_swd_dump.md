# ASR5601S SWD dump

How to read the ASR5601S SiP flash over SWD with an ST-Link. This is the
fallback path in [asr5601_dump_plan.md](asr5601_dump_plan.md); the UART paths
are documented there and are not usable on this unit.

The procedure is read-only. It sends `init`, `halt`, `mdw` and `dump_image`
and nothing else.

## What you need

| Item | Notes |
|---|---|
| ST-Link V2 | any common clone works, firmware V2J24 or newer |
| OpenOCD 0.12 | `winget install xpack-dev-tools.openocd-xpack` |
| Two fine wires | soldered to QFN pins 36 and 37 |
| Ground wire | any board ground |
| 3.3 V feed to J2 | the panel powers itself |

## Wiring

| ST-Link pin | Panel connection |
|---|---|
| `SWCLK` | U1 pin 37, `P06` |
| `SWDIO` | U1 pin 36, `P07` |
| `GND` | board ground |
| `3.3V` (VTREF) | board 3.3 V rail, sense only |

Pin 1 of U1 is the dot at the top-left corner. Pins 37 and 36 are the
top-right corner: 37 is the last pad on the top edge, 36 is the first pad down
the right edge.

Do not power the panel from the ST-Link. The panel gets 3.3 V through J2 and
the ST-Link only senses that rail.

## Step 1: prepare the target

1. Solder the wires with the panel unpowered.
2. Check continuity from each wire to its QFN pin, and check that the two
   wires do not short to each other or to ground.
3. Power the panel through J2.
4. Check the idle level on both wires. Both should sit near 3.3 V.

The ASR application may reassign `P06` and `P07`, which would remove SWD after
boot. Two ways to avoid that:

- Attach quickly after a power cycle, before the application starts.
- Or fit the `SEL0` to `+3.3` jumper and power-cycle, which leaves the chip in
  the ROM download monitor and keeps the application from running.

## Step 2: probe the debug port

```bash
python tools/asr5601_swd_dump.py --probe
```

A working connection prints a program counter, the first words at
`0x10000000`, and:

```
RESULT: debug port open and memory readable.
```

If OpenOCD reports an IDCODE mismatch, the wiring or the power is wrong. If it
reports no device, the ST-Link is not visible over USB.

## Step 3: read the flash

```bash
python tools/asr5601_swd_dump.py --dump dumps/asr --twice --trim
```

This reads 1 MB from `0x10000000` twice, compares the SHA-256, writes
`SHA256SUMS`, and writes a trimmed copy if the tail is all `0xFF` (the 512 KB
part).

For a 512 KB part:

```bash
python tools/asr5601_swd_dump.py --dump dumps/asr --size 512k --twice
```

The same read by hand:

```bash
openocd -f interface/stlink.cfg -f tools/openocd/asr5601_swd.cfg \
  -c "adapter speed 100" -c "init" -c "halt" \
  -c "dump_image dumps/asr/asr_flash.bin 0x10000000 0x100000" \
  -c "shutdown"
```

## Step 4: verify the image

1. The two reads must have the same SHA-256. Any difference means retry.
2. The vector table at `0x10000000` should hold a stack pointer near
   `0x2000xxxx` and a reset vector that points into flash.
3. A string scan should find BLE names, UUIDs and readable code, not just
   `0xFF` padding.

Then carve the partitions with
[asr5601_reference_archive.md](asr5601_reference_archive.md) and the memory
layout note in `reference/asr560x/drive/ASR560X_test_image_layout.md`.

## Troubleshooting

| Symptom | Cause | Action |
|---|---|---|
| `openocd not found` | not installed | `winget install xpack-dev-tools.openocd-xpack`, then reopen the shell |
| IDCODE mismatch | wiring, ground, or target power | recheck continuity and the 3.3 V rail |
| No device found | ST-Link USB or driver | try another port, check Device Manager |
| IDCODE reads, `0x10000000` does not | read protection | stop; the flash is locked |
| Read returns all `0xFF` | wrong base address or locked region | confirm `0x10000000`, then stop |
| Only works at 100 kHz | long wires or series parts | keep 100 kHz; speed is not needed |
| Two reads differ | signal integrity or power | lower the speed, shorten wires, retry |
| Cannot halt after boot | app reassigned `P06`/`P07` | use the `SEL0` jumper and a power cycle |

## What the image contains

| Offset | Address | Size | Contents |
|---|---|---|---|
| `0x00000` | `0x10000000` | 32 KB | bootloader |
| `0x0D000` | `0x1000D000` | | BLE ROM |
| `0x48000` | `0x10048000` | | application |
| `0xF0000` | `0x100F0000` | | ATE |

Offsets are from the ASR test image layout and have not been confirmed on this
panel yet.

## Safety

- Never send `erase`, `burn`, `boot` or `program`. There is no factory restore
  image for this chip.
- Keep the panel on its own 3.3 V supply.
- If the debug port is locked, stop. Decapsulation is out of scope.
