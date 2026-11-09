# DOGO VP2.3.8 extraction

DOGO is a PyInstaller one-file build of a Python 3.5 / Qt application. The
entry module is `pyserial_demo.pyc`. The packed archive `PYZ-00.pyz` contains
406 modules, including `data.pyc`, which is the chip database.

## Files

| File | What it is |
|---|---|
| `pyserial_demo.pyc` | Entry module, Python 3.5 bytecode |
| `data.pyc` | Chip database: image addresses, handshake strings, baud rates |
| `chip_table.txt` | Readable dump of the chip entries |
| `pyserial_demo.strings.txt` | Printable strings from the entry module |
| `dump_path.dis.txt` | Annotated disassembly of the receive and bin path |

A Python 3.5 interpreter is required to load these `.pyc` files. The magic is
`17 0d 0d 0a`. Python 3.12 rejects them with `EOFError` or `SystemError`.
The 6.9 MB embeddable `python-3.5.4-embed-amd64.zip` is enough; no install is
needed.

## Protocol summary

The ASR560X download monitor is a text CLI on UART1.

| Item | Value |
|---|---|
| Reset banner | `1F2E3D00` |
| Handshake | `AsrIot560x ` (ASCII, trailing space, no CRLF) |
| Default baud | 115200 |
| High-speed baud | 921600 |
| Prompt | `welcome to download\r\n>>>` |
| Identity | `get_chip_type` then `CT:0x...` |
| Read command | `coredump flash all` (documented by ASR for 582X) |
| Read frame | `:<ten-character label><hex>$` |
| Read Image frame | `$<hex>$` |

The host does not need `config/config.ini`. `get_cfg` uses it for language and
last-used paths, and shows a dialog if it is missing, but the chip table is
compiled into `data.pyc`. The `5601S` entry is present with the addresses in
`chip_table.txt`.

The license manager guards the download type, not the send box. A read command
typed into the send box is ordinary ASCII and does not go through the license
check.

## Capture parsing

DOGO has two parsers, and they expect different streams:

`generate_real_bin` reads a text capture, applies `re.findall(r":(.*?)\$", data)`,
takes the first ten characters of each match as a file name, converts the rest
from hex, and writes `recev_data/coredump/<name>.bin`.

`gen_flash_bin` reads `flash_image_data.txt`, applies `re.findall(r"\$(.+?)\$",
data)` and writes `flash_image_bin.bin`. This is the Read Image and Generate Bin
path.

The tool in `tools/asr5601_dump.py` accepts both shapes. When every label is an
eight-digit address it also rebuilds a flat `flash.bin`, writes `flash.hex`, and
fills gaps with `0xFF`.

## Safety

`coredump flash all` is a read. Do not send `erase`, `burn`, `boot` or any
write command before a verified dump exists. The ASR has no factory restore
image. See `docs/asr5601_dump_plan.md`.
