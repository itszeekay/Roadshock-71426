# Wiper Control

## Overview

The Roadshock panel supports wiper control with a single output and PWM. This is ideal for single-output wiper motors (common 5-wire motors with high/low speed windings and park switch).

## Wiring

- **High-speed winding** → high-side output (Channel 5 = PC5/TIM2_CH1)
- **Ground** → wiper motor ground
- **PWM** → control speed via duty cycle (lower duty = slower)

## Recommended Wiring for Roadshock

- Use **Channel 5 (PC5 = TIM2_CH1, 10 A fuse)** for wiper motor
- Connect high-speed winding of wiper motor to the output
- Connect wiper motor ground to ground
- For park switch: connect via middle ECU GPIO with resistor divider (see Park Switch section below)

## Park Switch Wiring by Vehicle

| Vehicle | Motor Connector | Park Pin(s) | Continuity When Parked | How to Wire to Middle ECU |
|---------|-----------------|-------------|------------------------|---------------------------|
| **Mazda Miata NA (1990)** | 4-wire (A/B/C/D) | **A** and **C** (both tied to ground via internal switch) | A ⇔ C continuous; A ⇔ D (ground) continuous | Resistor divider from terminal A (or C) to middle ECU GPIO |
| **Honda CRX Si (1990)** | 5-pin (B/HI/LO/AS/E) | **B** (common +12V) shorted to **AS** (park switch) or **HI** | B ⇔ AS (or B ⇔ HI) continuous | Resistor divider from terminal B (or AS) to middle ECU GPIO |
| **BMW E36 M3 (1995)** | 5-wire (X333) | **Pin 1 = Wiper in park** | Pin 1 ⇔ ground continuous | Resistor divider from X333 pin 1 to middle ECU GPIO |

**Middle ECU wiring example:**
```
Wiper motor park pin ── Resistor divider (10k top, 4.7k bottom) ── Middle ECU GPIO (3.3 V logic)
                                │
                            to ground (or to park-switch pin contact)
```
- GPIO reads ~3–4 V when wiper is parked, ~0 V otherwise
- Middle ECU polls GPIO and sends `type 0x0D action=0` to Roadshock Channel 5 when park is detected
- No base-board hardware changes required; only a resistor divider on the middle ECU side

## Safety Notes

- Leave the low-speed winding disconnected (open circuit)
- Add a flyback diode across motor terminals in the harness
- Recommended PWM frequency: 50–100 Hz for wipers
- Motor draws ~4 A (low) / ~6 A (high); Channel 5 (10 A) is sufficient

## Implementation Notes

- The wiper control uses `PROTO_TYPE_WIPER` (0x0D) in the firmware
- The middle ECU must read the park switch via a GPIO + resistor divider
- No base-board hardware changes are required for wiper control