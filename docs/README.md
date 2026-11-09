# Documentation

MCUs in this project: base board **STM8S003F3P6** (TSSOP-20), button panel **STM8S003K3** (LQFP-32), panel main controller **ASR5601S** (QFN-48).

| Document | Contents |
|---|---|
| [hardware.md](hardware.md) | Boards, identified ICs, connectors, power, programming headers, photos |
| [test-hardware.md](test-hardware.md) | Bench hardware, including the CAN Bus Feather used for early testing |
| [pinouts.md](pinouts.md) | Base output map, panel RGB LED map, STM8 TSSOP-20/LQFP-32, ASR5601S QFN-48, Feather wiring |
| [protocol.md](protocol.md) | 2400-baud frame format, message types, replies, checksum, display link |
| [firmware.md](firmware.md) | Base and panel firmware behavior, decompilation, custom firmware |
| [panel.md](panel.md) | Panel architecture, ASR + STM8 split, buttons, LEDs, standalone behavior |
| [asr5601.md](asr5601.md) | ASR5601S pin map, J3, boot mode, dump options |
| [asr5601_datasheet.md](asr5601_datasheet.md) | Datasheet review: corrected pin map, UART mux, keypad, memory map, 5 V I/O |
| [asr5601_reference_archive.md](asr5601_reference_archive.md) | Curated ASR archive, embedded chip table, and the DOGO read path |
| [asr5601_dump_plan.md](asr5601_dump_plan.md) | Step-by-step plan to dump the ASR over J3 |
| [bench-results.md](bench-results.md) | Everything verified on hardware, plus the dump text-mode trap |
| [reproduce.md](reproduce.md) | Dump, build, flash, restore, capture, inject |
| [roadmap.md](roadmap.md) | CAN gateway and PDU plan |
| [safety.md](safety.md) | Electrical safety, flashing, RF, and liability |
| [mode_timing.md](mode_timing.md) | Stock channel mode dispatch; timing and EEPROM open items |
| [hidden_commands.md](hidden_commands.md) | Hidden protocol commands 0x0B/0x0D/0x19 and frame handler |
| [panel_led_map.md](panel_led_map.md) | Display frame, pin table, nibble-to-pin patterns |

Confidence tags used throughout:

- **V** verified from the firmware or measured on hardware
- **I** inferred (consistent with evidence, not proven)
- **?** unknown / not yet determined
