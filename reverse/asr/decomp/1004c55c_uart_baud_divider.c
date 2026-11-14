// FUNC 0x1004c55c  uart_baud_divider

/* Converts a baud rate to the divisor written to the UART */

uint uart_baud_divider(int param_1)

{
  uint uVar1;
  int iVar2;
  int extraout_r1;
  uint uVar3;
  uint uVar4;
  
  uVar1 = 0;
  uVar3 = *DAT_1004c59c;
  if ((param_1 != 0) && (uVar4 = param_1 << 4, uVar4 <= uVar3)) {
    FUN_10056d68(uVar3,uVar4);
    uVar1 = FUN_10056d58(extraout_r1 << 3,param_1);
    iVar2 = FUN_10056d58(uVar3,uVar4);
    uVar1 = iVar2 << 0x10 | (uVar1 >> 1) + (uVar1 & 1) & 0xffff;
  }
  return uVar1;
}


