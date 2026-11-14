// FUNC 0x10050354  FUN_10050354

void FUN_10050354(uint param_1,uint param_2,uint param_3,undefined4 param_4,undefined1 param_5)

{
  byte bVar1;
  undefined1 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  uint uVar5;
  uint uVar6;
  
  uVar3 = FUN_10048f38(param_5);
  uVar3 = FUN_100486fc(uVar3,DAT_10050440);
  uVar5 = param_1;
  if (param_3 < param_1) {
    uVar5 = param_3 & 0xff;
  }
  bVar1 = (byte)uVar5;
  if (param_2 < (uVar5 & 0xff)) {
    bVar1 = (byte)param_2;
  }
  uVar5 = (uint)bVar1;
  bVar1 = FUN_10056e98(uVar5 << 1,3);
  uVar6 = (uint)bVar1;
  uVar4 = FUN_10048ea8((param_1 - uVar5 & 0xff) + uVar6 & 0xff);
  uVar4 = FUN_10048930(uVar4,DAT_10050444);
  uVar4 = FUN_100486fc(uVar4,DAT_10050440);
  FUN_10048930(uVar4,uVar3);
  uVar2 = FUN_10048224();
  FUN_1004e9f0(uVar2);
  uVar4 = FUN_10048ea8(uVar6 + (param_2 - uVar5 & 0xff) & 0xff);
  uVar4 = FUN_10048930(uVar4,DAT_10050444);
  uVar4 = FUN_100486fc(uVar4,DAT_10050440);
  FUN_10048930(uVar4,uVar3);
  uVar2 = FUN_10048224();
  FUN_1004ea70(uVar2);
  uVar4 = FUN_10048ea8(uVar6 + (param_3 - uVar5 & 0xff) & 0xff);
  uVar4 = FUN_10048930(uVar4,DAT_10050444);
  uVar4 = FUN_100486fc(uVar4,DAT_10050440);
  FUN_10048930(uVar4,uVar3);
  uVar2 = FUN_10048224();
  FUN_1004ea30(uVar2);
  uVar4 = FUN_10048ea8(param_4);
  uVar4 = FUN_10048930(uVar4,DAT_10050444);
  uVar4 = FUN_100486fc(uVar4,DAT_10050440);
  FUN_10048930(uVar4,uVar3);
  uVar2 = FUN_10048224();
  FUN_1004e968(uVar2);
  FUN_1004e9a8(param_5);
  return;
}


