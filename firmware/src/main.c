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
    MODE_BLINK,
    MODE_FLASH,      /* new: configurable flasher (on_time, off_time)     */
    MODE_PULSE_MS    /* new: pulse with ms duration (0x10)                 */
} mode_t;

typedef struct {
    uint8_t  on;          /* steady state                                */
    uint8_t  held;        /* button currently down                       */
    uint8_t  mode;        /* mode_t                                      */
    uint8_t  phase;       /* blink/flash phase counter                   */
    uint16_t timer;       /* countdown in ticks                          */
    uint16_t held_ticks;  /* duration button held, 2 ms per tick         */
    uint8_t  long_fired;  /* long-press action already sent              */
    uint32_t delayed_off_ticks;  /* countdown to auto-off after release    */
    uint32_t delay_ms;           /* configured run-on duration, ms (0=off) */
    uint32_t double_tap_ticks;   /* time of first press for double-tap     */
    uint8_t  flags;              /* bit0 delayed_off_en, bit1 double_tap_en */
    /* flasher config (MODE_FLASH) */
    uint16_t flash_on_ticks;     /* on phase in ticks                     */
    uint16_t flash_off_ticks;    /* off phase in ticks                    */
    uint8_t  flash_single;       /* bit: single flash (off after one cycle)*/
    /* pulse config (MODE_PULSE_MS) */
    uint16_t pulse_ticks;        /* pulse duration in ticks               */
    /* soft start (applied on top of any PWM) */
    uint16_t soft_start_ticks;   /* ramp time in ticks; 0 = no soft start */
    uint16_t soft_start_duty;    /* ramp from 0 to this duty (%)         */
    /* starter disable */
    uint8_t  start_disable;      /* this output is disabled while cranking  */
    /* input-driven mode (type 0x0F input bitmask) */
    uint8_t  input_drive;        /* 1 = output follows input bitmask bit   */
} channel_t;

/* channel_t layout note: the 0x0D..0x14 EEPROM region is one byte per channel:
 * bits 0-1 = mode, bit 2 = on, bit 3 = delayed_off_en, bit 4 = double_tap_en.
 * The per-channel run-on duration (ms) lives in a separate uint32_t delay_ms field
 * held in RAM; values are persisted via the config command (type 0x09) to bytes 0x15..0x1C. */

static channel_t ch[8];
static uint8_t master_on;
static uint16_t tick_counter;
static uint8_t input_mask;       /* from type 0x0F: middle ECU input bitmask   */
static uint8_t start_cranking;   /* 1 = engine cranking (type 0x12)           */

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
#define DOUBLE_TAP_WINDOW_TICKS 500            /* within this many ticks = double tap */

static void channel_press(uint8_t n)
{
    if (n >= 8) {
        return;
    }
    ch[n].held = 1;
    ch[n].held_ticks = 0;
    ch[n].long_fired = 0;
    /* start delayed-off countdown on every press (cancel run-on if active) */
    if (ch[n].delayed_off_ticks > 0) {
        ch[n].delayed_off_ticks = 0;
        channel_set(n, 0);
    }
    /* double-tap detection for momentary latch toggle */
    if ((ch[n].flags & 0x02) && ch[n].double_tap_ticks != 0 &&
        (tick_counter - ch[n].double_tap_ticks) < DOUBLE_TAP_WINDOW_TICKS) {
        /* second press within window: toggle latch */
        channel_set(n, !ch[n].on);
        ch[n].double_tap_ticks = 0;
        eeprom_save_state();
        return;
    }
    ch[n].double_tap_ticks = tick_counter;
    /* configure mode action below */
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
        if ((ch[n].flags & 0x01) && ch[n].on && ch[n].delay_ms != 0) {
            /* delayed_off_en set, output on, delay configured:
             * start the run-on countdown (2 ms per tick) */
            ch[n].delayed_off_ticks = ch[n].delay_ms / 2u;
        } else {
            channel_set(n, 0);
        }
    }
    eeprom_save_state();
}

static void set_master(uint8_t on);

/* Soft-start ramp helper: increments the PWM duty by 1% per call and
 * clamps to soft_start_duty. Returns 1 while ramping, 0 when done. */
