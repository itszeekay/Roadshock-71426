// FUNC 0x1004da80  FUN_1004da80

uint FUN_1004da80(void)

{
  int iVar1;
  ushort uVar2;
  int iVar3;
  uint uVar4;
  undefined8 uVar5;
  
  iVar3 = FUN_1004cb54(3,0x1c,1);
  iVar1 = DAT_1004dac0;
  if ((iVar3 == 1) && (iVar3 = FUN_1004cb54(0x23,0x15,4), iVar3 == 0xf)) {
    uVar5 = FUN_1004aa5c(*(uint *)(iVar1 + 0x20) & 0xffff);
    FUN_10049e54((int)uVar5,(int)((ulonglong)uVar5 >> 0x20),DAT_1004dac4,DAT_1004dac8);
    FUN_1004abf8();
    uVar2 = FUN_10048224();
    uVar4 = (uint)uVar2;
  }
  else {
    uVar4 = *(uint *)(iVar1 + 0x20);
  }
  return uVar4;
}


