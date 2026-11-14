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


