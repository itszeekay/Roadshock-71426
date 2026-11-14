// FUNC 0x100512ec  FUN_100512ec

void FUN_100512ec(void)

{
  char cVar1;
  char cVar2;
  bool bVar3;
  bool bVar4;
  bool bVar5;
  int iVar6;
  uint uVar7;
  char *pcVar8;
  int iVar9;
  undefined1 local_40;
  undefined1 local_38 [36];
  
  bVar5 = false;
  FUN_10056f28(local_38,0,0x1e);
  iVar9 = 1;
  FUN_10056d88();
  uVar7 = 0;
  bVar3 = false;
  bVar4 = false;
  pcVar8 = DAT_10051464;
  do {
    cVar1 = pcVar8[5];
    cVar2 = pcVar8[6];
    pcVar8[4] = cVar1;
    pcVar8[5] = cVar2;
    local_40 = (undefined1)iVar9;
    if (cVar1 == '\0') {
      if (cVar2 == '\x01') {
        local_38[uVar7 * 2] = *(undefined1 *)(iVar9 + DAT_10051468);
        local_38[uVar7 * 2 + 1] = local_40;
        uVar7 = uVar7 + 1 & 0xff;
        if (iVar9 == 0xe) {
          bVar5 = true;
        }
        if ((*(char *)(DAT_1005146c + 0x12) == '\0') && (iVar9 == 0xd)) {
          return;
        }
        FUN_1004bf28(DAT_10051470,iVar9);
        bVar3 = true;
      }
    }
    else if (cVar1 == '\x01') {
      if (cVar2 == '\x01') {
        cVar1 = pcVar8[7];
        pcVar8[7] = cVar1 + 1U;
        iVar6 = uVar7 * 2;
        if ((byte)(cVar1 + 1U) < 0x19) {
          local_38[iVar6] = *(undefined1 *)(iVar9 + DAT_10051468);
          local_38[iVar6 + 1] = local_40;
          bVar4 = true;
        }
        else {
          local_38[iVar6] = 0xff;
          local_38[iVar6 + 1] = local_40;
          pcVar8[7] = '\0';
        }
        uVar7 = uVar7 + 1 & 0xff;
        if (iVar9 == 0xe) {
          bVar5 = true;
        }
      }
      else if (cVar2 == '\0') {
        local_38[uVar7 * 2] = 0;
        local_38[uVar7 * 2 + 1] = local_40;
        uVar7 = uVar7 + 1 & 0xff;
        pcVar8[7] = '\0';
        bVar3 = true;
        if (iVar9 == 0xe) {
          bVar5 = true;
        }
      }
    }
    iVar6 = DAT_1005146c;
    iVar9 = iVar9 + 1;
    pcVar8 = pcVar8 + 4;
  } while (iVar9 != 0xf);
  if ((!bVar3) && (bVar4)) {
    return;
  }
  if (uVar7 == 0) {
    return;
  }
  if ((bVar5) && (uVar7 == 1)) {
    if (*(char *)(DAT_1005146c + 0x12) == '\0') {
      FUN_10050354(*(undefined1 *)(DAT_1005146c + 8),*(undefined1 *)(DAT_1005146c + 9),
                   *(undefined1 *)(DAT_1005146c + 10),*(undefined1 *)(DAT_1005146c + 0xb),
                   *(undefined1 *)(DAT_1005146c + 0xc));
      pcVar8 = DAT_10051474;
      *(undefined1 *)(iVar6 + 0x12) = 1;
      if (*pcVar8 != '\0') {
        *DAT_10051478 = 1;
        FUN_10053918(0x2d,100);
      }
      FUN_1004eae0();
      FUN_10051564();
      goto LAB_10051458;
    }
  }
  else if (*(char *)(DAT_1005146c + 0x12) == '\0') {
    FUN_10050354(*(undefined1 *)(DAT_1005146c + 8),*(undefined1 *)(DAT_1005146c + 9),
                 *(undefined1 *)(DAT_1005146c + 10),*(undefined1 *)(DAT_1005146c + 0xb),
                 *(undefined1 *)(DAT_1005146c + 0xc));
    pcVar8 = DAT_10051474;
    *(undefined1 *)(iVar6 + 0x12) = 1;
    if (*pcVar8 != '\0') {
      *DAT_10051478 = 1;
      FUN_10053918(0x2d,100);
    }
    FUN_1004eae0();
    FUN_10051564();
    return;
  }
  FUN_10053930(0x33);
LAB_10051458:
  FUN_10050530(local_38,uVar7);
  return;
}