static void soft_start_step(uint8_t n)
{
    channel_t *c = &ch[n];
    if (c->soft_start_ticks == 0) return;
    c->soft_start_ticks--;

    /* Add 1% of ARR to the CCR register, clamped to target duty. */
    uint16_t one_pct;
    uint16_t arr;
    uint16_t cur;
    uint16_t target;
    uint16_t new_val;

    target = (uint16_t)(100u * c->soft_start_duty / 256u);

    if (pwm2_channel_ok(n + 1)) {
        arr = ((uint16_t)TIM2_ARRH << 8) | TIM2_ARRL;
        one_pct = (arr + 1) / 100u;
        if (n == 0) {
            cur = ((uint16_t)TIM2_CCR3H << 8) | TIM2_CCR3L;
            new_val = cur + one_pct;
        } else {
            cur = ((uint16_t)TIM2_CCR1H << 8) | TIM2_CCR1L;
            new_val = cur + one_pct;
        }
        if (new_val > (uint16_t)((arr + 1) * target / 256u))
            new_val = (uint16_t)((arr + 1) * target / 256u);
        if (new_val > (uint16_t)(arr + 1)) new_val = (uint16_t)(arr + 1);
        if (n == 0) {
            TIM2_CCR3L = (uint8_t)(new_val & 0xFF);
            TIM2_CCR3H = (uint8_t)((new_val >> 8) & 0xFF);
        } else {
            TIM2_CCR1L = (uint8_t)(new_val & 0xFF);
            TIM2_CCR1H = (uint8_t)((new_val >> 8) & 0xFF);
        }
    } else if (pwm_channel_ok(n + 1)) {
        uint16_t ccr_lo;
        switch (n + 1) {
        case 3: ccr_lo = 0x5269; break;  /* CCR3 */
        case 4: ccr_lo = 0x5265; break;  /* CCR1 */
        case 6: ccr_lo = 0x526B; break;  /* CCR4 */
        case 7: ccr_lo = 0x5267; break;  /* CCR2 */
        default: return;
        }
        arr = ((uint16_t)TIM1_ARRH << 8) | TIM1_ARRL;
        one_pct = (arr + 1) / 100u;
        cur = (REG8(ccr_lo + 1) << 8) | REG8(ccr_lo);
        new_val = cur + one_pct;
        if (new_val > (uint16_t)((arr + 1) * target / 256u))
            new_val = (uint16_t)((arr + 1) * target / 256u);
        if (new_val > (uint16_t)(arr + 1)) new_val = (uint16_t)(arr + 1);
        REG8(ccr_lo)     = (uint8_t)((new_val >> 8) & 0xFF);
        REG8(ccr_lo + 1) = (uint8_t)(new_val & 0xFF);
    }
}

/* called every 2 ms TIM4 tick; see board_timer_init */
static void channel_tick(void)
{
    tick_counter++;

    for (uint8_t n = 0; n < 8; n++) {
        channel_t *c = &ch[n];

        /* long-press detection: count held duration on all modes */
        c->held_ticks = c->held ? (uint16_t)(c->held_ticks + 1) : 0;
        if (c->held && c->held_ticks >= LONG_PRESS_TICKS && !c->long_fired) {
            c->long_fired = 1;
            set_master(0);  /* long press = master off (valet mode) */
        }

        /* starter disable: force all disabled outputs off while cranking */
        if (start_cranking && c->start_disable) {
            channel_set(n, 0);
            c->on = 0;
            continue;
        }

        /* input-driven: output follows the input bitmask bit */
        if (c->input_drive) {
            uint8_t want = (input_mask & (1u << n)) != 0;
            if (want != c->on) {
                channel_set(n, want);
            }
            continue;
        }

        /* soft-start ramp: only when soft_start_ticks is active */
        if (c->soft_start_ticks > 0) {
            soft_start_step(n);
            continue;
        }

        /* delayed-off run-on countdown: auto-off when timer expires */
        if (c->delayed_off_ticks != 0) {
            if (--c->delayed_off_ticks == 0) {
                channel_set(n, 0);
            }
            continue;
        }

        switch (c->mode) {
        case MODE_PULSE:
            if (c->timer == 0) continue;
            if (--c->timer) continue;
            channel_set(n, 0);   /* pulse finished */
            break;

        case MODE_BLINK:
            if (c->timer == 0) continue;
            if (--c->timer) continue;
            c->phase ^= 1u;
            channel_set(n, c->phase);
            c->timer = BLINK_HALF_TICKS;
            break;

        case MODE_FLASH: {
            /* flasher: toggle between on and off using flash_on_ticks
             * and flash_off_ticks. Single mode: after one full cycle,
             * turn off. */
            if (c->phase == 1) {
                /* currently off phase: turn on */
                if (c->timer == 0) {
                    channel_set(n, 1);
                    c->phase = 1;  /* now on phase */
                    c->timer = c->flash_on_ticks;
                }
            } else {
                /* currently on phase */
                if (c->timer == 0) {
                    channel_set(n, 0);
                    c->phase = 0;  /* now off phase */
                    c->timer = c->flash_off_ticks;
                }
            }
            /* single flash: after one on+off cycle, turn off permanently */
            if (c->flash_single && c->phase == 0 && c->timer == 0) {
                channel_set(n, 0);
                c->flash_single = 0;
            }
            break;
        }

        case MODE_PULSE_MS:
            /* pulse with configured duration in ticks (from type 0x10) */
            if (c->timer == 0) continue;
            if (--c->timer) continue;
            channel_set(n, 0);
            break;

        default:
            break;
        }
    }
}

