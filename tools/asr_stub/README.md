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
