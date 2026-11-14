// FUNC 0x1004aa5c  FUN_1004aa5c

undefined8 FUN_1004aa5c(uint param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  
  if (param_1 == 0) {
    param_1 = 0;
    uVar3 = 0;
    uVar4 = 0;
    iVar2 = 0;
  }
  else {
    uVar4 = param_1 + ((int)param_1 >> 0x1f) ^ (int)param_1 >> 0x1f;
    param_1 = param_1 >> 0x1f;
    iVar1 = FUN_10056d78(uVar4);
    uVar3 = DAT_1004aad0 - iVar1;
    if ((int)(DAT_1004aad4 - uVar3) < 0x20) {
      iVar2 = uVar4 << (DAT_1004aad4 - uVar3 & 0xff);
      uVar4 = uVar4 >> (0xbU - iVar1 & 0xff) & 0xfffff;
      uVar3 = uVar3 & 0x7ff;
    }
    else {
      iVar2 = 0;
      uVar4 = uVar4 << (DAT_1004aad8 - uVar3 & 0xff) & 0xfffff;
      uVar3 = uVar3 & 0x7ff;
    }
  }
  return CONCAT44(uVar4 & DAT_1004aadc | uVar3 << 0x14 | param_1 << 0x1f,iVar2);
}


