// FUNC 0x1004dcec  FUN_1004dcec

void FUN_1004dcec(int param_1)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  
  iVar2 = *DAT_1004dd1c;
  uVar3 = 0;
  do {
    uVar1 = uVar3 >> 1;
    uVar4 = uVar3 & 1;
    iVar5 = uVar3 * 4;
    uVar3 = uVar3 + 1 & 0xff;
    *(uint *)(iVar5 + param_1) = *(uint *)(uVar1 * 8 + DAT_1004dd20) >> (uVar4 << 4) & 0xffff;
  } while (uVar3 <= (uint)(iVar2 << 6) >> 0x1d);
  return;
}


