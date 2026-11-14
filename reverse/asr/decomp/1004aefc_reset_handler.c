// FUNC 0x1004aefc  reset_handler

/* Copies init image 0x10059118 -> 0x20000800, then calls system_init and main */

void reset_handler(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  *puRam1004af68 = 4;
  for (iVar1 = 0; (uint)(iRam1004af70 + iVar1) < uRam1004af74; iVar1 = iVar1 + 4) {
    *(undefined4 *)(iRam1004af70 + iVar1) = *(undefined4 *)(iRam1004af6c + iVar1);
  }
  for (iVar1 = 0; puVar3 = puRam1004af84, (uint)(iRam1004af7c + iVar1) < uRam1004af80;
      iVar1 = iVar1 + 4) {
    *(undefined4 *)(iRam1004af7c + iVar1) = *(undefined4 *)(iRam1004af78 + iVar1);
  }
  for (; puVar2 = puRam1004af8c, puVar3 < puRam1004af88; puVar3 = puVar3 + 1) {
    *puVar3 = 0;
  }
  for (; puVar3 = puRam1004af94, puVar2 < puRam1004af90; puVar2 = puVar2 + 1) {
    *puVar2 = 0;
  }
  for (; puVar3 < puRam1004af9c; puVar3 = puVar3 + 1) {
    *puVar3 = uRam1004af98;
  }
  system_init();
  func_0x10056ec8();
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}


