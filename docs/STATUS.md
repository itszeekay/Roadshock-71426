# Project Status

Last updated: 2026-11-09

## Verified

### Hardware / acquisition
- Base board MCU: STM8S003F3P6. ROP = 0x00 (unprotected).
- Flash image: **8192 bytes @ 0x8000** (`stm8/base_board/firmware_dump.bin`,
  sha256 `a730e8b0bd32861a02fdfd75ada5a78f632b85e54de8cb0b6a3d2d85f1dcef62`).
  This is the corrected dump; a text-mode dump (`firmware_dump.textcorrupt.bin`)
  exists and must not be used.
- EEPROM image: **128 bytes @ 0x4000** (`stm8/base_board/eeprom_dump.bin`).
- Button panel MCU (STM8S003K3): ROP = 0x00, **8192 B flash + 128 B EEPROM**
  (two identical reads), fully decompiled 147/147. `stm8/button_panel/`,
  `reverse/panel_firmware_reconstructed.c`, `docs/panel_firmware.md`.
- ASR5601S BLE SoC on the panel: **main panel controller** (8 buttons + 2400-baud
  protocol + optional BLE). It does not advertise BLE in this variant. Not
  dumped, not flashed. `docs/asr5601_pinout.md`, `docs/asr5601_programming.md`.
- Panel STM8S003K3 is the **RGB LED display driver**: 8 RGB LEDs on 24 pins,
  115200 9-byte display frames (`0x5A...0xEE`), no button inputs.
  `docs/panel_io_map.md`, `docs/panel_led_map.md`.

### Firmware (see `docs/firmware_static_analysis.md` for detail)
- Toolchain: Ghidra 11.3.1 + STM8 SLEIGH module, language `STM8:BE:16`, base 0x8000;
  radare2 used as cross-check. Projects: `~/Ghidra1131/projects/Roadstm8true`
  (base, corrected dump) and `Roadstm8Panel` (panel).
- Coverage (base, Roadstm8true): 256/256 functions decompiled, 0 failures
  (`analysis/decomp12_ghidra/`, `analysis/asm_named_true.txt`, 3646 instructions).
- **UART1 is the panel link** (0x5230 block, ~50 accesses). No I2C and **no ADC
  use at all** in the corrected image (both were false positives from the
  corrupted dump).
- UART1 config at 0x8F7E (`uart1_configure`), called from `uart1_init_2400`
  (0x9B17) with `DAT_0002=0x960`. Control bits at 0x9780,
  raw byte I/O at 0x9F7E / 0x9F82. Live value: 2400 baud (BRR1=0xA0,
  BRR2=0x1A). See `docs/mode_timing.md`.
- RX buffering: 32-byte frame buffer at RAM 0x023E + length at 0x025E (limit 0x20).
- Clock config at 0x993C: ICKR=1, SWR=0xE1 (HSI), CKDIVR=0x18 -> CPU 2 MHz
  (f_master 16 MHz), PCKENR1=PCKENR2=0xFF (all peripheral clocks on).
- TIM2 PWM helpers (`tim2_set_ccr1l` at 0x9EC1, `tim2_set_arrh` at 0x9ECB).
- IWDG used (start 0xCC, periodic refresh).
- Startup code at 0x9CD8 (SP = 0x03FF).
- Mode dispatch at `mode_handler` (0x816D, 256/256 decompile): incoming mode
  1/3/5/7 -> internal 0/2/4/8 (off/toggle/momentary/pulse path); dispatch writes
  `0x10*N` or `*pb | N` via `channel_state_write` (0x828D). Type-7 path goes
  through `config_mode_handler` (0x8146). Four stock modes
  (toggle/momentary/pulse/blinking) recovered. See `docs/mode_timing.md`.
- Frame dispatch at `frame_handler` (0x851A): type 7 = master power/parameter,
  type 8 = button bitmask, 0x0B/0x0D/0x19 = hidden handlers
  (`cmd_0b_handler` 0x8640, `cmd_0d_handler` 0x8689, `cmd_19_handler` 0x860C).
  See `docs/hidden_commands.md`.
- Panel display dispatch at `display_frame_handler` (0x844C): 9-byte
  `0x5A...0xEE` frame, nibble table recovered (0/2/4/6=off, 1=pin1, 3=pin3,
  5=pin2, 7=pin1+pin2, 8-15=unchanged; active-low). See `docs/panel_led_map.md`.
