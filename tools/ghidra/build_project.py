# Build/refresh the STM8 annotation layer in the Ghidra project (idempotent).
#  - memory blocks for RAM / EEPROM / OPT / peripherals / core
#  - labels for every STM8S003 peripheral register + known RAM objects + vectors
#  - verified function names
#  - plate comments on key routines
#  - per-instruction EOL comments naming the register/object touched
#    (needed because the STM8 sleigh prints operand hex directly)
# @category STM8
from ghidra.program.model.symbol import SourceType
from ghidra.program.model.address import Address

mem = currentProgram.getMemory()
st = currentProgram.getSymbolTable()

REGS = {}
for i, n in enumerate(["UART1_SR", "UART1_DR", "UART1_BRR1", "UART1_BRR2",
                       "UART1_CR1", "UART1_CR2", "UART1_CR3", "UART1_CR4",
                       "UART1_CR5", "UART1_GTR", "UART1_PSCR"]):
    REGS[0x5230 + i] = n
for i, n in enumerate(["CLK_ICKR", "CLK_ECKR", "CLK_RSVD2", "CLK_CMSR", "CLK_SWR",
                       "CLK_SWCR", "CLK_CKDIVR", "CLK_PCKENR1", "CLK_CSSR",
                       "CLK_CCOR", "CLK_PCKENR2", "CLK_HSITRIMR"]):
    REGS[0x50C0 + i] = n
pb = ["ODR", "IDR", "DDR", "CR1", "CR2"]
for pi, port in enumerate(["PA", "PB", "PC", "PD"]):
    for bi, b in enumerate(pb):
        REGS[0x5000 + pi * 5 + bi] = "%s_%s" % (port, b)
for i, n in enumerate(["TIM4_CR1", "TIM4_CR2", "TIM4_SMCR", "TIM4_ETR", "TIM4_IER",
                       "TIM4_SR1", "TIM4_SR2", "TIM4_EGR", "TIM4_CNTR", "TIM4_PSCR",
                       "TIM4_ARR"]):
    REGS[0x5340 + i] = n
for i, n in enumerate(["TIM2_CR1", "TIM2_CR2", "TIM2_SMCR", "TIM2_IER", "TIM2_SR1",
                       "TIM2_SR2", "TIM2_EGR", "TIM2_CCMR1", "TIM2_CCMR2",
                       "TIM2_CCER1", "TIM2_CNTRH", "TIM2_CNTRL", "TIM2_PSCR",
                       "TIM2_ARRH", "TIM2_ARRL", "TIM2_CCR1H", "TIM2_CCR1L",
                       "TIM2_CCR2H", "TIM2_CCR2L"]):
    REGS[0x5300 + i] = n
for i, n in enumerate(["I2C_CR1", "I2C_CR2", "I2C_FREQR", "I2C_OARL", "I2C_OARH",
                       "I2C_DR", "I2C_SR1", "I2C_SR2", "I2C_CCRL", "I2C_CCRH",
                       "I2C_TRISER", "I2C_ITR"]):
    REGS[0x5210 + i] = n
for i, n in enumerate(["ADC1_CSR", "ADC1_CR1", "ADC1_CR2", "ADC1_CR3",
                       "ADC1_DRH", "ADC1_DRL"]):
    REGS[0x5400 + i] = n
REGS.update({0x5050: "FLASH_CR1", 0x5051: "FLASH_CR2", 0x5052: "FLASH_NCR2",
             0x5053: "FLASH_FPR", 0x5054: "FLASH_NFPR", 0x5055: "FLASH_IAPSR",
             0x5056: "FLASH_PUKR", 0x5059: "FLASH_DUKR",
             0x5062: "FLASH_KEYREG_A", 0x5064: "FLASH_KEYREG_B",
             0x50E0: "IWDG_KR", 0x50E1: "IWDG_PR", 0x50E2: "IWDG_RLR",
             0x50A0: "ITC_SPR1", 0x50A1: "ITC_SPR2", 0x50A2: "ITC_SPR3",
             0x50A3: "ITC_SPR4", 0x50A4: "ITC_SPR5", 0x50A5: "ITC_SPR6",
             0x50A6: "ITC_SPR7", 0x50A7: "ITC_SPR8",
             0x50D1: "WWDG_CR", 0x50D2: "WWDG_WR",
             0x5430: "AWU_CSR", 0x5431: "AWU_APR", 0x5432: "AWU_TBR",
             0x50B3: "RST_SR", 0x7F00: "CFG_GCR"})

