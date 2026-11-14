// FUNC 0x1004f814  FUN_1004f814

char FUN_1004f814(char *param_1,int param_2)

{
  char cVar1;
  char *pcVar2;
  
  pcVar2 = param_1 + param_2;
  cVar1 = '\0';
  for (; param_1 != pcVar2; param_1 = param_1 + 1) {
    cVar1 = cVar1 + *param_1;
  }
  return cVar1;
}


