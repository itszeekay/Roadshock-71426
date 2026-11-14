// FUNC 0x1004a348  FUN_1004a348

undefined8 FUN_1004a348(uint param_1,uint param_2,uint param_3,uint param_4)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  int iVar16;
  
  uVar5 = -((int)param_2 >> 0x1f);
  uVar10 = param_1 * 8;
  uVar6 = param_1 >> 0x1d;
  uVar12 = param_3 >> 0x1d;
  uVar2 = (param_4 << 0xc) >> 9 | uVar12;
  uVar14 = (param_2 << 0xc) >> 9 | uVar6;
  uVar9 = (param_2 << 1) >> 0x15;
  uVar7 = (param_4 << 1) >> 0x15;
  uVar8 = param_4 >> 0x1f;
  uVar4 = param_3 * 8;
  if ((uVar7 != DAT_1004a6ac) || (uVar2 == 0 && uVar4 == 0)) {
    uVar8 = uVar8 ^ 1;
  }
  uVar13 = uVar9 - uVar7;
  uVar11 = uVar10;
  uVar15 = uVar2;
  if (uVar8 == uVar5) {
    if (0 < (int)uVar13) {
      if (uVar7 == 0) {
        uVar15 = uVar14;
        if (uVar2 != 0 || uVar4 != 0) {
          uVar13 = uVar13 - 1;
          if (uVar13 == 0) {
            uVar11 = uVar10 + uVar4;
            uVar15 = (uint)(uVar11 < uVar10) + uVar14 + uVar2;
            goto LAB_1004a526;
          }
          if (uVar9 != DAT_1004a9e8) goto LAB_1004a506;
        }
      }
      else {
        uVar15 = uVar14;
        if (uVar9 != DAT_1004a6ac) {
          uVar2 = uVar2 | 0x800000;
LAB_1004a506:
          if ((int)uVar13 < 0x39) {
            if ((int)uVar13 < 0x20) {
              uVar11 = (uint)(uVar4 << (0x20 - uVar13 & 0xff) != 0) |
                       uVar4 >> (uVar13 & 0xff) | uVar2 << (0x20 - uVar13 & 0xff);
              uVar2 = uVar2 >> (uVar13 & 0xff);
            }
            else {
              if (uVar13 == 0x20) {
                iVar16 = 0;
              }
              else {
                iVar16 = uVar2 << (0x40 - uVar13 & 0xff);
              }
              uVar11 = (uint)(uVar4 != 0 || iVar16 != 0) | uVar2 >> (uVar13 - 0x20 & 0xff);
              uVar2 = 0;
            }
          }
          else {
            uVar11 = (uint)(uVar4 != 0 || uVar2 != 0);
            uVar2 = 0;
          }
          uVar11 = uVar11 + uVar10;
          uVar15 = (uint)(uVar11 < uVar10) + uVar2 + uVar14;
LAB_1004a526:
          uVar5 = uVar8;
          if (-1 < (int)(uVar15 << 8)) goto LAB_1004a4ca;
          uVar7 = uVar9 + 1;
          if (uVar7 == DAT_1004a6ac) goto LAB_1004a7d4;
          uVar9 = uVar7;
          uVar11 = (DAT_1004a6b0 & uVar15) << 0x1f | uVar11 & 1 | uVar11 >> 1;
          uVar15 = (DAT_1004a6b0 & uVar15) >> 1;
        }
      }
LAB_1004a3a0:
      uVar10 = uVar11;
      uVar8 = uVar5;
      if ((uVar11 & 7) != 0) {
LAB_1004a3a4:
        uVar11 = uVar10;
        uVar8 = uVar5;
        if ((uVar10 & 0xf) != 4) {
          uVar11 = uVar10 + 4;
          uVar15 = uVar15 + (uVar11 < uVar10);
        }
      }
      if ((int)(uVar15 << 8) < 0) {
        uVar9 = uVar9 + 1;
        if (uVar9 == DAT_1004a6ac) {
          uVar5 = 0;
          uVar10 = 0;
        }
        else {
          uVar5 = uVar11 >> 3 | (uVar15 & DAT_1004a6b0) << 0x1d;
          uVar10 = ((uVar15 & DAT_1004a6b0) << 9) >> 0xc;
          uVar9 = uVar9 & 0x7ff;
        }
        goto LAB_1004a3e2;
      }
      goto LAB_1004a4d0;
    }
    if (uVar13 != 0) {
      if (uVar9 == 0) {
        uVar9 = uVar7;
        uVar11 = uVar4;
        if (uVar14 != 0 || uVar10 != 0) {
          uVar13 = ~uVar13;
          if (uVar13 == 0) goto LAB_1004a868;
          if (uVar7 != DAT_1004a9e8) goto LAB_1004a82c;
        }
      }
      else {
        uVar9 = uVar7;
        uVar11 = uVar4;
        if (uVar7 != DAT_1004a9e8) {
          uVar13 = -uVar13;
          uVar14 = uVar14 | 0x800000;
LAB_1004a82c:
          if ((int)uVar13 < 0x39) {
            if ((int)uVar13 < 0x20) {
              uVar10 = (uint)(uVar10 << (0x20 - uVar13 & 0xff) != 0) |
                       uVar14 << (0x20 - uVar13 & 0xff) | uVar10 >> (uVar13 & 0xff);
              uVar14 = uVar14 >> (uVar13 & 0xff);
            }
            else {
              uVar9 = uVar14 >> (uVar13 - 0x20 & 0xff);
              if (uVar13 == 0x20) {
                iVar16 = 0;
              }
              else {
                iVar16 = uVar14 << (0x40 - uVar13 & 0xff);
              }
              uVar14 = 0;
              uVar10 = (uVar10 != 0 || iVar16 != 0) | uVar9;
            }
          }
          else {
            uVar10 = (uint)(uVar10 != 0 || uVar14 != 0);
            uVar14 = 0;
          }
LAB_1004a868:
          uVar11 = uVar10 + uVar4;
          uVar15 = (uint)(uVar11 < uVar4) + uVar14 + uVar2;
          uVar9 = uVar7;
          goto LAB_1004a526;
        }
      }
      goto LAB_1004a3a0;
    }
    uVar7 = uVar9 + 1;
    if ((uVar7 & 0x7ff) < 2) {
      if (uVar9 == 0) {
        uVar11 = uVar4;
        if ((uVar14 != 0 || uVar10 != 0) &&
           (uVar11 = uVar10, uVar15 = uVar14, uVar2 != 0 || uVar4 != 0)) {
          uVar11 = uVar10 + uVar4;
          uVar15 = (uint)(uVar11 < uVar10) + uVar14 + uVar2;
          if (-1 < (int)(uVar15 * 0x100)) goto LAB_1004a4ca;
          uVar9 = uVar7;
          uVar15 = uVar15 & DAT_1004a9ec;
        }
      }
      else {
        uVar9 = DAT_1004a9e8;
        uVar11 = uVar4;
        if ((uVar14 != 0 || uVar10 != 0) &&
           (uVar11 = uVar10, uVar15 = uVar14, uVar2 != 0 || uVar4 != 0)) {
          uVar5 = uVar6 << 0x1d | param_1 & 0x1fffffff;
          uVar10 = param_2 & 0xfffff;
          if (((param_2 & 0x80000) != 0) && ((param_4 & 0x80000) == 0)) {
            uVar5 = uVar12 << 0x1d | param_3 & 0x1fffffff;
            uVar10 = param_4 & 0xfffff;
          }
          uVar11 = uVar5 << 3;
          uVar15 = uVar10 << 3 | uVar5 >> 0x1d;
          uVar5 = uVar8;
        }
      }
      goto LAB_1004a3a0;
    }
    if (uVar7 != DAT_1004a6ac) {
      uVar8 = (uint)(uVar10 + uVar4 < uVar10) + uVar14 + uVar2;
      uVar9 = uVar7;
      uVar11 = uVar8 * -0x80000000 | uVar10 + uVar4 >> 1;
      uVar15 = uVar8 >> 1;
      goto LAB_1004a3a0;
    }
LAB_1004a7d4:
    uVar10 = 0;
    uVar5 = 0;
    uVar9 = uVar7;
  }
  else {
    if ((int)uVar13 < 1) {
      if (uVar13 == 0) {
        if ((uVar9 + 1 & 0x7ff) < 2) {
          if (uVar9 == 0) {
            if (uVar14 == 0 && uVar10 == 0) {
              uVar11 = uVar4;
              uVar5 = uVar8;
              if (uVar2 == 0 && uVar4 == 0) {
LAB_1004a960:
                uVar10 = 0;
                uVar8 = 0;
                uVar5 = 0;
                goto LAB_1004a4de;
              }
            }
            else {
              uVar15 = uVar14;
              if (uVar2 != 0 || uVar4 != 0) {
                uVar11 = uVar10 + param_3 * -8;
                uVar15 = (uVar14 - uVar2) - (uint)(uVar10 < uVar11);
                if (-1 < (int)(uVar15 * 0x100)) {
                  if (uVar11 != 0 || uVar15 != 0) goto LAB_1004a4ca;
                  goto LAB_1004a960;
                }
                uVar11 = uVar4 + param_1 * -8;
                uVar15 = (uVar2 - uVar14) - (uint)(uVar4 < uVar11);
                uVar5 = uVar8;
              }
            }
          }
          else if (uVar14 == 0 && uVar10 == 0) {
            uVar9 = DAT_1004a9e8;
            uVar11 = uVar4;
            uVar5 = uVar8;
            if (uVar2 == 0 && uVar4 == 0) {
              uVar8 = 0;
              uVar10 = 0x80000;
              uVar5 = 0;
              goto LAB_1004a4de;
            }
          }
          else {
            uVar9 = DAT_1004a9e8;
            uVar15 = uVar14;
            if (uVar2 != 0 || uVar4 != 0) {
              uVar2 = uVar6 << 0x1d | param_1 & 0x1fffffff;
              uVar10 = param_2 & 0xfffff;
              if (((param_2 & 0x80000) != 0) && ((param_4 & 0x80000) == 0)) {
                uVar2 = uVar12 << 0x1d | param_3 & 0x1fffffff;
                uVar10 = param_4 & 0xfffff;
                uVar5 = uVar8;
              }
              uVar11 = uVar2 << 3;
              uVar15 = uVar2 >> 0x1d | uVar10 << 3;
            }
          }
        }
        else {
          uVar11 = uVar10 + param_3 * -8;
          uVar15 = (uVar14 - uVar2) - (uint)(uVar10 < uVar11);
          if ((int)(uVar15 * 0x100) < 0) {
            uVar11 = uVar4 + param_1 * -8;
            uVar15 = (uVar2 - uVar14) - (uint)(uVar4 < uVar11);
            uVar5 = uVar8;
          }
          else if (uVar11 == 0 && uVar15 == 0) {
            uVar8 = 0;
            uVar9 = 0;
            uVar5 = 0;
            uVar10 = 0;
            goto LAB_1004a4de;
          }
LAB_1004a464:
          if (uVar15 == 0) {
            iVar3 = FUN_10056d78(uVar11);
            iVar16 = iVar3 + 0x20;
            uVar10 = iVar3 + 0x18;
            if ((int)uVar10 < 0x20) goto LAB_1004a47c;
LAB_1004a608:
            uVar2 = uVar11 << (iVar16 - 0x28U & 0xff);
            uVar8 = 0;
          }
          else {
            iVar16 = FUN_10056d78(uVar15);
            uVar10 = iVar16 - 8;
            if (0x1f < (int)uVar10) goto LAB_1004a608;
LAB_1004a47c:
            uVar8 = uVar11 << (uVar10 & 0xff);
            uVar2 = uVar11 >> (0x20 - uVar10 & 0xff) | uVar15 << (uVar10 & 0xff);
          }
          if ((int)uVar10 < (int)uVar9) {
            uVar9 = uVar9 - uVar10;
            uVar11 = uVar8;
            uVar15 = DAT_1004a6b0 & uVar2;
          }
          else {
            uVar4 = (uVar10 - uVar9) + 1;
            if (0x1f < (int)uVar4) {
              if (uVar4 == 0x20) {
                iVar16 = 0;
              }
              else {
                iVar16 = uVar2 << (0x40 - uVar4 & 0xff);
              }
              uVar15 = 0;
              uVar11 = (uint)(uVar8 != 0 || iVar16 != 0) | uVar2 >> ((uVar10 - uVar9) - 0x1f & 0xff)
              ;
              uVar9 = 0;
              goto LAB_1004a4ca;
            }
            uVar9 = 0;
            uVar11 = (uint)(uVar8 << (0x20 - uVar4 & 0xff) != 0) |
                     uVar2 << (0x20 - uVar4 & 0xff) | uVar8 >> (uVar4 & 0xff);
            uVar15 = uVar2 >> (uVar4 & 0xff);
          }
        }
      }
      else if (uVar9 == 0) {
        uVar9 = uVar7;
        uVar11 = uVar4;
        uVar5 = uVar8;
        if (uVar14 != 0 || uVar10 != 0) {
          uVar13 = ~uVar13;
          if (uVar13 == 0) {
            uVar11 = uVar4 + param_1 * -8;
            goto LAB_1004a75e;
          }
          if (uVar7 != DAT_1004a9e8) goto LAB_1004a6ce;
        }
      }
      else {
        uVar9 = uVar7;
        uVar11 = uVar4;
        uVar5 = uVar8;
        if (uVar7 != DAT_1004a9e8) {
          uVar13 = -uVar13;
          uVar14 = uVar14 | 0x800000;
LAB_1004a6ce:
          if ((int)uVar13 < 0x39) {
            if ((int)uVar13 < 0x20) {
              uVar9 = uVar14 << (0x20 - uVar13 & 0xff);
              uVar14 = uVar14 >> (uVar13 & 0xff);
              uVar11 = uVar4 - (uVar9 | uVar10 >> (uVar13 & 0xff) |
                               (uint)(uVar10 << (0x20 - uVar13 & 0xff) != 0));
            }
            else {
              uVar9 = uVar14 >> (uVar13 - 0x20 & 0xff);
              if (uVar13 == 0x20) {
                iVar16 = 0;
              }
              else {
                iVar16 = uVar14 << (0x40 - uVar13 & 0xff);
              }
              uVar14 = 0;
              uVar11 = uVar4 - (uVar9 | (uVar10 != 0 || iVar16 != 0));
            }
          }
          else {
            bVar1 = uVar14 != 0;
            uVar14 = 0;
            uVar11 = uVar4 - (uVar10 != 0 || bVar1);
          }
LAB_1004a75e:
          uVar15 = (uVar2 - uVar14) - (uint)(uVar4 < uVar11);
          uVar9 = uVar7;
          uVar5 = uVar8;
          goto LAB_1004a45a;
        }
      }
      goto LAB_1004a3a0;
    }
    if (uVar7 == 0) {
      uVar15 = uVar14;
      if (uVar2 != 0 || uVar4 != 0) {
        uVar13 = uVar13 - 1;
        if (uVar13 == 0) {
          uVar11 = uVar10 + param_3 * -8;
          uVar15 = (uVar14 - uVar2) - (uint)(uVar10 < uVar11);
          goto LAB_1004a45a;
        }
        if (uVar9 != DAT_1004a6ac) goto LAB_1004a41a;
      }
      goto LAB_1004a3a0;
    }
    uVar15 = uVar14;
    if (uVar9 == DAT_1004a6ac) goto LAB_1004a3a0;
    uVar2 = uVar2 | 0x800000;
LAB_1004a41a:
    if ((int)uVar13 < 0x39) {
      if ((int)uVar13 < 0x20) {
        uVar11 = (uint)(uVar4 << (0x20 - uVar13 & 0xff) != 0) |
                 uVar4 >> (uVar13 & 0xff) | uVar2 << (0x20 - uVar13 & 0xff);
        uVar2 = uVar2 >> (uVar13 & 0xff);
      }
      else {
        if (uVar13 == 0x20) {
          iVar16 = 0;
        }
        else {
          iVar16 = uVar2 << (0x40 - uVar13 & 0xff);
        }
        uVar11 = (uint)(uVar4 != 0 || iVar16 != 0) | uVar2 >> (uVar13 - 0x20 & 0xff);
        uVar2 = 0;
      }
    }
    else {
      uVar11 = (uint)(uVar4 != 0 || uVar2 != 0);
      uVar2 = 0;
    }
    uVar11 = uVar10 - uVar11;
    uVar15 = (uVar14 - uVar2) - (uint)(uVar10 < uVar11);
LAB_1004a45a:
    if ((int)(uVar15 << 8) < 0) {
      uVar15 = uVar15 & 0x7fffff;
      goto LAB_1004a464;
    }
LAB_1004a4ca:
    uVar10 = uVar11;
    uVar8 = uVar5;
    if ((uVar11 & 7) != 0) goto LAB_1004a3a4;
LAB_1004a4d0:
    uVar10 = uVar15 >> 3;
    uVar5 = uVar11 >> 3 | uVar15 << 0x1d;
  }
LAB_1004a4de:
  if (uVar9 == DAT_1004a6ac) {
    if (uVar5 == 0 && uVar10 == 0) {
      uVar10 = 0;
      uVar5 = 0;
    }
    else {
      uVar10 = uVar10 & 0xfffff | 0x80000;
    }
  }
  else {
    uVar10 = uVar10 & 0xfffff;
    uVar9 = uVar9 & 0x7ff;
  }
LAB_1004a3e2:
  return CONCAT44(DAT_1004a6b4 & uVar10 | (uVar9 << 0x15) >> 1 | uVar8 << 0x1f,uVar5);
}


