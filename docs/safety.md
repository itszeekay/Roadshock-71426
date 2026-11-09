# Safety

This project involves **12 V automotive power, high-current outputs, and RF**.
Read this before touching the hardware. The same hazards described here are
also covered by [`NOTICE.md`](../NOTICE.md).

## Electrical

- The base board drives 8 high-side P-channel MOSFETs rated up to **30 A per
  channel** (channels 1-2 use two in parallel). Per-channel fuses are rated
  30, 30, 20, 20, 10, 10, 5, 5 A. Fuse every output at or below its rating.
- Never work on the unit live. Connect leads with power off, verify
  polarity and fuse values, then apply power.
- The STM8 pins are **3.3 V only**. Do not apply 5 V or 12 V to any GPIO, SWIM,
  or UART pin. RP2040 test hardware is also 3.3 V only.
- The ASR5601S is 5 V tolerant on a limited set of pins (P02-P05,
  UART0/UART1). The other GPIOs follow the board supply. Treat every pin as
  3.3 V unless the datasheet note in `asr5601_datasheet.md` says otherwise.
- Rate current in the harness, not just at the board. A stalled motor or
  shorted load can exceed the MOSFET rating before the fuse opens.

## Firmware and flashing

- Reflashing a microcontroller can brick it. Stock restore images are in
  `restore/`; verify them before writing anything.
- Never erase or burn the ASR5601S before a verified dump. There is no
  factory restore image for the ASR.
- The stock STM8 images are unprotected (ROP open). Custom firmware assumes
  the stock pin map; driving the wrong pins can reverse or short outputs.
- Disconnect `RST` / remove the programmer before powering the board. The
  MCU is held in reset while `RST` is wired.

## RF and scope

- This project is **not for safety-critical or life-support systems**. Do
  not mount it where a failed output could cause injury or a vehicle hazard.
- The ASR5601S includes a BLE radio. RF work near medical devices or in
  regulated environments needs care with transmission power and duty cycle.

## Liability

Everything in this repository is provided for interoperability, repair, and
security research on hardware the author owns. Vendor material remains the
property of its respective owners. The authors accept no liability for
damage, injury, or legal consequences.
