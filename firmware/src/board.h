/*
 * board.h - STM8S003F3P6 register map and board wiring for the Roadshock
 *           8-gang base board (custom firmware).
 *
 * PIN MAP: the eight gate drivers are spread over PA/PB/PC/PD. The exact
 * channel order was not recoverable from the stock image (see
 * docs/hardware_pinout.md). Fill the table below once the map is confirmed;
 * nothing else in the firmware needs to change.
 */
#ifndef BOARD_H
#define BOARD_H

#include <stdint.h>

/* ------------------------------------------------------------ registers */
#define REG8(a)      (*(volatile uint8_t *)(a))

#define CLK_ICKR     REG8(0x50C0)
#define CLK_ECKR     REG8(0x50C1)
#define CLK_CMSR     REG8(0x50C3)
#define CLK_SWR      REG8(0x50C4)
#define CLK_SWCR     REG8(0x50C5)
#define CLK_CKDIVR   REG8(0x50C6)
#define CLK_PCKENR1  REG8(0x50C7)
#define CLK_PCKENR2  REG8(0x50CA)

#define PA_ODR       REG8(0x5000)
#define PA_IDR       REG8(0x5001)
#define PA_DDR       REG8(0x5002)
#define PA_CR1       REG8(0x5003)

#define PB_ODR       REG8(0x5005)
#define PB_DDR       REG8(0x5007)
#define PB_CR1       REG8(0x5008)

#define PC_ODR       REG8(0x500A)
#define PC_DDR       REG8(0x500C)
#define PC_CR1       REG8(0x500D)

#define PD_ODR       REG8(0x500F)
#define PD_IDR       REG8(0x5010)
#define PD_DDR       REG8(0x5011)
#define PD_CR1       REG8(0x5012)

#define UART1_SR     REG8(0x5230)
#define UART1_DR     REG8(0x5231)
#define UART1_BRR1   REG8(0x5232)
#define UART1_BRR2   REG8(0x5233)
#define UART1_CR1    REG8(0x5234)
#define UART1_CR2    REG8(0x5235)
#define UART1_CR3    REG8(0x5236)
#define UART1_CR4    REG8(0x5237)

#define TIM1_CR1     REG8(0x5250)
#define TIM1_CR2     REG8(0x5251)
#define TIM1_SMCR    REG8(0x5252)
#define TIM1_ETR     REG8(0x5253)
#define TIM1_IER     REG8(0x5254)
#define TIM1_SR1     REG8(0x5255)
#define TIM1_SR2     REG8(0x5256)
#define TIM1_EGR     REG8(0x5257)
#define TIM1_CCMR1   REG8(0x5258)
#define TIM1_CCMR2   REG8(0x5259)
#define TIM1_CCMR3   REG8(0x525A)
#define TIM1_CCMR4   REG8(0x525B)
#define TIM1_CCER1   REG8(0x525C)
#define TIM1_CCER2   REG8(0x525D)
#define TIM1_CNTRH   REG8(0x525E)
#define TIM1_CNTRL   REG8(0x525F)
#define TIM1_PSCRH   REG8(0x5260)
#define TIM1_PSCRL   REG8(0x5261)
#define TIM1_ARRH    REG8(0x5262)
#define TIM1_ARRL    REG8(0x5263)
#define TIM1_CCR1H   REG8(0x5265)
#define TIM1_CCR1L   REG8(0x5266)
#define TIM1_CCR2H   REG8(0x5267)
#define TIM1_CCR2L   REG8(0x5268)
#define TIM1_CCR3H   REG8(0x5269)
#define TIM1_CCR3L   REG8(0x526A)
#define TIM1_CCR4H   REG8(0x526B)
#define TIM1_CCR4L   REG8(0x526C)
#define TIM1_BKR     REG8(0x526D)

#define TIM2_CR1     REG8(0x5300)
#define TIM2_IER     REG8(0x5303)
#define TIM2_SR1     REG8(0x5304)
#define TIM2_SR2     REG8(0x5305)
#define TIM2_EGR     REG8(0x5306)
#define TIM2_CCMR1   REG8(0x5307)
#define TIM2_CCMR2   REG8(0x5308)
#define TIM2_CCMR3   REG8(0x5309)
#define TIM2_CCER1   REG8(0x530A)
#define TIM2_CNTRH   REG8(0x530C)
#define TIM2_CNTRL   REG8(0x530D)
#define TIM2_PSCR    REG8(0x530E)
#define TIM2_ARRH    REG8(0x530F)
#define TIM2_ARRL    REG8(0x5310)
#define TIM2_CCR1H   REG8(0x5311)
#define TIM2_CCR1L   REG8(0x5312)
#define TIM2_CCR2H   REG8(0x5313)
#define TIM2_CCR2L   REG8(0x5314)
#define TIM2_CCR3H   REG8(0x5315)
#define TIM2_CCR3L   REG8(0x5316)

#define TIM4_CR1     REG8(0x5340)
#define TIM4_IER     REG8(0x5344)
#define TIM4_SR1     REG8(0x5345)
#define TIM4_EGR     REG8(0x5347)
#define TIM4_CNTR    REG8(0x5348)
#define TIM4_PSCR    REG8(0x5349)
#define TIM4_ARR     REG8(0x534A)

#define IWDG_KR      REG8(0x50E0)

#define ITC_SPR1     REG8(0x50A0)

/* --------------------------------------------------------- output table */
typedef struct {
    volatile uint8_t *odr;   /* port output register */
    uint8_t           mask;  /* pin bit              */
} pin_t;

/* Channel table is in board.c and matches the stock map recovered from the
 * dump. */
extern const uint8_t board_pin_count;
extern const uint8_t board_pin_port[8];   /* 0=PA 1=PB 2=PC 3=PD */
#define PIN_PA 0
#define PIN_PB 1
#define PIN_PC 2
#define PIN_PD 3

/* ------------------------------------------------------------- functions */
void board_init(void);
void board_timer_init(void);
void board_output(uint8_t channel, uint8_t on);

/* hardware PWM (TIM1 channels 1..4, TIM2 channels 1..3) */
void pwm_set_frequency(uint16_t hz);
void pwm_set_duty(uint8_t channel, uint8_t percent);   /* channel 1..8 */
void pwm2_set_frequency(uint16_t hz);
void pwm2_set_duty(uint8_t channel, uint8_t percent);  /* channel 1..8 (TIM2 only) */
void out_set_mode(uint8_t channel, uint8_t mode);      /* 0=off 1=on 2=pwm */
uint8_t pwm_channel_ok(uint8_t channel);
uint8_t pwm2_channel_ok(uint8_t channel);
uint8_t board_acc_sense(void);
void board_watchdog_feed(void);
uint8_t board_tick_flag(void);
void board_tick_clear(void);

/* EEPROM (128 bytes at 0x4000-0x407F) */
void eeprom_write(uint16_t addr, uint8_t data);
uint8_t eeprom_read(uint16_t addr);

/* Option bytes (0x4800-0x480F) - for AFR remap */
void optbyte_write(uint16_t addr, uint8_t data);
uint8_t optbyte_read(uint16_t addr);

/* AFR configuration (call once, then power cycle) */
#define AFR_ADDR  0x4803
#define AFR0_BIT  0x01  /* TIM2_CH1 -> PC5 (enable ch 5 PWM) */
#define AFR1_BIT  0x02  /* TIM2_CH3 -> PD2 (steals from ch 1) */

void optbyte_set_afr(uint8_t afr_bits);   /* writes AFR byte, requires reset */

/* Status frame: type 0x0A (custom) — declared in protocol.h */

#endif /* BOARD_H */
