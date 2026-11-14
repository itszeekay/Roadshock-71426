// FUNC 0x1005147c  FUN_1005147c

undefined8 FUN_1005147c(uint param_1,undefined4 param_2)

{
  byte *pbVar1;
  int iVar2;
  uint uVar3;
  byte bVar4;
  char cVar5;
  uint uVar6;
  undefined4 local_10;
  
  uVar3 = FUN_1005023c();
  pbVar1 = DAT_10051514;
  bVar4 = 0;
  if (0xb6 < uVar3) {
    if (uVar3 - 0xb7 < 0xb6) {
      bVar4 = 1;
    }
    else if (uVar3 - 0x16d < 0x1b4) {
      bVar4 = 2;
    }
    else if (DAT_1005151c < uVar3 + DAT_10051518) {
      bVar4 = 4;
    }
    else {
      bVar4 = 3;
    }
  }
  *DAT_10051514 = bVar4;
  iVar2 = DAT_10051520;
  bVar4 = *(byte *)(DAT_10051520 + 0xc);
  uVar6 = (uint)bVar4;
  uVar3 = (uint)*(byte *)(DAT_10051524 + (uint)*pbVar1);
  if (uVar3 < uVar6) {
    if (uVar6 < 0x81) {
      if (uVar6 <= uVar3 + 1) {
LAB_100514ea:
        *(byte *)(DAT_10051520 + 0xc) = *(byte *)(DAT_10051524 + (uint)*pbVar1);
        goto LAB_100514f2;
      }
      cVar5 = bVar4 - 2;
    }
    else {
      cVar5 = bVar4 - 10;
    }
  }
  else {
    if (uVar3 <= uVar6) goto LAB_100514f2;
    if (uVar6 < 0x81) {
      cVar5 = bVar4 + 2;
    }
    else {
      cVar5 = bVar4 + 10;
      if ((int)(uVar3 - uVar6) < 10) goto LAB_100514ea;
    }
  }
  *(char *)(DAT_10051520 + 0xc) = cVar5;
LAB_100514f2:
  local_10 = param_1;
  if ((*DAT_10051528 == '\0') && (*(char *)(iVar2 + 0x11) != '\x03')) {
    local_10 = (uint)*(byte *)(iVar2 + 0xc);
    FUN_10050354(*(undefined1 *)(iVar2 + 8),*(undefined1 *)(iVar2 + 9),*(undefined1 *)(iVar2 + 10),
                 *(undefined1 *)(iVar2 + 0xb));
  }
  return CONCAT44(param_2,local_10);
}


