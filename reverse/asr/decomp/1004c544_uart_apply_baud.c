// FUNC 0x1004c544  uart_apply_baud

void uart_apply_baud(int param_1)

{
  *(undefined4 *)(param_1 + 4) = 0x1c200;
  *(undefined1 *)(param_1 + 8) = 3;
  *(undefined1 *)(param_1 + 9) = 0;
  *(undefined1 *)(param_1 + 10) = 0;
  *(undefined1 *)(param_1 + 0xb) = 0;
  *(undefined1 *)(param_1 + 0xc) = 3;
  *(undefined4 *)(param_1 + 0x10) = 0;
  return;
}