RAMS = {
    0x023E: "rx_frame_data",
    0x025E: "rx_frame_len",
    0x02D0: "uart_state_a",
    0x02D2: "uart_flag_b",
    0x02D3: "uart_flag_c",
    0x02D8: "pin_state_d3",
    0x0303: "pin_state_d4",
}


def ensure_block(name, addr, size):
    a = toAddr(addr)
    b = mem.getBlock(a)
    if b is not None:
        return
    try:
        mem.createUninitializedBlock(name, a, size, False)
    except Exception as e:
        print "block %s failed: %s" % (name, e)


# repair: the imported image block must keep a meaningful name
imgblk = mem.getBlock(toAddr(0x8000))
if imgblk is not None and imgblk.getName() == "RAM":
    imgblk.setName("firmware_flash")
    print "renamed image block to firmware_flash"

ensure_block("RAM", 0x0000, 0x0400)
ensure_block("EEPROM", 0x4000, 0x0080)
ensure_block("OPT_BYTES", 0x4800, 0x0080)
ensure_block("PERIPH", 0x5000, 0x0800)
ensure_block("CORE_DEBUG", 0x7F00, 0x0100)


def label(addr, name):
    try:
        a = toAddr(addr)
        s = st.getPrimarySymbol(a)
        if s is not None:
            if s.getName() != name:
                s.setName(name, SourceType.USER_DEFINED)
            return
        createLabel(a, name, True)
    except Exception as e:
        pass


for a, n in REGS.items():
    label(a, n)
for a, n in RAMS.items():
    label(a, n)

label(0x023E, "rx_frame_data")
label(0x025E, "rx_frame_len")

vnames = ["VEC00_RESET", "VEC01_TRAP", "VEC02_TLI", "VEC03_AWU", "VEC04_CLK",
          "VEC05_EXTI0", "VEC06_EXTI1", "VEC07_EXTI2", "VEC08_EXTI3", "VEC09_EXTI4",
          "VEC10_SPI", "VEC11_TIM1_OVF", "VEC12_TIM1_CC", "VEC13_TIM2_OVF",
          "VEC14_TIM2_CC", "VEC15_TIM1_BRK", "VEC16_TIM1_TRIG", "VEC17_UART1_TX",
          "VEC18_UART1_RX", "VEC19_I2C", "VEC20_ADC1", "VEC21_TIM4", "VEC22_FLASH",
          "VEC23", "VEC24", "VEC25", "VEC26", "VEC27", "VEC28", "VEC29",
          "VEC30", "VEC31"]
for i, n in enumerate(vnames):
    label(0x8000 + i * 4, n)


def rename(addr, name):
    try:
        f = getFunctionAt(toAddr(addr))
        if f is not None:
            f.setName(name, SourceType.USER_DEFINED)
            return True
    except:
        pass
    return False


