# What the stock firmware accepts over UART

MCU: **STM8S003F3P6** (base board). The Feather/MITM sits on J2, which
carries only the 2400-baud panel link. Everything in this note is a
stock-firmware behavior over that link; no firmware is flashed.

## What works with the stock firmware

These are verified in the decompilation and, for the first two, on the wire:

- **Button events** (type 0x08, flag 0x0C): `button_bitmask_handler` (0x82B3)
  drives the per-channel mode logic (toggle / momentary / pulse / blinking).
  A press/release sequence sent by the Feather produces the same output
  behavior as a panel button.
- **Master power** (type 0x07, flag 0/1): `frame_handler` posts to the mode
  handlers. Off forces every output to zero; on restores the state machine.
- **Per-channel mode config** (type 0x07 with a 6-byte payload): each payload
  byte expands to two nibbles (12 nibbles total) and `config_mode_handler`
  (0x8146) writes the channel state patterns (`0x10`..`0x80`) through
  `channel_state_write` (0x828D). This is how the mode double-click persists
  a choice. The Feather can set modes without the Mode button.
- **Acknowledgements**: every accepted frame gets a reply (`dir = 0xFF`,
  `type | 0x10`), so a MITM can observe success.

## What does not work via UART

- **Arbitrary PWM / duty / dimming.** The stock outputs are GPIO on/off.
  TIM2 timer helpers exist (`tim2_period_init` (0x9ECF),
  `tim2_duty_write` (0x9E61), `tim2_period_hi` (0x9E6A)) and the reset path
  starts the timer (`tim4_reset`, 0x9A0B), but there is no CCMR/CCER write
  anywhere in the image, and `outputs_init` (0x94D6) drives every pin with
  `gpio_init` (0x9541). No PWM output reaches the pins. Dimming over UART
  requires custom firmware (the TIM1 build in `firmware/src/`).
- **Panel LEDs.** The 115200 display frames are internal to the panel PCB
  (ASR to STM8). Nothing on the 2400-baud bus carries LED colors; the base
  replies echo the request payload. LED control needs a display-link tap or
  an ASR replacement, neither of which is part of the J2 gateway (see
  `roadmap.md` and `panel_led_map.md`).
- **Firmware replacement.** The STM8S003 has no UART bootloader. SWIM is the
  only programming interface. `frame_handler` has no path to
  `flash_unlock` (0x9CA7) or `flash_key_dispatch` (0x9C1B); only the boot
  chains call those.

## Hidden commands (risky, bench-only)

The dispatcher also accepts three types the panel never sends. Semantics are
recovered in code but unconfirmed on hardware. The `bench_probe.py`
guarded probe requires an explicit confirmation and a verified restore
image, because `0x0B` writes EEPROM:

- **0x0B** (`cmd_0b_handler`, 0x8640): payload byte 1..0x64, must differ from
  `cfg_value` (0x0206); stores it and writes EEPROM via `eeprom_write`.
- **0x0D** (`cmd_0d_handler`, 0x8689): payload 0 sets the scheduler timer to
  10000; payload 1 runs `reset_state` and sets `cfg_value` to 10.
- **0x19** (`cmd_19_handler`, 0x860C): searches the message queue for a
  matching sequence and clears it.

See `hidden_commands.md` for the handler detail. Do not send these on
hardware without dumps and a restore plan.

## Summary

| Capability | Stock firmware over J2 | Notes |
|---|---|---|
| Button events, master power | Yes | Verified on the wire |
| Per-channel mode select | Yes | Via type-7 nibbles |
| PWM / duty / dimming | No | Needs custom TIM1 firmware |
| Panel LED colors | No | Display link is panel-internal |
| Flash / firmware replacement | No | SWIM only; no UART boot loader |
| Config persistence | Partial | Hidden 0x0B writes EEPROM (guarded) |
