/*
 * board.c - clock, GPIO, timer and watchdog for the Roadshock base board.
 */
#include "board.h"

/* Channel -> port/mask.

   Verified by wire-probe (multimeter continuity + scope):
   - Channel 1  = PA3  (confirmed with scope on TIM1_CH3; package pins in docs/pinouts.md)
   - Channel 2  = PA2  (inferred by elimination; not yet wire-verified)
   - Channels 3 = PC7  (verified)
   - Channels 4 = PC6  (verified)
   - Channels 5 = PC5  (verified)
   - Channels 6 = PC4  (verified; also TIM1_CH4 for hardware PWM)
   - Channels 7 = PC3  (verified)
   - Channel 8  = PD2  (verified)

   Before driving real loads, verify each channel with a multimeter or scope. */

const uint8_t board_pin_count = 8;
const uint8_t board_pin_port[8] = {
    PIN_PA, PIN_PA,                              /* ch1 PA3, ch2 PA2        */
    PIN_PC, PIN_PC, PIN_PC, PIN_PC, PIN_PC,      /* ch3..ch7 PC7..PC3       */
    PIN_PD                                       /* ch8 PD2                 */
};
static const uint8_t board_pin_mask[8] = {
    0x08, 0x04,                                  /* PA3, PA2                */
    0x80, 0x40, 0x20, 0x10, 0x08,                /* PC7, PC6, PC5, PC4, PC3 */
    0x04                                         /* PD2                     */
};

/* TIM4 tick is polled from the main loop; ~2 ms period. */

void board_init(void)
{
    /* HSI is already the reset clock source; only disable the CPU divider.
     * No clock switch is performed, so there is nothing to wait for. */
    CLK_ICKR   = 0x01;        /* HSI on (already running)          */
    CLK_ECKR   = 0x00;
    CLK_CKDIVR = 0x00;        /* HSIDIV=1, CPUDIV=1 -> 16 MHz CPU  */
    CLK_PCKENR1 = 0xFF;       /* all peripheral clocks on          */
    CLK_PCKENR2 = 0xFF;

    /* Enable AFR0 (TIM2_CH1 -> PC5) for channel 5 hardware PWM.
     * Option byte 0x4803, bit 0. Write once; persists across flashes.
     * Safe to write on every boot - idempotent. */
    optbyte_set_afr(AFR0_BIT);

    /* PA1 = ACC sense input, pull-up, no interrupt */
    PA_DDR &= (uint8_t)~0x02;
    PA_CR1 |= 0x02;

    /* outputs: configure every channel pin as push-pull output, start low */
    for (uint8_t n = 0; n < 8; n++) {
        uint8_t m = board_pin_mask[n];
        switch (board_pin_port[n]) {
        case PIN_PA:
            PA_ODR &= (uint8_t)~m; PA_DDR |= m; PA_CR1 |= m; break;
        case PIN_PB:
            PB_ODR &= (uint8_t)~m; PB_DDR |= m; PB_CR1 |= m; break;
        case PIN_PC:
            PC_ODR &= (uint8_t)~m; PC_DDR |= m; PC_CR1 |= m; break;
        default:
            PD_ODR &= (uint8_t)~m; PD_DDR |= m; PD_CR1 |= m; break;
        }
    }

    /* UART1 pins PD5 (TX, alternate push-pull) and PD6 (RX, pull-up input) */
    PD_DDR |= 0x20;
    PD_CR1 |= 0x20;
    PD_DDR &= (uint8_t)~0x40;
    PD_CR1 |= 0x40;

    /* keep the watchdog off until the main loop feeds it */
    IWDG_KR = 0xAA;   /* refresh before start */
}

void board_timer_init(void)
{
    /* TIM4 tick: prescaler 128 (0x07) -> 125 kHz, ARR 250 -> ~2 ms.
     * Polling UIF from the main loop (no interrupt), 2 ms per tick.
     * ticks_from_ms() in main.c converts ms to 2 ms ticks. */
    TIM4_PSCR = 0x07;         /* /128 */
    TIM4_ARR  = 250;
    TIM4_CNTR = 250;
    TIM4_EGR  = 0x01;         /* UG: load prescaler */
    TIM4_SR1  = 0x00;
    TIM4_IER  = 0x00;         /* no interrupt: UIF polled */
    TIM4_CR1  = 0x01;         /* CEN */
}

