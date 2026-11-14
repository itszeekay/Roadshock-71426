// FUNC 0x1004e344  FUN_1004e344

void FUN_1004e344(void)

{
  undefined *puVar1;
  int iVar2;
  undefined1 local_2c [2];
  undefined2 local_2a;
  undefined1 local_28;
  undefined4 local_1c;
  undefined4 local_18;
  undefined1 local_14;
  undefined1 local_13;
  
  puVar1 = PTR_s_app_ble_config_legacy_advertisin_1004e390;
  log_printf(PTR_s_APP___s_1004e394,PTR_s_app_ble_config_legacy_advertisin_1004e390);
  FUN_10056f28(local_2c,0,0x1c);
  local_2a = 3;
  local_28 = 0xe2;
  local_1c = 0x40;
  local_18 = 0x40;
  local_14 = 7;
  local_2c[0] = 1;
  local_13 = 1;
  iVar2 = FUN_10053454(0,local_2c);
  if (iVar2 != 0) {
    log_printf(PTR_s_APP___s_ERROR__02X_1004e398,puVar1);
  }
  return;
}


