# Annotate the STM8S003 base-board firmware for readability:
#  - create RAM / peripheral / EEPROM / option-byte / core memory blocks
#  - label every peripheral register with its STM8S003 name
#  - label known RAM objects (UART frame buffer + counter)
#  - rename verified routines
#  - add comments explaining register bit settings and key constants
# Re-runnable: labels/blocks that already exist are skipped.
# @category STM8
from ghidra.program.model.symbol import SourceType

mem = currentProgram.getMemory()


def block(name, addr, size):
    a = toAddr(addr)
    if mem.getBlock(a) is not None:
        return
    try:
        mem.createUninitializedBlock(name, a, size, False)
    except Exception as e:
        print "block %s failed: %s" % (name, e)


def label(addr, name):
    try:
        a = toAddr(addr)
        s = getSymbolAt(a)
        if s is not None and s.getName() == name:
            return
        createLabel(a, name, True)
    except Exception as e:
        pass


def eol(addr, text):
    try:
        setEOLComment(toAddr(addr), text)
    except:
        pass


def plate(addr, text):
    try:
        setPlateComment(toAddr(addr), text)
    except:
        pass


def rename(addr, name):
    try:
        f = getFunctionAt(toAddr(addr))
        if f is not None:
            f.setName(name, SourceType.USER_DEFINED)
            return True
    except:
        pass
    return False


# ---------------------------------------------------------------- memory blocks
block("RAM",        0x0000, 0x0400)
block("EEPROM",     0x4000, 0x0080)
block("OPT_BYTES",  0x4800, 0x0080)
block("PERIPH",     0x5000, 0x0800)
block("CORE_DEBUG", 0x7F00, 0x0100)

# ------------------------------------------------------------- peripheral names
regs = {}

# UART1
for i, n in enumerate(["UART1_SR", "UART1_DR", "UART1_BRR1", "UART1_BRR2",
                       "UART1_CR1", "UART1_CR2", "UART1_CR3", "UART1_CR4",
                       "UART1_CR5", "UART1_GTR", "UART1_PSCR"]):
    regs[0x5230 + i] = n

# CLK
for i, n in enumerate(["CLK_ICKR", "CLK_ECKR", "CLK_CMSR", "CLK_SWR", "CLK_SWCR",
                       "CLK_CKDIVR", "CLK_PCKENR1", "CLK_CSSR", "CLK_CCOR",
                       "CLK_PCKENR2", "CLK_HSITRIMR", "CLK_SWIMCCR", "CLK_?"]):
    regs[0x50C0 + i] = n

# GPIO ports
portbits = ["ODR", "IDR", "DDR", "CR1", "CR2"]
for pi, port in enumerate(["PA", "PB", "PC", "PD"]):
    for bi, b in enumerate(portbits):
        regs[0x5000 + pi * 5 + bi] = "%s_%s" % (port, b)

# TIM4 (8-bit basic timer)
for i, n in enumerate(["TIM4_CR1", "TIM4_CR2", "TIM4_SMCR", "TIM4_ETR", "TIM4_IER",
                       "TIM4_SR1", "TIM4_SR2", "TIM4_EGR", "TIM4_CNTR", "TIM4_PSCR",
                       "TIM4_ARR"]):
    regs[0x5340 + i] = n

# TIM2 (16-bit general purpose timer)
for i, n in enumerate(["TIM2_CR1", "TIM2_CR2", "TIM2_SMCR", "TIM2_IER", "TIM2_SR1",
                       "TIM2_SR2", "TIM2_EGR", "TIM2_CCMR1", "TIM2_CCMR2",
                       "TIM2_CCER1", "TIM2_CNTRH", "TIM2_CNTRL", "TIM2_PSCR",
                       "TIM2_ARRH", "TIM2_ARRL", "TIM2_CCR1H", "TIM2_CCR1L",
                       "TIM2_CCR2H", "TIM2_CCR2L"]):
    regs[0x5300 + i] = n

