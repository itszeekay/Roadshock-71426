# Channel Capability Guide

Each of the 8 output channels has different hardware capabilities. This guide explains what each channel can do and what it's best suited for.

---

## Quick Reference

| Ch | Terminal | Fuse | Pin | Hardware PWM | Timer | Freq Group | Best For |
|----|----------|------|-----|--------------|-------|------------|----------|
| **1** | 1 | 30 A | PA3 | ✅ Yes | TIM2_CH3 | B | Radiator fan, fuel pump (variable speed) |
| **2** | 2 | 30 A | PA2 | ❌ No | - | - | High-current on/off (winch, compressor) |
| **3** | 3 | 20 A | PC7 | ✅ Yes | TIM1_CH2 | A | LED light bars (dimming) |
| **4** | 4 | 20 A | PC6 | ✅ Yes | TIM1_CH1 | A | LED light bars (dimming) |
| **5** | 5 | 10 A | PC5 | ✅ Yes (AFR0) | TIM2_CH1 | B | Aux fan, fuel pump #2 (variable speed), wiper PWM |
| **6** | 6 | 10 A | PC4 | ✅ Yes | TIM1_CH4 | A | LED light bars (dimming) |
| **7** | 7 | 5 A | PC3 | ✅ Yes | TIM1_CH3 | A | LED light bars (dimming) |
| **8** | 8 | 5 A | PD2 | ❌ No | - | - | Low-current on/off (ECU, relay coil) |

**All 8 outputs are 12 V high-side switched.** The table shows which have hardware PWM for smooth duty control.

---

## Frequency Groups

| Group | Timer | Channels | Frequency Range | Independent Duty Cycles |
|-------|-------|----------|-----------------|------------------------|
| **A** | TIM1 (advanced) | 3, 4, 6, 7 | 50–2000 Hz (shared) | 4 |
| **B** | TIM2 (general) | 1, 5 | 1 Hz–20 kHz (shared) | 2 |

- **Group A (TIM1):** 4 channels share one frequency. Each has its own duty cycle. Best for LED dimming where all lights should run at the same PWM frequency.
- **Group B (TIM2):** 2 channels share one frequency. Each has its own duty cycle. Best for fans/pumps needing independent speed control.

---

## Channel-by-Channel Detail

### Channel 1 (Terminal 1, 30 A, PA3) - **Hardware PWM (Group B)**
- **Hardware PWM:** Yes, TIM2_CH3 (default, no remap needed)
- **Frequency:** Shared with Channel 5 (1 Hz–20 kHz)
- **Duty cycle:** Independent
- **Software PWM:** Not needed
- **Best use:** Radiator fan, fuel pump prime/run, any variable-speed motor
- **Notes:** 30 A fuse, dual MOSFETs. Highest current capability with hardware PWM.

### Channel 2 (Terminal 2, 30 A, PA2) - **GPIO Only**
- **Hardware PWM:** No (no timer alternate function on PA2)
- **Software PWM:** Available but coarse (~2 ms steps, ~500 Hz base)
- **Best use:** High-current on/off only (winch, air compressor, starter solenoid)
- **Notes:** 30 A fuse, dual MOSFETs. **Do not use for fan speed control or smooth dimming.** Software PWM is too coarse.

### Channel 3 (Terminal 3, 20 A, PC7) - **Hardware PWM (Group A)**
- **Hardware PWM:** Yes, TIM1_CH2
- **Frequency:** Shared with Ch 4, 6, 7 (50–2000 Hz)
- **Duty cycle:** Independent
- **Software PWM:** Not needed
- **Best use:** LED light bar dimming
- **Notes:** 20 A fuse, single MOSFET.

### Channel 4 (Terminal 4, 20 A, PC6) - **Hardware PWM (Group A)**
- **Hardware PWM:** Yes, TIM1_CH1
- **Frequency:** Shared with Ch 3, 6, 7 (50–2000 Hz)
- **Duty cycle:** Independent
- **Software PWM:** Not needed
- **Best use:** LED light bar dimming
- **Notes:** 20 A fuse, single MOSFET.

### Channel 5 (Terminal 5, 10 A, PC5) - **Hardware PWM (Group B, AFR0)**
- **Hardware PWM:** Yes, TIM2_CH1 (requires AFR0 in option byte 0x4803)
- **AFR0:** Enabled by default in `board_init()` - no user action needed
- **Frequency:** Shared with Channel 1 (1 Hz–20 kHz)
- **Duty cycle:** Independent
- **Software PWM:** Not needed
- **Best use:** Auxiliary fan, second fuel pump, wiper motor PWM
- **Notes:** 10 A fuse, single MOSFET. Shares frequency with Channel 1. **Preferred channel for wiper PWM** thanks to 10 A rating and independent TIM2 frequency.

