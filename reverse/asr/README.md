# ASR5601S application analysis

Image: `dumps/asr/asr_flash.bin`. The application occupies `0x10048000` to
`0x1005BA14`. Bootloader and BLE ROM are in the same image.

Method: linear Thumb disassembly with `tools/asr_disasm.py` (capstone). This is
a first pass; control flow is not rebuilt yet.

| File | Contents |
|---|---|
| `app.lst` | linear listing of the application |
| `app_symbols.md` | vector entries and BL targets |
| `app_strings.md` | strings with addresses |

## Reset path

| Item | Value |
|---|---|
| stack top | `0x20005000` |
| reset vector | `0x1004AEFD` |
| reset handler | `0x1004AEFC` |
| main | `0x10056EC8` |

The reset handler writes `0x40110084`, copies an init image from `0x10059118`
to `0x20000800`, zero-fills the remaining RAM ranges, calls `0x1004B008`, then
calls `0x10056EC8` and loops forever.

Many entries in the `0x10056E..` region are veneers that branch into RAM, for
example `0x10056EC8` jumps to `0x20000FF8`. The RAM copy at `0x10059118` holds
the real code for those. Static analysis of RAM-resident functions must read
the source image at `0x10059118`, not the veneer.

## Display link is UART3

| Item | Value |
|---|---|
| peripheral | UART3, base `0x40018000` |
| frame builder | `0x100516D8` |
| frame format | `5A 00 <six bytes> EE` |
| sender | `0x1004E888` writes the buffer to UART3 through `0x1004C5AC` |
| log strings | `IND DATA SEND:` at `0x10058604`, `%02x ` at `0x10057653` |

The builder copies six bytes from its input into frame bytes 2 to 7 and appends
`0xEE`. That matches the documented 9-byte display frame. The input is the six
bytes produced by the LED logic.

UART1 (`0x40001000`) and UART2 (`0x40002000`) are also configured nearby, at
`0x1004B2D0` onward. UART1 is the 2400-baud base link per the earlier captures.

## SWD and the display link

The application disables SWD on P06/P07 after boot. UART3 can be mapped to
P06/P07, and that is the most likely reason. Confirm by continuity from the
panel STM8 `PD5`/`PD6` (pins 30 and 31) to U1 pins 36 and 37. If they beep, the
display link and the SWD pins are the same two pins, which explains why the
debug port only worked in the ROM monitor.

## Next

1. Locate the UART3 pin mux writes and confirm P06/P07.
2. Find the base-link handler: 11-byte frames, type `0x07` and `0x08`, 2400
   baud on UART1.
3. Find the button scan and the LED color table.
4. Carve the RAM image at `0x10059118` so veneered functions can be analyzed.
