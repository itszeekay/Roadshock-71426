/*
 * Roadshock 8-gang panel - custom base-board firmware
 * Target: STM8S003F3P6 (8 KB flash, 1 KB RAM), TSSOP-20
 *
 * Behavior implemented:
 *   - 2400 8N1 UART panel link (PD5 TX / PD6 RX)
 *   - frame: seq dir type flag p0..p5 sum   (sum = 8-bit sum of preceding bytes)
 *   - accepts panel type 0x08 flag 0x0C: button bitmask
 *   - accepts panel type 0x07 flag 0x00/0x01: master off/on
 *   - echoes every accepted frame back with dir 0xFF and type|0x10
 *   - per-channel modes: toggle, momentary, pulse, blinking
 *   - ACC/ignition sense on PA1 (active high)
 *   - independent watchdog refresh (the IWDG is not started by this build)
 *
 * The channel -> MCU pin map is isolated in board.h. It matches the stock
 * table recovered from the dump.
 */
#include <stdint.h>
#include <string.h>

#include "board.h"
#include "protocol.h"

#ifdef TEST_PATTERN
extern void test_pattern_run(void);
#endif

/* ------------------------------------------------------------------ types */
typedef enum {
    MODE_TOGGLE = 0,
    MODE_MOMENTARY,
    MODE_PULSE,
    MODE_BLINK
} mode_t;

typedef struct {
    uint8_t  on;          /* steady state                                */
    uint8_t  held;        /* button currently down                       */
    uint8_t  mode;        /* mode_t                                      */
    uint8_t  phase;       /* blink/pulse phase counter                   */
    uint16_t timer;       /* countdown in ticks                          */
} channel_t;

static channel_t ch[8];
static uint8_t master_on;

/* --------------------------------------------------------------- helpers */
static inline uint16_t ticks_from_ms(uint16_t ms)
{
    /* one TIM4 tick is ~2 ms (see board_timer_init) */
    return (uint16_t)(ms / 2u);
}

static void channel_set(uint8_t n, uint8_t on)
{
    if (n >= 8) {
        return;
    }
    ch[n].on = on;
    board_output(n, on ? 1 : 0);
}

/* 100 ms blink, 250 ms pulse */
#define BLINK_HALF_TICKS ticks_from_ms(100)
#define PULSE_TICKS      ticks_from_ms(250)

static void channel_press(uint8_t n)
{
    if (n >= 8) {
        return;
    }
    ch[n].held = 1;
    switch (ch[n].mode) {
    case MODE_TOGGLE:
        channel_set(n, !ch[n].on);
        break;
    case MODE_MOMENTARY:
        channel_set(n, 1);
        break;
    case MODE_PULSE:
        channel_set(n, 1);
        ch[n].timer = PULSE_TICKS;
        break;
    case MODE_BLINK:
        ch[n].phase = 1;
        ch[n].timer = BLINK_HALF_TICKS;
        break;
    default:
        break;
    }
}

static void channel_release(uint8_t n)
{
    if (n >= 8) {
        return;
    }
    ch[n].held = 0;
    if (ch[n].mode == MODE_MOMENTARY) {
        channel_set(n, 0);
    }
}

/* called every 5 ms */
static void channel_tick(void)
{
    for (uint8_t n = 0; n < 8; n++) {
        channel_t *c = &ch[n];
        if ((c->mode != MODE_PULSE && c->mode != MODE_BLINK) || c->timer == 0) {
            continue;
        }
        if (--c->timer) {
            continue;
        }
        if (c->mode == MODE_PULSE) {
            channel_set(n, 0);                 /* pulse finished            */
        } else {
            c->phase ^= 1u;                     /* blink toggles             */
            channel_set(n, c->phase);
            c->timer = BLINK_HALF_TICKS;
        }
    }
}

/* ------------------------------------------------------------ protocol */
static void apply_key_payload(const uint8_t *p)
{
    for (uint8_t n = 0; n < 8; n++) {
        uint8_t bit = (n & 1u) ? 0x01u : 0x10u;
        uint8_t down = (p[n >> 1] & bit) != 0;
        if (down && !ch[n].held) {
            channel_press(n);
        } else if (!down && ch[n].held) {
            channel_release(n);
        }
    }
}

static void set_master(uint8_t on)
{
    master_on = on;
    for (uint8_t n = 0; n < 8; n++) {
        if (!on) {
            channel_set(n, 0);
        }
    }
}

static void handle_frame(const proto_frame_t *f)
{
    if (!f->sum_ok || f->direction != PROTO_DIR_PANEL) {
        return;
    }
    if (!master_on && f->type != PROTO_TYPE_POWER) {
        return;                       /* nothing but power while master off  */
    }

    switch (f->type) {
    case PROTO_TYPE_KEYS:
        if (f->flag == PROTO_FLAG_KEYS) {
            apply_key_payload(f->payload);
        }
        break;
    case PROTO_TYPE_POWER:
        set_master(f->flag != 0);
        break;
    case PROTO_TYPE_CONFIG: {
        /* payload: [channel, mode, duty, freq_lo, freq_hi, 0]
         * mode: 0 = off, 1 = steady on, 2 = PWM */
        uint8_t chan = f->payload[0];
        uint8_t mode = f->payload[1];
        uint8_t duty = f->payload[2];
        uint16_t hz  = (uint16_t)f->payload[3] | ((uint16_t)f->payload[4] << 8);

        if (chan >= 1 && chan <= 8 && mode <= 2) {
            if (mode == 2 && !pwm_channel_ok(chan)) {
                out_set_mode(chan, 0);              /* no timer channel */
                ch[chan - 1].on = 0;
            } else {
                if (mode == 2) {
                    pwm_set_frequency(hz);
                }
                out_set_mode(chan, mode);
                if (mode == 2) {
                    pwm_set_duty(chan, duty);
                }
                ch[chan - 1].on = (mode != 0);
            }
        }
        break;
    }
    default:
        break;                        /* unknown types are ignored           */
    }

    /* always acknowledge like the stock firmware does */
    proto_send_reply(f);
}

/* ---------------------------------------------------------------- main */
void main(void)
{
    board_init();          /* clock, GPIO, watchdog                     */
    board_timer_init();    /* TIM4 tick                                 */
#ifdef TEST_PATTERN
    test_pattern_run();    /* never returns                             */
#endif
    proto_init();          /* UART1 2400 8N1, polled                    */

    memset(ch, 0, sizeof(ch));
    master_on = 1;

    /* default modes: all toggle, matching the panel's default */
    for (uint8_t n = 0; n < 8; n++) {
        ch[n].mode = MODE_TOGGLE;
        channel_set(n, 0);
    }

    for (;;) {
        board_watchdog_feed();

        proto_frame_t f;
        while (proto_poll(&f)) {
            handle_frame(&f);
        }

        /* 5 ms scheduler derived from the timer flag */
        if (board_tick_flag()) {
            board_tick_clear();
            channel_tick();

            /* ACC/ignition sense: if the vehicle is off, drop all outputs */
            if (!board_acc_sense()) {
                for (uint8_t n = 0; n < 8; n++) {
                    channel_set(n, 0);
                }
            }
        }
    }
}
