/*
 * ASR5601S bootloader - reconstructed from the SWD dump.
 * Image base 0x10000000, Ghidra 11.3.1, language ARM:LE:32:Cortex.
 * 101 functions, address order.
 *
 * Decompiler output, not original source. Types are approximate.
 * The per-function files and the Ghidra project are kept outside the
 * public repository; this file and the index are the tracked output.
 */

// FUNC 0x10000000  boot_vectors

int boot_vectors(void)

{
  int iVar1;
  int in_r3;
  uint unaff_r4;
  int unaff_r6;
  
  *(short *)(unaff_r4 - in_r3) = (short)(unaff_r4 >> 0xd) + (short)unaff_r4;
  iVar1 = *(int *)(unaff_r6 + 0x35);
  if ((*puRam10000130 & 2) == 0) {
    *puRam10000130 = 2;
  }
  return iVar1 + 0x2e;
}

// FUNC 0x10000740  FUN_10000740

int FUN_10000740(uint *param_1,uint *param_2)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  if ((((uint)param_1 | (uint)param_2) & 3) == 0) {
    do {
      uVar2 = *param_1;
      param_1 = param_1 + 1;
      uVar3 = *param_2;
      param_2 = param_2 + 1;
      uVar4 = uVar2 - DAT_100007c4 & ~uVar2 & DAT_100007c4 << 7;
      if (uVar4 != 0) {
        iVar1 = (uVar2 & 0xff) - (uVar3 & 0xff);
        if ((((uVar4 & 0xff) == 0 && iVar1 == 0) &&
            (iVar1 = (uVar2 & 0xffff) - (uVar3 & 0xffff), (uVar4 & 0xffff) == 0 && iVar1 == 0)) &&
           (iVar1 = (uVar2 & 0xffffff) - (uVar3 & 0xffffff), (uVar4 & 0xffffff) == 0 && iVar1 == 0))
        {
          iVar1 = (uVar2 >> 0x18) - (uVar3 >> 0x18);
        }
        return iVar1;
      }
    } while (uVar2 == uVar3);
    if ((uVar3 << 0x18 | (uVar3 >> 8 & 0xff) << 0x10 | (uVar3 >> 0x10 & 0xff) << 8 | uVar3 >> 0x18)
        < (uVar2 << 0x18 | (uVar2 >> 8 & 0xff) << 0x10 | (uVar2 >> 0x10 & 0xff) << 8 | uVar2 >> 0x18
          )) {
      return 1;
    }
    return -1;
  }
  while( true ) {
    uVar2 = (uint)(byte)*param_1;
    uVar3 = (uint)(byte)*param_2;
    if ((uVar2 == 0) || (uVar2 != uVar3)) break;
    uVar2 = (uint)*(byte *)((int)param_1 + 1);
    uVar3 = (uint)*(byte *)((int)param_2 + 1);
    param_1 = (uint *)((int)param_1 + 2);
    param_2 = (uint *)((int)param_2 + 2);
    if ((uVar2 == 0) || (uVar2 != uVar3)) break;
  }
  return uVar2 - uVar3;
}

// FUNC 0x100007c8  __gnu_thumb1_case_uqi

/* WARNING: This is an inlined function */

void __gnu_thumb1_case_uqi(void)

{
  return;
}

// FUNC 0x100007dc  __gnu_thumb1_case_shi

/* WARNING: This is an inlined function */

undefined8 __gnu_thumb1_case_shi(undefined4 param_1,undefined4 param_2)

{
  return CONCAT44(param_2,param_1);
}

// FUNC 0x100007f0  __gnu_thumb1_case_uhi

/* WARNING: This is an inlined function */

undefined8 __gnu_thumb1_case_uhi(undefined4 param_1,undefined4 param_2)

{
  return CONCAT44(param_2,param_1);
}

// FUNC 0x10000804  FUN_10000804

undefined8 FUN_10000804(uint param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  undefined4 uVar4;
  int iVar5;
  bool bVar6;
  bool bVar7;
  bool bVar8;
  bool bVar9;
  bool bVar10;
  
  iVar5 = 0;
  if (param_2 <= param_1 >> 1) {
    if (param_2 <= param_1 >> 4) {
      if (param_2 <= param_1 >> 8) {
        if (param_1 >> 0xc < param_2) goto LAB_10000870;
        if (param_2 <= param_1 >> 0x10) {
          iVar5 = -0x1000000;
          uVar1 = param_2 << 8;
          if (param_2 << 8 <= param_1 >> 0x10) {
            iVar5 = -0x10000;
            uVar1 = param_2 << 0x10;
            if (param_2 << 0x10 == 0) {
              uVar4 = FUN_10000918(0);
              return CONCAT44(param_1,uVar4);
            }
          }
          param_2 = uVar1;
          if (param_1 >> 0xc < param_2) goto LAB_10000870;
        }
        while( true ) {
          bVar6 = param_2 <= param_1 >> 0xf;
          uVar1 = param_1;
          if (bVar6) {
            uVar1 = param_1 + param_2 * -0x8000;
          }
          bVar10 = param_2 * 0x8000 <= param_1;
          bVar7 = param_2 <= uVar1 >> 0xe;
          uVar2 = uVar1;
          if (bVar7) {
            uVar2 = uVar1 + param_2 * -0x4000;
          }
          bVar8 = param_2 <= uVar2 >> 0xd;
          uVar3 = uVar2;
          if (bVar8) {
            uVar3 = uVar2 + param_2 * -0x2000;
          }
          bVar9 = param_2 <= uVar3 >> 0xc;
          param_1 = uVar3;
          if (bVar9) {
            param_1 = uVar3 + param_2 * -0x1000;
          }
          iVar5 = (((iVar5 * 2 + (uint)(bVar6 && bVar10)) * 2 +
                   (uint)(bVar7 && param_2 * 0x4000 <= uVar1)) * 2 +
                  (uint)(bVar8 && param_2 * 0x2000 <= uVar2)) * 2 +
                  (uint)(bVar9 && param_2 * 0x1000 <= uVar3);
LAB_10000870:
          bVar6 = param_2 <= param_1 >> 0xb;
          uVar1 = param_1;
          if (bVar6) {
            uVar1 = param_1 + param_2 * -0x800;
          }
          bVar10 = param_2 <= uVar1 >> 10;
          uVar2 = uVar1;
          if (bVar10) {
            uVar2 = uVar1 + param_2 * -0x400;
          }
          bVar7 = param_2 <= uVar2 >> 9;
          uVar3 = uVar2;
          if (bVar7) {
            uVar3 = uVar2 + param_2 * -0x200;
          }
          uVar1 = ((iVar5 * 2 + (uint)(bVar6 && param_2 * 0x800 <= param_1)) * 2 +
                  (uint)(bVar10 && param_2 * 0x400 <= uVar1)) * 2 +
                  (uint)(bVar7 && param_2 * 0x200 <= uVar2);
          bVar6 = param_2 <= uVar3 >> 8;
          param_1 = uVar3;
          if (bVar6) {
            param_1 = uVar3 + param_2 * -0x100;
          }
          bVar6 = bVar6 && param_2 * 0x100 <= uVar3;
          iVar5 = uVar1 * 2 + (uint)bVar6;
          if (!CARRY4(uVar1,uVar1) && !CARRY4(uVar1 * 2,(uint)bVar6)) break;
          param_2 = param_2 >> 8;
        }
      }
      bVar6 = param_2 <= param_1 >> 7;
      uVar1 = param_1;
      if (bVar6) {
        uVar1 = param_1 + param_2 * -0x80;
      }
      bVar10 = param_2 * 0x80 <= param_1;
      bVar7 = param_2 <= uVar1 >> 6;
      uVar2 = uVar1;
      if (bVar7) {
        uVar2 = uVar1 + param_2 * -0x40;
      }
      bVar8 = param_2 <= uVar2 >> 5;
      uVar3 = uVar2;
      if (bVar8) {
        uVar3 = uVar2 + param_2 * -0x20;
      }
      bVar9 = param_2 <= uVar3 >> 4;
      param_1 = uVar3;
      if (bVar9) {
        param_1 = uVar3 + param_2 * -0x10;
      }
      iVar5 = (((iVar5 * 2 + (uint)(bVar6 && bVar10)) * 2 + (uint)(bVar7 && param_2 * 0x40 <= uVar1)
               ) * 2 + (uint)(bVar8 && param_2 * 0x20 <= uVar2)) * 2 +
              (uint)(bVar9 && param_2 * 0x10 <= uVar3);
    }
    bVar6 = param_2 <= param_1 >> 3;
    uVar1 = param_1;
    if (bVar6) {
      uVar1 = param_1 + param_2 * -8;
    }
    bVar10 = param_2 * 8 <= param_1;
    bVar7 = param_2 <= uVar1 >> 2;
    uVar2 = uVar1;
    if (bVar7) {
      uVar2 = uVar1 + param_2 * -4;
    }
    bVar8 = param_2 <= uVar2 >> 1;
    param_1 = uVar2;
    if (bVar8) {
      param_1 = uVar2 + param_2 * -2;
    }
    iVar5 = ((iVar5 * 2 + (uint)(bVar6 && bVar10)) * 2 + (uint)(bVar7 && param_2 * 4 <= uVar1)) * 2
            + (uint)(bVar8 && param_2 * 2 <= uVar2);
  }
  uVar1 = param_1 - param_2;
  if (param_2 > param_1) {
    uVar1 = param_1;
  }
  return CONCAT44(uVar1,iVar5 * 2 + (uint)(param_2 <= param_1));
}

// FUNC 0x10000910  FUN_10000910

void FUN_10000910(undefined4 param_1,int param_2)

{
  if (param_2 != 0) {
    FUN_10000804();
    return;
  }
  FUN_10000918(0);
  return;
}

// FUNC 0x10000918  FUN_10000918

void FUN_10000918(void)

{
  return;
}

// FUNC 0x1000091c  FUN_1000091c

undefined8 FUN_1000091c(uint param_1,int param_2,uint param_3)

{
  return CONCAT44(param_2 << (param_3 & 0xff) | param_1 << (param_3 - 0x20 & 0xff) |
                  param_1 >> (-(param_3 - 0x20) & 0xff),param_1 << (param_3 & 0xff));
}

// FUNC 0x10000934  FUN_10000934

void FUN_10000934(int param_1,int param_2,int param_3,int param_4)

