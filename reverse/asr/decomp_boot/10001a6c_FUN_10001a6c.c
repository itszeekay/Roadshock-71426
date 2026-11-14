// FUNC 0x10001a6c  FUN_10001a6c

undefined4 FUN_10001a6c(int param_1,int *param_2,int param_3,int param_4)

{
  int iVar1;
  
  if ((param_2 != (int *)0x0) && (param_3 != 0)) {
    iVar1 = DAT_10001ab8 + param_1 * 0x14;
    if (((uint)(*param_2 + param_4) <= *(uint *)(iVar1 + 0xc)) &&
       (0x7ffffff < param_3 + 0xf0000000U)) {
      iVar1 = *(int *)(iVar1 + 8);
      FUN_100049ac(param_3,*param_2 + iVar1,param_4,iVar1,param_4);
      *param_2 = *param_2 + param_4;
      return 0;
    }
  }
  return 0xffffffff;
}


