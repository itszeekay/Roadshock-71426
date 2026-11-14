// FUNC 0x10000cf0  FUN_10000cf0

int FUN_10000cf0(code *param_1,undefined4 param_2,int param_3,undefined4 param_4,int param_5,
                uint param_6,char param_7,int param_8,uint param_9,uint param_10,uint param_11)

{
  uint uVar1;
  undefined1 uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  
  if ((param_11 & 2) == 0) {
    if (((param_10 != 0) && ((param_11 & 1) != 0)) && ((param_7 != '\0' || ((param_11 & 0xc) != 0)))
       ) {
      param_10 = param_10 - 1;
    }
    for (; (param_6 < param_9 && (param_6 != 0x20)); param_6 = param_6 + 1) {
      *(undefined1 *)(param_5 + param_6) = 0x30;
    }
    for (; (((param_11 & 1) != 0 && (param_6 < param_10)) && (param_6 != 0x20));
        param_6 = param_6 + 1) {
      *(undefined1 *)(param_5 + param_6) = 0x30;
    }
  }
  if ((int)(param_11 << 0x1b) < 0) {
    uVar1 = param_6;
    if (((((int)(param_11 << 0x15) < 0) || (param_6 == 0)) ||
        ((param_6 != param_9 && (param_6 != param_10)))) || (uVar1 = param_6 - 1, param_6 == 1)) {
      uVar4 = uVar1;
      if (param_8 == 0x10) goto LAB_10000d86;
      if (param_8 == 2) {
        if (0x1f < uVar1) goto LAB_10000d90;
        goto LAB_10000dd8;
      }
    }
    else {
      uVar4 = param_6 - 2;
      if (param_8 == 0x10) {
LAB_10000d86:
        if ((int)(param_11 << 0x1a) < 0) {
          uVar2 = 0x58;
        }
        else {
          uVar2 = 0x78;
        }
        uVar1 = uVar4;
        if (0x1f < uVar4) goto LAB_10000d90;
      }
      else {
        if (param_8 != 2) goto LAB_10000de8;
LAB_10000dd8:
        uVar2 = 0x62;
        uVar4 = uVar1;
      }
      *(undefined1 *)(param_5 + uVar4) = uVar2;
      uVar1 = uVar4 + 1;
    }
LAB_10000de8:
    if (0x1f < uVar1) goto LAB_10000d90;
    *(undefined1 *)(param_5 + uVar1) = 0x30;
    param_6 = uVar1 + 1;
  }
  uVar1 = param_6;
  if (param_6 != 0x20) {
    uVar2 = 0x2d;
    if (param_7 == '\0') {
      if ((int)(param_11 << 0x1d) < 0) {
        uVar2 = 0x2b;
      }
      else {
        if (-1 < (int)(param_11 << 0x1c)) goto LAB_10000d90;
        uVar2 = 0x20;
      }
    }
    *(undefined1 *)(param_5 + param_6) = uVar2;
    uVar1 = param_6 + 1;
  }
LAB_10000d90:
  uVar4 = uVar1;
  uVar6 = uVar1;
  iVar3 = param_3;
  if ((param_11 & 3) == 0) {
    for (; uVar4 < param_10; uVar4 = uVar4 + 1) {
      (*param_1)(0x20,param_2,(param_3 - uVar1) + uVar4,param_4);
    }
    iVar3 = 0;
    if (uVar1 <= param_10) {
      iVar3 = param_10 - uVar1;
    }
    iVar3 = iVar3 + param_3;
  }
  while( true ) {
    iVar5 = uVar1 + iVar3;
    if (uVar6 == 0) break;
    (*param_1)(*(undefined1 *)(param_5 + (uVar6 - 1)),param_2,iVar5 - uVar6,param_4);
    uVar6 = uVar6 - 1;
  }
  if ((param_11 & 2) != 0) {
    for (uVar1 = iVar5 - param_3; uVar1 < param_10; uVar1 = uVar1 + 1) {
      (*param_1)(0x20,param_2,uVar1 + param_3,param_4);
    }
    iVar3 = 0;
    if ((uint)(iVar5 - param_3) <= param_10) {
      iVar3 = (param_10 + param_3) - iVar5;
    }
    iVar5 = iVar5 + iVar3;
  }
  return iVar5;
}


