// FUNC 0x10004318  FUN_10004318

int FUN_10004318(int param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = param_2 - 2U;
  do {
    uVar2 = uVar1;
    if (uVar2 == 0xffffffff) break;
    uVar1 = uVar2 - 1;
  } while ((0x80 >> (uVar2 & 7) & (uint)*(byte *)(param_1 + (uVar2 >> 3))) != 0);
  return (uVar2 - (param_2 - 2U)) + param_2 + -1;
}


