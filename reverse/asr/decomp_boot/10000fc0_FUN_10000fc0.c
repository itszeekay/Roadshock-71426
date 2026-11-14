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


