// FUNC 0x10051588  FUN_10051588

undefined8 FUN_10051588(int param_1,int param_2)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  uint uVar5;
  undefined *puVar6;
  byte *pbVar7;
  byte *pbVar8;
  uint uVar9;
  bool bVar10;
  int local_18;
  
  puVar6 = PTR_s_ERROR_10051650;
  if (((*(char *)(param_1 + param_2 + -2) == '\r') && (*(char *)(param_1 + param_2 + -1) == '\n'))
     && (iVar2 = FUN_10056e88(param_1,DAT_1005163c,5), puVar6 = PTR_s_ERROR_10051650, iVar2 == 0)) {
    if (*(char *)(param_1 + 5) == '?') {
      FUN_1005152c();
      uVar9 = *(uint *)(DAT_10051640 + 4);
      uVar3 = FUN_10051578(uVar9 >> 0x10 & 0xff);
      uVar4 = FUN_10051578(uVar9 >> 8 & 0xff);
      local_18 = FUN_10051578(uVar9 & 0xff);
      log_printf(PTR_s__s_02d_02d_02d_10051648,PTR_DAT_10051644,uVar3,uVar4);
      goto LAB_1005163a;
    }
    if ((*(char *)(param_1 + 5) == '=') && (param_2 == 0xe)) {
      pbVar7 = (byte *)(param_1 + 6);
      cVar1 = '\0';
      pbVar8 = pbVar7;
      do {
        if (9 < *pbVar8 - 0x30) goto LAB_10051636;
        cVar1 = cVar1 + '\x01';
        pbVar8 = pbVar8 + 1;
      } while (cVar1 != '\x06');
      uVar5 = 0;
      uVar9 = 0x10;
      do {
        uVar5 = uVar5 | (((*pbVar7 - 0x30 & 0xff) << 4 | pbVar7[1] - 0x30) & 0xff) << (uVar9 & 0xff)
        ;
        pbVar7 = pbVar7 + 2;
        bVar10 = uVar9 != 0;
        uVar9 = uVar9 - 8;
      } while (bVar10);
      *(uint *)(DAT_10051640 + 4) = uVar5;
      FUN_100539ae(0x97,8);
      puVar6 = PTR_DAT_1005164c;
    }
  }
LAB_10051636:
  log_printf(puVar6);
  local_18 = param_1;
LAB_1005163a:
  return CONCAT44(param_2,local_18);
}


