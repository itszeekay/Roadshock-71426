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
