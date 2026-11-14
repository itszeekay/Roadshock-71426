// FUNC 0x1004e888  uart3_write

/* Writes a buffer to UART3, the display link */

void uart3_write(undefined1 *param_1,int param_2)

{
  undefined1 *puVar1;
  
  puVar1 = param_1 + param_2;
  for (; param_1 != puVar1; param_1 = param_1 + 1) {
    uart_putc(DAT_1004e8a0,*param_1);
  }
  return;
}


