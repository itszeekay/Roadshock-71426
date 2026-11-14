# ASR5601S application analysis

Image: `dumps/asr/asr_flash.bin`. The application occupies `0x10048000` to
`0x1005BA14`. The bootloader and BLE ROM are in the same image.

| File | Contents |
|---|---|
| `app_firmware.c` | application reconstruction, 346 functions in address order |
| `boot_firmware.c` | bootloader reconstruction, 101 functions |
| `app_index.md` | function index: peripherals, strings, calls |
| `app_symbols.md` | vector table and BL targets |
| `app_strings.md` | strings with addresses |
| `boot_symbols.md`, `boot_strings.md` | same for the bootloader |

## Method

- Dump read over SWD; the image was re-read over J3 alone and matched byte for
  byte; see [the J3 dump guide](../../docs/asr5601_dump.md).
- Ghidra 11.3.1, raw binary loader, language `ARM:LE:32:Cortex`.
  - application at `0x10048000`
  - bootloader at `0x10000000`
  - project `Asr5601s`, kept outside the public repository
- Annotations: `tools/ghidra/ApplyAsrNames.java` names the verified functions
  and seeds the application interrupt vectors. It currently names 72 of the 346
  application functions and 10 data objects; the remaining routines keep their
  `FUN_` names until their role is established.
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
- UART3 on P13/P14 at 115200 drives the LED display link; frame
  `5A 00 <6 bytes> EE` from `led_frame_send` at `0x100516D8`.
- P06/P07 are keypad columns in the application pin setup, which is why SWD
  stops working once the application starts.
- The UART0 RX callback stores bytes in a 32-byte ring buffer and publishes
  message `0x28`; `app_msg_dispatch` at `0x1004E1A0` handles app messages
  `0x28` to `0x37`, copies the received byte count and buffer pointer on
  `0x28`, and posts the frame as message `0x0B`.
- Outgoing frames go through `tx_frame_enqueue` at `0x1004FCF8` into a
  20-entry queue with a `sum8_checksum` at `0x1004F814`.
- Panel LED output is internal to the application. `all_leds_set` at
  `0x1004FE88` sends `0x11` (red) to all eight LEDs and starts the `all_leds_blink`
  loop at `0x1004FDF8`, which alternates all-off and all-red every 200 ms.
  `all_leds_flash_green` at `0x1004FE40` sends `0x55`. These run from app
  messages `0x34` to `0x36`, raised by the key handler; no base-link frame
  reaches them, and there is no per-channel flash.
- The keypad is a 4 by 4 matrix: columns P06/P07/P08/P09, rows P28/P25/P26/P29.
  Ten positions have buttons; `keypad_irq` at `0x1004DD24` reports row, column
  and pressed state.
- LED colour follows the mode index: state 0 to 3 stores nibble 1, 2, 5, 7.
  Visible colours are 1 red, 3 blue, 5 green, 7 yellow; `led_update` at
  `0x10051B04` alternates two nibble encoders.
- Advertising uses the template at `0x10059122`: `Controller8 Wired-XXXXXX`,
  with the last six characters taken from the BLE MAC.
- Bootloader `ASRBOOTLOADER-560X-MX-V2.0.2`, app
  `app-1.0.2-20240319.1000`, BLE stack `ASONATA_BLE_NONOS_V1.4.1`.

The wire frame is not length-prefixed. The count that `app_msg_dispatch` reads
on message `0x28` is the number of bytes that arrived in one burst, matching
the gap-delimited framing used by the base firmware.

## Open

- Runtime pin mux values for a definitive pinout.
- BLE service list; services are registered at runtime, so a live scan is needed.
- Programming the application region; only the ATE sector has been written so far.
