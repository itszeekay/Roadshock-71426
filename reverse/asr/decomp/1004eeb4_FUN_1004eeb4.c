// FUNC 0x1004eeb4  FUN_1004eeb4

bool FUN_1004eeb4(undefined4 param_1,short param_2)

{
  bool bVar1;
  ushort uVar2;
  int unaff_r4;
  uint uVar3;
  int unaff_r7;
  undefined4 in_stack_00000004;
  undefined2 uStack_1c;
  
  uVar2 = *DAT_1004f05c;
  uVar3 = (uint)(ushort)(param_2 + ~uVar2);
  log_printf(DAT_1004f064,DAT_1004f060,uVar3);
  bVar1 = uVar3 - 1 < 0x12;
  if (bVar1) {
    FUN_10056ee8();
    *(ushort *)(unaff_r7 + uVar3) = (short)unaff_r7 - (param_2 + ~uVar2);
    *(undefined2 *)(unaff_r4 + 0x34) = uStack_1c;
    FUN_1005226c(in_stack_00000004,*(undefined2 *)(unaff_r4 + 0x14),0,*DAT_1004f068);
  }
  return !bVar1;
}


