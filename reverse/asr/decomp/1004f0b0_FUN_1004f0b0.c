// FUNC 0x1004f0b0  FUN_1004f0b0

undefined4
FUN_1004f0b0(undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4,
            undefined1 *param_5)

{
  byte bVar1;
  undefined4 extraout_r1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  byte *pbVar5;
  int iVar6;
  char cVar7;
  uint uVar8;
  undefined1 *puVar9;
  byte local_20 [12];
  
  FUN_10056de8(local_20,DAT_1004f404 + 8,6);
  uVar8 = param_2 + ~(uint)*DAT_1004f408 & 0xffff;
  uVar2 = uVar8;
  FUN_1004bf28(DAT_1004f410,DAT_1004f40c,uVar8,param_2,param_3);
  FUN_1004cf2c();
  if (uVar8 - 1 < 0x10) {
    FUN_10056e18();
    FUN_1004bf28(DAT_1004f414,extraout_r1,uVar2 << 0x1a,(int)param_5 << 2,param_3);
    for (puVar9 = param_5; (int)puVar9 - (int)param_5 < 0; puVar9 = puVar9 + 1) {
      FUN_1004bf28(DAT_1004f418,*puVar9);
    }
    FUN_1004bf28(DAT_1004f41c);
    uVar3 = DAT_1004f424;
    if (*(char *)(DAT_1004f420 + 0x11) != '\x02') {
      cVar7 = '\x02';
      iVar6 = 0;
      FUN_10056de8(DAT_1004f428,param_5,0);
      *DAT_1004f42c = 0;
      do {
        iVar4 = DAT_1004f428 + iVar6;
        bVar1 = *(byte *)(iVar4 + 1);
        if (bVar1 >> 4 != 8) {
          pbVar5 = (byte *)(iVar6 + 0x57 + DAT_1004f420);
          *pbVar5 = *pbVar5 & 0xf | bVar1 & 0xf0;
          local_20[iVar6] = bVar1;
          if ((bVar1 >> 4) - 2 < 2) {
            FUN_100519ec(cVar7 + -1);
          }
          else {
            FUN_1005189c();
          }
        }
        bVar1 = *(byte *)(iVar4 + 1);
        uVar2 = bVar1 & 0xf;
        if (uVar2 != 8) {
          pbVar5 = (byte *)(iVar6 + 0x57 + DAT_1004f420);
          *pbVar5 = *pbVar5 & 0xf0 | (byte)uVar2;
          local_20[iVar6] = bVar1;
          if (uVar2 - 2 < 2) {
            FUN_100519ec(cVar7);
          }
          else {
            FUN_1005189c();
          }
        }
        iVar4 = DAT_1004f420;
        cVar7 = cVar7 + '\x02';
        iVar6 = iVar6 + 1;
      } while (iVar6 != 6);
      if (*(char *)(DAT_1004f420 + 0x12) == '\0') {
        FUN_10050354(*(undefined1 *)(DAT_1004f420 + 8),*(undefined1 *)(DAT_1004f420 + 9),
                     *(undefined1 *)(DAT_1004f420 + 10),*(undefined1 *)(DAT_1004f420 + 0xb),
                     *(undefined1 *)(DAT_1004f420 + 0xc));
        *(undefined1 *)(iVar4 + 0x12) = 1;
        FUN_1004eae0();
        if (*DAT_1004f430 != '\0') {
          *DAT_1004f434 = 1;
          FUN_10053918(0x2d,100);
        }
        FUN_10051564();
      }
      FUN_1004fd78(local_20[0],local_20[1],local_20[2],local_20[3],local_20[4],local_20[5]);
      uVar3 = DAT_1004f438;
    }
    FUN_1004bf28(uVar3,0);
    uVar3 = 0;
  }
  else {
    uVar3 = 10;
  }
  FUN_100522c8(param_1,param_2,uVar3);
  return 0;
}


