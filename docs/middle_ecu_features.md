# Middle ECU feature list

What an ESP32 placed between J2 and the base can do, based on the decoded
firmware for all three MCUs. The middle ECU sees two 2400-baud links:

```
 panel (ASR UART0, P02/P03) <-> ESP32 <-> base (STM8 UART1, PD5/PD6)
```

Both sides use the same 11-byte, gap-delimited frame with a checksum. See
[protocol.md](protocol.md) for the frame and
[asr5601_firmware.md](asr5601_firmware.md) for the panel side.

## What already works without new firmware

The stock panel expects the base to send one startup frame at boot and then
answer its frames.

| Direction | Frame | Meaning |
|---|---|---|
| ESP32 to panel | `00 FF 1B 02 00 00 00 00 00 00 1C` | startup, brings the LED UI alive |
| ESP32 to panel | `xx 00 07 00 ...` | master power off |
| ESP32 to panel | `xx 00 07 01 ...` | master power on |
| ESP32 to panel | `xx 00 08 0C ...` | inject a button bitmask |
| panel to ESP32 | `xx 00 08 0C ...` | buttons currently held |
| panel to ESP32 | `xx 00 07 00/01 ...` | power button pressed |

A reply is the request with `dir = 0xFF` and `type | 0x10`.

## Features by effort

### Easy: protocol already exists

| Feature | How |
|---|---|
| Remote on/off of all eight outputs | send `0x09` per channel, or `0x07` to the panel |
| PWM dimming and fan speed | `0x09` mode 2, duty and frequency per channel |
| Soft start for pumps and fans | `0x09` mode 3 with soft-start ticks |
| Timed output, momentary action | `0x10` pulse in milliseconds |
| Flasher for indicators or hazards | `0x0E` with on/off ticks and single-shot |
| Wiper slow, fast, intermittent, wash, swipe | `0x0D` actions 0 to 5 |
| Starter disable during cranking | `0x12` with a channel bitmask |
| Input-driven outputs | `0x0F` bitmask from ESP32 GPIOs or CAN |
| Speed or throttle mapping | `0x11` counter to PWM duty |
| Output state polling | `0x0A` status request |
| Force override | `0x0B` force on, off or toggle |
| Option byte AFR configuration | `0x0C`, one time, needs a power cycle |
| Remote button presses on the panel | inject `0x08 0x0C` frames to the panel |
| Read every panel button press | listen for panel `0x08 0x0C` frames |
| Panel power button as a CAN command | forward panel `0x07` frames |

### Medium: small amount of ESP32 logic

| Feature | How |
|---|---|
| CAN control of every output | map CAN IDs to the frames above |
| Macros and scenes | sequence several frames with idle gaps |
| Button remapping | panel `0x08` in, custom action out |
| Two-way status in a CAN frame | poll `0x0A`, publish the result |
| Panel UI without a base | send `0x1B` at boot and answer the panel frames |
| Mode changes from CAN | inject the mode button bitmask |
| Valet or all-off from CAN | use the base's long-press or force command |
| Wiper park handling | read park on an ESP32 GPIO, send `0x0D` action 0 |
| Ignition and cranking logic | read ACC and crank on ESP32 inputs |
| Log capture | second UART on J3 at 921600 for diagnostics |

### Hard: needs panel firmware work

| Feature | How |
|---|---|
| Custom BLE name and services | requires an ASR image change, then J3 flashing |
| Direct LED control from the ESP32 | the ASR owns the LED link; would need an ASR change |
| New button behaviours in the panel | requires an ASR image change |
| Panel-side configuration storage | ASR NVDS is blank on this unit |

## What the panel already gives us for free

- A 4x5 keypad matrix with press and release events.
- A backlight setting mode and an RGB cycle timer.
- A work mode entered by repeated key 13 presses.
- Temporary all-off and restore.
- Per-channel control mode stored in panel RAM.
- BLE advertising through the ASR stack.

Emulating button presses on the panel link is enough to reach all of these
without touching the panel firmware.

## Recommended ESP32 behaviour

1. On boot, send the `0x1B` startup frame to the panel side, then behave as the
   base: answer panel frames and forward selected button events.
2. Keep a map from panel button events to base commands, so a button press can
   drive any output or macro.
3. Pass panel `0x07` and `0x08` frames to the base by default, and substitute
   the custom `0x09` to `0x12` frames when automation is active.
4. Keep the frame rate low and leave an idle gap between frames; framing is
   gap-delimited and the checksum must match.
5. Use the J3 log port only for diagnostics, never as the product link.

## Open items that affect the list

- Runtime pinout of the ASR, needed only if an ASR image change is planned.
- LED colour table, needed only for direct LED control from the panel side.
- BLE provisioning details, needed only for BLE features.
