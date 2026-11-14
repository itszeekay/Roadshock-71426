// FUNC 0x10049c38  FUN_10049c38

bool FUN_10049c38(int param_1,uint param_2,int param_3,uint param_4)

{
  bool bVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar4 = param_2 & 0xfffff;
  uVar3 = (param_2 << 1) >> 0x15;
  uVar2 = (param_4 << 1) >> 0x15;
  if ((((uVar3 != DAT_10049cb4) || (bVar1 = true, uVar4 == 0 && param_1 == 0)) &&
      ((uVar2 != DAT_10049cb4 || (bVar1 = true, param_3 == 0 && (param_4 & 0xfffff) == 0)))) &&
     (((bVar1 = true, uVar3 == uVar2 && (uVar4 == (param_4 & 0xfffff))) && (param_1 == param_3)))) {
    if (-((int)param_2 >> 0x1f) == -((int)param_4 >> 0x1f)) {
      bVar1 = false;
    }
    else if (uVar3 == 0) {
      bVar1 = param_1 != 0 || uVar4 != 0;
    }
  }
  return bVar1;
}


