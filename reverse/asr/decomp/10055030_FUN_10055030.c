// FUNC 0x10055030  FUN_10055030

void FUN_10055030(undefined4 *param_1)

{
  int iVar1;
  
  iVar1 = FUN_10054b70(0x14);
  *param_1 = DAT_1005504c;
  *(undefined2 *)((int)param_1 + 10) = 3;
  param_1[1] = iVar1 + 0x1e;
  *(undefined2 *)(param_1 + 2) = 1;
  return;
}


