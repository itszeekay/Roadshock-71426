// FUNC 0x1004afb0  FUN_1004afb0

void FUN_1004afb0(int param_1)

{
  int iVar1;
  uint uVar2;
  undefined4 local_c;
  
  iVar1 = FUN_10056d58(*DAT_1004b000,DAT_1004b004);
  uVar2 = FUN_10056d58(iVar1 * param_1,0x11);
  if (uVar2 < 0xc) {
    local_c = 0;
  }
  else {
    local_c = uVar2 - 0xc;
  }
  for (; local_c != 0; local_c = local_c + -1) {
  }
  return;
}


