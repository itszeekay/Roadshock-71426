// FUNC 0x10056870  FUN_10056870

void FUN_10056870(int param_1,uint param_2)

{
  uint uVar1;
  
  if (param_1 == 0) {
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  if (param_2 < 4) {
    uVar1 = FUN_10056ee8(param_2);
    if (*(char *)(param_1 + 0x10) != '\0') {
      do {
                    /* WARNING: Do nothing block with infinite loop */
      } while( true );
    }
    *(undefined4 *)(param_1 + 8) = *(undefined4 *)(uVar1 >> 4);
  }
  return;
}


