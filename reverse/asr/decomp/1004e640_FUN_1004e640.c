// FUNC 0x1004e640  FUN_1004e640

undefined4 FUN_1004e640(uint param_1,undefined4 param_2,undefined4 param_3,uint param_4)

{
  undefined1 uVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  undefined *puVar4;
  undefined *puVar5;
  int iVar6;
  undefined *puVar7;
  uint uVar8;
  undefined *puVar9;
  char *pcVar10;
  undefined1 auStack_2c [24];
  
  puVar9 = PTR_s_app_ble_complete_event_handler_1004e7a0;
  log_printf(PTR_s_APP_COMPLETE___s_opt_id__04X_sta_1004e7a4,
             PTR_s_app_ble_complete_event_handler_1004e7a0,param_1,param_2,param_3,param_4);
  puVar5 = PTR_s_app_ble_start_advertising_1004e7dc;
  puVar4 = PTR_s_APP___s_1004e7c0;
  puVar7 = PTR_s_app_ble_set_adv_data_1004e7bc;
  if (param_1 == DAT_1004e7a8) {
    param_4 = param_4 & 0xffff;
    puVar7 = DAT_1004e7ec;
  }
  else {
    if (DAT_1004e7a8 < param_1) {
      if (param_1 != DAT_1004e7ac) {
        if (param_1 != DAT_1004e7b0) {
          if (param_1 != DAT_1004e7b4) {
            return 0;
          }
          FUN_10051ba0(10);
          if (*DAT_1004e7b8 != '\0') {
            FUN_1004e344();
          }
          FUN_1004e608();
          return 0;
        }
        if (*DAT_1004e7e0 == '\0') {
          FUN_10054ca8();
        }
        if (*DAT_1004e7e4 != '\0') {
          return 0;
        }
        FUN_100550f4();
        return 0;
      }
      log_printf(PTR_s_APP___s_1004e7c0,PTR_s_app_ble_set_adv_data_1004e7bc);
      FUN_10056de8(auStack_2c,PTR_s_0123456789ABCDEF_1004e7c4,0x11);
      iVar6 = DAT_1004e7cc;
      uVar8 = *(uint *)(DAT_1004e7c8 + 4);
      uVar1 = auStack_2c[uVar8 >> 0x10 & 0xf];
      uVar2 = auStack_2c[uVar8 >> 8 & 0xf];
      *(undefined1 *)(DAT_1004e7cc + 0x14) = auStack_2c[(uVar8 >> 0x10 & 0xff) >> 4];
      *(undefined1 *)(iVar6 + 0x15) = uVar1;
      uVar1 = auStack_2c[uVar8 & 0xf];
      uVar3 = auStack_2c[(uVar8 >> 8 & 0xff) >> 4];
      *(undefined1 *)(iVar6 + 0x18) = auStack_2c[(uVar8 & 0xff) >> 4];
      *(undefined1 *)(iVar6 + 0x19) = uVar1;
      *(undefined1 *)(iVar6 + 0x16) = uVar3;
      *(undefined1 *)(iVar6 + 0x17) = uVar2;
      iVar6 = FUN_10053788(0x1a);
      if (iVar6 != 0) {
        log_printf(PTR_s_APP___s_ERROR__02X_1004e7d0,puVar7);
      }
      puVar9 = PTR_s_app_ble_set_scan_response_data_1004e7d4;
      log_printf(puVar4,PTR_s_app_ble_set_scan_response_data_1004e7d4);
      FUN_10056de8(auStack_2c,PTR_DAT_1004e7d8,4);
      param_4 = FUN_100537bc(4,auStack_2c);
      puVar7 = PTR_s_APP___s_ERROR__02X_1004e7d0;
    }
    else {
      if (param_1 == 0x11b) {
        pcVar10 = DAT_1004e7e0;
        if ((param_4 == 0x14) || (pcVar10 = DAT_1004e7e4, param_4 == 0x50)) {
          *pcVar10 = '\x01';
        }
        if (*DAT_1004e7e8 != 0) {
          return 0;
        }
        if (param_4 != 0x14) {
          return 0;
        }
        FUN_1004ee2c();
        return 0;
      }
      if (param_1 != 0x1a9) {
        return 0;
      }
      log_printf(PTR_s_APP___s_1004e7c0,PTR_s_app_ble_start_advertising_1004e7dc);
      param_4 = FUN_100536d4(0);
      puVar7 = PTR_s_APP___s_ERROR__02X_1004e7d0;
      puVar9 = puVar5;
    }
    PTR_s_APP___s_ERROR__02X_1004e7d0 = puVar7;
    if (param_4 == 0) {
      return 0;
    }
  }
  log_printf(puVar7,puVar9,param_4);
  return 0;
}


