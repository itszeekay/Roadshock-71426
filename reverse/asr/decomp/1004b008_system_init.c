// FUNC 0x1004b008  system_init

void system_init(void)

{
  *puRam1004b020 = 1;
  *puRam1004b024 = 2;
  *puRam1004b028 = 2;
  func_0x1004c794();
  return;
}


