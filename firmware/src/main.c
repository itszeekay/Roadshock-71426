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
    uint16_t held_ticks;  /* duration button held, 2 ms per tick         */
    uint8_t  long_fired;  /* long-press action already sent              */
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

/* Blink/pulse timing, calculated from the 2 ms TIM4 tick (see board_timer_init:
 * 16 MHz / 128 prescaler = 125 kHz, ARR 250 -> ~2.008 ms per tick).
 * - Blink half period 100 ms = 100/2 = 50 ticks. A full blink cycle is a
 *   100 ms ON phase plus a 100 ms OFF phase = 200 ms = 5 Hz.
 * - Pulse on-time 250 ms = 250/2 = 125 ticks = 250 ms.
 * These rates are assumed: the manual (docs/71426-manual.pdf) names the modes
 * and their indicator colors but does not state timing, and the stock timing
 * has not been measured yet. Treat both as placeholders pending a bench
 * capture against the stock firmware. */
#define BLINK_HALF_TICKS ticks_from_ms(100)
#define PULSE_TICKS      ticks_from_ms(250)
#define LONG_PRESS_TICKS ticks_from_ms(800)

static void channel_press(uint8_t n)
{
    if (n >= 8) {
        return;
    }
    ch[n].held = 1;
    ch[n].held_ticks = 0;
    ch[n].long_fired = 0;
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
    eeprom_save_state();
}

static void channel_release(uint8_t n)
{
    if (n >= 8) {
        return;
    }
    ch[n].held = 0;
    ch[n].held_ticks = 0;
    ch[n].long_fired = 0;
    if (ch[n].mode == MODE_MOMENTARY) {
        channel_set(n, 0);
    }
    eeprom_save_state();
}

static void set_master(uint8_t on);

/* called every 2 ms TIM4 tick; see board_timer_init */
static void channel_tick(void)
{
    for (uint8_t n = 0; n < 8; n++) {
        channel_t *c = &ch[n];

        /* long-press detection: count held duration on all modes */
        c->held_ticks = c->held ? (uint16_t)(c->held_ticks + 1) : 0;
        if (c->held && c->held_ticks >= LONG_PRESS_TICKS && !c->long_fired) {
            c->long_fired = 1;
            set_master(0);  /* long press = master off (valet mode) */
        }

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

/* Save channel state to EEPROM (addresses 0x0D..0x14 = 8 bytes) */
static void eeprom_save_state(void)
{
    uint8_t i;
    for (i = 0; i < 8; i++) {
        uint8_t byte = ch[i].mode;       /* bits 0-1 */
        byte |= (ch[i].on != 0) << 2;   /* bit 2 */
        eeprom_write(0x0D + i, byte);
    }
}

/* Load channel state from EEPROM (addresses 0x0D..0x14 = 8 bytes) */
static void eeprom_load_state(void)
{
    uint8_t i;
    for (i = 0; i < 8; i++) {
        uint8_t b = eeprom_read(0x0D + i);
        ch[i].mode = b & 0x03;
        ch[i].on   = (b >> 2) & 0x01;
        board_output(i, ch[i].on != 0);  /* apply loaded state to outputs */
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
    eeprom_save_state();
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

    /* custom status frame: report current output state */
    if (f->type == PROTO_TYPE_STATUS) {
        uint8_t status[6] = {0};
        for (uint8_t n = 0; n < 6; n++) {
            status[n] = ch[n].on != 0 ? 1 : 0;
        }
        status[6 - 1] = master_on ? 1 : 0;  /* last byte: master state */
        proto_send_status(f, status);
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

    /* Load channel state from EEPROM (addresses 0x0D..0x14) */
    eeprom_load_state();

    for (;;) {
        board_watchdog_feed();

        proto_frame_t f;
        while (proto_poll(&f)) {
            handle_frame(&f);
        }

        /* 2 ms scheduler from the TIM4 flag (board_timer_init) */
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
