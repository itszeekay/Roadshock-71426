# Roadshock 71426: Configuration Options

Three ways to run the panel. Stock is the default; the other two add a microcontroller.

## 1. Stock (no modifications)
- Panel works exactly as it came from the factory.
- Four modes via the Mode button: toggle, momentary, pulse, blink.
- No remote control, no dimming, no automation.

## 2. Panel + Smart Controller (stock firmware on the middle MCU)
- Add a separate microcontroller (ESP32, RP2040, etc.) to send commands over the 2400 baud link.
- Can turn channels on/off and cycle modes remotely.
- **Limited to:** No PWM dimming, no status feedback, no auto-functions, no persistence after power loss.

## 3. Panel + Custom Firmware (flash once via SWIM header)
- Full control. All 6 PWM-capable channels work. Settings persist.
- **Hardware PWM on 6 channels:**
  - Channels 1 & 5: Independent speed/ramp control (radiator fans, fuel pumps) - Group B (TIM2)
  - Channels 3, 4, 6, 7: Dimming/brightness control (LED light bars) - Group A (TIM1)
  - Channels 2 & 8: GPIO only (software PWM available but coarse - not for smooth control)
- **Auto-functions (all persist after power loss):**
  - Valet mode: Hold any button ~0.8 s → all outputs off
  - Delayed-off (fan/run-on): Configurable 0-255 s; channel stays on after release, then auto-off
  - Double-tap latch: Two presses <1 s → momentary function becomes toggle
  - Force override: Immediately on/off/toggle any channel; clears on next panel event
- **Status feedback:** Request current state of all 6 channels + master at any time

---

**Choose option 3 if you want dimming, auto-functions, or remote status.** Otherwise stock works fine for basic on/off.

*See `docs/startup_guide.md` for wiring, flashing, and protocol details.*

**Real-world use cases:**
- Radiator fan control (variable speed)
- Fuel pump priming and run-on
- LED light bar dimming
- Water pump on/off
- Auxiliary fan control
- Ignition/ECU power
- Compressor clutch control
- Windshield wiper speed control (slow/fast PWM, intermittent wipe)

**Wiper control:** The custom firmware adds dedicated wiper control via the custom protocol type `0x0D` (off, slow PWM, fast PWM, intermittent momentary). The wiper output is driven on Channel 5 (PC5/TIM2_CH1, 10 A fuse), which uses hardware PWM with an independent frequency. The high-speed winding of the wiper motor is PWM driven; the low-speed winding is left disconnected. Park-position feedback is not available on the base board. The middle ECU polls the park switch through a GPIO and resistor divider and sends `type 0x0D action=0` to turn Channel 5 off when park is detected.