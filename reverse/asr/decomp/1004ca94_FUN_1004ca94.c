// FUNC 0x1004ca94  FUN_1004ca94

uint FUN_1004ca94(undefined4 param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  puVar1 = DAT_1004cab4;
  *DAT_1004cab4 = 0;
  puVar1[1] = 0;
  puVar1[7] = param_1;
  puVar1[2] = 1;
  puVar2 = DAT_1004cab4;
  do {
  } while (puVar1[0xc] == 0);
  DAT_1004cab4[0xb] = 1;
  return puVar2[9] & 0xff;
}


