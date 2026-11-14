# Expansion features and use cases

This page collects candidate features and use cases for the platform beyond what is built or verified today. Nothing here is implemented or verified. It is a proposal list for future work.

## What the platform is good for

The base board is a fused, high-side switched 8-channel 12 V PDM with a 10-button panel. Stock applications are auxiliary lights and accessories for off-road vehicles, trucks, SUVs, UTVs, and boats.

- **Off-road / overlanding:** LED bars, ditch lights, rock lights, winch, compressor, aux fans, fuel pump.
- **Marine:** Bilge pump, navigation lights, horn, cabin lights, wiper with park switch.
- **RV / caravan:** Water pump, awning, interior/exterior lights, fridge, fan.
- **Motorsport / race car:** Starter disable, fuel pump soft start, variable fan speed, throttle mapping.
- **Garage / workshop:** Battery charger, compressor cycling, lighting, pump control.
- **EV / conversion:** Output gating on cranking, CAN-mapped PWM for pumps/fans.

## What owners want (cheap PDM segment, $150-$200)

- Programmable, input-driven behavior (On/Off/On-with-high-beam) and persistence across power cycles.
- Direct switch interface, no Bluetooth/app required for basic operation.
- Simple, failsafe wiring: one power wire, chassis ground, per-channel control.
- Over-current sensing and auto-reset (detect short/overload, retry, then stay off).
- Diagnostic datalogging: on-time, cycle count, fault events per circuit.
- CAN integration: receive commands from vehicle ECU, publish status, error kill.
- PWM control: soft-start for fuel pumps, variable-speed fans.
- Safety: solid-state electronics fail closed; mechanical master relay recommended.

Open-source PDMs (dingoPDM, Synapse PDM, OpenPDM) follow the same feature set: limited current outputs, digital inputs, CAN, basic programmability.

## Candidate features, by problem solved

### Output feedback

Add per-channel current sensing (shunt + ADC, or I2C sensor like INA219/INA226):

- **Open-circuit / load monitoring:** The stock panel only shows a fuse-blown LED (no per-channel current readout). Adding shunt + ADC or I2C sensors gives actual open-circuit and load data.
- **Over-current shutdown:** prevent fuse blow or MOSFET failure.
- Load shedding when rail sags.
- Consumption totals for battery management.

Integration: `0x121 + n` status frame slot in proposed CAN ID map.

### Temperature monitoring

I2C sensor (MCP9808) on MOSFET or battery:

- Thermal foldback (reduce PWM as MOSFET heats).
- Fan auto-on above setpoint.
- Over-temperature shutdown.

### Input-driven outputs (`0x0F`)

Use ESP32 inputs:

- Float switch -> bilge pump.
- Door contact -> dome light.
- Limit switch -> actuator stop.
- Push button -> momentary output.
- Thermostat contact -> fan.

### CAN integration

Read wheel speed, RPM for flasher, reverse light, door open, ignition gating, error kill.

### Macros / scheduling

Sequence frames: "cold start," "night run," "tow mode," timed off, cranking timeout.

### Button remapping

Intercept panel `0x08 0x0C` frames to:

- Double-tap toggle.
- Long-press hidden action.
- Button lockout.
- Button combos.

### Wiper enhancements

Add rain sensor, return-to-park, wash-wipe, adjustable intermittent delay.

### Datalogging

Per-circuit status (on-time, cycle count, fault history) stored locally and streamed over CAN.

### Safety defaults

All circuits default to off, but last state before shutdown should be restored (persistence) - can be stored in EEPROM or battery-backed RAM.

## 3-way switch / 12 V trigger

Common requirement: a center-off toggle plus a 12 V input to achieve three positions (Off, On, On-while-high-beam). None of the panels discussed (Roadshock 71426, Auxbeam, Switch-Pros, etc.) provide this natively. Workaround: an SPDT relay driven by a second switch, or the custom base firmware's `0x0F` path with an external 12 V sense input.

## Priorities (ranked by community feedback)

1. Current sensing + over-current protection.
2. Input-driven outputs.
3. CAN integration.
4. Datalogging / diagnostic export.
5. Macros and scheduling.
6. Button remapping.
7. Wiper enhancements.
8. Temperature monitoring.
9. OTA / BLE.
10. Turn-signal mode.

## What is deliberately not on this list

- Panel LED override.
- ASR firmware replacement.
- Features not yet measured on hardware.

## ESP32-S2 Mini resources

- ~27 GPIO on headers.
- Two hardware UARTs.
- TWAI (CAN 2.0) controller.
- Two 12-bit ADCs.
- Two 8-bit DACs.
- Capacitive touch inputs.
- On-chip temperature sensor.
- Eight LEDC PWM channels.
- USB OTG.

## Summary

The platform is a solid, fused 8-channel PDM with a button panel. The middle ECU adds CAN, programmable inputs, and diagnostics. Community needs: output feedback, input-driven logic, CAN integration, datalogging. All proposed features are scoped for future development.

**Key open items:** runtime pinout of the ASR, BLE service list, application-region programming, bench tests.