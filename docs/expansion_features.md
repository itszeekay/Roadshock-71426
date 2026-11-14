# Expansion features and use cases

This page collects candidate features and use cases for the platform beyond
what is built or verified today. Nothing on this page is implemented or
verified. It is a proposal list for future work, in the same spirit as
[roadmap.md](roadmap.md). Hardware facts live in [channel_guide.md](channel_guide.md)
and [pinouts.md](pinouts.md); the protocol lives in [protocol.md](protocol.md).
Do not treat anything here as a promise or a tested result.

## What the platform is good for

The base board is a fused, high-side switched 8-channel 12 V output module
with a 10-button panel. The stock loads it is marketed for are auxiliary
lights and accessories on off-road vehicles, trucks, SUVs, UTVs, and boats.
With the custom base firmware and an ESP32 middle ECU, the same hardware
also fits these use cases:

| Use case | Why it fits |
|---|---|
| Off-road / overlanding | Light bars, ditch lights, rock lights, winch, compressor, aux fans, fuel pump, all fused and switchable from one panel |
| Marine | Bilge pump, navigation lights (flasher), horn, cabin lights, windshield wiper with park switch; the wiper actions are already in the custom firmware ([wiper_control.md](wiper_control.md)) |
| RV / caravan | Centralized fused outputs for water pump, awning, interior and exterior lights, fridge, fan; CAN control from a head unit or phone |
| Motorsport / race car | Starter disable (`0x12`), fuel pump soft start (`0x09` mode 3), fan duty mapping from a speed signal (`0x11`) |
| Garage / workshop | Battery charger, compressor cycling, lights, pump control; a Pi or home-automation CAN node can drive it |
| EV / conversion | Output gating on cranking, CAN-mapped duty for pumps and fans, low-current ECU power channel |

The per-channel capabilities and wiring recommendations already in
[channel_guide.md](channel_guide.md) map directly onto these uses; nothing
about them needs changing.

## The ESP32-S2 Mini as the middle ECU

The S2 Mini exposes roughly 27 GPIO pins on its headers, plus two
hardware UARTs, a TWAI (CAN 2.0) controller, two 12-bit ADCs, two 8-bit
DACs, capacitive touch inputs, an on-chip temperature sensor, eight LEDC
PWM channels, and USB OTG. The bridge layout in
[middle_ecu_features.md](middle_ecu_features.md) already uses two UARTs for
the 2400-baud links and two pins for TWAI; the rest is free.

| Resource | Count | Suggested use |
|---|---:|---|
| Free GPIO | ~19 | Digital inputs: float switches, limit switches, door contacts, panel remap buttons |
| ADC (12-bit) | 2 (up to ~15 channels) | Analog sensors on a divider: rain, temperature, rail voltage, thermoswitch |
| DAC (8-bit) | 2 | 0-3.3 V analog reference or throttle signal |
| LEDC PWM | 8 | Servos, actuators, strip LEDs, or extra dimmable loads without touching the base board |
| I2C | 1-2 | External current and temperature sensors (see below) |
| SPI | 1-4 | SD card for logging; second CAN controller if ever needed |
| Touch | several | Capacitive button replacement for the panel |

Any analog or load-side addition needs a verification bench session before
it is documented as working; see [bench-results.md](bench-results.md) for how
verified facts are recorded.

## Candidate features, by problem solved

### Output feedback: current and voltage monitoring

The stock board has no current sensing, so a failed load looks identical to
a working one at the panel. An I2C current sensor per board (for example an
INA219 or INA226 on one bus) gives shunt voltage and, with the right
calibration, per-channel current on many channels at once. A voltage divider
into an ADC pin gives rail-voltage monitoring.

What it solves:

- Open-circuit detection (light out, blown LED).
- Over-current and over-temp shutdown before a fuse or MOSFET fails.
- Load shedding when the rail sags: drop non-critical channels first.
- Honest consumption totals for battery management.

Integration point: the `0x121 + n` status frame slot in the proposed CAN ID
map ([roadmap.md](roadmap.md)); the base firmware would report actual state,
and the bridge would publish it.

### Temperature monitoring

An I2C temperature sensor (for example an MCP9808) on the MOSFET or battery
gives:

- Thermal foldback on hot channels.
- Fan auto-on above a setpoint.
- Over-temperature shutdown.

### Input-driven outputs

The custom base firmware already accepts `0x0F` with an 8-bit input bitmask
and follows it on channels flagged for input drive ([protocol.md](protocol.md)).
The ESP32 supplies the inputs directly, so no base-board changes are needed:

- Float switch to bilge pump.
- Door contact to dome light.
- Limit switch to actuator stop.
- Push button to momentary output.
- Thermostat contact to fan.

### CAN integration

TWAI plus an SN65HVD230 transceiver puts the PDU on the vehicle bus.
Candidate mappings (none implemented yet):

- Read wheel speed from CAN, feed the `0x11` counter to PWM for a pump or fan.
- Read RPM for shift light or flasher logic.
- Reverse-active dims interior lights.
- Door-open wakes interior light.
- Ignition-on enables the configured output set.

### Macros, scenes and scheduling

The ESP32 has an RTC and can sequence frames with idle gaps:

- "Night run": rock light at 30 %, ditch lights full, panel backlight dim.
- "Cold start": fan high for 30 s, then ramp down.
- "Tow mode": disable traction-sensitive outputs, enable trailer loads.
- Timed off: water pump off after 30 minutes.
- Crank timeout: disable starter output after N seconds and latch a flag.

### Button remapping and long-press actions

The middle ECU can intercept panel `0x08 0x0C` frames and remap:

- Double-tap changes a button from momentary to toggle.
- Long-press triggers a hidden action.
- Lockout of selected buttons while driving.
- Two-button combos for valet or all-off.

### Wiper enhancements

The base firmware supports slow, fast, intermittent, wash and swipe
([wiper_control.md](wiper_control.md)). The middle ECU can add:

- Rain sensor (ADC) to scale wiper speed.
- Return-to-park regardless of power cycling mid-sweep.
- Wash triggers spray plus three wipes.
- Adjustable intermittent delay.

### Wireless and remote control

- Phone app over Wi-Fi (S2) for all eight outputs.
- OTA updates for the middle ECU.
- Cloud telemetry for faults and consumption.
- Note: BLE features build on the ASR's BLE stack; that needs a live scan and
  provisioning work, tracked as open in [asr5601_custom_app.md](asr5601_custom_app.md).

### Data logging

An SD card over SPI logs:

- Per-output on-time and cycle count.
- Rail voltage history.
- Fault history (over-current, over-temp).

Uses: find parasitic drains, audit flasher behavior, post-mortem after a
MOSFET failure.

## Priorities

1. Current and voltage monitoring with per-channel feedback (biggest gap in
   the stock design).
2. Input-driven outputs (`0x0F`) wired to real switches, floats and
   thermoswitches.
3. CAN read for speed and RPM to drive `0x11`.
4. Macros and scheduling for common scenes.
5. Button remapping and long-press actions.
6. Temperature monitoring and thermal foldback.
7. Wiper rain-sense and return-to-park.
8. OTA plus app control (needs the S2 Wi-Fi path, or an S3 for BLE).
9. SD-card logging.

## What is deliberately not on this list

- Panel LED override over the internal 115200 display link; see
  [roadmap.md](roadmap.md) "Out of scope".
- ASR firmware replacement for custom BLE services; see
  [asr5601_custom_app.md](asr5601_custom_app.md).
- Any claim about features not yet measured on hardware.
