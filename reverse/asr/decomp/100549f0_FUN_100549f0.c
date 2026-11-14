// FUNC 0x100549f0  FUN_100549f0

undefined4 FUN_100549f0(byte param_1)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  
  puVar2 = DAT_10054a3c;
  if (param_1 != 0x26) {
    if (param_1 < 0x27) {
      puVar2 = DAT_10054a38;
      if ((param_1 != 0x14) && (puVar2 = DAT_10054a30, param_1 != 0x24)) {
        return 0;
      }
    }
    else {
      puVar2 = DAT_10054a44;
      if (((param_1 != 0x50) && (puVar2 = DAT_10054a40, param_1 != 200)) &&
         (puVar2 = DAT_10054a34, param_1 != 0x28)) {
        return 0;
      }
    }
  }
  uVar1 = (*(code *)*puVar2)();
  return uVar1;
}


