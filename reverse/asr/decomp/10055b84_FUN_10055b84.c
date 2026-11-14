// FUNC 0x10055b84  FUN_10055b84

undefined4 FUN_10055b84(undefined1 *param_1)

{
  undefined4 uVar1;
  int iVar2;
  char *pcVar3;
  undefined *puVar4;
  byte *pbVar5;
  byte local_39;
  undefined4 local_38 [9];
  
  local_39 = 0;
  FUN_1004bf28(DAT_10055c50,DAT_10055c4c);
  uVar1 = DAT_10055c58;
  pbVar5 = DAT_10055c4c;
  while (*pbVar5 != 0) {
    if ((0x5e < *pbVar5 - 0x20) || (pbVar5 = pbVar5 + 1, pbVar5 == DAT_10055c54)) {
      FUN_1004bf28(PTR_s_bl_ver_isn_t_str_10055c70);
      return 0xffffffff;
    }
  }
  FUN_10056de8(DAT_10055c58,DAT_10055c4c,pbVar5 + DAT_10055c5c);
  iVar2 = FUN_10056af4(uVar1,PTR_s_ASRBOOTLOADER_560X_10055c60,0x12);
  puVar4 = PTR_s_bl_ver_or_slip___error___d_10055c6c;
  if (iVar2 == 0) {
    local_39 = 1;
    iVar2 = FUN_10055ad4(uVar1,&local_39,local_38,0x2d);
    puVar4 = PTR_s_bl_ver_or_slip___error___d_10055c6c;
    if (iVar2 == 0) {
      if (local_39 < 3) {
        return 0xffffffff;
      }
      pcVar3 = (char *)local_38[local_39 - 1];
      if (*pcVar3 != 'V') {
        return 0xffffffff;
      }
      pcVar3 = pcVar3 + 1;
      puVar4 = PTR_s_bl_slip___error___d_10055c68;
      if (pcVar3 != (char *)0x0) {
        local_39 = 1;
        iVar2 = FUN_10055ad4(pcVar3,&local_39,local_38,0x2e);
        puVar4 = PTR_s_bl_slip___error___d_10055c68;
        if (iVar2 == 0) {
          iVar2 = FUN_10056cd8(local_38[0],0,10);
          if (iVar2 < 2) {
            *param_1 = 0;
          }
          else {
            *param_1 = 1;
          }
          FUN_1004bf28(PTR_s_bl_first_ver__s_10055c64,local_38[0]);
          return 0;
        }
      }
    }
  }
  FUN_1004bf28(puVar4,local_39);
  return 0xffffffff;
}


