// FUNC 0x100507a0  FUN_100507a0

void FUN_100507a0(undefined4 param_1)

{
  char cVar1;
  char cVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  byte bVar6;
  int unaff_r4;
  
  do {
    FUN_1004bf28(param_1);
    uVar4 = FUN_10051294();
    cVar1 = *(char *)(unaff_r4 + 0x24);
    if (cVar1 != '\0') {
      uVar4 = FUN_10051294();
    }
    iVar3 = DAT_10050850;
    if (*(char *)(DAT_10050850 + 0x11) == '\x02') {
      iVar5 = FUN_100501fc();
      cVar2 = *(char *)(iVar3 + 0x15);
      if (iVar5 == 0) {
        bVar6 = cVar2 + 1;
        if (bVar6 < 4) {
LAB_100507e8:
          *(byte *)(iVar3 + 0x15) = bVar6;
        }
        else {
          *(undefined1 *)(iVar3 + 0x15) = 0;
        }
LAB_100507ea:
        FUN_10050160(2,*(undefined1 *)(iVar3 + 0x15));
      }
      else if (cVar2 != '\x01') {
        bVar6 = cVar2 + 1;
        if (bVar6 < 4) {
          if (bVar6 == 1) {
            bVar6 = 2;
          }
          goto LAB_100507e8;
        }
        *(char *)(iVar3 + 0x15) = cVar1;
        goto LAB_100507ea;
      }
      FUN_10053930(0x2a);
      FUN_10053918(0x2a,DAT_10050878);
    }
    else if (*(char *)(DAT_10050850 + 0x11) == '\0') {
      FUN_1004ffe0(uVar4,1);
    }
    *(undefined1 *)(unaff_r4 + 0x24) = 1;
    param_1 = DAT_100508b4;
    unaff_r4 = unaff_r4 + 5;
  } while( true );
}