# TIM1 (advanced)
t1 = ["CR1", "CR2", "SMCR", "ETR", "IER", "SR1", "SR2", "EGR", "CCMR1", "CCMR2",
      "CCER1", "CCER2", "CNTRH", "CNTRL", "PSCRH", "PSCRL", "ARRH", "ARRL",
      "RCR", "CCR1H", "CCR1L", "CCR2H", "CCR2L", "CCR3H", "CCR3L", "BKR",
      "DMAR", "DTR", "OISR"]
for i, n in enumerate(t1):
    regs[0x5250 + i] = "TIM1_" + n

# I2C
for i, n in enumerate(["I2C_CR1", "I2C_CR2", "I2C_FREQR", "I2C_OARL", "I2C_OARH",
                       "I2C_DR", "I2C_SR1", "I2C_SR2", "I2C_CCRL", "I2C_CCRH",
                       "I2C_TRISER", "I2C_ITR"]):
    regs[0x5210 + i] = n

# ADC1
for i, n in enumerate(["ADC1_CSR", "ADC1_CR1", "ADC1_CR2", "ADC1_CR3",
                       "ADC1_DRH", "ADC1_DRL"]):
    regs[0x5400 + i] = n

# Flash / option-byte interface
regs.update({0x5050: "FLASH_CR1", 0x5051: "FLASH_CR2", 0x5052: "FLASH_NCR2",
             0x5053: "FLASH_FPR", 0x5054: "FLASH_NFPR", 0x5055: "FLASH_IAPSR",
             0x5056: "FLASH_PUKR", 0x5059: "FLASH_DUKR",
             0x5062: "FLASH_KEYREG_A", 0x5064: "FLASH_KEYREG_B"})

# Interrupt controller
for i in range(8):
    regs[0x50A0 + i] = "ITC_SPR%d" % (i + 1)

# IWDG / WWDG / AWU / RST
regs.update({0x50E0: "IWDG_KR", 0x50E1: "IWDG_PR", 0x50E2: "IWDG_RLR",
             0x50D1: "WWDG_CR", 0x50D2: "WWDG_WR", 0x50D3: "WWDG_WR2",
             0x5430: "AWU_CSR", 0x5431: "AWU_APR", 0x5432: "AWU_TBR",
             0x50B3: "RST_SR", 0x7F00: "CFG_GCR"})

for a, n in regs.items():
    label(a, n)

# ------------------------------------------------------------------ RAM objects
# Frame buffer: 32 data bytes at 0x023E, length counter at 0x025E
label(0x023E, "rx_frame_data")
for i in range(1, 32):
    label(0x023E + i, "rx_frame_data_%02d" % i)
label(0x025E, "rx_frame_len")
plate(0x023E, "UART1 receive frame buffer.\n"
              "Layout (inferred from the RX handler that stores bytes at (0x023E + index)):\n"
              "  0x023E..0x025D  u8 data[32]\n"
              "  0x025E          u8 len      (saturates/marks overflow at 32)\n"
              "Frame size limit is 32 bytes.")

label(0x02D0, "uart_state_a")
label(0x02D2, "uart_flag_b")
label(0x02D3, "uart_flag_c")
label(0x02D8, "pin_state_d3")
label(0x0303, "pin_state_d4")

# ------------------------------------------------------------------- routines
verified = [
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
]
named = 0
for a, n in verified:
    if rename(a, n):
        named += 1

# ------------------------------------------------------------------- comments
# UART1 configuration sequence (addresses from the listing)
eol(0x8FB9, "CR1: clear WAKE (bit4)")
eol(0x8FC0, "CR1 |= saved mask (data format bits)")
eol(0x8FC8, "CR3: clear STOP[5:4] -> 1 stop bit")
eol(0x8FD0, "CR3 |= 0x04 (bit2)")
eol(0x8FD8, "CR1: clear bits 2:1")
eol(0x8FE0, "CR1 |= 0x05 (bits 2,0)")
eol(0x8FE8, "BRR1 = 0 (divisor written later)")
eol(0x8FEF, "BRR2 low nibble cleared")
eol(0x8FF7, "BRR2 high nibble cleared")
eol(0x9041, "BRR2 |= divisor bits 3:0")
eol(0x904B, "compute fractional part")
eol(0x904F, "BRR2 |= fraction nibble")
eol(0x905A, "BRR1 |= divisor[11:4]")
eol(0x9063, "CR2: clear bits 3:2")
eol(0x906B, "CR3: clear bits 2:0")

