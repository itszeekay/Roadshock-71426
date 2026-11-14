// FUNC 0x10053564  FUN_10053564

undefined4 FUN_10053564(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = DAT_10053594;
  if (param_1 == 0) {
    uVar1 = 0x340;
  }
  else {
    *DAT_10053590 = *(undefined1 *)(param_1 + 0x28);
    *DAT_10053598 = 1;
    FUN_10056de8(uVar1,param_1,0x2a);
    FUN_10053544();
    uVar1 = 0;
  }
  return uVar1;
}


