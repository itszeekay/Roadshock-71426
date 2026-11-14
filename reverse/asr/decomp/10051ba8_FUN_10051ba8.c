// FUNC 0x10051ba8  FUN_10051ba8

void FUN_10051ba8(void)

{
  uint *puVar1;
  uint uVar2;
  
  puVar1 = DAT_10051c10;
  *DAT_10051c10 = *DAT_10051c10 & 0xfffffff0;
  *puVar1 = *puVar1 | 8;
  *puVar1 = *puVar1 & 0xffffff0f;
  *puVar1 = *puVar1 | 0x80;
  *puVar1 = DAT_10051c14 & *puVar1;
  *puVar1 = *puVar1 | 0x800;
  *puVar1 = DAT_10051c18 & *puVar1;
  *puVar1 = *puVar1 | 0x8000;
  uVar2 = DAT_10051c20;
  puVar1 = DAT_10051c1c;
  *DAT_10051c1c = *DAT_10051c1c & 0xfffff000;
  *puVar1 = *puVar1 | uVar2;
  *DAT_10051c24 = 0xd0;
  *DAT_10051c28 = 1;
  return;
}


