// FUNC 0x1004b098  FUN_1004b098

void FUN_1004b098(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 int param_5,uint param_6,char param_7,int param_8,uint param_9,uint param_10,
                 uint param_11)

{
  undefined1 uVar1;
  uint uVar2;
  
  if (-1 < (int)(param_11 << 0x1e)) {
    if (((param_10 != 0) && ((int)(param_11 << 0x1f) < 0)) &&
       ((param_7 != '\0' || ((param_11 & 0xc) != 0)))) {
      param_10 = param_10 - 1;
    }
    for (; (param_6 < param_9 && (param_6 < 0x20)); param_6 = param_6 + 1) {
      *(undefined1 *)(param_5 + param_6) = 0x30;
    }
    for (; (((param_11 & 1) != 0 && (param_6 < param_10)) && (param_6 < 0x20));
        param_6 = param_6 + 1) {
      *(undefined1 *)(param_5 + param_6) = 0x30;
    }
  }
  if ((int)(param_11 << 0x1b) < 0) {
    uVar2 = param_6;
    if (((((int)(param_11 << 0x15) < 0) || (param_6 == 0)) ||
        ((param_6 != param_9 && (param_6 != param_10)))) || (uVar2 = param_6 - 1, uVar2 == 0)) {
      param_6 = uVar2;
      if (param_8 == 0x10) goto LAB_1004b120;
LAB_1004b136:
      if (param_8 == 2) {
        param_6 = uVar2;
        if (0x1f < uVar2) goto LAB_1004b170;
        uVar1 = 0x62;
        goto LAB_1004b142;
      }
    }
    else {
      param_6 = param_6 - 2;
      if (param_8 != 0x10) goto LAB_1004b136;
LAB_1004b120:
      if ((int)(param_11 << 0x1a) < 0) {
        uVar1 = 0x58;
      }
      else {
        uVar1 = 0x78;
      }
      uVar2 = param_6;
      if (0x1f < param_6) goto LAB_1004b170;
LAB_1004b142:
      *(undefined1 *)(param_5 + uVar2) = uVar1;
      uVar2 = uVar2 + 1;
    }
    param_6 = uVar2;
    if (0x1f < uVar2) goto LAB_1004b170;
    *(undefined1 *)(param_5 + uVar2) = 0x30;
    param_6 = uVar2 + 1;
  }
  if (param_6 < 0x20) {
    if (param_7 == '\0') {
      if ((int)(param_11 << 0x1d) < 0) {
        uVar1 = 0x2b;
      }
      else {
        if (-1 < (int)(param_11 << 0x1c)) goto LAB_1004b170;
        uVar1 = 0x20;
      }
    }
    else {
      uVar1 = 0x2d;
    }
    *(undefined1 *)(param_5 + param_6) = uVar1;
    param_6 = param_6 + 1;
  }
LAB_1004b170:
  FUN_1004b02e(param_1,param_2,param_3,param_4,param_5,param_6,param_10,param_11);
  return;
}


