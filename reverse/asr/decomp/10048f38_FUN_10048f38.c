// FUNC 0x10048f38  FUN_10048f38

uint FUN_10048f38(uint param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  if (param_1 == 0) {
    uVar3 = 0;
    uVar2 = 0;
  }
  else {
    iVar1 = FUN_10056d78();
    uVar3 = 0x9e - iVar1;
    if ((int)uVar3 < 0x97) {
      uVar2 = param_1 << (0x96 - uVar3 & 0xff) & 0x7fffff;
      uVar3 = uVar3 & 0xff;
    }
    else {
      if ((int)uVar3 < 0x9a) {
        param_1 = param_1 << (0x99 - uVar3 & 0xff);
      }
      else {
        param_1 = param_1 >> (5U - iVar1 & 0xff) | (uint)(param_1 << (0xb9 - uVar3 & 0xff) != 0);
      }
      uVar2 = DAT_10048fb0 & param_1;
      if (((param_1 & 7) != 0) && ((param_1 & 0xf) != 4)) {
        uVar2 = uVar2 + 4;
      }
      if ((int)(uVar2 << 5) < 0) {
        uVar2 = uVar2 & DAT_10048fb0;
        uVar3 = 0x9f - iVar1;
      }
      uVar2 = (uVar2 << 6) >> 9;
      uVar3 = uVar3 & 0xff;
    }
  }
  return uVar3 << 0x17 | uVar2;
}