### Channel 6 (Terminal 6, 10 A, PC4) - **Hardware PWM (Group A)**
- **Hardware PWM:** Yes, TIM1_CH4
- **Frequency:** Shared with Ch 3, 4, 7 (50–2000 Hz)
- **Duty cycle:** Independent
- **Software PWM:** Not needed
- **Best use:** LED light bar dimming
- **Notes:** 10 A fuse, single MOSFET.

### Channel 7 (Terminal 7, 5 A, PC3) - **Hardware PWM (Group A)**
- **Hardware PWM:** Yes, TIM1_CH3
- **Frequency:** Shared with Ch 3, 4, 6 (50–2000 Hz)
- **Duty cycle:** Independent
- **Software PWM:** Not needed
- **Best use:** LED light bar dimming
- **Notes:** 5 A fuse, single MOSFET.

### Channel 8 (Terminal 8, 5 A, PD2) - **GPIO Only**
- **Hardware PWM:** No (AFR1 would steal TIM2_CH3 from Channel 1 - not recommended)
- **Software PWM:** Available but coarse (~2 ms steps, ~500 Hz base)
- **Best use:** Low-current on/off (ECU power, relay coil, indicator LED)
- **Notes:** 5 A fuse, single MOSFET. **Do not use for smooth control.** Software PWM only.

---

## Software PWM - When Is It Fine?

| Channel | Software PWM Acceptable? | Why |
|---------|--------------------------|-----|
| 1, 3, 4, 5, 6, 7 | **No - use hardware PWM** | Hardware PWM available, smoother, zero CPU load |
| 2, 8 | **Only for simple on/off, blink, or very slow dimming** | Coarse steps (~2 ms), CPU must service tick |

**Software PWM limitations:**
- Runs on 2 ms scheduler tick (~500 Hz base rate)
- Duty steps = multiples of 2 ms → very coarse at low frequencies
- CPU must service tick; no hardware offload
- **Avoid for:** fan speed control, fuel pump ramp, any smooth curve, wiper speed
- **OK for:** simple blink, slow dimming where precision doesn't matter, on/off with delay

---

## Typical Wiring Assignments

| Function | Recommended Channel(s) | Reason |
|----------|------------------------|--------|
| Radiator fan (variable) | **1** | 30 A, hardware PWM, independent freq |
| Fuel pump (prime + run) | **1** | Soft-start, independent freq |
| Aux fan #2 (variable) | **5** | 10 A, hardware PWM, shares freq with Ch 1 |
| LED light bars (dim) | **3, 4, 6, 7** | Share freq, independent brightness |
| Water pump (on/off) | **2** or **5** | High current, simple on/off |
| Wiper PWM | **5** | 10 A, hardware PWM (Group B), independent freq |
| Ignition / ECU power | **7** or **8** | Low current, GPIO fine |
| Compressor clutch | **5** or **8** | On/off only |
| Winch / high-current load | **2** | 30 A, dual MOSFETs |
| Relay coil / signal | **8** | 5 A, low current |

---

## Protocol Control (Custom Firmware)

| Command | Type | Payload | Description |
|---------|------|---------|-------------|
| Config channel | 0x09 | `[chan, mode, duty, freq_lo, freq_hi, delay_secs]` | mode 0=off, 1=on, 2=PWM |
| Status request | 0x0A | (empty) | Returns 6 channel states + master |
| Force override | 0x0B | `[chan, action]` | 0=off, 1=on, 2=toggle |
| Option byte (AFR) | 0x0C | `[action, value]` | Read/write AFR (power cycle needed) |
| Wiper control | 0x0D | `[action, param]` | Wiper mode/speed control |

---

## EEPROM Persistence (Custom Firmware)

All channel settings auto-save to EEPROM on any state change:

| Address | Contents |
|---------|----------|
| 0x0D–0x14 | Per-channel: mode (2 bits), on (1 bit), delayed_off_en (1), double_tap_en (1) |
| 0x15–0x1C | Delayed-off seconds per channel (0–255) |

---

## Summary

- **6 channels have hardware PWM** (1, 3, 4, 5, 6, 7) - use these for any smooth control (dimming, fan speed, wiper speed)
- **2 channels are GPIO only** (2, 8) - use for simple on/off; software PWM is too coarse for smooth control
- **Channel 1 & 5 share frequency** (Group B) - good for two independent fans/pumps
- **Channels 3, 4, 6, 7 share frequency** (Group A) - good for multiple LED bars at same PWM frequency
- **AFR0 is enabled by default** - Channel 5 PWM works out of the box with custom firmware