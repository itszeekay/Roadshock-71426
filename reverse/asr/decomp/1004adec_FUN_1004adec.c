// FUNC 0x1004adec  FUN_1004adec

uint FUN_1004adec(uint param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar4 = param_1 & 0x7fffff;
  uVar3 = param_2 & 0x7fffff;
  uVar2 = (param_1 << 1) >> 0x18;
  uVar1 = (param_2 << 1) >> 0x18;
  if (((uVar2 == 0xff) && (uVar4 != 0)) || ((uVar1 == 0xff && (uVar3 != 0)))) {
    return 0xfffffffe;
  }
  if (uVar2 == 0) {
    if ((uVar1 == 0) && (uVar3 == 0)) {
      if (uVar4 == 0) {
        return 0;
      }
      goto LAB_1004ae2e;
    }
    if (uVar4 == 0) {
      return -(uint)(-1 < (int)param_2) | 1;
    }
  }
  else if ((uVar1 == 0) && (uVar3 == 0)) goto LAB_1004ae2e;
  if (((int)param_2 >> 0x1f == (int)param_1 >> 0x1f) && (uVar2 <= uVar1)) {
    if (uVar1 <= uVar2) {
      if (uVar3 < uVar4) goto LAB_1004ae2e;
      if (uVar3 <= uVar4) {
        return 0;
      }
    }
    return -(uint)(-1 < (int)param_1) | 1;
  }
LAB_1004ae2e:
  return (int)param_1 >> 0x1f | 1;
}