{
  if ((param_4 == 0) && (param_3 == 0)) {
    if (param_2 != 0 || param_1 != 0) {
      param_1 = -1;
      param_2 = param_1;
    }
                    /* WARNING: Could not recover jumptable at 0x10000954. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)((int)&DAT_10000958 + DAT_10000958))(param_1,param_2);
    return;
  }
  FUN_10000974(param_1);
  return;
}

// FUNC 0x10000974  FUN_10000974

undefined8 FUN_10000974(uint param_1,uint param_2,uint param_3,uint param_4,uint *param_5)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  bool bVar9;
  uint local_30;
  uint local_2c;
  
  if ((param_2 <= param_4 && param_4 != param_2) || ((param_4 == param_2 && (param_1 < param_3)))) {
    local_30 = 0;
    local_2c = 0;
    goto LAB_100009f8;
  }
  iVar1 = FUN_10000b0c(param_3,param_4);
  iVar2 = FUN_10000b0c(param_1,param_2);
  uVar4 = iVar1 - iVar2;
  uVar5 = uVar4 - 0x20;
  if ((int)uVar5 < 0) {
    uVar6 = param_4 << (uVar4 & 0xff) | param_3 >> (0x20 - uVar4 & 0xff);
    param_3 = param_3 << (uVar4 & 0xff);
    if (uVar6 <= param_2) goto LAB_100009c0;
LAB_10000a36:
    local_30 = 0;
    local_2c = 0;
  }
  else {
    uVar6 = param_3 << (uVar5 & 0xff);
    param_3 = param_3 << (uVar4 & 0xff);
    if (param_2 < uVar6) goto LAB_10000a36;
LAB_100009c0:
    if ((uVar6 == param_2) && (param_1 < param_3)) goto LAB_10000a36;
    bVar9 = param_1 < param_3;
    param_1 = param_1 - param_3;
    param_2 = (param_2 - uVar6) - (uint)bVar9;
    if ((int)uVar5 < 0) {
      local_2c = 1 >> (0x20 - uVar4 & 0xff);
    }
    else {
      local_2c = 1 << (uVar5 & 0xff);
    }
    local_30 = 1 << (uVar4 & 0xff);
  }
  if (uVar4 == 0) goto LAB_100009f8;
  uVar3 = param_3 >> 1 | uVar6 << 0x1f;
  uVar6 = uVar6 >> 1;
  uVar8 = uVar4;
  do {
    while ((uVar6 <= param_2 && ((uVar6 != param_2 || (uVar3 <= param_1))))) {
      bVar9 = param_1 < uVar3;
      uVar7 = param_1 - uVar3;
      uVar8 = uVar8 - 1;
      param_1 = uVar7 * 2 + 1;
      param_2 = ((param_2 - uVar6) - (uint)bVar9) * 2 + (uint)CARRY4(uVar7,uVar7) +
                (uint)(0xfffffffe < uVar7 * 2);
      if (uVar8 == 0) goto LAB_10000a7c;
    }
    uVar8 = uVar8 - 1;
    bVar9 = CARRY4(param_1,param_1);
    param_1 = param_1 * 2;
    param_2 = param_2 * 2 + (uint)bVar9;
  } while (uVar8 != 0);
LAB_10000a7c:
  bVar9 = CARRY4(local_30,param_1);
  uVar6 = local_30 + param_1;
  iVar1 = local_2c + param_2;
  if ((int)uVar5 < 0) {
    param_1 = param_1 >> (uVar4 & 0xff) | param_2 << (0x20 - uVar4 & 0xff);
    param_2 = param_2 >> (uVar4 & 0xff);
    if (-1 < (int)uVar5) goto LAB_10000aa0;
LAB_10000af6:
    uVar5 = param_2 << (uVar4 & 0xff) | param_1 >> (0x20 - uVar4 & 0xff);
  }
  else {
    param_1 = param_2 >> (uVar5 & 0xff);
    param_2 = param_2 >> (uVar4 & 0xff);
    if ((int)uVar5 < 0) goto LAB_10000af6;
LAB_10000aa0:
    uVar5 = param_1 << (uVar5 & 0xff);
  }
  uVar4 = param_1 << (uVar4 & 0xff);
  local_30 = uVar6 - uVar4;
  local_2c = ((iVar1 + (uint)bVar9) - uVar5) - (uint)(uVar6 < uVar4);
LAB_100009f8:
  if (param_5 != (uint *)0x0) {
    *param_5 = param_1;
    param_5[1] = param_2;
  }
  return CONCAT44(local_2c,local_30);
}

// FUNC 0x10000b0c  FUN_10000b0c

int FUN_10000b0c(undefined4 param_1,int param_2)

{
  int iVar1;
  
  if (param_2 == 0) {
    iVar1 = FUN_10000b24();
    iVar1 = iVar1 + 0x20;
  }
  else {
    iVar1 = FUN_10000b24(param_2);
  }
  return iVar1;
}

// FUNC 0x10000b24  FUN_10000b24

int FUN_10000b24(uint param_1)

{
  int iVar1;
  
  iVar1 = 0x1c;
  if (0xffff < param_1) {
    param_1 = param_1 >> 0x10;
    iVar1 = 0xc;
  }
  if (0xff < param_1) {
    param_1 = param_1 >> 8;
    iVar1 = iVar1 + -8;
  }
  if (0xf < param_1) {
    param_1 = param_1 >> 4;
    iVar1 = iVar1 + -4;
  }
  return (uint)(byte)(&LAB_10000b50)[param_1] + iVar1;
}

// FUNC 0x10000c6c  FUN_10000c6c

uint FUN_10000c6c(int param_1)

{
  uint uVar1;
  
  uVar1 = *DAT_10000c84;
  if (DAT_10000c88 < uVar1 + param_1) {
    uVar1 = 0xffffffff;
  }
  else {
    *DAT_10000c84 = uVar1 + param_1;
  }
  return uVar1;
}

// FUNC 0x10000c8c  FUN_10000c8c

void FUN_10000c8c(int param_1)

{
  int iVar1;
  uint uVar2;
  undefined4 local_c;
  
  iVar1 = FUN_10000804(*DAT_10000cdc,DAT_10000ce0);
  uVar2 = FUN_10000804(iVar1 * param_1,0x11);
  if (uVar2 < 0xc) {
    uVar2 = 0xc;
  }
  for (local_c = uVar2 - 0xc; local_c != 0; local_c = local_c + -1) {
  }
  return;
}

// FUNC 0x10000cee  FUN_10000cee

void FUN_10000cee(void)

{
  return;
}

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

// FUNC 0x10000e5a  FUN_10000e5a

void FUN_10000e5a(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 uint param_5,undefined1 param_6,uint param_7,undefined4 param_8,undefined4 param_9,
                 uint param_10)

{
  char cVar1;
  char cVar2;
  char cVar3;
  uint uVar4;
  ulonglong uVar5;
  char local_38 [36];
  
  if (param_5 == 0) {
    param_10 = param_10 & 0xffffffef;
  }
  if ((-1 < (int)(param_10 << 0x15)) || (param_5 != 0)) {
    cVar3 = 'a';
    if ((int)(param_10 << 0x1a) < 0) {
      cVar3 = 'A';
    }
    uVar4 = param_5;
    param_5 = 0;
    do {
      uVar5 = FUN_10000910(uVar4,param_7);
      cVar2 = (char)(uVar5 >> 0x20);
      cVar1 = cVar2 + cVar3 + -10;
      if (uVar5 < 0xa00000000) {
        cVar1 = cVar2 + '0';
      }
      local_38[param_5] = cVar1;
      param_5 = param_5 + 1;
    } while ((param_7 <= uVar4) && (uVar4 = (uint)uVar5, param_5 != 0x20));
  }
  FUN_10000cf0(param_1,param_2,param_3,param_4,local_38,param_5,param_6,param_7,param_8,param_9,
               param_10);
  return;
}

// FUNC 0x10000eee  FUN_10000eee

/* WARNING: Removing unreachable block (ram,0x10000f74) */

void FUN_10000eee(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 int param_5,int param_6,undefined1 param_7,undefined4 param_8,uint param_9,
                 undefined4 param_10,undefined4 param_11,undefined4 param_12,uint param_13)

{
  ulonglong uVar1;
  uint uVar2;
  char cVar3;
  char cVar4;
  int iVar5;
  ulonglong uVar6;
  int local_5c;
  char acStack_38 [36];
  
  if (param_5 == 0 && param_6 == 0) {
    param_13 = param_13 & 0xffffffef;
  }
  if ((-1 < (int)(param_13 << 0x15)) || (iVar5 = 0, param_5 != 0 || param_6 != 0)) {
    cVar3 = 'a';
    if ((int)(param_13 << 0x1a) < 0) {
      cVar3 = 'A';
    }
    local_5c = 0;
    uVar1 = CONCAT44(param_6,param_5);
    do {
      uVar2 = param_9;
      uVar6 = FUN_10000934((int)uVar1,(int)(uVar1 >> 0x20),param_9,param_10);
      cVar4 = (char)uVar2 + cVar3 + -10;
      if ((uVar2 & 0xff) < 10) {
        cVar4 = (char)uVar2 + '0';
      }
      iVar5 = local_5c + 1;
      acStack_38[local_5c] = cVar4;
    } while ((CONCAT44(param_10,param_9) <= uVar1) &&
            (local_5c = iVar5, uVar1 = uVar6, iVar5 != 0x20));
  }
  FUN_10000cf0(param_1,param_2,param_3,param_4,acStack_38,iVar5,param_7,param_9,param_11,param_12,
               param_13);
  return;
}

// FUNC 0x10000fc0  FUN_10000fc0

/* WARNING: Function: __gnu_thumb1_case_uhi replaced with injection: switch16_uhi_r0 */
/* WARNING (jumptable): Removing unreachable block (ram,0x10001170) */
/* WARNING: Removing unreachable block (ram,0x10001170) */

uint FUN_10000fc0(code *param_1,int param_2,uint param_3,byte *param_4,uint *param_5)

{
  byte bVar1;
  uint uVar2;
  byte *pbVar3;
  uint uVar4;
  uint uVar5;
  undefined4 uVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  char *pcVar10;
  bool bVar11;
  uint local_54;
  byte *local_50;
  uint local_4c;
  code *local_48;
  uint local_40;
  char *local_3c;
  
  local_48 = param_1;
  if (param_2 == 0) {
    local_48 = DAT_1000128c;
  }
  uVar2 = 0;
  local_50 = param_4;
LAB_10000ff2:
  do {
    while( true ) {
      bVar1 = *local_50;
      if (bVar1 == 0) {
        uVar4 = uVar2;
        if (param_3 <= uVar2) {
          uVar4 = param_3 - 1;
        }
        (*local_48)(0,param_2,uVar4,param_3);
        return uVar2;
      }
      local_50 = local_50 + 1;
      if (bVar1 == 0x25) break;
      (*local_48)(bVar1,param_2,uVar2,param_3);
      uVar2 = uVar2 + 1;
    }
    uVar4 = 0;
LAB_10001026:
    while( true ) {
      uVar5 = (uint)*local_50;
      pbVar3 = local_50 + 1;
      if (uVar5 != 0x2b) break;
      uVar5 = 4;
LAB_1000104e:
      uVar4 = uVar4 | uVar5;
      local_50 = pbVar3;
    }
    if (0x2b < uVar5) {
      if (uVar5 == 0x2d) {
        uVar5 = 2;
        goto LAB_1000104e;
      }
      if (uVar5 != 0x30) goto LAB_1000103c;
      uVar4 = uVar4 | 1;
      local_50 = pbVar3;
      goto LAB_10001026;
    }
    if (uVar5 == 0x20) {
      uVar4 = uVar4 | 8;
      local_50 = pbVar3;
      goto LAB_10001026;
    }
    if (uVar5 == 0x23) {
      uVar5 = 0x10;
      goto LAB_1000104e;
    }
LAB_1000103c:
    if (uVar5 - 0x30 < 10) {
      local_54 = 0;
      while( true ) {
        if (9 < *local_50 - 0x30) break;
        local_54 = (uint)*local_50 + local_54 * 10 + -0x30;
        local_50 = local_50 + 1;
      }
    }
    else {
      local_54 = 0;
      if (uVar5 == 0x2a) {
        local_54 = *param_5;
        param_5 = param_5 + 1;
        local_50 = pbVar3;
        if ((int)local_54 < 0) {
          uVar4 = uVar4 | 2;
          local_54 = -local_54;
        }
      }
    }
    local_4c = 0;
    pbVar3 = local_50;
    if (*local_50 == 0x2e) {
      uVar4 = uVar4 | 0x400;
      pbVar3 = local_50 + 1;
      if (local_50[1] - 0x30 < 10) {
        while( true ) {
          if (9 < *pbVar3 - 0x30) break;
          local_4c = (uint)*pbVar3 + local_4c * 10 + -0x30;
          pbVar3 = pbVar3 + 1;
        }
      }
      else if (local_50[1] == 0x2a) {
        local_4c = *param_5;
        param_5 = param_5 + 1;
        local_4c = local_4c & (int)~local_4c >> 0x1f;
        pbVar3 = local_50 + 2;
      }
    }
    local_50 = pbVar3;
    bVar1 = *local_50;
    if (bVar1 == 0x6c) {
      if (local_50[1] != 0x6c) {
LAB_10001134:
        uVar5 = 0x100;
        goto LAB_10001158;
      }
      uVar5 = 0x300;
LAB_10001146:
      uVar4 = uVar4 | uVar5;
      local_50 = local_50 + 2;
    }
    else if (bVar1 < 0x6d) {
      if (bVar1 == 0x68) {
        if (local_50[1] == 0x68) {
          uVar5 = 0xc0;
          goto LAB_10001146;
        }
        uVar5 = 0x80;
      }
      else {
        if (bVar1 != 0x6a) goto LAB_100010f0;
        uVar5 = 0x200;
      }
LAB_10001158:
      uVar4 = uVar4 | uVar5;
      local_50 = local_50 + 1;
    }
    else if ((bVar1 == 0x74) || (bVar1 == 0x7a)) goto LAB_10001134;
LAB_100010f0:
    bVar1 = *local_50;
    local_50 = local_50 + 1;
    if (0x78 < bVar1) {
switchD_10001170_caseD_65:
      (*local_48)(bVar1,param_2,uVar2,param_3);
      uVar2 = uVar2 + 1;
      goto LAB_10000ff2;
    }
    if (bVar1 < 0x62) {
      if ((bVar1 != 0x25) && (bVar1 == 0x58)) {
        uVar4 = uVar4 | 0x20;
        uVar6 = 0x10;
        goto LAB_100011c0;
      }
      goto switchD_10001170_caseD_65;
    }
    switch(bVar1) {
    case 0x62:
    case 100:
    case 0x69:
    case 0x6f:
    case 0x75:
    case 0x78:
      if (bVar1 == 0x78) {
        uVar6 = 0x10;
LAB_100011c0:
        uVar4 = uVar4 & 0xfffffff3;
      }
      else {
        if (bVar1 == 0x6f) {
          uVar6 = 8;
          goto LAB_100011c0;
        }
        if (bVar1 == 0x62) {
          uVar6 = 2;
          goto LAB_100011c0;
        }
        uVar4 = uVar4 & 0xffffffef;
        uVar6 = 10;
        if ((bVar1 != 0x69) && (bVar1 != 100)) goto LAB_100011c0;
      }
      if ((int)(uVar4 << 0x15) < 0) {
        uVar4 = uVar4 & 0xfffffffe;
      }
      if ((bVar1 == 0x69) || (bVar1 == 100)) {
        if ((uVar4 & 0x200) == 0) {
          if ((int)(uVar4 << 0x17) < 0) {
            uVar5 = *param_5;
          }
          else {
            uVar5 = *param_5;
            if ((int)(uVar4 << 0x19) < 0) {
              uVar5 = uVar5 & 0xff;
            }
            else if ((int)(uVar4 << 0x18) < 0) {
              uVar5 = (uint)(short)uVar5;
            }
          }
          uVar7 = uVar5 >> 0x1f;
          uVar5 = uVar5 + ((int)uVar5 >> 0x1f) ^ (int)uVar5 >> 0x1f;
          goto LAB_100012a8;
        }
        param_5 = (uint *)((int)param_5 + 7U & 0xfffffff8);
        uVar4 = param_5[1];
        uVar7 = uVar4 >> 0x1f;
        uVar8 = (int)uVar4 >> 0x1f;
        uVar5 = (uVar8 ^ *param_5) - uVar8;
        uVar4 = ((uVar8 ^ uVar4) - uVar8) - (uint)((uVar8 ^ *param_5) < uVar8);
      }
      else {
        if ((uVar4 & 0x200) == 0) {
          if ((int)(uVar4 << 0x17) < 0) {
            uVar5 = *param_5;
            uVar7 = 0;
          }
          else {
            uVar5 = *param_5;
            if ((int)(uVar4 << 0x19) < 0) {
              uVar5 = uVar5 & 0xff;
            }
            else if ((int)(uVar4 << 0x18) < 0) {
              uVar5 = uVar5 & 0xffff;
            }
            uVar7 = 0;
          }
LAB_100012a8:
          param_5 = param_5 + 1;
          uVar2 = FUN_10000e5a(local_48,param_2,uVar2,param_3,uVar5,uVar7,uVar6,local_4c,local_54,
                               uVar4);
          break;
        }
        param_5 = (uint *)((int)param_5 + 7U & 0xfffffff8);
        uVar7 = 0;
        uVar5 = *param_5;
        uVar4 = param_5[1];
      }
      param_5 = param_5 + 2;
      uVar2 = FUN_10000eee(local_48,param_2,uVar2,param_3,uVar5,uVar4,uVar7);
      break;
    case 99:
      uVar7 = 1;
      uVar5 = uVar2;
      if ((uVar4 & 2) == 0) {
        while ((uVar5 + 1) - uVar2 < local_54) {
          (*local_48)(0x20,param_2,uVar5,param_3);
          uVar5 = uVar5 + 1;
        }
        iVar9 = 0;
        if (local_54 != 0) {
          iVar9 = local_54 - 1;
        }
        uVar5 = uVar2 + iVar9;
        uVar7 = 2;
        if (local_54 != 0) {
          uVar7 = local_54 + 1;
        }
      }
      uVar8 = *param_5;
      param_5 = param_5 + 1;
      uVar2 = uVar5 + 1;
      (*local_48)(uVar8 & 0xff,param_2,uVar5,param_3);
      uVar5 = uVar2;
      local_40 = uVar7;
      if ((uVar4 & 2) != 0) {
        for (; local_40 < local_54; local_40 = local_40 + 1) {
          (*local_48)(0x20,param_2,uVar5,param_3);
          uVar5 = uVar5 + 1;
        }
        iVar9 = 0;
        if (uVar7 <= local_54) {
          iVar9 = local_54 - uVar7;
        }
        uVar2 = uVar2 + iVar9;
      }
      break;
    default:
      goto switchD_10001170_caseD_65;
    case 0x70:
      uVar5 = *param_5;
      param_5 = param_5 + 1;
      uVar2 = FUN_10000e5a(local_48,param_2,uVar2,param_3,uVar5,0,0x10,local_4c,8,uVar4 | 0x21);
      break;
    case 0x73:
      local_3c = (char *)*param_5;
      param_5 = param_5 + 1;
      if (local_3c == (char *)0x0) {
        local_3c = DAT_1000149c;
      }
      uVar5 = local_4c;
      if (local_4c == 0) {
        uVar5 = 0xffffffff;
      }
      for (pcVar10 = local_3c; (*pcVar10 != '\0' && (local_3c + uVar5 != pcVar10));
          pcVar10 = pcVar10 + 1) {
      }
      uVar5 = (int)pcVar10 - (int)local_3c;
      if (((uVar4 & 0x400) != 0) && (local_4c < uVar5)) {
        uVar5 = local_4c;
      }
      uVar7 = uVar2;
      local_40 = uVar2;
      if ((uVar4 & 2) == 0) {
        for (; uVar7 + (uVar5 - uVar2) < local_54; uVar7 = uVar7 + 1) {
          (*local_48)(0x20,param_2,uVar7,param_3);
        }
        iVar9 = 0;
        if (uVar5 <= local_54) {
          iVar9 = local_54 - uVar5;
        }
        local_40 = uVar2 + iVar9;
        uVar5 = iVar9 + uVar5 + 1;
        uVar2 = local_40;
      }
      while ((local_3c[local_40 - uVar2] != '\0' &&
             (((uVar4 & 0x400) == 0 || (bVar11 = local_4c != 0, local_4c = local_4c - 1, bVar11)))))
      {
        (*local_48)(local_3c[local_40 - uVar2],param_2,local_40,param_3);
        local_40 = local_40 + 1;
      }
      uVar2 = local_40;
      if ((uVar4 & 2) != 0) {
        for (; uVar2 + (uVar5 - local_40) < local_54; uVar2 = uVar2 + 1) {
          (*local_48)(0x20,param_2,uVar2,param_3);
        }
        iVar9 = 0;
        if (uVar5 <= local_54) {
          iVar9 = local_54 - uVar5;
        }
        uVar2 = local_40 + iVar9;
      }
    }
  } while( true );
}

// FUNC 0x100014a0  FUN_100014a0

void FUN_100014a0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uStack_20;
  undefined4 *local_1c;
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  local_1c = &uStack_c;
  uStack_20 = param_3;
  uStack_c = param_2;
  uStack_8 = param_3;
  uStack_4 = param_4;
  FUN_10000fc0(DAT_100014c0,&uStack_20,0xffffffff,param_1,local_1c,param_2);
  return;
}

// FUNC 0x10001554  FUN_10001554

uint FUN_10001554(void)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  byte *pbVar4;
  char cVar5;
  
  uVar3 = 0xffffffff;
  pbVar4 = DAT_10001588;
  do {
    bVar1 = *pbVar4;
    pbVar4 = pbVar4 + 1;
    cVar5 = '\b';
    uVar2 = uVar3 ^ (uint)bVar1 << 0x18;
    do {
      uVar3 = uVar2 << 1;
      if ((int)uVar2 < 0) {
        uVar3 = uVar3 ^ DAT_1000158c;
      }
      cVar5 = cVar5 + -1;
      uVar2 = uVar3;
    } while (cVar5 != '\0');
  } while (pbVar4 != DAT_10001590);
  return ~uVar3;
}

// FUNC 0x10001614  FUN_10001614

void FUN_10001614(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = DAT_10001628;
  *(undefined4 *)(DAT_10001628 + 0x10) = param_1;
  *(undefined4 *)(iVar1 + 0x14) = param_2;
  *(undefined4 *)(iVar1 + 0x18) = param_3;
  uVar2 = FUN_10001554();
  *(undefined4 *)(iVar1 + 0x1c) = uVar2;
  return;
}

// FUNC 0x100018a8  FUN_100018a8

void FUN_100018a8(undefined4 *param_1,undefined4 param_2)

{
  do {
  } while ((param_1[6] & 0x20) != 0);
  *param_1 = param_2;
  return;
}

// FUNC 0x10001944  FUN_10001944

int FUN_10001944(int param_1)

{
  return param_1 * 0x14 + DAT_10001950;
}

// FUNC 0x10001954  FUN_10001954

int FUN_10001954(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = 0;
  iVar3 = DAT_1000197c;
  do {
    iVar1 = FUN_10000740(param_1,*(undefined4 *)(iVar3 + 4));
    if (iVar1 == 0) {
      return (int)(char)iVar2;
    }
    iVar2 = iVar2 + 1;
    iVar3 = iVar3 + 0x14;
  } while (iVar2 != 0x10);
  return -1;
}

// FUNC 0x10001980  FUN_10001980

int FUN_10001980(int param_1,int param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  iVar1 = DAT_100019c8 + param_1 * 0x14;
  if (*(uint *)(iVar1 + 0xc) < (uint)(param_3 + param_2)) {
    iVar1 = -1;
  }
  else {
    uVar2 = param_2 + *(int *)(iVar1 + 8);
    for (uVar3 = uVar2 & 0xfffff000; uVar3 <= (param_3 + -1 + uVar2 & 0xfffff000);
        uVar3 = uVar3 + 0x1000) {
      iVar1 = FUN_10004e80(DAT_100019cc,uVar3);
      if (iVar1 != 0) {
        return iVar1;
      }
    }
    iVar1 = 0;
  }
  return iVar1;
}

// FUNC 0x100019d0  flash_write

/* flash_write(region, offset, data, len) */

undefined4 flash_write(int param_1,int *param_2,int param_3,int param_4)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  
  iVar1 = flash_status();
  if ((param_2 != (int *)0x0) && (param_3 != 0)) {
    iVar3 = DAT_10001a68 + param_1 * 0x14;
    if ((uint)(*param_2 + param_4) <= *(uint *)(iVar3 + 0xc)) {
      uVar2 = *param_2 + *(int *)(iVar3 + 8);
      uVar4 = param_4 + uVar2;
      if (iVar1 != 0) {
        flash_end();
      }
      for (iVar3 = param_4; iVar3 != 0; iVar3 = iVar3 - iVar5) {
        iVar5 = iVar3;
        if (uVar2 >> 8 < uVar4 >> 8) {
          iVar5 = 0x100 - (uVar2 & 0xff);
        }
        flash_write_page(uVar2,iVar5,param_3);
        param_3 = param_3 + iVar5;
        uVar2 = uVar2 + iVar5;
      }
      if (iVar1 != 0) {
        flash_begin();
      }
      *param_2 = param_4 + *param_2;
      return 0;
    }
  }
  return 0xffffffff;
}

// FUNC 0x10001a6c  FUN_10001a6c

undefined4 FUN_10001a6c(int param_1,int *param_2,int param_3,int param_4)

{
  int iVar1;
  
  if ((param_2 != (int *)0x0) && (param_3 != 0)) {
    iVar1 = DAT_10001ab8 + param_1 * 0x14;
    if (((uint)(*param_2 + param_4) <= *(uint *)(iVar1 + 0xc)) &&
       (0x7ffffff < param_3 + 0xf0000000U)) {
      iVar1 = *(int *)(iVar1 + 8);
      FUN_100049ac(param_3,*param_2 + iVar1,param_4,iVar1,param_4);
      *param_2 = *param_2 + param_4;
      return 0;
    }
  }
  return 0xffffffff;
}

// FUNC 0x10001abc  FUN_10001abc

void FUN_10001abc(void)

{
  int iVar1;
  
  iVar1 = DAT_10001ad0;
  *(undefined4 *)(DAT_10001ad0 + 0xc00) = DAT_10001ad4;
  *(undefined4 *)(iVar1 + 0xc) = 1;
  *(undefined4 *)(iVar1 + 0xc00) = DAT_10001ad8;
  return;
}

// FUNC 0x10001b54  FUN_10001b54

uint FUN_10001b54(byte *param_1,int param_2)

{
  byte *pbVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  
  uVar4 = 0;
  pbVar1 = param_1 + param_2;
  for (; pbVar1 != param_1; param_1 = param_1 + 1) {
    iVar2 = 8;
    uVar4 = uVar4 ^ (uint)*param_1 << 8;
    do {
      uVar3 = uVar4 << 1;
      if ((short)uVar4 < 0) {
        uVar3 = uVar3 ^ DAT_10001b8c;
      }
      uVar4 = uVar3 & 0xffff;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
  }
  FUN_100014a0(DAT_10001b90,uVar4);
  return uVar4;
}

// FUNC 0x10001b94  FUN_10001b94

void FUN_10001b94(undefined4 *param_1)

{
  int iVar1;
  
  iVar1 = FUN_100036c4(2,param_1,0x1c);
  if (iVar1 == 0) {
    FUN_10001614(*param_1,param_1[2],param_1[3]);
  }
  return;
}

// FUNC 0x10001bb4  FUN_10001bb4

void FUN_10001bb4(uint param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  bool bVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  
  uVar3 = param_1 & 0xfffff000;
  uVar5 = (param_1 + param_2) - uVar3;
  while( true ) {
    if (uVar5 == 0) {
      return;
    }
    if (((uVar3 & 0xffff) == 0) && (0xf000 < (int)uVar5)) {
      uVar4 = 0x10000;
      uVar2 = DAT_10001c24;
    }
    else if (((uVar3 & 0x7fff) == 0) && (0x7000 < (int)uVar5)) {
      uVar4 = 0x8000;
      uVar2 = DAT_10001c28;
    }
    else {
      uVar4 = 0x1000;
      uVar2 = DAT_10001c20;
    }
    iVar6 = 0;
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      iVar6 = isIRQinterruptsEnabled();
    }
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      enableIRQinterrupts(1);
    }
    FUN_10004e80(uVar2,uVar3,param_3,1,param_4);
    if (iVar6 == 0) {
      bVar1 = (bool)isCurrentModePrivileged();
      if (bVar1) {
        enableIRQinterrupts(0);
      }
    }
    else {
      bVar1 = (bool)isCurrentModePrivileged();
      if (bVar1) {
        enableIRQinterrupts(1);
      }
    }
    uVar3 = uVar3 + uVar4;
    if (uVar5 <= uVar4) break;
    uVar5 = uVar5 - uVar4;
  }
  return;
}

// FUNC 0x10001c70  FUN_10001c70

undefined4 FUN_10001c70(uint param_1,int param_2,int param_3)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  undefined4 local_24;
  
  iVar2 = flash_status();
  uVar3 = param_3 + param_1;
  if (iVar2 != 0) {
    flash_end();
  }
  local_24 = param_2;
  for (; param_3 != 0; param_3 = param_3 - iVar4) {
    iVar4 = param_3;
    if (param_1 >> 8 < uVar3 >> 8) {
      iVar4 = 0x100 - (param_1 & 0xff);
    }
    iVar5 = 0;
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      iVar5 = isIRQinterruptsEnabled();
    }
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      enableIRQinterrupts(1);
    }
    flash_write_page(param_1,iVar4,local_24,1);
    if (iVar5 == 0) {
      bVar1 = (bool)isCurrentModePrivileged();
      if (bVar1) {
        enableIRQinterrupts(0);
      }
    }
    else {
      bVar1 = (bool)isCurrentModePrivileged();
      if (bVar1) {
        enableIRQinterrupts(1);
      }
    }
    param_1 = param_1 + iVar4;
    local_24 = local_24 + iVar4;
  }
  if (iVar2 != 0) {
    flash_begin();
  }
  return 0;
}

// FUNC 0x10001ce6  FUN_10001ce6

undefined4 FUN_10001ce6(undefined4 param_1,undefined4 param_2)

{
  FUN_100049ac(param_2,param_1);
  return 0;
}

// FUNC 0x10001d88  FUN_10001d88

