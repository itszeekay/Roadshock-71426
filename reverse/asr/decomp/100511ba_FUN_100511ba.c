// FUNC 0x100511ba  FUN_100511ba

void FUN_100511ba(void)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  undefined *puVar4;
  undefined1 *puVar5;
  int iVar6;
  uint uVar7;
  uint *puVar8;
  char *pcVar9;
  int unaff_r7;
  int in_stack_00000014;
  
  iVar6 = DAT_100512c4;
  iVar2 = DAT_100512c0;
  if (*(char *)(DAT_100512c4 + 0x11) == '\x03') {
    pcVar9 = (char *)(DAT_100512c0 + 0x30);
    log_printf(DAT_100512c8,*(undefined1 *)(DAT_100512c0 + 0xc),*pcVar9);
    if (*DAT_100512cc == '\0') {
      if (*(char *)(iVar2 + 0xc) == '\0') goto LAB_10051224;
      iVar6 = *(int *)(iVar2 + 0x10);
      puVar5 = (undefined1 *)(iVar6 + 1);
      *(undefined1 **)(iVar2 + 0x10) = puVar5;
      while( true ) {
        uVar3 = DAT_100512d4;
        if (puVar5 == (undefined1 *)0x1) {
          iVar6 = 6;
          *DAT_100512d0 = 6;
          puVar5 = DAT_100512d8;
          *DAT_100512d8 = 6;
          FUN_100507a0(uVar3);
        }
        puVar4 = PTR_s_BL_change_10_times_100512dc;
        if (iVar6 - 1U < 3) {
          *DAT_100512d0 = 3;
          puVar5 = DAT_100512d8;
          *DAT_100512d8 = 3;
          FUN_100507a0(puVar4);
        }
        puVar4 = PTR_s_BL_change_30_times_100512e0;
        if (puVar5 < (undefined1 *)0x5) break;
        *DAT_100512d0 = 0;
        *DAT_100512d8 = 0;
        FUN_100507a0(puVar4);
LAB_10051224:
        if (*pcVar9 == '\0') break;
        iVar6 = *(int *)(iVar2 + 0x34);
        puVar5 = (undefined1 *)(iVar6 + 1);
        *(undefined1 **)(iVar2 + 0x34) = puVar5;
      }
    }
  }
  else if ((*(char *)(in_stack_00000014 + 1) == '\x0e') && (unaff_r7 == 1)) {
    pcVar9 = (char *)(DAT_100512c0 + 0xa8);
    if (*pcVar9 != '\0') {
      puVar8 = (uint *)(DAT_100512c0 + 0xac);
      uVar7 = *puVar8;
      *puVar8 = uVar7 + 1;
      if (9 < uVar7 + 1) {
        FUN_10051674();
        FUN_10050354(*(undefined1 *)(iVar6 + 8),*(undefined1 *)(iVar6 + 9),
                     *(undefined1 *)(iVar6 + 10),*(undefined1 *)(iVar6 + 0xb));
        led_frame_send(DAT_100512e4);
        FUN_10051564();
        cVar1 = *DAT_100512e8;
        *DAT_100512e8 = cVar1 + '\x01';
        FUN_1004fcf8(cVar1,0,0xd);
        *puVar8 = 0;
        *pcVar9 = '\0';
      }
    }
  }
  FUN_100505b4();
  return;
}