verified = [
    # interrupts and main loops (2026-11-09 batch 2)
    (0x9608, "tim4_isr"),
    (0x97D3, "uart1_rx_isr"),
    (0x99E1, "ext0_pa1_isr"),
    (0x8EE6, "link_service_loop"),
    (0x8841, "state_dispatch"),
    (0x8700, "mode_tick"),
    (0x833B, "mode_apply_block"),
    (0x8A46, "param_block_apply"),
    (0x8C31, "idle_reply_builder"),
    (0x8B96, "button_frame_builder"),
    (0x935E, "tx_queue_drain"),
    (0x94D6, "outputs_init"),
    (0x92C2, "channels_apply"),
    (0x9A0B, "tim4_reset"),
    (0x8B79, "index_add_7"),
    (0x8B8A, "index_set"),
    (0x8B6E, "msg_step"),
    (0x845E, "channel_step"),
    (0x828E, "channel_step_b"),
    (0x845D, "channel_state_write_b"),
    (0x8480, "channel_ptr_2"),
    (0x8112, "channel_ptr_4"),
    (0x8118, "channel_ptr_3"),
    (0x9E40, "channel_ptr_5"),
    (0x84D5, "flag_clear_pair"),
    (0x84A5, "flag_init_pair"),
    (0x84E4, "flag_set_1"),
    (0x84CC, "mode_off_prelude"),
    (0x84B3, "mode_off_entry"),
    (0x8E30, "noop"),
    (0x8DC0, "div_small"),
    (0x95DE, "store_pair_0"),
    (0x95EC, "store_pair_1"),
    (0x95FA, "store_pair_2"),
    (0x95B5, "load_pair_0"),
    (0x95C1, "load_pair_1"),
    (0x90F3, "save_pair_0"),
    (0x90FE, "save_pair_1"),
    (0x9109, "save_pair_2"),
    (0x9114, "save_pair_3"),
    (0x9139, "save_regs_0"),
    (0x9140, "save_regs_1"),
    (0x9127, "save_regs_2"),
    (0x912E, "save_regs_chain"),
    (0x9CD2, "shl_6"),
    (0x9E34, "load_000c"),
    (0x9E46, "sum_add"),
    (0x9CA7, "flash_unlock"),
    (0x9CB8, "poll_busy"),
    (0x9CF6, "byte_store_inc"),
    (0x9DF9, "seq_inc"),
    (0x9E0D, "seq_alloc"),
    (0x9F02, "seq_alloc_2"),
    (0x9CE7, "seq_alloc_3"),
    (0x9E03, "block_copy_7"),
    (0x9E05, "block_copy_7b"),
    (0x9F06, "tim2_off"),
    (0x9D76, "tim2_enable"),
    (0x9D83, "tim2_cr1_or_80"),
    (0x9D90, "tim4_enable"),
    (0x9D9D, "uart1_clear_20"),
    (0x9E58, "itc_clear"),
    (0x9E73, "tim4_egr_set"),
    (0x9EE6, "tim2_sr1_clear"),
    (0x9EEB, "tim4_ier_set"),
    (0x9EF0, "tim4_ier_set_2"),
    (0x9E4F, "clk_trim_clear"),
    (0x9F16, "iwdg_kr_write"),
    (0x9F1A, "iwdg_pr_write"),
    (0x9F1E, "iwdg_rlr_write"),
    (0x9EDC, "iwdg_refresh"),
    (0x9EE1, "iwdg_kick_cc"),
    (0x9C95, "iwdg_setup"),
    (0x9C47, "init_walker"),
    (0x9C5B, "frame_get"),
    (0x86E8, "eeprom_sequencer"),
    (0x86AB, "post_if_ff"),
    (0x86A6, "eeprom_flush"),
    (0x86DF, "reset_state"),
    (0x86D3, "dat_0002_ret"),
    (0x8B71, "to_button_frame"),
    (0x8B8E, "channel_index_set"),
    (0x908F, "bank_post_8"),
    (0x9094, "bank_post_c"),
    (0x90C2, "bank_set_0"),
    (0x90C7, "bank_set_4"),
    (0x90CC, "bank_set_8"),
    (0x90D1, "bank_set_c"),
    (0x9099, "bank_fn_9099"),
    (0x90D6, "identity_fn"),
    (0x90AC, "frame_push_0"),
    (0x90B3, "frame_push_1"),
    (0x90BA, "stack_ret"),
    (0x911F, "stack_ret_2"),
    (0x9147, "save_ptr_0"),
    (0x9154, "save_ptr_1"),
    (0x9161, "save_ptr_2"),
    (0x916E, "save_ptr_3"),
    (0x9F12, "pin_and"),
    (0x9EBA, "pin_or"),
    (0x9D23, "flash_and_505a"),
    (0x9DDA, "flash_and_505f"),
    (0x9DC3, "ptr_02c4"),
    (0x9DE5, "eeprom_ofs"),
    (0x9E61, "pin_bit_a"),
    (0x9E6A, "pin_bit_b"),
    (0x9E95, "poll_and_load"),
    (0x9E9D, "mul_wide_call"),
    (0x9EA5, "byte_store_off24"),
    (0x9EB3, "poll_call"),
    (0x9D05, "bit_scan_a"),
    (0x9D14, "bit_scan_b"),
    (0x9D5C, "clk_enable_a"),
    (0x9D40, "clk_enable_b"),
    (0x9D4E, "clk_reg_a"),
    (0x9D69, "clk_shift"),
    (0x9DB7, "inc_pair"),
    (0x9E21, "flag1_clear2"),
    (0x99D4, "shift_loop"),
    (0x9CC8, "shl_loop"),
    (0x9D32, "pack_pair"),
    (0x84B9, "toggle_head"),
    (0x8B5D, "state_step"),
    (0x8E51, "init_pair"),
    (0x9E17, "addr_plus_10"),
    (0x95A5, "get_arg_ptr"),
    (0x95CD, "get_arg_ptr_2"),
    (0x9550, "unused_9550"),
    (0x9C31, "memset_like"),
    (0x9B3A, "boot_chain"),
    (0x8828, "bank_prelude"),
    (0x8811, "noop_2"),
    (0x8814, "tick_b"),
    (0x881C, "tick_c"),
    (0x8386, "unused_8386"),
    (0x9E03, "block_copy_7"),
    (0x9F33, "ret_one"),
    (0x9F0A, "store_0002"),
    (0x9F0E, "load_0002"),
    (0x9E2B, "eeprom_init_a"),
    (0x9DCF, "seq_save"),
    (0x9E7C, "nibble_map"),
    (0x9E8D, "noop_3"),
    (0x9EC8, "noop_4"),
    (0x9EF5, "table_lookup"),
    (0x9AC4, "identity_2"),
    (0x9ACF, "eeprom_rd_a"),
    (0x9BCF, "reg_clear_a"),
    (0x998A, "tx_index"),
    (0x8D16, "arith_sub"),
    (0x8D03, "counter_inc"),
    (0x8E40, "reg_snapshot"),
    (0x9A5C, "bad_code_9a5c"),
    (0x811E, "mode_convert"),
    # batch 3: remaining functions (2026-11-09)
    (0x8A15, "msg_alloc_loop"),
    (0x9AAA, "load_a"),
    (0x9AB7, "load_b"),
    (0x9BEB, "tim2_ier_write"),
    (0x9C03, "tim4_etr_write"),
    (0x9C6F, "msg_alloc"),
    (0x9E3D, "channel_ptr_5_store"),
    (0x9ED6, "tx_index_ret"),
    (0x9EFE, "block_copy_call"),
    (0x9F22, "uart1_dr_read"),
    (0x9F26, "uart1_dr_write"),
    (0x9F39, "nop_spin"),
    (0x9F4B, "noop_f"),
    (0x8D00, "noop_d"),
    (0x8DBB, "div_path"),
    (0x908A, "bank_0_call"),
    (0x912A, "save_pair_2w"),
    (0x9135, "frame_push_call"),
    (0x99DC, "shr_4"),
    (0x9A84, "queue_scan"),
    (0x9E85, "noop_e"),
    (0x9F3C, "unused_vec_9f3c"),
    (0x9F3E, "unused_vec_9f3e"),
    (0x9F3F, "unused_vec_9f3f"),
    (0x9F40, "unused_vec_9f40"),
    (0x9F41, "unused_vec_9f41"),
    (0x9F42, "unused_vec_9f42"),
    (0x9F43, "unused_vec_9f43"),
    (0x9F44, "unused_vec_9f44"),
    (0x9F45, "unused_vec_9f45"),
    (0x9F46, "unused_vec_9f46"),
    (0x9F47, "unused_vec_9f47"),
    (0x9F48, "unused_vec_9f48"),
    (0x9F49, "unused_vec_9f49"),
    (0x9F4A, "unused_vec_9f4a"),
    (0x9F4C, "unused_irq_vec_9f4c"),
    (0x9F5D, "unused_irq_vec_9f5d"),
    (0x9F6E, "unused_irq_vec_9f6e"),
    (0x9F7F, "unused_irq_vec_9f7f"),
    (0x9F90, "unused_irq_vec_9f90"),
    (0x81CD, "mode_dispatch_tail"),
    (0x82A8, "tim2_path_set"),
    (0x82AA, "tim2_path_set_b"),
    (0x8490, "set_6"),
    (0x8495, "pin_table_ptrs"),
    (0x84C5, "mode_head"),
    (0x86C2, "post_dispatch"),
    (0x86C8, "noop_c"),
    (0x9B72, "pa_outputs_init"),
    (0x9B92, "block_copy"),
    (0x9F30, "nop_spin_a"),
    # peripheral drivers (from firmware_static_analysis.md)
    (0x8FA9, "uart1_configure"),
    (0x9F7E, "uart1_read_dr"),
    (0x9F82, "uart1_write_dr"),
    (0x9780, "uart1_set_control_bits"),
    (0x9EC1, "tim2_set_ccr1l"),
    (0x9ECB, "tim2_set_arrh"),
    (0x9F36, "iwdg_reload"),
    (0x9F3D, "iwdg_start"),
    (0x9C76, "flash_write_key_ae"),
    (0x9C82, "flash_write_key_56"),
    (0x9423, "clk_switch"),
    (0x9464, "clk_set_divider"),
    (0x98F1, "clk_gate_enable_1"),
    (0x9DAA, "clk_gate_enable_2"),
    (0x9EAC, "clk_gate_enable_3"),
    (0x96CB, "itc_set_priority"),
    (0x9DEF, "tim4_init"),
    (0x9ECF, "tim4_clear_egr"),
    (0x9CD8, "reset_startup"),
    (0x993C, "clk_configure_all"),
    # mode handler (Roadstm8true, 2026-11-09)
    (0x8F7E, "uart1_configure"),
    (0x9B17, "uart1_init_2400"),
    (0x9C1B, "flash_key_dispatch"),
    (0x8146, "config_mode_handler"),
    (0x8FB5, "uart1_configure_ex"),
    (0x9541, "gpio_init"),
    (0x93E5, "clk_switch"),
    (0x8E5C, "system_init"),
    (0x8EE6, "link_service_loop"),
    (0x9223, "acc_sense_sample"),
    (0x9823, "mode_remap"),
    (0x966A, "itc_spr_write"),
    (0x9728, "uart1_cr_write"),
    (0x8DC3, "div_helper"),
    (0x8D31, "mul_wide"),
    (0x99B6, "mul_small"),
    (0x9A34, "block_move"),
    (0x9872, "pin_table_apply"),
    (0x917B, "state_table_init"),
    (0x8700, "mode_tick"),
    (0x833B, "mode_apply_block"),
    (0x8A46, "param_block_apply"),
    (0x8C31, "idle_reply_builder"),
    (0x8B96, "button_frame_builder"),
    (0x935E, "tx_queue_drain"),
    (0x94D6, "outputs_init"),
    (0x92C2, "channels_apply"),
    (0x995A, "mem_compare"),
    (0x98B6, "baud_lookup"),
    (0x8080, "message_post_loop"),
    (0x816D, "mode_handler"),
    (0x82B3, "button_bitmask_handler"),
    (0x848B, "channel_index_get"),
    (0x8485, "channel_pair_get"),
    (0x828D, "channel_state_write"),
    (0x8504, "channel_advance"),
    # frame handler + hidden commands
    (0x851A, "frame_handler"),
    (0x8640, "cmd_0b_handler"),
    (0x8689, "cmd_0d_handler"),
    (0x860C, "cmd_19_handler"),
    (0x86CB, "msg_post"),
    (0x86D1, "msg_next"),
    (0x86D8, "msg_peek"),
    # EEPROM writers
    (0x9927, "eeprom_write"),
    (0x9AF3, "state_clear"),
]
named = sum(1 for a, n in verified if rename(a, n))


