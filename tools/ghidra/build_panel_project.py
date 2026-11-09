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
    (0x8D26, "uart1_configure"),
    (0x8510, "gpio_init"),
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
plate(0x8D26, "UART1 configure for display link (115200).")
plate(0x8510, "GPIO_Init helper (SPL-style). Mode 0xF0 = push-pull output.")

print "build_panel_project: %d functions named" % (named,)
