# Channel Capability Guide

Each of the 8 output channels has different hardware capabilities. This guide
explains what each channel can do and what it is best suited for.

---

## Quick Reference

| Ch | Terminal | Fuse | Pin | Hardware PWM | Timer | Freq Group |
|----|----------|------|-----|--------------|-------|------------|
| **1** | 1 | 30 A | PA3 | Yes | TIM2_CH3 | B |
| **2** | 2 | 30 A | PA2 | No (GPIO only) | - | - |
| **3** | 3 | 20 A | PC7 | Yes | TIM1_CH2 | A |
| **4** | 4 | 20 A | PC6 | Yes | TIM1_CH1 | A |
| **5** | 5 | 10 A | PC5 | Yes (AFR0) | TIM2_CH1 | B |
| **6** | 6 | 10 A | PC4 | Yes | TIM1_CH4 | A |
| **7** | 7 | 5 A | PC3 | Yes | TIM1_CH3 | A |
| **8** | 8 | 5 A | PD2 | No (GPIO only) | - | - |

**All 8 outputs are 12 V high-side switched.** Channels 1, 3, 4, 5, 6, 7 have
hardware PWM; channels 2 and 8 are GPIO only.

---

## Frequency Groups

| Group | Timer | Channels | Frequency | Independent Duty Cycles |
|-------|-------|----------|-----------|-------------------------|
| **A** | TIM1 (advanced) | 3, 4, 6, 7 | 50-2000 Hz, shared | 4 |
| **B** | TIM2 (general) | 1, 5 | 1 Hz-20 kHz, shared | 2 |

- **Group A (TIM1):** 4 channels share one frequency. Each channel has its own duty cycle register. All four channels run at the same PWM frequency; brightness is set independently.
- **Group B (TIM2):** 2 channels share one frequency. Each channel has its own duty cycle register. Two independent duty cycles at one shared frequency.

---

## Channel-by-Channel Detail

### Channel 1 (Terminal 1, 30 A, PA3) - Hardware PWM (Group B)
- **Hardware PWM:** Yes, TIM2_CH3 (default, no remap needed)
- **Frequency:** Shared with Channel 5 (1 Hz-20 kHz)
- **Duty cycle:** Independent
- **Best use:** Variable-speed loads (radiator fan, fuel pump)
- **Notes:** 30 A fuse, dual MOSFETs. Highest current capability with hardware PWM.

### Channel 2 (Terminal 2, 30 A, PA2) - GPIO Only
- **Hardware PWM:** No (no timer alternate function on PA2)
- **Software PWM:** Available but coarse (2 ms steps, 500 Hz base)
- **Best use:** High-current on/off only (winch, air compressor, starter solenoid)
- **Notes:** 30 A fuse, dual MOSFETs. Use only for simple on/off.

### Channel 3 (Terminal 3, 20 A, PC7) - Hardware PWM (Group A)
- **Hardware PWM:** Yes, TIM1_CH2
- **Frequency:** Shared with Ch 4, 6, 7 (50-2000 Hz)
- **Duty cycle:** Independent
- **Best use:** LED light bar dimming
- **Notes:** 20 A fuse, single MOSFET.

### Channel 4 (Terminal 4, 20 A, PC6) - Hardware PWM (Group A)
- **Hardware PWM:** Yes, TIM1_CH1
- **Frequency:** Shared with Ch 3, 6, 7 (50-2000 Hz)
- **Duty cycle:** Independent
- **Best use:** LED light bar dimming
- **Notes:** 20 A fuse, single MOSFET.

### Channel 5 (Terminal 5, 10 A, PC5) - Hardware PWM (Group B, AFR0)
- **Hardware PWM:** Yes, TIM2_CH1 (requires AFR0 in option byte 0x4803)
- **AFR0:** Enabled by default in `board_init()`, no user action needed
- **Frequency:** Shared with Channel 1 (1 Hz-20 kHz)
- **Duty cycle:** Independent
- **Best use:** Auxiliary fan, second fuel pump, or other variable-speed load
- **Notes:** 10 A fuse, single MOSFET. Shares frequency with Channel 1.

### Channel 6 (Terminal 6, 10 A, PC4) - Hardware PWM (Group A)
- **Hardware PWM:** Yes, TIM1_CH4
- **Frequency:** Shared with Ch 3, 4, 7 (50-2000 Hz)
- **Duty cycle:** Independent
- **Best use:** LED light bar dimming
- **Notes:** 10 A fuse, single MOSFET.

### Channel 7 (Terminal 7, 5 A, PC3) - Hardware PWM (Group A)
- **Hardware PWM:** Yes, TIM1_CH3
- **Frequency:** Shared with Ch 3, 4, 6 (50-2000 Hz)
- **Duty cycle:** Independent
- **Best use:** LED light bar dimming
- **Notes:** 5 A fuse, single MOSFET.

### Channel 8 (Terminal 8, 5 A, PD2) - GPIO Only
- **Hardware PWM:** No (AFR1 would steal TIM2_CH3 from Channel 1, not recommended)
- **Software PWM:** Available but coarse (2 ms steps, 500 Hz base)
- **Best use:** Low-current on/off (ECU power, relay coil, indicator LED)
- **Notes:** 5 A fuse, single MOSFET. GPIO only.

---

## Software PWM - When Is It Fine?

| Channel | Software PWM Acceptable | Why |
|---------|--------------------------|-----|
| 1, 3, 4, 5, 6, 7 | No, use hardware PWM | Hardware PWM available, smoother, zero CPU load |
| 2, 8 | Only for simple on/off, blink, or very slow dimming | Coarse steps (2 ms), CPU must service tick |

Software PWM runs on the 2 ms scheduler tick (500 Hz base rate). Duty steps are multiples of 2 ms, so control is coarse at low frequencies. The CPU must service the tick; there is no hardware offload. Use it only for simple on/off, blink, or slow dimming where precision does not matter.

---

## Typical Wiring Assignments

| Function | Recommended Channel(s) | Reason |
|----------|------------------------|--------|
| Radiator fan (variable) | **1** | 30 A, hardware PWM, independent duty |
| Fuel pump (prime + run) | **1** | Soft-start, independent duty |
| Aux fan (variable) | **5** | 10 A, hardware PWM, shares frequency with Ch 1 |
| LED light bars (dim) | **3, 4, 6, 7** | Share frequency, independent brightness |
| Water pump (on/off) | **2** or **5** | High current, simple on/off |
| Ignition / ECU power | **7** or **8** | Low current, GPIO fine |
| Compressor clutch | **5** or **8** | On/off only |
| Winch / high-current load | **2** | 30 A, dual MOSFETs |
| Relay coil / signal | **8** | 5 A, low current |
