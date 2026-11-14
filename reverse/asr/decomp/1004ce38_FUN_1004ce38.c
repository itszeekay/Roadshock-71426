// FUNC 0x1004ce38  FUN_1004ce38

undefined4 FUN_1004ce38(byte *param_1)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  byte bVar4;
  
  if (param_1 == (byte *)0x0) {
LAB_1004ce5e:
    uVar2 = 0xffffffff;
  }
  else {
    bVar4 = *param_1;
    if (bVar4 < 0x10) {
      uVar3 = *(uint *)(DAT_1004ce64 + 4);
      iVar1 = DAT_1004ce64;
    }
    else {
      if (0x1e < bVar4) goto LAB_1004ce5e;
      bVar4 = bVar4 - 0x10;
      uVar3 = *(uint *)(DAT_1004ce68 + 4);
      iVar1 = DAT_1004ce68;
    }
    *(uint *)(iVar1 + 4) = uVar3 & ~(1 << (uint)bVar4);
    uVar2 = 0;
  }
  return uVar2;
}


