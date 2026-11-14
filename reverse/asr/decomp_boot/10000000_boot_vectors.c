// FUNC 0x10000000  boot_vectors

int boot_vectors(void)

{
  int iVar1;
  int in_r3;
  uint unaff_r4;
  int unaff_r6;
  
  *(short *)(unaff_r4 - in_r3) = (short)(unaff_r4 >> 0xd) + (short)unaff_r4;
  iVar1 = *(int *)(unaff_r6 + 0x35);
  if ((*puRam10000130 & 2) == 0) {
    *puRam10000130 = 2;
  }
  return iVar1 + 0x2e;
}


