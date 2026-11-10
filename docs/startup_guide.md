# Quick Start & PWM Guide

## Flash the Custom Firmware

```bash
cd firmware
make
stm8flash -c stlinkv2 -p stm8s003f3 -s flash -w roadshock_full.ihx
```

Stock restore: `restore/base_flash.raw.bin`

---

## Hardware PWM Assignment (All 8 Channels)

| Ch | Terminal | Fuse | Pin | Hardware PWM | Timer / Channel | Freq Group | Duty Cycle | Notes |
|----|----------|------|-----|--------------|-----------------|------------|------------|-------|
| **1** | 1 | 30 A | **PA3** | ✅ **Yes** | TIM2_CH3 (default) | **B** | Independent | Best for fan/fuel-pump ramp |
| **2** | 2 | 30 A | PA2 | ❌ No | - | - | - | GPIO only (no timer AF) |
| **3** | 3 | 20 A | PC7 | ✅ Yes | TIM1_CH2 | **A** | Independent | Shared freq with 4,6,7 |
| **4** | 4 | 20 A | PC6 | ✅ Yes | TIM1_CH1 | **A** | Independent | Shared freq with 3,6,7 |
| **5** | 5 | 10 A | PC5 | ✅ **With AFR0** | TIM2_CH1 (remap) | **B** | Independent | Same freq as Ch 1 |
| **6** | 6 | 10 A | PC4 | ✅ Yes | TIM1_CH4 | **A** | Independent | Shared freq with 3,4,7 |
| **7** | 7 | 5 A | PC3 | ✅ Yes | TIM1_CH3 | **A** | Independent | Shared freq with 3,4,6 |
| **8** | 8 | 5 A | PD2 | ❌ No | - | - | - | GPIO only (AFR1 steals Ch 1) |

**All 8 outputs are 12 V high-side switched.** The table above only shows which have hardware PWM for smooth duty control.

---

## Frequency Groups

| Group | Timer | Channels | Frequency | Duty Cycles |
|-------|-------|----------|-----------|-------------|
| **A** | TIM1 (advanced) | **3, 4, 6, 7** | **1 shared** (50–2000 Hz) | **4 independent** |
| **B** | TIM2 (general) | **1, 5** | **1 shared** (1 Hz–20 kHz) | **2 independent** |

- **Independent duty cycle = each channel has its own CCR register.**
- **Shared frequency = all channels in a group run at the same PWM frequency (set by ARR/PSC).**
- **Channel 5 (PC5) gets hardware PWM via AFR0**, which is enabled by default in `board_init()`. No build flags needed.

---

## Typical Assignments (Recommended)

| Function | Channel | Reason |
|----------|---------|--------|
| Radiator fan (variable) | **1 (Group B)** | Independent freq for smooth ramp |
| Fuel pump (prime + run) | **1 (Group B)** | Soft-start, independent freq |
| LED light bars (dim) | **3, 4, 6, 7 (Group A)** | Share freq, independent brightness |
| Aux fans (if 2+) | **1 + 5 (Group B)** | Enable `PWM_ENABLE_CH5` for 2nd fan |
| Water pump (on/off) | 2 or 5 | High current, simple on/off |
| Wiper PWM | **5 (Group B)** | 10 A fuse, independent TIM2 freq |
| Ignition/ECU power | 7 or 8 | Low current, GPIO |
| Compressor clutch | 5 or 8 | On/off |

---

## Protocol Commands (2400 baud, 8N1)

| Type | Payload | Description |
|------|---------|-------------|
| 0x07 | `flag: 0/1` | Master off/on |
| 0x08 | `flag: 0x0C, 6 bytes` | Button bitmask (panel → base) |
| 0x09 | `[chan, mode, duty, freq_lo, freq_hi, delay_secs]` | Config: mode 0=off, 1=on, 2=PWM; delay 0–255 s run-on |
| 0x0A | (request) | Status: returns 6 channel states + master |
| 0x0B | `[chan, action]` | Force: 0=off, 1=on, 2=toggle |

---

## Software PWM (Channels 2, 8)

- Runs on 2 ms scheduler tick (~500 Hz base)
- Duty steps = multiples of 2 ms → coarse at low frequencies
- CPU must service tick; no hardware offload
- **Avoid for:** fan speed control, fuel pump ramp, any smooth curve
- **OK for:** simple blink, slow dimming where precision doesn't matter

*Channels 1, 3, 4, 5, 6, 7 have hardware PWM. Channels 2 and 8 are GPIO only.*

---

## EEPROM Persistence

Auto-saved on button press/release, master toggle, config (0x09), force (0x0B).

| Address | Contents |
|---------|----------|
| 0x0D–0x14 | Mode (2 bits), on (1 bit), delayed_off_en (1), double_tap_en (1) |
| 0x15–0x1C | Delayed-off seconds per channel (0–255) |

---

## Long-Press Valet

Hold any button **800 ms** → master off (anti-theft).

---

## Delayed-Off (Fan Run-On)

Enable via config (0x09) with `delay_secs` > 0. On momentary release, channel stays on for configured seconds, then auto-off.

---

## Double-Tap Latch

Momentary mode + `double_tap_en` flag: two presses < 1 s → toggles latch on/off.

---

## Force Override (Middle MCU)

Type 0x0B: immediate on/off/toggle, bypasses state machine. Cleared by next panel event.

---

## ACC Sense

PA1 low → all outputs off (polled every 2 ms). No MCU reset.

---

## Status Frame (Type 0x0A)

Returns 6 bytes: channels 1–6 on/off, byte 6 = master state. Request by sending type 0x0A.