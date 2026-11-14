// FUNC 0x10001c70  FUN_10001c70

undefined4 FUN_10001c70(uint param_1,int param_2,int param_3)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  undefined4 local_24;
  
  iVar2 = flash_status();
  uVar3 = param_3 + param_1;
  if (iVar2 != 0) {
    flash_end();
  }
  local_24 = param_2;
  for (; param_3 != 0; param_3 = param_3 - iVar4) {
    iVar4 = param_3;
    if (param_1 >> 8 < uVar3 >> 8) {
      iVar4 = 0x100 - (param_1 & 0xff);
    }
    iVar5 = 0;
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      iVar5 = isIRQinterruptsEnabled();
    }
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      enableIRQinterrupts(1);
    }
    flash_write_page(param_1,iVar4,local_24,1);
    if (iVar5 == 0) {
      bVar1 = (bool)isCurrentModePrivileged();
      if (bVar1) {
        enableIRQinterrupts(0);
      }
    }
    else {
      bVar1 = (bool)isCurrentModePrivileged();
      if (bVar1) {
        enableIRQinterrupts(1);
      }
    }
    param_1 = param_1 + iVar4;
    local_24 = local_24 + iVar4;
  }
  if (iVar2 != 0) {
    flash_begin();
  }
  return 0;
}


