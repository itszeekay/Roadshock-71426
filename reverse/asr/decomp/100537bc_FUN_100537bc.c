// FUNC 0x100537bc  FUN_100537bc

undefined8 FUN_100537bc(int param_1,int *param_2)

{
  undefined1 uVar1;
  ushort uVar2;
  int iStack_10;
  int *piStack_c;
  
  uVar1 = *DAT_100537e8;
  iStack_10 = param_1;
  piStack_c = param_2;
  if ((param_1 == 0) || (param_2 == (int *)0x0)) {
    FUN_10056de8(&iStack_10,DAT_100537ec,8);
    param_1 = 8;
    param_2 = &iStack_10;
  }
  uVar2 = FUN_10053738(0xaa,uVar1,param_1,param_2);
  return CONCAT44(iStack_10,(uint)uVar2);
}


