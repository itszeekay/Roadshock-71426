// FUNC 0x10050ea2  FUN_10050ea2

void FUN_10050ea2(void)

{
  int iVar1;
  int unaff_r7;
  
  iVar1 = DAT_10050f74;
  if (*(char *)(DAT_10050f74 + 0xa8) != '\0') {
    FUN_10051294();
    return;
  }
  if (unaff_r7 != 1) {
    FUN_10051294();
    return;
  }
  FUN_1004eab0();
  *(undefined1 *)(iVar1 + 0xa8) = 1;
  FUN_100507a0(DAT_10050fac);
  return;
}


