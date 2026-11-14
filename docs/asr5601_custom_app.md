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
| Full flash backup | `dumps/asr/asr_flash.bin`, two SWD reads and one J3 read, all identical |
| Mask ROM backup | `dumps/asr/asr_rom.bin`, 8 KB |
| Read path | SWD, and a full J3-only dump through the ROM monitor |
| Word read and write over J3 | `rdreg` and `wrreg`, verified |
| Code execution over J3 | RAM boot with a self-built image, verified |
| Boot strap control | `SEL0` from the Feather, or a jumper |
| Recovery | SWD in the ROM monitor, or a power cycle |
| ARM toolchain | GCC 5.4 2016q3, verified compiling for Cortex-M0+ |
| Flash programming stub | `tools/asr_stub`, erase and program proven on the ATE sector |

## Still needed

| Item | Why | Notes |
|---|---|---|
| ASR BLE NONOS SDK | headers, linker scripts, ROM API declarations | ASR distributes it from its site and free-form download page |
| Application image header | the bootloader verifies the app before jumping | reuse the stock header as the template |
| BLE configuration | name, services, advertising | NVDS is blank on this unit |
| Test plan | verify radio and panel behavior | needs a phone and the panel wired to a base or an emulator |

## Vendor tooling and where it lives

Anything that is publicly downloadable is referenced here, not distributed in
this repository.

| Item | Version | Where to get it | Local copy |
|---|---|---|---|
| ARM GNU toolchain | 5.4, 2016q3 (`5_4-2016q3-20160926`) | ARM's archived release on Launchpad | `toolchains/` in the local archive |
| ASR BLE NONOS SDK | vendor build | ASR's documentation and Drive links | `toolchains/` or the SDK folder in the local archive |
| DOGO | VP2.3.8 | ASR | `reference/asr560x/drive/` |

The toolchain archive is executable only from a local disk. Network shares in
this setup deny execution, so keep the archive copy in the local folder and a
working copy on the local disk. A quick check:

```
arm-none-eabi-gcc --version
# gcc-arm-none-eabi 5.4.1 20160919
arm-none-eabi-gcc -mcpu=cortex-m0plus -mthumb -c test.c -o test.o
```

The SDK expects this exact version on Windows. A newer GCC may build, but ASR
does not support it.

## The write path

The ROM monitor has no `erase` or `burn`. The working route is:

1. Enter the ROM monitor with `SEL0` high.
2. Send a small stub with `boot`. This is proven and documented in
   [asr5601_monitor.md](asr5601_monitor.md).
3. The stub drives the flash controller, using the same routines the bootloader
   uses for OTA writes.
4. Verify by reading the region back, then reset.

The stub is written and tested. The bootloader does not program flash directly;
it calls RAM-resident routines through pointers at `0x10004E6C` (`0x20000331`)
and `0x10004ECC` (`0x2000002D`).

Those routines are copied into RAM by the bootloader reset handler:

| Destination | Source in flash | Size |
|---|---|---|
| `0x20000000` | `0x10000120` | `0x620` |
| `0x20000620` | `0x100053E8` | `0x848` |

The first block holds the flash routines. A RAM stub can copy `0x620` bytes from
`0x10000120` to `0x20000000` and call the same entry points the bootloader uses.

The reset handler also writes `0x40006000` = 1, `0x40006004` = 2 and
`0x40006008` = 2 before use, which is likely a flash or bus configuration step.
Reproduce that order in the stub.

The bootloader's flash API, recovered from its erase and write paths:

| Wrapper (flash) | Target (RAM) | Signature | Role |
|---|---|---|---|
| `0x10004E70` | `0x20000298` | `()` | flash init, called from reset |
| `0x10004EC0` | `0x2000002C` | `()` | read lock state |
| `0x10004EB0` | `0x20000000` | `()` | unlock |
| `0x10004EA0` | `0x20000014` | `()` | lock |
| `0x10004E80` | `0x200002B8` | `(0x2520, addr)` | erase 4 KB sector at `addr` |
| `0x10004E60` | `0x20000330` | `(addr, len, data)` | program, 256-byte chunks |

The wrappers preserve all argument registers and tail-call into RAM, so a stub
can call them directly once the first block is copied.

Region table at `0x10004FF8`, 0x14 bytes per entry:

| Entry | Base | Size | Contents |
|---|---|---|---|
| 0 | `0x10000000` | `0x8000` | bootloader |
| 1 | `0x10048000` | `0x1C000` | application |
| 3 | `0x10064000` | `0x1C000` | OTA or ATE |
| 5 | `0x10007000` | `0x2000` | OTA info |

The ATE partition at `0x100F0000` is not in the table, so the high-level erase
that enforces these bounds cannot reach it. A stub must call the low-level erase
directly with the ATE address, after checking the address range itself.

Result on the panel: the write build produced `a0 a1 a2 ... af` for 256 bytes at
`0x100F0000`, and the erase-only build returned the sector to `0xFF`. Both were
verified over SWD. Source and instructions are in `tools/asr_stub/README.md`.

Next step: repeat the same test on the application region, then program a
minimal application.

## Application image header

The bootloader verifies the application before it jumps, and prints
`app image verify pass` or `app image verify failed: reboot`. The ROM also holds
the strings `image token unexpected`, `image length unexpected` and
`image crc unexpected`, which describe the same header fields: a token, a
length and a CRC.

The stock application starts directly with its vector table at `0x10048000`
(stack `0x20005000`, reset `0x1004AEFD`), and there is no separate header in
front of it. The OTA tag at `0x10008000` holds `7F 7F FF FF` then `FDB0` and is
otherwise blank, yet the stock application verifies, so the check is not driven
by a populated tag on this unit.

Practical rule: keep the vector table and the first vectors exactly where they
are, and replace only the body. Then test with a minimal application and read
the bootloader message.

## SDK and build

From ASR's environment guide:

| Item | Value |
|---|---|
| Build system | `make TARGET=<project>` from the SDK `build` directory |
| Environment | `source setBuildEnv.sh` in Git Bash |
| Toolchain | GCC `arm-none-eabi` 5.4, 2016q3, bundled in `tools/toolchain` |
| Windows rule | use the SDK-provided toolchain, ASR does not support another version |
| Output | `build/out/<project>/` |
| Example target | `sonata_hl_data_trans_demo` |
| Keil option | generate with `GenkeilPrj.bat`; flash algorithm `ASR560X_2W2D.FLM`; algorithm RAM `0x20000000`, size `0x1000` |

The 2016q3 Windows toolchain was archived by ARM and is still downloadable. It
is kept outside the public repository with the rest of the vendor tooling.

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

1. The flash stub is built and proven on the ATE partition.
2. Write a minimal application that keeps the stock vector table and header and
   only toggles one output, then confirm the bootloader accepts it.
3. Add the BLE stack calls and verify advertising with a phone.
4. Only then replace the UI behavior.

Step 2 is the safety gate: if the bootloader rejects the image, the stock
application is still intact in the backup.
