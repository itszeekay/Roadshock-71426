// FUNC 0x1004ce00  FUN_1004ce00

undefined4 FUN_1004ce00(byte *param_1)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  byte bVar4;
  
  if (param_1 == (byte *)0x0) {
LAB_1004ce28:
    uVar2 = 0xffffffff;
  }
  else {
    bVar4 = *param_1;
    if (bVar4 < 0x10) {
      uVar3 = *(uint *)(DAT_1004ce30 + 4);
      iVar1 = DAT_1004ce30;
    }
    else {
      if (0x1e < bVar4) goto LAB_1004ce28;
      bVar4 = bVar4 - 0x10;
      uVar3 = *(uint *)(DAT_1004ce34 + 4);
      iVar1 = DAT_1004ce34;
    }
    *(uint *)(iVar1 + 4) = 1 << (uint)bVar4 | uVar3;
    uVar2 = 0;
  }
  return uVar2;
}


