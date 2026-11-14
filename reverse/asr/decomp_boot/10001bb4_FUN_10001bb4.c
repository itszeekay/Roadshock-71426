// FUNC 0x10001bb4  FUN_10001bb4

void FUN_10001bb4(uint param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  bool bVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  
  uVar3 = param_1 & 0xfffff000;
  uVar5 = (param_1 + param_2) - uVar3;
  while( true ) {
    if (uVar5 == 0) {
      return;
    }
    if (((uVar3 & 0xffff) == 0) && (0xf000 < (int)uVar5)) {
      uVar4 = 0x10000;
      uVar2 = DAT_10001c24;
    }
    else if (((uVar3 & 0x7fff) == 0) && (0x7000 < (int)uVar5)) {
      uVar4 = 0x8000;
      uVar2 = DAT_10001c28;
    }
    else {
      uVar4 = 0x1000;
      uVar2 = DAT_10001c20;
    }
    iVar6 = 0;
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      iVar6 = isIRQinterruptsEnabled();
    }
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      enableIRQinterrupts(1);
    }
    FUN_10004e80(uVar2,uVar3,param_3,1,param_4);
    if (iVar6 == 0) {
      bVar1 = (bool)isCurrentModePrivileged();
      if (bVar1) {
        enableIRQinterrupts(0);
      }
    }
    else {
      bVar1 = (bool)isCurrentModePrivileged();
      if (bVar1) {
        enableIRQinterrupts(1);
      }
    }
    uVar3 = uVar3 + uVar4;
    if (uVar5 <= uVar4) break;
    uVar5 = uVar5 - uVar4;
  }
  return;
}


