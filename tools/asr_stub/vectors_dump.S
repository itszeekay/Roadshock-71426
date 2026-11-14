    .syntax unified
    .thumb
    .section .vectors,"a",%progbits
    .global vectors
    .type vectors, %object
vectors:
    .word 0x2000F000
    .word reset_handler + 1
    .size vectors, . - vectors
