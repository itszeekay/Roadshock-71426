// FUNC 0x1004f728  uart0_rx_callback

void uart0_rx_callback(undefined1 param_1)

{
  byte bVar1;
  byte *pbVar2;
  byte *pbVar3;
  uint uVar4;
  int iVar5;
  
  FUN_10053930(0x28);
  FUN_10053918(0x28,0x14);
  pbVar2 = DAT_1004f778;
  if ((*DAT_1004f778 + 1 & 1) != *DAT_1004f77c) {
    FUN_10053930(0x28);
    FUN_10053918(0x28,0x14);
    pbVar3 = DAT_1004f780;
    bVar1 = *DAT_1004f780;
    uVar4 = bVar1 + 1;
    iVar5 = DAT_1004f784 + (uint)*pbVar2 * 0x20;
    *DAT_1004f780 = (byte)uVar4;
    *(undefined1 *)(iVar5 + (uint)bVar1) = param_1;
    if (0x1f < (uVar4 & 0xff)) {
      *pbVar3 = 0;
    }
  }
  return;
}


