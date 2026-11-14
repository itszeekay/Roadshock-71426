// FUNC 0x1004c4ac  FUN_1004c4ac

void FUN_1004c4ac(void)

{
  code *pcVar1;
  uint uVar2;
  uint uVar3;
  
  uVar2 = 0;
  uVar3 = *DAT_1004c4e0;
  do {
    if ((uVar3 & 1 << (uVar2 & 0xff)) != 0) {
      FUN_1004c120(uVar2);
      pcVar1 = *(code **)(uVar2 * 8 + DAT_1004c4e4);
      if (pcVar1 != (code *)0x0) {
        (*pcVar1)(*(undefined4 *)(DAT_1004c4e4 + uVar2 * 8 + 4));
        return;
      }
    }
    uVar2 = uVar2 + 1;
  } while (uVar2 != 0x20);
  return;
}


