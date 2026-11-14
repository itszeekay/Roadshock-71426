# Custom ASR5601S application: prerequisites

What is already in place, and what is still needed, for a custom BLE
application on the panel's ASR5601S. This is groundwork only; no application is
started here.

## Where the code runs

| Region | Address | Current content |
|---|---|---|
| bootloader | `0x10000000` | `ASRBOOTLOADER-560X-MX-V2.0.2` |
| BLE stack | `0x1000D000` | `rom-asr-1.00`, `ASONATA_BLE_NONOS_V1.4.1` |
| application | `0x10048000` | `app-1.0.2-20240319.1000` |
| ATE | `0x100F0000` | blank |

The BLE stack and its API stay in the ROM. A custom application is linked
against those ROM entry points and replaces only the application region.

## Already in place

| Item | Status |
|---|---|
| Full flash backup | `dumps/asr/asr_flash.bin`, two identical reads, hash recorded |
| Mask ROM backup | `dumps/asr/asr_rom.bin`, 8 KB |
| Read path | SWD, and the ROM monitor over J3 |
| Word read and write over J3 | `rdreg` and `wrreg`, verified |
| Code execution over J3 | RAM boot with a self-built image, verified |
| Boot strap control | `SEL0` from the Feather, or a jumper |
| Recovery | SWD in the ROM monitor, or a power cycle |

## Still needed

| Item | Why | Notes |
|---|---|---|
| ASR BLE NONOS SDK | headers, linker scripts, ROM API declarations | linked from ASR's Quick Start documentation |
| ARM toolchain | build the application | `arm-none-eabi-gcc` or Keil |
| Flash programming stub | write the application region | the ROM has flash routines; a RAM stub can call them |
| Application image header | the bootloader verifies the app before jumping | reuse the stock header as the template |
| BLE configuration | name, services, advertising | NVDS is blank on this unit |
| Test plan | verify radio and panel behaviour | needs a phone and the panel wired to a base or an emulator |

## The write path

The ROM monitor has no `erase` or `burn`. The working route is:

1. Enter the ROM monitor with `SEL0` high.
2. Send a small stub with `boot`. This is proven and documented in
   [asr5601_monitor.md](asr5601_monitor.md).
3. The stub drives the flash controller, using the same routines the bootloader
   uses for OTA writes.
4. Verify by reading the region back, then reset.

What is not done yet: the stub itself. The bootloader's flash routines are
decompiled and their addresses are known, so the remaining work is to package
them into a RAM image and test on the ATE partition first.

## Application image header

The bootloader verifies the application before it jumps, and prints
`app image verify pass` or `app image verify failed: reboot`. The ROM also holds
the strings `image token unexpected`, `image length unexpected` and
`image crc unexpected`, which describe the same header fields: a token, a
length and a CRC.

The stock application is the reference. Keep its header and vector table layout,
and replace the body. The exact field offsets still need to be read out of the
verifier.

## BLE notes from the dump

- Stack: `ASONATA_BLE_NONOS_V1.4.1`, no RTOS.
- API prefix: `sonata_`. GAP and GATT callbacks are named `app_gap_*` and
  `app_ble_*`.
- Advertising helpers present: `app_ble_set_adv_data`,
  `app_ble_start_advertising`, `app_ble_config_legacy_advertising`.
- The NVDS block at `0x1000A000` holds only the tag, so the device name and
  bonding data are set at runtime or were never provisioned.
- The panel has no BLE advertising in its current state when powered alone, so
  advertising is conditional in the vendor application.

## Radio

The ASR drives the RF port at pin 1, and the panel PCB carries the matching
network. No hardware change is needed for BLE.

## Recommended order when the work starts

1. Build the flash stub and prove it on the ATE partition.
2. Write a minimal application that keeps the stock vector table and header and
   only toggles one output, then confirm the bootloader accepts it.
3. Add the BLE stack calls and verify advertising with a phone.
4. Only then replace the UI behaviour.

Step 2 is the safety gate: if the bootloader rejects the image, the stock
application is still intact in the backup.