plate(0x8FA9, "UART1 configuration routine.\n"
              "Order of operations observed:\n"
              "  1. CR1: 8-bit word, WAKE cleared, mask OR'ed from RAM 0x0006\n"
              "  2. CR3: STOP=00 (1 stop bit), bit2 set\n"
              "  3. CR1/CR2/CR3/CR4: enable + interrupt bits from the mask\n"
              "  4. BRR1/BRR2 programmed from a computed 16-bit divisor\n"
              "NOTE: no direct CALL to this routine exists in the image; it is reached\n"
              "by fall-through or through an indirect function pointer, so the baud\n"
              "divisor constant is not yet recovered statically.")

plate(0x9EC1, "Write TIM2 capture/compare register 1 (low byte) = PWM duty helper.")
plate(0x9ECB, "Write TIM2 auto-reload high byte (PWM period helper).")
plate(0x9F36, "IWDG reload/refresh (writes IWDG_KR).")
plate(0x9F3D, "IWDG start: IWDG_KR = 0xCC.")
plate(0x9C76, "FLASH key write 0xAE to FLASH_KEYREG_A (0x5062) - STM8 mass-key idiom.")
plate(0x9C82, "FLASH key write 0x56 to FLASH_KEYREG_B (0x5064) - STM8 mass-key idiom.")
plate(0x9CD8, "Reset entry: SP = 0x03FF, then init calls and jump into main.")
plate(0x96CB, "Interrupt controller priority setup (ITC_SPR1/SPR2 at 0x50A0/0x50A1).")
plate(0x993C, "Clock tree configuration.\n"
              "Writes CLK_ECKR, CLK_SWR=0xE1, CLK_SWCR, CLK_CKDIVR, CLK_PCKENR1=0x18,\n"
              "CLK_PCKENR2=0xFF, CLK_CSSR, CLK_HSITRIMR.\n"
              "PCKENR1=0x18 gates bits 3|4 (TIM4 | UART1) - consistent with the\n"
              "peripherals this firmware actually uses.")

# Vector table description
plate(0x8000, "STM8S003 interrupt vector area, 32 x 4-byte entries (0x8000-0x807F).\n"
              "Each entry: 82 00 <handler_hi> <handler_lo>.\n"
              "Parsed handlers: 00=0x9C82 05=0x99E1 15=0x9223 19=0x96CB 20=0x97D3 25=0x9608\n"
              "OPEN QUESTION: the reset entry parses to 0x9C82, but the real startup\n"
              "code (SP init) is at 0x9CD8, which does not appear anywhere in this area.\n"
              "Treat the vector parse as unconfirmed until verified on hardware.")

vnames = ["VEC00_RESET", "VEC01_TRAP", "VEC02_TLI", "VEC03_AWU", "VEC04_CLK",
          "VEC05_EXTI0", "VEC06_EXTI1", "VEC07_EXTI2", "VEC08_EXTI3", "VEC09_EXTI4",
          "VEC10_SPI", "VEC11_TIM1_OVF", "VEC12_TIM1_CC", "VEC13_TIM2_OVF",
          "VEC14_TIM2_CC", "VEC15_TIM1_BRK", "VEC16_TIM1_TRIG", "VEC17_UART1_TX",
          "VEC18_UART1_RX", "VEC19_I2C", "VEC20_ADC1", "VEC21_TIM4", "VEC22_FLASH",
          "VEC23", "VEC24", "VEC25", "VEC26", "VEC27", "VEC28", "VEC29",
          "VEC30", "VEC31"]
for i, n in enumerate(vnames):
    label(0x8000 + i * 4, n)

print "annotate: blocks+labels+names done (renamed %d functions)" % named