void FUN_10001d88(int param_1,uint *param_2)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  int local_120;
  int local_11c;
  undefined1 auStack_118 [260];
  
  uVar2 = DAT_10001ec4;
  if (*(int *)(param_1 + 0x40) == 1) {
LAB_10001ebc:
    FUN_100014a0(uVar2);
  }
  else {
    uVar4 = *(uint *)(param_1 + 0x44);
    if (uVar4 - 2 < 2) {
      FUN_100014a0(DAT_10001ec8);
      uVar2 = DAT_10001ecc;
      if (*(int *)(param_1 + 0x44) == 3) {
        FUN_10001bb4(DAT_10001ed0,*(undefined4 *)(param_1 + 0x5c));
        FUN_100014a0(uVar2);
        FUN_100014a0(DAT_10001ed4);
        iVar1 = FUN_10002030(*(undefined4 *)(param_1 + 0x48),DAT_10001ed0,
                             *(undefined4 *)(param_1 + 0x5c));
        if (iVar1 != 0) {
          FUN_100014a0(DAT_10001ed8);
          DataSynchronizationBarrier(0xf);
          *(undefined4 *)(DAT_10001edc + 0xc) = DAT_10001ee0;
          DataSynchronizationBarrier(0xf);
          do {
                    /* WARNING: Do nothing block with infinite loop */
          } while( true );
        }
      }
      else {
        FUN_10001bb4(DAT_10001ed0,*(undefined4 *)(param_1 + 0x5c));
        FUN_100014a0(uVar2);
        FUN_100014a0(DAT_10001ee4);
        local_120 = *(int *)(param_1 + 0x48);
        uVar4 = *(uint *)(param_1 + 0x5c);
        local_11c = DAT_10001ed0;
        for (; uVar4 != 0; uVar4 = uVar4 - uVar3) {
          uVar3 = 0x100;
          if (uVar4 < 0x100) {
            uVar3 = uVar4;
          }
          FUN_100049ac(auStack_118,local_120,uVar3);
          FUN_10001c70(local_11c,auStack_118,uVar3);
          local_120 = local_120 + uVar3;
          local_11c = local_11c + uVar3;
        }
      }
      uVar4 = FUN_10001b54(DAT_10001ed0,*(undefined4 *)(param_1 + 0x5c));
      if ((*(uint *)(param_1 + 0x60) & 0xffff) != uVar4) {
        FUN_100014a0(DAT_10001ef0);
        DataSynchronizationBarrier(0xf);
        *(undefined4 *)(DAT_10001edc + 0xc) = DAT_10001ee0;
        DataSynchronizationBarrier(0xf);
        do {
                    /* WARNING: Do nothing block with infinite loop */
        } while( true );
      }
      FUN_100014a0(DAT_10001ee8);
      uVar4 = 0;
      uVar3 = *(uint *)(param_1 + 0x48);
      *param_2 = 0;
      param_2[2] = uVar3;
      param_2[3] = *(uint *)(param_1 + 0x5c);
LAB_10001e28:
      param_2[1] = uVar4;
    }
    else {
      uVar2 = DAT_10001efc;
      if (1 < uVar4) goto LAB_10001ebc;
      *param_2 = uVar4;
      param_2[2] = *(uint *)(param_1 + 0x48);
      param_2[3] = *(uint *)(param_1 + 0x5c);
      param_2[1] = 0;
      param_2[4] = 0;
      if (*(int *)(param_1 + 0x68) == DAT_10001ef4) {
        FUN_100014a0(DAT_10001ef8);
        uVar4 = *(uint *)(param_1 + 0x68);
        goto LAB_10001e28;
      }
    }
    uVar3 = *(uint *)(param_1 + 100);
    uVar4 = *(uint *)(param_1 + 0x4c);
    param_2[4] = uVar3;
    param_2[5] = uVar4;
    param_2[6] = *(uint *)(param_1 + 0x50);
    FUN_100014a0(DAT_10001eec,*param_2,param_2[2],param_2[3],param_2[1],uVar3);
    FUN_10001b94(param_2);
  }
  return;
}

// FUNC 0x10002030  FUN_10002030

void FUN_10002030(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  *DAT_10002048 = param_1;
  uVar1 = DAT_10002050;
  *DAT_1000204c = param_2;
  uVar2 = DAT_10002058;
  *DAT_10002054 = param_3;
  FUN_100034f8(uVar1,uVar2);
  return;
}

// FUNC 0x1000205c  FUN_1000205c

void FUN_1000205c(void)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  
  iVar2 = DAT_10002090;
  uVar1 = DAT_1000208c;
  uVar4 = 0;
  do {
    iVar3 = 8;
    uVar5 = uVar4;
    do {
      iVar3 = iVar3 + -1;
      uVar5 = -(uVar5 & 1) & uVar1 ^ uVar5 >> 1;
    } while (iVar3 != 0);
    iVar3 = uVar4 * 4;
    uVar4 = uVar4 + 1;
    *(uint *)(iVar2 + iVar3) = uVar5;
  } while (uVar4 != 0x100);
  return;
}

// FUNC 0x10002094  FUN_10002094

uint FUN_10002094(byte *param_1,int param_2,uint param_3)

{
  byte *pbVar1;
  
  param_3 = ~param_3;
  pbVar1 = param_1 + param_2;
  for (; param_1 != pbVar1; param_1 = param_1 + 1) {
    param_3 = param_3 >> 8 ^ *(uint *)(((uint)*param_1 ^ param_3 & 0xff) * 4 + DAT_100020bc);
  }
  return ~param_3;
}

// FUNC 0x100020c0  FUN_100020c0

undefined8 FUN_100020c0(uint *param_1,ushort *param_2,int param_3)

{
  ushort uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  ushort *puVar5;
  uint uVar6;
  uint uVar7;
  
  if (*param_1 < 0x1000000) {
    *param_1 = *param_1 << 8;
    uVar4 = param_1[4];
    param_1[4] = uVar4 + 1;
    param_1[1] = (uint)*(byte *)(param_1[3] + uVar4) + param_1[1] * 0x100;
  }
  uVar1 = *param_2;
  uVar4 = (uint)uVar1 * (*param_1 >> 0xb);
  uVar6 = param_1[1];
  if (uVar4 < uVar6 || uVar4 - uVar6 == 0) {
    uVar3 = *param_1 - uVar4;
    *param_1 = uVar3;
    param_1[1] = uVar6 - uVar4;
    *param_2 = uVar1 - (uVar1 >> 5);
    if (uVar3 < 0x1000000) {
      *param_1 = uVar3 * 0x100;
      uVar3 = param_1[4];
      param_1[4] = uVar3 + 1;
      param_1[1] = (uint)*(byte *)(param_1[3] + uVar3) + (uVar6 - uVar4) * 0x100;
    }
    uVar1 = param_2[1];
    uVar6 = (uint)uVar1 * (*param_1 >> 0xb);
    uVar4 = param_1[1];
    if (uVar6 < uVar4 || uVar6 - uVar4 == 0) {
      *param_1 = *param_1 - uVar6;
      param_1[1] = uVar4 - uVar6;
      param_2[1] = uVar1 - (uVar1 >> 5);
      iVar2 = 0x204;
      param_1[0x19] = 0x12;
      uVar4 = 0x100;
      goto LAB_1000210a;
    }
    iVar2 = param_3 * 0x10 + 0x104;
    *param_1 = uVar6;
    param_2[1] = uVar1 + (short)((int)(0x800 - (uint)uVar1) >> 5);
    uVar6 = 10;
  }
  else {
    uVar6 = 2;
    iVar2 = param_3 * 0x10 + 4;
    *param_1 = uVar4;
    *param_2 = uVar1 + (short)((int)(0x800 - (uint)uVar1) >> 5);
  }
  uVar4 = 8;
  param_1[0x19] = uVar6;
LAB_1000210a:
  uVar6 = 1;
  do {
    puVar5 = (ushort *)((int)param_2 + uVar6 * 2 + iVar2);
    if (*param_1 < 0x1000000) {
      *param_1 = *param_1 << 8;
      uVar3 = param_1[4];
      param_1[4] = uVar3 + 1;
      param_1[1] = (uint)*(byte *)(param_1[3] + uVar3) + param_1[1] * 0x100;
    }
    uVar7 = param_1[1];
    uVar1 = *puVar5;
    uVar3 = (uint)uVar1 * (*param_1 >> 0xb);
    uVar6 = uVar6 * 2;
    if (uVar3 < uVar7 || uVar3 - uVar7 == 0) {
      *param_1 = *param_1 - uVar3;
      uVar6 = uVar6 + 1;
      param_1[1] = uVar7 - uVar3;
      *puVar5 = uVar1 - (uVar1 >> 5);
    }
    else {
      *param_1 = uVar3;
      *puVar5 = uVar1 + (short)((int)(0x800 - (uint)uVar1) >> 5);
    }
  } while (uVar6 < uVar4);
  param_1[0x19] = (param_1[0x19] - uVar4) + uVar6;
  return CONCAT44(uVar7,param_1);
}

// FUNC 0x100021ea  FUN_100021ea

undefined4 FUN_100021ea(int *param_1,uint *param_2,uint param_3)

{
  undefined1 *puVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  
  uVar3 = *param_2;
  uVar6 = param_1[2];
  uVar5 = param_1[4] - uVar6;
  if (uVar3 < param_1[4] - uVar6) {
    uVar5 = uVar3;
  }
  *param_2 = uVar3 - uVar5;
  iVar4 = ~param_3 + uVar6;
  if (uVar6 <= param_3) {
    iVar4 = iVar4 + param_1[5];
  }
  do {
    iVar2 = param_1[2];
    param_1[2] = iVar2 + 1;
    puVar1 = (undefined1 *)(*param_1 + iVar4);
    iVar4 = iVar4 + 1;
    *(undefined1 *)(*param_1 + iVar2) = *puVar1;
    if (iVar4 == param_1[5]) {
      iVar4 = 0;
    }
    uVar5 = uVar5 - 1;
  } while (uVar5 != 0);
  if ((uint)param_1[3] < (uint)param_1[2]) {
    param_1[3] = param_1[2];
  }
  return 1;
}

// FUNC 0x10002234  FUN_10002234

undefined4 FUN_10002234(uint *param_1)

{
  ushort uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  byte bVar8;
  undefined1 uVar9;
  uint uVar10;
  int iVar11;
  int iVar12;
  ushort *puVar13;
  uint uVar14;
  uint local_2c;
  
  if ((((param_1[8] < param_1[10]) && (param_1[0x19] != 0)) && (param_1[0x14] < param_1[9])) &&
     (param_1[0x14] < param_1[0xc])) {
    FUN_100021ea(param_1 + 6,param_1 + 0x19);
  }
  do {
    while( true ) {
      uVar5 = param_1[8];
      uVar10 = *param_1;
      if ((param_1[10] <= uVar5) || (uVar6 = param_1[4], param_1[5] < uVar6)) {
        if (0xffffff < uVar10) {
          return 1;
        }
        *param_1 = uVar10 << 8;
        uVar5 = param_1[4];
        param_1[4] = uVar5 + 1;
        param_1[1] = (uint)*(byte *)(param_1[3] + uVar5) + param_1[1] * 0x100;
        return 1;
      }
      uVar2 = param_1[0x1c] & uVar5;
      uVar3 = (uint)(byte)param_1[0x18];
      if (uVar10 < 0x1000000) {
        *param_1 = uVar10 << 8;
        param_1[4] = uVar6 + 1;
        param_1[1] = (uint)*(byte *)(param_1[3] + uVar6) + param_1[1] * 0x100;
      }
      iVar4 = uVar3 * 0x10 + uVar2;
      puVar13 = (ushort *)((int)param_1 + iVar4 * 2 + 0x74);
      uVar1 = *puVar13;
      uVar6 = (uint)uVar1 * (*param_1 >> 0xb);
      uVar10 = param_1[1];
      if (uVar6 < uVar10 || uVar6 - uVar10 == 0) break;
      *param_1 = uVar6;
      *puVar13 = uVar1 + (short)((int)(0x800 - (uint)uVar1) >> 5);
      iVar4 = uVar5 - 1;
      if (uVar5 == 0) {
        iVar4 = param_1[0xb] - 1;
      }
      uVar10 = param_1[6];
      local_2c = param_1[9];
      uVar6 = 0;
      if (local_2c != 0) {
        uVar6 = (uint)*(byte *)(uVar10 + iVar4);
      }
      iVar4 = (((param_1[0x1b] & uVar5) << (param_1[0x1a] & 0xff)) +
              (uVar6 >> (8 - param_1[0x1a] & 0xff))) * 0x600 + 0xee0;
      if (uVar3 < 7) {
        uVar2 = 1;
        do {
          puVar13 = (ushort *)((int)param_1 + uVar2 * 2 + iVar4);
          if (*param_1 < 0x1000000) {
            *param_1 = *param_1 << 8;
            uVar6 = param_1[4];
            param_1[4] = uVar6 + 1;
            param_1[1] = (uint)*(byte *)(param_1[3] + uVar6) + param_1[1] * 0x100;
          }
          uVar1 = *puVar13;
          uVar6 = (uint)uVar1 * (*param_1 >> 0xb);
          uVar3 = param_1[1];
          uVar2 = uVar2 * 2;
          if (uVar6 < uVar3 || uVar6 - uVar3 == 0) {
            param_1[1] = uVar3 - uVar6;
            *param_1 = *param_1 - uVar6;
            uVar2 = uVar2 + 1;
            *puVar13 = uVar1 - (uVar1 >> 5);
          }
          else {
            *param_1 = uVar6;
            *puVar13 = uVar1 + (short)((int)(0x800 - (uint)uVar1) >> 5);
          }
        } while (uVar2 < 0x100);
      }
      else {
        iVar11 = (uVar5 - 1) - param_1[0x14];
        if (uVar5 <= param_1[0x14]) {
          iVar11 = iVar11 + param_1[0xb];
        }
        if (local_2c != 0) {
          local_2c = (uint)*(byte *)(uVar10 + iVar11);
        }
        uVar2 = 1;
        uVar6 = 0x100;
        do {
          local_2c = local_2c << 1;
          uVar3 = uVar6 & local_2c;
          puVar13 = (ushort *)((int)param_1 + (uVar6 + uVar2 + uVar3) * 2 + iVar4);
          if (*param_1 < 0x1000000) {
            *param_1 = *param_1 << 8;
            uVar7 = param_1[4];
            param_1[4] = uVar7 + 1;
            param_1[1] = (uint)*(byte *)(param_1[3] + uVar7) + param_1[1] * 0x100;
          }
          uVar14 = param_1[1];
          uVar1 = *puVar13;
          uVar7 = (uint)uVar1 * (*param_1 >> 0xb);
          uVar2 = uVar2 * 2;
          if (uVar7 < uVar14 || uVar7 - uVar14 == 0) {
            uVar2 = uVar2 + 1;
            *param_1 = *param_1 - uVar7;
            param_1[1] = uVar14 - uVar7;
            *puVar13 = uVar1 - (uVar1 >> 5);
          }
          else {
            *param_1 = uVar7;
            *puVar13 = uVar1 + (short)((int)(0x800 - (uint)uVar1) >> 5);
            uVar3 = uVar6 & ~uVar3;
          }
          uVar6 = uVar3;
        } while (uVar2 < 0x100);
      }
      param_1[8] = uVar5 + 1;
      *(char *)(uVar10 + uVar5) = (char)uVar2;
      if (param_1[9] < param_1[8]) {
        param_1[9] = param_1[8];
      }
      bVar8 = (byte)param_1[0x18];
      if (bVar8 < 4) {
        bVar8 = 0;
      }
      else if (bVar8 < 10) {
        bVar8 = bVar8 - 3;
      }
      else {
        bVar8 = bVar8 - 6;
      }
      *(byte *)(param_1 + 0x18) = bVar8;
    }
    uVar5 = *param_1 - uVar6;
    *param_1 = uVar5;
    param_1[1] = uVar10 - uVar6;
    *puVar13 = uVar1 - (uVar1 >> 5);
    if (uVar5 < 0x1000000) {
      *param_1 = uVar5 * 0x100;
      uVar5 = param_1[4];
      param_1[4] = uVar5 + 1;
      param_1[1] = (uint)*(byte *)(param_1[3] + uVar5) + (uVar10 - uVar6) * 0x100;
    }
    uVar1 = *(ushort *)((int)param_1 + uVar3 * 2 + 500);
    uVar10 = (uint)uVar1 * (*param_1 >> 0xb);
    uVar5 = param_1[1];
    if (uVar10 < uVar5 || uVar10 - uVar5 == 0) {
      uVar6 = *param_1 - uVar10;
      *param_1 = uVar6;
      param_1[1] = uVar5 - uVar10;
      *(ushort *)((int)param_1 + uVar3 * 2 + 500) = uVar1 - (uVar1 >> 5);
      if (uVar6 < 0x1000000) {
        *param_1 = uVar6 * 0x100;
        uVar6 = param_1[4];
        param_1[4] = uVar6 + 1;
        param_1[1] = (uint)*(byte *)(param_1[3] + uVar6) + (uVar5 - uVar10) * 0x100;
      }
      uVar1 = *(ushort *)((int)param_1 + uVar3 * 2 + 0x20c);
      uVar5 = (uint)uVar1 * (*param_1 >> 0xb);
      uVar10 = param_1[1];
      if (uVar5 < uVar10 || uVar5 - uVar10 == 0) {
        uVar6 = *param_1 - uVar5;
        *param_1 = uVar6;
        param_1[1] = uVar10 - uVar5;
        *(ushort *)((int)param_1 + uVar3 * 2 + 0x20c) = uVar1 - (uVar1 >> 5);
        if (uVar6 < 0x1000000) {
          uVar7 = param_1[4];
          param_1[4] = uVar7 + 1;
          *param_1 = uVar6 * 0x100;
          param_1[1] = (uint)*(byte *)(param_1[3] + uVar7) + (uVar10 - uVar5) * 0x100;
        }
        uVar1 = *(ushort *)((int)param_1 + uVar3 * 2 + 0x224);
        uVar6 = (uint)uVar1 * (*param_1 >> 0xb);
        uVar5 = param_1[1];
        uVar10 = param_1[0x15];
        if (uVar6 < uVar5 || uVar6 - uVar5 == 0) {
          uVar7 = *param_1 - uVar6;
          *param_1 = uVar7;
          param_1[1] = uVar5 - uVar6;
          *(ushort *)((int)param_1 + uVar3 * 2 + 0x224) = uVar1 - (uVar1 >> 5);
          if (uVar7 < 0x1000000) {
            *param_1 = uVar7 * 0x100;
            uVar7 = param_1[4];
            param_1[4] = uVar7 + 1;
            param_1[1] = (uint)*(byte *)(param_1[3] + uVar7) + (uVar5 - uVar6) * 0x100;
          }
          uVar1 = *(ushort *)((int)param_1 + uVar3 * 2 + 0x23c);
          uVar6 = param_1[1];
          uVar5 = (uint)uVar1 * (*param_1 >> 0xb);
          uVar7 = param_1[0x16];
          if (uVar5 < uVar6 || uVar5 - uVar6 == 0) {
            param_1[1] = uVar6 - uVar5;
            *param_1 = *param_1 - uVar5;
            *(ushort *)((int)param_1 + uVar3 * 2 + 0x23c) = uVar1 - (uVar1 >> 5);
            uVar5 = param_1[0x17];
            param_1[0x17] = uVar7;
          }
          else {
            *param_1 = uVar5;
            *(ushort *)((int)param_1 + uVar3 * 2 + 0x23c) =
                 uVar1 + (short)((int)(0x800 - (uint)uVar1) >> 5);
            uVar5 = uVar7;
          }
          param_1[0x16] = uVar10;
        }
        else {
          *param_1 = uVar6;
          *(ushort *)((int)param_1 + uVar3 * 2 + 0x224) =
               uVar1 + (short)((int)(0x800 - (uint)uVar1) >> 5);
          uVar5 = uVar10;
        }
        uVar10 = param_1[0x14];
        param_1[0x14] = uVar5;
        param_1[0x15] = uVar10;
      }
      else {
        *param_1 = uVar5;
        *(ushort *)((int)param_1 + uVar3 * 2 + 0x20c) =
             uVar1 + (short)((int)(0x800 - (uint)uVar1) >> 5);
        if (uVar5 < 0x1000000) {
          uVar6 = param_1[4];
          *param_1 = uVar5 * 0x100;
          param_1[4] = uVar6 + 1;
          param_1[1] = (uint)*(byte *)(param_1[3] + uVar6) + uVar10 * 0x100;
        }
        uVar1 = *(ushort *)((int)param_1 + iVar4 * 2 + 0x254);
        uVar10 = (uint)uVar1 * (*param_1 >> 0xb);
        uVar5 = param_1[1];
        if (uVar5 <= uVar10 && uVar10 - uVar5 != 0) {
          *param_1 = uVar10;
          *(ushort *)((int)param_1 + iVar4 * 2 + 0x254) =
               uVar1 + (short)((int)(0x800 - (uint)uVar1) >> 5);
          uVar9 = 9;
          if (6 < uVar3) {
            uVar9 = 0xb;
          }
          *(undefined1 *)(param_1 + 0x18) = uVar9;
          param_1[0x19] = 1;
          goto LAB_1000253a;
        }
        param_1[1] = uVar5 - uVar10;
        *param_1 = *param_1 - uVar10;
        *(ushort *)((int)param_1 + iVar4 * 2 + 0x254) = uVar1 - (uVar1 >> 5);
      }
      uVar9 = 8;
      if (6 < uVar3) {
        uVar9 = 0xb;
      }
      *(undefined1 *)(param_1 + 0x18) = uVar9;
      FUN_100020c0(param_1,(int)param_1 + DAT_10002874,uVar2);
    }
    else {
      *param_1 = uVar10;
      *(ushort *)((int)param_1 + uVar3 * 2 + 500) = uVar1 + (short)((int)(0x800 - (uint)uVar1) >> 5)
      ;
      uVar9 = 7;
      if (6 < uVar3) {
        uVar9 = 10;
      }
      *(undefined1 *)(param_1 + 0x18) = uVar9;
      param_1[0x17] = param_1[0x16];
      param_1[0x16] = param_1[0x15];
      param_1[0x15] = param_1[0x14];
      FUN_100020c0(param_1,param_1 + 0x1b6,uVar2);
      uVar5 = param_1[0x19];
      if (5 < uVar5) {
        uVar5 = 5;
      }
      uVar10 = 1;
      do {
        uVar10 = uVar10 * 2;
        puVar13 = (ushort *)((int)param_1 + uVar10 + uVar5 * 0x80 + 0x2d4);
        if (*param_1 < 0x1000000) {
          *param_1 = *param_1 << 8;
          uVar6 = param_1[4];
          param_1[4] = uVar6 + 1;
          param_1[1] = (uint)*(byte *)(param_1[3] + uVar6) + param_1[1] * 0x100;
        }
        uVar1 = *puVar13;
        uVar6 = (uint)uVar1 * (*param_1 >> 0xb);
        uVar2 = param_1[1];
        if (uVar6 < uVar2 || uVar6 - uVar2 == 0) {
          param_1[1] = uVar2 - uVar6;
          *param_1 = *param_1 - uVar6;
          uVar10 = uVar10 + 1;
          *puVar13 = uVar1 - (uVar1 >> 5);
        }
        else {
          *param_1 = uVar6;
          *puVar13 = uVar1 + (short)((int)(0x800 - (uint)uVar1) >> 5);
        }
        iVar4 = DAT_1000286c;
      } while (uVar10 < 0x40);
      uVar10 = uVar10 - 0x40;
      if (uVar10 < 4) {
        param_1[0x14] = uVar10;
      }
      else {
        uVar5 = (uVar10 & 1) + 2;
        if (uVar10 < 0xe) {
          uVar6 = (uVar10 >> 1) - 1;
          uVar5 = uVar5 << (uVar6 & 0xff);
          param_1[0x14] = uVar5;
          iVar11 = (uVar5 - uVar10) + DAT_10002870;
          uVar5 = 0;
          iVar12 = 1;
          do {
            puVar13 = (ushort *)((int)param_1 + (iVar11 + iVar12) * 2 + iVar4);
            if (*param_1 < 0x1000000) {
              *param_1 = *param_1 << 8;
              uVar10 = param_1[4];
              param_1[4] = uVar10 + 1;
              param_1[1] = (uint)*(byte *)(param_1[3] + uVar10) + param_1[1] * 0x100;
            }
            uVar1 = *puVar13;
            uVar10 = (uint)uVar1 * (*param_1 >> 0xb);
            uVar2 = param_1[1];
            iVar12 = iVar12 * 2;
            if (uVar10 < uVar2 || uVar10 - uVar2 == 0) {
              *param_1 = *param_1 - uVar10;
              uVar3 = param_1[0x14];
              param_1[1] = uVar2 - uVar10;
              *puVar13 = uVar1 - (uVar1 >> 5);
              iVar12 = iVar12 + 1;
              param_1[0x14] = (1 << (uVar5 & 0xff)) + uVar3;
            }
            else {
              *param_1 = uVar10;
              *puVar13 = uVar1 + (short)((int)(0x800 - (uint)uVar1) >> 5);
            }
            uVar5 = uVar5 + 1;
          } while (uVar5 < uVar6);
        }
        else {
          param_1[0x14] = uVar5;
          iVar4 = (uVar10 >> 1) - 5;
          do {
            if (*param_1 < 0x1000000) {
              *param_1 = *param_1 << 8;
              uVar5 = param_1[4];
              param_1[4] = uVar5 + 1;
              param_1[1] = (uint)*(byte *)(param_1[3] + uVar5) + param_1[1] * 0x100;
            }
            iVar4 = iVar4 + -1;
            uVar10 = *param_1 >> 1;
            *param_1 = uVar10;
            uVar5 = (int)(param_1[1] - uVar10) >> 0x1f;
            param_1[1] = (uVar10 & uVar5) + (param_1[1] - uVar10);
            uVar5 = param_1[0x14] * 2 + 1 + uVar5;
            param_1[0x14] = uVar5;
          } while (iVar4 != 0);
          param_1[0x14] = uVar5 * 0x10;
          iVar4 = 1;
          uVar5 = 0;
          do {
            puVar13 = (ushort *)((int)param_1 + iVar4 * 2 + 0x6b8);
            if (*param_1 < 0x1000000) {
              *param_1 = *param_1 << 8;
              uVar10 = param_1[4];
              param_1[4] = uVar10 + 1;
              param_1[1] = (uint)*(byte *)(param_1[3] + uVar10) + param_1[1] * 0x100;
            }
            uVar1 = *puVar13;
            uVar10 = (uint)uVar1 * (*param_1 >> 0xb);
            uVar6 = param_1[1];
            iVar4 = iVar4 * 2;
            if (uVar10 < uVar6 || uVar10 - uVar6 == 0) {
              uVar2 = param_1[0x14];
              *param_1 = *param_1 - uVar10;
              param_1[1] = uVar6 - uVar10;
              *puVar13 = uVar1 - (uVar1 >> 5);
              iVar4 = iVar4 + 1;
              param_1[0x14] = (1 << (uVar5 & 0xff)) + uVar2;
            }
            else {
              *param_1 = uVar10;
              *puVar13 = uVar1 + (short)((int)(0x800 - (uint)uVar1) >> 5);
            }
            uVar5 = uVar5 + 1;
          } while (uVar5 != 4);
        }
      }
    }
LAB_1000253a:
    if (((param_1[9] <= param_1[0x14]) || (param_1[0xc] <= param_1[0x14])) ||
       (iVar4 = FUN_100021ea(param_1 + 6,param_1 + 0x19), iVar4 == 0)) {
      return 0;
    }
  } while( true );
}

