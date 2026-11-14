# Configuration options

Three ways to run the panel. Stock is the default; the other two add a
microcontroller.

| Option | What it needs | What it adds | Limits |
|---|---|---|---|
| 1. Stock | Nothing | Factory behavior: four modes per channel, 2400-baud base link | No dimming, no automation, no remote control |
| 2. Panel plus middle ECU | A second MCU on the 2400-baud link, stock base firmware | Remote on/off and mode changes; button and power events | No per-channel custom commands, no PWM dimming, no auto functions, no persistence |
| 3. Panel plus custom base firmware | Flash the base STM8 once over SWIM | Hardware PWM on six channels, auto functions, status readback, wiper control | Base board only; panel and ASR stay stock |

Option 2 is the least invasive and is enough for CAN control of the stock
outputs. Option 3 changes the base firmware and gives dimming and the auto
functions. See:

- [startup_guide.md](startup_guide.md) for building and flashing option 3
- [channel_guide.md](channel_guide.md) for per-channel PWM capability
- [wiper_control.md](wiper_control.md) for type `0x0D`
- [middle_ecu_features.md](middle_ecu_features.md) for option 2 in detail
