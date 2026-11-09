# Documentation

| Document | Contents |
|---|---|
| [hardware.md](hardware.md) | Boards, identified ICs, connectors, power, programming headers, photos |
| [pinouts.md](pinouts.md) | Base output map, panel RGB LED map, STM8 TSSOP-20/LQFP-32, ASR5601S QFN-48, Feather wiring |
| [protocol.md](protocol.md) | 2400-baud frame format, message types, replies, checksum, display link |
| [firmware.md](firmware.md) | Base and panel firmware behaviour, decompilation, custom firmware |
| [panel.md](panel.md) | Panel architecture, ASR + STM8 split, buttons, LEDs, standalone behaviour |
| [asr5601.md](asr5601.md) | ASR5601S pin map, J3, boot mode, dump options |
| [bench-results.md](bench-results.md) | Everything verified on hardware, plus the dump text-mode trap |
| [reproduce.md](reproduce.md) | Dump, build, flash, restore, capture, inject |
| [roadmap.md](roadmap.md) | CAN gateway and PDU plan |

Confidence tags used throughout:

- **V** verified from the firmware or measured on hardware
- **I** inferred (consistent with evidence, not proven)
- **?** unknown / not yet determined
