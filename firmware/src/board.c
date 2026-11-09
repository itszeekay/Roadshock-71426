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
