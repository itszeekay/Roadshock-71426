// FUNC 0x10051f48  FUN_10051f48

undefined8 FUN_10051f48(int param_1,int param_2)

{
  code *pcVar1;
  int extraout_r1;
  int iVar2;
  int iVar3;
  undefined2 *puVar4;
  int unaff_r7;
  
  iVar3 = *DAT_10052068;
  pcVar1 = (code *)0x1;
  if (iVar3 != 0) {
    if ((uint)(param_2 + DAT_1005206c) < 0x27) {
      iVar2 = DAT_1005206c;
      FUN_10056ee8();
      *(char *)(iVar3 + 9) = (char)iVar2;
      *(ushort *)(unaff_r7 + extraout_r1 + -0x2c) = (ushort)*(byte *)(unaff_r7 + 0x15);
      puVar4 = (undefined2 *)(uint)*(byte *)(iVar3 + 0x15);
      pcVar1 = *(code **)(iVar3 + 8);
      if (pcVar1 != (code *)0x0) {
        param_1 = (int)puVar4 + 5;
        pcVar1 = (code *)(*pcVar1)((int)puVar4 << 1,*puVar4,puVar4[1],*(undefined1 *)(puVar4 + 2),
                                   param_1,param_2);
      }
    }
    else {
      pcVar1 = (code *)0x0;
    }
  }
  return CONCAT44(param_1,pcVar1);
}


