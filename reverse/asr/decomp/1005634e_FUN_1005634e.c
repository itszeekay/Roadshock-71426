// FUNC 0x1005634e  FUN_1005634e

void FUN_1005634e(int param_1,int param_2,undefined4 param_3,undefined4 param_4,code *param_5)

{
  int iVar1;
  uint uVar2;
  undefined1 uStack_2c;
  byte local_2b;
  int local_28;
  
  do {
    uVar2 = 0;
    while( true ) {
      iVar1 = FUN_10056068(param_1,uVar2,&uStack_2c,0);
      if (((iVar1 == 0) && (param_5 != (code *)0x0)) && (local_2b - 2 < 2)) {
        *(int *)(param_2 + 0x10) = local_28 + 8;
        do {
          FUN_10055eb6(param_1,param_2);
          iVar1 = (*param_5)(param_2,param_3,param_4);
          if (iVar1 != 0) {
            return;
          }
          if (local_2b == 1) {
            iVar1 = -1;
          }
          else {
            iVar1 = FUN_10056000(param_1,&uStack_2c,param_2 + 0x10);
          }
          *(int *)(param_2 + 0x10) = iVar1;
        } while (iVar1 != -1);
      }
      if (local_28 == -1) break;
      uVar2 = local_28 + *(int *)(param_1 + 8);
      if ((*(uint *)(param_1 + 0xc) <= uVar2) || (uVar2 == 0xffffffff)) {
        return;
      }
    }
  } while( true );
}


