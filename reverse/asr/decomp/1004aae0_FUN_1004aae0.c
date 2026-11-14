// FUNC 0x1004aae0  FUN_1004aae0

undefined8 FUN_1004aae0(uint param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  
  if (param_1 == 0) {
    uVar2 = 0;
    uVar3 = 0;
    iVar4 = 0;
  }
  else {
    iVar1 = FUN_10056d78();
    uVar2 = DAT_1004ab40 - iVar1;
    if ((int)(DAT_1004ab44 - uVar2) < 0x20) {
      iVar4 = param_1 << (DAT_1004ab44 - uVar2 & 0xff);
      uVar3 = param_1 >> (0xbU - iVar1 & 0xff) & 0xfffff;
      uVar2 = uVar2 & 0x7ff;
    }
    else {
      iVar4 = 0;
      uVar3 = param_1 << (DAT_1004ab48 - uVar2 & 0xff) & 0xfffff;
      uVar2 = uVar2 & 0x7ff;
    }
  }
  return CONCAT44(uVar3 & DAT_1004ab4c | uVar2 << 0x14,iVar4);
}


