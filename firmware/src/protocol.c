/*
 * protocol.c - 2400 8N1 panel link, polled (no interrupt vector needed).
 *
 * Frame layout (verified against the stock firmware):
 *   seq  dir  type  flag  p0 p1 p2 p3 p4 p5  sum
 *   sum = (sum of all preceding bytes) & 0xFF
 */
#include "board.h"
#include "protocol.h"

static volatile uint8_t buf[PROTO_FRAME_LEN];
static volatile uint8_t len;

uint8_t proto_checksum(const uint8_t *p, uint8_t n)
{
    uint8_t s = 0;
    while (n--) {
        s = (uint8_t)(s + *p++);
    }
    return s;
}

void proto_init(void)
{
    /* 16 MHz / 6666 = 2400 baud (same divider the stock firmware loads) */
    UART1_CR1  = 0x00;          /* 8 data bits, no parity */
    UART1_CR3  = 0x00;          /* 1 stop bit             */
    UART1_BRR2 = 0x1A;          /* DIV[15:12] | DIV[3:0]  */
    UART1_BRR1 = 0xA0;          /* DIV[11:4]              */
    UART1_CR2  = 0x0C;          /* TEN | REN (no RX irq)  */
    UART1_CR4  = 0x00;
    len = 0;
}

/* Drain the receive register into the frame buffer. */
void proto_pump(void)
{
    while (UART1_SR & 0x20) {              /* RXNE */
        uint8_t b = UART1_DR;
        if (len < PROTO_FRAME_LEN) {
            buf[len++] = b;
        } else {
            len = 0;
        }
    }
}

uint8_t proto_poll(proto_frame_t *f)
{
    proto_pump();

    if (len < PROTO_FRAME_LEN) {
        return 0;
    }

    uint8_t fr[PROTO_FRAME_LEN];
    for (uint8_t i = 0; i < PROTO_FRAME_LEN; i++) {
        fr[i] = buf[i];
    }

    f->seq       = fr[0];
    f->direction = fr[1];
    f->type      = fr[2];
    f->flag      = fr[3];
    for (uint8_t i = 0; i < 6; i++) {
        f->payload[i] = fr[4 + i];
    }
    f->sum    = fr[PROTO_FRAME_LEN - 1];
    f->sum_ok = (proto_checksum(fr, PROTO_FRAME_LEN - 1) == f->sum);

    if (f->sum_ok) {
        len = 0;
    } else {
        /* shift one byte so the next frame can resynchronize */
        for (uint8_t i = 1; i < PROTO_FRAME_LEN; i++) {
            buf[i - 1] = fr[i];
        }
        len = PROTO_FRAME_LEN - 1;
    }
    return 1;
}

void proto_send_reply(const proto_frame_t *req)
{
    uint8_t f[12];
    uint8_t n = PROTO_FRAME_LEN;

    f[0] = req->seq;
    f[1] = PROTO_DIR_BASE;
    f[2] = (uint8_t)(req->type | 0x10);
    f[3] = 0x00;                    /* stock always zeroes this byte */

    if (req->type == PROTO_TYPE_POWER) {
        /* 12-byte reply: the request flag moves into the extra byte */
        f[4] = req->flag;
        for (uint8_t i = 0; i < 6; i++) {
            f[5 + i] = req->payload[i];
        }
        n = 12;
    } else {
        for (uint8_t i = 0; i < 6; i++) {
            f[4 + i] = req->payload[i];
        }
    }
    f[n - 1] = proto_checksum(f, (uint8_t)(n - 1));

    for (uint8_t i = 0; i < n; i++) {
        while (!(UART1_SR & 0x80)) {
        }                           /* wait TXE */
        UART1_DR = f[i];
    }
}