// FUNC 0x10002878  FUN_10002878

/* WARNING: Function: __gnu_thumb1_case_shi replaced with injection: switch16_shi_r0 */
/* WARNING (jumptable): Removing unreachable block (ram,0x100029b4) */
/* WARNING: Removing unreachable block (ram,0x100029b4) */

undefined8 FUN_10002878(undefined4 *param_1,int *param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  char *pcVar3;
  undefined4 *puVar4;
  char *pcVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  undefined1 uVar10;
  uint uVar11;
  int *piVar12;
  undefined4 *puVar13;
  uint uVar14;
  undefined4 *puVar15;
  
  puVar15 = param_1;
  piVar12 = param_2;
LAB_1000287e:
  do {
    pcVar5 = (char *)(param_1 + 0x10);
    uVar11 = param_2[1];
    uVar14 = param_2[2];
switchD_100029b4_caseD_9:
    if (uVar14 <= uVar11) {
      if (*pcVar5 == '\a') goto switchD_100029b4_caseD_7;
      goto LAB_10002b84;
    }
    switch(*pcVar5) {
    case '\0':
      goto switchD_100029b4_caseD_0;
    case '\x01':
      param_2[1] = uVar11 + 1;
      param_1[0x11] = param_1[0x11] + (uint)*(byte *)(*param_2 + uVar11) * 0x100;
      uVar10 = 2;
      goto LAB_10002aa0;
    case '\x02':
      param_2[1] = uVar11 + 1;
      param_1[0x11] = (uint)*(byte *)(*param_2 + uVar11) + param_1[0x11] + 1;
      uVar10 = 3;
      goto LAB_10002aa0;
    case '\x03':
      param_2[1] = uVar11 + 1;
      param_1[0x12] = (uint)*(byte *)(*param_2 + uVar11) << 8;
      uVar10 = 4;
      goto LAB_10002aa0;
    case '\x04':
      param_2[1] = uVar11 + 1;
      param_1[0x12] = (uint)*(byte *)(*param_2 + uVar11) + param_1[0x12] + 1;
      uVar10 = *(undefined1 *)((int)param_1 + 0x41);
      goto LAB_10002aa0;
    case '\x05':
      param_2[1] = uVar11 + 1;
      uVar11 = (uint)*(byte *)(*param_2 + uVar11);
      if (0xe0 < uVar11) goto LAB_10002a3a;
      param_1[0x1c] = 0;
      for (; 0x2c < uVar11; uVar11 = uVar11 - 0x2d & 0xff) {
        param_1[0x1c] = param_1[0x1c] + 1;
      }
      param_1[0x1c] = (1 << (param_1[0x1c] & 0xff)) + -1;
      iVar1 = 0;
      while( true ) {
        param_1[0x1b] = iVar1;
        uVar7 = param_1[0x1b];
        if (uVar11 < 9) break;
        uVar11 = uVar11 - 9 & 0xff;
        iVar1 = uVar7 + 1;
      }
      param_1[0x1a] = uVar11;
      if (4 < uVar11 + uVar7) goto LAB_10002a3a;
      param_1[0x1b] = (1 << (uVar7 & 0xff)) + -1;
      *(undefined1 *)(param_1 + 0x18) = 0;
      param_1[0x14] = 0;
      param_1[0x15] = 0;
      param_1[0x16] = 0;
      param_1[0x17] = 0;
      puVar13 = param_1 + 0x1d;
      puVar4 = (undefined4 *)((int)param_1 + DAT_10002bb4);
      do {
        *(undefined2 *)puVar13 = 0x400;
        puVar13 = (undefined4 *)((int)puVar13 + 2);
      } while (puVar4 != puVar13);
      *param_1 = 0xffffffff;
      param_1[1] = 0;
      param_1[2] = 5;
      *pcVar5 = '\x06';
switchD_100029b4_caseD_6:
      uVar11 = param_1[0x12];
      if (uVar11 < 5) goto LAB_10002a3a;
      while( true ) {
        iVar1 = param_1[2];
        uVar7 = param_2[1];
        if (iVar1 == 0) break;
        if (uVar14 == uVar7) goto LAB_10002b84;
        iVar6 = param_1[1];
        param_2[1] = uVar7 + 1;
        param_1[1] = (uint)*(byte *)(*param_2 + uVar7) + iVar6 * 0x100;
        param_1[2] = iVar1 + -1;
      }
      param_1[0x12] = uVar11 - 5;
      *(undefined1 *)(param_1 + 0x10) = 7;
switchD_100029b4_caseD_7:
      iVar1 = DAT_10002bb4;
      uVar11 = param_2[5] - param_2[4];
      if ((uint)param_1[0x11] < (uint)(param_2[5] - param_2[4])) {
        uVar11 = param_1[0x11];
      }
      iVar6 = param_1[0xb];
      if (uVar11 < (uint)(iVar6 - param_1[8])) {
        iVar6 = uVar11 + param_1[8];
      }
      param_1[10] = iVar6;
      iVar1 = *(int *)((int)param_1 + iVar1);
      if ((iVar1 != 0) || (param_1[0x12] == 0)) {
        uVar11 = param_1[0x12] - iVar1;
        if (0x2aU - iVar1 < uVar11) {
          uVar11 = 0x2aU - iVar1;
        }
        uVar14 = uVar14 - param_2[1];
        if (uVar11 < uVar14) {
          uVar14 = uVar11;
        }
        iVar6 = (int)param_1 + DAT_10002bb8;
        FUN_100049ac(iVar6 + iVar1,*param_2 + param_2[1],uVar14,*param_2,puVar15,piVar12,param_3);
        piVar12 = *(int **)((int)param_1 + DAT_10002bb4);
        uVar11 = uVar14 + (int)piVar12;
        if (uVar11 != param_1[0x12]) {
          if (0x14 < uVar11) {
            param_1[5] = uVar11 - 0x15;
            goto LAB_1000290c;
          }
          *(uint *)((int)param_1 + DAT_10002bb4) = uVar11;
LAB_10002ba6:
          param_2[1] = param_2[1] + uVar14;
          goto LAB_10002946;
        }
        FUN_10004b08(iVar6 + uVar11,0,0x3f - uVar11,param_1[0x12],puVar15,piVar12);
        piVar12 = *(int **)((int)param_1 + DAT_10002bb4);
        param_1[5] = (int)piVar12 + uVar14;
LAB_1000290c:
        param_1[3] = iVar6;
        param_1[4] = 0;
        iVar1 = FUN_10002234(param_1);
        if (iVar1 != 0) {
          uVar11 = param_1[4];
          uVar7 = *(uint *)((int)param_1 + DAT_10002bb4);
          if (uVar11 <= uVar14 + uVar7) {
            param_1[0x12] = param_1[0x12] - uVar11;
            iVar1 = DAT_10002cf0;
            if (uVar7 <= uVar11) {
              param_2[1] = (param_2[1] - uVar7) + uVar11;
              *(undefined4 *)((int)param_1 + iVar1) = 0;
              goto LAB_10002bce;
            }
            *(uint *)((int)param_1 + DAT_10002bb4) = uVar7 - uVar11;
            FUN_10004a50(iVar6,iVar6 + uVar11);
            goto LAB_10002946;
          }
        }
        goto LAB_10002a3a;
      }
LAB_10002bce:
      iVar1 = param_2[1];
      uVar14 = param_2[2] - iVar1;
      if (0x14 < uVar14) {
        iVar6 = param_2[2] + -0x15;
        param_1[3] = *param_2;
        param_1[4] = iVar1;
        if (param_1[0x12] + 0x15 <= uVar14) {
          iVar6 = iVar1 + param_1[0x12];
        }
        param_1[5] = iVar6;
        iVar1 = FUN_10002234(param_1);
        if (iVar1 != 0) {
          iVar1 = param_1[4];
          if ((uint)(iVar1 - param_2[1]) <= (uint)param_1[0x12]) {
            param_1[0x12] = (param_2[1] - iVar1) + param_1[0x12];
            param_2[1] = iVar1;
            goto LAB_10002c10;
          }
        }
        goto LAB_10002a3a;
      }
LAB_10002c10:
      uVar11 = param_2[2] - param_2[1];
      if (uVar11 < 0x15) {
        uVar14 = param_1[0x12];
        if (uVar11 < (uint)param_1[0x12]) {
          uVar14 = uVar11;
        }
        FUN_100049ac((int)param_1 + DAT_10002cf4,*param_2 + param_2[1],uVar14,DAT_10002cf4,puVar15,
                     piVar12,param_3);
        *(uint *)((int)param_1 + DAT_10002cf0) = uVar14;
        goto LAB_10002ba6;
      }
LAB_10002946:
      iVar6 = param_1[8];
      iVar1 = param_1[7];
      piVar12 = (int *)(iVar6 - iVar1);
      if (*(char *)(param_1 + 0xf) != '\0') {
        if (iVar6 == param_1[0xb]) {
          param_1[8] = 0;
        }
        FUN_100049ac(param_2[3] + param_2[4],param_1[6] + iVar1,iVar6 - iVar1,param_1[6],puVar15,
                     piVar12,param_3);
      }
      iVar8 = param_2[4];
      param_1[7] = param_1[8];
      iVar8 = (iVar6 - iVar1) + iVar8;
      iVar6 = (iVar1 + param_1[0x11]) - iVar6;
      param_2[4] = iVar8;
      param_1[0x11] = iVar6;
      if (iVar6 == 0) {
        if (((param_1[0x12] != 0) || (param_1[0x19] != 0)) || (param_1[1] != 0)) goto LAB_10002a3a;
        *param_1 = 0xffffffff;
        param_1[2] = 5;
        goto LAB_100029a8;
      }
      if ((param_2[5] == iVar8) ||
         ((param_2[1] == param_2[2] &&
          (*(uint *)((int)param_1 + DAT_10002cf0) < (uint)param_1[0x12])))) goto LAB_10002b84;
      break;
    case '\x06':
      goto switchD_100029b4_caseD_6;
    case '\a':
      goto switchD_100029b4_caseD_7;
    case '\b':
      goto switchD_100029b4_caseD_8;
    default:
      goto switchD_100029b4_caseD_9;
    }
  } while( true );
switchD_100029b4_caseD_8:
  uVar11 = param_1[0x12];
  uVar14 = param_2[1];
  if (uVar11 == 0) goto LAB_100029a8;
  if ((uint)param_2[2] <= uVar14) goto LAB_10002b84;
  if ((uint)param_2[5] <= (uint)param_2[4]) goto LAB_10002b84;
  piVar12 = (int *)param_1[8];
  uVar7 = param_1[0xb] - (int)piVar12;
  if (uVar11 < (uint)(param_1[0xb] - (int)piVar12)) {
    uVar7 = uVar11;
  }
  uVar9 = param_2[5] - param_2[4];
  if (uVar9 < uVar7) {
    uVar7 = uVar9;
  }
  uVar9 = param_2[2] - uVar14;
  if (uVar9 < uVar7) {
    uVar7 = uVar9;
  }
  param_1[0x12] = uVar11 - uVar7;
  FUN_100049ac(param_1[6] + (int)piVar12,*param_2 + uVar14,uVar7);
  uVar14 = uVar7 + param_1[8];
  param_1[8] = uVar14;
  if ((uint)param_1[9] < uVar14) {
    param_1[9] = uVar14;
  }
  if (*(char *)(param_1 + 0xf) != '\0') {
    if (uVar14 == param_1[0xb]) {
      param_1[8] = 0;
    }
    FUN_100049ac(param_2[3] + param_2[4],*param_2 + param_2[1],uVar7);
  }
  param_1[7] = param_1[8];
  param_2[4] = param_2[4] + uVar7;
  param_2[1] = param_2[1] + uVar7;
  goto switchD_100029b4_caseD_8;
switchD_100029b4_caseD_0:
  param_2[1] = uVar11 + 1;
  uVar14 = (uint)*(byte *)(*param_2 + uVar11);
  if (uVar14 == 0) {
    uVar2 = 1;
    goto LAB_10002a3c;
  }
  pcVar3 = (char *)(param_1 + 0x13);
  if ((uVar14 < 0xe0) && (uVar14 != 1)) {
    if (*pcVar3 != '\0') goto LAB_10002a3a;
  }
  else {
    pcVar3[0] = '\0';
    pcVar3[1] = '\x01';
    if (*(char *)(param_1 + 0xf) == '\0') {
      iVar1 = param_2[4];
      param_1[6] = param_2[3] + iVar1;
      param_1[0xb] = param_2[5] - iVar1;
    }
    param_1[7] = 0;
    param_1[8] = 0;
    param_1[10] = 0;
    param_1[9] = 0;
  }
  if (uVar14 < 0x80) {
    if (uVar14 < 3) {
      *(short *)(param_1 + 0x10) = (short)DAT_10002bbc;
      goto LAB_1000287e;
    }
  }
  else {
    param_1[0x11] = (uVar14 & 0x1f) << 0x10;
    *pcVar5 = '\x01';
    if (0xbf < uVar14) {
      *(char *)((int)param_1 + 0x4d) = '\0';
      *(undefined1 *)((int)param_1 + 0x41) = 5;
      goto LAB_1000287e;
    }
    if (*(char *)((int)param_1 + 0x4d) == '\0') {
      *(undefined1 *)((int)param_1 + 0x41) = 6;
      if (0x9f < uVar14) {
        *(undefined1 *)(param_1 + 0x18) = 0;
        param_1[0x14] = 0;
        param_1[0x15] = 0;
        param_1[0x16] = 0;
        param_1[0x17] = 0;
        puVar13 = param_1 + 0x1d;
        puVar4 = (undefined4 *)((int)param_1 + DAT_10002bb4);
        do {
          *(undefined2 *)puVar13 = 0x400;
          puVar13 = (undefined4 *)((int)puVar13 + 2);
        } while (puVar4 != puVar13);
        *param_1 = 0xffffffff;
        param_1[1] = 0;
        param_1[2] = 5;
      }
      goto LAB_1000287e;
    }
  }
LAB_10002a3a:
  uVar2 = 7;
  goto LAB_10002a3c;
LAB_100029a8:
  uVar10 = 0;
LAB_10002aa0:
  *(undefined1 *)(param_1 + 0x10) = uVar10;
  goto LAB_1000287e;
LAB_10002b84:
  uVar2 = 0;
LAB_10002a3c:
  return CONCAT44(puVar15,uVar2);
}

// FUNC 0x10002cf8  FUN_10002cf8

int FUN_10002cf8(int param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = FUN_100043bc(DAT_10002d38);
  if (iVar1 != 0) {
    *(char *)(iVar1 + 0x3c) = (char)param_1;
    *(undefined4 *)(iVar1 + 0x34) = param_2;
    if (param_1 == 1) {
      iVar2 = FUN_100043bc(param_2);
      *(int *)(iVar1 + 0x18) = iVar2;
      if (iVar2 == 0) {
        FUN_100043d0(iVar1);
        iVar1 = 0;
      }
    }
    else if (param_1 == 2) {
      *(undefined4 *)(iVar1 + 0x18) = 0;
      *(undefined4 *)(iVar1 + 0x38) = 0;
    }
  }
  return iVar1;
}

// FUNC 0x10002d3c  FUN_10002d3c

