// FUNC 0x1005415c  FUN_1005415c

undefined4 FUN_1005415c(int param_1)

{
  byte bVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar2 = 0;
  do {
    if (*(char *)(iVar2 * 2 + DAT_100541cc) == param_1) {
      bVar1 = *(byte *)(DAT_100541cc + iVar2 * 2 + 1);
      if (bVar1 < 0x10) {
        FUN_10056e58(0x31,0,4,2);
        FUN_10056e58(0x34,0x17,3);
        uVar3 = 7;
      }
      else {
        FUN_10056e58(0x31,0,4,3);
        FUN_10056e58(0x34,0x17,3,6);
        uVar3 = 0xd;
      }
      FUN_10056e58(0x33,1,4,uVar3);
      FUN_10053f18(1,0x18,5,bVar1);
      return 1;
    }
    iVar2 = iVar2 + 1;
  } while (iVar2 != 0x20);
  return 0;
}


