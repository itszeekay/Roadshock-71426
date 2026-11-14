// FUNC 0x100502ec  FUN_100502ec

void FUN_100502ec(void)

{
  int iVar1;
  
  iVar1 = DAT_10050320;
  if (*(char *)(DAT_10050320 + 0x12) == '\x01') {
    FUN_100502d4();
    FUN_1004e9a8(4);
    *(undefined1 *)(iVar1 + 0x12) = 0;
    FUN_1004ead0();
    *DAT_10050324 = 0;
    FUN_10053930(0x2d);
    FUN_10051564();
  }
  log_printf(DAT_10050328);
  return;
}


