// FUNC 0x1005189c  FUN_1005189c

void FUN_1005189c(uint param_1,uint param_2,int param_3)

{
  bool bVar1;
  int iVar2;
  byte bVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  char *pcVar7;
  int iVar8;
  byte bVar9;
  uint local_28;
  
  iVar2 = DAT_100519e8;
  iVar4 = 0;
  pcVar7 = (char *)(DAT_100519e8 + 0x1f);
  do {
    if (*pcVar7 != '\0') {
      bVar1 = false;
      for (uVar5 = 0; (uVar5 & 0xff) < (uint)(byte)pcVar7[1]; uVar5 = uVar5 + 1) {
        if ((byte)pcVar7[uVar5 + 2] == param_1) {
          bVar1 = true;
        }
      }
      if (bVar1) {
        local_28 = 0;
        iVar4 = DAT_100519e8 + iVar4 * 0xe;
        break;
      }
    }
    iVar4 = iVar4 + 1;
    pcVar7 = pcVar7 + 0xe;
    if (iVar4 == 4) {
      return;
    }
  } while( true );
LAB_100518f2:
  if (*(byte *)(iVar4 + 0x20) <= local_28) {
    return;
  }
  uVar5 = *(byte *)(iVar4 + local_28 + 0x21) - 1 & 0xff;
  if (uVar5 < 0xc) {
    uVar6 = uVar5 >> 1;
    if ((int)(uVar5 << 0x1f) < 0) {
      if (1 < (*(byte *)(iVar2 + uVar6 + 0x57) & 0xf) - 2) {
        if (((param_2 & 0xfffffffb) == 0) || (param_2 == 6)) {
          bVar9 = *(byte *)(param_3 + uVar6) & 0xf0;
          iVar8 = DAT_100519e8 + uVar6;
          *(byte *)(param_3 + uVar6) = bVar9;
          bVar3 = FUN_10051734(*(byte *)(iVar8 + 0x57) & 0xf);
        }
        else {
          if (((param_2 & 0xfffffffb) != 1) && (param_2 != 7)) goto LAB_100519d0;
          iVar8 = DAT_100519e8 + uVar6;
          bVar9 = *(byte *)(param_3 + uVar6) & 0xf0;
          *(byte *)(param_3 + uVar6) = bVar9;
          bVar3 = FUN_1005187c(*(byte *)(iVar8 + 0x57) & 0xf);
        }
LAB_100519cc:
        *(byte *)(param_3 + uVar6) = bVar9 | bVar3;
      }
    }
    else if (1 < (*(byte *)(iVar2 + uVar6 + 0x57) >> 4) - 2) {
      if (((param_2 & 0xfffffffb) == 0) || (param_2 == 6)) {
        bVar9 = *(byte *)(param_3 + uVar6) & 0xf;
        *(byte *)(param_3 + uVar6) = bVar9;
        iVar8 = FUN_10051734(*(byte *)(iVar2 + uVar6 + 0x57) >> 4);
      }
      else {
        if (((param_2 & 0xfffffffb) != 1) && (param_2 != 7)) goto LAB_100519d0;
        bVar9 = *(byte *)(param_3 + uVar6) & 0xf;
        *(byte *)(param_3 + uVar6) = bVar9;
        iVar8 = FUN_1005187c(*(byte *)(iVar2 + uVar6 + 0x57) >> 4);
      }
      bVar3 = (byte)(iVar8 << 4);
      goto LAB_100519cc;
    }
  }
LAB_100519d0:
  local_28 = local_28 + 1 & 0xff;
  goto LAB_100518f2;
}


