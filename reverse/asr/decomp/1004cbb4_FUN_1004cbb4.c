// FUNC 0x1004cbb4  FUN_1004cbb4

void FUN_1004cbb4(void)

{
  uint uVar1;
  undefined4 *puVar2;
  uint uVar3;
  
  uVar3 = 0;
  puVar2 = (undefined4 *)(DAT_1004cbe0 + 0x80);
  do {
    uVar1 = 1 << (uVar3 & 0xff);
    if ((uVar1 & *(uint *)(DAT_1004cbe4 + 0x38)) != 0) {
      *(uint *)(DAT_1004cbe4 + 0x38) = uVar1;
      if ((code *)*puVar2 != (code *)0x0) {
        (*(code *)*puVar2)(puVar2[1]);
      }
    }
    uVar3 = uVar3 + 1;
    puVar2 = puVar2 + 2;
  } while (uVar3 != 0x10);
  return;
}


