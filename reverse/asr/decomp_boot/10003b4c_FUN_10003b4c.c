// FUNC 0x10003b4c  FUN_10003b4c

undefined8
FUN_10003b4c(int param_1,int param_2,uint param_3,undefined4 param_4,undefined4 param_5,
            code *param_6,byte param_7)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar2 = (uint)param_7;
  uVar4 = param_3;
  do {
    uVar3 = 0;
    while( true ) {
      FUN_100038e0(param_1,uVar3,param_2,0,param_4,uVar2,uVar4);
      if ((param_3 == 0) || (*(byte *)(param_2 + 1) == param_3)) {
        if (uVar2 != 0) {
          FUN_100038e0(param_1,uVar3,param_2,1,param_4,uVar2,uVar4);
        }
        iVar1 = (*param_6)(param_2,param_4,param_5);
        if (iVar1 != 0) goto LAB_10003ba8;
      }
      if (*(int *)(param_2 + 4) == -1) break;
      uVar3 = *(int *)(param_2 + 4) + *(int *)(param_1 + 8);
      if ((*(uint *)(param_1 + 0xc) <= uVar3) || (uVar3 == 0xffffffff)) {
LAB_10003ba8:
        return CONCAT44(uVar2,param_4);
      }
    }
  } while( true );
}


