// FUNC 0x1004cab8  FUN_1004cab8

undefined4 FUN_1004cab8(undefined4 param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  puVar1 = DAT_1004cad4;
  *DAT_1004cad4 = 0;
  puVar1[1] = 1;
  puVar1[7] = param_1;
  puVar1[2] = 1;
  puVar2 = DAT_1004cad4;
  do {
  } while (puVar1[0xc] == 0);
  DAT_1004cad4[0xb] = 1;
  return puVar2[9];
}