def plate(addr, text):
    try:
        setPlateComment(toAddr(addr), text)
    except:
        pass


plate(0x8FA9,
      "UART1 configuration routine.\n"
      "  1. CR1: 8-bit word, WAKE cleared, mask OR'ed from RAM 0x0006\n"
      "  2. CR3: STOP=00 (1 stop bit), bit2 set\n"
      "  3. CR1/CR2/CR3/CR4 enable/interrupt bits set from mask\n"
      "  4. BRR1/BRR2 programmed from a computed 16-bit divisor\n"
      "No direct CALL exists in the image; reached by fall-through or via an\n"
      "indirect function pointer, so the baud divisor is not yet recovered.")
plate(0x9EC1, "Write TIM2 CCR1 low byte (PWM duty helper).")
plate(0x9ECB, "Write TIM2 ARR high byte (PWM period helper).")
plate(0x9F36, "IWDG reload/refresh (writes IWDG_KR).")
plate(0x9F3D, "IWDG start: IWDG_KR = 0xCC.")
plate(0x9C76, "FLASH key 0xAE -> FLASH_KEYREG_A (0x5062), STM8 mass-key idiom.")
plate(0x9C82, "FLASH key 0x56 -> FLASH_KEYREG_B (0x5064), STM8 mass-key idiom.")
plate(0x9CD8, "Reset entry: SP = 0x03FF, init calls, then jump to main.")
plate(0x96CB, "Interrupt priority setup via ITC_SPR1/SPR2 (0x50A0/0x50A1).")
plate(0x993C,
      "Clock tree configuration: ECKR, SWR=0xE1, SWCR, CKDIVR,\n"
      "CKDIVR=0x18 (CPUDIV=8, HSIDIV=1 -> CPU 2 MHz, f_master 16 MHz), PCKENR1=0xFF, PCKENR2=0xFF, CSSR, HSITRIMR.")
