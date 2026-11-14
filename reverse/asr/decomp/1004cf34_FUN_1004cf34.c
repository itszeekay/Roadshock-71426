// FUNC 0x1004cf34  FUN_1004cf34

void FUN_1004cf34(void)

{
  uint uVar1;
  code *pcVar2;
  uint uVar3;
  
  uVar3 = 0;
  do {
    uVar1 = 1 << (uVar3 & 0xff);
    if ((uVar1 & *(uint *)(DAT_1004cf60 + 0x7c)) != 0) {
      *(uint *)(DAT_1004cf64 + 0x7c) = uVar1;
      pcVar2 = *(code **)(uVar3 * 4 + DAT_1004cf68);
      if (pcVar2 != (code *)0x0) {
        (*pcVar2)();
      }
    }
    uVar3 = uVar3 + 1;
  } while (uVar3 != 6);
  return;
}


