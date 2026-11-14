// FUNC 0x10003ef4  FUN_10003ef4

int FUN_10003ef4(int param_1,undefined4 param_2,int *param_3)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  char local_2d;
  undefined1 auStack_2c [4];
  undefined4 local_28;
  undefined4 local_24;
  uint local_20;
  undefined2 local_1c;
  
  iVar6 = 8;
  if (*(char *)(param_1 + 0x10) != '\0') {
    if (*(code **)(param_1 + 0x14) != (code *)0x0) {
      (**(code **)(param_1 + 0x14))();
    }
    iVar2 = *param_3;
    if (iVar2 == 0) {
      iVar6 = FUN_10003a48(param_1,param_2,0,1);
    }
    else {
      uVar3 = param_3[1];
      iVar4 = param_1 + 0x44;
      iVar1 = FUN_10003e10(param_1,iVar4,uVar3 + 0x14);
      iVar6 = 7;
      if (iVar1 != -1) {
        iVar5 = param_1 + 0x2c;
        iVar1 = FUN_10003a1c(param_1,param_2,iVar5);
        if ((iVar1 == 0) || (iVar6 = FUN_10003a48(param_1,param_2,iVar5,0), iVar6 == 0)) {
          local_2d = '\0';
          iVar7 = *(int *)(param_1 + 0x54);
          FUN_10004b08(auStack_2c,0xff,0x14);
          local_28 = DAT_10004074;
          local_1c = (undefined2)param_2;
          local_20 = uVar3;
          if (((*(int *)(param_1 + 8) - 8U < uVar3) || (0x80 < uVar3)) ||
             ((iVar7 == -1 && (iVar7 = FUN_10003e10(param_1,iVar4,0x94), iVar7 == -1)))) {
            iVar6 = 7;
          }
          else {
            iVar6 = FUN_10003af4(param_1,iVar4,&local_2d);
            if (iVar6 == 0) {
              local_24 = FUN_100042c0(0,&local_20,8);
              local_24 = FUN_100042c0(local_24,iVar2,local_20);
              iVar6 = FUN_10004346(param_1,iVar7,auStack_2c,6,1,0);
              if (iVar6 == 0) {
                iVar6 = FUN_10004242(param_1,iVar7 + 4,&local_28,0x10,0);
                if (iVar6 == 0) {
                  iVar6 = FUN_10004242(param_1,iVar7 + 0x14,iVar2,local_20,0);
                  if (iVar6 == 0) {
                    iVar6 = FUN_10004346(param_1,iVar7,auStack_2c,6,2,1);
                    if (iVar6 == 0) {
                      if (local_2d != '\0') {
                        *(undefined1 *)(param_1 + 0x28) = 1;
                      }
                      if (iVar1 != 0) {
                        iVar6 = FUN_10003a48(param_1,param_2,iVar5,1);
                      }
                    }
                  }
                }
              }
            }
          }
        }
        if (*(char *)(param_1 + 0x28) != '\0') {
          FUN_10003dc8(param_1);
        }
      }
    }
    if (*(code **)(param_1 + 0x18) != (code *)0x0) {
      (**(code **)(param_1 + 0x18))(param_1);
    }
  }
  return iVar6;
}


