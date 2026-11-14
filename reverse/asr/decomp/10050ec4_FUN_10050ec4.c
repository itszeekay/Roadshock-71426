// FUNC 0x10050ec4  FUN_10050ec4

void FUN_10050ec4(void)

{
  char cVar1;
  int iVar2;
  undefined1 *puVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  undefined *puVar10;
  uint uVar11;
  char *pcVar12;
  int unaff_r4;
  byte *pbVar13;
  int unaff_r7;
  int in_stack_00000010;
  uint uStack00000018;
  
  iVar2 = DAT_10050f68;
  uStack00000018 = (uint)*(byte *)(DAT_10050f68 + 0x11);
  if (uStack00000018 == 3) {
    if ((*(char *)(unaff_r4 + 0xc) != '\0') || (*(char *)(unaff_r4 + 0x30) != '\0')) {
      *DAT_10050fb0 = 0;
      FUN_10053930(0x2f);
      FUN_10053930(0x2e);
      FUN_10053918(0x2e,DAT_10050fb4);
      uVar4 = FUN_10053944(0x2f);
      log_printf(DAT_10050fb8,uVar4);
    }
    if (*(char *)(in_stack_00000010 + 1) == '\x01') {
      *(undefined1 *)(unaff_r4 + 0xc) = 0;
      *(undefined4 *)(unaff_r4 + 0x10) = 0;
    }
    if (*(char *)(in_stack_00000010 + 1) == '\x04') {
      *(undefined1 *)(unaff_r4 + 0x30) = 0;
      *(undefined4 *)(unaff_r4 + 0x34) = 0;
    }
    puVar10 = DAT_10050fbc;
    if (*(char *)(in_stack_00000010 + 1) == '\r') {
      *(undefined1 *)(unaff_r4 + 0x9c) = 0;
      *(undefined4 *)(unaff_r4 + 0xa0) = 0;
      puVar10 = DAT_10050fbc;
    }
  }
  else {
    if (*DAT_10050f80 != '\0') {
      *DAT_10050f80 = '\0';
      FUN_1004eb00();
      goto LAB_100511a0;
    }
    if (*DAT_10050fa0 != '\0') {
      FUN_1004eae0();
      *DAT_10050fa0 = '\0';
      goto LAB_100511a0;
    }
    uVar11 = (uint)*(byte *)(DAT_100512a4 + (uint)*(byte *)(in_stack_00000010 + 1));
    if ((uVar11 == 0xd) && (unaff_r7 == 1)) {
      FUN_10053930(0x32);
      FUN_10053918(0x32,0x15e);
      pcVar12 = (char *)(unaff_r4 + 0xa4);
      cVar1 = *pcVar12;
      *pcVar12 = cVar1 + '\x01';
      if ((char)(cVar1 + '\x01') == '\x02') {
        *pcVar12 = '\0';
        puVar3 = DAT_100512a8;
        *(undefined4 *)(unaff_r4 + 0xa0) = 0;
        *puVar3 = 1;
        FUN_10053918(0x2b,200);
        uVar4 = DAT_100512ac;
        *(undefined1 *)(iVar2 + 0x11) = 2;
        FUN_10053918(0x2a,uVar4);
        FUN_10053930(0x32);
        if (*(char *)(iVar2 + 0x12) == '\0') {
          FUN_10050354(*(undefined1 *)(iVar2 + 8),*(undefined1 *)(iVar2 + 9),
                       *(undefined1 *)(iVar2 + 10),*(undefined1 *)(iVar2 + 0xb));
          *(undefined1 *)(iVar2 + 0x12) = 1;
          FUN_1004eae0();
          FUN_10051564();
        }
        else {
          FUN_10053930(0x33);
        }
        log_printf(DAT_100512b0,2);
      }
      goto LAB_100511a0;
    }
    if (1 < uVar11 - 0xd) {
      if (uStack00000018 == 0) {
        FUN_1004ffe0((uint)*(byte *)(in_stack_00000010 + 1),3);
      }
      goto LAB_100511a0;
    }
    if ((((uStack00000018 != 0) || (uVar11 != 0xe)) || (unaff_r7 != 1)) || (*DAT_100512b4 != '\0'))
    goto LAB_100511a0;
    FUN_1004eac0();
    if (*(char *)(iVar2 + 0x5d) == '\0') {
      pbVar13 = (byte *)(iVar2 + 0x57);
      FUN_10056de8(iVar2 + 0x5e,pbVar13,6);
      iVar5 = FUN_10051734(*pbVar13 >> 4);
      uVar11 = FUN_10051734(*pbVar13 & 0xf);
      iVar6 = FUN_10051734(*(byte *)(iVar2 + 0x58) >> 4);
      uVar7 = FUN_10051734(*(byte *)(iVar2 + 0x58) & 0xf);
      iVar8 = FUN_10051734(*(byte *)(iVar2 + 0x59) >> 4);
      uVar9 = FUN_10051734(*(byte *)(iVar2 + 0x59) & 0xf);
      FUN_10051734(*(byte *)(iVar2 + 0x5a) >> 4);
      FUN_10051734(*(byte *)(iVar2 + 0x5a) & 0xf);
      FUN_10051734(*(byte *)(iVar2 + 0x5b) >> 4);
      FUN_10051734(*(byte *)(iVar2 + 0x5b) & 0xf);
      FUN_10051734(*(byte *)(iVar2 + 0x5c) >> 4);
      FUN_10051734(*(byte *)(iVar2 + 0x5c) & 0xf);
      FUN_1004fdb8(uStack00000018,(iVar5 << 4 | uVar11) & 0xff,(iVar6 << 4 | uVar7) & 0xff,
                   (iVar8 << 4 | uVar9) & 0xff);
      puVar10 = PTR_s_temp_all_off_100512b8;
    }
    else {
      FUN_1004fdb8(*(char *)(iVar2 + 0x5d),*(undefined1 *)(iVar2 + 0x5e),
                   *(undefined1 *)(iVar2 + 0x5f),*(undefined1 *)(iVar2 + 0x60));
      puVar10 = PTR_s_temp_all_restore_100512bc;
    }
  }
  log_printf(puVar10);
LAB_100511a0:
  iVar2 = DAT_100512c0;
  *(undefined1 *)((uint)*(byte *)(in_stack_00000010 + 1) * 0xc + DAT_100512c0) = 0;
  *(undefined4 *)(iVar2 + (uint)*(byte *)(in_stack_00000010 + 1) * 0xc + 4) = 0;
  FUN_10051294();
  return;
}


