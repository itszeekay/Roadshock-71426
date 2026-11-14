// FUNC 0x100567dc  FUN_100567dc

undefined4 FUN_100567dc(int param_1)

{
  int iVar1;
  int local_40;
  undefined1 auStack_3c [20];
  undefined1 auStack_28 [28];
  
  *(undefined1 *)(param_1 + 0x29) = 1;
  local_40 = 0;
  FUN_100561b6(param_1,auStack_3c,0,&local_40,param_1,PTR_LAB_10056144_1_10056864,0);
  iVar1 = FUN_10056d58(*(undefined4 *)(param_1 + 0xc),*(undefined4 *)(param_1 + 8));
  if (iVar1 == local_40) {
    FUN_100567a4(param_1);
  }
  if (*(code **)(param_1 + 0x14) != (code *)0x0) {
    (**(code **)(param_1 + 0x14))(param_1);
  }
  FUN_100561b6(param_1,auStack_3c,0,param_1,0,PTR_LAB_1005632e_1_10056868,0);
  while( true ) {
    FUN_1005634e(param_1,auStack_28,param_1,0,PTR_FUN_1005655e_1_1005686c);
    if (*(char *)(param_1 + 0x28) == '\0') break;
    FUN_100562ac(param_1);
  }
  *(undefined1 *)(param_1 + 0x29) = 0;
  if (*(code **)(param_1 + 0x18) != (code *)0x0) {
    (**(code **)(param_1 + 0x18))(param_1);
  }
  return 0;
}


