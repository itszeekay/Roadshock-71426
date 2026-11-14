// FUNC 0x10054d40  FUN_10054d40

int FUN_10054d40(int param_1,ushort *param_2,ushort param_3,uint param_4,ushort *param_5)

{
  int iVar1;
  ushort *puVar2;
  undefined4 uVar3;
  undefined4 local_1c [2];
  
  local_1c[0] = FUN_10054d18(*param_5);
  iVar1 = func_0x1002f20c(param_2,DAT_10054dc8,local_1c,0x13,0,*(undefined2 *)(param_1 + 0x10),
                          DAT_10054dc4,param_4 & 0x1e);
  if (iVar1 == 0) {
    puVar2 = (ushort *)FUN_10056f18(0x20,1);
    *(ushort **)(param_1 + 0xc) = puVar2;
    puVar2[0xc] = *param_2;
    puVar2[0xd] = *param_5;
    uVar3 = DAT_10054dcc;
    if (-1 < (int)(param_4 << 0x1f)) {
      uVar3 = 0;
    }
    *puVar2 = (ushort)uVar3 | param_3;
    puVar2[1] = *(ushort *)(param_1 + 0x10);
    *(undefined2 *)(param_1 + 0x12) = 0x14;
    FUN_10055030(param_1);
    FUN_10056f38(puVar2 + 2);
    func_0x1000dc44(*(undefined2 *)(param_1 + 0x10),0);
  }
  return iVar1;
}


