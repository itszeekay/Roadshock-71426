# Build/refresh the STM8 panel annotation layer in the Ghidra project (idempotent).
# Ghidra 11.3.1, STM8:BE:16, Roadstm8Panel project.
# @category STM8
from ghidra.program.model.symbol import SourceType

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
for pi, port in enumerate(["PA", "PB", "PC", "PD", "PE", "PF"]):
    for bi, b in enumerate(pb):
        REGS[0x5000 + pi * 5 + bi] = "%s_%s" % (port, b)
for i, n in enumerate(["TIM4_CR1", "TIM4_CR2", "TIM4_SMCR", "TIM4_ETR", "TIM4_IER",
                       "TIM4_SR1", "TIM4_SR2", "TIM4_EGR", "TIM4_CNTR", "TIM4_PSCR",
                       "TIM4_ARR"]):
    REGS[0x5340 + i] = n
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
    0x0010: "led_pin_table",
    0x023E: "rx_frame_data",
    0x025E: "rx_frame_len",
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

label(0x8AB4, "led_pin_table_flash")
label(0x0010, "led_pin_table")

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
    # display frame handler (Roadstm8Panel, 2026-11-09)
    (0x844C, "display_frame_handler"),
    (0x8F38, "pin1_set_low"),
    (0x8F44, "pin1_set_high"),
    (0x8F3E, "pin2_set_high"),
    (0x8EFD, "get_pin1"),
    (0x8E7F, "get_pin2"),
    (0x8E72, "get_pin3"),
    (0x8F65, "pin_clear"),
    (0x8F68, "pin_set"),
    (0x8C52, "led_gpio_init"),
    (0x8D26, "uart1_init_115200"),
    (0x8080, "uart1_param_check"),
    (0x8252, "mul_wide"),
    (0x896D, "panel_main_loop"),
    (0x8510, "gpio_init"),
    # batch 2 (2026-11-09 functions batch)
    (0x8841, "desync_8841"),
    (0x816D, "uart_config_tail"),
    (0x85C1, "uart1_cr_bits_checked"),
    (0x82E4, "div_helper"),
    (0x8A52, "led_selftest"),
    (0x89EF, "led_state_read"),
    (0x8B0C, "vec_8b0c_isr"),
    (0x8BA9, "baud_lookup"),
    (0x8BE4, "pin_ctrl_a"),
    (0x83A2, "identity_fn"),
    (0x8B8A, "display_step"),
    (0x8FFE, "irq_fill_8ffe"),
    (0x8AF0, "led_nibble_dispatch"),
    (0x8CAC, "pin_ctrl_b"),
    (0x8CD6, "pin_ctrl_c"),
    (0x8D4D, "vec_8d4d_isr"),
    (0x9686, "unused_9686"),
    (0x8F8F, "irq_fill_8f8f"),
    (0x8FBA, "irq_fill_8fba"),
    (0x8FCB, "irq_fill_8fcb"),
    (0x8FDC, "irq_fill_8fdc"),
    (0x8FED, "irq_fill_8fed"),
    (0x908A, "desync_908a"),
    (0x9510, "desync_9510"),
    (0x95DE, "desync_95de"),
    (0x97D3, "desync_97d3"),
    (0x9824, "desync_9824"),
    (0x9BCF, "desync_9bcf"),
    (0x9C31, "desync_9c31"),
    (0x9C5B, "desync_9c5b"),
    (0x8237, "arith_sub"),
    (0x836C, "identity_fn_2"),
    (0x8C31, "display_wait"),
    (0x8B62, "load_pair_0"),
    (0x8C81, "uart_brr_clear"),
    (0x8E05, "addr_lookup"),
    (0x8DA3, "pin_ctrl"),
    (0x8DBD, "pin_ctrl_2"),
    (0x8DD6, "pin_ctrl_3"),
    (0x8351, "reg_write_a"),
    (0x8DEF, "uart_cr_a"),
    (0x8E1B, "init_walker"),
    (0x8E2F, "reg_read_a"),
    (0x837F, "save_ptr"),
    (0x8FA0, "irq_fill_8fa0"),
    (0x8B72, "load_pair_1"),
    (0x8B7E, "load_pair_2"),
    (0x8C1E, "pin_init"),
    (0x8E43, "reset_chain"),
    (0x8D74, "pin_set_call"),
    (0x8D81, "pin_set_call_2"),
    (0x8E56, "led_shift"),
    (0x8EA6, "step_pair"),
    (0x83BF, "save_ptr_0"),
    (0x83CA, "save_ptr_1"),
    (0x83D5, "save_ptr_2"),
    (0x83E0, "save_ptr_3"),
    (0x8E8C, "uart_clear_20"),
    (0x8E99, "shift_loop"),
    (0x8EF3, "shift_loop_2"),
    (0x8F18, "nibble_map"),
    (0x8F50, "bank_helper"),
    (0x83EB, "stack_ret"),
    (0x83FE, "save_regs_0"),
    (0x840B, "save_regs_1"),
    (0x8418, "save_regs_2"),
    (0x8425, "save_regs_3"),
    (0x8432, "save_regs_4"),
    (0x843F, "save_regs_5"),
    (0x8D8E, "identity_2"),
    (0x8E65, "display_kick"),
    (0x8EA1, "shr_4"),
    (0x8EB1, "trap_setup_a"),
    (0x8EBC, "trap_setup_b"),
    (0x8EC7, "trap_setup_c"),
    (0x8ED2, "trap_setup_d"),
    (0x8EDD, "trap_setup_e"),
    (0x8EE8, "trap_setup_f"),
    (0x8F31, "pin_or_low"),
    (0x8FB5, "irq_fill_8fb5"),
    (0x8F06, "led_off"),
    (0x8F0F, "clk_trim_clear"),
    (0x8F21, "mul_wide_call"),
    (0x8F59, "pin_and_low"),
    (0x8362, "bank_0"),
    (0x8367, "bank_8"),
    (0x838E, "bank_0b"),
    (0x8393, "bank_4"),
    (0x8398, "bank_8b"),
    (0x839D, "bank_c"),
    (0x8508, "frame_fail"),
    (0x8F29, "uart_prelude"),
    (0x8F4A, "nibble_get"),
    (0x8F6B, "cc_ret"),
    (0x8F71, "ret_one"),
    (0x82DC, "div_panel"),
    (0x83F6, "save_chain_a"),
    (0x83FA, "save_chain_b"),
    (0x8F5D, "uart1_read_dr"),
    (0x8F61, "uart1_write_dr"),
    (0x8F77, "nop_spin"),
    (0x82E1, "div_panel_2"),
    (0x83F3, "save_chain_c"),
    (0x8AC3, "desync_8ac3"),
    (0x8F6E, "nop_spin_2"),
    (0x8F74, "bank_helper_2"),
    (0x8F7A, "spin_wdt"),
    (0x8F7C, "unused_vec_8f7c"),
    (0x8F7D, "unused_vec_8f7d"),
    (0x8F7E, "unused_vec_8f7e"),
    (0x8F7F, "unused_vec_8f7f"),
    (0x8F80, "unused_vec_8f80"),
    (0x8F81, "unused_vec_8f81"),
    (0x8F82, "unused_vec_8f82"),
    (0x8F83, "unused_vec_8f83"),
    (0x8F84, "unused_vec_8f84"),
    (0x8F85, "unused_vec_8f85"),
    (0x8F86, "unused_vec_8f86"),
    (0x8F87, "unused_vec_8f87"),
    (0x8F88, "unused_vec_8f88"),
    (0x8F89, "unused_vec_8f89"),
    (0x8F8A, "unused_vec_8f8a"),
    (0x8F8B, "unused_vec_8f8b"),
    (0x8F8C, "unused_vec_8f8c"),
    (0x8F8D, "unused_vec_8f8d"),
    (0x8F8E, "noop"),
]

