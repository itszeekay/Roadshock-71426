# Attach equates to scalar operands so the listing shows register/object names
# instead of bare numbers (STM8 sleigh encodes peripheral addresses as scalars).
# @category STM8
from ghidra.program.model.scalar import Scalar

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
             0x5055: "FLASH_IAPSR", 0x5056: "FLASH_PUKR", 0x5059: "FLASH_DUKR",
             0x5062: "FLASH_KEYREG_A", 0x5064: "FLASH_KEYREG_B",
             0x50E0: "IWDG_KR", 0x50E1: "IWDG_PR", 0x50E2: "IWDG_RLR",
             0x50A0: "ITC_SPR1", 0x50A1: "ITC_SPR2", 0x50A2: "ITC_SPR3",
             0x50A3: "ITC_SPR4", 0x7F00: "CFG_GCR"})

# verified RAM objects
RAMS = {
    0x023E: "rx_frame_data",
    0x025E: "rx_frame_len",
    0x02D0: "uart_state_a",
    0x02D2: "uart_flag_b",
    0x02D3: "uart_flag_c",
    0x02D8: "pin_state_d3",
    0x0303: "pin_state_d4",
}

eqtab = currentProgram.getEquateTable()
cache = {}


def equate(name, value):
    key = (name, value)
    if key in cache:
        return cache[key]
    e = eqtab.getEquate(name)
    if e is None:
        try:
            e = eqtab.createEquate(name, value)
        except:
            e = None
    cache[key] = e
    return e


count = 0
listing = currentProgram.getListing()
it = listing.getInstructions(True)
while it.hasNext():
    ins = it.next()
    for oi in range(ins.getNumOperands()):
        for op in ins.getOpObjects(oi):
            if not isinstance(op, Scalar):
                continue
            v = op.getUnsignedValue()
            name = REGS.get(v) or RAMS.get(v)
            if name is None:
                continue
            e = equate(name, v)
            if e is None:
                continue
            try:
                ins.setOperandEquate(oi, e)
                count += 1
            except:
                pass

print "equates attached: %d" % count
