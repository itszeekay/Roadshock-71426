# ASR5601S application analysis

Image: `dumps/asr/asr_flash.bin`. The application occupies `0x10048000` to
`0x1005BA14`. The bootloader and BLE ROM are in the same image.

| File | Contents |
|---|---|
| `app_firmware.c` | application reconstruction, 360 functions in address order |
| `boot_firmware.c` | bootloader reconstruction, 101 functions |
| `app_index.md` | function index: peripherals, strings, calls |
| `app_symbols.md` | vector table and BL targets |
| `app_strings.md` | strings with addresses |
| `boot_symbols.md`, `boot_strings.md` | same for the bootloader |

## Method

- Dump read over SWD; see [the SWD dump guide](../../docs/asr5601_swd_dump.md).
- Ghidra 11.3.1, raw binary loader, language `ARM:LE:32:Cortex`.
  - application at `0x10048000`
  - bootloader at `0x10000000`
  - project `Asr5601s`, kept outside the public repository
- Annotations: `tools/ghidra/ApplyAsrNames.java` names the verified functions
  and seeds the application interrupt vectors.
- Decompile: `tools/ghidra/DecompileTree.java` writes one file per function.
- Concatenation: `tools/build_asr_reconstruction.py` builds the two `.c` files.
- Cross-check: `tools/asr_disasm.py` produces the capstone listings, which are
  working files and are not tracked.

The per-function decompiler output and the Ghidra project stay out of the
public repository, the same rule used for the STM8 reconstructions.

## What is confirmed

- Reset at `0x1004AEFC`, main at `0x10056EC8`.
- The app copies an image from `0x10059118` to RAM at `0x20000800`; many
  `0x10056E..` symbols are veneers into that RAM copy.
- UART0 on P02/P03 at 2400 is the base board link.
- UART1 on P04/P05 at 921600 is the log and console, broken out on J3.
- UART3 on P06/P07 drives the LED display link; frame `5A 00 <6 bytes> EE`
  from `led_frame_send` at `0x100516D8`.
- The UART0 RX callback stores bytes in a 32-byte ring buffer and publishes
  event `0x28`; `base_link_byte_handler` at `0x1004E1A0` treats the first byte
  as a length and posts message `0x0B`.
- Bootloader `ASRBOOTLOADER-560X-MX-V2.0.2`, app
  `app-1.0.2-20240319.1000`, BLE stack `ASONATA_BLE_NONOS_V1.4.1`.

## Open

- Whether the wire frame is length-prefixed ahead of the 11-byte frame.
- Button scan pins and the mode, long-press and double-click rules.
- The LED color table behind `0x10051734` and `0x1005187C`.
- Runtime pin mux values for a definitive pinout.
- BLE advertising name and services.
