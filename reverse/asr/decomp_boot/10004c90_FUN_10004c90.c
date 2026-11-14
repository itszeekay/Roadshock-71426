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


