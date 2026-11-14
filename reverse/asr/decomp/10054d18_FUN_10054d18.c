// FUNC 0x10054d18  FUN_10054d18

uint FUN_10054d18(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = 1;
  uVar2 = 0;
  do {
    if ((param_1 >> (uVar2 & 0xff) & 1U) != 0) {
      uVar1 = uVar1 | 3 << (uVar2 * 2 + 1 & 0xff);
    }
    uVar2 = uVar2 + 1;
  } while (uVar2 != 9);
  return uVar1;
}


