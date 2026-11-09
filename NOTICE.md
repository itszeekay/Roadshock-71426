# Notices

## Original work

The original code and documentation in this repository (custom firmware, tools,
protocol description, pin maps, photos) are released under the MIT licence in
[`LICENSE`](LICENSE).

## Stock firmware dumps

The files under `dumps/` and `restore/` are binary images read from hardware
owned by the author. They are provided for **interoperability, repair, and
security research** on that hardware.

They are not claimed to be free works. The stock firmware remains the property
of its respective owners. If you are a rights holder and want a file removed,
open an issue.

## No vendor source code

This repository does **not** contain:

- ASR SDK source, ASR BLE stack/ROM binaries, or ASR datasheet text,
- ST Standard Peripheral Library source,
- the community STM8 SLEIGH module,
- vendor schematics or manuals.

Those are referenced by name/URL where relevant. The decompiled C is a
reconstruction produced from the author's own dumps; the STM8 SLEIGH module is
an independent third-party project.

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
