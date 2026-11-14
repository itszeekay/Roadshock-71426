// FUNC 0x10054b70  FUN_10054b70

undefined4 FUN_10054b70(uint param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  do {
    iVar1 = DAT_10054b94 + iVar2 * 0x14;
    if (*(ushort *)(iVar1 + 0x12) == param_1) {
      return *(undefined4 *)(iVar1 + 0xc);
    }
    iVar2 = iVar2 + 1;
  } while (iVar2 != 10);
  return 0;
}


