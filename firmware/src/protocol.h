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
#define PROTO_TYPE_FORCE 0x0B    /* custom: force on/off */
#define PROTO_TYPE_OPTBYT 0x0C   /* custom: one-time option byte write (requires reset) */
#define PROTO_TYPE_WIPER 0x0D    /* custom: wiper control (off/slow/fast/intermittent) */
#define PROTO_TYPE_FLASH 0x0E    /* custom: flasher config (on_time, off_time, single) */
#define PROTO_TYPE_INPUT 0x0F    /* custom: input bitmask (middle ECU digital/CAN inputs) */
#define PROTO_TYPE_PULSE 0x10    /* custom: pulse mode (duration in ms) */
#define PROTO_TYPE_CNT   0x11    /* custom: counter value (for wiper speed / fan speed) */
#define PROTO_TYPE_START 0x12    /* custom: starter disable (bitmask of outputs to disable while cranking) */

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
void proto_send_status(const proto_frame_t *req, const uint8_t *status);
uint8_t proto_checksum(const uint8_t *buf, uint8_t n);

#endif
