// FUNC 0x100505b4  FUN_100505b4

void FUN_100505b4(void)

{
  undefined1 uVar1;
  undefined1 uVar2;
  char cVar3;
  char cVar4;
  undefined1 uVar5;
  undefined2 uVar6;
  short *psVar7;
  undefined1 *puVar8;
  byte *pbVar9;
  ushort *puVar10;
  int iVar11;
  int iVar12;
  char *pcVar13;
  uint uVar14;
  int iVar15;
  undefined4 uVar16;
  int iVar17;
  byte bVar18;
  short sVar19;
  undefined1 uVar20;
  byte bVar21;
  int unaff_r4;
  int iVar22;
  int unaff_r7;
  byte *in_stack_00000010;
  byte *in_stack_0000001c;
  
  if (in_stack_0000001c == in_stack_00000010) {
    FUN_1005129e();
  }
  log_printf(DAT_10050870,DAT_1005086c,*in_stack_00000010);
  iVar12 = DAT_10050f74;
  iVar11 = DAT_10050f68;
  iVar17 = DAT_10050c00;
  iVar15 = DAT_10050bf8;
  iVar22 = DAT_10050874;
  uVar14 = (uint)*in_stack_00000010;
  if (uVar14 != 7) {
    if (uVar14 < 8) {
      if (uVar14 == 3) {
        uVar16 = 3;
        iVar15 = DAT_10050874;
        goto LAB_100507a8;
      }
      if (3 < uVar14) {
        if (uVar14 != 5) {
          if (5 < uVar14) {
            if (*(char *)(DAT_10050874 + 0x48) != '\0') {
              FUN_10051294();
            }
            iVar15 = DAT_10050c00;
            if (*(char *)(DAT_10050c00 + 0x11) != '\x02') {
              if (*(char *)(DAT_10050c00 + 0x11) == '\0') {
                FUN_1004ffe0(6,1);
              }
              goto LAB_10050a60;
            }
            iVar17 = FUN_100501fc(6);
            cVar4 = *(char *)(iVar15 + 0x18);
            if (iVar17 == 0) {
              bVar18 = cVar4 + 1;
              if (3 < bVar18) {
LAB_10050a30:
                bVar18 = 0;
              }
LAB_10050a3a:
              *(byte *)(iVar15 + 0x18) = bVar18;
              FUN_10050160(5,*(undefined1 *)(iVar15 + 0x18));
            }
            else if (cVar4 != '\x01') {
              bVar18 = cVar4 + 1;
              if (3 < bVar18) goto LAB_10050a30;
              if (bVar18 == 1) {
                bVar18 = 2;
              }
              goto LAB_10050a3a;
            }
            FUN_10053930(0x2a);
            FUN_10053918(0x2a,DAT_10050bc8);
LAB_10050a60:
            *(undefined1 *)(iVar22 + 0x48) = 1;
            FUN_100507a0(DAT_10050c08);
            return;
          }
          if (*(char *)(DAT_10050874 + 0x30) != '\0') {
            FUN_10051294();
          }
          iVar22 = DAT_10050850;
          cVar4 = *(char *)(DAT_10050850 + 0x11);
          if (cVar4 != '\x02') {
            if (cVar4 == '\0') {
              FUN_1004ffe0(4,1);
            }
            else if (cVar4 == '\x03') {
              FUN_10053930(0x2e);
              pbVar9 = DAT_10050bf0;
              if (*DAT_10050bcc == '\0') {
                *DAT_10050bd0 = 0xf;
                *DAT_10050bd4 = 0xf;
                *DAT_10050bd8 = 1;
                *DAT_10050bdc = 1;
                FUN_10053918(0x2f,0x21);
                puVar10 = DAT_10050be0;
                if (*DAT_10050be0 < 0x167) {
                  *DAT_10050be0 = *DAT_10050be0 + 1;
                }
                else {
                  *DAT_10050be0 = 1;
                }
                puVar8 = DAT_10050be8;
                FUN_1004fec0(DAT_10050be8,DAT_10050be8 + 1,DAT_10050be8 + 2,*puVar10);
                uVar20 = 0;
                puVar8[4] = 0xff;
                puVar8[3] = 0;
                uVar1 = puVar8[2];
                uVar2 = puVar8[1];
                uVar5 = *puVar8;
              }
              else {
                if (*DAT_10050bf0 == 7) {
                  bVar18 = 0;
                }
                else {
                  bVar18 = *DAT_10050bf0 + 1;
                }
                *DAT_10050bf0 = bVar18;
                iVar22 = DAT_10050bf4 + (uint)*pbVar9 * 5;
                uVar20 = *(undefined1 *)(iVar22 + 3);
                uVar1 = *(undefined1 *)(iVar22 + 2);
                uVar2 = *(undefined1 *)(iVar22 + 1);
                uVar5 = *(undefined1 *)((uint)*pbVar9 * 5 + DAT_10050bf4);
              }
              FUN_10050354(uVar5,uVar2,uVar1,uVar20);
            }
            goto LAB_1005097e;
          }
          iVar15 = FUN_100501fc(4);
          cVar4 = *(char *)(iVar22 + 0x16);
          if (iVar15 == 0) {
            bVar18 = cVar4 + 1;
            if (3 < bVar18) {
LAB_1005084c:
              bVar18 = 0;
            }
LAB_100508be:
            *(byte *)(iVar22 + 0x16) = bVar18;
            FUN_10050160(3,*(undefined1 *)(iVar22 + 0x16));
          }
          else if (cVar4 != '\x01') {
            bVar18 = cVar4 + 1;
            if (3 < bVar18) goto LAB_1005084c;
            if (bVar18 == 1) {
              bVar18 = 2;
            }
            goto LAB_100508be;
          }
          FUN_10053930(0x2a);
          FUN_10053918(0x2a,DAT_10050bc8);
LAB_1005097e:
          uVar16 = DAT_10050bfc;
          *(undefined1 *)(DAT_10050bf8 + 0x30) = 1;
          FUN_100507a0(uVar16);
          return;
        }
        uVar16 = 5;
        if (*(char *)(DAT_10050874 + 0x3c) != '\0') {
          uVar16 = FUN_10051294();
        }
        iVar15 = DAT_10050c00;
        if (*(char *)(DAT_10050c00 + 0x11) != '\x02') {
          if (*(char *)(DAT_10050c00 + 0x11) == '\0') {
            FUN_1004ffe0(uVar16,1);
          }
          goto LAB_100509ee;
        }
        iVar17 = FUN_100501fc();
        cVar4 = *(char *)(iVar15 + 0x17);
        if (iVar17 == 0) {
          bVar18 = cVar4 + 1;
          if (3 < bVar18) {
LAB_100509c0:
            bVar18 = 0;
          }
LAB_100509ca:
          *(byte *)(iVar15 + 0x17) = bVar18;
          FUN_10050160(4,*(undefined1 *)(iVar15 + 0x17));
        }
        else if (cVar4 != '\x01') {
          bVar18 = cVar4 + 1;
          if (3 < bVar18) goto LAB_100509c0;
          if (bVar18 == 1) {
            bVar18 = 2;
          }
          goto LAB_100509ca;
        }
        FUN_10053930(0x2a);
        FUN_10053918(0x2a,DAT_10050bc8);
LAB_100509ee:
        *(undefined1 *)(iVar22 + 0x3c) = 1;
        FUN_100507a0(DAT_10050c04);
        return;
      }
      unaff_r4 = DAT_10050874;
      if (uVar14 != 1) {
        if (uVar14 < 2) {
          FUN_10050ec4();
        }
        if (*(char *)(iVar22 + 0x18) != '\0') {
          FUN_10051294();
        }
        iVar15 = DAT_10050850;
        if (*(char *)(DAT_10050850 + 0x11) != '\x02') {
          if (*(char *)(DAT_10050850 + 0x11) == '\0') {
            FUN_1004ffe0(2,1);
          }
          goto LAB_1005079a;
        }
        iVar17 = FUN_100501fc();
        cVar4 = *(char *)(iVar15 + 0x14);
        if (iVar17 == 0) {
          bVar18 = cVar4 + 1;
          if (3 < bVar18) {
LAB_1005076a:
            bVar18 = 0;
          }
LAB_10050774:
          *(byte *)(iVar15 + 0x14) = bVar18;
          FUN_10050160(1,*(undefined1 *)(iVar15 + 0x14));
        }
        else if (cVar4 != '\x01') {
          bVar18 = cVar4 + 1;
          if (3 < bVar18) goto LAB_1005076a;
          if (bVar18 == 1) {
            bVar18 = 2;
          }
          goto LAB_10050774;
        }
        FUN_10053930(0x2a);
        FUN_10053918(0x2a,DAT_10050878);
LAB_1005079a:
        uVar16 = DAT_100508b0;
        *(undefined1 *)(iVar22 + 0x18) = 1;
        do {
          log_printf(uVar16);
          uVar16 = FUN_10051294();
          iVar15 = iVar22;
LAB_100507a8:
          cVar4 = *(char *)(iVar15 + 0x24);
          if (cVar4 != '\0') {
            uVar16 = FUN_10051294();
          }
          iVar22 = DAT_10050850;
          if (*(char *)(DAT_10050850 + 0x11) == '\x02') {
            iVar17 = FUN_100501fc();
            cVar3 = *(char *)(iVar22 + 0x15);
            if (iVar17 == 0) {
              bVar18 = cVar3 + 1;
              if (bVar18 < 4) {
LAB_100507e8:
                *(byte *)(iVar22 + 0x15) = bVar18;
              }
              else {
                *(undefined1 *)(iVar22 + 0x15) = 0;
              }
LAB_100507ea:
              FUN_10050160(2,*(undefined1 *)(iVar22 + 0x15));
            }
            else if (cVar3 != '\x01') {
              bVar18 = cVar3 + 1;
              if (bVar18 < 4) {
                if (bVar18 == 1) {
                  bVar18 = 2;
                }
                goto LAB_100507e8;
              }
              *(char *)(iVar22 + 0x15) = cVar4;
              goto LAB_100507ea;
            }
            FUN_10053930(0x2a);
            FUN_10053918(0x2a,DAT_10050878);
          }
          else if (*(char *)(DAT_10050850 + 0x11) == '\0') {
            FUN_1004ffe0(uVar16,1);
          }
          iVar22 = iVar15 + 5;
          *(undefined1 *)(iVar15 + 0x24) = 1;
          uVar16 = DAT_100508b4;
        } while( true );
      }
LAB_1005062e:
      if (*(char *)(unaff_r4 + 0xc) != '\0') {
        uVar14 = FUN_10051294();
      }
      iVar22 = DAT_10050850;
      cVar4 = *(char *)(DAT_10050850 + 0x11);
      if (cVar4 != '\x02') {
        if (cVar4 == '\0') {
          FUN_1004ffe0(uVar14,uVar14);
        }
        else if (cVar4 == '\x03') {
          FUN_10053930(0x2e);
          pbVar9 = DAT_100508a4;
          if (*DAT_10050880 == '\0') {
            *DAT_10050884 = 0xf;
            *DAT_10050888 = 0xf;
            *DAT_1005088c = 0;
            *DAT_10050890 = 1;
            FUN_10053918(0x2f,0x21);
            psVar7 = DAT_10050894;
            if (*DAT_10050894 == 0) {
              sVar19 = 0x166;
            }
            else {
              sVar19 = *DAT_10050894 + -1;
            }
            *DAT_10050894 = sVar19;
            puVar8 = DAT_100508a0;
            FUN_1004fec0(DAT_100508a0,DAT_100508a0 + 1,DAT_100508a0 + 2,*psVar7);
            uVar20 = 0;
            puVar8[4] = 0xff;
            puVar8[3] = 0;
            uVar1 = puVar8[2];
            uVar2 = puVar8[1];
            uVar5 = *puVar8;
          }
          else {
            if (*DAT_100508a4 == 0) {
              cVar4 = '\a';
            }
            else {
              cVar4 = -1;
            }
            *DAT_100508a4 = *DAT_100508a4 + cVar4;
            iVar22 = DAT_100508a8 + (uint)*pbVar9 * 5;
            uVar20 = *(undefined1 *)(iVar22 + 3);
            uVar1 = *(undefined1 *)(iVar22 + 2);
            uVar2 = *(undefined1 *)(iVar22 + 1);
            uVar5 = *(undefined1 *)((uint)*pbVar9 * 5 + DAT_100508a8);
          }
          FUN_10050354(uVar5,uVar2,uVar1,uVar20);
        }
        goto LAB_1005072e;
      }
      iVar15 = FUN_100501fc();
      cVar4 = *(char *)(iVar22 + 0x13);
      if (iVar15 == 0) {
        bVar18 = cVar4 + 1;
        if (3 < bVar18) {
LAB_10050660:
          bVar18 = 0;
        }
LAB_1005066a:
        *(byte *)(iVar22 + 0x13) = bVar18;
        FUN_10050160(0,*(undefined1 *)(iVar22 + 0x13));
      }
      else if (cVar4 != '\x01') {
        bVar18 = cVar4 + 1;
        if (3 < bVar18) goto LAB_10050660;
        if (bVar18 == 1) {
          bVar18 = 2;
        }
        goto LAB_1005066a;
      }
      FUN_10053930(0x2a);
      FUN_10053918(0x2a,DAT_10050878);
      log_printf(DAT_1005087c,*(undefined1 *)(iVar22 + 0x13));
LAB_1005072e:
      uVar16 = DAT_100508ac;
      *(undefined1 *)(DAT_10050874 + 0xc) = 1;
      FUN_100507a0(uVar16);
      return;
    }
    if (uVar14 != 0xb) {
      if (0xb < uVar14) {
        if (uVar14 == 0xd) {
          if (*(char *)(DAT_10050f74 + 0x9c) != '\0') {
            FUN_10051294();
            return;
          }
          if (unaff_r7 == 1) {
            if (*(char *)(DAT_10050f68 + 0x11) == '\x03') {
              *DAT_10050f80 = 1;
              FUN_1004eb00();
              FUN_10053930(0x2e);
              pcVar13 = DAT_10050f84;
              *(undefined1 *)(iVar11 + 0x11) = 0;
              iVar22 = DAT_10050f98;
              puVar8 = DAT_10050f88;
              if (*pcVar13 == '\0') {
                cVar4 = DAT_10050f88[4];
                if (cVar4 != '\0') {
                  uVar6 = *DAT_10050f8c;
                  *(undefined1 *)(iVar11 + 8) = *DAT_10050f88;
                  *(undefined2 *)(iVar11 + 0xe) = uVar6;
                  *(undefined1 *)(iVar11 + 9) = puVar8[1];
                  uVar5 = puVar8[2];
                  *(char *)(iVar11 + 0xc) = cVar4;
                  *(undefined1 *)(iVar11 + 10) = uVar5;
                  *(undefined1 *)(iVar11 + 0xb) = puVar8[3];
                  FUN_10050354();
                  FUN_10051564();
                  puVar8 = DAT_10050f90;
                  *DAT_10050f90 = *(undefined1 *)(iVar11 + 0xc);
                  puVar8[1] = *(undefined1 *)(iVar11 + 8);
                  puVar8[2] = *(undefined1 *)(iVar11 + 9);
                  puVar8[3] = *(undefined1 *)(iVar11 + 10);
                  FUN_1004ee58(0,9,puVar8,4);
                }
              }
              else {
                bVar18 = *DAT_10050f94;
                *(byte *)(iVar11 + 0x10) = bVar18;
                iVar15 = (uint)bVar18 * 5;
                iVar17 = iVar22 + iVar15;
                uVar5 = *(undefined1 *)(iVar17 + 1);
                uVar20 = *(undefined1 *)(iVar17 + 2);
                uVar1 = *(undefined1 *)(iVar17 + 3);
                uVar2 = *(undefined1 *)(iVar17 + 4);
                *(undefined1 *)(iVar11 + 8) = *(undefined1 *)(iVar15 + iVar22);
                *(undefined1 *)(iVar11 + 9) = uVar5;
                *(undefined1 *)(iVar11 + 10) = uVar20;
                *(undefined1 *)(iVar11 + 0xb) = uVar1;
                *(undefined1 *)(iVar11 + 0xc) = uVar2;
                FUN_10050354();
                FUN_10051564();
              }
              *DAT_10050f80 = 1;
              cVar4 = *DAT_10050f9c;
              *DAT_10050f9c = cVar4 + '\x01';
              FUN_1004fcf8(cVar4,0xff,0xc,0);
            }
            puVar8 = DAT_10050fa0;
            iVar22 = DAT_10050f68;
            if (*(char *)(DAT_10050f68 + 0x11) == '\x02') {
              *(undefined1 *)(DAT_10050f68 + 0x11) = 0;
              *puVar8 = 1;
              FUN_10051564();
              *DAT_10050fa4 = 0;
              FUN_10053930(0x2b);
              FUN_10053930(0x2a);
              FUN_1004fd78(*(undefined1 *)(iVar22 + 0x57),*(undefined1 *)(iVar22 + 0x58),
                           *(undefined1 *)(iVar22 + 0x59),*(undefined1 *)(iVar22 + 0x5a));
            }
            uVar16 = DAT_10050fa8;
            *(undefined1 *)(DAT_10050f74 + 0x9c) = 1;
            FUN_100507a0(uVar16);
            return;
          }
          FUN_10051294();
          return;
        }
        if (0xc < uVar14) {
          if (uVar14 == 0xe) {
            uVar14 = FUN_10050ea2();
          }
          if (uVar14 == 0xff) {
            FUN_100511ba();
          }
          uVar14 = FUN_10051294();
          goto LAB_1005062e;
        }
        if (*(char *)(DAT_10050f74 + 0x90) != '\0') {
          FUN_10051294();
          return;
        }
        if (*(char *)(DAT_10050f68 + 0x11) != '\x02') {
          if (*(char *)(DAT_10050f68 + 0x11) == '\0') {
            FUN_1004ffe0(0xc,1);
          }
          goto LAB_10050d60;
        }
        iVar22 = FUN_100501fc(0xc);
        cVar4 = *(char *)(iVar11 + 0x1e);
        if (iVar22 == 0) {
          bVar18 = cVar4 + 1;
          if (3 < bVar18) {
LAB_10050d30:
            bVar18 = 0;
          }
LAB_10050d3a:
          *(byte *)(iVar11 + 0x1e) = bVar18;
          FUN_10050160(0xb,*(undefined1 *)(iVar11 + 0x1e));
        }
        else if (cVar4 != '\x01') {
          bVar18 = cVar4 + 1;
          if (3 < bVar18) goto LAB_10050d30;
          if (bVar18 == 1) {
            bVar18 = 2;
          }
          goto LAB_10050d3a;
        }
        FUN_10053930(0x2a);
        FUN_10053918(0x2a,DAT_10050f6c);
LAB_10050d60:
        *(undefined1 *)(iVar12 + 0x90) = 1;
        FUN_100507a0(DAT_10050f7c);
        return;
      }
      if (uVar14 != 9) {
        if (9 < uVar14) {
          if (*(char *)(DAT_10050874 + 0x78) != '\0') {
            FUN_10051294();
            return;
          }
          if (*(char *)(DAT_10050f68 + 0x11) != '\x02') {
            if (*(char *)(DAT_10050f68 + 0x11) == '\0') {
              FUN_1004ffe0(10,1);
            }
            goto LAB_10050c7e;
          }
          iVar15 = FUN_100501fc(10);
          cVar4 = *(char *)(iVar11 + 0x1c);
          if (iVar15 == 0) {
            bVar18 = cVar4 + 1;
            if (3 < bVar18) {
LAB_10050c4e:
              bVar18 = 0;
            }
LAB_10050c58:
            *(byte *)(iVar11 + 0x1c) = bVar18;
            FUN_10050160(9,*(undefined1 *)(iVar11 + 0x1c));
          }
          else if (cVar4 != '\x01') {
            bVar18 = cVar4 + 1;
            if (3 < bVar18) goto LAB_10050c4e;
            if (bVar18 == 1) {
              bVar18 = 2;
            }
            goto LAB_10050c58;
          }
          FUN_10053930(0x2a);
          FUN_10053918(0x2a,DAT_10050f6c);
LAB_10050c7e:
          *(undefined1 *)(iVar22 + 0x78) = 1;
          FUN_100507a0(DAT_10050f70);
          return;
        }
        if (*(char *)(DAT_10050874 + 0x60) != '\0') {
          FUN_10051294();
          return;
        }
        if (*(char *)(DAT_10050c00 + 0x11) != '\x02') {
          if (*(char *)(DAT_10050c00 + 0x11) == '\0') {
            FUN_1004ffe0(8,1);
          }
          goto LAB_10050b50;
        }
        iVar15 = FUN_100501fc(8);
        cVar4 = *(char *)(iVar17 + 0x1a);
        if (iVar15 == 0) {
          bVar18 = cVar4 + 1;
          if (3 < bVar18) {
LAB_10050b20:
            bVar18 = 0;
          }
LAB_10050b2a:
          *(byte *)(iVar17 + 0x1a) = bVar18;
          FUN_10050160(7,*(undefined1 *)(iVar17 + 0x1a));
        }
        else if (cVar4 != '\x01') {
          bVar18 = cVar4 + 1;
          if (3 < bVar18) goto LAB_10050b20;
          if (bVar18 == 1) {
            bVar18 = 2;
          }
          goto LAB_10050b2a;
        }
        FUN_10053930(0x2a);
        FUN_10053918(0x2a,DAT_10050bc8);
LAB_10050b50:
        *(undefined1 *)(iVar22 + 0x60) = 1;
        FUN_100507a0(DAT_10050c10);
        return;
      }
      if (*(char *)(DAT_10050874 + 0x6c) != '\0') {
        FUN_10051294();
        return;
      }
      if (*(char *)(DAT_10050c00 + 0x11) != '\x02') {
        if (*(char *)(DAT_10050c00 + 0x11) == '\0') {
          FUN_1004ffe0(9,1);
        }
        goto LAB_10050bbc;
      }
      iVar15 = FUN_100501fc();
      cVar4 = *(char *)(iVar17 + 0x1b);
      if (iVar15 == 0) {
        bVar18 = cVar4 + 1;
        if (3 < bVar18) {
LAB_10050b8e:
          bVar18 = 0;
        }
LAB_10050b98:
        *(byte *)(iVar17 + 0x1b) = bVar18;
        FUN_10050160(8,*(undefined1 *)(iVar17 + 0x1b));
      }
      else if (cVar4 != '\x01') {
        bVar18 = cVar4 + 1;
        if (3 < bVar18) goto LAB_10050b8e;
        if (bVar18 == 1) {
          bVar18 = 2;
        }
        goto LAB_10050b98;
      }
      FUN_10053930(0x2a);
      FUN_10053918(0x2a,DAT_10050bc8);
LAB_10050bbc:
      *(undefined1 *)(iVar22 + 0x60) = 1;
      FUN_100507a0(DAT_10050c14);
      return;
    }
    if (*(char *)(DAT_10050f74 + 0x84) != '\0') {
      FUN_10051294();
      return;
    }
    if (*(char *)(DAT_10050f68 + 0x11) != '\x02') {
      if (*(char *)(DAT_10050f68 + 0x11) == '\0') {
        FUN_1004ffe0(0xb,1);
      }
      goto LAB_10050cee;
    }
    iVar22 = FUN_100501fc();
    cVar4 = *(char *)(iVar11 + 0x1d);
    if (iVar22 == 0) {
      bVar18 = cVar4 + 1;
      if (bVar18 < 4) {
LAB_10050cca:
        *(byte *)(iVar11 + 0x1d) = bVar18;
      }
      else {
        *(undefined1 *)(iVar11 + 0x1d) = 0;
      }
LAB_10050ccc:
      FUN_10050160(10,*(undefined1 *)(iVar11 + 0x1d));
    }
    else if (cVar4 != '\x01') {
      bVar18 = cVar4 + 1;
      if (bVar18 < 4) {
        if (bVar18 == 1) {
          bVar18 = 2;
        }
        goto LAB_10050cca;
      }
      *(undefined1 *)(iVar11 + 0x1d) = 0;
      goto LAB_10050ccc;
    }
    FUN_10053930(0x2a);
    FUN_10053918(0x2a,DAT_10050f6c);
LAB_10050cee:
    *(undefined1 *)(iVar12 + 0x84) = 1;
    FUN_100507a0(DAT_10050f78);
    return;
  }
  bVar18 = *(byte *)(DAT_10050bf8 + 0x54);
  uVar16 = 7;
  if (bVar18 != 0) {
    uVar16 = FUN_10051294();
  }
  iVar22 = DAT_10050c00;
  if (*(char *)(DAT_10050c00 + 0x11) != '\x02') {
    if (*(char *)(DAT_10050c00 + 0x11) == '\0') {
      FUN_1004ffe0(uVar16,1);
    }
    goto LAB_10050ae0;
  }
  iVar17 = FUN_100501fc();
  cVar4 = *(char *)(iVar22 + 0x19);
  if (iVar17 == 0) {
    if ((byte)(cVar4 + 1U) < 4) {
      *(char *)(iVar22 + 0x19) = cVar4 + '\x01';
    }
    else {
      *(undefined1 *)(iVar22 + 0x19) = 0;
    }
    uVar5 = *(undefined1 *)(iVar22 + 0x19);
LAB_10050ac0:
    FUN_10050160(6,uVar5);
  }
  else if (cVar4 != '\x01') {
    bVar21 = cVar4 + 1;
    if ((bVar21 < 4) && (bVar18 = bVar21, bVar21 == 1)) {
      *(undefined1 *)(iVar22 + 0x19) = 2;
    }
    else {
      *(byte *)(iVar22 + 0x19) = bVar18;
    }
    uVar5 = *(undefined1 *)(DAT_10050c00 + 0x19);
    goto LAB_10050ac0;
  }
  FUN_10053930(0x2a);
  FUN_10053918(0x2a,DAT_10050bc8);
LAB_10050ae0:
  *(undefined1 *)(iVar15 + 0x54) = 1;
  FUN_100507a0(DAT_10050c0c);
  return;
}


