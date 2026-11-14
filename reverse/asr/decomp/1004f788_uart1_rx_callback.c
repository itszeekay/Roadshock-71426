// FUNC 0x1004f788  uart1_rx_callback

void uart1_rx_callback(undefined1 param_1)

{
  byte bVar1;
  
  FUN_10053930(0x37);
  FUN_10053918(0x37,0x14);
  bVar1 = *DAT_1004f7b4;
  if (bVar1 < 0x20) {
    *DAT_1004f7b4 = bVar1 + 1;
    *(undefined1 *)(DAT_1004f7b8 + (uint)bVar1) = param_1;
  }
  else {
    *DAT_1004f7b4 = 0;
  }
  return;
}


