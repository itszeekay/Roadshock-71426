// FUNC 0x10056af4  FUN_10056af4

int FUN_10056af4(uint *param_1,uint *param_2,uint param_3)

{
  uint *puVar1;
  uint uVar2;
  
  if (param_3 != 0) {
    if ((((((uint)param_1 | (uint)param_2) & 3) == 0) && (3 < param_3)) &&
       (uVar2 = *param_1, uVar2 == *param_2)) {
      param_3 = param_3 - 4;
      if (param_3 == 0) {
        return 0;
      }
      if ((uVar2 + DAT_10056b84 & ~uVar2 & DAT_10056b88) != 0) {
        return 0;
      }
      do {
        param_1 = param_1 + 1;
        param_2 = param_2 + 1;
        if ((param_3 < 4) || (uVar2 = *param_1, uVar2 != *param_2)) goto LAB_10056b48;
        param_3 = param_3 - 4;
      } while ((param_3 != 0) && ((uVar2 + DAT_10056b84 & ~uVar2 & DAT_10056b88) == 0));
    }
    else {
LAB_10056b48:
      uVar2 = (uint)(byte)*param_2;
      if (uVar2 != (byte)*param_1) {
        return (byte)*param_1 - uVar2;
      }
      if (param_3 - 1 != 0) {
        puVar1 = (uint *)((int)param_2 + (param_3 - 1));
        do {
          if (uVar2 == 0) {
            return 0;
          }
          param_2 = (uint *)((int)param_2 + 1);
          param_1 = (uint *)((int)param_1 + 1);
          uVar2 = (uint)*(byte *)param_1;
          if (uVar2 != *(byte *)param_2) {
            return uVar2 - *(byte *)param_2;
          }
        } while (puVar1 != param_2);
      }
    }
  }
  return 0;
}