plate(0x816D,
      "Mode handler (Roadstm8true, 2026-11-09).\n"
      "Converts incoming mode byte 1/3/5/7 -> internal 0/2/4/8 (off/toggle/momentary/pulse).\n"
      "Dispatches on internal mode to sub_84b3/sub_84b9/sub_84c5/sub_8485 + sub_848b + sub_828d.\n"
      "See docs/mode_timing.md. Timing constants still need bench measurement.")
plate(0x8F7E,
      "UART1 configure (Roadstm8true, 2026-11-09). Caller is uart1_init_2400 at 0x9B17.\n"
      "Caller sets DAT_0007=0x0C, DAT_0006=0x80, DAT_0005=0, DAT_0004=0, DAT_0002=0x960 (2400)\n"
      "then CALLs this function. BRR1/BRR2 split via sub_99dc (>>4). Live value: 2400 baud\n"
      "(BRR1=0xA0, BRR2=0x1A, divider 6666). See docs/mode_timing.md.")
plate(0x8FB5, "UART1 configure with explicit params (CR1/BRR/CR2/CR3 from args).")
plate(0x8E5C,
      "System init. Calls uart1_init_2400, clk_set_divider, uart1_set_control_bits,\n"
      "sub_9b72 (output init), enables interrupts, posts message 0x1B.")
