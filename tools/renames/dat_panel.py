#!/usr/bin/env python3
"""Semantic names for STM8 panel-button data globals (decomp rename layer).

Applied to the Ghidra decomp output (analysis/decomp_panel_ghidra). Each entry maps
a Ghidra ``DAT_``/``_DAT_`` token to a human-readable name derived from how the
global is used in the firmware.

Naming policy (matches the ASR5601S approach):
  * Clear semantic globals get a name derived from their behaviour.
  * The 0x0000-0x000F register save/restore scratch block is named by its role
    (the low-RAM register-swap area used by the UART/arith helpers).
  * 2-byte "overlap" views (underscore-prefixed) are named for the distinct value
    they hold.
  * Data touched only by the flagged decompiler-desync artifact (8841) is named
    ``dsync_*`` so its non-semantic nature is visible in the reconstruction.
"""

PANEL_DAT = {
    # --- Register save/restore scratch block (0x0000-0x000F) --------------
    # save_regs_0..5 swap these; used as general working space by arith_sub,
    # mul_wide and the UART helpers.
    "DAT_0000": "reg_save_w0",
    "DAT_0001": "reg_save_w1",
    "DAT_0002": "reg_save_w2",
    "DAT_0003": "reg_save_w3",
    "DAT_0004": "reg_save_w4",
    "DAT_0005": "reg_save_w5",
    "DAT_0006": "reg_save_w6",
    "DAT_0007": "reg_save_w7",
    "DAT_0008": "reg_save_s0",
    "DAT_0009": "reg_save_s1",
    "DAT_000a": "reg_save_s2",
    "DAT_000b": "reg_save_s3",
    "DAT_000c": "reg_save_s4",
    "DAT_000d": "reg_save_s5",
    "DAT_000e": "reg_save_s6",
    "DAT_000f": "reg_save_s7",

    # 2-byte "overlap" views (same RAM, different alignment / width).
    # 0x0000 (SP low) in save_ptr chain.
    "_DAT_0000": "sp_save_lo",
    # 0x0002 (SP high) in save_ptr chain.
    "_DAT_0002": "sp_save_hi",
    # 0x0004/0x0006: divisor quotient halves in div_panel_2.
    "_DAT_0004": "div_quot_hi",
    "_DAT_0006": "div_quot_lo",
    # 2-byte view of 0x0008: GPIO pin-table pointer (led_gpio_init).
    "_DAT_0008": "gpio_pin_table",
    # 2-byte view of 0x000a: pin count (0x18 = 24 pins) (led_gpio_init).
    "_DAT_000a": "gpio_pin_count",
    # 0x000c/0x000e: 2-byte SP halves saved by save_ptr_3.
    "_DAT_000c": "sp_save_a",
    "_DAT_000e": "sp_save_b",

    # --- LED / display region ------------------------------------------
    # LED flash phase counter: set to 10 in nibble_dispatch / IRQs, decremented
    # to zero by the display ISR.
    "DAT_005c": "led_flash_cnt",
    # LED nibble index (0..8): advanced in nibble_dispatch.
    "DAT_0066": "led_nibble_idx",
    # Display frame pending flag / payload: set to 1 when a frame is posted,
    # passed as payload to display_frame_handler, cleared after the frame.
    "DAT_0067": "display_frame",
    # Frame base pointer (set to 0x58 = display frame buffer start).
    "DAT_0058": "display_frame_buf",
    # 11-byte display string length (0..0xFF) to be printed in panel_main_loop.
    "DAT_005b": "display_str_len",
    # UART control-character mask (led_selftest).
    "DAT_7f75": "led_ctrl_mask",

    # --- Reset / stack-pointer area -------------------------------------
    "_DAT_03fe": "reset_sp",

    # --- Code pointer into the panel init walker chain ------------------
    "DAT_8d99": "walker_entry",

    # --- Decompiler desync artifact scratch (only 8841_desync_8841) -----
    # This function is flagged "decompiler desync artifact (not a real entry
    # point)"; its RAM fields have no stable semantic meaning, so they are named
    # as desync scratch to stay honest in the reconstruction.
    "DAT_003a": "dsync_a0",
    "DAT_004f": "dsync_a1",
    "DAT_0053": "dsync_a2",
    "DAT_7372": "dsync_b0",
    "_DAT_7068": "dsync_b1",
    "_DAT_7665": "dsync_b2",
    "_DAT_6a65": "dsync_b3",
}

if __name__ == "__main__":
    for k in sorted(PANEL_DAT):
        print("%-14s -> %s" % (k, PANEL_DAT[k]))
