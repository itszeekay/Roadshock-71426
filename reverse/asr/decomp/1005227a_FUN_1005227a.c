// FUNC 0x1005227a  FUN_1005227a

longlong FUN_1005227a(uint param_1,undefined2 *param_2,undefined4 param_3,uint param_4)

{
  int iVar1;
  
  iVar1 = FUN_10051f48(param_4 >> 8,param_1,param_2,param_4,param_1,param_2,param_3);
  if (iVar1 == 1) {
    param_1 = 0;
    FUN_1005221c(param_4 >> 8,*param_2,1);
  }
  return (ulonglong)param_1 << 0x20;
}


