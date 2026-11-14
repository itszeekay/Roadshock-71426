// FUNC 0x1004d1a8  FUN_1004d1a8

void FUN_1004d1a8(void)

{
  char cVar1;
  
  cVar1 = '@';
  do {
    if ((*(uint *)(DAT_1004d1c0 + 0x2c) & 0x10) != 0) {
      return;
    }
    cVar1 = cVar1 + -1;
  } while (cVar1 != '\0');
  return;
}


