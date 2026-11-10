# Quick Start & PWM Guide

## Flash the Custom Firmware

```bash
cd firmware
make
stm8flash -c stlinkv2 -p stm8s003f3 -s flash -w roadshock_full.ihx
```

Stock restore: `restore/base_flash.raw.bin`

---

## Hardware PWM Quick Reference

| Channel | Terminal | Fuse | Pin | Timer | Best For |
|---------|----------|------|-----|-------|----------|
| **1** | 1 | 30 A | **PA3** | **TIM2 (independent)** | **Variable-speed fans, fuel pump ramp, soft-start** |
| **2** | 2 | 30 A | PA2 | — | High-current on/off only (crystal pin) |
| **3** | 3 | 20 A | PC7 | TIM1 CH2 (Group A) | LED dimming, PWM loads sharing freq |
| **4** | 4 | 20 A | PC6 | TIM1 CH1 (Group A) | LED dimming, PWM loads sharing freq |
| **5** | 5 | 10 A | PC5 | — | GPIO only (SPI SCK) |
| **6** | 6 | 10 A | PC4 | TIM1 CH4 (Group A) | LED dimming, PWM loads sharing freq |
| **7** | 7 | 5 A | PC3 | TIM1 CH3 (Group A) | LED dimming, PWM loads sharing freq |
| **8** | 8 | 5 A | PD2 | — | GPIO only |

---

## PWM Groups

**Group A (TIM1):** Channels 3, 4, 6, 7 share **one frequency** (50–2000 Hz). Each has **independent duty cycle** (0–100%). Use when multiple loads need the same PWM frequency but different intensities.

**Group B (TIM2):** Channel 1 has its **own independent frequency** (1 Hz – 20 kHz). Use for fan speed curves, fuel pump priming ramps, soft-start profiles.

**Channels 2, 5, 8:** GPIO only — on/off. Software PWM via 2 ms tick (~500 Hz max, coarse duty steps).

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

## Typical Assignments

| Function | Channel | Why |
|----------|---------|-----|
| Radiator fan (variable) | **1 (TIM2)** | Independent freq for smooth ramp/curve |
| Fuel pump (prime + run) | **1 (TIM2)** | Soft-start, independent from fan freq |
| LED light bars (dimming) | 3, 4, 6, 7 (TIM1) | Share freq, independent brightness |
| Water pump (on/off) | 2 or 5 | High current, simple on/off |
| Ignition/ECU power | 7 or 8 | Low current, GPIO |
| Aux lights | 3, 4, 6, 7 (TIM1) | PWM dimming |
| Compressor clutch | 5 or 8 | On/off |

---

## Software PWM Limitations

- Runs on 2 ms scheduler tick (~500 Hz base)
- Duty steps = multiples of 2 ms → coarse at low frequencies
- CPU must service tick; no hardware offload
- **Avoid for:** fan speed control, fuel pump ramp, any smooth curve
- **OK for:** simple blink, slow dimming where precision doesn't matter

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