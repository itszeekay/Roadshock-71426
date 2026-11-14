// FUNC 0x1005513c  FUN_1005513c

int FUN_1005513c(int param_1,ushort *param_2,ushort param_3,uint param_4,byte *param_5)

{
  ushort uVar1;
  int iVar2;
  ushort *puVar3;
  undefined4 uVar4;
  undefined1 local_19 [5];
  
  local_19[0] = 0x3f;
  iVar2 = func_0x1002f20c(param_2,*DAT_100551b8,local_19,6,0,*(undefined2 *)(param_1 + 0x10),
                          DAT_100551bc,param_4 & 0x1e);
  if (iVar2 == 0) {
    puVar3 = (ushort *)FUN_10056f18(10,1);
    uVar1 = *param_2;
    *(ushort **)(param_1 + 0xc) = puVar3;
    puVar3[2] = uVar1;
    puVar3[3] = (ushort)*param_5;
    uVar4 = DAT_100551c0;
    if (-1 < (int)(param_4 << 0x1f)) {
      uVar4 = 0;
    }
    *puVar3 = (ushort)uVar4 | param_3;
    puVar3[1] = *(ushort *)(param_1 + 0x10);
    *(undefined2 *)(param_1 + 0x12) = 0x50;
    FUN_100556e8(param_1);
    func_0x1000dc44(*(undefined2 *)(param_1 + 0x10),0);
    FUN_100556b4();
  }
  return iVar2;
}


