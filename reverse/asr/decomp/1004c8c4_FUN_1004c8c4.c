// FUNC 0x1004c8c4  FUN_1004c8c4

undefined4 FUN_1004c8c4(int param_1,int *param_2,int param_3,int param_4)

{
  int iVar1;
  
  if ((param_2 != (int *)0x0) && (param_3 != 0)) {
    iVar1 = DAT_1004c910 + param_1 * 0x14;
    if (((uint)(*param_2 + param_4) <= *(uint *)(iVar1 + 0xc)) &&
       (DAT_1004c914 < param_3 + 0xf0000000U)) {
      FUN_10056de8(param_3,*param_2 + *(int *)(iVar1 + 8),param_4);
      *param_2 = *param_2 + param_4;
      return 0;
    }
  }
  return 0xffffffff;
}


