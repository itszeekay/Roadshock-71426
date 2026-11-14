// FUNC 0x1004c5e4  FUN_1004c5e4

undefined4 FUN_1004c5e4(char *param_1,uint param_2,int param_3)

{
  char cVar1;
  int iVar2;
  
  cVar1 = *param_1;
  if (cVar1 == '\0') {
    iVar2 = 0x40000000;
  }
  else {
    iVar2 = DAT_1004c628;
    if (((cVar1 != '\x01') && (iVar2 = DAT_1004c62c, cVar1 != '\x02')) &&
       (iVar2 = DAT_1004c624, cVar1 != '\x03')) {
      return 0xffffffff;
    }
  }
  if (param_3 == 1) {
    *(uint *)(iVar2 + 0x48) = param_2 | *(uint *)(iVar2 + 0x48);
  }
  else {
    *(uint *)(iVar2 + 0x48) = *(uint *)(iVar2 + 0x48) & ~param_2;
  }
  return 0;
}


