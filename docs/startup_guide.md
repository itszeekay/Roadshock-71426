# Quick Start & PWM Guide

This page walks through building the custom base firmware, wiring it for
hardware PWM, and using the protocol to drive the panel.

## Prerequisites

| Tool | Use |
|---|---|
| ST-Link V2 (or clone) + `stm8flash` | SWIM dump and flash |
| SDCC 4.5 | build the custom base firmware |
| Python 3 + `pyserial` | protocol tests and console capture |
| Adafruit Feather RP2040 + CircuitPython | bus capture / impersonation |

## Step 1: Build the Custom Firmware

```bash
cd firmware
make
```

The build produces:

- `build/roadshock.ihx`: application image.
- The full 8 KB image used for flashing is the prebuilt
  `firmware/prebuilt/roadshock_full.ihx`. The Makefile does not generate it.

Prebuilt images are in `firmware/prebuilt/`.

## Step 2: Flash the Custom Firmware

```bash
stm8flash -c stlinkv2 -p stm8s003f3 -s flash -w firmware/prebuilt/roadshock_full.ihx
```

Or `make flash-full` from `firmware/`. `make flash` writes the application image
built by `make`.

To run: disconnect `RST` / remove the ST-Link. The MCU is held in reset while
`RST` is wired.

12 V **off**. ST-Link on `V+`, `GND`, `SWIM`, `RST`.

## Step 3: Restore Stock (if needed)

```powershell
# verify only (read-only, default)
powershell -File restore\restore_stock.ps1

# actually restore
powershell -File restore\restore_stock.ps1 -Write
```

The script uses `stm8flash` from `PATH`; pass `-Flash <path>` if needed. It
covers the base board. The panel STM8 images are in `dumps/panel/`; write them
with the same commands and `-p stm8s003k3`.

## Step 4: Wire for Hardware PWM

All 8 outputs are 12 V high-side switched. The table shows which have hardware
PWM for smooth duty control.

| Ch | Terminal | Fuse | Pin | Hardware PWM | Timer / Channel | Freq Group | Duty Cycle | Notes |
|----|----------|------|-----|--------------|-----------------|------------|------------|-------|
| **1** | 1 | 30 A | **PA3** | Yes | TIM2_CH3 (default) | **B** | Independent | Best for fan/fuel-pump ramp |
| **2** | 2 | 30 A | PA2 | No | - | - | - | GPIO only (no timer AF) |
| **3** | 3 | 20 A | PC7 | Yes | TIM1_CH2 | **A** | Independent | Shared freq with 4,6,7 |
| **4** | 4 | 20 A | PC6 | Yes | TIM1_CH1 | **A** | Independent | Shared freq with 3,6,7 |
| **5** | 5 | 10 A | PC5 | Yes (AFR0) | TIM2_CH1 (remap) | **B** | Independent | Same freq as Ch 1 |
| **6** | 6 | 10 A | PC4 | Yes | TIM1_CH4 | **A** | Independent | Shared freq with 3,4,7 |
| **7** | 7 | 5 A | PC3 | Yes | TIM1_CH3 | **A** | Independent | Shared freq with 3,4,6 |
| **8** | 8 | 5 A | PD2 | No | - | - | - | GPIO only (AFR1 steals Ch 1) |

**Channel 5 (PC5) gets hardware PWM via AFR0**, which is enabled by default in
`board_init()`. No build flags needed.

## Step 5: Frequency Groups

| Group | Timer | Channels | Frequency | Duty Cycles |
|-------|-------|----------|-----------|-------------|
| **A** | TIM1 (advanced) | **3, 4, 6, 7** | **1 shared** (50-2000 Hz) | **4 independent** |
| **B** | TIM2 (general) | **1, 5** | **1 shared** (1 Hz-20 kHz) | **2 independent** |

- Independent duty cycle = each channel has its own CCR register.
- Shared frequency = all channels in a group run at the same PWM frequency (set by ARR/PSC).
- AFR0 is enabled by default in `board_init()`. Channel 5 PWM works out of the box with custom firmware.

## Step 6: Typical Assignments (Recommended)

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

## Step 7: Protocol Commands (2400 baud, 8N1)

| Type | Payload | Description |
|------|---------|-------------|
| 0x07 | `flag: 0/1` | Master off/on |
| 0x08 | `flag: 0x0C, 6 bytes` | Button bitmask (panel to base) |
| 0x09 | `[chan, mode, duty, freq_lo, freq_hi, delay_secs]` | Config: mode 0=off, 1=on, 2=PWM; delay 0-255 s run-on |
| 0x0A | (request) | Status: returns 6 channel states + master |
| 0x0B | `[chan, action]` | Force: 0=off, 1=on, 2=toggle |

## Step 8: Software PWM (Channels 2, 8)

- Runs on 2 ms scheduler tick (~500 Hz base)
- Duty steps = multiples of 2 ms, coarse at low frequencies
- CPU must service tick; no hardware offload
- Avoid for: fan speed control, fuel pump ramp, any smooth curve
- OK for: simple blink, slow dimming where precision does not matter

*Channels 1, 3, 4, 5, 6, 7 have hardware PWM. Channels 2 and 8 are GPIO only.*

## Step 9: EEPROM Persistence

Auto-saved on button press/release, master toggle, config (0x09), force (0x0B).

| Address | Contents |
|---------|----------|
| 0x0D-0x14 | Mode (2 bits), on (1 bit), delayed_off_en (1), double_tap_en (1) |
| 0x15-0x1C | Delayed-off seconds per channel (0-255) |

## Step 10: Long-Press Valet

Hold any button **800 ms**, master off (anti-theft).

## Step 11: Delayed-Off (Fan Run-On)

Enable via config (0x09) with `delay_secs` > 0. On momentary release, channel stays on for configured seconds, then auto-off.

## Step 12: Double-Tap Latch

Momentary mode + `double_tap_en` flag: two presses < 1 s, toggles latch on/off.

## Step 13: Force Override (Middle MCU)

Type 0x0B: immediate on/off/toggle, bypasses state machine. Cleared by next panel event.

## Step 14: ACC Sense

PA1 low, all outputs off (polled every 2 ms). No MCU reset.

## Step 15: Status Frame (Type 0x0A)

Returns 6 bytes: channels 1-6 on/off, byte 6 = master state. Request by sending type 0x0A.