/* Save channel state to EEPROM (addresses 0x0D..0x14 = 8 bytes) */
static void eeprom_save_state(void)
{
    uint8_t i;
    for (i = 0; i < 8; i++) {
        uint8_t byte = ch[i].mode;          /* bits 0-1 */
        byte |= (ch[i].on != 0) << 2;      /* bit 2 */
        byte |= (ch[i].flags & 0x03) << 3; /* bit 3 delayed_off_en, bit 4 double_tap_en */
        eeprom_write(0x0D + i, byte);
    }
}

/* Persist per-channel run-on delay in seconds (0-255).
 * Layout: byte 0x15 + n = delay in seconds for channel n (0-7). */
static void eeprom_save_delays(uint8_t chan, uint32_t ms)
{
    if (chan < 1 || chan > 8) {
        return;
    }
    eeprom_write(0x15 + (uint8_t)(chan - 1), (uint8_t)(ms / 1000u));
}

static void eeprom_load_delays(uint8_t chan)
{
    if (chan < 1 || chan > 8) {
        return;
    }
    uint8_t secs = eeprom_read(0x15 + (uint8_t)(chan - 1));
    ch[chan - 1].delay_ms = (uint32_t)secs * 1000u;
}

/* Load channel state from EEPROM (addresses 0x0D..0x14 = 8 bytes) */
static void eeprom_load_state(void)
{
    uint8_t i;
    for (i = 0; i < 8; i++) {
        uint8_t b = eeprom_read(0x0D + i);
        ch[i].mode   = b & 0x03;
        ch[i].on     = (b >> 2) & 0x01;
        ch[i].flags  = (b >> 3) & 0x03;    /* bits 3-4: delayed_off_en, double_tap_en */
        eeprom_load_delays(i + 1);
        board_output(i, ch[i].on != 0);    /* apply loaded state to outputs */
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
        /* payload: [channel, mode, duty, freq_lo, freq_hi, delay_secs]
         * mode: 0 = off, 1 = steady on, 2 = PWM, 3 = PWM with soft start
         *       (mode 3: payload[2]=target_duty, payload[3]=soft_start_ticks,
         *        payload[4] unused)
         * freq: PWM frequency in Hz (mode 2 only)
         * delay_secs: 0-255 seconds of run-on after release (fan/pump).
         *   Only used with delayed-off enabled (flags bit0). */
        uint8_t chan = f->payload[0];
        uint8_t mode = f->payload[1];
        uint8_t duty = f->payload[2];
        uint16_t hz  = (uint16_t)f->payload[3] | ((uint16_t)f->payload[4] << 8);
        uint8_t delay_secs = f->payload[5];

        if (chan >= 1 && chan <= 8 && mode <= 3) {
            ch[chan - 1].delay_ms = (uint32_t)delay_secs * 1000u;
            eeprom_save_delays(chan, ch[chan - 1].delay_ms);
            if (mode == 2 || mode == 3) {
                /* Route to correct timer */
                uint16_t soft_ticks = 0;
                if (mode == 3) {
                    soft_ticks = (uint16_t)f->payload[3];
                    hz = 100;  /* default 100 Hz for soft-start PWM */
                }
                if (pwm2_channel_ok(chan)) {
                    pwm2_set_frequency(hz);
                    out_set_mode(chan, mode);
                    pwm2_set_duty(chan, duty);
                } else if (pwm_channel_ok(chan)) {
                    pwm_set_frequency(hz);
                    out_set_mode(chan, mode);
                    pwm_set_duty(chan, duty);
                } else {
                    out_set_mode(chan, 0);
                    ch[chan - 1].on = 0;
                }
                /* Soft start: zero the CCR duty, then ramp up */
                if (mode == 3 && soft_ticks > 0) {
                    ch[chan - 1].soft_start_ticks = soft_ticks;
                    ch[chan - 1].soft_start_duty = duty;
                    ch[chan - 1].on = 0;
                    /* Reset CCR to 0 to start the ramp from zero */
                    if (pwm2_channel_ok(chan)) {
                        pwm2_set_duty(chan, 0);
                    } else if (pwm_channel_ok(chan)) {
                        pwm_set_duty(chan, 0);
                    }
                }
            } else {
                out_set_mode(chan, mode);
                ch[chan - 1].on = (mode != 0);
            }
        }
        break;
    }
    case PROTO_TYPE_FORCE: {
        /* payload: [channel, action]
         * action: 0 = off, 1 = on, 2 = toggle
         * Overrides normal state machine; cleared by next panel event. */
        uint8_t chan = f->payload[0];
        uint8_t action = f->payload[1];
        if (chan >= 1 && chan <= 8 && action <= 2) {
            uint8_t n = (uint8_t)(chan - 1);
            if (action == 0) {
                channel_set(n, 0);
                ch[n].delayed_off_ticks = 0;
            } else if (action == 1) {
                channel_set(n, 1);
                ch[n].delayed_off_ticks = 0;
            } else {
                channel_set(n, !ch[n].on);
            }
            ch[n].double_tap_ticks = 0;  /* clear any pending double-tap */
            eeprom_save_state();
        }
        break;
    }
    case PROTO_TYPE_OPTBYT: {
        /* payload: [action, value]
         * action: 0 = read AFR, 1 = write AFR (requires power cycle)
         * value: AFR bits (bit0=AFR0 TIM2_CH1->PC5, bit1=AFR1 TIM2_CH3->PD2)
         * Reply via status frame with current AFR value. */
        uint8_t action = f->payload[0];
        if (action == 0) {
            uint8_t afr = optbyte_read(0x4803);
            uint8_t status[6] = {0};
            status[0] = afr;  /* current AFR value */
            proto_send_status(f, status);
        } else if (action == 1) {
            uint8_t afr = f->payload[1] & 0x03;
            optbyte_set_afr(afr);
            /* trigger reset via WWDG (window watchdog) to force reload */
            CLK_CKDIVR |= 0x80;  /* not a real reset; user must power cycle */
        }
        break;
    }
    case PROTO_TYPE_WIPER: {
        /* payload: [action, duty]
         * action: 0 = off, 1 = slow PWM, 2 = fast PWM, 3 = intermittent momentary,
         *         4 = wash (on-off-on-off, 4 sweeps), 5 = swipe (single fast sweep)
         * duty: 0-100 PWM duty cycle (for actions 1 & 2 only)
         * Wiper output uses channel 5 (PC5/TIM2_CH1, 10 A fuse). */
        uint8_t wiper_action = f->payload[0];
        uint8_t wiper_duty = f->payload[1] & 0x3F;  /* 0-63 */
        uint8_t n = 4;  /* channel 5 = index 4 (0-based) */

        if (n >= 8) break;

        switch (wiper_action) {
        case 0: /* off */
            channel_set(n, 0);
            ch[n].timer = 0;
            break;
        case 1: /* slow PWM */
            pwm2_set_frequency(50);
            pwm2_set_duty(n, wiper_duty);
            channel_set(n, 1);
            ch[n].mode = 2;
            break;
        case 2: /* fast PWM */
            pwm2_set_frequency(100);
            pwm2_set_duty(n, wiper_duty);
            channel_set(n, 1);
            ch[n].mode = 2;
            break;
        case 3: { /* intermittent: one sweep (momentary) */
            channel_set(n, 1);
            ch[n].timer = ticks_from_ms(500);  /* auto-off after 500 ms */
            ch[n].mode = 3;  /* MODE_PULSE */
            break;
        }
        case 4: { /* wash: 4 sweeps with pauses between */
            /* First sweep: momentary on for 800 ms, off for 200 ms, repeat 4x */
            /* Use MODE_PULSE with timer as the "on" time; the off time
             * is implicit (coast). For simplicity, do 4 quick sweeps. */
            channel_set(n, 1);
            ch[n].timer = ticks_from_ms(800);
            ch[n].mode = 3;  /* MODE_PULSE */
            break;
        }
        case 5: { /* swipe: single fast sweep */
            channel_set(n, 1);
            ch[n].timer = ticks_from_ms(300);
            ch[n].mode = 3;  /* MODE_PULSE */
            break;
        }
        default:
            channel_set(n, 0);
            break;
        }
        break;
    }
    case PROTO_TYPE_FLASH: {
        /* payload: [channel, flash_on_ticks, flash_off_ticks, single]
         * flash_on_ticks: on phase in ticks (2 ms each)
         * flash_off_ticks: off phase in ticks (2 ms each)
         * single: 1 = single flash (turn off after one full cycle)
         * Mode is set to MODE_FLASH for the target channel. */
        uint8_t chan = f->payload[0];
        uint16_t on_ticks = (uint16_t)(f->payload[1] | ((uint16_t)f->payload[2] << 8));
        uint16_t off_ticks = (uint16_t)(f->payload[3] | ((uint16_t)f->payload[4] << 8));
        uint8_t single = f->payload[5];

        if (chan >= 1 && chan <= 8) {
            uint8_t n = (uint8_t)(chan - 1);
            ch[n].mode = MODE_FLASH;
            ch[n].flash_on_ticks = on_ticks;
            ch[n].flash_off_ticks = off_ticks;
            ch[n].flash_single = single & 0x01;
            ch[n].phase = 1;  /* start on */
            ch[n].timer = on_ticks;
            if (on_ticks > 0) {
                channel_set(n, 1);
            } else {
                channel_set(n, 0);
            }
            eeprom_save_state();
        }
        break;
    }
    case PROTO_TYPE_INPUT: {
        /* payload: [mask]
         * mask: 8-bit bitmask of active inputs from middle ECU.
         * Channels with input_drive set will follow this bitmask. */
        input_mask = f->payload[0];
        break;
    }
    case PROTO_TYPE_PULSE: {
        /* payload: [channel, duration_ms]
         * duration_ms: pulse on-time in milliseconds (0-65535)
         * Sets the channel to MODE_PULSE_MS and arms the timer. */
        uint8_t chan = f->payload[0];
        uint16_t dur_ms = (uint16_t)(f->payload[1] | ((uint16_t)f->payload[2] << 8));

        if (chan >= 1 && chan <= 8 && dur_ms > 0) {
            uint8_t n = (uint8_t)(chan - 1);
            ch[n].mode = MODE_PULSE_MS;
            ch[n].pulse_ticks = dur_ms / 2u;  /* 2 ms per tick */
            ch[n].timer = ch[n].pulse_ticks;
            channel_set(n, 1);
            break;
        }
        break;
    }
    case PROTO_TYPE_CNT: {
        /* payload: [channel, counter_value]
         * counter_value: 16-bit counter from middle ECU (e.g. wheel speed).
         * Used for wiper/fan speed mapping:
         *   counter_value 0       -> off
         *   counter_value > 0     -> PWM duty = counter_value * 100 / 65535
         *   (mapped to 0-100% duty, clamped) */
        uint8_t chan = f->payload[0];
        uint16_t cnt_val = (uint16_t)(f->payload[1] | ((uint16_t)f->payload[2] << 8));

        if (chan >= 1 && chan <= 8) {
            uint8_t n = (uint8_t)(chan - 1);
            uint16_t duty = (cnt_val > 0) ? (uint16_t)((uint32_t)cnt_val * 100u / 65535u) : 0;
            if (duty > 100) duty = 100;

            if (pwm2_channel_ok(chan)) {
                pwm2_set_frequency(100);
                pwm2_set_duty(chan, (uint8_t)duty);
                out_set_mode(chan, duty > 0 ? 2 : 0);
            } else if (pwm_channel_ok(chan)) {
                pwm_set_frequency(100);
                pwm_set_duty(chan, (uint8_t)duty);
                out_set_mode(chan, duty > 0 ? 2 : 0);
            } else {
                out_set_mode(chan, duty > 0 ? 1 : 0);
            }
            ch[n].on = (duty > 0) ? 1 : 0;
        }
        break;
    }
    case PROTO_TYPE_START: {
        /* payload: [cranking, disable_mask]
         * crank: 1 = engine cranking, 0 = not cranking
         * disable_mask: 8-bit bitmask of channels to disable while cranking
         * When crank=1, channels with their bit in disable_mask are forced off. */
        start_cranking = f->payload[0] & 0x01;
        uint8_t disable_mask = f->payload[1];

        for (uint8_t n = 0; n < 8; n++) {
            ch[n].start_disable = (disable_mask & (1u << n)) != 0 ? 1 : 0;
            if (start_cranking && ch[n].start_disable) {
                channel_set(n, 0);
            }
        }
        break;
    }
    default:
        break;
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
