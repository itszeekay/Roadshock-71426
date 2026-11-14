// FUNC 0x100541d0  FUN_100541d0

void FUN_100541d0(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  (*(code *)*DAT_1005420c)();
  uVar1 = (*(code *)*DAT_10054210)(0x1c);
  uVar2 = uVar1 >> 0x10 & 0xff;
  uVar3 = uVar1 >> 8 & 0xff;
  if (((uVar2 != 0) || (uVar2 = uVar3, uVar3 != 0)) || (uVar2 = uVar1 & 0xff, (uVar1 & 0xff) != 0))
  {
    FUN_10056e58(0x35,0,8,uVar2);
  }
  return;
}


