// FUNC 0x10050488  FUN_10050488

undefined8 FUN_10050488(uint param_1,uint param_2)

{
  ushort *puVar1;
  undefined1 *puVar2;
  ushort uVar3;
  uint local_14;
  
  puVar1 = DAT_10050518;
  if (*DAT_10050510 != '\0') {
    *DAT_10050510 = *DAT_10050510 + -1;
    local_14 = param_2;
    goto LAB_1005050c;
  }
  *DAT_10050510 = *DAT_10050514;
  if (*DAT_1005051c == '\0') {
    if (*puVar1 == 0) {
      uVar3 = 0x166;
    }
    else {
      uVar3 = *puVar1 - 1;
    }
LAB_100504b6:
    *puVar1 = uVar3;
  }
  else if (*DAT_1005051c == '\x01') {
    if (*puVar1 < 0x167) {
      uVar3 = *puVar1 + 1;
      goto LAB_100504b6;
    }
    *puVar1 = 1;
  }
  puVar2 = DAT_10050524;
  local_14 = (uint)*DAT_10050520;
  FUN_1004fec0(DAT_10050524,DAT_10050524 + 1,DAT_10050524 + 2,*puVar1,*DAT_10050528);
  puVar2[3] = 0;
  puVar2[4] = 0xff;
  FUN_10050354(*puVar2,puVar2[1],puVar2[2],0,0xff);
  param_1 = (uint)(byte)puVar2[2];
  FUN_1004bf28(DAT_1005052c,*puVar1,*puVar2,puVar2[1]);
LAB_1005050c:
  return CONCAT44(local_14,param_1);
}