named = sum(1 for a, n in verified if rename(a, n))

def plate(addr, text):
    try:
        setPlateComment(toAddr(addr), text)
    except:
        pass

plate(0x844C,
      "Display frame handler (ASR -> STM8, 115200 8N1).\n"
      "Validates 9-byte frame: [0]=0x5A, [8]=0xEE, len=9.\n"
      "Splits bytes 2-5 into 8 nibbles (abStack_8), then dispatches per channel.\n"
      "Nibble table: 0/2/4/6=off, 1=pin1, 3=pin3, 5=pin2, 7=pin1+pin2, 8-15=unchanged.\n"
      "Active-low: low=lit. See docs/panel_led_map.md.")
plate(0x8C52,
      "LED GPIO init. Iterates _DAT_0008=0x0010 with DAT_000a=0x18 (24 pins), calls sub_8510 with mode 0xF0.")
plate(0x8D26,
      "UART1 init for 115200 (Roadstm8Panel). Sets DAT_0007=0x0C, DAT_0006=0x80,\n"
      "DAT_0002=0xC200 (115200), then calls the configure chain. Parallel to the\n"
      "base board uart1_init_2400 (0x9B17, DAT_0002=0x960).")
plate(0x8080,
      "UART1 parameter check/checker. Validates DAT_000e/DAT_000c/DAT_000d and\n"
      "mask args against valid sets; calls sub_8edd on failure.")
plate(0x896D,
      "Panel main loop. Calls uart1_init_115200, led_gpio_init, sub_8a52 twice,\n"
      "enables interrupts, prints the DAT_005b buffer, then loops calling\n"
      "display_frame_handler (sub_844c) + sub_8e65.")
plate(0x8252, "Wide multiply helper (MUL with carry), panel twin of base mul_wide.")
plate(0x8841, "Decompiler desync artifact (SP-relative heap arithmetic). Not a real entry point.")
plate(0x816D, "Ghidra split artifact: starts mid-UART-config (BRR writes). Real entry is uart1_param_check.")
plate(0x908A, "Decompiler desync artifact (bad instruction / 0xFF filler).")
plate(0x9510, "Decompiler desync artifact (bad instruction / 0xFF filler).")
plate(0x8510, "GPIO_Init helper (SPL-style). Mode 0xF0 = push-pull output.")

print "build_panel_project: %d functions named" % (named,)
