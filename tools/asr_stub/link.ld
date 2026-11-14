ENTRY(reset_handler)
SECTIONS
{
  . = 0x20010000;
  .vectors : { KEEP(*(.vectors)) }
  .text    : { *(.text*) *(.rodata*) }
  .data    : { *(.data*) }
  .bss     : { *(.bss*) *(COMMON) }
}
