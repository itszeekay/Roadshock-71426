# Project Status

Last updated: 2026-11-09

## Verified

### Hardware / acquisition
- Base board MCU: STM8S003F3P6. ROP = 0x00 (unprotected).
- Flash image: **8192 bytes @ 0x8000** (`stm8/base_board/firmware_dump.bin`).
- EEPROM image: **128 bytes @ 0x4000** (`stm8/base_board/eeprom_dump.bin`).
- Button panel MCU (STM8S003K3): ROP = 0x00, **8192 B flash + 128 B EEPROM**
  (two identical reads), fully decompiled 147/147. `stm8/button_panel/`,
  `reverse/panel_firmware_reconstructed.c`, `docs/panel_firmware.md`.
- ASR5601S BLE SoC on the panel: **main panel controller** (8 buttons + 2400-baud
  protocol + optional BLE). It does not advertise BLE in this variant. Not
  dumped, not flashed. `docs/asr5601_pinout.md`, `docs/asr5601_programming.md`.
- Panel STM8S003K3 is the **RGB LED display driver**: 8 RGB LEDs on 24 pins,
  115200 9-byte display frames (`0x5A...0xEE`), no button inputs.
  `docs/panel_io_map.md`.

### Firmware (see `docs/firmware_static_analysis.md` for detail)
- Toolchain: Ghidra 11.3.1 + STM8 SLEIGH module, language `STM8:BE:16`, base 0x8000;
  radare2 used as cross-check. Project: `~/Ghidra1131/projects/Roadstm8`.
- Coverage: 3626 instructions, 394 functions, 93.0 % of image bytes decoded.
- **UART1 is the panel link** (0x5230 block, ~50 accesses). No I2C and **no ADC use at all**
  in the corrected image (both were false positives from the corrupted dump).
- UART1 config at 0x8FA9 (`uart1_configure`), control bits at 0x9780,
  raw byte I/O at 0x9F7E / 0x9F82.
- RX buffering: 32-byte frame buffer at RAM 0x023E + length at 0x025E (limit 0x20).
- Clock config at 0x993C: ICKR=1, SWR=0xE1 (HSI), CKDIVR=0x18 -> CPU 2 MHz
  (f_master 16 MHz), PCKENR1=PCKENR2=0xFF (all peripheral clocks on).
- TIM2 PWM helpers (`tim2_set_ccr1l` at 0x9EC1, `tim2_set_arrh` at 0x9ECB).
- IWDG used (start 0xCC, periodic refresh).
- Startup code at 0x9CD8 (SP = 0x03FF).

## Open / unverified

### Firmware / hardware verification
- **UART baud divisor** - computed at runtime; caller not reachable statically yet.
  Current capture shows BRR1=0xA0, BRR2=0x1A (divider 6666) = **2400 baud** (verified).
- **Reset vector anomaly** - vector slot 0 parses to 0x9C82 (flash key write stub).
  Real startup is 0x9CD8 with SP=0x03FF; confirmed in firmware_reconstruction.c
  `reset_startup()`.
- **UART pins** - PD5/TX and PD6/RX used by firmware; PD1/PD2 mapping assumed from
  datasheet but not yet confirmed on the PCB.
- **Addresses 0x5062/0x5064** - flash-key-like registers do not match the documented
  block 0xAE/0x56 write idiom; needs hardware verification.
- **Decode drift zones** - known problematic regions: 0x8080–0x8130,
  0x8FA0–0x8FA8, 0x9510–0x9545. Ghidra reports overlapping instructions and bad
  instruction control flow.
- **Button panel firmware** - not dumped yet (hardware not connected).
- **Panel LED colour map** - nibble-to-RGB mapping not finalized. Captured frames are
  9-byte `0x5A...0xEE` at 115200, four payload bytes = eight nibbles = eight RGB LEDs.
- **Four stock modes' exact timing rules** - toggle / momentary / pulse / blinking are
  implemented, but timing specifics are not fully extracted from the decompilation.

### Project administration
- **Working README vs public repo alignment** - current working README aligns with
  public repo (local-only section added).
- **License** - MIT for custom code; stock dumps not claimed; vendor material remains
  property of respective owners.
- **Public vs local archive** - `local_archive/` contains raw prints; public repo has
  derived, publishable copies (`MANIFEST.sha256` tracked).
- **Third-party notices** - Ghidra, STM8 SLEIGH module, radare2, CircuitPython.
- **Reproduce-from-scratch instructions** - need verification on clean machine.
- **Publication checklist** - license notes, third-party notices, compliance doc pending.

### Open code gaps
- **STM8 button panel dump** - still pending SWIM dump.
- **Channel -> MCU pin map (QFN-48) details** - QFN48 pinout.md incomplete; pin 2 ch2 PA2
  inferred by elimination.
- **Protocol hidden commands** - some opcodes (0x0D/0x0E/0x19) inferred; details need
  extraction from decompilation.
- **Hardware PWM edge cases** - verify 0% / 100% duty cycle, reload timing.

## Removed speculation
The earlier `docs/protocol_analysis.md` guesses (start bytes 0xAA/0x55, command
codes 0x01–0x10, CRC-8 0x07) remain unverified guesses and are contradicted by nothing
yet - but no evidence for them has been found in the image either. Do not build on them
until live capture confirms the frame format.

## Next steps
1. Flash the rebuilt base board firmware with the prescaler fix and re-test low PWM
   frequencies (123 Hz, 777 Hz, 1.5 kHz).
2. Implement the four channel modes (toggle / momentary / pulse / blinking).
3. Re-validate against the stock button panel (button frames + replies).
4. Implement the CAN gateway on the confirmed protocol.