undefined4 FUN_10002d3c(int param_1,uint param_2)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  
  uVar1 = 6;
  if (param_2 < 0x28) {
    uVar3 = (param_2 & 1) + 2 << ((param_2 >> 1) + 0xb & 0xff);
    *(uint *)(param_1 + 0x30) = uVar3;
    if (*(char *)(param_1 + 0x3c) != '\0') {
      if (*(uint *)(param_1 + 0x34) < uVar3) {
        return 4;
      }
      *(uint *)(param_1 + 0x2c) = uVar3;
      if ((*(char *)(param_1 + 0x3c) == '\x02') && (*(uint *)(param_1 + 0x38) < uVar3)) {
        FUN_100043d0(*(undefined4 *)(param_1 + 0x18));
        iVar2 = FUN_100043bc(*(undefined4 *)(param_1 + 0x30));
        *(int *)(param_1 + 0x18) = iVar2;
        if (iVar2 == 0) {
          *(undefined4 *)(param_1 + 0x38) = 0;
          return 3;
        }
      }
    }
    uVar1 = 0;
    *(undefined4 *)(param_1 + 100) = 0;
    *(undefined1 *)(param_1 + 0x40) = 0;
    *(undefined1 *)(param_1 + 0x4c) = 1;
    *(undefined4 *)(param_1 + DAT_10002da0) = 0;
  }
  return uVar1;
}

// FUNC 0x10002da4  FUN_10002da4

void FUN_10002da4(int param_1)

{
  if (*(char *)(param_1 + 0x3c) != '\0') {
    FUN_100043d0(*(undefined4 *)(param_1 + 0x18));
  }
  FUN_100043d0(param_1);
  return;
}

// FUNC 0x10002dc0  FUN_10002dc0

undefined4 FUN_10002dc0(undefined4 *param_1)

{
  return *param_1;
}

// FUNC 0x10002dd6  FUN_10002dd6

undefined8 FUN_10002dd6(int param_1,int param_2,uint *param_3,uint param_4)

{
  byte bVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  undefined8 uVar5;
  
  if (*(int *)(param_1 + 4) == 0) {
    *(undefined4 *)(param_1 + 8) = 0;
    *(undefined4 *)(param_1 + 0xc) = 0;
  }
  while( true ) {
    uVar3 = *param_3;
    if (param_4 <= uVar3) {
      uVar2 = 0;
      goto LAB_10002e2c;
    }
    iVar4 = *(int *)(param_1 + 4);
    bVar1 = *(byte *)(param_2 + uVar3);
    *param_3 = uVar3 + 1;
    uVar5 = FUN_1000091c(bVar1 & 0x7f,0,iVar4);
    *(uint *)(param_1 + 8) = (uint)uVar5 | *(uint *)(param_1 + 8);
    *(uint *)(param_1 + 0xc) = (uint)((ulonglong)uVar5 >> 0x20) | *(uint *)(param_1 + 0xc);
    if (-1 < (char)bVar1) break;
    *(int *)(param_1 + 4) = iVar4 + 7;
    if (iVar4 + 7 == 0x3f) {
LAB_10002e2a:
      uVar2 = 7;
LAB_10002e2c:
      return CONCAT44(param_2,uVar2);
    }
  }
  if ((bVar1 != 0) || (iVar4 == 0)) {
    uVar2 = 1;
    *(undefined4 *)(param_1 + 4) = 0;
    goto LAB_10002e2c;
  }
  goto LAB_10002e2a;
}

// FUNC 0x10002e40  FUN_10002e40

void FUN_10002e40(int param_1,int *param_2,undefined4 param_3,undefined4 param_4)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  
  uVar4 = param_2[1] - *(int *)(param_1 + 0x10);
  uVar1 = *(uint *)(param_1 + 0x70);
  iVar2 = *param_2;
  *(uint *)(param_1 + 0x70) = uVar4 + uVar1;
  *(uint *)(param_1 + 0x74) = *(int *)(param_1 + 0x74) + (uint)CARRY4(uVar4,uVar1);
  uVar3 = FUN_10002094(iVar2 + *(int *)(param_1 + 0x10),uVar4,*(undefined4 *)(param_1 + 0x18),
                       param_2,param_4);
  *(undefined4 *)(param_1 + 0x18) = uVar3;
  return;
}

// FUNC 0x10002e6c  FUN_10002e6c

bool FUN_10002e6c(int param_1,int *param_2,undefined4 param_3,undefined4 param_4)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int *piVar4;
  bool bVar5;
  
  piVar4 = (int *)(param_1 + 0x98);
  uVar1 = param_2[2] - param_2[1];
  uVar2 = *(int *)(param_1 + 0x9c) - *piVar4;
  if (uVar1 < uVar2) {
    uVar2 = uVar1;
  }
  FUN_100049ac(param_1 + 0xa0 + *piVar4,*param_2 + param_2[1],uVar2,*param_2,param_4);
  param_2[1] = param_2[1] + uVar2;
  iVar3 = uVar2 + *piVar4;
  *piVar4 = iVar3;
  bVar5 = iVar3 == *(int *)(param_1 + 0x9c);
  if (bVar5) {
    *piVar4 = 0;
  }
  return bVar5;
}

// FUNC 0x10002eb2  FUN_10002eb2

void FUN_10002eb2(undefined1 *param_1)

{
  *param_1 = 0;
  param_1[0x1e] = 0;
  *(undefined4 *)(param_1 + 4) = 0;
  *(undefined4 *)(param_1 + 0x18) = 0;
  FUN_10004b08(param_1 + 0x38,0,0x30);
  FUN_10004b08(param_1 + 0x68,0,0x30);
  *(undefined4 *)(param_1 + 0x98) = 0;
  *(undefined4 *)(param_1 + 0x9c) = 0xc;
  return;
}

// FUNC 0x10002ee8  FUN_10002ee8

/* WARNING: Function: __gnu_thumb1_case_uhi replaced with injection: switch16_uhi_r0 */
/* WARNING (jumptable): Removing unreachable block (ram,0x10002f0c) */
/* WARNING: Removing unreachable block (ram,0x10002f0c) */

int FUN_10002ee8(undefined1 *param_1,int *param_2)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  char cVar6;
  undefined1 uVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  undefined4 uVar11;
  uint uVar12;
  undefined1 *puVar13;
  int iVar14;
  int *piVar15;
  uint *puVar16;
  uint uVar17;
  
  if (param_1[0x1d] == '\0') {
    FUN_10002eb2();
  }
  iVar8 = param_2[1];
  iVar9 = param_2[4];
  *(int *)(param_1 + 0x10) = iVar8;
LAB_10002f06:
switchD_10002f0c_switchD:
  switch(*param_1) {
  case 0:
    iVar2 = FUN_10002e6c(param_1,param_2);
    uVar1 = DAT_10003280;
    if (iVar2 == 0) goto LAB_10002f30;
    *param_1 = 1;
    iVar2 = FUN_10004964(param_1 + 0xa0,uVar1,6);
    if (iVar2 != 0) {
      iVar2 = 5;
      goto LAB_10002f66;
    }
    iVar2 = FUN_10002094(param_1 + 0xa6,2);
    iVar3 = FUN_10002dc0(param_1 + 0xa8);
    if (iVar2 != iVar3) goto LAB_10002f64;
    if ((param_1[0xa6] == '\0') && (param_1[0x1c] = param_1[0xa7], (byte)param_1[0xa7] < 2))
    goto switchD_10002f0c_caseD_1;
    break;
  case 1:
switchD_10002f0c_caseD_1:
    iVar2 = param_2[1];
    if (iVar2 != param_2[2]) {
      if (*(byte *)(*param_2 + iVar2) != 0) {
        iVar2 = (*(byte *)(*param_2 + iVar2) + 1) * 4;
        *(int *)(param_1 + 0x30) = iVar2;
        *(int *)(param_1 + 0x9c) = iVar2;
        *(undefined4 *)(param_1 + 0x98) = 0;
        *param_1 = 2;
        goto switchD_10002f0c_caseD_2;
      }
      param_2[1] = iVar2 + 1;
      uVar7 = 6;
      *(int *)(param_1 + 0x10) = iVar2;
      goto LAB_10002fb8;
    }
    goto LAB_10002f30;
  case 2:
switchD_10002f0c_caseD_2:
    iVar2 = FUN_10002e6c(param_1,param_2);
    if (iVar2 == 0) goto LAB_10002f30;
    piVar15 = (int *)(param_1 + 0x9c);
    iVar2 = *piVar15;
    puVar13 = param_1 + 0xa0;
    *piVar15 = iVar2 + -4;
    iVar2 = FUN_10002094(puVar13,iVar2 + -4,0);
    iVar14 = *piVar15;
    iVar3 = FUN_10002dc0(puVar13 + iVar14);
    if (iVar2 != iVar3) goto LAB_10002f64;
    *(undefined4 *)(param_1 + 0x98) = 2;
    if ((param_1[0xa1] & 0x3f) == 0) {
      if ((int)((uint)(byte)param_1[0xa1] << 0x19) < 0) {
        iVar2 = FUN_10002dd6(param_1,puVar13,param_1 + 0x98,iVar14);
        if (iVar2 != 1) goto LAB_10002f64;
        uVar1 = *(undefined4 *)(param_1 + 8);
        uVar11 = *(undefined4 *)(param_1 + 0xc);
      }
      else {
        uVar1 = 0xffffffff;
        uVar11 = 0xffffffff;
      }
      *(undefined4 *)(param_1 + 0x20) = uVar1;
      *(undefined4 *)(param_1 + 0x24) = uVar11;
      if ((byte)param_1[0xa1] < 0x80) {
        uVar1 = 0xffffffff;
        uVar11 = 0xffffffff;
      }
      else {
        iVar2 = FUN_10002dd6(param_1,puVar13,param_1 + 0x98,*(undefined4 *)(param_1 + 0x9c));
        if (iVar2 != 1) goto LAB_10002f64;
        uVar1 = *(undefined4 *)(param_1 + 8);
        uVar11 = *(undefined4 *)(param_1 + 0xc);
      }
      *(undefined4 *)(param_1 + 0x28) = uVar1;
      *(undefined4 *)(param_1 + 0x2c) = uVar11;
      puVar16 = (uint *)(param_1 + 0x98);
      uVar4 = *(uint *)(param_1 + 0x9c);
      uVar12 = *puVar16;
      if (uVar4 - uVar12 < 2) goto LAB_10002f64;
      *puVar16 = uVar12 + 1;
      if (param_1[uVar12 + 0xa0] == '!') {
        *puVar16 = uVar12 + 2;
        if (param_1[uVar12 + 0xa1] == '\x01') {
          if (uVar4 != uVar12 + 2) {
            *puVar16 = uVar12 + 3;
            iVar2 = FUN_10002d3c(*(undefined4 *)(param_1 + 0x4a0),param_1[uVar12 + 0xa2]);
            if (iVar2 == 0) {
              while (uVar4 = *puVar16, uVar4 < *(uint *)(param_1 + 0x9c)) {
                *puVar16 = uVar4 + 1;
                if (param_1[uVar4 + 0xa0] != '\0') goto LAB_10002f90;
              }
              *puVar16 = 0;
              *(undefined4 *)(param_1 + 0x38) = 0;
              *(undefined4 *)(param_1 + 0x3c) = 0;
              *(undefined4 *)(param_1 + 0x40) = 0;
              *(undefined4 *)(param_1 + 0x44) = 0;
              *param_1 = 3;
              goto switchD_10002f0c_caseD_3;
            }
            goto LAB_10002f66;
          }
          goto LAB_10002f64;
        }
      }
    }
    break;
  case 3:
switchD_10002f0c_caseD_3:
    *(int *)(param_1 + 0x10) = param_2[1];
    *(int *)(param_1 + 0x14) = param_2[4];
    iVar2 = FUN_10002878(*(undefined4 *)(param_1 + 0x4a0),param_2);
    uVar4 = (param_2[1] - *(int *)(param_1 + 0x10)) + *(uint *)(param_1 + 0x38);
    uVar12 = *(int *)(param_1 + 0x3c) +
             (uint)CARRY4(param_2[1] - *(int *)(param_1 + 0x10),*(uint *)(param_1 + 0x38));
    *(uint *)(param_1 + 0x38) = uVar4;
    *(uint *)(param_1 + 0x3c) = uVar12;
    uVar17 = param_2[4] - *(int *)(param_1 + 0x14);
    uVar5 = uVar17 + *(uint *)(param_1 + 0x40);
    uVar10 = *(int *)(param_1 + 0x44) + (uint)CARRY4(uVar17,*(uint *)(param_1 + 0x40));
    *(uint *)(param_1 + 0x40) = uVar5;
    *(uint *)(param_1 + 0x44) = uVar10;
    if (((uVar12 <= *(uint *)(param_1 + 0x24)) &&
        ((*(uint *)(param_1 + 0x24) != uVar12 || (uVar4 <= *(uint *)(param_1 + 0x20))))) &&
       ((uVar10 <= *(uint *)(param_1 + 0x2c) &&
        ((*(uint *)(param_1 + 0x2c) != uVar10 || (uVar5 <= *(uint *)(param_1 + 0x28))))))) {
      if (param_1[0x1c] == '\x01') {
        uVar1 = FUN_10002094(*(int *)(param_1 + 0x14) + param_2[3],uVar17,
                             *(undefined4 *)(param_1 + 0x18));
        *(undefined4 *)(param_1 + 0x18) = uVar1;
      }
      if (iVar2 == 1) {
        if (((*(int *)(param_1 + 0x20) == -1) && (*(int *)(param_1 + 0x24) == -1)) ||
           ((*(int *)(param_1 + 0x38) == *(int *)(param_1 + 0x20) &&
            (*(int *)(param_1 + 0x3c) == *(int *)(param_1 + 0x24))))) {
          uVar4 = *(uint *)(param_1 + 0x40);
          if (((*(uint *)(param_1 + 0x28) == 0xffffffff) && (*(int *)(param_1 + 0x2c) == -1)) ||
             ((uVar4 == *(uint *)(param_1 + 0x28) &&
              (*(int *)(param_1 + 0x44) == *(int *)(param_1 + 0x2c))))) {
            uVar12 = *(uint *)(param_1 + 0x50) + *(uint *)(param_1 + 0x38);
            uVar5 = uVar12 + *(uint *)(param_1 + 0x30);
            iVar2 = *(int *)(param_1 + 0x54) + *(int *)(param_1 + 0x3c) +
                    (uint)CARRY4(*(uint *)(param_1 + 0x50),*(uint *)(param_1 + 0x38)) +
                    (uint)CARRY4(uVar12,*(uint *)(param_1 + 0x30));
            *(uint *)(param_1 + 0x50) = uVar5;
            *(int *)(param_1 + 0x54) = iVar2;
            if (param_1[0x1c] == '\x01') {
              *(uint *)(param_1 + 0x50) = uVar5 + 4;
              *(uint *)(param_1 + 0x54) = iVar2 + (uint)(0xfffffffb < uVar5);
            }
            uVar12 = *(uint *)(param_1 + 0x58);
            *(uint *)(param_1 + 0x58) = uVar4 + uVar12;
            *(uint *)(param_1 + 0x5c) =
                 *(int *)(param_1 + 0x44) + *(int *)(param_1 + 0x5c) + (uint)CARRY4(uVar4,uVar12);
            uVar1 = FUN_10002094(param_1 + 0x50,0x18,*(undefined4 *)(param_1 + 0x60));
            uVar4 = *(uint *)(param_1 + 0x48);
            *(undefined4 *)(param_1 + 0x60) = uVar1;
            *(uint *)(param_1 + 0x48) = uVar4 + 1;
            *(uint *)(param_1 + 0x4c) = *(int *)(param_1 + 0x4c) + (uint)(0xfffffffe < uVar4);
            *param_1 = 4;
            goto switchD_10002f0c_caseD_4;
          }
        }
        goto LAB_10002f64;
      }
      goto LAB_10002f66;
    }
    goto LAB_10002f64;
  case 4:
switchD_10002f0c_caseD_4:
    while( true ) {
      uVar4 = *(uint *)(param_1 + 0x38);
      iVar2 = *(int *)(param_1 + 0x3c);
      if ((uVar4 & 3) == 0) break;
      iVar3 = param_2[1];
      if (iVar3 == param_2[2]) goto LAB_10002f30;
      param_2[1] = iVar3 + 1;
      if (*(char *)(*param_2 + iVar3) != '\0') goto LAB_10002f64;
      *(uint *)(param_1 + 0x38) = uVar4 + 1;
      *(uint *)(param_1 + 0x3c) = iVar2 + (uint)(0xfffffffe < uVar4);
    }
    *param_1 = 5;
switchD_10002f0c_caseD_5:
    if (param_1[0x1c] == '\x01') {
      iVar2 = param_2[2];
      do {
        iVar3 = param_2[1];
        if (iVar3 == iVar2) goto LAB_10002f30;
        uVar12 = *(uint *)(param_1 + 4);
        uVar4 = *(uint *)(param_1 + 0x18);
        param_2[1] = iVar3 + 1;
        if ((uVar4 >> (uVar12 & 0xff) & 0xff) != (uint)*(byte *)(*param_2 + iVar3))
        goto LAB_10002f64;
        uVar12 = uVar12 + 8;
        *(uint *)(param_1 + 4) = uVar12;
      } while (uVar12 < 0x20);
      *(undefined4 *)(param_1 + 0x18) = 0;
      *(undefined4 *)(param_1 + 4) = 0;
    }
    uVar7 = 1;
LAB_10002fb8:
    *param_1 = uVar7;
    goto LAB_10002f06;
  case 5:
    goto switchD_10002f0c_caseD_5;
  case 6:
    goto switchD_10002f0c_caseD_6;
  case 7:
    goto switchD_10002f0c_caseD_7;
  case 8:
    goto switchD_10002f0c_caseD_8;
  case 9:
    goto switchD_10002f0c_caseD_9;
  default:
    goto switchD_10002f0c_switchD;
  }
LAB_10002f90:
  iVar2 = 6;
  goto LAB_10002f66;
LAB_10002f30:
  iVar2 = 0;
  goto LAB_10002f66;
switchD_10002f0c_caseD_6:
  do {
    iVar2 = FUN_10002dd6(param_1,*param_2,param_2 + 1,param_2[2]);
    if (iVar2 != 1) {
      FUN_10002e40(param_1,param_2);
      goto LAB_10002f66;
    }
    cVar6 = param_1[0x68];
    if (cVar6 == '\x01') {
      uVar4 = *(uint *)(param_1 + 0x80);
      *(uint *)(param_1 + 0x80) = uVar4 + *(uint *)(param_1 + 8);
      *(uint *)(param_1 + 0x84) =
           *(int *)(param_1 + 0x84) + *(int *)(param_1 + 0xc) +
           (uint)CARRY4(uVar4,*(uint *)(param_1 + 8));
      cVar6 = '\x02';
LAB_1000330e:
      param_1[0x68] = cVar6;
    }
    else {
      if (cVar6 == '\x02') {
        uVar4 = *(uint *)(param_1 + 0x88);
        *(uint *)(param_1 + 0x88) = uVar4 + *(uint *)(param_1 + 8);
        *(uint *)(param_1 + 0x8c) =
             *(int *)(param_1 + 0x8c) + *(int *)(param_1 + 0xc) +
             (uint)CARRY4(uVar4,*(uint *)(param_1 + 8));
        uVar1 = FUN_10002094(param_1 + 0x80,0x18,*(undefined4 *)(param_1 + 0x90));
        iVar2 = *(int *)(param_1 + 0x78);
        *(undefined4 *)(param_1 + 0x90) = uVar1;
        *(int *)(param_1 + 0x78) = iVar2 + -1;
        *(uint *)(param_1 + 0x7c) = *(int *)(param_1 + 0x7c) + -1 + (uint)(iVar2 != 0);
LAB_100032f2:
        cVar6 = '\x01';
        goto LAB_1000330e;
      }
      if (cVar6 == '\0') {
        *(int *)(param_1 + 0x78) = *(int *)(param_1 + 8);
        *(int *)(param_1 + 0x7c) = *(int *)(param_1 + 0xc);
        if ((*(int *)(param_1 + 0x48) == *(int *)(param_1 + 8)) &&
           (*(int *)(param_1 + 0x4c) == *(int *)(param_1 + 0xc))) goto LAB_100032f2;
        goto LAB_10002f64;
      }
    }
  } while (*(int *)(param_1 + 0x78) != 0 || *(int *)(param_1 + 0x7c) != 0);
  *param_1 = 7;
switchD_10002f0c_caseD_7:
  iVar3 = *(int *)(param_1 + 0x10);
  uVar4 = *(uint *)(param_1 + 0x70);
  iVar2 = *(int *)(param_1 + 0x74);
  while( true ) {
    iVar14 = param_2[1];
    uVar12 = (iVar14 - iVar3) + uVar4;
    if ((uVar12 & 3) == 0) break;
    if (param_2[2] == iVar14) {
      FUN_10002e40(param_1,param_2);
      goto LAB_10002f30;
    }
    param_2[1] = iVar14 + 1;
    if (*(char *)(*param_2 + iVar14) != '\0') goto LAB_10002f64;
  }
  FUN_10002e40(param_1,param_2,uVar12,iVar2 + (uint)CARRY4(iVar14 - iVar3,uVar4));
  iVar2 = FUN_10004964(param_1 + 0x50,param_1 + 0x80,0x18);
  if (iVar2 != 0) goto LAB_10002f64;
  *param_1 = 8;
