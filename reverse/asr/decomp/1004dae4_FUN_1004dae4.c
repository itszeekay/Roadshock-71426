// FUNC 0x1004dae4  FUN_1004dae4

void FUN_1004dae4(undefined4 *param_1)

{
  char cVar1;
  byte bVar2;
  undefined1 uVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined4 *puVar6;
  uint *puVar7;
  undefined4 uVar8;
  undefined1 auStack_19 [5];
  
  puVar6 = DAT_1004dbd8;
  puVar4 = DAT_1004dbd0;
  cVar1 = *(char *)(param_1 + 2);
  if (cVar1 == '\0') {
    bVar2 = *(byte *)(param_1 + 4);
    FUN_1004d1a8();
    if (bVar2 < 8) {
      FUN_1004d9f0(bVar2 + 6,auStack_19);
    }
    FUN_1004d6e0(bVar2,0);
    iVar5 = DAT_1004dbd4;
    *(uint *)(DAT_1004dbd4 + 4) = *(uint *)(DAT_1004dbd4 + 4) & 0xfffffff7;
    *(uint *)(iVar5 + 4) = *(uint *)(iVar5 + 4) & 0xffffffef;
    *(uint *)(iVar5 + 0x28) = *(uint *)(iVar5 + 0x28) | 4;
  }
  else {
    if (cVar1 != '\x01') {
      FUN_1004d1c4();
      FUN_1004d6e0(3,cVar1);
      puVar7 = DAT_1004dbdc;
      *DAT_1004dbdc = *DAT_1004dbdc | 4;
      *puVar7 = *puVar7 & 0xffffffdf;
      puVar7[2] = puVar7[2] | 4;
      *puVar6 = 0x800000;
      FUN_1004d1c4();
      FUN_1004d250(*(undefined1 *)(param_1 + 2),*(undefined1 *)((int)param_1 + 0x13));
      if (*(byte *)((int)param_1 + 0x11) < 0xe) {
        FUN_1004d4b4();
      }
      FUN_1004dacc(*(undefined1 *)((int)param_1 + 0x12));
      puVar4[2] = *param_1;
      puVar4[3] = param_1[1];
      return;
    }
    uVar8 = param_1[5];
    uVar3 = *(undefined1 *)(param_1 + 6);
    FUN_1004d1a8();
    FUN_1004d6e0(3,1);
    FUN_1004d5c0(uVar8,uVar3);
    iVar5 = DAT_1004dbd4;
    *(uint *)(DAT_1004dbd4 + 4) = *(uint *)(DAT_1004dbd4 + 4) | 8;
    *(uint *)(iVar5 + 4) = *(uint *)(iVar5 + 4) & 0xffffffef;
    *(uint *)(iVar5 + 0x28) = *(uint *)(iVar5 + 0x28) | 4;
    *puVar6 = 0x400000;
    FUN_1004d1a8();
  }
  *puVar4 = *param_1;
  puVar4[1] = param_1[1];
  return;
}


