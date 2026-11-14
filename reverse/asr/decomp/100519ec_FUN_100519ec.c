// FUNC 0x100519ec  FUN_100519ec

void FUN_100519ec(uint param_1,int param_2,int param_3)

{
  bool bVar1;
  int iVar2;
  byte bVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  byte *pbVar7;
  char *pcVar8;
  uint uVar9;
  byte bVar10;
  
  iVar2 = DAT_10051b00;
  iVar5 = 0;
  pcVar8 = (char *)(DAT_10051b00 + 0x1f);
  do {
    if (*pcVar8 != '\0') {
      bVar1 = false;
      for (uVar6 = 0; (uVar6 & 0xff) < (uint)(byte)pcVar8[1]; uVar6 = uVar6 + 1) {
        if ((byte)pcVar8[uVar6 + 2] == param_1) {
          bVar1 = true;
        }
      }
      if (bVar1) {
        uVar6 = 0;
        iVar5 = DAT_10051b00 + iVar5 * 0xe;
        break;
      }
    }
    iVar5 = iVar5 + 1;
    pcVar8 = pcVar8 + 0xe;
    if (iVar5 == 4) {
      return;
    }
  } while( true );
LAB_10051a42:
  if (*(byte *)(iVar5 + 0x20) <= uVar6) {
    return;
  }
  bVar10 = *(char *)(iVar5 + uVar6 + 0x21) - 1;
  if (bVar10 < 0xc) {
    uVar9 = (uint)(bVar10 >> 1);
    if ((bVar10 & 1) == 0) {
      pbVar7 = (byte *)(iVar2 + uVar9 + 0x57);
      if ((*pbVar7 >> 4) - 2 < 2) {
        if (param_2 == 2) {
          bVar10 = *(byte *)(param_3 + uVar9) & 0xf;
          *(byte *)(param_3 + uVar9) = bVar10;
          iVar4 = FUN_10051734(*pbVar7 >> 4);
        }
        else {
          if (param_2 != 3) goto LAB_10051aee;
          bVar10 = *(byte *)(param_3 + uVar9) & 0xf;
          *(byte *)(param_3 + uVar9) = bVar10;
          iVar4 = FUN_1005187c(*pbVar7 >> 4);
        }
        bVar3 = (byte)(iVar4 << 4);
        goto LAB_10051aea;
      }
    }
    else {
      pbVar7 = (byte *)(iVar2 + uVar9 + 0x57);
      if ((*pbVar7 & 0xf) - 2 < 2) {
        if (param_2 == 2) {
          bVar10 = *(byte *)(param_3 + uVar9) & 0xf0;
          *(byte *)(param_3 + uVar9) = bVar10;
          bVar3 = FUN_10051734(*pbVar7 & 0xf);
        }
        else {
          if (param_2 != 3) goto LAB_10051aee;
          bVar10 = *(byte *)(param_3 + uVar9) & 0xf0;
          *(byte *)(param_3 + uVar9) = bVar10;
          bVar3 = FUN_1005187c(*pbVar7 & 0xf);
        }
LAB_10051aea:
        *(byte *)(param_3 + uVar9) = bVar10 | bVar3;
      }
    }
  }
LAB_10051aee:
  uVar6 = uVar6 + 1 & 0xff;
  goto LAB_10051a42;
}


