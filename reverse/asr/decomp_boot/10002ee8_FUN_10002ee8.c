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


