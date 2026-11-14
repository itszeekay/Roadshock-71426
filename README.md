# ROADSHOCK Universal LED 8-Gang Switch Panel: Reverse Engineering

**Harbor Freight SKU 71426** · [product page](https://www.harborfreight.com/universal-led-8-gang-switch-panel-71426.html) · [owner's manual](https://manuals.harborfreight.com/manuals/71000-71999/71426-193175548276.pdf)

Firmware analysis, pinouts, wire protocol, and a practical path to a CAN-controlled power distribution unit (PDU) built on the stock hardware.

![ROADSHOCK 71426 base/output unit with the lid off](images/hero.jpg) *ROADSHOCK 71426 base/output unit, lid removed. The terminal/fuse map is printed inside.*

This is a community reverse-engineering project for the **Harbor Freight 71426**
8-gang switch panel system, also sold under related brand names. It covers the
base board (power and output module) and the button panel (10 buttons with RGB
status LEDs), including the three processors inside them:

| Board | Processor | Job |
|---|---|---|
| Base | STM8S003F3P6 | 2400-baud link, outputs, fusing logic, stock channel modes |
| Panel | ASR5601S | main controller: buttons, UI, LED colors, base link, BLE |
| Panel | STM8S003K3 | receives 115200 display frames and drives the 8 RGB LEDs |

Everything here comes from hardware the author owns: SWIM dumps of both STM8
parts, an SWD dump of the ASR5601S, static analysis, and passive UART captures.

## Status

| Area | State |
|---|---|
| Base firmware | dumped, decompiled, custom SDCC firmware with hardware PWM and wiper control; stock restore path verified |
| Panel LED firmware | dumped and decompiled; 115200 display frame and nibble to color map recovered |
| ASR5601S firmware | 1 MB dump verified twice over SWD and once over J3 alone; 375 application and 101 bootloader functions decompiled |
| ASR programming | ROM monitor documented; RAM stub erase and program proven on the ATE sector |
| 2400-baud link | frame format, message types, replies and checksum documented; capture, impersonation and injection work |
| Middle ECU | ESP32-S2 plus SN65HVD230 design; firmware not started |
| Bench pending | four stock channel modes and the low-frequency TIM1 prescaler, both built but not flashed for those tests |

Open questions are listed in the relevant documents. The main ones are the ASR
runtime pin map, its BLE service list, and LED control over J2 alone.

## Start here

- **Read by goal**: [`docs/README.md`](docs/README.md)
- **Build and flash the custom base firmware**: [`docs/startup_guide.md`](docs/startup_guide.md)
- **Full dump, build, flash, restore and capture run**: [`docs/reproduce.md`](docs/reproduce.md)
- **Protocol reference**: [`docs/protocol.md`](docs/protocol.md)
- **ASR dump record**: [`docs/asr5601_dump.md`](docs/asr5601_dump.md)
- **ASR firmware behavior**: [`docs/asr5601_firmware.md`](docs/asr5601_firmware.md)
- **Middle ECU feature list**: [`docs/middle_ecu_features.md`](docs/middle_ecu_features.md)

## What you need

- Harbor Freight 71426 switch panel, base board and button panel
- ST-Link V2 and `stm8flash` for SWIM work
- SDCC 4.5 for the custom base firmware
- Python 3 with `pyserial` for the protocol and dump tools
- Adafruit Feather RP2040 for bus capture and panel emulation
- For the planned bridge: ESP32-S2 Mini and an SN65HVD230 CAN transceiver

The ASR work uses an ARM GNU toolchain and a Ghidra project; both are referenced
in the relevant guides and are not distributed here. An early CAN test used an
Adafruit RP2040 CAN Bus Feather (MCP25625); it is retired from the current
design, see [`docs/test-hardware.md`](docs/test-hardware.md).

## Repository layout

```
docs/       human-readable documentation
dumps/      stock flash / EEPROM / option bytes + SHA-256
restore/    base-board stock restore images and script
reverse/    decompiled firmware + annotated listings
firmware/   custom base firmware (SDCC source + prebuilt images)
tools/      protocol reference, PWM tests, ASR dump tools, Ghidra scripts
reference/  curated ASR560X documentation, DOGO extraction and chip table
rp2040/     CircuitPython sniffer, impersonator, base emulator, CAN sketch
captures/   real bus captures
images/     board photos
```

## Confidence

Findings are tagged where it matters: **verified** means read from firmware or
measured on hardware, **inferred** means consistent with the evidence but not
proven, and **unknown** means not yet determined.

The protocol, pin maps, dump integrity, PWM behavior and the STM8 display driver
are verified. The custom firmware's auto functions (valet, delayed-off,
double-tap latch, force override) and wiper control are implemented and
bench-verified. The four stock channel modes and the low-frequency prescaler fix
are built but not yet flashed for bench testing. The ASR firmware is dumped and
analyzed; its runtime pin map and BLE service list remain open.

## Safety

This is 12 V automotive hardware. Fuse every output, never work on it live, and
do not use this project for safety-critical systems. The authors accept no
liability for damage or injury.

## Legal and license

Original code and documentation in this repository are released under the MIT
license (see [`LICENSE`](LICENSE)). Stock firmware dumps are provided for
interoperability and research on hardware owned by the author. Vendor material
remains the property of its respective owners. The ASR reference archive
contains ASR-published documentation, the DOGO tool, and an OCR text and print
of the ASR560X datasheet. See [`NOTICE.md`](NOTICE.md).

Harbor Freight and the product names are trademarks of their owners. This
project is not affiliated with or endorsed by Harbor Freight, the OEM, or ASR
Microelectronics.
