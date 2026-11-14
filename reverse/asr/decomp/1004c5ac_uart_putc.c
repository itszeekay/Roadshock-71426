// FUNC 0x1004c5ac  uart_putc

void uart_putc(undefined4 *param_1,undefined4 param_2)

{
  if (param_1 != (undefined4 *)0x0) {
    do {
    } while ((param_1[6] & 0x20) != 0);
    *param_1 = param_2;
  }
  return;
}


