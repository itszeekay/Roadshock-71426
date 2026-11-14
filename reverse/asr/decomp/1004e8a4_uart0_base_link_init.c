// FUNC 0x1004e8a4  uart0_base_link_init

/* UART0 on P02/P03 at 2400; the base board link */

void uart0_base_link_init(void)

{
  undefined1 auStack_24 [4];
  undefined4 local_20;
  undefined1 local_1c;
  undefined1 local_18;
  
  uart_driver_init(0,DAT_1004e908);
  pinmux_set(2,0xd);
  pinmux_set(3,0xd);
  FUN_10056f28(auStack_24,0,0x14);
  local_20 = 0x960;
  local_1c = 3;
  local_18 = 3;
  uart_init(auStack_24);
  uart_set_config(0x40000000,0x50,1);
  *DAT_1004e90c = 8;
  uart_irq_enable(auStack_24,2,1);
  uart_nvic_priority(0x40000000,0);
  return;
}


