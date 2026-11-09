# Notices

## Original work

The original code and documentation in this repository (custom firmware, tools,
protocol description, pin maps, photos) are released under the MIT license in
[`LICENSE`](LICENSE).

## Stock firmware dumps

The files under `dumps/` and `restore/` are binary images read from hardware
owned by the author. They are provided for **interoperability, repair, and
security research** on that hardware.

They are not claimed to be free works. The stock firmware remains the property
of its respective owners. If you are a rights holder and want a file removed,
open an issue.

## Vendor reference archive

`reference/asr560x/` contains ASR-published documentation, the DOGO tool,
Python modules extracted from it, and an OCR text and 150 dpi print of the
ASR560X V1.4.0 datasheet. This material is included for preservation and
interoperability research. Copyright remains with ASR Microelectronics; no
license is granted. If ASR or a rights holder asks for removal, the files will
be removed.

ASR publishes the ASR560X demo image, which contains the bootloader, BLE ROM
and app. Its partition layout is documented in
`reference/asr560x/drive/ASR560X_test_image_layout.md`.

Vendor material in this repository remains the property of its respective
owners. The decompiled C is a reconstruction produced from the author's own
dumps; the STM8 SLEIGH module is an independent third-party project.

## Trademarks

Harbor Freight, Roadshock, Auxbeam, STMicroelectronics, ASR Microelectronics,
Adafruit, and Raspberry Pi are trademarks of their respective owners. This
project is not affiliated with or endorsed by any of them.

## Safety

Automotive 12 V power, high-current outputs, and RF are involved. Fuse every
output, never work on the unit live, and do not use this project in
safety-critical or life-support systems. The authors accept no liability for
damage, injury, or legal consequences.

## No warranty

Everything is provided "as is". Reflashing a microcontroller can brick it. Keep
the stock restore images and verify them before writing anything.
