// FUNC 0x1004fe88  FUN_1004fe88

undefined8 FUN_1004fe88(undefined4 param_1,undefined4 param_2)

{
  undefined1 local_10;
  undefined1 local_f;
  undefined1 local_e;
  undefined1 local_d;
  undefined1 local_c;
  undefined1 local_b;
  undefined2 uStack_a;
  
  local_c = (undefined1)param_2;
  local_b = (undefined1)((uint)param_2 >> 8);
  uStack_a = (undefined2)((uint)param_2 >> 0x10);
  local_10 = (undefined1)param_1;
  local_f = (undefined1)((uint)param_1 >> 8);
  local_e = (undefined1)((uint)param_1 >> 0x10);
  local_d = (undefined1)((uint)param_1 >> 0x18);
  *DAT_1004feb8 = 0;
  FUN_1004eac0();
  local_10 = 0x11;
  local_f = 0x11;
  local_e = 0x11;
  local_d = 0x11;
  local_c = 0x11;
  local_b = 0x11;
  FUN_100516d8(&local_10);
  *DAT_1004febc = 0;
  FUN_10053918(0x36,200);
  return CONCAT26(uStack_a,CONCAT15(local_b,CONCAT14(local_c,CONCAT13(local_d,CONCAT12(local_e,
                                                  CONCAT11(local_f,local_10))))));
}


