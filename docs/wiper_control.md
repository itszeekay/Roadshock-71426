# Wiper Control

## Overview

The Roadshock base board can drive a wiper motor on a single output. A common
5-wire wiper motor has a high-speed winding, a low-speed winding, and a park
switch. The park switch is an open/closed contact inside the motor that indicates
whether the wiper is at the park position.

## Wiring

- **Motor power** to a 12 V high-side output (Channel 5, PC5 = TIM2_CH1, 10 A fuse)
- **Motor ground** to a board ground
- **Park switch** to the middle ECU GPIO via a resistor divider
- **Low-speed winding** left open (do not connect)

Use Channel 5 for the wiper motor: 10 A fuse, hardware PWM (TIM2, Group B),
and an independent duty cycle. The 5-wire motor park pin is the only signal
the middle ECU needs to read.

## Park Switch Wiring to the Middle ECU

The park switch is an open/closed contact inside the wiper motor. When the wiper
is parked, the contact closes (ground); when it is moving or running, the
contact is open.

Wiring:

```
Wiper motor park pin -- resistor divider (10k top, 4.7k bottom) -- Middle ECU GPIO (3.3 V logic)
                                     |
                                  to ground (or to park-switch contact)
```

- GPIO reads roughly 3-4 V when the wiper is parked, roughly 0 V otherwise
- The middle ECU polls the GPIO and, on park detection, sends `type 0x0D` with `action=0` to the Roadshock base on Channel 5
- No base-board hardware changes are required; only a resistor divider on the
  middle ECU side

The exact park pin on a given motor connector must be verified on the physical
wiring harness. The local service manuals (Miata 1990, CRX Si 1990, BMW E36 M3
1995, from LEMON Manuals) document the wiper switch location, service/repair,
and testing procedures, but do not include a pin-level continuity table for the
park contact. Confirm the park pin and its continuity by measuring the
harness on the vehicle.

## Safety Notes

- Leave the low-speed winding disconnected (open circuit)
- Add a flyback diode across the motor terminals in the harness
- Recommended PWM frequency: 50-100 Hz for wipers
- Motor draws roughly 4 A (low) to 6 A (high); the 10 A fuse on Channel 5 is sufficient

## Implementation Notes

- Wiper control uses `PROTO_TYPE_WIPER` (0x0D) in the custom base firmware
- The middle ECU reads the park switch via a GPIO plus resistor divider
- No base-board hardware changes are required for wiper control