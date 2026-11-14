// FUNC 0x10052388  FUN_10052388

undefined4 FUN_10052388(undefined4 param_1,uint param_2,char *param_3)

{
  undefined4 uVar1;
  int iVar2;
  int *piVar3;
  code *pcVar4;
  undefined1 local_24 [2];
  undefined2 local_22;
  undefined2 local_20;
  char local_1e;
  
  piVar3 = DAT_1005264c;
  iVar2 = *DAT_1005264c;
  if (iVar2 == 0) {
    return 1;
  }
  if (param_2 != DAT_10052650) {
    if (param_2 <= DAT_10052650) {
      if (param_2 == DAT_10052654) {
        pcVar4 = *(code **)(iVar2 + 0x9c);
        if (pcVar4 == (code *)0x0) {
          return 1;
        }
        goto LAB_1005255a;
      }
      if (DAT_10052654 < param_2) {
        if (param_2 == DAT_10052668) {
          if (*(code **)(iVar2 + 0x84) != (code *)0x0) {
            uVar1 = (**(code **)(iVar2 + 0x84))
                              (param_1,*(undefined2 *)param_3,*(undefined2 *)(param_3 + 2),
                               *(undefined2 *)(param_3 + 4));
            return uVar1;
          }
          return 0;
        }
        if (param_2 <= DAT_10052668) {
          if (param_2 != DAT_1005266c) {
            if (param_2 != DAT_10052670) {
              return 0;
            }
            if (*(code **)(iVar2 + 0x80) == (code *)0x0) {
              return 1;
            }
            uVar1 = (**(code **)(iVar2 + 0x80))
                              (param_1,*(undefined2 *)param_3,*(undefined2 *)(param_3 + 2),
                               *(undefined2 *)(param_3 + 4),*(undefined2 *)(param_3 + 6));
            return uVar1;
          }
          if ((*(code **)(iVar2 + 0x8c) != (code *)0x0) && (*param_3 == '\0')) {
            (**(code **)(iVar2 + 0x8c))(param_1,*(undefined2 *)(param_3 + 2),param_3 + 4);
          }
LAB_10052516:
          if (*(code **)(*piVar3 + 0xb8) == (code *)0x0) {
            return 1;
          }
          uVar1 = (**(code **)(*piVar3 + 0xb8))(param_1,*(undefined2 *)param_3,param_3 + 2);
          return uVar1;
        }
        if (param_2 != DAT_10052674) {
          if (param_2 == DAT_10052678) goto LAB_10052516;
          if (param_2 != DAT_1005267c) {
            return 0;
          }
          piVar3 = (int *)(iVar2 + 0xac);
          goto LAB_100524ea;
        }
        piVar3 = (int *)(iVar2 + 0xb0);
      }
      else {
        if (param_2 != DAT_10052658) {
          if (DAT_10052658 < param_2) {
            piVar3 = (int *)(iVar2 + 0x98);
            if (param_2 == DAT_10052664) {
              pcVar4 = (code *)*piVar3;
              if (pcVar4 == (code *)0x0) {
                return 0;
              }
              FUN_10056f28(local_24,0,10);
              uVar1 = 8;
              local_24[0] = 4;
              goto LAB_10052602;
            }
            if (param_2 <= DAT_10052664) {
              pcVar4 = (code *)*piVar3;
              if (pcVar4 == (code *)0x0) {
                return 0;
              }
              FUN_10056f28(local_24,0,10);
              local_24[0] = 3;
              local_1e = param_3[4];
              local_20 = *(undefined2 *)(param_3 + 2);
              goto LAB_10052626;
            }
            pcVar4 = (code *)*piVar3;
            if (pcVar4 == (code *)0x0) {
              return 0;
            }
            FUN_10056f28(local_24,0,10);
            local_24[0] = 7;
            goto LAB_100526dc;
          }
          if (param_2 != DAT_1005265c) {
            if (param_2 != DAT_10052660) {
              return 0;
            }
            if (*(code **)(iVar2 + 0x7c) != (code *)0x0) {
              uVar1 = (**(code **)(iVar2 + 0x7c))(param_1,*(undefined2 *)param_3,param_3[2]);
              return uVar1;
            }
            return 0;
          }
          piVar3 = (int *)(iVar2 + 0x90);
LAB_100524ea:
          pcVar4 = (code *)*piVar3;
          if (pcVar4 == (code *)0x0) {
            return 1;
          }
          goto LAB_1005259e;
        }
        piVar3 = (int *)(iVar2 + 0x94);
      }
      pcVar4 = (code *)*piVar3;
      if (pcVar4 == (code *)0x0) {
        return 0;
      }
LAB_1005259e:
      uVar1 = (*pcVar4)(param_1,param_3);
      return uVar1;
    }
    if (param_2 == 0xe30) {
      pcVar4 = *(code **)(iVar2 + 0x98);
      if (pcVar4 == (code *)0x0) {
        return 0;
      }
      FUN_10056f28(local_24,0,10);
      local_24[0] = 0x18;
      local_22._1_1_ = param_3[1];
    }
    else {
      if (param_2 < 0xe31) {
        if (param_2 == DAT_10052680) {
          pcVar4 = *(code **)(iVar2 + 0x98);
          if (pcVar4 == (code *)0x0) {
            return 0;
          }
          FUN_10056f28(local_24,0,10);
          uVar1 = 5;
          local_24[0] = 8;
LAB_10052602:
          FUN_10056de8(&local_22,param_3,uVar1);
          goto LAB_100526e0;
        }
        if (DAT_10052680 < param_2) {
          if (param_2 == DAT_1005268c) {
            if (*(code **)(iVar2 + 0xb4) != (code *)0x0) {
              (**(code **)(iVar2 + 0xb4))
                        (param_1,*(undefined2 *)param_3,*(undefined2 *)(param_3 + 2),
                         *(undefined2 *)(param_3 + 4),*(undefined2 *)(param_3 + 6));
              return 0;
            }
            return 0;
          }
          if (param_2 == DAT_10052690) {
            pcVar4 = *(code **)(iVar2 + 200);
            if (pcVar4 == (code *)0x0) {
              return 0;
            }
            goto LAB_1005255a;
          }
          if (param_2 != DAT_10052694) {
            return 0;
          }
          pcVar4 = *(code **)(iVar2 + 0x98);
          if (pcVar4 == (code *)0x0) {
            return 0;
          }
          FUN_10056f28(local_24,0,10);
          local_24[0] = 0x12;
LAB_10052626:
          local_22 = *(undefined2 *)param_3;
          goto LAB_100526e0;
        }
        if (param_2 != DAT_10052684) {
          if (param_2 != DAT_10052688) {
            return 0;
          }
          if (*(code **)(iVar2 + 0xc4) != (code *)0x0) {
            uVar1 = (**(code **)(iVar2 + 0xc4))
                              (param_1,*(undefined4 *)param_3,*(undefined4 *)(param_3 + 4));
            return uVar1;
          }
          return 0;
        }
        piVar3 = (int *)(iVar2 + 0xc0);
        goto LAB_10052532;
      }
      if (param_2 == DAT_10052698) {
        if (*(code **)(iVar2 + 0xd0) != (code *)0x0) {
          uVar1 = (**(code **)(iVar2 + 0xd0))
                            (param_1,*param_3,*(undefined2 *)(param_3 + 2),param_3 + 4);
          return uVar1;
        }
        return 0;
      }
      if (DAT_10052698 < param_2) {
        if (param_2 == DAT_100526a4) {
          piVar3 = (int *)(iVar2 + 0xd4);
        }
        else {
          if (param_2 < DAT_100526a4) {
            pcVar4 = *(code **)(iVar2 + 0x88);
            if (pcVar4 == (code *)0x0) {
              return 0;
            }
            goto LAB_1005258e;
          }
          piVar3 = (int *)(iVar2 + 0xd8);
          if (param_2 != DAT_100526a8) {
            return 0;
          }
        }
        pcVar4 = (code *)*piVar3;
        if (pcVar4 == (code *)0x0) {
          return 0;
        }
LAB_1005258e:
        uVar1 = (*pcVar4)(param_1);
        return uVar1;
      }
      if (param_2 != DAT_1005269c) {
        if (param_2 != DAT_100526a0) {
          return 0;
        }
        pcVar4 = *(code **)(iVar2 + 0xcc);
        if (pcVar4 == (code *)0x0) {
          return 0;
        }
        goto LAB_1005259e;
      }
      pcVar4 = *(code **)(iVar2 + 0x98);
      if (pcVar4 == (code *)0x0) {
        return 0;
      }
      FUN_10056f28(local_24,0,10);
      local_24[0] = 0x19;
    }
LAB_100526dc:
    local_22 = CONCAT11(local_22._1_1_,*param_3);
LAB_100526e0:
    uVar1 = (*pcVar4)(param_1,local_24);
    return uVar1;
  }
  piVar3 = (int *)(iVar2 + 0xbc);
LAB_10052532:
  pcVar4 = (code *)*piVar3;
  if (pcVar4 == (code *)0x0) {
    return 0;
  }
LAB_1005255a:
  uVar1 = (*pcVar4)(param_1,*param_3);
  return uVar1;
}


