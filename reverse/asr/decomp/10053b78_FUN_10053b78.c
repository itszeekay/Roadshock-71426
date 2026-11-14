// FUNC 0x10053b78  FUN_10053b78

void FUN_10053b78(void)

{
  int *piVar1;
  char *pcVar2;
  undefined4 uVar3;
  
  pcVar2 = DAT_10053bbc;
  piVar1 = DAT_10053bb8;
  if (*DAT_10053bb8 != 0) {
    if ((*DAT_10053bbc != '\0') && (-1 < (int)((uint)*(byte *)(*DAT_10053bb8 + 0xc) << 0x1f))) {
      (*(code *)*DAT_10053bc0)(0x2000);
      uVar3 = 10;
      if (*(char *)(*piVar1 + 2) == '\0') {
        uVar3 = 2000;
      }
      FUN_10053918(0xe9,uVar3);
    }
    *pcVar2 = '\0';
  }
  return;
}


