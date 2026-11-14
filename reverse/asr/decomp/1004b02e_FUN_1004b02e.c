// FUNC 0x1004b02e  FUN_1004b02e

void FUN_1004b02e(code *param_1,undefined4 param_2,int param_3,undefined4 param_4,int param_5,
                 int param_6,uint param_7,uint param_8)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar2 = param_3;
  iVar3 = param_6;
  iVar4 = param_3;
  if ((param_8 & 3) == 0) {
    for (; (uint)(iVar2 + (param_6 - param_3)) < param_7; iVar2 = iVar2 + 1) {
      (*param_1)(0x20,param_2,iVar2,param_4,param_2,param_4,iVar4);
    }
  }
  while( true ) {
    iVar1 = param_6 + iVar2;
    if (iVar3 == 0) break;
    (*param_1)(*(undefined1 *)(param_5 + iVar3 + -1),param_2,iVar1 - iVar3,param_4,param_2,param_4,
               iVar4);
    iVar3 = iVar3 + -1;
  }
  if ((int)(param_8 << 0x1e) < 0) {
    for (; (uint)(iVar1 - param_3) < param_7; iVar1 = iVar1 + 1) {
      (*param_1)(0x20,param_2,iVar1,param_4,param_2,param_4,iVar4);
    }
  }
  return;
}


