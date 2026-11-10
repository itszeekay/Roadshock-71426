# Roadshock 71426: Configuration Options

You can run your Roadshock panel in one of three ways, depending on how much control you need.

## Feature Overview

| Feature | Stock Panel | Panel + Smart Controller | Panel + Custom Firmware |
| :--- | :---: | :---: | :---: |
| **Simple Operation** | ✅ | ✅ | ✅ |
| **Remote Control (App/Web)** | ❌ | ⚠️ *Limited* | ✅ **Full** |
| **Advanced Auto-Functions** | ❌ | ❌ | ✅ **Yes** |
| **System Diagnostics** | ❌ | ❌ | ✅ **Real-time** |

---

## The Three Configurations

### 1. Stock (No Modifications)
*Use this if you just want the panel to work exactly as it came out of the box.*
- **Experience:** Reliable, simple 12 V power distribution.
- **Limitation:** Fixed functionality. No remote access, no dimming, no automation.

### 2. Panel + Smart Controller (Stock Firmware)
*Use this if you want remote control but don't want to flash the panel.*
- **Experience:** Add a middle MCU (like an ESP32) to send basic commands.
- **Capabilities:** Turn channels on/off and cycle modes remotely.
- **Limitation:** You are limited to the stock firmware's capabilities; no status feedback, no PWM dimming, no advanced logic.

### 3. Panel + Custom Firmware (Recommended)
*Use this to unlock the full potential of your hardware.*
- **Experience:** A smart power distribution system.
- **Capabilities:**
    - **Smooth Dimming (PWM):** Control LED brightness or motor speed on 6 channels.
    - **Smart Auto-Functions:** 
        - *Valet Mode:* Hold any button to kill all power.
        - *Fan/Pump Run-on:* Set a timer for pumps or fans to run after engine shutdown.
        - *Smart Latching:* Double-tap to toggle functions.
    - **Full Diagnostics:** Real-time status feedback for every channel.
    - **Total Control:** Override any channel instantly.

---

## Hardware PWM Compatibility

To ensure smooth performance, we've optimized 6 channels for hardware-accelerated control (dimming/speed):

| Channel | Best Use |
| :--- | :--- |
| **1 & 5** | **Independent Speed/Ramp Control** (e.g., Radiator fans, Fuel pumps) |
| **3, 4, 6, 7** | **Dimming / Brightness Control** (e.g., LED light bars) |
| **2 & 8** | On/Off only (High-power devices) |

---

## How to get started
If you choose **Option 3**, simply flash the panel once using our provided firmware image via the SWIM header. No further hardware mods or proprietary apps are required.

*For wiring guides, protocol documentation for developers, and flashing instructions, see `docs/startup_guide.md`.*