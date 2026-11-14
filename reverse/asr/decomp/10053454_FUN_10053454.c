// FUNC 0x10053454  FUN_10053454

undefined2 FUN_10053454(undefined4 param_1,undefined1 *param_2)

{
  undefined2 uVar1;
  undefined1 local_38;
  undefined1 local_37;
  undefined2 local_36;
  undefined1 local_34;
  undefined1 local_33;
  undefined1 auStack_32 [6];
  undefined1 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined1 local_20;
  undefined1 local_1f;
  
  local_38 = 0;
  local_37 = *param_2;
  local_36 = *(undefined2 *)(param_2 + 2);
  local_34 = param_2[4];
  local_33 = param_2[5];
  FUN_10056de8(auStack_32,param_2 + 6);
  local_2c = param_2[0xc];
  local_24 = *(undefined4 *)(param_2 + 0x14);
  local_28 = *(undefined4 *)(param_2 + 0x10);
  local_1f = param_2[0x19];
  local_20 = param_2[0x18];
  uVar1 = FUN_10053204(param_1,&local_38);
  return uVar1;
}


