// FUNC 0x1004f7bc  FUN_1004f7bc

void FUN_1004f7bc(int param_1)

{
  char *pcVar1;
  
  pcVar1 = DAT_1004f7d8;
  if (param_1 == 0x37) {
    if (*DAT_1004f7d8 != '\0') {
      FUN_10051588(DAT_1004f7dc);
      *pcVar1 = '\0';
    }
  }
  return;
}


