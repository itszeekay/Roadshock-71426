// FUNC 0x10048ea8  FUN_10048ea8

uint FUN_10048ea8(uint param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  if (param_1 == 0) {
    param_1 = 0;
    uVar3 = 0;
    uVar4 = 0;
  }
  else {
    uVar4 = param_1 + ((int)param_1 >> 0x1f) ^ (int)param_1 >> 0x1f;
    param_1 = param_1 >> 0x1f;
    iVar1 = FUN_10056d78(uVar4);
    uVar3 = 0x9e - iVar1;
    if ((int)uVar3 < 0x97) {
      uVar4 = uVar4 << (0x96 - uVar3 & 0xff) & 0x7fffff;
      uVar3 = uVar3 & 0xff;
    }
    else {
      if ((int)uVar3 < 0x9a) {
        uVar4 = uVar4 << (0x99 - uVar3 & 0xff);
      }
      else {
        uVar4 = uVar4 >> (5U - iVar1 & 0xff) | (uint)(uVar4 << (0xb9 - uVar3 & 0xff) != 0);
      }
      uVar2 = DAT_10048f34 & uVar4;
      if (((uVar4 & 7) != 0) && ((uVar4 & 0xf) != 4)) {
        uVar2 = uVar2 + 4;
      }
      if ((int)(uVar2 << 5) < 0) {
        uVar2 = uVar2 & DAT_10048f34;
        uVar3 = 0x9f - iVar1;
      }
      uVar4 = (uVar2 << 6) >> 9;
      uVar3 = uVar3 & 0xff;
    }
  }
  return uVar4 | uVar3 << 0x17 | param_1 << 0x1f;
}


