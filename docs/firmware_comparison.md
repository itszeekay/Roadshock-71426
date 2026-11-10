# Firmware Comparison: Stock vs. Custom Base Board

The middle MCU (Feather RP2040, ESP32, or any carrier) can run either the stock base firmware or the custom build. This table documents what each provides over the 2400-baud UART link.

| Capability | Stock Firmware | Custom Firmware (this repo) |
|------------|----------------|----------------------------|
| **Channel modes** | 4: Toggle, Momentary, Pulse, Blink (EEPROM only) | 4: Toggle, Momentary, Pulse, Blink (EEPROM + runtime) |
| **Mode selection** | Double-press Mode button on panel; or type 0x07 config frame | Same + explicit `PROTO_TYPE_CONFIG` (type 0x09) per channel |
| **Master on/off** | Type 0x07 flag 0/1 | Same |
| **Button events** | Type 0x08 flag 0x0C bitmask from panel | Same; Feather can inject synthetic presses |
| **PWM / dimming** | Not exposed (no CCMR/CCER writes over UART) | **Type 0x09**: channel, mode=2 (PWM), duty %, frequency Hz on ch 3,4,6,7 (PC3,PC6,PC4,PC7) |
| **EEPROM persistence** | Factory reset clears to `00 00 00 00 00 00 00 00` | **Auto-save** on press/release/master; **auto-load** at boot; bytes 0x0D-0x14 hold mode + on/off |
| **Status reporting** | Only ACK reply (`type|0x10`) | **Type 0x0A**: 6-channel state + master state on request |
| **Long press / valet** | Not implemented | **800 ms hold** on any button → master off (valet/anti-theft) |
| **ACC/ignition sense** | ISR on PA1 low → full reset | Polled in 2 ms loop; PA1 low → all outputs off (no reset) |
| **Watchdog** | IWDG enabled in stock | IWDG fed in main loop (not started by this build) |
| **PWM channels** | Internal only, not controllable | Ch 3 (PC3), 4 (PC6), 6 (PC4), 7 (PC7) via TIM1_CH3/1/4/2 |
| **Frequency range** | N/A | 50-2000 Hz (gate driver limit) |
| **Duty resolution** | N/A | 0-100% (0% = low, 100% = high) |

## How the middle MCU chooses

- **Stock path**: middle MCU acts as a transparent UART pass-through (or MITM with logging). Panel behaves exactly as shipped.
- **Custom path**: middle MCU flashes the custom `.ihx` once via SWIM, then the custom protocol (0x09/0x0A) is available. The middle MCU can still forward panel frames unchanged; the custom firmware is backward-compatible with stock panel behavior.

## Flashing the custom build

```bash
cd firmware
make
stm8flash -c stlinkv2 -p stm8s003f3 -s flash -w roadshock_full.ihx
```

The stock restore image is in `restore/base_flash.raw.bin` if needed.

## Notes for the carrier board designer

- The 2400-baud UART (PD5 TX / PD6 RX on base, J2 on panel) is the only mandatory link.
- PA1 (ACC sense) is available on the SWIM header for external monitoring.
- PD3 (AIN4) is unpopulated on the stock board; usable for a voltage divider if the carrier needs battery monitoring without ESP32 ADC.
- No changes to panel MCU (STM8S003K3) or ASR5601S are required for any custom firmware feature.