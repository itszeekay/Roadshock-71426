// FUNC 0x10002d3c  FUN_10002d3c

undefined4 FUN_10002d3c(int param_1,uint param_2)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  
  uVar1 = 6;
  if (param_2 < 0x28) {
    uVar3 = (param_2 & 1) + 2 << ((param_2 >> 1) + 0xb & 0xff);
    *(uint *)(param_1 + 0x30) = uVar3;
    if (*(char *)(param_1 + 0x3c) != '\0') {
      if (*(uint *)(param_1 + 0x34) < uVar3) {
        return 4;
      }
      *(uint *)(param_1 + 0x2c) = uVar3;
      if ((*(char *)(param_1 + 0x3c) == '\x02') && (*(uint *)(param_1 + 0x38) < uVar3)) {
        FUN_100043d0(*(undefined4 *)(param_1 + 0x18));
        iVar2 = FUN_100043bc(*(undefined4 *)(param_1 + 0x30));
        *(int *)(param_1 + 0x18) = iVar2;
        if (iVar2 == 0) {
          *(undefined4 *)(param_1 + 0x38) = 0;
          return 3;
        }
      }
    }
    uVar1 = 0;
    *(undefined4 *)(param_1 + 100) = 0;
    *(undefined1 *)(param_1 + 0x40) = 0;
    *(undefined1 *)(param_1 + 0x4c) = 1;
    *(undefined4 *)(param_1 + DAT_10002da0) = 0;
  }
  return uVar1;
}


