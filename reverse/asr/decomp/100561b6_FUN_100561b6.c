// FUNC 0x100561b6  FUN_100561b6

undefined8
FUN_100561b6(int param_1,int param_2,uint param_3,undefined4 param_4,undefined4 param_5,
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
      FUN_10056068(param_1,uVar3,param_2,0,param_4,uVar2,uVar4);
      if ((param_3 == 0) || (*(byte *)(param_2 + 1) == param_3)) {
        if (uVar2 != 0) {
          FUN_10056068(param_1,uVar3,param_2,1,param_4,uVar2,uVar4);
        }
        if ((param_6 != (code *)0x0) && (iVar1 = (*param_6)(param_2,param_4,param_5), iVar1 != 0))
        goto LAB_1005621a;
      }
      if (*(int *)(param_2 + 4) == -1) break;
      uVar3 = *(int *)(param_2 + 4) + *(int *)(param_1 + 8);
      if ((*(uint *)(param_1 + 0xc) <= uVar3) || (uVar3 == 0xffffffff)) {
LAB_1005621a:
        return CONCAT44(uVar2,param_4);
      }
    }
  } while( true );
}


