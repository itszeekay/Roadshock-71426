# Firmware Comparison: Stock vs. Custom Base Board

The middle MCU (Feather RP2040, ESP32, or carrier) can run three configurations.

## Feature Matrix

| Capability | Stock (no middle MCU) | Middle MCU only (stock firmware) | Middle MCU + custom firmware |
|---|---|---|---|
| **Channel modes** | Toggle, Momentary, Pulse, Blink | Toggle, Momentary, Pulse, Blink | Same, plus runtime persistence |
| **Mode selection** | Panel Mode button | Type 0x07 config frames | Same |
| **Master on/off** | Panel button | Type 0x07 flag 0/1 | Same |
| **Button events** | Panel buttons | Type 0x08 flag 0x0C | Same, plus synthetic presses |
| **PWM / dimming** | No | No | **Type 0x09**: TIM1 freq 50-2000 Hz, duty 0-100 on ch 3,4,6,7; **TIM2 independent freq+duty on ch 1** |
| **Status reporting** | No | No | **Type 0x0A**: 6-channel state + master |
| **Long-press valet** | No | No | **800 ms** hold → master off |
| **Delayed-off run-on** | No | No | **Configurable** (type 0x09 delay_secs) |
| **Double-tap latch** | No | No | **Via flags bit1** |
| **Force on/off** | No | No | **Type 0x0B**: override channel |
| **ACC sense** | ISR → full reset | Polled → outputs off | Polled → outputs off (no reset) |
| **Watchdog** | IWDG | IWDG | Main loop fed |

## Notes

- **Stock**: Panel behavior only; middle MCU adds nothing beyond injection via existing types.
- **Middle MCU only**: The stock firmware accepts type 0x07/0x08 for power/mode/button control. No PWM, no status, no timing features.
- **Custom**: Adds PWM config, status, long-press, delayed-off, double-tap, force, and EEPROM persistence.

To use the middle MCU + custom firmware, flash `firmware/roadshock_full.ihx` once via SWIM. To fall back, use the stock restore image.
