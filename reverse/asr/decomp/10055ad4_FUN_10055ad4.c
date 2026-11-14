// FUNC 0x10055ad4  FUN_10055ad4

int FUN_10055ad4(byte *param_1,byte *param_2,undefined4 *param_3,uint param_4)

{
  byte bVar1;
  byte *pbVar2;
  byte *pbVar3;
  
  for (pbVar3 = param_1; *pbVar3 != 0; pbVar3 = pbVar3 + 1) {
  }
  *param_3 = param_1;
  do {
    do {
      pbVar2 = param_1;
      if (pbVar3 == pbVar2) {
        return -(uint)(*param_2 < 2);
      }
      param_1 = pbVar2 + 1;
    } while ((*pbVar2 != param_4) || (*pbVar2 = 0, pbVar2[1] == param_4));
    param_3[*param_2] = param_1;
    bVar1 = *param_2;
    *param_2 = bVar1 + 1;
  } while ((byte)(bVar1 + 1) < 8);
  return 0;
}


