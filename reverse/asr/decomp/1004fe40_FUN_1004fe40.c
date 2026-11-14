// FUNC 0x1004fe40  FUN_1004fe40

undefined8 FUN_1004fe40(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  byte bVar1;
  undefined1 local_10;
  undefined1 local_f;
  undefined1 local_e;
  undefined1 local_d;
  undefined1 local_c;
  undefined1 local_b;
  undefined2 uStack_a;
  undefined4 uStack_8;
  
  local_c = (undefined1)param_2;
  local_b = (undefined1)((uint)param_2 >> 8);
  uStack_a = (undefined2)((uint)param_2 >> 0x10);
  local_10 = (undefined1)param_1;
  local_f = (undefined1)((uint)param_1 >> 8);
  local_e = (undefined1)((uint)param_1 >> 0x10);
  local_d = (undefined1)((uint)param_1 >> 0x18);
  bVar1 = *DAT_1004fe80 + 1;
  *DAT_1004fe80 = bVar1;
  uStack_8 = param_3;
  if ((int)((uint)bVar1 << 0x1f) < 0) {
    local_10 = 0x44;
  }
  else {
    if (3 < bVar1) {
      FUN_100516d8(DAT_1004fe84);
      goto LAB_1004fe7e;
    }
    local_10 = 0x55;
  }
  local_f = local_10;
  local_e = local_10;
  local_d = local_10;
  local_c = local_10;
  local_b = local_10;
  FUN_100516d8(&local_10);
  FUN_10053918(0x35,200);
LAB_1004fe7e:
  return CONCAT26(uStack_a,CONCAT15(local_b,CONCAT14(local_c,CONCAT13(local_d,CONCAT12(local_e,
                                                  CONCAT11(local_f,local_10))))));
}


