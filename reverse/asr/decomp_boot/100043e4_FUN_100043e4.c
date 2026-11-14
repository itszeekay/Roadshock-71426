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


