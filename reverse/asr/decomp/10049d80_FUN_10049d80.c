// FUNC 0x10049d80  FUN_10049d80

uint FUN_10049d80(uint param_1,uint param_2,uint param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar1 = param_4 & 0xfffff;
  uVar4 = param_2 & 0xfffff;
  uVar2 = (param_2 << 1) >> 0x15;
  uVar3 = (param_4 << 1) >> 0x15;
  if ((uVar2 == DAT_10049e50) && (uVar4 != 0 || param_1 != 0)) {
    return 2;
  }
  if ((uVar3 == DAT_10049e50) && (uVar1 != 0 || param_3 != 0)) {
    return 2;
  }
  if (uVar2 == 0) {
    if ((uVar3 == 0) && (param_3 == 0 && uVar1 == 0)) {
      if (param_1 == 0 && uVar4 == 0) {
        return 0;
      }
      goto LAB_10049de6;
    }
    if (param_1 == 0 && uVar4 == 0) goto LAB_10049dc6;
  }
  else if ((uVar3 == 0) && (param_3 == 0 && uVar1 == 0)) goto LAB_10049de6;
  if ((int)param_2 >> 0x1f == (int)param_4 >> 0x1f) {
    if (uVar3 < uVar2) {
      return (int)param_4 >> 0x1f | 1;
    }
    if (uVar2 < uVar3) {
LAB_10049dc6:
      return -(uint)(-1 < (int)param_4) | 1;
    }
    if (uVar4 <= uVar1) {
      if (uVar4 == uVar1) {
        if (param_3 < param_1) goto LAB_10049de6;
        if (param_3 <= param_1) {
          return 0;
        }
      }
      else if (uVar1 <= uVar4) {
        return 0;
      }
      return -(uint)(-1 < (int)param_2) | 1;
    }
  }
LAB_10049de6:
  return (int)param_2 >> 0x1f | 1;
}


