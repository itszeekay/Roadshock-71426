// FUNC 0x1004e7f0  uart1_log_init

/* UART1 on P04/P05 at 921600; the J3 log/console port */

void uart1_log_init(void)

{
  undefined1 local_24 [4];
  undefined4 local_20;
  undefined1 local_1c;
  undefined1 local_18;
  
  uart_driver_init(1,DAT_1004e848);
  pinmux_set(4,0xe);
  pinmux_set(5,0xe);
  FUN_10056f28(local_24,0,0x14);
  local_20 = 0xe1000;
  local_1c = 3;
  local_18 = 3;
  local_24[0] = 1;
  uart_init(local_24);
  uart_enable(1);
  uart_set_config(DAT_1004e84c,0x50,1);
  *DAT_1004e850 = 4;
  return;
}


