// FUNC 0x1004dd24  FUN_1004dd24

void FUN_1004dd24(void)

{
  uint *puVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  undefined4 *puVar7;
  undefined4 uVar8;
  int iVar9;
  uint uVar10;
  undefined4 *puVar11;
  
  puVar1 = DAT_1004ddd4;
  FUN_1004dc24(0);
  log_printf(DAT_1004ddd8);
  puVar2 = DAT_1004dde4;
  puVar7 = DAT_1004dde0;
  if (*DAT_1004dddc == '\x01') {
    uVar3 = DAT_1004dde0[1];
    uVar8 = DAT_1004dde0[2];
    puVar11 = DAT_1004dde0 + 3;
    *DAT_1004dde4 = *DAT_1004dde0;
    puVar2[1] = uVar3;
    puVar2[2] = uVar8;
    iVar9 = 0;
    puVar2[3] = *puVar11;
    FUN_1004dcec(puVar7);
    do {
      uVar5 = puVar2[iVar9];
      uVar6 = DAT_1004dde0[iVar9];
      if ((uVar5 ^ uVar6) != 0) {
        uVar10 = 0;
        do {
          uVar4 = 1 << (uVar10 & 0xff);
          if (((uVar4 & (uVar5 ^ uVar6)) != 0) && ((code *)*DAT_1004dde8 != (code *)0x0)) {
            (*(code *)*DAT_1004dde8)(iVar9,uVar10,(uVar4 & DAT_1004dde0[iVar9]) != 0);
          }
          uVar10 = uVar10 + 1;
        } while (uVar10 != 5);
      }
      iVar9 = iVar9 + 1;
    } while (iVar9 != 4);
  }
  else {
    uVar5 = (puVar1[8] << 1) >> 0x1b;
    puVar7 = DAT_1004ddf0;
    if ((uVar5 != 0) && (puVar7 = DAT_1004ddf4, uVar5 == 1)) {
      puVar7 = DAT_1004ddec;
    }
    if ((code *)*puVar7 != (code *)0x0) {
      (*(code *)*puVar7)();
    }
  }
  *puVar1 = *puVar1 | 0x800;
  return;
}


