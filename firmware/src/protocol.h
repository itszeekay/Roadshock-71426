#ifndef PROTOCOL_H
#define PROTOCOL_H

#include <stdint.h>

#define PROTO_FRAME_LEN  11
#define PROTO_DIR_PANEL  0x00
#define PROTO_DIR_BASE   0xFF

#define PROTO_TYPE_POWER 0x07
#define PROTO_TYPE_KEYS  0x08
#define PROTO_FLAG_KEYS  0x0C
#define PROTO_TYPE_CONFIG 0x09   /* custom: configure one output */
#define PROTO_TYPE_STATUS 0x0A   /* custom: status report */
#define PROTO_TYPE_FORCE 0x0B  /* custom: force on/off */

typedef struct {
    uint8_t seq;
    uint8_t direction;
    uint8_t type;
    uint8_t flag;
    uint8_t payload[6];
    uint8_t sum;
    uint8_t sum_ok;
} proto_frame_t;

void proto_init(void);
uint8_t proto_poll(proto_frame_t *out);
void proto_send_reply(const proto_frame_t *request);
uint8_t proto_checksum(const uint8_t *buf, uint8_t n);

#endif
