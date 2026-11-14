// FUNC 0x100568a2  FUN_100568a2

int FUN_100568a2(int param_1)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = FUN_10056a80();
  if (iVar1 == 0) {
    *(undefined1 *)(param_1 + 0x28) = 0;
    *(undefined1 *)(param_1 + 0x29) = 0;
    uVar2 = FUN_10056d58(*(undefined4 *)(param_1 + 0xc),*(undefined4 *)(param_1 + 8));
    if (uVar2 < 2) {
      do {
                    /* WARNING: Do nothing block with infinite loop */
      } while( true );
    }
    iVar1 = FUN_100567dc(param_1);
  }
  FUN_100569bc(param_1,iVar1);
  return iVar1;
}