switchD_10002f0c_caseD_8:
  iVar2 = param_2[2];
  do {
    iVar3 = param_2[1];
    if (iVar3 == iVar2) goto LAB_10002f30;
    uVar12 = *(uint *)(param_1 + 4);
    uVar4 = *(uint *)(param_1 + 0x18);
    param_2[1] = iVar3 + 1;
    if ((uVar4 >> (uVar12 & 0xff) & 0xff) != (uint)*(byte *)(*param_2 + iVar3)) goto LAB_10002f64;
    uVar12 = uVar12 + 8;
    *(uint *)(param_1 + 4) = uVar12;
  } while (uVar12 < 0x20);
  *(undefined4 *)(param_1 + 0x18) = 0;
  *(undefined4 *)(param_1 + 4) = 0;
  *(undefined4 *)(param_1 + 0x9c) = 0xc;
  *param_1 = 9;
switchD_10002f0c_caseD_9:
  iVar2 = FUN_10002e6c(param_1,param_2);
  if (iVar2 == 0) goto LAB_10002f30;
  iVar2 = FUN_10004964(param_1 + 0xaa,DAT_100034a0,2);
  if (iVar2 == 0) {
    iVar2 = FUN_10002094(param_1 + 0xa4,6);
    iVar3 = FUN_10002dc0(param_1 + 0xa0);
    if (iVar2 == iVar3) {
      uVar4 = FUN_10002dc0(param_1 + 0xa4);
      if (((((*(uint *)(param_1 + 0x70) >> 2 | *(uint *)(param_1 + 0x74) << 0x1e) == uVar4) &&
           (*(uint *)(param_1 + 0x74) >> 2 == 0)) && (param_1[0xa8] == '\0')) &&
         (iVar2 = 1, param_1[0xa9] == param_1[0x1c])) goto LAB_10002f66;
    }
  }
LAB_10002f64:
  iVar2 = 7;
LAB_10002f66:
  if (param_1[0x1d] == '\0') {
    if (iVar2 == 0) {
      iVar2 = 8 - (uint)(param_2[1] == param_2[2]);
    }
    else if (iVar2 == 1) {
      return 1;
    }
    param_2[1] = iVar8;
    param_2[4] = iVar9;
  }
  else {
    if (((iVar2 == 0) && (param_2[1] == iVar8)) && (param_2[4] == iVar9)) {
      if (param_1[0x1e] != '\0') {
        iVar2 = 8;
      }
      uVar7 = 1;
    }
    else {
      uVar7 = 0;
    }
    param_1[0x1e] = uVar7;
  }
  return iVar2;
}

// FUNC 0x100034a4  FUN_100034a4

int FUN_100034a4(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = FUN_100043bc(0x4a8);
  if (iVar1 != 0) {
    *(char *)(iVar1 + 0x1d) = (char)param_1;
    iVar2 = FUN_10002cf8(param_1,param_2);
    *(int *)(iVar1 + 0x4a0) = iVar2;
    if (iVar2 == 0) {
      FUN_100043d0();
      iVar1 = 0;
    }
    else {
      FUN_10002eb2(iVar1);
    }
  }
  return iVar1;
}

// FUNC 0x100034de  FUN_100034de

void FUN_100034de(int param_1)

{
  if (param_1 != 0) {
    FUN_10002da4(*(undefined4 *)(param_1 + 0x4a0));
    FUN_100043d0(param_1);
  }
  return;
}

// FUNC 0x100034f8  FUN_100034f8

/* WARNING: Function: __gnu_thumb1_case_uqi replaced with injection: switch8_r0 */
/* WARNING (jumptable): Removing unreachable block (ram,0x100035c0) */
/* WARNING: Removing unreachable block (ram,0x100035c0) */

undefined4 FUN_100034f8(code *param_1,code *param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  undefined4 local_1c;
  
  FUN_1000205c();
  iVar1 = FUN_100034a4(2,0x4000);
  if (iVar1 == 0) {
switchD_100035c0_caseD_3:
    uVar4 = DAT_10003618;
  }
  else {
    local_30 = FUN_100043bc(0x1000);
    local_2c = 0;
    local_28 = 0;
    local_24 = FUN_100043bc(0x1000);
    local_20 = 0;
    local_1c = 0x1000;
    do {
      if (local_2c == local_28) {
        local_28 = (*param_1)(local_30,1,0x1000,0);
        local_2c = 0;
      }
      iVar2 = FUN_10002ee8(iVar1,&local_30);
      if (local_20 == 0x1000) {
        iVar3 = (*param_2)(local_24,1,0x1000,0);
        uVar4 = DAT_100035fc;
        if (iVar3 != local_20) goto LAB_1000357a;
        local_20 = 0;
      }
    } while (iVar2 == 0);
    iVar3 = (*param_2)(local_24,1,local_20,0);
    uVar4 = DAT_100035fc;
    if (iVar3 != local_20) goto LAB_1000357a;
    switch(iVar2) {
    case 1:
      FUN_100034de(iVar1);
      FUN_100043d0(local_30);
      FUN_100043d0(local_24);
      return 0;
    default:
      uVar4 = DAT_10003614;
      break;
    case 3:
      goto switchD_100035c0_caseD_3;
    case 4:
      uVar4 = DAT_10003604;
      break;
    case 5:
      uVar4 = DAT_10003608;
      break;
    case 6:
      uVar4 = DAT_1000360c;
      break;
    case 7:
    case 8:
      uVar4 = DAT_10003610;
    }
  }
LAB_1000357a:
  FUN_100034de(iVar1);
  if (local_30 != 0) {
    FUN_100043d0();
  }
  if (local_24 != 0) {
    FUN_100043d0();
  }
  FUN_100014a0(DAT_10003600,uVar4);
  return 1;
}

// FUNC 0x1000369c  FUN_1000369c

int FUN_1000369c(undefined4 param_1)

{
  undefined4 uVar1;
  undefined1 auStack_1c [16];
  int local_c;
  
  uVar1 = FUN_1000439c(auStack_1c);
  FUN_10003e66(DAT_100036c0,param_1,uVar1);
  return -(uint)(local_c == 0);
}

// FUNC 0x100036c4  FUN_100036c4

void FUN_100036c4(undefined4 param_1)

{
  undefined4 uVar1;
  undefined1 auStack_1c [20];
  
  uVar1 = FUN_1000439c(auStack_1c);
  FUN_10003ef4(DAT_100036e0,param_1,uVar1);
  return;
}

// FUNC 0x10003726  FUN_10003726

undefined4 FUN_10003726(undefined4 param_1,undefined2 *param_2)

{
  undefined1 uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  undefined1 auStack_4c [8];
  int local_44;
  uint local_40;
  undefined2 local_3c;
  undefined1 auStack_38 [36];
  
  FUN_1000421e(param_1,*(undefined4 *)(param_2 + 8),auStack_4c,0x14);
  uVar1 = FUN_10004318(auStack_4c,6);
  *(undefined1 *)param_2 = uVar1;
  if (local_40 < 0x81) {
    uVar3 = 0;
    iVar4 = 0;
    *(uint *)(param_2 + 4) = local_40;
    uVar2 = local_40 + 8;
    do {
      iVar5 = 0x20;
      if (uVar2 <= uVar3 + 0x20) {
        iVar5 = uVar2 - uVar3;
      }
      FUN_1000421e(param_1,*(int *)(param_2 + 8) + 0xc + uVar3,auStack_38,iVar5);
      iVar4 = FUN_100042c0(iVar4,auStack_38,iVar5);
      uVar3 = uVar3 + iVar5;
    } while (uVar3 < uVar2);
    if (local_44 == iVar4) {
      *(undefined1 *)((int)param_2 + 1) = 1;
      param_2[6] = local_3c;
      *(int *)(param_2 + 10) = *(int *)(param_2 + 8) + 0x14;
      return 0;
    }
    *(undefined1 *)((int)param_2 + 1) = 0;
  }
  else {
    *(undefined4 *)(param_2 + 4) = 0x80;
    *param_2 = 5;
  }
  return 2;
}

// FUNC 0x100037b0  FUN_100037b0

void FUN_100037b0(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int extraout_r1;
  undefined4 uVar2;
  undefined4 uStack_18;
  undefined4 local_14;
  
  uStack_18 = param_3;
  local_14 = param_4;
  FUN_10004b08(&uStack_18,0,8,param_4,param_1,param_2);
  uVar2 = *(undefined4 *)(param_1 + 8);
  FUN_10000910(param_2,uVar2);
  if (extraout_r1 != 0) {
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  iVar1 = FUN_10004230(param_1,param_2,uVar2);
  if (iVar1 == 0) {
    FUN_10004b08(&uStack_18,0xff,8);
    FUN_100042f4(&uStack_18,4,1);
    FUN_100042f4((int)&uStack_18 + 1,4,1);
    local_14 = DAT_10003818;
    FUN_10004242(param_1,param_2,&uStack_18,8,1);
  }
  return;
}

// FUNC 0x10003874  FUN_10003874

uint FUN_10003874(int param_1,int param_2,uint *param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  undefined1 auStack_2c [4];
  int local_28;
  
  if (*(char *)(param_2 + 1) != '\x01') {
    uVar1 = *param_3;
    if (uVar1 == 0xffffffff) {
      return *(int *)(param_2 + 4) + 8;
    }
    uVar3 = *(int *)(param_2 + 4) + *(int *)(param_1 + 8);
    if (uVar1 <= uVar3) {
      uVar3 = uVar3 - 8;
      uVar1 = uVar1 + 0x94;
      do {
        uVar2 = uVar1;
        if ((uVar3 <= uVar2) || (uVar3 <= uVar2 + 0x94)) {
          uVar2 = 0xffffffff;
          break;
        }
        FUN_1000421e(param_1,uVar2,auStack_2c,0x14);
        uVar1 = uVar2 + 0x94;
      } while (local_28 != DAT_100038dc);
      if (uVar2 <= (uint)(*(int *)(param_2 + 4) + *(int *)(param_1 + 8))) {
        return uVar2;
      }
    }
  }
  return 0xffffffff;
}

// FUNC 0x100038e0  FUN_100038e0

undefined1 FUN_100038e0(int param_1,undefined4 param_2,undefined1 *param_3,int param_4)

{
  int iVar1;
  undefined1 uVar2;
  int extraout_r1;
  undefined1 uStack_38;
  undefined1 auStack_37 [3];
  int local_34;
  byte local_30;
  char local_2f;
  int local_20 [3];
  
  FUN_10004b08(&uStack_38,0,8);
  FUN_10000910(param_2,*(undefined4 *)(param_1 + 8));
  if (extraout_r1 != 0) {
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  FUN_1000421e(param_1,param_2,&uStack_38,8);
  iVar1 = DAT_100039a8;
  *(undefined4 *)(param_3 + 4) = param_2;
  *(int *)(param_3 + 8) = local_34;
  if (local_34 == iVar1) {
    *param_3 = 1;
    uVar2 = FUN_10004318(&uStack_38,4);
    param_3[1] = uVar2;
    uVar2 = FUN_10004318(auStack_37,4);
    param_3[2] = uVar2;
    if (param_4 != 0) {
      local_20[0] = *(int *)(param_3 + 4) + 8;
      *(undefined4 *)(param_3 + 0xc) = 0;
      *(int *)(param_3 + 0x10) = local_20[0];
      if (param_3[1] == '\x01') {
        *(int *)(param_3 + 0xc) = *(int *)(param_1 + 8) + -8;
      }
      else if (param_3[1] == '\x02') {
        *(int *)(param_3 + 0xc) = *(int *)(param_1 + 8) + -8;
        do {
          FUN_10003726(param_1,&local_30);
          if ((local_2f == '\0') && ((local_30 & 0xfb) != 1)) {
            *(undefined4 *)(param_3 + 0xc) = 0;
            return 2;
          }
          *(int *)(param_3 + 0x10) = *(int *)(param_3 + 0x10) + 0x94;
          *(int *)(param_3 + 0xc) = *(int *)(param_3 + 0xc) + -0x94;
          local_20[0] = FUN_10003874(param_1,param_3,local_20);
        } while (local_20[0] != -1);
      }
    }
    uVar2 = 0;
  }
  else {
    uVar2 = 8;
    *param_3 = 0;
  }
  return uVar2;
}

// FUNC 0x100039ac  FUN_100039ac

void FUN_100039ac(int param_1,int param_2,undefined4 param_3,undefined4 param_4,code *param_5)

{
  int iVar1;
  uint uVar2;
  undefined1 uStack_2c;
  byte local_2b;
  int local_28;
  
  do {
    uVar2 = 0;
    while( true ) {
      iVar1 = FUN_100038e0(param_1,uVar2,&uStack_2c,0);
      if ((iVar1 == 0) && (local_2b - 2 < 2)) {
        *(int *)(param_2 + 0x10) = local_28 + 8;
        do {
          FUN_10003726(param_1,param_2);
          iVar1 = (*param_5)(param_2,param_3,param_4);
          if (iVar1 != 0) {
            return;
          }
          iVar1 = FUN_10003874(param_1,&uStack_2c,param_2 + 0x10);
          *(int *)(param_2 + 0x10) = iVar1;
        } while (iVar1 != -1);
      }
      if (local_28 == -1) break;
      uVar2 = local_28 + *(int *)(param_1 + 8);
      if ((*(uint *)(param_1 + 0xc) <= uVar2) || (uVar2 == 0xffffffff)) {
        return;
      }
    }
  } while( true );
}

// FUNC 0x10003a1c  FUN_10003a1c

undefined1 FUN_10003a1c(undefined4 param_1,undefined2 param_2,undefined4 param_3)

{
  undefined2 local_12 [4];
  undefined1 local_9;
  
  local_9 = 0;
  local_12[0] = param_2;
  FUN_100039ac(param_1,param_3,local_12,&local_9,DAT_10003a44);
  return local_9;
}

// FUNC 0x10003a48  FUN_10003a48

int FUN_10003a48(int param_1,undefined4 param_2,undefined1 *param_3,int param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined1 auStack_34 [4];
  undefined1 auStack_30 [28];
  
  if (param_3 == (undefined1 *)0x0) {
    iVar1 = FUN_10003a1c(param_1,param_2,auStack_30);
    if (iVar1 == 0) {
      return 5;
    }
    param_3 = auStack_30;
  }
  if (param_4 != 0) {
    iVar1 = FUN_10004346(param_1,*(undefined4 *)(param_3 + 0x10),auStack_34,6,4,1);
  }
  else {
    iVar1 = FUN_10004346(param_1,*(undefined4 *)(param_3 + 0x10),auStack_34,6,3,0);
  }
  *(bool *)(param_1 + 0x58) = param_4 == 0;
  if (iVar1 == 0) {
    iVar3 = (*(uint *)(param_3 + 0x10) & -*(int *)(param_1 + 8)) + 1;
    iVar2 = FUN_10004380(param_1,iVar3,auStack_34,4);
    if (iVar2 == 1) {
      iVar1 = FUN_10004346(param_1,iVar3,auStack_34,4,2,1);
    }
  }
  return iVar1;
}

// FUNC 0x10003af4  FUN_10003af4

undefined4 FUN_10003af4(undefined4 param_1,int param_2,undefined1 *param_3)

{
  undefined4 uVar1;
  undefined1 auStack_14 [8];
  
  if (*(char *)(param_2 + 1) == '\x01') {
    uVar1 = FUN_10004346(param_1,*(undefined4 *)(param_2 + 4),auStack_14,4,2,1);
  }
  else {
    uVar1 = 0;
    if (*(char *)(param_2 + 1) == '\x02') {
      if (*(uint *)(param_2 + 0xc) < 0x128) {
        uVar1 = FUN_10004346(param_1,*(undefined4 *)(param_2 + 4),auStack_14,4,3,1);
        if (param_3 != (undefined1 *)0x0) {
          *param_3 = 1;
        }
      }
      else if (param_3 != (undefined1 *)0x0) {
        *param_3 = 0;
      }
    }
  }
  return uVar1;
}

// FUNC 0x10003b4c  FUN_10003b4c

undefined8
FUN_10003b4c(int param_1,int param_2,uint param_3,undefined4 param_4,undefined4 param_5,
            code *param_6,byte param_7)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar2 = (uint)param_7;
  uVar4 = param_3;
  do {
    uVar3 = 0;
    while( true ) {
      FUN_100038e0(param_1,uVar3,param_2,0,param_4,uVar2,uVar4);
      if ((param_3 == 0) || (*(byte *)(param_2 + 1) == param_3)) {
        if (uVar2 != 0) {
          FUN_100038e0(param_1,uVar3,param_2,1,param_4,uVar2,uVar4);
        }
        iVar1 = (*param_6)(param_2,param_4,param_5);
        if (iVar1 != 0) goto LAB_10003ba8;
      }
      if (*(int *)(param_2 + 4) == -1) break;
      uVar3 = *(int *)(param_2 + 4) + *(int *)(param_1 + 8);
      if ((*(uint *)(param_1 + 0xc) <= uVar3) || (uVar3 == 0xffffffff)) {
LAB_10003ba8:
        return CONCAT44(uVar2,param_4);
      }
    }
  } while( true );
}

// FUNC 0x10003bac  FUN_10003bac

int FUN_10003bac(int param_1,undefined4 param_2,undefined4 param_3)

{
  int local_28;
  uint local_24;
  int local_20;
  int local_1c;
  undefined4 local_18;
  int *local_14;
  
  local_28 = -1;
  local_14 = &local_28;
  local_24 = 0;
  local_20 = 0;
  local_1c = param_1;
  local_18 = param_3;
  FUN_10003b4c(param_1,param_2,0,&local_24,&local_20,DAT_10003c34,0);
  if (local_20 != 0) {
    FUN_10003b4c(param_1,param_2,2,&local_1c,0,DAT_10003c38,1);
  }
  if ((local_24 != 0) && (local_28 == -1)) {
    if ((local_24 < 2) && (*(char *)(param_1 + 0x28) == '\0')) {
      *(char *)(param_1 + 0x28) = '\x01';
    }
    else {
      FUN_10003b4c(param_1,param_2,1,&local_1c,0,DAT_10003c38,1);
    }
  }
  return local_28;
}

// FUNC 0x10003c3c  FUN_10003c3c

undefined4 FUN_10003c3c(int param_1,char *param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  undefined4 local_5c;
  undefined1 auStack_50 [4];
  undefined1 auStack_4c [20];
  undefined1 auStack_38 [36];
  
  if (*param_2 == '\x02') {
    FUN_10003a48(param_1,0,param_2);
  }
  iVar1 = FUN_10003bac(param_1,auStack_4c,0x94);
  local_5c = 7;
  if (iVar1 != -1) {
    if ((*(char *)(param_1 + 0x29) == '\0') ||
       (iVar2 = FUN_10003a1c(param_1,*(undefined2 *)(param_2 + 0xc),auStack_38), iVar2 == 0)) {
      iVar2 = *(int *)(param_2 + 8);
      FUN_10003af4(param_1,auStack_4c,0);
      FUN_10004346(param_1,iVar1,auStack_50,6,1,0);
      uVar3 = iVar2 + 0x10;
      local_5c = 0;
      for (uVar4 = 0; uVar4 < uVar3; uVar4 = uVar4 + iVar2) {
        iVar2 = 0x20;
        if (uVar3 <= uVar4 + 0x20) {
          iVar2 = uVar3 - uVar4;
        }
        FUN_1000421e(param_1,*(int *)(param_2 + 0x10) + 4 + uVar4,auStack_38,iVar2);
        local_5c = FUN_10004242(param_1,iVar1 + 4 + uVar4,auStack_38,iVar2,1);
      }
      FUN_10004346(param_1,iVar1,auStack_50,6,2,1);
    }
    else {
      local_5c = 0;
    }
    FUN_10003a48(param_1,0,param_2,1);
  }
  return local_5c;
}

// FUNC 0x10003dc8  FUN_10003dc8

void FUN_10003dc8(int param_1)

{
  uint local_28;
  undefined1 auStack_24 [24];
  
  local_28 = 0;
  FUN_10003b4c(param_1,auStack_24,1,&local_28,0,DAT_10003e08,0);
  if (local_28 < 2) {
    FUN_10003b4c(param_1,auStack_24,0,param_1,0,DAT_10003e0c,0);
  }
  *(undefined1 *)(param_1 + 0x28) = 0;
  return;
}

// FUNC 0x10003e10  FUN_10003e10

void FUN_10003e10(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  
  iVar1 = FUN_10003bac();
  if (iVar1 == -1) {
    if (*(char *)(param_1 + 0x28) != '\0') {
      FUN_10003dc8(param_1);
      iVar1 = FUN_10003bac(param_1,param_2,param_3);
      if (iVar1 == -1) {
        *(char *)(param_1 + 0x28) = '\0';
      }
    }
  }
  return;
}

// FUNC 0x10003e66  FUN_10003e66

uint FUN_10003e66(int param_1,undefined4 param_2,int *param_3)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  undefined1 auStack_30 [8];
  uint local_28;
  undefined4 local_1c;
  
  uVar2 = (uint)*(byte *)(param_1 + 0x10);
  if (uVar2 != 0) {
    if (*(code **)(param_1 + 0x14) != (code *)0x0) {
      (**(code **)(param_1 + 0x14))();
    }
    iVar3 = *param_3;
    uVar2 = param_3[1];
    iVar1 = FUN_10003a1c(param_1,param_2,auStack_30);
    if (iVar1 == 0) {
      param_3[4] = 0;
      uVar2 = 0;
    }
    else {
      param_3[4] = local_28;
      if (local_28 < uVar2) {
        uVar2 = local_28;
      }
      if (iVar3 != 0) {
        FUN_1000421e(param_1,local_1c,iVar3,uVar2);
      }
    }
    if (*(code **)(param_1 + 0x18) != (code *)0x0) {
      (**(code **)(param_1 + 0x18))(param_1);
    }
  }
  return uVar2;
}

