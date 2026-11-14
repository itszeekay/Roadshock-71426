// FUNC 0x1004e608  FUN_1004e608

void FUN_1004e608(void)

{
  FUN_10053918(0x29,0x4b);
  FUN_10053918(0x30,0x28);
  if (*(char *)(DAT_1004e638 + 0x12) == '\0') {
    FUN_1004ead0();
  }
  else {
    *DAT_1004e63c = 1;
    FUN_10053918(0x2d,100);
  }
  return;
}


