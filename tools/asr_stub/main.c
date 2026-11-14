/*
 * ASR5601S RAM flash stub.
 *
 * Runs from RAM at 0x20010000 after the ROM monitor `boot` command.
 * Copies the bootloader's flash routines into RAM, then erases and programs
 * one 256-byte block at the ATE partition 0x100F0000, and resets.
 *
 * Flash API (flash wrappers, all tail-call into the RAM copy):
 *   0x10004E70 ()                        flash init
 *   0x10004EC0 () -> unsigned            lock state
 *   0x10004EB0 ()                        unlock
 *   0x10004EA0 ()                        lock
 *   0x10004E80 (0x2520, addr)            erase 4 KB sector
 *   0x10004E60 (addr, len, data)         program, 256-byte chunks
 */
typedef unsigned int u32;
typedef unsigned char u8;

void reset_handler(void);

#define ATE_BASE   0x100F0000u
#define RAM_BASE   0x20000000u
#define ROM_SRC    0x10000120u
#define ROM_LEN    0x620u
#define STACK_TOP  0x2000F000u
#define AIRCR      0xE000ED0Cu

typedef void    (*fn0_t)(void);
typedef u32     (*fnu_t)(void);
typedef void    (*fnerase_t)(u32, u32);
typedef void    (*fnwrite_t)(u32, u32, const void *);

static void copy_block(void)
{
    volatile u32 *dst = (volatile u32 *)RAM_BASE;
    const u32 *src = (const u32 *)ROM_SRC;
    u32 i;

    for (i = 0; i < ROM_LEN / 4u; i++) {
        dst[i] = src[i];
    }
}

void reset_handler(void)
{
    static u8 pattern[256];
    u32 i;
    u32 lock;

    for (i = 0; i < sizeof(pattern); i++) {
        pattern[i] = (u8)(0xA0u + (i & 0x0Fu));
    }

    copy_block();

    ((fn0_t)0x10004E71u)();

    lock = ((fnu_t)0x10004EC1u)();
    if (lock) {
        ((fn0_t)0x10004EB1u)();
    }

    ((fnerase_t)0x10004E81u)(0x2520u, ATE_BASE);
#ifndef ERASE_ONLY
    ((fnwrite_t)0x10004E61u)(ATE_BASE, sizeof(pattern), pattern);
#endif

    if (lock) {
        ((fn0_t)0x10004EA1u)();
    }

    *(volatile u32 *)AIRCR = 0x05FA0004u;
    for (;;) {
    }
}
