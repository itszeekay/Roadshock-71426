// FUNC 0x10051c2c  FUN_10051c2c

void FUN_10051c2c(void)

{
  *DAT_10051c70 = DAT_10051c6c;
  *DAT_10051c74 = *DAT_10051c74 & 0xffffff | 0x12000000;
  *DAT_10051c78 = DAT_10051c7c & *DAT_10051c78 | 0x80000;
  *DAT_10051c80 = *DAT_10051c80 & 0xffffff0f | 0x80;
  *DAT_10051c84 = *DAT_10051c84 & 0xffffff0f | 0x80;
  return;
}


