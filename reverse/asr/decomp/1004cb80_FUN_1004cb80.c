// FUNC 0x1004cb80  FUN_1004cb80

void FUN_1004cb80(void)

{
  int iVar1;
  uint uVar2;
  code *pcVar3;
  uint uVar4;
  
  uVar4 = 0;
  do {
    iVar1 = DAT_1004cbb0;
    uVar2 = 1 << (uVar4 & 0xff);
    if ((uVar2 & *(uint *)(DAT_1004cbac + 0x38)) != 0) {
      *(uint *)(DAT_1004cbac + 0x38) = uVar2;
      pcVar3 = *(code **)(uVar4 * 8 + iVar1);
      if (pcVar3 != (code *)0x0) {
        (*pcVar3)(*(undefined4 *)(iVar1 + uVar4 * 8 + 4));
      }
    }
    uVar4 = uVar4 + 1;
  } while (uVar4 != 0x10);
  return;
}


