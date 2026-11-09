# ASR5601S reference archive and dump findings

Companion note to [`reference/asr560x/`](../reference/asr560x/). It covers what
is archived, what it changed, and where the dump work stands.

## What is archived

A curated subset of ASR's public ASR560X material, chosen for the dump work:

| Path | Contents |
|---|---|
| `reference/asr560x/docs-en/ASR560X/` | Hardware reference, schematics, reference design, hardware design, developer guide, memory layout, DOGO manual, FAQ |
| `reference/asr560x/docs-en/_sources/ASR560X/` | The clean reStructuredText twins |
| `reference/asr560x/docs-zh/ASR560X/软件快速入门/` | AT command list and SDK firmware types |
| `reference/asr560x/drive/` | QFN48 EVB schematic, Peripheral User's Guide, Development Board guide, Security notes, DOGO tool, extracted entry module and chip database, image layout notes |
| `reference/asr560x/drive/DOGO_extract/` | Python 3.5 modules, readable chip table, annotated dump-path disassembly |
| `reference/asr560x/notes/ASR582X_FAQ_coredump/` | The ASR582X FAQ page that names `coredump flash all` |
| `reference/asr560x/SOURCES.md` | Source URL or Drive ID for each file |
| `reference/asr560x/MANIFEST.sha256` | Hashes of the published files |

Not included: the full site mirror, other ASR product families, the ASR SDK, and
the datasheet (credit or form gated). The one ASR582X page above is kept because
it documents the read command. ASR's 560X demo flash image is not redistributed
because it contains the ASR BLE ROM; its partition layout is in
`reference/asr560x/drive/ASR560X_test_image_layout.md`. PDF author and creator
metadata was stripped before publication.

## What Phase 0 changed

`DOGO_VP2.3.8.exe` is a PyInstaller one-file build of a Python 3.5/Qt app. Its
entry module is `pyserial_demo.pyc`; its chip database is `data.pyc` inside
`PYZ-00.pyz`. The annotated disassembly of `recv_flash_image`,
`generate_real_bin`, `get_cmd_cfg`, `send_cmd` and `data_receive` is in
`reference/asr560x/drive/DOGO_extract/dump_path.dis.txt`.

`read_image` is **not** a command. It is a checkbox flag plus two host files:

- `checkBox_read_image` sets `self.read_image = True`.
- `data_receive` appends incoming payload to `flash_image_fname` when the flag
  is set.
- `rece_bin` calls `write_to_bin_file` and `generate_real_bin`.
- `generate_real_bin` runs the regex `:(.*?)\$`, takes the first ten characters
  of each match as a file name, converts the rest from hex, writes
  `./recev_data/coredump/<name>.bin`, and prints `dumping done!!!`.

The download monitor is a **text CLI**, not binary framing:

- prompt `welcome to download\r\n>>>`
- ASCII, CRLF-terminated commands
- `get_chip_type`, `erase <addr> <size>`, `burn <addr> <size>`,
  `boot <type> <size>`, `init <baud>`
- `1F2E3D00` is the banner the chip prints after reset in download mode;
  `1F2E3D81` is a communication error
- the ASCII handshake is `AsrIot560x ` (trailing space, no CRLF)
- `CT:` plus a regex for the chip ID
- `1048576` and `2097152` for the 1 MB and 2 MB parts

The chip database is **inside the executable**, not in `config.ini`. The
`5601S` entry gives:

| Item | Value |
|---|---|
| Handshake | `AsrIot560x` |
| Bench default baud | 115200 (manual) |
| High-speed baud | 921600 (chip table) |
| Bootloader | `0x10000000` |
| BLE ROM | `0x1000D000` |
| App | `0x10048000` |
| ATE | `0x100F0000` |
| OTA tag address | `0x10008000` |

`config/config.ini` only stores language and last-used paths. A missing file
produces a dialog, not an empty chip table. `config/script.ini` is the unrelated
multi-send macro list. Neither is needed for a read.

The license manager guards download types, not the send box. A read command
typed as ordinary ASCII does not pass through the license check.

## The read command

ASR's ASR582X FAQ documents the read path for the same DOGO tool:

1. Create `recev_data/coredump` beside the tool.
2. Open the UART1 port.
3. Check `Coredump` and `ReceiveFile`.
4. Enter `coredump flash all`.
5. Collect the `.bin` files from `recev_data/coredump`.

DOGO parses the reply as `:<ten-character label><hex>$`. The separate Read Image
path captures `$<hex>$` blocks and the Generate Bin button converts them to
`flash_image_bin.bin`.

The command is documented for the 582X family and has not yet been proven on the
5601S. The probe order and fallbacks are in
[asr5601_dump_plan.md](asr5601_dump_plan.md). The host tool is
[`tools/asr5601_dump.py`](../tools/asr5601_dump.py).

## Pins: what reaches a pad

From the panel photos: `U1` is the ASR5601S QFN-48, `U2` the STM8S003K3, `J3`
the 6-pad ASR UART header, `J1` the 3-pad STM8 SWIM header, and `PZ20` a 6-pin
unlabelled header to the right of the ASR, on the pin 36-43 side.

| Signal | Pin | Pad |
|---|---|---|
| GND | 25 / 49 | `J3 GND` |
| 3.3 V | 12 / 22 | `J3 +3.3` |
| P04 / UART1_TX | 13 | `J3 TX` |
| P05 / UART1_RX | 14 | `J3 RX` |
| RSTN | 44 | `J3 RST` |
| P00 / SEL0 | 40 | `J3 SEL0` |
| P01 / SEL1 | 41 | no pad; internal pull-down = 0 |
| P06 / SWCLK | 37 | **no known pad** |
| P07 / SWDIO | 36 | **no known pad**; `PZ20` is the only candidate |

The ROM bootloader signal set is on a labeled header. SWD is not, which is why
the DOGO read path matters more than the SWD fallback.

Continuity checks still worth running with the board unpowered:

- `PZ20` to `J3 TX`: is PZ20 on the ASR side?
- `PZ20` to QFN pin 36 or 37: is SWD a wire or a rework?
- `J3 TX/RX` to the `J2` signal wires: must J2 be disconnected during a
  bootloader session?

## Next steps

1. Run `tools/asr5601_dump.py --probe` at 115200 with `SEL0=1` and confirm
   `1F2E3D00` and the `>>>` prompt. This proves the link and writes nothing.
2. Send `get_chip_type`, `help` and `?`, one at a time, and record the command
   vocabulary.
3. Send `coredump flash all`, capture the stream, and let the tool rebuild
   `flash.bin`. Read twice and compare SHA-256, the same rule used for the STM8
   images.
4. Use SWD only if the monitor has no read command and PZ20 carries P06/P07.

Do not run `Flash Erase` or `Burn` before a verified dump exists. There is no
factory restore image for the ASR.
