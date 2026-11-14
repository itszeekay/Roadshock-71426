// FUNC 0x1005655e  FUN_1005655e

bool FUN_1005655e(char *param_1,undefined4 param_2)

{
  int iVar1;
  bool bVar2;
  undefined1 auStack_14 [8];
  
  if ((param_1[1] == '\0') || (*param_1 != '\x03')) {
    bVar2 = false;
    if (*param_1 == '\x01') {
      FUN_10056960(param_2,*(undefined4 *)(param_1 + 0x10),auStack_14,6,5,1);
      bVar2 = true;
    }
  }
  else {
    iVar1 = FUN_10056486(param_2,param_1);
    bVar2 = iVar1 != 0;
  }
  return bVar2;
}