uint8_t board_tick_flag(void)
{
    return (TIM4_SR1 & 0x01) != 0;     /* UIF */
}

void board_tick_clear(void)
{
    TIM4_SR1 = 0x00;
}

void board_output(uint8_t channel, uint8_t on)
{
    if (channel >= 8) {
        return;
    }
    uint8_t m = board_pin_mask[channel];
    if (on) {
        switch (board_pin_port[channel]) {
        case PIN_PA: PA_ODR |= m; break;
        case PIN_PB: PB_ODR |= m; break;
        case PIN_PC: PC_ODR |= m; break;
        default:     PD_ODR |= m; break;
        }
    } else {
        switch (board_pin_port[channel]) {
        case PIN_PA: PA_ODR &= (uint8_t)~m; break;
        case PIN_PB: PB_ODR &= (uint8_t)~m; break;
        case PIN_PC: PC_ODR &= (uint8_t)~m; break;
        default:     PD_ODR &= (uint8_t)~m; break;
        }
    }
}

uint8_t board_acc_sense(void)
{
    return (PA_IDR & 0x02) != 0;
}

void board_watchdog_feed(void)
{
    IWDG_KR = 0xAA;
}

/* ----------------------------------------------------------- EEPROM
 * The STM8S003F3P6 has 128 bytes of EEPROM at 0x4000-0x407F.
 * The EEPROM is byte-addressable; each write takes ~10 ms.
 * EEPROM write sequence (from stock firmware):
 *   1. Write address to 0x5045 (EEPROM address register) and 0x5044 (page register)
 *   2. Write data to 0x5040 (EEPROM data register) with FLASH_CR2 E1EE enabled
 *   3. Wait for FLASH_IAPSR (0x505A) EEPROM write flag to clear
 */

void eeprom_write(uint16_t addr, uint8_t data)
{
    /* Set address: low byte to 0x5045, high byte to 0x5044 (page register) */
    REG8(0x5045) = (uint8_t)(addr & 0xFF);
    REG8(0x5044) = (uint8_t)((addr >> 8) & 0xFF);

    /* Write data to data register; enable EEPROM write via FLASH_CR2 */
    REG8(0x5040) = data;
    REG8(0x505F) |= 0x02;               /* set CR2.E1EE (EEPROM write enable) */

    /* Wait for write to complete (poll until FLASH_IAPSR.EEPROM_WR_FLAG clears) */
    uint8_t timeout = 255;
    while (timeout--) {
        if ((REG8(0x505A) & 0x80) == 0) break;  /* EEPROM write flag cleared */
    }
}

uint8_t eeprom_read(uint16_t addr)
{
    /* Set address */
    REG8(0x5045) = (uint8_t)(addr & 0xFF);
    REG8(0x5044) = (uint8_t)((addr >> 8) & 0xFF);

    /* Read data from data register */
    return REG8(0x5040);
}

/* ----------------------------------------------------------- hardware PWM
 * TIM1 (verified layout: four separate CCMR registers, one per channel)
 *   ch3 PC3 = CH3, ch4 PC6 = CH1, ch6 PC4 = CH4, ch7 PC7 = CH2
 *   per-channel: CCMRn bits 6:4 = OCxM (110 = PWM1), bit3 = OCxPE
 *   CCER1 bit0 = CC1E, bit4 = CC2E ; CCER2 bit0 = CC3E, bit4 = CC4E
 *   BKR bit7 = MOE (main output enable, required on an advanced timer)
 */
static uint8_t tim1_ch_of(uint8_t channel, uint8_t *idx)
{
    switch (channel) {
    case 4: *idx = 1; return 1;
    case 7: *idx = 2; return 1;
    case 3: *idx = 3; return 1;
    case 6: *idx = 4; return 1;
    default: return 0;
    }
}

uint8_t pwm_channel_ok(uint8_t channel)
{
    uint8_t idx;
    return tim1_ch_of(channel, &idx);
}

