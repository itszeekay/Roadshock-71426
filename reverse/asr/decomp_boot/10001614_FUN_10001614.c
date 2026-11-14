// FUNC 0x10001614  FUN_10001614

void FUN_10001614(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = DAT_10001628;
  *(undefined4 *)(DAT_10001628 + 0x10) = param_1;
  *(undefined4 *)(iVar1 + 0x14) = param_2;
  *(undefined4 *)(iVar1 + 0x18) = param_3;
  uVar2 = FUN_10001554();
  *(undefined4 *)(iVar1 + 0x1c) = uVar2;
  return;
}


