// FUNC 0x10001954  FUN_10001954

int FUN_10001954(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = 0;
  iVar3 = DAT_1000197c;
  do {
    iVar1 = FUN_10000740(param_1,*(undefined4 *)(iVar3 + 4));
    if (iVar1 == 0) {
      return (int)(char)iVar2;
    }
    iVar2 = iVar2 + 1;
    iVar3 = iVar3 + 0x14;
  } while (iVar2 != 0x10);
  return -1;
}


