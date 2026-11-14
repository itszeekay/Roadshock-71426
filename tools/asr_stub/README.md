# ASR5601S RAM flash stub

A small bare-metal program that runs from RAM after the ROM monitor `boot`
command, copies the bootloader's flash routines into RAM, and erases and
programs one sector.

## Build

Uses the ARM GNU toolchain 5.4 2016q3 that the ASR SDK pins.

```bash
arm-none-eabi-gcc -mcpu=cortex-m0plus -mthumb -Os -nostdlib -nostartfiles \
  -fno-builtin -Wl,-T,link.ld -Wl,--gc-sections -o stub.elf main.c vectors.S
arm-none-eabi-objcopy -O binary stub.elf stub.bin
```

For an erase-only build, add `-DERASE_ONLY`.

The two `.bin` files in this directory are prebuilt payloads: `stub.bin` erases
and programs, `erase.bin` erases only. The `.elf` files are build artifacts and
are not tracked.

## Send

```bash
python tools/asr_ram_boot.py --payload tools/asr_stub/stub.bin --hexfile image.hex
```

Then, in the ROM monitor at 115200, with `SEL0` high:

1. send `AsrIot560x ` followed by CRLF
2. send `boot`
3. send `0x20010000`
4. send the image size as hex, for example `0x120`
5. send the image bytes

The monitor answers `1F2E3D04` and `1F2E3D05`, the stub runs, and the monitor
restarts.

## What it does

1. Copies `0x620` bytes from `0x10000120` to `0x20000000`.
2. Calls the flash init wrapper at `0x10004E70`.
3. Reads the lock state at `0x10004EC0` and unlocks at `0x10004EB0` if needed.
4. Erases the 4 KB sector at `0x100F0000` with `0x10004E80(0x2520, addr)`.
5. Unless `ERASE_ONLY` is set, programs 256 bytes with
   `0x10004E60(addr, 256, pattern)`.
6. Locks again if it unlocked, then resets through `AIRCR`.

## Tested

Run on the panel with the ATE partition at `0x100F0000`:

- the write build produced `a0 a1 a2 ... af` repeating for 256 bytes, verified
  over SWD;
- the erase-only build returned the sector to `0xFF`, verified over SWD.

The bootloader and application regions were never touched.

## Warning

The stub hard-codes the ATE address. Do not change `ATE_BASE` to an application
or bootloader address until the same test passes on the target region and you
have a verified backup.

## Standalone UART3 test

A variant was tried that initialized UART3 from the stub and sent display
frames with known nibbles, to check the color mapping without the base. It
faulted at `PC 0xFFFFFFFE` because the application's UART3 init calls into app
state that does not exist in the RAM-only context.

Use the panel's own UI instead: with the stock base connected, double-click
Mode on a channel and watch the indicator color. The mode order and the
nibbles are documented in `docs/asr5601_firmware.md`.

## Planned: dump stub

A read-side equivalent of this stub, not yet written or tested:

1. Runs from RAM through the ROM monitor `boot` command.
2. Reads `0x10000000` to `0x100FFFFF` directly; the flash is memory-mapped.
3. Formats the bytes as ASCII hex and prints them through the ROM monitor's
   print routine at `0x000009B0`, so it uses the monitor's own 115200 UART.
4. The host captures the text and rebuilds the binary.

At 115200 the text is about 2 MB, so expect several minutes. Validate it on a
unit that also has a SWD dump and compare SHA-256 before trusting it on an
unknown variant.

This is the piece that would make J3-only workflows complete. Flash erase and
program over J3 are already proven.