// FUNC 0x10003ef4  FUN_10003ef4

int FUN_10003ef4(int param_1,undefined4 param_2,int *param_3)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  char local_2d;
  undefined1 auStack_2c [4];
  undefined4 local_28;
  undefined4 local_24;
  uint local_20;
  undefined2 local_1c;
  
  iVar6 = 8;
  if (*(char *)(param_1 + 0x10) != '\0') {
    if (*(code **)(param_1 + 0x14) != (code *)0x0) {
      (**(code **)(param_1 + 0x14))();
    }
    iVar2 = *param_3;
    if (iVar2 == 0) {
      iVar6 = FUN_10003a48(param_1,param_2,0,1);
    }
    else {
      uVar3 = param_3[1];
      iVar4 = param_1 + 0x44;
      iVar1 = FUN_10003e10(param_1,iVar4,uVar3 + 0x14);
      iVar6 = 7;
      if (iVar1 != -1) {
        iVar5 = param_1 + 0x2c;
        iVar1 = FUN_10003a1c(param_1,param_2,iVar5);
        if ((iVar1 == 0) || (iVar6 = FUN_10003a48(param_1,param_2,iVar5,0), iVar6 == 0)) {
          local_2d = '\0';
          iVar7 = *(int *)(param_1 + 0x54);
          FUN_10004b08(auStack_2c,0xff,0x14);
          local_28 = DAT_10004074;
          local_1c = (undefined2)param_2;
          local_20 = uVar3;
          if (((*(int *)(param_1 + 8) - 8U < uVar3) || (0x80 < uVar3)) ||
             ((iVar7 == -1 && (iVar7 = FUN_10003e10(param_1,iVar4,0x94), iVar7 == -1)))) {
            iVar6 = 7;
          }
          else {
            iVar6 = FUN_10003af4(param_1,iVar4,&local_2d);
            if (iVar6 == 0) {
              local_24 = FUN_100042c0(0,&local_20,8);
              local_24 = FUN_100042c0(local_24,iVar2,local_20);
              iVar6 = FUN_10004346(param_1,iVar7,auStack_2c,6,1,0);
              if (iVar6 == 0) {
                iVar6 = FUN_10004242(param_1,iVar7 + 4,&local_28,0x10,0);
                if (iVar6 == 0) {
                  iVar6 = FUN_10004242(param_1,iVar7 + 0x14,iVar2,local_20,0);
                  if (iVar6 == 0) {
                    iVar6 = FUN_10004346(param_1,iVar7,auStack_2c,6,2,1);
                    if (iVar6 == 0) {
                      if (local_2d != '\0') {
                        *(undefined1 *)(param_1 + 0x28) = 1;
                      }
                      if (iVar1 != 0) {
                        iVar6 = FUN_10003a48(param_1,param_2,iVar5,1);
                      }
                    }
                  }
                }
              }
            }
          }
        }
        if (*(char *)(param_1 + 0x28) != '\0') {
          FUN_10003dc8(param_1);
        }
      }
    }
    if (*(code **)(param_1 + 0x18) != (code *)0x0) {
      (**(code **)(param_1 + 0x18))(param_1);
    }
  }
  return iVar6;
}

// FUNC 0x1000421e  FUN_1000421e

undefined4 FUN_1000421e(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = 2;
  if (*(code **)(param_1 + 0x1c) != (code *)0x0) {
    uVar1 = (**(code **)(param_1 + 0x1c))(param_1);
  }
  return uVar1;
}

// FUNC 0x10004230  FUN_10004230

undefined4 FUN_10004230(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = 1;
  if (*(code **)(param_1 + 0x24) != (code *)0x0) {
    uVar1 = (**(code **)(param_1 + 0x24))(param_1);
  }
  return uVar1;
}

// FUNC 0x10004242  FUN_10004242

undefined4 FUN_10004242(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = 3;
  if (*(code **)(param_1 + 0x20) != (code *)0x0) {
    uVar1 = (**(code **)(param_1 + 0x20))(param_1);
  }
  return uVar1;
}

// FUNC 0x10004254  FUN_10004254

undefined4 FUN_10004254(int *param_1,int param_2,int param_3)

