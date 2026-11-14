// FUNC 0x1004ca50  FUN_1004ca50

void FUN_1004ca50(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  uVar2 = DAT_1004ca88;
  iVar1 = DAT_1004ca84;
  *(undefined4 *)(DAT_1004ca84 + 0xc) = 5;
  iVar3 = *DAT_1004ca8c;
  uVar2 = FUN_10056d58(iVar3,uVar2);
  *(undefined4 *)(iVar1 + 0x10) = uVar2;
  *(undefined4 *)(iVar1 + 0x14) = 0;
  uVar2 = FUN_10056d58(iVar3 * 6,DAT_1004ca90);
  *(undefined4 *)(iVar1 + 0x18) = uVar2;
  if (param_1 != 0) {
    FUN_1004ca2c();
  }
  return;
}


