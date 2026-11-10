# Documentation

MCUs in this project: base board **STM8S003F3P6** (TSSOP-20), button panel
**STM8S003K3** (LQFP-32), panel main controller **ASR5601S** (QFN-48).

## Start here by goal

Pick the path that matches what you want to do.

### Flash custom firmware, or restore stock
- [startup_guide.md](startup_guide.md) - full step-by-step: build, flash,
  test, and what each setting does
- [reproduce.md](reproduce.md) - dump, build, flash, restore, capture, inject
- [pogo_fixture.md](pogo_fixture.md) - pogo pin fixture for repeatable SWIM
  access through the potting

### Control channels and use the protocol
- [protocol.md](protocol.md) - 2400-baud frame format, all message types,
  replies, checksum, display link, and stock channel modes
- [channel_guide.md](channel_guide.md) - per-channel hardware capabilities,
  frequency groups, and wiring assignments
- [wiper_control.md](wiper_control.md) - wiper motor wiring, park switch, and
  type 0x0D

### Understand the stock firmware
- [firmware.md](firmware.md) - base and panel firmware behavior, decompilation,
  custom firmware
- [firmware_comparison.md](firmware_comparison.md) - the three ways to run the
  panel (stock, stock + middle ECU, custom base)
- [hidden_commands.md](hidden_commands.md) - hidden protocol commands
  0x0B/0x0D/0x19 and the frame handler
- [uart_capabilities.md](uart_capabilities.md) - what the stock firmware accepts
  over the 2400-baud UART

### Understand the panel and the ASR
- [panel.md](panel.md) - panel architecture, ASR + STM8 split, buttons, LEDs,
  standalone behavior
- [asr5601.md](asr5601.md) - ASR5601S pin map, J3, boot mode, dump options
- [asr5601_datasheet.md](asr5601_datasheet.md) - datasheet review: corrected
  pin map, UART mux, keypad, memory map, 5 V I/O
- [asr5601_reference_archive.md](asr5601_reference_archive.md) - curated ASR
  archive, embedded chip table, DOGO read path
- [asr5601_dump_plan.md](asr5601_dump_plan.md) - step-by-step plan to dump the
  ASR over J3
- [panel_led_map.md](panel_led_map.md) - display frame, pin table, nibble-to-pin
  patterns

### Look up hardware details
- [hardware.md](hardware.md) - boards, identified ICs, connectors, power,
  programming headers, photos
- [pinouts.md](pinouts.md) - base output map, panel RGB LED map, STM8 TSSOP-20/
  LQFP-32, ASR5601S QFN-48, Feather wiring
- [test-hardware.md](test-hardware.md) - bench hardware, including the CAN Bus
  Feather used for early testing

### Verify results and look ahead
- [bench-results.md](bench-results.md) - everything verified on hardware, plus
  the dump text-mode trap
- [roadmap.md](roadmap.md) - CAN gateway and PDU plan
- [safety.md](safety.md) - electrical safety, flashing, RF, and liability

---

## Reference table

| Document | Contents |
|---|---|
| [hardware.md](hardware.md) | Boards, ICs, connectors, power, programming headers, photos |
| [test-hardware.md](test-hardware.md) | Bench hardware, CAN Bus Feather used for early testing |
| [pinouts.md](pinouts.md) | Base output map, panel RGB LED map, STM8 and ASR pin maps, Feather wiring |
| [protocol.md](protocol.md) | 2400-baud frame format, message types, replies, checksum, display link, stock channel modes |
| [firmware.md](firmware.md) | Base and panel firmware behavior, decompilation, custom firmware |
| [firmware_comparison.md](firmware_comparison.md) | Three ways to run the panel |
| [channel_guide.md](channel_guide.md) | Channel hardware capabilities, PWM suitability, wiring assignments |
| [wiper_control.md](wiper_control.md) | Wiper motor wiring, park switch, type 0x0D |
| [panel.md](panel.md) | Panel architecture, ASR + STM8 split, buttons, LEDs, standalone behavior |
| [asr5601.md](asr5601.md) | ASR5601S pin map, J3, boot mode, dump options |
| [asr5601_datasheet.md](asr5601_datasheet.md) | Datasheet review |
| [asr5601_reference_archive.md](asr5601_reference_archive.md) | Curated ASR archive, chip table, DOGO read path |
| [asr5601_dump_plan.md](asr5601_dump_plan.md) | Step-by-step plan to dump the ASR over J3 |
| [panel_led_map.md](panel_led_map.md) | Display frame, pin table, nibble-to-pin patterns |
| [bench-results.md](bench-results.md) | Everything verified on hardware, plus the dump text-mode trap |
| [startup_guide.md](startup_guide.md) | Step-by-step build, flash, test, and configuration guide |
| [reproduce.md](reproduce.md) | Dump, build, flash, restore, capture, inject |
| [hidden_commands.md](hidden_commands.md) | Hidden protocol commands 0x0B/0x0D/0x19 and frame handler |
| [uart_capabilities.md](uart_capabilities.md) | What the stock firmware accepts over the 2400-baud UART |
| [pogo_fixture.md](pogo_fixture.md) | Pogo pin fixture design for SWIM access |
| [roadmap.md](roadmap.md) | CAN gateway and PDU plan |
| [safety.md](safety.md) | Electrical safety, flashing, RF, and liability |

Confidence tags used throughout:

- **V** verified from the firmware or measured on hardware
- **I** inferred (consistent with evidence, not proven)
- **?** unknown / not yet determined