plate(0x8EE6,
      "Link service loop. When uart_flag_c is set, copies the RX frame and calls frame_handler.\n"
      "Also services DAT_02d5/DAT_025f and the pin-table block at UNK_01bf.")
plate(0x9223,
      "ACC sense sample. Reads PA_IDR bit1 (PA1), debounce 8 samples into DAT_02da,\n"
      "stores to DAT_0260. DT/DAT_02d4 selects the sample vs reset path.")
plate(0x8700,
      "Mode tick. DAT_02d7 divider (every 3rd pass), toggles pin_state_d3/d4 via\n"
      "sub_8811/8814/881c. Blink/pulse state advance.")
plate(0x94D6,
      "Outputs init. GPIO_Init on PD (0x40), tim2_set_ccr1l twice, then iterates the\n"
      "12-entry pin table at DAT_02df calling sub_9541 + FUN_9f12 per channel.")
plate(0x935E,
      "TX queue drain. Loops msg_post/msg_peek over 0..9, decrements counts,\n"
      "then scans DAT_02ce queue for zero-count messages.")
plate(0x9541,
      "GPIO_Init helper (SPL-style). Mode bits 0x80/0x10 in DAT_0000 select\n"
      "ODR/DDR/CR1/CR2 read-modify-write via the port pointer.")
