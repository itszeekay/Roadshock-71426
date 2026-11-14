// FUNC 0x10003874  FUN_10003874

uint FUN_10003874(int param_1,int param_2,uint *param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  undefined1 auStack_2c [4];
  int local_28;
  
  if (*(char *)(param_2 + 1) != '\x01') {
    uVar1 = *param_3;
    if (uVar1 == 0xffffffff) {
      return *(int *)(param_2 + 4) + 8;
    }
    uVar3 = *(int *)(param_2 + 4) + *(int *)(param_1 + 8);
    if (uVar1 <= uVar3) {
      uVar3 = uVar3 - 8;
      uVar1 = uVar1 + 0x94;
      do {
        uVar2 = uVar1;
        if ((uVar3 <= uVar2) || (uVar3 <= uVar2 + 0x94)) {
          uVar2 = 0xffffffff;
          break;
        }
        FUN_1000421e(param_1,uVar2,auStack_2c,0x14);
        uVar1 = uVar2 + 0x94;
      } while (local_28 != DAT_100038dc);
      if (uVar2 <= (uint)(*(int *)(param_2 + 4) + *(int *)(param_1 + 8))) {
        return uVar2;
      }
    }
  }
  return 0xffffffff;
}


