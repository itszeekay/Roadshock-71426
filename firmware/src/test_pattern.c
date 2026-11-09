/*
 * test_pattern.c - bench test for the Roadshock base board
 *
 * Repeating sequence:
 *   3 x blink on channel 6 (PC4, pin 14)
 *   PWM ramp 0 -> 100 % -> 0 % at ~1 kHz (software PWM on the same pin)
 *   3 x blink
 *   1 s pause
 *
 * Text status is written to UART1 (2400 8N1) so it can be monitored on the
 * panel-link tap. The panel protocol is not used in this mode.
 *
 * Timing is a calibrated busy loop - no timer dependency (the TIM4 poll path
 * was unreliable on this part during bench testing).
 */
#include "board.h"
#include "protocol.h"

extern void board_output(uint8_t channel, uint8_t on);

/* Measured on hardware: the previous constant produced 662 Hz instead of
 * 1 kHz for a 1000 us frame, i.e. the loop ran ~1.51x slower than assumed.
 * Compensate with 4/3 of a microsecond per iteration (was 2).            */
static void delay_us(uint16_t us)
{
    volatile uint16_t n = (uint16_t)((us * 4u) / 3u);
    while (n--) {
    }
}

static void delay_ms(uint16_t ms)
{
    while (ms--) {
        delay_us(1000);
    }
}

static void dbg_char(char c)
{
    while (!(UART1_SR & 0x80)) {
    }
    UART1_DR = (uint8_t)c;
}

static void dbg_str(const char *s)
{
    while (*s) {
        dbg_char(*s++);
    }
}

/* channel 6 -> pin 14 (PC4), index 5 in the board table */
#define CH 5

static void blink3(void)
{
    for (uint8_t i = 0; i < 3; i++) {
        board_output(CH, 1);
        dbg_str("BLINK ON\r\n");
        delay_ms(200);
        board_output(CH, 0);
        dbg_str("BLINK OFF\r\n");
        delay_ms(200);
    }
}

/* ---- software PWM -------------------------------------------------------- */
#define PWM_PERIOD_US 1000u

static void sw_pwm_period(uint8_t percent)
{
    uint16_t on = (uint16_t)percent * (PWM_PERIOD_US / 100u);
    if (on) {
        board_output(CH, 1);
        delay_us(on);
    }
    if (on < PWM_PERIOD_US) {
        board_output(CH, 0);
        delay_us((uint16_t)(PWM_PERIOD_US - on));
    }
}

static void sw_pwm_ramp(uint8_t from, uint8_t to, uint16_t ms)
{
    int8_t step = (to > from) ? 1 : -1;
    uint8_t pct = from;
    uint16_t frames = (uint16_t)(ms / 30u);

    for (;;) {
        for (uint16_t i = 0; i < frames; i++) {
            sw_pwm_period(pct);
        }
        if (pct == to) {
            break;
        }
        pct = (uint8_t)(pct + step);
    }
}

void test_pattern_run(void)
{
    proto_init();             /* UART1 2400 8N1, TX only here */

    dbg_str("\r\nROADSHOCK TEST PATTERN\r\n");

    for (;;) {
        blink3();

        dbg_str("PWM RAMP UP 0-100\r\n");
        sw_pwm_ramp(0, 100, 3000);

        dbg_str("PWM RAMP DOWN 100-0\r\n");
        sw_pwm_ramp(100, 0, 3000);

        blink3();

        dbg_str("PAUSE\r\n");
        delay_ms(1000);
    }
}
