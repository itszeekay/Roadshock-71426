# Sources

| Published file | Source |
|---|---|
| `docs-en/ASR560X/Hardware-Reference/Development_Board` | https://asriot.readthedocs.io/en/latest/ASR560X/Hardware-Reference/Development_Board.html |
| `docs-en/ASR560X/Hardware-Reference/Schematics` | https://asriot.readthedocs.io/en/latest/ASR560X/Hardware-Reference/Schematics.html |
| `docs-en/ASR560X/Hardware-Reference/reference_design` | https://asriot.readthedocs.io/en/latest/ASR560X/Hardware-Reference/reference_design.html |
| `docs-en/ASR560X/Hardware-Reference/hardware_design` | https://asriot.readthedocs.io/en/latest/ASR560X/Hardware-Reference/hardware_design.html |
| `docs-en/ASR560X/Quick-Start/Developer_Guide` | https://asriot.readthedocs.io/en/latest/ASR560X/Quick-Start/Developer_Guide.html |
| `docs-en/ASR560X/Quick-Start/Memory_Layout_Configuration` | https://asriot.readthedocs.io/en/latest/ASR560X/Quick-Start/Memory_Layout_Configuration.html |
| `docs-en/ASR560X/Download-Tool/560X_Programming` | https://asriot.readthedocs.io/en/latest/ASR560X/Download-Tool/560X_Programming.html |
| `docs-en/ASR560X/FAQ/FAQs` | https://asriot.readthedocs.io/en/latest/ASR560X/FAQ/FAQs.html |
| `docs-en/_sources/ASR560X/...` | The `_sources/*.rst.txt` twin of each page above |
| `docs-zh/ASR560X/软件快速入门/命令说明` | https://asriot-cn.readthedocs.io/zh/latest/ASR560X/软件快速入门/命令说明.html |
| `docs-zh/ASR560X/软件快速入门/SDK固件类型` | https://asriot-cn.readthedocs.io/zh/latest/ASR560X/软件快速入门/SDK固件类型.html |
| `drive/ASR5601T3_QFN48_EVB_LITE_SCH.pdf` | https://drive.google.com/file/d/1aBxEaoEmZEevNI-5a3PhiMQOXCXvy1hf/view |
| `drive/ASR560X_Peripheral_Users_Guide_V1.2.0_EN.pdf` | https://drive.google.com/file/d/1Q1-Jnlh8A6GL4dPEv2mGy088NXb1CvkB/view |
| `drive/ASR560X_Development_Board_User_Guide_V1.1.0.pdf` | https://drive.google.com/file/d/1ie_yM-ItQ5_PIh5NClD7macu2FYobJXd/view |
| `drive/ASR_IoT_Security_Application_Notes_V1.0.0_EN.pdf` | https://drive.google.com/file/d/1UYQFE1LQbBFFVinsHPXCAljKA4VLE6F_/view |
| `drive/DOGO_VP2.3.8.exe` | https://drive.google.com/file/d/1wWtGCSKRu0-ehqY-_R00N9Rb6gdeiZ0G/view |
| `drive/DOGO_extract/pyserial_demo.pyc` | Extracted from that executable |
| `drive/DOGO_extract/pyserial_demo.strings.txt` | Generated from `pyserial_demo.pyc` |
| `drive/DOGO_extract/data.pyc` | Extracted from `PYZ-00.pyz` inside that executable |
| `drive/DOGO_extract/chip_table.txt` | Generated from `data.pyc` |
| `drive/DOGO_extract/dump_path.dis.txt` | Annotated disassembly produced from `pyserial_demo.pyc` |
| `drive/DOGO_extract/README.md` | Notes on the extraction and protocol |
| `drive/ASR560X_test_image_layout.md` | Derived from ASR's public 560X demo image, which is not redistributed |

The `coredump flash all` procedure is quoted from ASR's ASR582X FAQ:
https://asriot-cn.readthedocs.io/zh/latest/ASR582X/常见问题/582X_开发常见问题.html

That page and its rst twin are kept under `notes/ASR582X_FAQ_coredump/` because
it is the only ASR document found that names the read command.

The test image source is ASR's ASR560X demo project:
https://drive.google.com/file/d/15PWqvktRdqpaRSQ3lrGuPQahQKwdiC1G/view?usp=sharing

The image is a full flash image for the ASR560X transparent-transmission demo.
ASR's readme says it contains bootloader, BLE ROM and app, and is written at
`0x10000000`. Its bootloader string is `ASRBOOTLOADER-560X-MX-V2.0.3`. It is
**not redistributed here** because it contains the ASR BLE ROM. Only the derived
partition layout note is included.

The PDFs were re-saved with author and creator metadata removed. Their visible
content is unchanged.

The ASR560X datasheet is not listed because it could not be obtained:
V1.4.0 is form-gated on asrmicro.com and V1.2.1 is credit-gated on CSDN. The
public CSDN preview pages are blank cover pages. If you obtain the PDF, add it
here with its source URL and update `MANIFEST.sha256`.
