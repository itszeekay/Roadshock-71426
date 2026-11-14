// FUNC 0x10001b54  FUN_10001b54

uint FUN_10001b54(byte *param_1,int param_2)

{
  byte *pbVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  
  uVar4 = 0;
  pbVar1 = param_1 + param_2;
  for (; pbVar1 != param_1; param_1 = param_1 + 1) {
    iVar2 = 8;
    uVar4 = uVar4 ^ (uint)*param_1 << 8;
    do {
      uVar3 = uVar4 << 1;
      if ((short)uVar4 < 0) {
        uVar3 = uVar3 ^ DAT_10001b8c;
      }
      uVar4 = uVar3 & 0xffff;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
  }
  FUN_100014a0(DAT_10001b90,uVar4);
  return uVar4;
}


