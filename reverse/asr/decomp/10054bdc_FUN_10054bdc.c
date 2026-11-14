// FUNC 0x10054bdc  FUN_10054bdc

uint FUN_10054bdc(uint param_1)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  
  iVar1 = 0;
  do {
    iVar3 = DAT_10054c08 + iVar1 * 0x14;
    if ((uint)*(ushort *)(iVar3 + 0x12) == (param_1 & 0xff)) {
      uVar2 = (uint)*(ushort *)(iVar3 + 0x10);
      goto LAB_10054c00;
    }
    iVar1 = iVar1 + 1;
  } while (iVar1 != 10);
  uVar2 = 0xff;
LAB_10054c00:
  return param_1 & 0xffffff00 | uVar2;
}


