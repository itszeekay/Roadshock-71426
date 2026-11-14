# Documentation

MCUs in this project: base board **STM8S003F3P6** (TSSOP-20), button panel
**STM8S003K3** (LQFP-32), panel main controller **ASR5601S** (QFN-48).

## Start here by goal

### Flash custom firmware, or restore stock

- [startup_guide.md](startup_guide.md): build, flash, test, and what each
  setting does
- [reproduce.md](reproduce.md): dump, build, flash, restore, capture, inject
- [pogo_fixture.md](pogo_fixture.md): pogo pin fixture for repeatable SWIM
  access through the potting

### Control channels and use the protocol

- [protocol.md](protocol.md): 2400-baud frame format, message types, replies,
  checksum, display link, and stock channel modes
- [channel_guide.md](channel_guide.md): per-channel hardware capabilities,
  frequency groups, and wiring assignments
- [wiper_control.md](wiper_control.md): wiper motor wiring, park switch, and
  type 0x0D

### Understand the stock firmware

- [firmware.md](firmware.md): base and panel firmware behavior, decompilation,
  custom firmware
- [firmware_comparison.md](firmware_comparison.md): the three ways to run the
  panel (stock, stock plus middle ECU, custom base)
- [hidden_commands.md](hidden_commands.md): hidden protocol commands
  0x0B/0x0D/0x19 and the frame handler
- [uart_capabilities.md](uart_capabilities.md): what the stock firmware accepts
  over the 2400-baud UART

### Understand the panel and the ASR

- [panel.md](panel.md): panel architecture, ASR and STM8 split, buttons, LEDs,
  standalone behavior
- [asr5601.md](asr5601.md): ASR5601S pin map, J3, boot straps, and links to the
  dump and firmware documents
- [asr5601_datasheet.md](asr5601_datasheet.md): datasheet review, corrected pin
  map, UART mux, keypad, memory map, 5 V I/O
- [asr5601_reference_archive.md](asr5601_reference_archive.md): curated ASR
  archive, embedded chip table, DOGO read path
- [asr5601_dump.md](asr5601_dump.md): dump requirements, UART findings, SWD and
  J3-only results
- [asr5601_swd_dump.md](asr5601_swd_dump.md): step-by-step SWD read with an
  ST-Link and OpenOCD, including wiring and verification
- [asr5601_firmware.md](asr5601_firmware.md): what the ASR firmware does:
  UARTs, base link, keypad, LED path
- [asr5601_monitor.md](asr5601_monitor.md): ROM download monitor commands,
  status codes and word access over J3
- [asr5601_custom_app.md](asr5601_custom_app.md): what is needed for a custom
  BLE application, and what is already in place
- [middle_ecu_features.md](middle_ecu_features.md): what an ESP32 between J2 and
  the base can do, by effort
- [panel_led_map.md](panel_led_map.md): display frame, pin table, nibble-to-pin
  patterns

### Look up hardware details

- [hardware.md](hardware.md): boards, identified ICs, connectors, power,
  programming headers, photos
- [pinouts.md](pinouts.md): base output map, panel RGB LED map, STM8 TSSOP-20
  and LQFP-32, ASR5601S QFN-48, Feather wiring
- [test-hardware.md](test-hardware.md): bench hardware, including the CAN Bus
  Feather used for early testing

### Verify results and look ahead

- [bench-results.md](bench-results.md): everything verified on hardware, plus
  the dump text-mode trap
- [roadmap.md](roadmap.md): CAN gateway and PDM plan
- [expansion_features.md](expansion_features.md): proposed use cases and
  features beyond the current build; none are implemented
- [safety.md](safety.md): electrical safety, flashing, RF, and liability

## Confidence tags

- **V** verified from the firmware or measured on hardware
- **I** inferred, consistent with evidence but not proven
- **?** unknown or not yet determined