static volatile uint8_t *ccmr_for(uint8_t idx)
{
    return (volatile uint8_t *)(0x5258u + (idx - 1u));
}

static volatile uint8_t *ccr_for(uint8_t idx)
{
    return (volatile uint8_t *)(0x5265u + 2u * (idx - 1u));
}

static void ccxe(uint8_t idx, uint8_t on)
{
    if (idx == 1) {
        if (on) TIM1_CCER1 |= 0x01; else TIM1_CCER1 &= (uint8_t)~0x01;
    } else if (idx == 2) {
        if (on) TIM1_CCER1 |= 0x10; else TIM1_CCER1 &= (uint8_t)~0x10;
    } else if (idx == 3) {
        if (on) TIM1_CCER2 |= 0x01; else TIM1_CCER2 &= (uint8_t)~0x01;
    } else {
        if (on) TIM1_CCER2 |= 0x10; else TIM1_CCER2 &= (uint8_t)~0x10;
    }
}

void pwm_set_frequency(uint16_t hz)
{
    uint32_t pscr = 1;
    uint32_t div;
    uint16_t arr;

    if (hz < 50)   hz = 50;
    if (hz > 2000) hz = 2000;          /* gate-driver limit */

    /* Raise the prescaler until the ARR value fits in 16 bits. TIM1 has a
     * real 16-bit prescaler, so low frequencies stay exact. */
    while ((16000000UL / (pscr * hz)) > 65536UL && pscr < 65536UL) {
        pscr <<= 1;
    }
    div = 16000000UL / (pscr * (uint32_t)hz);
    if (div == 0) div = 1;
    arr = (uint16_t)(div - 1u);

    TIM1_PSCRH = (uint8_t)((pscr - 1u) >> 8);
    TIM1_PSCRL = (uint8_t)((pscr - 1u) & 0xFF);
    TIM1_ARRH  = (uint8_t)(arr >> 8);
    TIM1_ARRL  = (uint8_t)(arr & 0xFF);
    TIM1_EGR   = 0x01;
    TIM1_CNTRH = 0;
    TIM1_CNTRL = 0;
}

void pwm_set_duty(uint8_t channel, uint8_t percent)
{
    uint8_t idx;
    uint16_t arr;
    uint32_t duty;
    volatile uint8_t *ccr;

    if (!tim1_ch_of(channel, &idx)) {
        return;
    }
    if (percent > 100) percent = 100;
    /* Edge cases: 0% -> CCR=0 (output stays low, channel is still in
     * PWM mode); 100% -> CCR=ARR+1 (output stays high). Both are valid
     * PWM states; switching to GPIO off requires out_set_mode(channel, 0). */

    arr = ((uint16_t)TIM1_ARRH << 8) | TIM1_ARRL;
    duty = ((uint32_t)(arr + 1u) * percent) / 100u;

    ccr = ccr_for(idx);
    ccr[0] = (uint8_t)(duty >> 8);
    ccr[1] = (uint8_t)(duty & 0xFF);
}

void out_set_mode(uint8_t channel, uint8_t mode)
{
    uint8_t idx;

    if (channel < 1 || channel > 8) {
        return;
    }
    if (!tim1_ch_of(channel, &idx)) {
        board_output((uint8_t)(channel - 1), mode != 0);
        return;
    }

    ccxe(idx, 0);                      /* pin back to GPIO control */

    if (mode == 2) {
        volatile uint8_t *cm = ccmr_for(idx);
        *cm = (uint8_t)((*cm & 0x8F) | 0x60 | 0x08);   /* PWM1 + preload */
        ccxe(idx, 1);
        TIM1_BKR |= 0x80;              /* MOE */
        TIM1_CR1 |= 0x01;              /* CEN */
    } else {
        board_output((uint8_t)(channel - 1), mode != 0);
    }
}

