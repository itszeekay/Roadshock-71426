// FUNC 0x1005032c  FUN_1005032c

void FUN_1005032c(void)

{
  int iVar1;
  
  iVar1 = DAT_10050350;
  if (*(char *)(DAT_10050350 + 0xa4) == '\x01') {
    FUN_100502ec();
  }
  *(undefined1 *)(iVar1 + 0xa4) = 0;
  FUN_1004eac0();
  return;
}


