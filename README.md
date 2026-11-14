# ROADSHOCK Universal LED 8-Gang Switch Panel: Reverse Engineering

**Harbor Freight SKU 71426** · [product page](https://www.harborfreight.com/universal-led-8-gang-switch-panel-71426.html) · [owner's manual](https://manuals.harborfreight.com/manuals/71000-71999/71426-193175548276.pdf)

Firmware analysis, pinouts, wire protocol, and a practical path to a CAN-controlled power distribution unit (PDU) built on the stock hardware.

![ROADSHOCK 71426 base/output unit with the lid off](images/hero.jpg) *ROADSHOCK 71426 base/output unit, lid removed. The terminal/fuse map is printed inside.*

This is a community reverse-engineering project for the **Harbor Freight 71426** 8-gang switch panel system (also sold under related brand names). It covers both boards:

- the **base board** (the power/output module), and
- the **button panel** (10-button remote with RGB status LEDs).

Everything here was obtained from hardware the author owns: SWIM dumps of two unprotected STM8 microcontrollers, static analysis, and passive UART captures.

---

## What This Project Is

This project documents the reverse-engineering of the Harbor Freight 71426 Universal LED 8-Gang Switch Panel. It covers:

- **Hardware analysis**: pinouts, pin mappings, and hardware design
- **Protocol reverse-engineering**: 2400-baud link between base board and panel
- **Firmware analysis**: decompilation of base and panel STM8 firmware
- **Protocol specification**: 2400-baud frame format, message types, replies, checksum
- **Protocol tools**: Python scripts for validation, frame capture, and protocol reference
- **Custom firmware**: SDCC-based firmware for the base board with hardware PWM
- **CAN gateway/PDU plan**: design for a CAN-controlled power distribution unit

This project documents everything needed to understand, repair, or build upon the 71426 switch panel system.

---

## What This Project Is Not

This project is **not**:
- A commercial product
- A commercial firmware release
- A fully tested, production-ready solution
- A complete CAN gateway implementation (still in design phase)
- A replacement for the original ASR firmware

This is a research project documenting reverse engineering of proprietary hardware.

---

## What You Can Do With This Project

- **Reverse engineer** similar products
- **Build custom firmware** for the base board with additional features
- **Develop a CAN gateway** to control the panel via CAN bus
- **Create custom firmware** with new features like LED control or CAN integration
- **Understand reverse engineering techniques** for similar embedded systems

---

## What You Need

- **Hardware**: Harbor Freight 71426 switch panel (base board + button panel)
- **Tools**: 
  - ST-Link V2 + `stm8flash` (for SWIM operations)
  - SDCC 4.5 (for custom firmware builds)
  - Python 3 + `pyserial` (for protocol tools)
  - Adafruit Feather RP2040 (for bus operations)
  - Optional: Adafruit RP2040 CAN Bus Feather (MCP25625) for CAN testing
- **Software**:
  - Python 3
  - SDCC 4.5 (in PATH)
  - Python 3 + `pyserial`, `pyserial` tools
  - Python 3 + `pyserial` tools for protocol operations

---

## Quick Start

If you want to flash the custom firmware on your own hardware, follow
[`docs/startup_guide.md`](docs/startup_guide.md). It walks you through:

1. What you are building (base board vs button panel)
2. Accessing the potted SWIM header
3. Building the custom firmware with `make`
4. Flashing with `stm8flash`
5. Restoring stock if needed
6. Configuring a channel over the 2400-baud link
7. Testing the output
8. What the firmware does with each setting

Other entry points:

- **Full reproduce run** (dump, build, flash, restore, capture):
  [`docs/reproduce.md`](docs/reproduce.md)
- **Protocol reference** (frame format, all message types, replies):
  [`docs/protocol.md`](docs/protocol.md)
- **Channel capabilities** (which channels have hardware PWM, frequency
  groups, wiring assignments): [`docs/channel_guide.md`](docs/channel_guide.md)
- **Wiper control** (park switch, type 0x0D):
  [`docs/wiper_control.md`](docs/wiper_control.md)
- **Reading guide for all docs** (by goal): [`docs/README.md`](docs/README.md)

---
# What Works Today

- **Read the base firmware**: SWIM dump, 8 KB flash + 128 B EEPROM.
- **Read the ASR5601S firmware**: SWD dump, 1 MB, two identical reads, hash recorded.
- **Analyze the ASR firmware**: 360 application functions and 101 bootloader functions decompiled; UART map, keypad, LED path and base link documented.
- **Write the ASR flash over J3**: the ROM monitor loads a RAM stub that erases and programs the ATE partition, verified by read-back. Source in `tools/asr_stub`.
- **ASR BLE name**: `Controller8 Wired-XXXXXX`, from the advertising template at `0x10059122`.
- **Read the panel firmware**: same, ROP open.
- **Capture the 2400-baud bus** with a Feather RP2040 (listen-only or MITM).
- **Injection**: button frames, master power, and our custom `0x09` PWM command.
- **Hardware PWM** on 6 channels (1, 3, 4, 5, 6, 7) at 200-2000 Hz, 10-100 % duty (TIM1 + TIM2, verified on a scope).
- **Wiper control** on Channel 5 (PC5/TIM2_CH1) via custom protocol type `0x0D`.
- **Build custom base firmware** with SDCC 4.5.
- **ASR datasheet reference**: V1.4.0 OCR text plus a compressed print, with the QFN48 pin map, UART mux, keypad and peripheral map reviewed.
- **Restore the STM8 stock firmware** from verified images at any time.

---

## What Is Still Open

- **ASR runtime pinout**: the pin mux class numbers are not recoverable from the image; the runtime read is blocked because the application repurposes the SWD pins.
- **ASR BLE services**: no static GATT table; the list needs a live scan. The advertising name is known.
- Bench verification of the four stock channel modes and the low-frequency TIM1 prescaler fix. Both are built, but the prebuilt full image has not been flashed for those tests.
- Direct control of the panel LEDs without touching the private 115200 link; the ASR owns that link (UART3 on P06/P07).
- Over J2 alone, the LEDs remain under the ASR's UI control.
- The final CAN gateway/PDU hardware (CAN controller choice, current sensing).

---

## Test Hardware

The bench used an Adafruit Feather RP2040 DVI for UART capture and an **Adafruit RP2040 CAN Bus Feather (MCP25625)** for early CAN testing. The CAN Feather is not part of the current design and is not actively used. See [`docs/test-hardware.md`](docs/test-hardware.md).

Board notes:
- RP2040, 8 MB QSPI flash, 264 KB RAM, 3.3 V logic
- MCP25625 on SPI: SCK/MOSI/MISO plus CS, INT and standby
- 5 V charge pump for the transceiver
- 3.5 mm terminal block: CAN H, CAN L, GND
- 120 ohm termination fitted; cut the `TERM` jumper to remove it
- UART0 on TX/RX; UART1 on D24/D25 (or D4/D9/D5, depending on the mux)
- TX pins are not connected. Check that the idle level is 3.3 V; the RP2040 is not 5 V tolerant.

If it is reused:
- Tie the Feather ground to the bus ground
- Fit 120 ohm termination only at the two ends of the bus
- Keep CAN H/L away from the 2400-baud panel link

---

## Repository Layout

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

---

## Status and Confidence

Findings are tagged where it matters:

- **Verified**: read from the firmware or measured on hardware.
- **Inferred**: consistent with the evidence but not proven.
- **Unknown**: not yet determined.

The protocol, pin maps, dump integrity, PWM behavior, and the STM8 display driver are verified. The custom firmware's auto-functions (valet, delayed-off, double-tap latch, force override) and wiper control are implemented and bench-verified. The four stock channel modes and the low-frequency prescaler fix are built but not yet flashed for bench testing. The ASR firmware and any J2-only LED control are not verified.

---

## Safety

This is 12 V automotive hardware. Fuse every output, never work on it live, and do not use this project for safety-critical systems. The authors accept no liability for damage or injury.

---

## Legal and License

Original code and documentation in this repository are released under the MIT license (see [`LICENSE`](LICENSE)). Stock firmware dumps are provided for interoperability and research on hardware owned by the author. Vendor material remains the property of its respective owners. The ASR reference archive contains ASR-published documentation, the DOGO tool, and an OCR text and print of the ASR560X datasheet. See [`NOTICE.md`](NOTICE.md).

Harbor Freight and the product names are trademarks of their owners. This project is not affiliated with or endorsed by Harbor Freight, the OEM, or ASR Microelectronics.