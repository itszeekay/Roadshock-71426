// FUNC 0x1004d690  mic_pins_config

/* Configures P27/P28/P29 for the audio front end */

undefined8 mic_pins_config(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined1 uVar1;
  undefined1 local_18;
  undefined1 local_17;
  undefined2 uStack_16;
  undefined4 local_14;
  undefined4 uStack_10;
  
  uStack_16 = (undefined2)((uint)param_1 >> 0x10);
  local_18 = 0x1c;
  uVar1 = (undefined1)param_1;
  local_14 = 0;
  local_17 = uVar1;
  uStack_10 = param_3;
  pin_config(&local_18);
  local_18 = 0x1d;
  local_14 = 0;
  local_17 = uVar1;
  pin_config(&local_18);
  local_18 = 0x1b;
  local_14 = 0;
  local_17 = uVar1;
  pin_config(&local_18);
  FUN_1004afa2(600);
  FUN_1004cb20(1,0x1f,1);
  return CONCAT44(local_14,CONCAT22(uStack_16,CONCAT11(local_17,local_18)));
}


