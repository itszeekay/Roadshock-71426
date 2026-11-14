// FUNC 0x1004ab50  FUN_1004ab50

undefined8 FUN_1004ab50(uint param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar2 = (param_1 << 1) >> 0x18;
  uVar4 = param_1 & 0x7fffff;
  if ((uVar2 + 1 & 0xff) < 2) {
    if (uVar2 == 0) {
      if (uVar4 == 0) {
        uVar3 = 0;
        uVar2 = 0;
      }
      else {
        iVar1 = FUN_10056d78(uVar4);
        if (iVar1 < 0xb) {
          uVar3 = uVar4 >> (0xbU - iVar1 & 0xff);
          uVar4 = uVar4 << (iVar1 + 0x15U & 0xff);
        }
        else {
          uVar3 = uVar4 << (iVar1 - 0xbU & 0xff);
          uVar4 = 0;
        }
        uVar3 = uVar3 & 0xfffff;
        uVar2 = DAT_1004abf0 - iVar1 & 0x7ff;
      }
    }
    else {
      uVar2 = DAT_1004abf4;
      if (uVar4 == 0) {
        uVar3 = 0;
      }
      else {
        uVar3 = (param_1 << 9) >> 0xc | 0x80000;
        uVar4 = uVar4 << 0x1d;
      }
    }
  }
  else {
    uVar4 = uVar4 << 0x1d;
    uVar3 = (param_1 << 9) >> 0xc;
    uVar2 = uVar2 + 0x380;
  }
  return CONCAT44(uVar3 & DAT_1004abec | (uVar2 << 0x15) >> 1 | param_1 & 0x80000000,uVar4);
}


