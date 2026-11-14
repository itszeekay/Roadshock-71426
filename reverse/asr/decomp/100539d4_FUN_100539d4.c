// FUNC 0x100539d4  FUN_100539d4

undefined4 FUN_100539d4(void)

{
  int iVar1;
  code *pcVar2;
  char local_20 [20];
  
  if ((((undefined4 *)*DAT_10053a78 != (undefined4 *)0x0) &&
      (pcVar2 = *(code **)*DAT_10053a78, pcVar2 != (code *)0x0)) &&
     (iVar1 = (*pcVar2)(), iVar1 == 1)) {
    local_20[8] = 6;
    iVar1 = func_0x1000fd8c(1,local_20 + 8,DAT_10053a7c);
    if (iVar1 == 0) {
      return DAT_10053a7c;
    }
  }
  FUN_1004ca50(0);
  FUN_10056f28(local_20,0,6);
  FUN_1004cad8(0x16,6,local_20);
  iVar1 = 0;
  do {
    if (local_20[iVar1] != '\0') {
      iVar1 = 0;
      do {
        local_20[iVar1 + 8] = local_20[5 - iVar1];
        iVar1 = iVar1 + 1;
      } while (iVar1 != 6);
      goto LAB_10053a58;
    }
    iVar1 = iVar1 + 1;
  } while (iVar1 != 6);
  FUN_1004cad8(0x10,6,local_20);
  iVar1 = 0;
  while (local_20[iVar1] == '\0') {
    iVar1 = iVar1 + 1;
    if (iVar1 == 6) {
      local_20[8] = 6;
      func_0x1000fd8c(1,local_20 + 8,DAT_10053a7c);
      return DAT_10053a7c;
    }
  }
  iVar1 = 0;
  do {
    local_20[iVar1 + 8] = local_20[5 - iVar1];
    iVar1 = iVar1 + 1;
  } while (iVar1 != 6);
LAB_10053a58:
  FUN_10056de8(DAT_10053a7c);
  return DAT_10053a7c;
}


