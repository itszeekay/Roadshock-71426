// FUNC 0x1005023c  FUN_1005023c

undefined4 FUN_1005023c(void)

{
  ushort uVar1;
  uint uVar2;
  undefined4 uVar3;
  char cVar4;
  int iVar5;
  undefined8 uVar6;
  undefined4 local_34;
  undefined4 local_30;
  undefined1 local_2c;
  undefined2 local_2a;
  undefined4 local_28;
  undefined1 local_24;
  
  *(undefined4 *)(DAT_100502c4 + 0x7c) = 0x400000;
  local_28 = 0;
  local_30 = 0;
  local_34 = 0;
  local_2c = 0;
  local_24 = 6;
  local_2a = 10;
  FUN_1004dae4(&local_34);
  FUN_1004da58(1);
  cVar4 = (char)local_2a;
  iVar5 = DAT_100502c8;
  do {
    uVar2 = FUN_1004da74();
    if ((uVar2 & 4) != 0) {
      iVar5 = 0;
      while (cVar4 != '\0') {
        uVar2 = FUN_1004da74();
        if ((uVar2 & 0x10) == 0) {
          uVar1 = FUN_1004da80();
          cVar4 = cVar4 + -1;
          iVar5 = iVar5 + (uint)uVar1;
        }
      }
      FUN_1004da58(0);
      FUN_10056d58(iVar5,local_2a);
      uVar6 = FUN_1004aae0();
      FUN_10049e54((int)uVar6,(int)((ulonglong)uVar6 >> 0x20),DAT_100502cc,DAT_100502d0);
      uVar3 = FUN_1004a9f0();
      return uVar3;
    }
    iVar5 = iVar5 + -1;
  } while (iVar5 != 0);
  return 0xffffffff;
}


