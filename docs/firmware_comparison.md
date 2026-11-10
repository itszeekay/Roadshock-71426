# Firmware Comparison: Stock vs. Custom Base Board

Three ways to run the panel:

| Capability | Stock (no middle MCU) | Middle MCU + stock firmware | Middle MCU + custom firmware |
|------------|----------------------|----------------------------|------------------------------|
| **Channel modes** | Toggle, Momentary, Pulse, Blink | Same | Same, but settings persist after power loss |
| **Change modes** | Panel Mode button only | Type 0x07 config frames | Same |
| **Master on/off** | Panel power button | Type 0x07 flag 0/1 | Same |
| **Button control** | Physical buttons only | Type 0x08 synthetic presses | Same |
| **PWM / dimming** | No | No | **Yes** — 6 channels (1,3,4,5,6,7), independent duty |
| **Status feedback** | LED colors only | No | **Type 0x0A** — 6 channel states + master |
| **Long-press valet** | No | No | **800 ms hold** → master off |
| **Delayed-off (fan run-on)** | No | No | **Configurable 0–255 s** per channel |
| **Double-tap latch** | No | No | **Two quick presses** → momentary becomes toggle |
| **Force override** | No | No | **Type 0x0B** — immediate on/off/toggle |
| **ACC/ignition sense** | Resets MCU on loss | Outputs off, no reset | Outputs off, no reset |

## What each configuration gives you

**Stock (panel only)** — Works out of the box. Four modes via Mode button. No external control.

**Middle MCU + stock firmware** — External MCU can inject button presses and power commands over the 2400 baud link. No PWM, no status, no persistence.

**Middle MCU + custom firmware** — Full control: PWM on 6 channels, status reporting, persistent settings, valet mode, fan run-on timers, double-tap latching, force override. Flash once via SWIM (`roadshock_full.ihx`).

## Hardware PWM availability (custom firmware)

| Channel | Fuse | Hardware PWM | Frequency Group |
|---------|------|--------------|-----------------|
| 1 | 30 A | ✅ TIM2 | B (independent) |
| 2 | 30 A | ❌ | — |
| 3 | 20 A | ✅ TIM1 | A (shared) |
| 4 | 20 A | ✅ TIM1 | A (shared) |
| 5 | 10 A | ✅ TIM2 (AFR0) | B (shared with ch 1) |
| 6 | 10 A | ✅ TIM1 | A (shared) |
| 7 | 5 A | ✅ TIM1 | A (shared) |
| 8 | 5 A | ❌ | — |

Group A (TIM1): Channels 3,4,6,7 share one frequency (50–2000 Hz), 4 independent duties.
Group B (TIM2): Channels 1,5 share one frequency (1 Hz–20 kHz), 2 independent duties.
Channels 2,8: GPIO only (software PWM available, coarse).

See `docs/startup_guide.md` for wiring recommendations and protocol details.