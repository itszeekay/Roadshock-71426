#!/usr/bin/env python3
"""Semantic names for STM8 base-board data globals (decomp rename layer).

Applied to the Ghidra decomp output (analysis/decomp12_ghidra). Each entry maps a
Ghidra ``DAT_``/``_DAT_`` token to a human-readable name derived from how the
global is used in the firmware (call sites, init values, and consumers).
"""

BASE_DAT = {
    # --- Reset / stack-pointer area ----------------------------------------
    # Holds the SP/frame values written into the reset entry (0x9c89..0x9c92).
    "_DAT_03fe": "reset_sp",

    # --- Scheduler dispatch table (init_walker walks 0x01c5..0x01f7) -------
    # 2-byte fields. Function-pointer entries are the scheduler callbacks that
    # init_walker links through; numeric entries are counters/parameters.
    "_DAT_01c5": "sched_entry_cnt",
    "_DAT_01c7": "sched_apply_fn",     # = channels_apply
    "_DAT_01ca": "sched_cnt_0",
    "_DAT_01cc": "sched_cnt_1",        # 0x32 (50)
    "_DAT_01ce": "sched_cnt_2",
    "_DAT_01d0": "sched_cnt_3",
    "_DAT_01d2": "sched_tick_fn",      # = mode_tick
    "_DAT_01d5": "sched_cnt_4",
    "_DAT_01d7": "sched_cnt_5",        # 0x4b (75)
    "_DAT_01d9": "sched_cnt_6",
    "_DAT_01db": "sched_cnt_7",
    "_DAT_01dd": "sched_drain_fn",     # = tx_queue_drain
    "DAT_01ea": "sched_active",        # = 1
    "_DAT_01eb": "sched_cnt_8",
    "_DAT_01ed": "sched_cnt_9",        # 10
    "_DAT_01ef": "sched_cnt_10",
    "_DAT_01f1": "sched_cnt_11",
    "_DAT_01f3": "sched_tx_idx_ptr",   # = tx_index
    "DAT_01f5": "clk_cfg_ptr",         # config-table pointer (0x0134)
    "_DAT_01f5": "clk_cfg_ptr_save",
    "_DAT_01f7": "clk_cfg_magic",       # 0xb421
    "DAT_02a0": "ch_state_table",       # 14 x 2-byte channel-state array
    "DAT_02ce": "tx_msg_queue",         # message queue scanned for zero-count entries
    "DAT_02df": "pin_table",            # 12-entry GPIO pin table

    # --- Message / timeout --------------------------------------------------
    "_DAT_02cb": "msg_timeout",          # 10000 by cmd 0x0D; TIM4 ISR decrements; 0 = expiry

    # --- UART control-character masks (9780_uart1_set_control_bits) --------
    "DAT_7f73": "uart_ctrl_mask_a",       # applied to control chars (0x0f..0x12,0x17)
    "DAT_7f75": "uart_ctrl_mask_b",

    # --- Code pointer into init_walker chain ---------------------------------
    "DAT_9b5c": "walker_entry",

    # --- UART parameters (set by callers) -------------------------------------
    "DAT_0002": "uart_baud",              # 0x960 = 2400
    "DAT_0004": "uart_ctrl_a",
    "DAT_0005": "uart_ctrl_b",
    "DAT_0006": "uart_ctrl_c",
    "DAT_0007": "uart_mode",
    # --- Save/restore register scratch (9147_save_ptr_0 / 916e_save_ptr_3) ---
    "DAT_000f": "reg_save_0",
}

if __name__ == "__main__":
    for k in sorted(BASE_DAT):
        print("%-14s -> %s" % (k, BASE_DAT[k]))
