// FUNC 0x1004c7ac  FUN_1004c7ac

int FUN_1004c7ac(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = DAT_1004c7d8;
  iVar3 = 0;
  do {
    iVar2 = iVar3 * 0x14 + iVar1;
    iVar2 = FUN_100480b0(param_1,*(undefined4 *)(iVar2 + 4),param_3,iVar2,param_4);
    if (iVar2 == 0) {
      return (int)(char)iVar3;
    }
    iVar3 = iVar3 + 1;
  } while (iVar3 != 0x10);
  return -1;
}


