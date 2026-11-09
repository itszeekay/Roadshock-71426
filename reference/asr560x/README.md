# ASR560X / ASR5601S reference archive (curated)

A small, curated copy of ASR Microelectronics' public ASR560X documentation and
tools. It exists because ASR's original links are disappearing and the ASR5601S
dump work depends on a few of them.

Only the files used by the Roadshock work are included. The full site mirror,
unrelated ASR product families, the SDK, and the datasheet (credit/form gated)
are not.

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
| `drive/DOGO_VP2.3.8.exe` | ASR's flash tool, PyInstaller build |
| `drive/DOGO_extract/` | Entry module and strings from the tool |

## Why these files

- The QFN48 EVB schematic is the useful pin and board reference for the package
  on the panel.
- The Peripheral User's Guide covers the flash controller, eFuse, AES and TRNG.
- The Development Board guide covers the boot straps and the `1F2E3D00`
  handshake.
- The Security notes cover readout and secure boot.
- The DOGO tool contains the undocumented read path (`read_image`,
  `recv_flash_image`, `dumping done!!!`).
- The selected EN pages cover the boot, memory layout, download tool and FAQ.
- The two ZH pages cover the AT command list and the SDK firmware types.

## Provenance

- English pages: `https://asriot.readthedocs.io/en/latest/ASR560X/...`
- Chinese pages: `https://asriot-cn.readthedocs.io/zh/latest/ASR560X/...`
- PDFs and DOGO: ASR's Google Drive links, as referenced by the ASR560X pages.
  Drive IDs are in [SOURCES.md](SOURCES.md).

## Copyright and takedown

These documents and the DOGO executable are copyright ASR Microelectronics
Co., Ltd. They remain ASR's property. They are included for preservation,
interoperability and repair research, with no license granted. If ASR or a
rights holder asks for removal, the files will be removed.

PDF author and creator metadata was stripped before publication. The visible
content is unchanged. `MANIFEST.sha256` covers the files as published.
