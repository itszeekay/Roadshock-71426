# Dump the annotated listing to text with human-readable register/object names.
# Usage: -postScript dump_asm.py <outputPath>
# @category STM8
from java.io import PrintWriter
import re

NAMES = {}
for i, n in enumerate(["UART1_SR", "UART1_DR", "UART1_BRR1", "UART1_BRR2",
                       "UART1_CR1", "UART1_CR2", "UART1_CR3", "UART1_CR4",
                       "UART1_CR5", "UART1_GTR", "UART1_PSCR"]):
    NAMES[0x5230 + i] = n
for i, n in enumerate(["CLK_ICKR", "CLK_ECKR", "CLK_RSVD2", "CLK_CMSR", "CLK_SWR",
                       "CLK_SWCR", "CLK_CKDIVR", "CLK_PCKENR1", "CLK_CSSR",
                       "CLK_CCOR", "CLK_PCKENR2", "CLK_HSITRIMR"]):
    NAMES[0x50C0 + i] = n
pb = ["ODR", "IDR", "DDR", "CR1", "CR2"]
for pi, port in enumerate(["PA", "PB", "PC", "PD"]):
    for bi, b in enumerate(pb):
        NAMES[0x5000 + pi * 5 + bi] = "%s_%s" % (port, b)
for i, n in enumerate(["TIM4_CR1", "TIM4_CR2", "TIM4_SMCR", "TIM4_ETR", "TIM4_IER",
                       "TIM4_SR1", "TIM4_SR2", "TIM4_EGR", "TIM4_CNTR", "TIM4_PSCR",
                       "TIM4_ARR"]):
    NAMES[0x5340 + i] = n
for i, n in enumerate(["TIM2_CR1", "TIM2_CR2", "TIM2_SMCR", "TIM2_IER", "TIM2_SR1",
                       "TIM2_SR2", "TIM2_EGR", "TIM2_CCMR1", "TIM2_CCMR2",
                       "TIM2_CCR2", "TIM2_PSCR",
                       "TIM2_ARRH", "TIM2_ARRL", "TIM2_CCR1H", "TIM2_CCR1L",
                       "TIM2_CCR2B", "TIM2_CCR2C"]):
    pass
NAMES.update({0x5300: "TIM2_CR1", 0x5307: "TIM2_CCMR1", 0x5308: "TIM2_CCMR2",
              0x530D: "TIM2_ARRH", 0x530E: "TIM2_ARRL",
              0x530F: "TIM2_CCR1H", 0x5310: "TIM2_CCR1L",
              0x5311: "TIM2_CCR2H", 0x5312: "TIM2_CCR2L"})
for i, n in enumerate(["I2C_CR1", "I2C_CR2", "I2C_FREQR", "I2C_OARL", "I2C_OARH",
                       "I2C_DR", "I2C_CR1B", "I2C_SR1", "I2C_SR2", "I2C_CCRL",
                       "I2C_CCRH", "I2C_TRISER", "I2C_ITR"]):
    pass
NAMES.update({0x5210: "I2C_CR1", 0x5211: "I2C_CR2", 0x5212: "I2C_FREQR",
              0x5215: "I2C_DR", 0x5216: "I2C_SR1", 0x5217: "I2C_SR2",
              0x5218: "I2C_CCRL", 0x5219: "I2C_CCRH", 0x521B: "I2C_ITR"})
for i, n in enumerate(["ADC1_CSR", "ADC1_CR1", "ADC1_CR2", "ADC1_CR3",
                       "ADC1_DRH", "ADC1_DRL"]):
    NAMES[0x5400 + i] = n
NAMES.update({0x5050: "FLASH_CR1", 0x5051: "FLASH_CR2", 0x5052: "FLASH_NCR2",
              0x5055: "FLASH_IAPSR", 0x5056: "FLASH_PUKR", 0x5059: "FLASH_DUKR",
              0x5062: "FLASH_KEYREG_A", 0x5064: "FLASH_KEYREG_B",
              0x50E0: "IWDG_KR", 0x50E1: "IWDG_PR", 0x50E2: "IWDG_RLR",
              0x50A0: "ITC_SPR1", 0x50A1: "ITC_SPR2", 0x50A2: "ITC_SPR3",
              0x50A3: "ITC_SPR4", 0x7F00: "CFG_GCR",
              0x023E: "rx_frame_data", 0x025E: "rx_frame_len",
              0x02D0: "uart_state_a", 0x02D2: "uart_flag_b", 0x02D3: "uart_flag_c",
              0x02D8: "pin_state_d3", 0x0303: "pin_state_d4"})

args = getScriptArgs()
out = args[0] if len(args) > 0 else "analysis/asm_named.txt"
listing = currentProgram.getListing()
w = PrintWriter(out)

w.println("== STM8S003 base board firmware - annotated listing ==")
w.println("image base 0x8000, %d bytes, language %s" % (
    currentProgram.getMemory().getBlock(toAddr(0x8000)).getSize(),
    currentProgram.getLanguageID()))
w.println()
w.println("== FUNCTIONS ==")
fit = listing.getFunctions(True)
while fit.hasNext():
    f = fit.next()
    w.println("FUNC %04x %s" % (f.getEntryPoint().getOffset(), f.getName()))
w.println()
w.println("== LISTING ==")

n = 0
it = listing.getInstructions(True)
while it.hasNext():
    ins = it.next()
    bs = ins.getBytes()
    hexs = " ".join("%02x" % (b & 0xFF) for b in bs)
    text = ins.toString()
    for v in sorted(NAMES.keys(), reverse=True):
        text = text.replace("0x%04x" % v, NAMES[v]).replace("0x%04X" % v, NAMES[v])
    cmt = ins.getComment(0)
    line = "%04x: %-15s %-42s" % (ins.getAddress().getOffset(), hexs, text)
    if cmt:
        line += "   ; " + cmt
    w.println(line)
    n += 1
w.println()
w.println("TOTAL INSTRUCTIONS: %d" % n)
w.close()
print "dump_asm wrote %d instructions to %s" % (n, out)
