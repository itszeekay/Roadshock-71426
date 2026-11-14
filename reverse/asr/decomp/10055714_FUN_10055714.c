// FUNC 0x10055714  FUN_10055714

void FUN_10055714(void)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  uint uVar4;
  byte *pbVar5;
  byte local_70 [64];
  undefined1 local_30 [40];
  
  disableIRQinterrupts();
  iVar1 = FUN_1004cb10(1);
  uVar3 = DAT_100557c0;
  if (iVar1 << 1 < 0) {
    uVar3 = DAT_100557bc;
  }
  FUN_1004cb00(1,uVar3);
  uVar2 = FUN_1004cb10(1);
  FUN_1004cb00(1,uVar2 & DAT_100557c4);
  uVar2 = FUN_1004cb10(7);
  FUN_1004cb00(7,uVar2 | 0x800000);
  uVar2 = 0;
  do {
    uVar4 = uVar2;
    if ((uVar4 & 1) == 0) {
      local_30[uVar4] = 0;
    }
    else {
      local_30[uVar4] = 0x10;
    }
    uVar2 = uVar4 + 1;
  } while (uVar4 + 1 != 0x25);
  iVar1 = 0;
  pbVar5 = local_70 + uVar4;
  do {
    if (iVar1 < 0x10) {
      pbVar5[0x1c] = pbVar5[0x1c] | 5;
      pbVar5[0x1d] = pbVar5[0x1d] | 5;
    }
    else {
      *pbVar5 = *pbVar5 | 10;
      pbVar5[1] = pbVar5[1] | 10;
    }
    iVar1 = iVar1 + 1;
    pbVar5 = pbVar5 + 2;
  } while (iVar1 != 0x20);
  iVar1 = 0;
  do {
    FUN_1004cb00(0x14,local_30[iVar1]);
    iVar1 = iVar1 + 1;
    FUN_1004afb0(10);
  } while (iVar1 != 0x25);
  return;
}


