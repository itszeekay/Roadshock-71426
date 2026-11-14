# ASR5601S application analysis

Image: `dumps/asr/asr_flash.bin`. The application occupies `0x10048000` to
`0x1005BA14`. Bootloader and BLE ROM are in the same image.

## Ghidra

Ghidra 11.3.1, raw binary loader, language `ARM:LE:32:Cortex` (Thumb).

| Program | Base | Functions | Output |
|---|---|---:|---|
| `app.bin` | `0x10048000` | 324 | `decomp/` |
| `boot.bin` | `0x10000000` | 100 | `decomp_boot/` |

Script: `tools/ghidra/DecompileTree.java`. Each file is named
`<address>_<name>.c`.

`app.lst`, `app_symbols.md` and `app_strings.md` come from
`tools/asr_disasm.py` and are the capstone cross-check.

## Reset path

| Item | Value |
|---|---|
| stack top | `0x20005000` |
| reset | `0x1004AEFD` |
| reset handler | `0x1004AEFC` |
| main | `0x10056EC8` |

The handler writes `0x40110084`, copies an init image from `0x10059118` to
`0x20000800`, zero-fills the rest, then calls `0x1004B008` and main.

Many `0x10056E..` entries are veneers that branch into RAM (`0x2000xxxx`). The
real code for those is the copy at `0x10059118`.

## Display link is UART3

| Item | Value |
|---|---|
| peripheral | UART3, base `0x40018000` |
| frame builder | `0x100516D8` |
| frame | `5A 00 <six bytes> EE` |
| sender | `0x1004E888` -> `0x1004C5AC` |
| log strings | `IND DATA SEND:` and `%02x ` |

The application reassigns P06/P07 at boot, which is why SWD only worked in the
ROM monitor. P06/P07 is the UART3 TX/RX pair in the datasheet pin mux, so the
display link and the SWD pins are the same two pins.

## Pin mux

| Item | Value |
|---|---|
| pin mux setter | `FUN_1004c918(pin, class)` |
| pin mux registers | `0x40110068` to `0x40110074`, 4 bits per pin |
| flash table | `0x100573B0`, one word per pin |

Values in the flash table: P00 = 5, P01 = 5, P06 = 8, P07 = 8, all other pins 0.

Calls found in the listing, grouped by the second argument:

| Pins | Value |
|---|---|
| P02, P03 | 13 |
| P04, P05 | 14 |
| P08, P09, P25, P26, P28, P29 | 12 |
| P10, P15, P16, P22, P24 | 3 |
| P13, P14 | 16 |
| P06, P07 | 8 in the flash table |

The second argument is a configuration class, not the `Func=0..4` column in the
datasheet pin table, so the names cannot be assigned from the static data alone.
A definitive pinout needs a runtime read of `0x40110068` to `0x40110074`.

## Runtime pinout plan

1. Hold `SEL0` high, power-cycle, attach SWD in the ROM monitor.
2. Drive `SEL0` low.
3. `reset halt` through SYSRESETREQ. The core stops at the app reset vector
   while P06/P07 are still SWD.
4. Set a breakpoint after the pin mux init and resume.
5. Read `0x40110068` to `0x40110074` and the GPIO direction registers, then
   decode 4 bits per pin.

This avoids relying on the app to leave SWD alive, which it does not.

## Flashing over J3

The ROM download monitor is the flashing interface. It accepts `init`, `erase`,
`burn` and `boot`, and `init` was confirmed live on the bench. DOGO drives the
same command set.

We now hold a verified full image, so the main risk that blocked writes is gone.

A safe end-to-end test, without touching the boot image:

1. Enter the ROM monitor (`SEL0` high, power cycle).
2. Burn a small pattern into the blank ATE partition at `0x100F0000`.
3. Power-cycle into the ROM monitor and read the partition back over SWD.
4. If the pattern matches, erase the partition back to `0xFF`.

That proves the write path on a region that cannot brick the panel. Do not
erase the bootloader or the application until that test passes.
