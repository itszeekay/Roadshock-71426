// FUNC 0x1004da58  FUN_1004da58

void FUN_1004da58(int param_1)

{
  if (param_1 == 1) {
    *(uint *)(DAT_1004da70 + 4) = *(uint *)(DAT_1004da70 + 4) | 1;
  }
  else {
    *(uint *)(DAT_1004da70 + 4) = *(uint *)(DAT_1004da70 + 4) & 0xfffffffe;
  }
  return;
}


