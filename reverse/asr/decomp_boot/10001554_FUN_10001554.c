// FUNC 0x10001554  FUN_10001554

uint FUN_10001554(void)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  byte *pbVar4;
  char cVar5;
  
  uVar3 = 0xffffffff;
  pbVar4 = DAT_10001588;
  do {
    bVar1 = *pbVar4;
    pbVar4 = pbVar4 + 1;
    cVar5 = '\b';
    uVar2 = uVar3 ^ (uint)bVar1 << 0x18;
    do {
      uVar3 = uVar2 << 1;
      if ((int)uVar2 < 0) {
        uVar3 = uVar3 ^ DAT_1000158c;
      }
      cVar5 = cVar5 + -1;
      uVar2 = uVar3;
    } while (cVar5 != '\0');
  } while (pbVar4 != DAT_10001590);
  return ~uVar3;
}


