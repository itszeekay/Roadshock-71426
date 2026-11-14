// FUNC 0x100501fc  FUN_100501fc

undefined4 FUN_100501fc(uint param_1)

{
  undefined4 uVar1;
  uint uVar2;
  char *pcVar3;
  
  uVar1 = 0;
  pcVar3 = DAT_10050234;
  do {
    if (*pcVar3 != '\0') {
      for (uVar2 = 0; (uVar2 & 0xff) < (uint)(byte)pcVar3[1]; uVar2 = uVar2 + 1) {
        if ((byte)pcVar3[uVar2 + 2] == param_1) {
          uVar1 = 1;
        }
      }
    }
    pcVar3 = pcVar3 + 0xe;
  } while (pcVar3 != DAT_10050238);
  return uVar1;
}


