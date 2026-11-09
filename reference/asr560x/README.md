# ASR560X / ASR5601S reference archive (curated)

A small, curated copy of ASR Microelectronics' public ASR560X documentation and
tools. It exists because ASR's original links are disappearing and the ASR5601S
dump work depends on a few of them.

Only the files used by the Roadshock work are included. The full site mirror and
the SDK are not. The original 2 MB vector datasheet is not included either; an
OCR text and a 150 dpi print of ASR's V1.4.0 datasheet are. One ASR582X page is
kept in `notes/` because it is the only ASR document found that names the read
command. ASR's 560X demo flash image is not redistributed because it contains
the ASR BLE ROM; its partition layout is recorded in
`drive/ASR560X_test_image_layout.md`.

## Contents

| Path | What it is |
|---|---|
| `docs-en/ASR560X/` | Selected English pages: hardware reference, schematics, reference design, hardware design, developer guide, memory layout, DOGO manual, FAQ |
| `docs-en/_sources/ASR560X/` | The clean reStructuredText for those pages |
| `docs-zh/ASR560X/软件快速入门/命令说明` | Chinese AT command list |
| `docs-zh/ASR560X/软件快速入门/SDK固件类型` | Chinese SDK firmware types and download notes |
| `drive/ASR5601T3_QFN48_EVB_LITE_SCH.pdf` | QFN48 EVB schematic |
| `drive/ASR560X_Peripheral_Users_Guide_V1.2.0_EN.pdf` | Flash controller, eFuse, AES/TRNG registers |
| `drive/ASR560X_Development_Board_User_Guide_V1.1.0.pdf` | Boot straps, `1F2E3D00`, EVB serial wiring |
| `drive/ASR_IoT_Security_Application_Notes_V1.0.0_EN.pdf` | Readout, secure boot, eFuse |
| `drive/ASR560X_Datasheet_V1.4.0_EN.ocr.txt` | Page-marked OCR text |
| `drive/ASR560X_Datasheet_V1.4.0_EN.print_150dpi.pdf` | 150 dpi print of the datasheet |
| `drive/DOGO_VP2.3.8.exe` | ASR's flash tool, PyInstaller build |
| `drive/DOGO_extract/` | Entry module, embedded chip database, string table, and annotated disassembly of the dump path |
| `drive/ASR560X_test_image_layout.md` | Partition offsets and signatures from ASR's public 560X demo image |
| `meta/ASR560X_datasheet_provenance.md` | Datasheet source and OCR limitations |
| `notes/ASR582X_FAQ_coredump/` | The one ASR page that names `coredump flash all` |

## Datasheet status

The archive contains ASR560X Series Datasheet V1.4.0 (2023-09-18) as OCR text
and a 150 dpi print. The original 2 MB vector PDF is not included. The OCR is
useful for grep and table reading order; use the print PDF for exact table
cells. Source and OCR limitations are in
[meta/ASR560X_datasheet_provenance.md](meta/ASR560X_datasheet_provenance.md).

The V1.2.1 datasheet is not included. It is available only through a credit-gated
CSDN re-upload.

The `analysis/asr6601.pdf` file sometimes mistaken for this datasheet is the
**ASR6601** datasheet, a different LoRa chip. It is not included.

The datasheet review is in
[docs/asr5601_datasheet.md](../../docs/asr5601_datasheet.md). It corrected the
QFN48 pin table and the 5 V tolerance note, and it adds the UART pin options,
keypad block, peripheral map and power passives.

## Why these files

- The QFN48 EVB schematic is the useful pin and board reference for the package
  on the panel.
- The datasheet OCR/print gives the QFN48 pin table, UART pin mux, keypad
  controller, memory map, 5 V tolerance and power passives. See
  [docs/asr5601_datasheet.md](../../docs/asr5601_datasheet.md).
- The Peripheral User's Guide covers the flash controller, eFuse, AES and TRNG.
- The Development Board guide covers the boot straps and the `1F2E3D00`
  download-mode banner.
- The Security notes cover readout and secure boot.
- The DOGO tool contains the undocumented read path (`read_image`,
  `recv_flash_image`, `dumping done!!!`).
- The embedded `data.pyc` chip table gives the 5601S image addresses, the ASCII
  handshake `AsrIot560x` and the 921600 high-speed baud without needing
  `config.ini`.
- ASR's 560X demo image is a known-good flash layout. Its bootloader identifies
  itself as `ASRBOOTLOADER-560X-MX-V2.0.3` and its partition table includes
  `COREDUMP`. The offsets and signatures are in
  `drive/ASR560X_test_image_layout.md`; the image itself is not redistributed.
- The selected EN pages cover the boot, memory layout, download tool and FAQ.
- The two ZH pages cover the AT command list and the SDK firmware types.

## The read command

ASR's ASR582X FAQ documents the same DOGO tool's read path:

1. Create `recev_data/coredump` beside the tool.
2. Open the UART1 port.
3. Check `Coredump` and `ReceiveFile`.
4. Enter `coredump flash all`.
5. Collect the `.bin` files from `recev_data/coredump`.

DOGO parses the reply as `:<ten-character label><hex>$` and writes one file per
label. The Read Image checkbox uses a separate `$<hex>$` capture and the
Generate Bin button. Neither path needs a license, because the command is typed
into the ordinary send box.

The command is documented for the 582X family and has not yet been proven on
the 5601S. The probe order and fallbacks are in
[docs/asr5601_dump_plan.md](../../docs/asr5601_dump_plan.md).

## Provenance

- English pages: `https://asriot.readthedocs.io/en/latest/ASR560X/...`
- Chinese pages: `https://asriot-cn.readthedocs.io/zh/latest/ASR560X/...`
- PDFs and DOGO: ASR's Google Drive links, as referenced by the ASR560X pages.
  Drive IDs are in [SOURCES.md](SOURCES.md).
- Datasheet: ASR's Baidu Pan share `pan.baidu.com/s/19k-GYoEX1FZoNk6SNfoOrw`,
  extraction code `brif`.

## Copyright and takedown

These documents, the DOGO executable, the modules extracted from it, and the
datasheet OCR/print are copyright ASR Microelectronics Co., Ltd. They remain
ASR's property. They are included for preservation, interoperability and repair
research, with no license granted. If ASR or a rights holder asks for removal,
the files will be removed.

PDF author and creator metadata was stripped before publication. The visible
content is unchanged. `MANIFEST.sha256` covers the files as published.