plate(0x8DC3, "32-bit division/modulo helper (compiler library).")
plate(0x8D31, "Wide multiply helper (MUL with carry).")
plate(0x99B6, "Small multiply helper (MUL X,A).")
plate(0x9A34, "Block move (backward copy).")
plate(0x995A, "Memory compare (returns 0/-1/1).")
plate(0x98B6,
      "Clock/baud lookup. Reads CLK_CMSR, looks up sub_9ef5 table by CKDIVR.\n"
      "Returns DAT_0002=0x2400 (2400 baud) for the default clock, 0xF400 otherwise.")
plate(0x9B17,
      "UART init for 2400 baud (Roadstm8true, 2026-11-09).\n"
      "Sets the UART control masks and DAT_0002=0x960, then CALLs uart1_configure (0x8F7E).\n"
      "Called from 0x8E9B. This resolves the formerly open static-caller question.")
plate(0x9C1B,
      "Flash key dispatch (Roadstm8true, 2026-11-09).\n"
      "If A==0xFD, FLASH_KEYREG_A (0x5062) unlock sequence (0x56 then 0xAE).\n"
      "Otherwise FLASH_KEYREG_B (0x5064) unlock sequence (0xAE then 0x56).\n"
      "Confirms 0x5062/0x5064 are the flash unlock registers for this part.")
plate(0x8146,
      "Type-7 config mode handler (Roadstm8true, 2026-11-09).\n"
      "Called from frame_handler with 12 nibbles (abStack_b) expanded from the 6-byte payload.\n"
      "Copies the block via sub_9b92, then loops calling mode_handler logic per channel.\n"
      "See docs/hidden_commands.md.")
plate(0x851A,
      "Frame handler. Validates 11-byte checksum, dispatches on DAT_021f (type).\n"
      "Type 7: master power/parameter (6 bytes -> 12 nibbles at 0x9E85, post 0x1700).\n"
      "Type 8: button bitmask (sub_82b3, post 0x1800).\n"
      "Type 0x0B: cmd_0b_handler (sub_8640). Type 0x0D: cmd_0d_handler (sub_8689).\n"
      "Type 0x19: cmd_19_handler (sub_860c). See docs/hidden_commands.md.")
plate(0x8640, "Hidden command 0x0B handler. Updates DAT_0206, writes EEPROM via sub_9927, posts 0x1B.")
plate(0x8689, "Hidden command 0x0D handler. Type 0 -> _DAT_02cb=10000; Type 1 -> reset state, DAT_0206=10.")
plate(0x860C, "Hidden command 0x19 handler. Searches message queue for matching seq, clears it.")
plate(0x9927, "EEPROM write helper. Called from sub_86e8 and cmd_0b_handler.")
plate(0x9AF3, "State clear helper. Clears the per-channel state at param_1.")
plate(0x8000,
      "STM8S003 vector area: 32 x 4-byte entries (0x8000-0x807F).\n"
      "Entry format: 82 00 <handler_hi> <handler_lo>.\n"
      "Parsed: 00=0x9C82 05=0x99E1 15=0x9223 19=0x96CB 20=0x97D3 25=0x9608\n"
      "OPEN: reset entry parses to 0x9C82 but real startup (SP init) is 0x9CD8\n"
      "and does not appear in this area - unconfirmed until checked on hardware.")

# per-instruction naming comments (persisted, visible in the GUI listing)
from ghidra.program.model.address import GenericAddress

listing = currentProgram.getListing()
annotated = 0
it = listing.getInstructions(True)
while it.hasNext():
    ins = it.next()
    names = []
    for oi in range(ins.getNumOperands()):
        for op in ins.getOpObjects(oi):
            if isinstance(op, GenericAddress):
                v = op.getOffset()
                nm = REGS.get(v) or RAMS.get(v)
                if nm:
                    names.append(nm)
    if not names:
        continue
    txt = ", ".join(names)
    cur = ins.getComment(0)  # EOL comment type 0
    if cur is None or txt not in cur:
        try:
            ins.setComment(0, txt if not cur else cur + " | " + txt)
            annotated += 1
        except:
            pass

print "build_project: %d functions named, %d instructions annotated" % (named, annotated)
