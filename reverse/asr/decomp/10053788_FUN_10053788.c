// FUNC 0x10053788  FUN_10053788

undefined8 FUN_10053788(int param_1,int *param_2)

{
  undefined1 uVar1;
  ushort uVar2;
  int iStack_10;
  int *piStack_c;
  
  uVar1 = *DAT_100537b4;
  iStack_10 = param_1;
  piStack_c = param_2;
  if ((param_1 == 0) || (param_2 == (int *)0x0)) {
    FUN_10056de8(&iStack_10,DAT_100537b8,8);
    param_1 = 8;
    param_2 = &iStack_10;
  }
  uVar2 = FUN_10053738(0xa9,uVar1,param_1,param_2);
  return CONCAT44(iStack_10,(uint)uVar2);
}


