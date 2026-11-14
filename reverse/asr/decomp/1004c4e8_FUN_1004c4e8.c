// FUNC 0x1004c4e8  FUN_1004c4e8

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1004c4e8(uint param_1)

{
  code *pcVar1;
  uint *puVar2;
  
  if (param_1 < 4) {
    puVar2 = *(uint **)(param_1 * 4 + DAT_1004c53c);
    if (((int)(puVar2[0x10] << 0x1b) < 0) || ((int)(puVar2[0x10] << 0x19) < 0)) {
      puVar2[0xe] = puVar2[0xe] & 0xffffffaf;
      puVar2[0x11] = puVar2[0x11] | 0x50;
      while ((puVar2[6] & 0x10) == 0) {
        pcVar1 = *(code **)(DAT_1004c540 + param_1 * 4);
        if (pcVar1 != (code *)0x0) {
          (*pcVar1)(*puVar2 & 0xff);
        }
      }
      puVar2[0xe] = puVar2[0xe] | 0x50;
    }
    return;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)software_udf(0xff,0x1004c536);
  (*pcVar1)();
}


