// FUNC 0x1004fec0  FUN_1004fec0

void FUN_1004fec0(undefined1 *param_1,undefined1 *param_2,undefined1 *param_3,undefined4 param_4,
                 ushort param_5,undefined2 param_6)

{
  byte bVar1;
  undefined1 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  uint extraout_r1;
  
  uVar3 = FUN_10048ea8(param_6);
  uVar3 = FUN_10048930(uVar3,DAT_1004ffd4);
  uVar4 = FUN_10048ea8(100 - (uint)param_5);
  uVar4 = FUN_10048930(uVar4,uVar3);
  uVar5 = FUN_100486fc(uVar4,DAT_1004ffd8);
  FUN_10056d68(param_4,0x3c);
  uVar4 = FUN_10048ea8(extraout_r1 & 0xffff);
  uVar6 = FUN_10048b58(uVar3,uVar5);
  uVar4 = FUN_10048930(uVar4,uVar6);
  uVar4 = FUN_100486fc(uVar4,DAT_1004ffdc);
  bVar1 = FUN_10056d58(param_4,0x3c);
  if (bVar1 < 5) {
    FUN_10056ee8();
    uVar2 = FUN_10048224(uVar3,uVar4);
    *param_1 = uVar2;
    FUN_10048410(uVar5,uVar4);
    uVar2 = FUN_10048224();
    *param_2 = uVar2;
  }
  else {
    uVar2 = FUN_10048224(uVar3);
    *param_1 = uVar2;
    uVar2 = FUN_10048224(uVar5);
    *param_2 = uVar2;
    uVar5 = FUN_10048b58(uVar3,uVar4);
  }
  uVar2 = FUN_10048224(uVar5);
  *param_3 = uVar2;
  return;
}


