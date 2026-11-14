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

## What owners want (from real discussion)

The price point of the Roadshock panel (~$150, about half of the Auxbeam $200-219 kit) puts it in the "budget PDM" segment. Owners from the Tacoma World thread emphasized:

- **Programmable, input-driven behavior** - a button press can turn a load on, off, or on only when high-beam is active (On/Off/On-with-HB).
- **Persistence across power cycles** - the default behavior of many panels is to clear all settings at the next start, requiring a full re-setup. This is a frequent frustration.
- **No Bluetooth / app for basic operation** - the panel should work as a direct switch interface, not as a connected device. BLE features are optional and can be deferred.
- **Simple, failsafe wiring** - one power wire, chassis ground, and per-channel control. The hardware should be robust enough for frequent on/off cycles.

The broader GRM PDM community (track and street builders) lists these features repeatedly:

- **Over-current sensing and auto-reset** - detect a short or overload, trip the output, and retry a few times before staying off.
- **Diagnostic datalogging** - record on-time, cycle count, and fault events for each circuit, accessible via a PC or CAN-enabled dashboard.
- **PWM output control** - soft-start for fuel pumps, variable-speed fans, and throttle mapping.
- **CAN integration** - receive commands from a vehicle ECU, and publish status back. A CAN message can also "kill all functions" in an error condition.
- **Safety-oriented design** - solid-state electronics fail closed, so a mechanical master relay is recommended to guarantee a safe state.

Open-source PDM projects (dingoPDM, Synapse PDM, OpenPDM) expose a similar feature set: limited current outputs, digital inputs, CAN, and basic programmability. The cheap ($150-$300) market emphasizes reliability and simplicity, not high-end telemetry.

## Candidate features, by problem solved

### Output feedback: current sensing, voltage monitoring, and over-current protection

The stock board has no current sensing, so a failed load looks identical to a working one at the panel. Adding per-channel current sensing (shunt + ADC, or an I²C sensor like INA219/INA226) gives:

- **Open-circuit detection** - a light that reads zero current when it should be on.
- **Over-current shutdown** - prevent a fuse from blowing or a MOSFET from burning out.
- **Load shedding** - drop low-priority channels first when the rail sags.
- **Consumption totals** - track battery drain for battery management.

Integration point: the `0x121 + n` status frame slot in the proposed CAN ID map ([roadmap.md](roadmap.md)). The base firmware would report actual state, and the bridge would publish it.

### Temperature monitoring

An I²C sensor (MCP9808) on the MOSFET or battery gives:

- **Thermal foldback** - reduce PWM duty as the MOSFET heats.
- **Fan auto-on** - turn the radiator fan on above a setpoint.
- **Over-temperature shutdown** - protect the hardware.

### Input-driven outputs (`0x0F`)

The custom base firmware already accepts an 8-bit input bitmask and will drive outputs that have the `input_drive` flag set. The ESP32 supplies the inputs directly:

- **Float switch -> bilge pump**
- **Door contact -> dome light**
- **Limit switch -> actuator stop**
- **Push button -> momentary output**
- **Thermostat contact -> fan**

### CAN integration

TWAI plus an SN65HVD230 transceiver puts the PDU on the vehicle bus. Candidates:

- **Read wheel speed from CAN, feed the `0x11` counter to PWM** for a pump or fan.
- **Read RPM for tachometer-driven flasher** or shift light.
- **Reverse-light input** - when reverse is active, dim interior lights, flash backup alarm.
- **Door-open input** - when a door opens, auto-on dome light.
- **Ignition-on gating** - only enable configured outputs when the ignition is on.
- **Error kill** - a CAN message can force all outputs off in an error condition (as requested by the GRM community).

### Macros, scenes and scheduling

The ESP32 has an RTC and can sequence frames with idle gaps:

- **"Start track day"** - fuel pump prime for 2 seconds, then fan on, then pump warm-up.
- **"Night run"** - rock lights at 30 %, ditch lights full, panel backlight dimmed.
- **"Cold start"** - fan high for 30 seconds, then ramp down.
- **"Tow mode"** - disable traction-sensitive outputs, enable trailer loads.
- **Timed off** - water pump off after 30 minutes.
- **Cranking timeout** - disable starter output after N seconds and latch a flag.

### Button remapping and long-press actions

The middle ECU can intercept panel `0x08 0x0C` frames and remap:

- **Double-tap** changes a button from momentary to toggle.
- **Long-press** triggers a hidden action.
- **Button lock** - disable selected buttons while driving.
- **Button combos** - press 1+2 together for a hidden function.

### Wiper enhancements

The base firmware supports slow, fast, intermittent, wash and swipe ([wiper_control.md](wiper_control.md)). The middle ECU can add:

- **Auto rain sensor** - analog input scales wiper speed.
- **Return-to-park** - always return to park position, even if power cycled mid-sweep.
- **Wash-wipe** - wash button triggers spray + three wipe cycles.
- **Adjustable intermittent delay** - variable pause based on rain intensity.

### Datalogging and diagnostic export

A CAN-enabled dashboard (e.g., AiM, Haltech) or a PC can request per-circuit status (`0x120`) and receive:

- **On-time** and **cycle count** - how many times each load was activated.
- **Fault history** - over-current, over-temperature, or manual forced-off events.
- **Consumption totals** - summed current over time, for battery state of charge.

Logging can be stored locally (SD card) and streamed over CAN for a race-car data logger.

### Safety-oriented defaults

All circuits should default to **off** at power-up, but the **last state before shutdown** should be restored (persistence) - otherwise the panel is less convenient than a manual switch block. This can be stored in the EEPROM or battery-backed RAM.

## 3-way switch / 12 V trigger

A common requirement for off-road panels is a center-off toggle plus two independent buttons so you get three positions: **Off**, **On**, and **On while high beam or another signal is active**. None of the panels discussed (Roadshock 71426, Auxbeam AR-800, Switch-Pros SP-9100, sPOD, D-Switch) ships with this capability out of the box. Users report that standard momentary, toggle, and pulse buttons only give one position per press and cannot be combined with a 12 V input to activate a different circuit.

Workaround that has been used: place an SPDT mechanical relay on the panel side driven by a second switch, then feed the 12 V signal into the relay coil. This adds a small extra part but gives the three-position behavior without modifying the base board. The custom base firmware already accepts an input bitmask (`0x0F`) that could implement the same logic on the ESP32 side once a 12 V sense input is wired.

## Priorities (ranked by community feedback)

1. **Current sensing + over-current protection** - biggest gap in the stock design.
2. **Input-driven outputs** - repeatedly requested to enable complex trigger logic (door, float, limit).
3. **CAN integration** - needed for error handling, sensor mapping, and remote control.
4. **Datalogging / diagnostic export** - requested by track builders for troubleshooting.
5. **Macros and scheduling** - valuable for workflows like "night run" or "cold start".
6. **Button remapping** - customization for driver preference.
7. **Wiper enhancements** - natural extension of existing wiper control.
8. **Temperature monitoring** - safety and thermal management.
9. **OTA / BLE** - optional, premium convenience, not required for basic operation.
10. **Turn-signal mode** - keep as a niche feature, deprioritize due to legal concerns.

## What is deliberately not on this list

- **Panel LED override** - the display link between the ASR and the STM8 is internal to the panel and out of scope for the J2 gateway.
- **ASR firmware replacement** - the ASR's BLE stack and runtime pin map remain open and are not required for the J2 gateway.
- **Any claim about features not yet measured on hardware**.