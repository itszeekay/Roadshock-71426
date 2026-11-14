// FUNC 0x1004f7e0  FUN_1004f7e0

void FUN_1004f7e0(void)

{
  short *psVar1;
  short *psVar2;
  
  FUN_100538e8(0xc,0);
  psVar2 = (short *)(DAT_1004f80c + 2);
  psVar1 = (short *)(DAT_1004f80c + DAT_1004f810);
  do {
    if (((char)psVar2[-1] != '\0') && (*psVar2 != 0)) {
      *psVar2 = *psVar2 + -1;
    }
    psVar2 = psVar2 + 0x13;
  } while (psVar2 != psVar1);
  return;
}