/* ----------------------------------------------------------- TIM2 PWM (channel 1 = PA3/TIM2_CH3, channel 5 = PC5/TIM2_CH1 with AFR0) */
static uint8_t tim2_ch_of(uint8_t channel, uint8_t *idx)
{
    /* Channel 1: PA3 = TIM2_CH3 (default)
     * Channel 5: PC5 = TIM2_CH1 (requires AFR0 bit in option byte 0x4803) */
    if (channel == 1) {
        *idx = 3;  /* TIM2_CH3 -> CCR3 */
        return 1;
    }
    if (channel == 5) {
        *idx = 1;  /* TIM2_CH1 -> CCR1 */
        return 1;
    }
    return 0;
}

uint8_t pwm2_channel_ok(uint8_t channel)
{
    uint8_t idx;
    return tim2_ch_of(channel, &idx);
}

void pwm2_set_frequency(uint16_t hz)
{
    uint32_t pscr = 1;
    uint32_t div;
    uint16_t arr;

    if (hz < 1)    hz = 1;
    if (hz > 20000) hz = 20000;  /* TIM2 16-bit, can go higher */

    /* Raise prescaler until ARR fits in 16 bits */
    while ((16000000UL / (pscr * hz)) > 65536UL && pscr < 65536UL) {
        pscr <<= 1;
    }
    div = 16000000UL / (pscr * (uint32_t)hz);
    if (div == 0) div = 1;
    arr = (uint16_t)(div - 1u);

    TIM2_PSCR  = (uint8_t)(pscr - 1u);    /* 8-bit prescaler */
    TIM2_ARRH  = (uint8_t)(arr >> 8);
    TIM2_ARRL  = (uint8_t)(arr & 0xFF);
    TIM2_EGR   = 0x01;                    /* UG: update generation */
    TIM2_CNTRH = 0;
    TIM2_CNTRL = 0;
}

void pwm2_set_duty(uint8_t channel, uint8_t percent)
{
    uint8_t idx;
    uint16_t arr;
    uint32_t duty;

    if (!tim2_ch_of(channel, &idx)) {
        return;
    }
    if (percent > 100) percent = 100;

    arr = ((uint16_t)TIM2_ARRH << 8) | TIM2_ARRL;
    duty = ((uint32_t)(arr + 1u) * percent) / 100u;

    if (idx == 3) {  /* TIM2_CH3 -> CCR3 (channel 1) */
        TIM2_CCR3H = (uint8_t)(duty >> 8);
        TIM2_CCR3L = (uint8_t)(duty & 0xFF);
        TIM2_CCMR3 = 0x68;                /* PWM1 mode + preload */
        TIM2_CCER1 |= 0x10;               /* CC3E enable */
    } else if (idx == 1) {  /* TIM2_CH1 -> CCR1 (channel 5 with AFR0) */
        TIM2_CCR1H = (uint8_t)(duty >> 8);
        TIM2_CCR1L = (uint8_t)(duty & 0xFF);
        TIM2_CCMR1 = 0x68;                /* PWM1 mode + preload */
        TIM2_CCER1 |= 0x01;               /* CC1E enable */
    }
    TIM2_CR1 |= 0x01;  /* CEN */
}

/* ----------------------------------------------------------- Option bytes (AFR remap) */
/* Option bytes at 0x4800-0x480F. AFR byte at 0x4803.
 * Write sequence: unlock -> write -> lock. Requires power cycle to take effect. */
static void opt_unlock(void)
{
    REG8(0x505A) = 0x56;   /* FLASH_DUKR key 1 */
    REG8(0x505A) = 0xAE;   /* FLASH_DUKR key 2 */
}

static void opt_lock(void)
{
    REG8(0x505A) &= (uint8_t)~0x01;  /* clear DUL bit */
}

uint8_t optbyte_read(uint16_t addr)
{
    return REG8(addr);
}

void optbyte_write(uint16_t addr, uint8_t data)
{
    opt_unlock();
    REG8(addr) = data;
    /* wait for write */
    uint8_t timeout = 255;
    while (timeout-- && (REG8(0x505A) & 0x04) == 0) { }
    opt_lock();
}

void optbyte_set_afr(uint8_t afr_bits)
{
    /* AFR byte at 0x4803: bit0 = AFR0 (TIM2_CH1 -> PC5), bit1 = AFR1 (TIM2_CH3 -> PD2) */
    optbyte_write(0x4803, afr_bits);
}