- Flash unlock at `flash_key_dispatch` (0x9C1B): 0x5062/0x5064 are the unlock
  registers (0x56 then 0xAE sequences). Confirms the decompilation.
- Ghidra annotations are in `tools/ghidra/build_project.py` (base) and
  `build_panel_project.py` (panel); renames verified with `ListAnnotations.java`.
- PWM edge cases reviewed in `firmware/src/board.c`: 0% = CCR 0 (low),
  100% = CCR ARR+1 (high); frequency clamped 50-2000 Hz with prescaler 8x.
- Bench aids: `tools/verify_builds.py` (checksum + compile + self-test),
  `tools/led_color_sweep.py` (nibble sweep), `tools/bench_probe.py`
  (continuity checklist, guarded hidden-command probe).

## Open / unverified

### Firmware / hardware verification
- **UART pins** - PD5/TX and PD6/RX used by firmware; PD1/PD2 mapping assumed
  from datasheet but not yet confirmed on the PCB.
- **ASR5601S firmware dump** - not dumped yet. Requires the J3 bench session
  (probe at 115200/921600, confirm `1F2E3D00`, try `coredump flash all`).
- **Panel LED color order** - nibble->pin pattern is fully recovered (see
  `docs/panel_led_map.md`), but which pin is R/G/B per channel is still a bench
  measurement. Use `tools/led_color_sweep.py`.
- **Four stock modes' exact timing rules** - dispatch recovered (toggle/
  momentary/pulse/blinking); blink period, pulse duration, and EEPROM byte
  encoding (0x0D-0x14) still need bench measurement. No explicit timing
  constants were found in the decompilation; timing is via TIM4 2 ms ticks
  and RAM counters.
- **Hidden command semantics** - 0x0B/0x0D/0x19 handlers recovered in code
  (see `docs/hidden_commands.md`); exact behavior still needs hardware testing
  via `tools/bench_probe.py --probe-hidden` (guarded).
- **PWM bench re-test** - prescaler fix is in the prebuilt image; 50-200 Hz
  has not been re-measured on hardware.

### Project administration
- **Working README vs public repo alignment** - current working README aligns
  with public repo (local-only section added).
- **License** - MIT for custom code; stock dumps not claimed; vendor material
  remains property of respective owners. Third-party notices added to NOTICE.md.
- **Public vs local archive** - `local_archive/` contains raw prints; public repo
  has derived, publishable copies (`MANIFEST.sha256` tracked).
- **Reproduce-from-scratch instructions** - `tools/verify_builds.py` is the
  acceptance test; run it on a clean clone to confirm.
- **Publication checklist** - compliance doc still pending.

### Open code gaps
- **Channel -> MCU pin map (QFN-48) details** - QFN48 pinout incomplete; pin 2
  ch2 PA2 inferred by elimination, not yet wire-verified.
- **Display UART continuity** - measure STM8 PD5/PD6 to ASR UART2/UART3 pins
  (narrowed list in `docs/asr5601_datasheet.md`).
- **J2-only LED control** - unsolved; LEDs are under ASR UI control over J2 alone.
- **Gateway/PDU hardware** - CAN controller choice, current sensing not decided.
- **Original vector datasheet** - 2 MB PDF unavailable; only OCR/print copies.

## Removed speculation
The earlier `docs/protocol_analysis.md` guesses (start bytes 0xAA/0x55, command
codes 0x01–0x10, CRC-8 0x07) remain unverified guesses and are contradicted by
nothing yet - but no evidence for them has been found in the image either. Do not
build on them until live capture confirms the frame format.

## Next steps
1. Flash the rebuilt base board firmware with the prescaler fix and re-test low
   PWM frequencies (123 Hz, 777 Hz, 1.5 kHz).
2. Confirm the four channel modes on hardware (toggle / momentary / pulse /
   blinking); extract blink/pulse timing and EEPROM encoding.
3. Bench J3: probe the ASR at 115200/921600, confirm `1F2E3D00`, try
   `coredump flash all`.
4. Map LED colors (tools/led_color_sweep.py) and identify the display UART
   continuity.
5. Implement the CAN gateway on the confirmed protocol.
