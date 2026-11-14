// FUNC 0x1004b9e0  FUN_1004b9e0

uint FUN_1004b9e0(code *param_1,int param_2,uint param_3,byte *param_4,uint *param_5)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  byte *pbVar4;
  uint uVar5;
  undefined4 uVar6;
  uint uVar7;
  uint uVar8;
  undefined4 *puVar9;
  char *pcVar10;
  uint *puVar11;
  uint uVar12;
  byte *local_54;
  code *local_4c;
  uint local_44;
  uint *local_40;
  char *local_3c;
  
  local_4c = param_1;
  if (param_2 == 0) {
    local_4c = DAT_1004bccc;
  }
  puVar11 = (uint *)0;
LAB_1004b9f8:
  do {
    while( true ) {
      bVar1 = *param_4;
      if (bVar1 == 0) {
        uVar8 = (uint)puVar11;
        if (param_3 <= puVar11) {
          uVar8 = param_3 - 1;
        }
        (*local_4c)(0,param_2,uVar8,param_3);
        return (uint)puVar11;
      }
      if (bVar1 == 0x25) break;
      (*local_4c)(bVar1,param_2,puVar11,param_3);
LAB_1004ba9c:
      puVar11 = (uint *)((int)puVar11 + 1);
LAB_1004ba9e:
      param_4 = param_4 + 1;
    }
    param_4 = param_4 + 2;
    uVar8 = 0;
LAB_1004ba18:
    pbVar4 = param_4 + -1;
    uVar2 = (uint)*pbVar4;
    if (uVar2 == 0x2b) {
      uVar2 = 4;
LAB_1004ba46:
      uVar8 = uVar8 | uVar2;
LAB_1004bab0:
      param_4 = param_4 + 1;
      goto LAB_1004ba18;
    }
    if (0x2b < uVar2) {
      if (uVar2 == 0x2d) {
        uVar2 = 2;
        goto LAB_1004ba46;
      }
      if (uVar2 != 0x30) goto LAB_1004bab4;
      uVar8 = uVar8 | 1;
      goto LAB_1004bab0;
    }
    if (uVar2 == 0x20) {
      uVar8 = uVar8 | 8;
      goto LAB_1004bab0;
    }
    if (uVar2 == 0x23) {
      uVar2 = 0x10;
      goto LAB_1004ba46;
    }
LAB_1004bab4:
    local_40 = param_5;
    if (uVar2 - 0x30 < 10) {
      local_44 = 0;
      for (; *pbVar4 - 0x30 < 10; pbVar4 = pbVar4 + 1) {
        local_44 = (uint)*pbVar4 + local_44 * 10 + -0x30;
      }
    }
    else {
      local_44 = 0;
      if (uVar2 == 0x2a) {
        local_44 = *param_5;
        pbVar4 = param_4;
        local_40 = param_5 + 1;
        if ((int)local_44 < 0) {
          uVar8 = uVar8 | 2;
          local_44 = -local_44;
        }
      }
    }
    if (*pbVar4 == 0x2e) {
      uVar8 = uVar8 | 0x400;
      local_54 = pbVar4 + 1;
      uVar2 = 0;
      if (pbVar4[1] - 0x30 < 10) {
        for (; *local_54 - 0x30 < 10; local_54 = local_54 + 1) {
          uVar2 = (uint)*local_54 + uVar2 * 10 + -0x30;
        }
      }
      else if (pbVar4[1] == 0x2a) {
        uVar2 = *local_40;
        local_40 = local_40 + 1;
        uVar2 = uVar2 & (int)~uVar2 >> 0x1f;
        local_54 = pbVar4 + 2;
      }
    }
    else {
      uVar2 = 0;
      local_54 = pbVar4;
    }
    bVar1 = *local_54;
    if (bVar1 == 0x6c) {
      if (local_54[1] != 0x6c) {
LAB_1004bb50:
        uVar5 = 0x100;
        goto LAB_1004bb54;
      }
      uVar5 = 0x300;
LAB_1004bb48:
      local_54 = local_54 + 2;
LAB_1004bb5a:
      uVar8 = uVar8 | uVar5;
    }
    else {
      if (bVar1 < 0x6d) {
        if (bVar1 == 0x68) {
          if (local_54[1] == 0x68) {
            uVar5 = 0xc0;
            goto LAB_1004bb48;
          }
          uVar5 = 0x80;
        }
        else {
          if (bVar1 != 0x6a) goto LAB_1004ba6e;
          uVar5 = 0x200;
        }
LAB_1004bb54:
        local_54 = local_54 + 1;
        goto LAB_1004bb5a;
      }
      if ((bVar1 == 0x74) || (bVar1 == 0x7a)) goto LAB_1004bb50;
    }
LAB_1004ba6e:
    bVar1 = *local_54;
    if (bVar1 == 0x65) goto LAB_1004bd62;
    param_4 = local_54;
    if (bVar1 < 0x66) {
      if (bVar1 != 0x47) {
        if (0x47 < bVar1) {
          if (bVar1 == 0x62) {
            uVar6 = 2;
            goto LAB_1004bbee;
          }
          if (bVar1 < 99) {
            if (bVar1 == 0x58) {
              uVar6 = 0x10;
              uVar8 = uVar8 | 0x20;
              goto LAB_1004bbee;
            }
LAB_1004ba8e:
            (*local_4c)(bVar1,param_2,puVar11,param_3);
            param_5 = local_40;
            goto LAB_1004ba9c;
          }
          if (bVar1 != 99) {
            if (bVar1 == 100) goto LAB_1004bbe0;
            goto LAB_1004ba8e;
          }
          uVar8 = uVar8 & 2;
          local_3c = (char *)0x1;
          uVar2 = uVar8;
          uVar5 = (uint)puVar11;
          if (uVar8 == 0) {
            while( true ) {
              local_3c = (char *)(uVar2 + 2);
              uVar5 = (int)puVar11 + uVar2;
              uVar2 = uVar2 + 1;
              if (local_44 <= uVar2) break;
              (*local_4c)(0x20,param_2,uVar5,param_3);
            }
          }
          param_5 = local_40 + 1;
          (*local_4c)(*local_40 & 0xff,param_2,uVar5,param_3);
          puVar11 = (uint *)(uVar5 + 1);
          if (uVar8 != 0) {
            for (; (int)puVar11 + (((int)local_3c + -1) - uVar5) < local_44;
                puVar11 = (uint *)((int)puVar11 + 1)) {
              (*local_4c)(0x20,param_2,puVar11,param_3);
            }
          }
          goto LAB_1004ba9e;
        }
        if (bVar1 != 0x45) {
          if (0x45 < bVar1) goto LAB_1004bd32;
          goto LAB_1004ba8e;
        }
      }
LAB_1004bd62:
      if ((bVar1 & 0xdf) == 0x47) {
        uVar8 = uVar8 | 0x800;
        bVar1 = bVar1 & 0xfd;
      }
      if (bVar1 == 0x45) {
        uVar8 = uVar8 | 0x20;
      }
      puVar9 = (undefined4 *)((int)local_40 + 7U & 0xfffffff8);
      param_5 = puVar9 + 2;
      puVar11 = (uint *)FUN_1004b638(local_4c,param_2,puVar11,param_3,*puVar9,puVar9[1],uVar2,
                                     local_44,uVar8);
    }
    else {
      if (bVar1 == 0x6f) {
        uVar6 = 8;
        goto LAB_1004bbee;
      }
      if (bVar1 < 0x70) {
        if (bVar1 == 0x67) goto LAB_1004bd62;
        if (0x66 < bVar1) {
          if (bVar1 == 0x69) goto LAB_1004bbe0;
          goto LAB_1004ba8e;
        }
LAB_1004bd32:
        if (bVar1 == 0x46) {
          uVar8 = uVar8 | 0x20;
        }
        puVar9 = (undefined4 *)((int)local_40 + 7U & 0xfffffff8);
        param_5 = puVar9 + 2;
        puVar11 = (uint *)FUN_1004b338(local_4c,param_2,puVar11,param_3,*puVar9,puVar9[1],uVar2,
                                       local_44,uVar8);
      }
      else {
        if (bVar1 == 0x73) {
          param_5 = local_40 + 1;
          local_3c = (char *)*local_40;
          if (local_3c == (char *)0x0) {
            local_3c = DAT_1004bf24;
          }
          uVar5 = uVar2;
          if (uVar2 == 0) {
            uVar5 = 0xffffffff;
          }
          for (pcVar10 = local_3c; (*pcVar10 != '\0' && (pcVar10 != local_3c + uVar5));
              pcVar10 = pcVar10 + 1) {
          }
          uVar5 = (int)pcVar10 - (int)local_3c;
          if (((uVar8 & 0x400) != 0) && (uVar2 < uVar5)) {
            uVar5 = uVar2;
          }
          uVar7 = uVar5;
          local_40 = puVar11;
          uVar12 = (uint)puVar11;
          uVar3 = uVar5;
          if ((uVar8 & 2) == 0) {
            while( true ) {
              uVar3 = uVar7 + 1;
              local_40 = (uint *)(((int)puVar11 - uVar5) + uVar7);
              uVar12 = (uint)local_40;
              if (local_44 <= uVar7) break;
              (*local_4c)(0x20,param_2,local_40,param_3);
              uVar7 = uVar3;
            }
          }
          while ((local_3c[(int)local_40 - uVar12] != '\0' &&
                 ((uVar5 = uVar2, (uVar8 & 0x400) == 0 || (uVar5 = uVar2 - 1, uVar2 != 0))))) {
            (*local_4c)(local_3c[(int)local_40 - uVar12],param_2,local_40,param_3);
            uVar2 = uVar5;
            local_40 = (uint *)((int)local_40 + 1);
          }
          puVar11 = local_40;
          if ((uVar8 & 2) != 0) {
            for (; (int)puVar11 + (uVar3 - (int)local_40) < local_44;
                puVar11 = (uint *)((int)puVar11 + 1)) {
              (*local_4c)(0x20,param_2,puVar11,param_3);
            }
          }
          local_40 = puVar11;
          param_4 = local_54 + 1;
          puVar11 = local_40;
          goto LAB_1004b9f8;
        }
        if (bVar1 < 0x74) {
          if (bVar1 != 0x70) goto LAB_1004ba8e;
          param_5 = local_40 + 1;
          puVar11 = (uint *)FUN_1004b184(local_4c,param_2,puVar11,param_3,*local_40,0,0x10,uVar2,8,
                                         uVar8 | 0x21);
          param_4 = local_54 + 1;
          goto LAB_1004b9f8;
        }
        if (bVar1 == 0x75) {
LAB_1004bbe0:
          uVar6 = 10;
          uVar8 = uVar8 & 0xffffffef;
          if ((bVar1 != 0x69) && (bVar1 != 100)) goto LAB_1004bbee;
        }
        else {
          uVar6 = 0x10;
          if (bVar1 != 0x78) goto LAB_1004ba8e;
LAB_1004bbee:
          uVar8 = uVar8 & 0xfffffff3;
        }
        if ((int)(uVar8 << 0x15) < 0) {
          uVar8 = uVar8 & 0xfffffffe;
        }
        if ((bVar1 == 0x69) || (bVar1 == 100)) {
          if ((uVar8 & 0x200) != 0) {
            param_5 = (uint *)((int)local_40 + 7U & 0xfffffff8);
            uVar7 = param_5[1];
            uVar8 = uVar7 >> 0x1f;
            uVar5 = (int)uVar7 >> 0x1f;
            uVar2 = (uVar5 ^ *param_5) - uVar5;
            uVar5 = ((uVar5 ^ uVar7) - uVar5) - (uint)((uVar5 ^ *param_5) < uVar5);
LAB_1004bcbc:
            param_5 = param_5 + 2;
            puVar11 = (uint *)FUN_1004b218(local_4c,param_2,puVar11,param_3,uVar2,uVar5,uVar8);
            goto LAB_1004bd2c;
          }
          if (-1 < (int)(uVar8 << 0x17)) {
            if ((int)(uVar8 << 0x19) < 0) {
              uVar5 = *local_40 & 0xff;
            }
            else {
              uVar5 = *local_40;
              if ((int)(uVar8 << 0x18) < 0) {
                uVar5 = (uint)(short)uVar5;
              }
            }
            uVar7 = uVar5 >> 0x1f;
            uVar5 = uVar5 + ((int)uVar5 >> 0x1f) ^ (int)uVar5 >> 0x1f;
LAB_1004bd1c:
            param_5 = local_40 + 1;
            puVar11 = (uint *)FUN_1004b184(local_4c,param_2,puVar11,param_3,uVar5,uVar7,uVar6,uVar2,
                                           local_44,uVar8);
            goto LAB_1004bd2c;
          }
          uVar7 = *local_40;
          uVar5 = uVar7 >> 0x1f;
          uVar7 = uVar7 + ((int)uVar7 >> 0x1f) ^ (int)uVar7 >> 0x1f;
        }
        else {
          if ((uVar8 & 0x200) != 0) {
            param_5 = (uint *)((int)local_40 + 7U & 0xfffffff8);
            uVar8 = 0;
            uVar5 = param_5[1];
            uVar2 = *param_5;
            goto LAB_1004bcbc;
          }
          if (-1 < (int)(uVar8 << 0x17)) {
            if ((int)(uVar8 << 0x19) < 0) {
              uVar5 = *local_40 & 0xff;
            }
            else {
              uVar5 = *local_40;
              if ((int)(uVar8 << 0x18) < 0) {
                uVar5 = uVar5 & 0xffff;
              }
            }
            uVar7 = 0;
            goto LAB_1004bd1c;
          }
          uVar7 = *local_40;
          uVar5 = 0;
        }
        local_40 = local_40 + 1;
        puVar11 = (uint *)FUN_1004b184(local_4c,param_2,puVar11,param_3,uVar7,uVar5,uVar6,uVar2,
                                       local_44,uVar8);
        param_5 = local_40;
      }
    }
LAB_1004bd2c:
    param_4 = local_54 + 1;
  } while( true );
}


