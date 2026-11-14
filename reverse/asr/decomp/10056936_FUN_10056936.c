// FUNC 0x10056936  FUN_10056936

int FUN_10056936(int param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  
  uVar1 = param_2 - 2U;
  do {
    iVar2 = (param_2 - 2U) - uVar1;
    if (uVar1 == 0xffffffff) break;
    uVar3 = uVar1 & 7;
    uVar4 = uVar1 >> 3;
    uVar1 = uVar1 - 1;
  } while ((0x80 >> uVar3 & (uint)*(byte *)(param_1 + uVar4)) != 0);
  return (param_2 + -1) - iVar2;
}


