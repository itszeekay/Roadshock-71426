// FUNC 0x10056000  FUN_10056000

uint FUN_10056000(int param_1,int param_2,uint *param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  undefined1 auStack_2c [4];
  int local_28;
  
  uVar3 = *param_3;
  if (uVar3 == 0xffffffff) {
    uVar3 = *(int *)(param_2 + 4) + 8;
  }
  else {
    uVar1 = *(int *)(param_2 + 4) + *(int *)(param_1 + 8);
    if (uVar3 <= uVar1) {
      uVar1 = uVar1 - 8;
      uVar3 = uVar3 + 0x94;
      do {
        uVar2 = uVar3;
        if ((uVar1 <= uVar2) || (uVar1 <= uVar2 + 0x94)) {
          uVar2 = 0xffffffff;
          break;
        }
        FUN_10056a4a(param_1,uVar2,auStack_2c,0x14);
        uVar3 = uVar2 + 0x94;
      } while (local_28 != DAT_10056064);
      if (uVar2 <= (uint)(*(int *)(param_2 + 4) + *(int *)(param_1 + 8))) {
        return uVar2;
      }
    }
    uVar3 = 0xffffffff;
  }
  return uVar3;
}


