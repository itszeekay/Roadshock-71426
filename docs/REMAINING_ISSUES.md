# ROADSHOCK PROJECT - REMAINING ISSUES & PLAN

## 1. UART Baud Divisor Issue
- Problem: Divider computed at runtime, not statically reachable
- Evidence: BRR1=0xA0, BRR2=0x1A (divider 6666) → 2400 baud (confirmed)
- Location: decompilation_status.md §124-159 (baud divisor §6)
- Solution:
  1. Find where BRR1/BRR2 are set in firmware_reconstruction.c
  2. Identify the function that computes the divisor value
  3. Extract the static value or create a macro for static access
  4. Add documentation to STATUS.md

## 2. Reset Vector Anomaly
- Problem: Slot 0 (0x9C82) is a stub writing FLASH_KEYREG_B, real startup at 0x9CD8
- Evidence: docs/STATUS.md:38; docs/firmware_static_analysis.md §142-143
- Solution:
  1. Verify reset vector parsing in function_index.md
  2. Trace reset_startup function in firmware_reconstruction.c
  3. Document clearly in STATUS.md about real startup point

3. UART Pins Confirmation
- Problem: PD1/PD2 mapping assumed from datasheet, not confirmed on PCB
- Solution:
  - Add hardware verification step to next_steps
  - Document exact pins used in firmware_reconstruction

4. Addresses 0x5062/0x5064
- Problem: Flash-key-like registers don't match documented block
- Solution: Document discrepancy and note it requires verification

5. Decode drift zones
- Problem: 0x8080–0x8130, 0x8FA0–0x8FA8, 0x9510–0x9545
- Solution: Document these zones as known problematic areas in decompilation

6. Four Stock Modes Timing
- Problem: Not fully implemented or verified
- Solution: Extract timing details from decompiled code

7. Panel LED Colour Map
- Problem: Nibble to RGB mapping not finalized
- Solution: Analyze captured frames to determine colour mapping

## 8. MEGA_EPIC_CANBUS Fork Analysis
- Project: epicefi_iox_bundle_mega2560.zip (2.2MB)
- Project: MEGA_EPIC_CANBUS fork of ggurov/MEGA_EPIC_CANBUS
- Pain Points:
  1. MCU mismatch (ATmega2560 vs RP2040)
  2. Toolchain mismatch (arduino-cli vs CircuitPython/SDCC)
  3. No native Feather RP2040 support
  4. Binary protocol vs our 2400-baud protocol
  5. Pin count mismatch (54+ vs fewer)
  6. CAN controller mismatch (MCP2515 vs CAN2040)
  7. Web config vs CLI/serial config
  8. Source visibility: only precompiled hex, no source code visible

## 9. Immediate Next Steps
1. Extract and examine MEGA_EPIC_CANBUS key files
2. Document pain points and required modifications for RP2040 port
3. Address UART baud divisor issue first (most critical)
4. Document reset vector anomaly clearly
5. Update STATUS.md with comprehensive open items list
6. Begin work on four stock modes timing extraction
7. Document panel LED colour map from captured frames
