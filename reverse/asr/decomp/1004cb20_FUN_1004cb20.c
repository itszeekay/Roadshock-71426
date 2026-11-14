// FUNC 0x1004cb20  FUN_1004cb20

void FUN_1004cb20(int param_1,uint param_2,uint param_3,uint param_4)

{
  uint *puVar1;
  uint uVar2;
  
  if ((((param_1 != 0xff) && (param_2 < 0x20)) && (param_3 < 0x21)) &&
     (uVar2 = 1 << (param_3 & 0xff), param_4 < uVar2)) {
    puVar1 = (uint *)(param_1 * 4 + DAT_1004cb50);
    *puVar1 = param_4 << (param_2 & 0xff) | *puVar1 & ~(uVar2 - 1 << (param_2 & 0xff));
  }
  return;
}


