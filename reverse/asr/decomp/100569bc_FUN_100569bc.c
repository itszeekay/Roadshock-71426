// FUNC 0x100569bc  FUN_100569bc

void FUN_100569bc(int param_1,int param_2)

{
  char *pcVar1;
  
  pcVar1 = DAT_100569d0;
  if (param_2 == 0) {
    *(undefined1 *)(param_1 + 0x10) = 1;
    if (*pcVar1 == '\0') {
      *pcVar1 = '\x01';
    }
  }
  return;
}


