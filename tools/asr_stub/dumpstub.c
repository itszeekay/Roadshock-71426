/*
 * J3-only flash dump stub.
 *
 * Runs from RAM at 0x20010000 through the ROM monitor `boot` command.
 * Prints the whole 1 MB flash as ASCII hex, 16 bytes per line, through the
 * ROM monitor's own print routine, so it uses the monitor's 115200 UART.
 *
 * Host parsing: ignore every line that is not exactly 32 hex characters,
 * concatenate the rest in order.
 */
typedef unsigned int u32;
typedef unsigned char u8;

#define PRINT_ENABLE 0x20016000u
#define FLASH_BASE   0x10000000u
#define FLASH_SIZE   0x00100000u
#define AIRCR        0xE000ED0Cu

void reset_handler(void);

static char hexdigit(u8 v)
{
    v &= 0x0Fu;
    return (char)(v < 10u ? ('0' + v) : ('A' + (v - 10u)));
}

static void print(const char *s)
{
    ((void (*)(const char *))0x000009B1u)(s);
}

void reset_handler(void)
{
    const u8 *p = (const u8 *)FLASH_BASE;
    char line[35];
    u32 i;
    u32 j;

    *(volatile u32 *)PRINT_ENABLE = 1u;

    print("DUMP START\r\n");

    for (i = 0; i < FLASH_SIZE; i += 16u) {
        for (j = 0; j < 16u; j++) {
            u8 b = p[i + j];
            line[j * 2u] = hexdigit((u8)(b >> 4));
            line[j * 2u + 1u] = hexdigit(b);
        }
        line[32] = '\r';
        line[33] = '\n';
        line[34] = '\0';
        print(line);
    }

    print("DUMP END\r\n");

    /* Do not reset here. A reset discards the last UART bytes before they
       leave the chip. Stay in this loop so the link drains; the host stops
       on DUMP END and the panel is power-cycled afterwards. */
    for (;;) {
    }
}
