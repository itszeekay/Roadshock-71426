// FUNC 0x1004a9f0  FUN_1004a9f0

uint FUN_1004a9f0(uint param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar2 = (param_2 << 1) >> 0x15;
  uVar3 = 0;
  if (DAT_1004aa44 < (int)uVar2) {
    if (DAT_1004aa48 < (int)uVar2) {
      uVar3 = DAT_1004aa54 - ((int)param_2 >> 0x1f);
    }
    else {
      uVar1 = param_2 & 0xfffff | 0x100000;
      if ((int)(DAT_1004aa4c - uVar2) < 0x20) {
        uVar1 = uVar1 << (uVar2 + DAT_1004aa58 & 0xff) | param_1 >> (DAT_1004aa4c - uVar2 & 0xff);
      }
      else {
        uVar1 = uVar1 >> (DAT_1004aa50 - uVar2 & 0xff);
      }
      uVar3 = -uVar1;
      if (-1 < (int)param_2) {
        uVar3 = uVar1;
      }
    }
  }
  return uVar3;
}