{
  int iVar1;
  undefined8 uVar2;
  
  iVar1 = DAT_100042b4;
  if (param_1 == (int *)0x0) {
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  if (param_2 == 0) {
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  if (param_3 == 0) {
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  if ((char)param_1[4] == '\0') {
    *param_1 = param_2;
    param_1[7] = iVar1;
    param_1[8] = DAT_100042b8;
    param_1[9] = DAT_100042bc;
    iVar1 = FUN_10001954(param_3);
    *(char *)(param_1 + 1) = (char)iVar1;
    if (iVar1 == -1) {
      return 4;
    }
    param_1[2] = 0x1000;
    iVar1 = FUN_10001944();
    iVar1 = *(int *)(iVar1 + 0xc);
    param_1[3] = iVar1;
    uVar2 = FUN_10000910(iVar1,param_1[2]);
    if ((int)((ulonglong)uVar2 >> 0x20) != 0) {
      do {
                    /* WARNING: Do nothing block with infinite loop */
      } while( true );
    }
    if ((uint)uVar2 < 2) {
      do {
                    /* WARNING: Do nothing block with infinite loop */
      } while( true );
    }
  }
  return 0;
}

// FUNC 0x100042c0  FUN_100042c0

uint FUN_100042c0(uint param_1,byte *param_2,int param_3)

{
  uint uVar1;
  byte *pbVar2;
  char cVar3;
  
  param_1 = ~param_1;
  pbVar2 = param_2 + param_3;
  for (; param_2 != pbVar2; param_2 = param_2 + 1) {
    cVar3 = '\b';
    uVar1 = param_1 ^ (uint)*param_2 << 0x18;
    do {
      param_1 = uVar1 << 1;
      if ((int)uVar1 < 0) {
        param_1 = param_1 ^ DAT_100042f0;
      }
      cVar3 = cVar3 + -1;
      uVar1 = param_1;
    } while (cVar3 != '\0');
  }
  return ~param_1;
}

// FUNC 0x100042f4  FUN_100042f4

uint FUN_100042f4(undefined1 *param_1,undefined4 param_2,uint param_3)

{
  uint uVar1;
  
  *param_1 = 0xff;
  if (param_3 == 0) {
    uVar1 = 0xffffffff;
  }
  else {
    uVar1 = param_3 - 1 >> 3;
    param_1[uVar1] = (byte)(0xff >> (param_3 & 7)) & param_1[uVar1];
  }
  return uVar1;
}

// FUNC 0x10004318  FUN_10004318

int FUN_10004318(int param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = param_2 - 2U;
  do {
    uVar2 = uVar1;
    if (uVar2 == 0xffffffff) break;
    uVar1 = uVar2 - 1;
  } while ((0x80 >> (uVar2 & 7) & (uint)*(byte *)(param_1 + (uVar2 >> 3))) != 0);
  return (uVar2 - (param_2 - 2U)) + param_2 + -1;
}

// FUNC 0x10004346  FUN_10004346

undefined8 FUN_10004346(uint param_1,int param_2,int param_3,uint param_4,uint param_5,byte param_6)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  
  uVar3 = (uint)param_6;
  if (param_4 <= param_5) {
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  if (param_3 == 0) {
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  uVar4 = param_1;
  iVar5 = param_2;
  iVar6 = param_3;
  iVar1 = FUN_100042f4(param_3);
  uVar2 = 0;
  if (iVar1 != -1) {
    uVar2 = FUN_10004242(param_1,iVar1 + param_2,param_3 + iVar1,1,uVar3,iVar5,iVar6);
    uVar4 = uVar3;
  }
  return CONCAT44(uVar4,uVar2);
}

// FUNC 0x10004380  FUN_10004380

void FUN_10004380(undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  if (param_3 == 0) {
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  FUN_1000421e();
  FUN_10004318(param_3,param_4);
  return;
}

// FUNC 0x1000439c  FUN_1000439c

void FUN_1000439c(undefined4 *param_1,undefined4 param_2,undefined4 param_3)

{
  *param_1 = param_2;
  param_1[1] = param_3;
  return;
}

// FUNC 0x100043bc  FUN_100043bc

void FUN_100043bc(undefined4 param_1)

{
  FUN_100043e4(*DAT_100043cc,param_1);
  return;
}

// FUNC 0x100043d0  FUN_100043d0

void FUN_100043d0(undefined4 param_1)

{
  FUN_10004c90(*DAT_100043e0,param_1);
  return;
}

// FUNC 0x100043e4  FUN_100043e4

int * FUN_100043e4(undefined4 *param_1,uint param_2)

{
  uint *puVar1;
  uint *puVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  int *piVar8;
  uint uVar9;
  int iVar10;
  int *piVar11;
  int iVar12;
  int *piVar13;
  uint uVar14;
  uint uVar15;
  uint *puVar16;
  uint local_30;
  
  uVar14 = param_2 + 0xb;
  if (uVar14 < 0x17) {
    if (0x10 < param_2) {
LAB_10004568:
      *param_1 = 0xc;
      return (int *)0x0;
    }
    FUN_10004bb0();
    uVar15 = 0x10;
    uVar14 = 2;
    iVar10 = 0x18;
LAB_1000440c:
    iVar10 = DAT_1000473c + iVar10;
    iVar12 = *(int *)(iVar10 + 4);
    if (iVar12 == iVar10 + -8) {
      iVar12 = *(int *)(iVar10 + 0xc);
      uVar14 = uVar14 + 2;
      if (iVar10 == iVar12) {
        iVar12 = *(int *)(DAT_1000473c + 0x10);
        iVar10 = DAT_1000473c + 8;
        if (iVar12 == iVar10) goto LAB_1000459e;
LAB_100044ac:
        uVar3 = DAT_1000473c;
        uVar4 = *(uint *)(iVar12 + 4);
        uVar6 = uVar4 & 0xfffffffc;
        uVar5 = uVar6 - uVar15;
        if (0xf < (int)uVar5) {
          iVar7 = iVar12 + uVar15;
          *(uint *)(iVar12 + 4) = uVar15 | 1;
          *(int *)(uVar3 + 0x14) = iVar7;
          *(int *)(uVar3 + 0x10) = iVar7;
          *(int *)(iVar7 + 0xc) = iVar10;
          *(int *)(iVar7 + 8) = iVar10;
          *(uint *)(iVar7 + 4) = uVar5 | 1;
          *(uint *)(iVar12 + uVar6) = uVar5;
          FUN_10004bc0(param_1);
          return (int *)(iVar12 + 8);
        }
        *(int *)(DAT_1000473c + 0x14) = iVar10;
        *(int *)(uVar3 + 0x10) = iVar10;
        if (-1 < (int)uVar5) goto LAB_1000442c;
        if (uVar6 < 0x200) {
          iVar7 = (uVar4 & 0xfffffff8) + uVar3;
          uVar4 = 1 << (uVar4 >> 5 & 0xff) | *(uint *)(uVar3 + 4);
          iVar10 = *(int *)(iVar7 + 8);
          *(uint *)(uVar3 + 4) = uVar4;
          *(int *)(iVar12 + 0xc) = iVar7;
          *(int *)(iVar12 + 8) = iVar10;
          *(int *)(iVar7 + 8) = iVar12;
          *(int *)(iVar10 + 0xc) = iVar12;
        }
        else {
          uVar5 = uVar4 >> 9;
          if (uVar5 < 5) {
            iVar10 = (uVar4 >> 6) + 0x38;
            iVar7 = ((uVar4 >> 6) + 0x39) * 8;
          }
          else if (uVar5 < 0x15) {
            iVar10 = uVar5 + 0x5b;
            iVar7 = (uVar5 + 0x5c) * 8;
          }
          else if (uVar5 < 0x55) {
            iVar10 = (uVar4 >> 0xc) + 0x6e;
            iVar7 = ((uVar4 >> 0xc) + 0x6f) * 8;
          }
          else if (uVar5 < 0x155) {
            iVar10 = (uVar4 >> 0xf) + 0x77;
            iVar7 = ((uVar4 >> 0xf) + 0x78) * 8;
          }
          else if (DAT_10004960 < uVar5) {
            iVar10 = 0x7e;
            iVar7 = 0x3f8;
          }
          else {
            iVar10 = (uVar4 >> 0x12) + 0x7c;
            iVar7 = ((uVar4 >> 0x12) + 0x7d) * 8;
          }
          piVar11 = (int *)(uVar3 + iVar7) + -2;
          piVar8 = *(int **)(uVar3 + iVar7);
          if (piVar11 == piVar8) {
            uVar4 = 1 << (iVar10 >> 2 & 0xffU) | *(uint *)(uVar3 + 4);
            *(uint *)(uVar3 + 4) = uVar4;
          }
          else {
            do {
              if ((piVar8[1] & 0xfffffffcU) <= uVar6) break;
              piVar8 = (int *)piVar8[2];
            } while (piVar11 != piVar8);
            piVar11 = (int *)piVar8[3];
            uVar4 = *(uint *)(uVar3 + 4);
          }
          *(int **)(iVar12 + 8) = piVar8;
          *(int **)(iVar12 + 0xc) = piVar11;
          piVar11[2] = iVar12;
          piVar8[3] = iVar12;
        }
        uVar6 = 1 << ((int)uVar14 >> 2 & 0xffU);
        if (uVar6 <= uVar4) goto LAB_100044f6;
        goto LAB_100045aa;
      }
    }
    uVar6 = *(uint *)(iVar12 + 4) & 0xfffffffc;
LAB_10004424:
    iVar7 = *(int *)(iVar12 + 0xc);
    iVar10 = *(int *)(iVar12 + 8);
    *(int *)(iVar10 + 0xc) = iVar7;
    *(int *)(iVar7 + 8) = iVar10;
LAB_1000442c:
    *(uint *)(iVar12 + uVar6 + 4) = *(uint *)(iVar12 + uVar6 + 4) | 1;
    FUN_10004bc0(param_1);
    return (int *)(iVar12 + 8);
  }
  uVar15 = uVar14 & 0xfffffff8;
  if (((int)uVar15 < 0) || (uVar15 < param_2)) goto LAB_10004568;
  FUN_10004bb0();
  if (uVar15 < 0x1f8) {
    uVar14 = uVar14 >> 3;
    iVar10 = uVar15 + 8;
    goto LAB_1000440c;
  }
  uVar3 = uVar14 >> 9;
  if (uVar3 == 0) {
    uVar4 = 0x3f;
    uVar3 = 0x40;
    iVar10 = 0x200;
  }
  else if (uVar3 < 5) {
    uVar4 = (uVar14 >> 6) + 0x38;
    uVar3 = (uVar14 >> 6) + 0x39;
    iVar10 = uVar3 * 8;
  }
  else if (uVar3 < 0x15) {
    uVar4 = uVar3 + 0x5b;
    uVar3 = uVar3 + 0x5c;
    iVar10 = uVar3 * 8;
  }
  else if (uVar3 < 0x55) {
    uVar4 = (uVar14 >> 0xc) + 0x6e;
    uVar3 = (uVar14 >> 0xc) + 0x6f;
    iVar10 = uVar3 * 8;
  }
  else if (uVar3 < 0x155) {
    uVar4 = (uVar14 >> 0xf) + 0x77;
    uVar3 = (uVar14 >> 0xf) + 0x78;
    iVar10 = uVar3 * 8;
  }
  else if (DAT_10004960 < uVar3) {
    uVar3 = 0x7f;
    uVar4 = 0x7e;
    iVar10 = 0x3f8;
  }
  else {
    uVar4 = (uVar14 >> 0x12) + 0x7c;
    uVar3 = (uVar14 >> 0x12) + 0x7d;
    iVar10 = uVar3 * 8;
  }
  for (iVar12 = *(int *)(DAT_1000473c + iVar10 + 4); uVar14 = uVar3,
      DAT_1000473c + iVar10 + -8 != iVar12; iVar12 = *(int *)(iVar12 + 0xc)) {
    uVar6 = *(uint *)(iVar12 + 4) & 0xfffffffc;
    uVar14 = uVar4;
    if (0xf < (int)(uVar6 - uVar15)) break;
    if (-1 < (int)(uVar6 - uVar15)) goto LAB_10004424;
  }
  iVar12 = *(int *)(DAT_1000473c + 0x10);
  iVar10 = DAT_1000473c + 8;
  if (iVar12 != iVar10) goto LAB_100044ac;
LAB_1000459e:
  uVar4 = *(uint *)(DAT_1000473c + 4);
  uVar6 = 1 << ((int)uVar14 >> 2 & 0xffU);
  uVar3 = DAT_1000473c;
  if (uVar6 <= uVar4) {
LAB_100044f6:
    if ((uVar4 & uVar6) == 0) {
      uVar14 = uVar14 & 0xfffffffc;
      do {
        uVar6 = uVar6 << 1;
        uVar14 = uVar14 + 4;
      } while ((uVar4 & uVar6) == 0);
    }
    do {
      piVar8 = (int *)(uVar14 * 8 + uVar3);
      uVar4 = uVar14;
      piVar11 = piVar8;
      do {
        for (piVar13 = (int *)piVar11[3]; piVar11 != piVar13; piVar13 = (int *)piVar13[3]) {
          uVar9 = piVar13[1] & 0xfffffffc;
          uVar5 = uVar9 - uVar15;
          if (0xf < (int)uVar5) {
            iVar12 = (int)piVar13 + uVar15;
            piVar13[1] = uVar15 | 1;
            iVar10 = piVar13[2];
            iVar7 = piVar13[3];
            *(int *)(iVar10 + 0xc) = iVar7;
            *(int *)(iVar7 + 8) = iVar10;
            *(int *)(uVar3 + 0x14) = iVar12;
            *(int *)(uVar3 + 0x10) = iVar12;
            *(uint *)(iVar12 + 4) = uVar5 | 1;
            *(uint *)(iVar12 + 0xc) = uVar3 + 8;
            *(uint *)(iVar12 + 8) = uVar3 + 8;
            *(uint *)((int)piVar13 + uVar9) = uVar5;
            FUN_10004bc0(param_1);
            return piVar13 + 2;
          }
          if (-1 < (int)uVar5) {
            *(uint *)((int)piVar13 + uVar9 + 4) = *(uint *)((int)piVar13 + uVar9 + 4) | 1;
            iVar12 = piVar13[3];
            iVar10 = piVar13[2];
            *(int *)(iVar10 + 0xc) = iVar12;
            *(int *)(iVar12 + 8) = iVar10;
            FUN_10004bc0(param_1);
            return piVar13 + 2;
          }
        }
        piVar11 = piVar11 + 2;
        uVar4 = uVar4 + 1;
      } while ((uVar4 & 3) != 0);
      do {
        if ((uVar14 & 3) == 0) {
          uVar5 = *(uint *)(uVar3 + 4) & ~uVar6;
          *(uint *)(uVar3 + 4) = uVar5;
          goto LAB_10004832;
        }
        piVar13 = piVar8 + -2;
        piVar11 = (int *)*piVar8;
        uVar14 = uVar14 - 1;
        piVar8 = piVar13;
      } while (piVar11 == piVar13);
      uVar5 = *(uint *)(uVar3 + 4);
LAB_10004832:
      uVar6 = uVar6 * 2;
      if ((uVar5 <= uVar6 && uVar6 - uVar5 != 0) || (uVar14 = uVar4, uVar6 == 0)) break;
      for (; (uVar5 & uVar6) == 0; uVar6 = uVar6 << 1) {
        uVar14 = uVar14 + 4;
      }
    } while( true );
  }
LAB_100045aa:
  puVar1 = DAT_10004740;
  uVar14 = *(uint *)(uVar3 + 8);
  uVar4 = *(uint *)(uVar14 + 4) & 0xfffffffc;
  if ((uVar15 <= uVar4) && (uVar6 = uVar4 - uVar15, 0xf < (int)uVar6)) goto LAB_100046d2;
  uVar6 = uVar14 + uVar4;
  if (*DAT_10004740 == 0xffffffff) {
    local_30 = uVar15 + *DAT_10004744 + 0x10;
  }
  else {
    local_30 = uVar15 + *DAT_10004744 + DAT_10004748 & 0xfffff000;
  }
  uVar5 = FUN_10004bd0(param_1,local_30);
  puVar2 = DAT_1000495c;
  puVar16 = DAT_1000474c;
  if (uVar5 == 0xffffffff) {
LAB_100047e8:
    uVar5 = *(uint *)(uVar3 + 8);
    local_30 = *(uint *)(uVar5 + 4);
  }
  else {
    if (uVar5 < uVar6) {
      if (uVar14 == uVar3) {
        uVar9 = local_30 + *DAT_1000495c;
        *DAT_1000495c = uVar9;
        puVar16 = puVar2;
        goto LAB_1000461a;
      }
      goto LAB_100047e8;
    }
    uVar9 = local_30 + *DAT_1000474c;
    *DAT_1000474c = uVar9;
    if ((uVar6 == uVar5) && ((uVar6 & 0xfff) == 0)) {
      uVar5 = *(uint *)(uVar3 + 8);
      local_30 = local_30 + uVar4 | 1;
      *(uint *)(uVar5 + 4) = local_30;
    }
    else {
LAB_1000461a:
      if (*puVar1 == 0xffffffff) {
        *puVar1 = uVar5;
      }
      else {
        *puVar16 = (uVar5 - uVar6) + uVar9;
      }
      uVar6 = uVar5 & 7;
      if ((uVar5 & 7) == 0) {
        uVar9 = -(local_30 + uVar5) & 0xfff;
        iVar10 = FUN_10004bd0(param_1,uVar9);
        if (iVar10 == -1) {
          uVar9 = 0;
        }
        else {
LAB_10004668:
          local_30 = (iVar10 - uVar5) + uVar9;
        }
      }
      else {
        uVar5 = (uVar5 - uVar6) + 8;
        uVar9 = (DAT_10004750 - uVar6) - (local_30 + uVar5) & 0xfff;
        iVar10 = FUN_10004bd0(param_1,uVar9);
        if (iVar10 != -1) goto LAB_10004668;
        local_30 = ((uVar6 - 8) + local_30 + uVar5) - uVar5;
        uVar9 = 0;
      }
      uVar9 = *puVar16 + uVar9;
      *puVar16 = uVar9;
      *(uint *)(uVar3 + 8) = uVar5;
      local_30 = local_30 | 1;
      *(uint *)(uVar5 + 4) = local_30;
      if (uVar14 != uVar3) {
        if (uVar4 < 0x10) {
          *(undefined4 *)(uVar5 + 4) = 1;
          goto LAB_100047fc;
        }
        uVar4 = uVar4 - 0xc & 0xfffffff8;
        *(uint *)(uVar14 + 4) = *(uint *)(uVar14 + 4) & 1 | uVar4;
        *(undefined4 *)(uVar14 + uVar4 + 4) = 5;
        *(undefined4 *)(uVar14 + uVar4 + 8) = 5;
        if (uVar4 < 0x10) {
          local_30 = *(uint *)(uVar5 + 4);
        }
        else {
          FUN_10004c90(param_1,uVar14 + 8);
          uVar5 = *(uint *)(uVar3 + 8);
          uVar9 = *puVar16;
          local_30 = *(uint *)(uVar5 + 4);
        }
      }
    }
    if (*DAT_10004754 < uVar9) {
      *DAT_10004754 = uVar9;
    }
    if (*DAT_10004758 < uVar9) {
      *DAT_10004758 = uVar9;
    }
  }
  uVar6 = (local_30 & 0xfffffffc) - uVar15;
  if ((uVar15 <= (local_30 & 0xfffffffc)) && (uVar14 = uVar5, 0xf < (int)uVar6)) {
LAB_100046d2:
    *(uint *)(uVar14 + 4) = uVar15 | 1;
    *(uint *)(uVar3 + 8) = uVar14 + uVar15;
    *(uint *)(uVar14 + uVar15 + 4) = uVar6 | 1;
    FUN_10004bc0(param_1);
    return (int *)(uVar14 + 8);
  }
LAB_100047fc:
  FUN_10004bc0(param_1);
  return (int *)0x0;
}

// FUNC 0x10004964  FUN_10004964

int FUN_10004964(int *param_1,int *param_2,uint param_3)

{
  int iVar1;
  bool bVar2;
  
  if (3 < param_3) {
    if ((((uint)param_1 | (uint)param_2) & 3) != 0) goto LAB_1000498a;
    do {
      if (*param_1 != *param_2) goto LAB_1000498a;
      param_3 = param_3 - 4;
      param_1 = param_1 + 1;
      param_2 = param_2 + 1;
    } while (3 < param_3);
  }
  if (param_3 == 0) {
    return 0;
  }
LAB_1000498a:
  iVar1 = 0;
  do {
    if ((uint)*(byte *)((int)param_1 + iVar1) != (uint)*(byte *)((int)param_2 + iVar1)) {
      return (uint)*(byte *)((int)param_1 + iVar1) - (uint)*(byte *)((int)param_2 + iVar1);
    }
    bVar2 = param_3 - 1 != iVar1;
    iVar1 = iVar1 + 1;
  } while (bVar2);
  return 0;
}

// FUNC 0x100049ac  FUN_100049ac

void FUN_100049ac(undefined4 *param_1,undefined4 *param_2,uint param_3)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  undefined4 uVar7;
  bool bVar8;
  
  uVar4 = param_3;
  if (0xf < param_3) {
    uVar6 = ((uint)param_2 | (uint)param_1) & 3;
    if ((((uint)param_2 | (uint)param_1) & 3) != 0) {
      iVar5 = param_3 - 1;
      goto LAB_10004a26;
    }
    uVar4 = param_3 - 0x10 >> 4;
    puVar1 = param_1;
    puVar3 = param_2;
    do {
      uVar7 = puVar3[1];
      *puVar1 = *puVar3;
      puVar1[1] = uVar7;
      uVar7 = puVar3[3];
      puVar1[2] = puVar3[2];
      puVar1[3] = uVar7;
      puVar3 = puVar3 + 4;
      bVar8 = puVar1 != param_1 + uVar4 * 4;
      puVar1 = puVar1 + 4;
    } while (bVar8);
    iVar5 = uVar4 + 1;
    param_2 = param_2 + iVar5 * 4;
    uVar4 = param_3 & 0xf;
    param_1 = param_1 + iVar5 * 4;
    if ((param_3 & 0xc) != 0) {
      do {
        *(undefined4 *)((int)param_1 + uVar6) = *(undefined4 *)((int)param_2 + uVar6);
        uVar6 = uVar6 + 4;
      } while (3 < uVar4 - uVar6);
      iVar5 = (uVar4 - 4 >> 2) + 1;
      param_1 = param_1 + iVar5;
      param_2 = param_2 + iVar5;
      uVar4 = param_3 & 3;
    }
  }
  iVar5 = uVar4 - 1;
  if (uVar4 == 0) {
    return;
  }
LAB_10004a26:
  iVar2 = 0;
  do {
    *(undefined1 *)((int)param_1 + iVar2) = *(undefined1 *)((int)param_2 + iVar2);
    bVar8 = iVar5 != iVar2;
    iVar2 = iVar2 + 1;
  } while (bVar8);
  return;
}

// FUNC 0x10004a50  FUN_10004a50

void FUN_10004a50(undefined4 *param_1,undefined4 *param_2,uint param_3)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  uint uVar6;
  uint uVar7;
  bool bVar8;
  
  if ((param_2 < param_1) && (param_1 < (undefined4 *)((int)param_2 + param_3))) {
    iVar2 = param_3 - 1;
    if (param_3 == 0) {
      return;
    }
    do {
      *(undefined1 *)((int)param_1 + iVar2) = *(undefined1 *)((int)param_2 + iVar2);
      bVar8 = iVar2 != 0;
      iVar2 = iVar2 + -1;
    } while (bVar8);
    return;
  }
  uVar6 = param_3;
  if (0xf < param_3) {
    uVar7 = ((uint)param_2 | (uint)param_1) & 3;
    if ((((uint)param_2 | (uint)param_1) & 3) != 0) {
      iVar2 = param_3 - 1;
      goto LAB_10004a80;
    }
    uVar6 = param_3 - 0x10 >> 4;
    puVar4 = param_1;
    puVar5 = param_2;
    do {
      *puVar4 = *puVar5;
      puVar4[1] = puVar5[1];
      puVar4[2] = puVar5[2];
      puVar1 = puVar5 + 3;
      puVar5 = puVar5 + 4;
      puVar4[3] = *puVar1;
      bVar8 = puVar4 != param_1 + uVar6 * 4;
      puVar4 = puVar4 + 4;
    } while (bVar8);
    iVar2 = uVar6 + 1;
    param_2 = param_2 + iVar2 * 4;
    uVar6 = param_3 & 0xf;
    param_1 = param_1 + iVar2 * 4;
    if ((param_3 & 0xc) != 0) {
      do {
        *(undefined4 *)((int)param_1 + uVar7) = *(undefined4 *)((int)param_2 + uVar7);
        uVar7 = uVar7 + 4;
      } while (3 < uVar6 - uVar7);
      iVar2 = (uVar6 - 4 >> 2) + 1;
      param_1 = param_1 + iVar2;
      param_2 = param_2 + iVar2;
      uVar6 = param_3 & 3;
    }
  }
  iVar2 = uVar6 - 1;
  if (uVar6 == 0) {
    return;
  }
LAB_10004a80:
  iVar3 = 0;
  do {
    *(undefined1 *)((int)param_1 + iVar3) = *(undefined1 *)((int)param_2 + iVar3);
    bVar8 = iVar2 != iVar3;
    iVar3 = iVar3 + 1;
  } while (bVar8);
  return;
}

// FUNC 0x10004b08  FUN_10004b08

void FUN_10004b08(undefined4 *param_1,undefined1 param_2,uint param_3)

{
  uint uVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  uint uVar4;
  bool bVar5;
  
  if (((uint)param_1 & 3) != 0) {
    uVar1 = param_3 - 1;
    puVar2 = param_1;
    if (param_3 == 0) {
      return;
    }
    while( true ) {
      param_1 = (undefined4 *)((int)param_1 + 1);
      *(undefined1 *)puVar2 = param_2;
      param_3 = uVar1;
      if (((uint)param_1 & 3) == 0) break;
      bVar5 = uVar1 == 0;
      uVar1 = uVar1 - 1;
      puVar2 = (undefined4 *)((int)puVar2 + 1);
      if (bVar5) {
        return;
      }
    }
  }
  uVar1 = param_3;
  if (3 < param_3) {
    uVar3 = CONCAT22(CONCAT11(param_2,param_2),CONCAT11(param_2,param_2));
    if (0xf < param_3) {
      uVar4 = param_3 - 0x10 >> 4;
      puVar2 = param_1;
      do {
        *puVar2 = uVar3;
        puVar2[1] = uVar3;
        puVar2[2] = uVar3;
        puVar2[3] = uVar3;
        puVar2 = puVar2 + 4;
      } while (puVar2 != param_1 + uVar4 * 4 + 4);
      uVar1 = param_3 & 0xf;
      param_1 = param_1 + (uVar4 + 1) * 4;
      uVar4 = param_3 & 0xc;
      param_3 = uVar1;
      if (uVar4 == 0) goto LAB_10004b90;
    }
    uVar1 = param_3 - 4 >> 2;
    puVar2 = param_1;
    do {
      *puVar2 = uVar3;
      puVar2 = puVar2 + 1;
    } while (puVar2 != param_1 + uVar1 + 1);
    param_1 = param_1 + uVar1 + 1;
    uVar1 = param_3 & 3;
  }
LAB_10004b90:
  if (uVar1 != 0) {
    puVar2 = (undefined4 *)((int)param_1 + uVar1);
    do {
      *(undefined1 *)param_1 = param_2;
      param_1 = (undefined4 *)((int)param_1 + 1);
    } while (puVar2 != param_1);
  }
  return;
}

// FUNC 0x10004bb0  FUN_10004bb0

void FUN_10004bb0(void)

{
  FUN_10004e54(DAT_10004bbc);
  return;
}

// FUNC 0x10004bc0  FUN_10004bc0

void FUN_10004bc0(void)

{
  FUN_10004e58(DAT_10004bcc);
  return;
}

// FUNC 0x10004bd0  FUN_10004bd0

void FUN_10004bd0(int *param_1,undefined4 param_2)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = DAT_10004bf0;
  *DAT_10004bf0 = 0;
  iVar2 = FUN_10000c6c(param_2);
  if ((iVar2 == -1) && (*piVar1 != 0)) {
    *param_1 = *piVar1;
  }
  return;
}

// FUNC 0x10004bf4  FUN_10004bf4

undefined4 FUN_10004bf4(undefined4 param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  
  FUN_10004bb0();
  iVar2 = DAT_10004c80;
  uVar4 = *(uint *)(*(int *)(DAT_10004c80 + 8) + 4) & 0xfffffffc;
  iVar3 = ((uVar4 - param_2) + DAT_10004c84 >> 0xc) - 1;
  if ((DAT_10004c84 + 0x11 <= iVar3 * 0x1000) &&
     (iVar1 = FUN_10004bd0(param_1,0), iVar1 == *(int *)(iVar2 + 8) + uVar4)) {
    iVar1 = FUN_10004bd0(param_1,iVar3 * -0x1000);
    if (iVar1 != -1) {
      *(uint *)(*(int *)(iVar2 + 8) + 4) = uVar4 + iVar3 * -0x1000 | 1;
      *DAT_10004c88 = *DAT_10004c88 + iVar3 * -0x1000;
      FUN_10004bc0(param_1);
      return 1;
    }
    iVar3 = FUN_10004bd0(param_1,0);
    iVar2 = *(int *)(iVar2 + 8);
    uVar4 = iVar3 - iVar2;
    if (0xf < (int)uVar4) {
      *DAT_10004c88 = iVar3 - *DAT_10004c8c;
      *(uint *)(iVar2 + 4) = uVar4 | 1;
    }
  }
  FUN_10004bc0(param_1);
  return 0;
}

// FUNC 0x10004c90  FUN_10004c90

void FUN_10004c90(undefined4 param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  int *piVar7;
  uint uVar8;
  int iVar9;
  int *piVar10;
  uint *puVar11;
  
  if (param_2 == 0) {
    return;
  }
  FUN_10004bb0();
  iVar1 = DAT_10004e40;
  piVar2 = (int *)(param_2 + -8);
  uVar8 = *(uint *)(param_2 + -4);
  uVar3 = uVar8 & 0xfffffffe;
  puVar11 = (uint *)((int)piVar2 + uVar3);
  uVar5 = puVar11[1] & 0xfffffffc;
  if (*(uint **)(DAT_10004e40 + 8) == puVar11) {
    uVar3 = uVar3 + uVar5;
    if ((uVar8 & 1) == 0) {
      iVar9 = *piVar2;
      piVar2 = (int *)((int)piVar2 - iVar9);
      iVar6 = piVar2[2];
      uVar3 = uVar3 + iVar9;
      iVar9 = piVar2[3];
      *(int *)(iVar6 + 0xc) = iVar9;
      *(int *)(iVar9 + 8) = iVar6;
    }
    piVar2[1] = uVar3 | 1;
    puVar11 = DAT_10004e48;
    *(int **)(iVar1 + 8) = piVar2;
    if (*puVar11 <= uVar3) {
      FUN_10004bf4(param_1,*DAT_10004e4c);
    }
    goto LAB_10004d38;
  }
  puVar11[1] = uVar5;
  if ((uVar8 & 1) == 0) {
    iVar9 = *piVar2;
    piVar2 = (int *)((int)piVar2 - iVar9);
    uVar3 = uVar3 + iVar9;
    iVar9 = piVar2[2];
    if (iVar9 == iVar1 + 8) {
      if ((*(uint *)((int)puVar11 + uVar5 + 4) & 1) == 0) {
        uVar8 = puVar11[2];
        uVar4 = puVar11[3];
        uVar3 = uVar3 + uVar5;
        *(uint *)(uVar8 + 0xc) = uVar4;
        *(uint *)(uVar4 + 8) = uVar8;
        piVar2[1] = uVar3 | 1;
        *(uint *)((int)piVar2 + uVar3) = uVar3;
      }
      else {
        piVar2[1] = uVar3 | 1;
        *puVar11 = uVar3;
      }
      goto LAB_10004d38;
    }
    iVar6 = piVar2[3];
    *(int *)(iVar9 + 0xc) = iVar6;
    *(int *)(iVar6 + 8) = iVar9;
    if ((*(uint *)((int)puVar11 + uVar5 + 4) & 1) != 0) goto LAB_10004d0e;
LAB_10004cea:
    uVar8 = puVar11[2];
    uVar3 = uVar3 + uVar5;
    if (uVar8 == DAT_10004e44) {
      *(int **)(uVar8 + 0xc) = piVar2;
      *(int **)(uVar8 + 8) = piVar2;
      piVar2[3] = uVar8;
      piVar2[2] = uVar8;
      piVar2[1] = uVar3 | 1;
      *(uint *)((int)piVar2 + uVar3) = uVar3;
      goto LAB_10004d38;
    }
    uVar5 = puVar11[3];
    *(uint *)(uVar8 + 0xc) = uVar5;
    *(uint *)(uVar5 + 8) = uVar8;
    piVar2[1] = uVar3 | 1;
    *(uint *)((int)piVar2 + uVar3) = uVar3;
  }
  else {
    if ((*(uint *)((int)puVar11 + uVar5 + 4) & 1) == 0) goto LAB_10004cea;
LAB_10004d0e:
    piVar2[1] = uVar3 | 1;
    *puVar11 = uVar3;
  }
  if (uVar3 < 0x200) {
    *(uint *)(iVar1 + 4) = 1 << (uVar3 >> 5 & 0xff) | *(uint *)(iVar1 + 4);
    iVar1 = (uVar3 & 0xfffffff8) + iVar1;
    iVar9 = *(int *)(iVar1 + 8);
    piVar2[3] = iVar1;
    piVar2[2] = iVar9;
    *(int **)(iVar1 + 8) = piVar2;
    *(int **)(iVar9 + 0xc) = piVar2;
  }
  else {
    uVar5 = uVar3 >> 9;
    if (uVar5 < 5) {
      iVar6 = (uVar3 >> 6) + 0x38;
      iVar9 = ((uVar3 >> 6) + 0x39) * 8;
    }
    else if (uVar5 < 0x15) {
      iVar6 = uVar5 + 0x5b;
      iVar9 = (uVar5 + 0x5c) * 8;
    }
    else if (uVar5 < 0x55) {
      iVar6 = (uVar3 >> 0xc) + 0x6e;
      iVar9 = ((uVar3 >> 0xc) + 0x6f) * 8;
    }
    else if (uVar5 < 0x155) {
      iVar6 = (uVar3 >> 0xf) + 0x77;
      iVar9 = ((uVar3 >> 0xf) + 0x78) * 8;
    }
    else if (DAT_10004e50 < uVar5) {
      iVar6 = 0x7e;
      iVar9 = 0x3f8;
    }
    else {
      iVar6 = (uVar3 >> 0x12) + 0x7c;
      iVar9 = ((uVar3 >> 0x12) + 0x7d) * 8;
    }
    piVar7 = *(int **)(iVar1 + iVar9);
    piVar10 = (int *)(iVar1 + iVar9) + -2;
    if (piVar10 == piVar7) {
      *(uint *)(iVar1 + 4) = 1 << (iVar6 >> 2 & 0xffU) | *(uint *)(iVar1 + 4);
    }
    else {
      do {
        if ((piVar7[1] & 0xfffffffcU) <= uVar3) break;
        piVar7 = (int *)piVar7[2];
      } while (piVar10 != piVar7);
      piVar10 = (int *)piVar7[3];
    }
    piVar2[3] = (int)piVar10;
    piVar2[2] = (int)piVar7;
    piVar10[2] = (int)piVar2;
    piVar7[3] = (int)piVar2;
  }
LAB_10004d38:
  FUN_10004bc0(param_1);
  return;
}

// FUNC 0x10004e54  FUN_10004e54

void FUN_10004e54(void)

{
  return;
}

// FUNC 0x10004e58  FUN_10004e58

void FUN_10004e58(void)

{
  return;
}

// FUNC 0x10004e60  flash_write_page

void flash_write_page(undefined4 param_1)

{
                    /* WARNING: Could not recover jumptable at 0x10004e68. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*DAT_10004e6c)(param_1);
  return;
}

// FUNC 0x10004e80  FUN_10004e80

void FUN_10004e80(undefined4 param_1)

{
                    /* WARNING: Could not recover jumptable at 0x10004e88. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*DAT_10004e8c)(param_1);
  return;
}

// FUNC 0x10004ea0  flash_begin

void flash_begin(undefined4 param_1)

{
                    /* WARNING: Could not recover jumptable at 0x10004ea8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*DAT_10004eac)(param_1);
  return;
}

// FUNC 0x10004eb0  flash_end

void flash_end(undefined4 param_1)

{
                    /* WARNING: Could not recover jumptable at 0x10004eb8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*DAT_10004ebc)(param_1);
  return;
}

// FUNC 0x10004ec0  flash_status

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void flash_status(undefined4 param_1)

{
                    /* WARNING: Could not recover jumptable at 0x10004ec8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*_DAT_10004ecc)(param_1);
  return;
}

