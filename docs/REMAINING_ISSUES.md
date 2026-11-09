# Roadshock project - remaining issues and plan

Status: updated 2026-11-09. Items marked RESOLVED were closed by the
Roadstm8true / Roadstm8Panel Ghidra runs; the rest are hardware-blocked.

## Firmware / decompilation

1. **UART baud divisor** - RESOLVED (static caller found). `uart1_init_2400`
   (0x9B17) sets `DAT_0002=0x960` and CALLs `uart1_configure` (0x8F7E).
   Live value: 2400 baud (BRR1=0xA0, BRR2=0x1A, divider 6666). See
   `docs/mode_timing.md`.

2. **Reset vector anomaly** - RESOLVED (documented). Vector slot 0 parses to
   0x9C82 (`flash_write_key_56` stub). Real startup is 0x9CD8 (`reset_startup`,
   SP=0x03FF). Confirmed in `firmware_reconstructed_true.c` and the Roadstm8true
   decomp.

3. **UART pins** - OPEN (hardware). Firmware uses PD5/TX and PD6/RX. PD1/PD2
   mapping is assumed from the datasheet and not yet confirmed on the PCB.

4. **Addresses 0x5062/0x5064** - RESOLVED (confirmed in code).
   `flash_key_dispatch` (0x9C1B) writes the 0x56/0xAE unlock sequences to
   `FLASH_KEYREG_A` (0x5062) and `FLASH_KEYREG_B` (0x5064). The block differs
   from the STM8S003 datasheet PUKR address (0x5056); the firmware idiom is
   authoritative.

5. **Decode drift zones** - RESOLVED. The zones 0x8080-0x8130, 0x8FA0-0x8FA8,
   0x9510-0x9545 were artifacts of the textcorrupt dump (sha256 98ca8aba...).
   On the corrected dump (Roadstm8true, 256/256 functions, 0 failures) the
   drift is gone. `Roadstm8` (textcorrupt) must not be used.

6. **Four stock modes** - PARTIAL. Dispatch recovered in `mode_handler` (0x816D):
   incoming 1/3/5/7 -> internal 0/2/4/8; dispatch writes `0x10*N` or `*pb | N`.
   Toggle/momentary/pulse/blinking identified. Type-7 path goes through
   `config_mode_handler` (0x8146). Blink period, pulse duration, and EEPROM
   encoding (0x0D-0x14) still need bench measurement. No explicit timing
   constants were found in the decompilation; timing is via TIM4 2 ms ticks
   and RAM counters. See `docs/mode_timing.md`.

7. **Panel LED map** - PARTIAL. Nibble->pin table fully recovered in
   `display_frame_handler` (0x844C): 0/2/4/6=off, 1=pin1, 3=pin3, 5=pin2,
   7=pin1+pin2, 8-15=unchanged (active-low). Pin table at flash 0x8AB4 /
   RAM 0x0010 verified. Which pin is R/G/B per channel is still a bench
   measurement via `tools/led_color_sweep.py`. See `docs/panel_led_map.md`.

8. **Hidden commands** - PARTIAL. `frame_handler` (0x851A) dispatch recovered:
   type 7 = master power/parameter, type 8 = button bitmask, 0x0B/0x0D/0x19 =
   `cmd_0b_handler`/`cmd_0d_handler`/`cmd_19_handler`. Exact semantics still
   need hardware testing via `tools/bench_probe.py --probe-hidden` (guarded).
   See `docs/hidden_commands.md`.

9. **PWM edge cases** - RESOLVED (code-reviewed and documented).
   `pwm_set_duty`: 0% -> CCR 0, 100% -> CCR ARR+1; `pwm_set_frequency` clamps
   50-2000 Hz with prescaler 8x. Bench re-test at 123/777/1500 Hz still needed
   to confirm the prescaler fix.

## Hardware-blocked

10. **ASR5601S firmware dump** - OPEN. Requires the J3 bench session
    (115200/921600 probe, `1F2E3D00`, `coredump flash all`, read twice,
    compare SHA-256).

11. **Display UART continuity** - OPEN. Measure STM8 PD5/PD6 to ASR UART2/UART3
    candidates (narrowed list in `docs/asr5601_datasheet.md`). Checklist:
    `tools/bench_probe.py --checklist display-uart`.

12. **Pin 2 (ch2 PA2)** - OPEN. Inferred by elimination; not wire-verified.

13. **J2-only LED control** - OPEN. Unsolved; LEDs are under ASR UI control
    over J2 alone.

14. **CAN gateway/PDU hardware** - OPEN. Controller choice (MCP2515 vs CAN2040
    vs ESP32 TWAI), current sensing not decided.

15. **Original vector datasheet** - OPEN. 2 MB, 46-page PDF unavailable; only
    OCR/print copies exist.

## Project administration

16. **Reproduce-from-scratch** - OPEN (tool ready). Run `python3
    tools/verify_builds.py` on a clean clone; it checks checksums, compile,
    HEX line endings, and tool self-tests.

17. **Publication checklist** - PARTIAL. Third-party notices added to
    NOTICE.md. Compliance doc still pending.
