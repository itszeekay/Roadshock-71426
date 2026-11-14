// FUNC 0x1000205c  FUN_1000205c

void FUN_1000205c(void)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  
  iVar2 = DAT_10002090;
  uVar1 = DAT_1000208c;
  uVar4 = 0;
  do {
    iVar3 = 8;
    uVar5 = uVar4;
    do {
      iVar3 = iVar3 + -1;
      uVar5 = -(uVar5 & 1) & uVar1 ^ uVar5 >> 1;
    } while (iVar3 != 0);
    iVar3 = uVar4 * 4;
    uVar4 = uVar4 + 1;
    *(uint *)(iVar2 + iVar3) = uVar5;
  } while (uVar4 != 0x100);
  return;
}


