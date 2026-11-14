// FUNC 0x1004c5bc  FUN_1004c5bc

void FUN_1004c5bc(int param_1,uint param_2,int param_3)

{
  if (param_3 == 0) {
    *(uint *)(param_1 + 0x38) = *(uint *)(param_1 + 0x38) & ~param_2;
  }
  else {
    *(uint *)(param_1 + 0x38) = param_2 | *(uint *)(param_1 + 0x38);
  }
  return;
}


