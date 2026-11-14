/*
 * ASR5601S bootloader - reconstructed from the SWD dump.
 * Image base 0x10000000, Ghidra 11.3.1, language ARM:LE:32:Cortex.
 * 150 functions, address order.
 *
 * Decompiler output, not original source. Types are approximate.
 * The per-function files and the Ghidra project are kept outside the
 * public repository; this file and the index are the tracked output.
 */

// FUNC 0x10000120  flash_begin

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Re-enables the flash controller after a direct access */

void flash_begin(void)

{
  if ((*_DAT_10000130 & 2) == 0) {
    *_DAT_10000130 = 2;
  }
  return;
}

// FUNC 0x10000134  flash_end

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Releases the flash controller and clears its state */

void flash_end(void)

{
  int *piVar1;
  
  piVar1 = _DAT_10000148;
  if (*_DAT_10000148 << 0x1e < 0) {
    *_DAT_10000148 = 3;
    *piVar1 = 0;
  }
  return;
}

// FUNC 0x1000014c  flash_status

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Returns the flash busy/ready flag */

uint flash_status(void)

{
  return ~(*_DAT_10000158 >> 1) & 1;
}

// FUNC 0x1000015c  flash_exit_powerdown

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Leaves flash deep power-down */

void flash_exit_powerdown(void)

{
  uint *puVar1;
  uint uVar2;
  
  puVar1 = _DAT_10000174;
  uVar2 = *_DAT_10000174;
  if ((uVar2 & 2) == 0) {
    *_DAT_10000174 = 2;
    *puVar1 = 3;
    *puVar1 = uVar2 & 2;
  }
  return;
}

// FUNC 0x10000178  delay_loop

/* Short calibrated busy loop */

void delay_loop(char param_1)

{
  do {
    param_1 = param_1 + -1;
  } while (param_1 != -1);
  return;
}

// FUNC 0x10000186  flash_wait_ready

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Waits for the flash controller bit 0x20 */

uint flash_wait_ready(void)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = *(uint *)(_DAT_100001a8 + 8);
  iVar1 = _DAT_100001ac;
  do {
    if ((uVar2 & 0x20) == 0) {
      return uVar2 & 0x20;
    }
    iVar1 = iVar1 + -1;
    uVar2 = *(uint *)(_DAT_100001a8 + 8);
  } while (iVar1 != 0);
  return 1;
}

// FUNC 0x100001b0  flash_wait_ready_long

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Waits for the flash controller bit 0x40 with a longer timeout */

uint flash_wait_ready_long(void)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = 0xc9;
  uVar2 = *(uint *)(_DAT_100001d0 + 8);
  do {
    if ((uVar2 & 0x40) == 0) {
      return uVar2 & 0x40;
    }
    iVar1 = iVar1 + -1;
    uVar2 = *(uint *)(_DAT_100001d0 + 8);
  } while (iVar1 != 0);
  return 1;
}

// FUNC 0x100001d4  flash_run_command

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Strobes the flash command register */

void flash_run_command(void)

{
  int iVar1;
  
  iVar1 = _DAT_100001e0;
  *(undefined4 *)(_DAT_100001e0 + 0xc) = _DAT_100001e4;
  *(undefined4 *)(iVar1 + 0xc) = 0;
  return;
}

// FUNC 0x100001e8  flash_arm_command

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Arms the flash controller for a command */

undefined4 flash_arm_command(void)

{
  uint *puVar1;
  uint uVar2;
  
  puVar1 = _DAT_100001fc;
  uVar2 = *_DAT_100001fc;
  *_DAT_100001fc = (uVar2 & 0xfffffffd) + 2;
  *puVar1 = uVar2 & 0xfffffffd;
  return 0;
}

// FUNC 0x10000200  flash_set_read_mode

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Configures the flash controller for reads */

undefined4 flash_set_read_mode(void)

{
  uint *puVar1;
  
  puVar1 = _DAT_10000234;
  _DAT_10000234[5] = _DAT_10000238;
  *puVar1 = *puVar1 | 0x400000;
  puVar1[4] = 0;
  puVar1[9] = 1;
  puVar1[10] = 0;
  puVar1[0x24] = 1;
  delay_loop(10);
  flash_wait_ready();
  flash_run_command();
  return 0;
}

// FUNC 0x1000023c  flash_set_write_mode

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Configures the flash controller for writes */

undefined4 flash_set_write_mode(void)

{
  uint *puVar1;
  
  puVar1 = _DAT_10000270;
  _DAT_10000270[5] = _DAT_10000274;
  *puVar1 = *puVar1 | 0x400000;
  puVar1[4] = 0;
  puVar1[9] = 2;
  puVar1[10] = 2;
  puVar1[0x24] = 1;
  delay_loop(10);
  flash_wait_ready();
  flash_run_command();
  return 0;
}

// FUNC 0x1000035c  flash_set_window

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Programs the flash address window and timing */

void flash_set_window(void)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  flash_arm_command();
  flash_wait_ready_long();
  iVar2 = _DAT_100003ac;
  piVar1 = _DAT_100003a8;
  iVar3 = *_DAT_100003a0;
  if (*_DAT_100003a0 == 0) {
    iVar3 = _DAT_100003a4;
  }
  *_DAT_100003a8 = iVar3;
  piVar1[1] = 0x140000;
  piVar1[3] = 0;
  piVar1[4] = 0;
  piVar1[5] = iVar2;
  piVar1[6] = 0;
  piVar1[7] = 0;
  piVar1[8] = 0;
  piVar1[9] = 0;
  piVar1[10] = 0;
  piVar1[0xb] = 0;
  piVar1[0xc] = _DAT_100003b0;
  *_DAT_100003b4 = 0x200;
  return;
}

// FUNC 0x100003b8  flash_controller_init

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Initializes the flash controller after reset */

undefined4 flash_controller_init(void)

{
  *_DAT_100003d4 = 0;
  delay_loop(0x20);
  flash_set_window();
  flash_exit_powerdown();
  return 0;
}

// FUNC 0x100003d8  flash_erase_sector

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Erases one flash sector through the controller */

longlong flash_erase_sector(uint param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 *puVar2;
  
  delay_loop(0x20);
  flash_arm_command();
  flash_wait_ready_long();
  puVar2 = _DAT_1000044c;
  iVar1 = _DAT_10000448;
  *(undefined4 *)(_DAT_10000448 + 0x14) = 0x106;
  flash_run_command();
  *puVar2 = 1;
  delay_loop(10);
  flash_wait_ready();
  flash_set_write_mode();
  *(uint *)(iVar1 + 0x14) = param_1;
  if (param_1 != 0x160) {
    *(undefined4 *)(iVar1 + 0x18) = param_2;
  }
  flash_run_command();
  *puVar2 = 1;
  delay_loop(10);
  flash_wait_ready();
  flash_run_command();
  flash_set_read_mode();
  delay_loop(10);
  flash_run_command();
  flash_set_window();
  flash_exit_powerdown();
  return (ulonglong)param_1 << 0x20;
}

// FUNC 0x10000450  flash_program_page

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Programs one flash page, handling unaligned sources */

undefined4 flash_program_page(undefined4 param_1,int param_2,undefined4 *param_3)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  uint uVar5;
  uint uVar6;
  undefined4 auStack_118 [65];
  
  rom_memset(auStack_118,0,0x100);
  uVar4 = 1;
  if ((param_2 != 0) && (param_3 != (undefined4 *)0x0)) {
    if ((param_3 + -0x4000000 < (undefined4 *)0x8000000) || (((uint)param_3 & 3) != 0)) {
      rom_memcpy(auStack_118,param_3,param_2);
      param_3 = auStack_118;
    }
    uVar6 = param_2 + 3U & 0xfffffffc;
    delay_loop(0x20);
    flash_arm_command();
    flash_wait_ready_long();
    iVar2 = _DAT_1000053c;
    *(undefined4 *)(_DAT_1000053c + 0x14) = 0x106;
    flash_run_command();
    puVar3 = _DAT_10000540;
    *_DAT_10000540 = 1;
    delay_loop(10);
    flash_wait_ready();
    flash_set_write_mode();
    uVar5 = uVar6 - 0x20;
    *(undefined4 *)(iVar2 + 0x14) = _DAT_10000544;
    *(int *)(iVar2 + 0x10) = param_2 + -1;
    *(undefined4 *)(iVar2 + 0x18) = param_1;
    while ((uVar6 != 0 && (uVar5 != uVar6))) {
      if ((*(int *)(iVar2 + 8) >> 8 & 0x38U) == 0) {
        uVar4 = *param_3;
        param_3 = param_3 + 1;
        uVar6 = uVar6 - 4;
        *(undefined4 *)(iVar2 + 0x20) = uVar4;
      }
    }
    delay_loop(10);
    flash_wait_ready();
    *puVar3 = 1;
    delay_loop(10);
    uVar5 = uVar6;
    while (uVar5 != 0) {
      if ((*(int *)(iVar2 + 8) >> 8 & 0x38U) == 0) {
        iVar1 = uVar6 - uVar5;
        uVar5 = uVar5 - 4;
        *(undefined4 *)(iVar2 + 0x20) = *(undefined4 *)((int)param_3 + iVar1);
      }
    }
    delay_loop(10);
    flash_wait_ready();
    flash_set_read_mode();
    flash_set_window();
    flash_exit_powerdown();
    uVar4 = 0;
  }
  return uVar4;
}

// FUNC 0x10000720  rom_memcpy

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Veneer into the ROM copy routine */

void rom_memcpy(undefined4 param_1)

{
                    /* WARNING: Could not recover jumptable at 0x10000728. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*_DAT_1000072c)(param_1);
  return;
}

// FUNC 0x10000730  rom_memset

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Veneer into the ROM fill routine */

void rom_memset(undefined4 param_1)

{
                    /* WARNING: Could not recover jumptable at 0x10000738. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*_DAT_1000073c)(param_1);
  return;
}

// FUNC 0x10000740  strcmp

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Word-optimized string compare with a byte tail */

int strcmp(uint *param_1,uint *param_2)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  if ((((uint)param_1 | (uint)param_2) & 3) == 0) {
    do {
      uVar2 = *param_1;
      param_1 = param_1 + 1;
      uVar3 = *param_2;
      param_2 = param_2 + 1;
      uVar4 = uVar2 - _DAT_100007c4 & ~uVar2 & _DAT_100007c4 << 7;
      if (uVar4 != 0) {
        iVar1 = (uVar2 & 0xff) - (uVar3 & 0xff);
        if ((((uVar4 & 0xff) == 0 && iVar1 == 0) &&
            (iVar1 = (uVar2 & 0xffff) - (uVar3 & 0xffff), (uVar4 & 0xffff) == 0 && iVar1 == 0)) &&
           (iVar1 = (uVar2 & 0xffffff) - (uVar3 & 0xffffff), (uVar4 & 0xffffff) == 0 && iVar1 == 0))
        {
          iVar1 = (uVar2 >> 0x18) - (uVar3 >> 0x18);
        }
        return iVar1;
      }
    } while (uVar2 == uVar3);
    if ((uVar3 << 0x18 | (uVar3 >> 8 & 0xff) << 0x10 | (uVar3 >> 0x10 & 0xff) << 8 | uVar3 >> 0x18)
        < (uVar2 << 0x18 | (uVar2 >> 8 & 0xff) << 0x10 | (uVar2 >> 0x10 & 0xff) << 8 | uVar2 >> 0x18
          )) {
      return 1;
    }
    return -1;
  }
  while( true ) {
    uVar2 = (uint)(byte)*param_1;
    uVar3 = (uint)(byte)*param_2;
    if ((uVar2 == 0) || (uVar2 != uVar3)) break;
    uVar2 = (uint)*(byte *)((int)param_1 + 1);
    uVar3 = (uint)*(byte *)((int)param_2 + 1);
    param_1 = (uint *)((int)param_1 + 2);
    param_2 = (uint *)((int)param_2 + 2);
    if ((uVar2 == 0) || (uVar2 != uVar3)) break;
  }
  return uVar2 - uVar3;
}

// FUNC 0x100007c8  FUN_100007c8

void FUN_100007c8(void)

{
  return;
}

// FUNC 0x100007dc  FUN_100007dc

undefined8 FUN_100007dc(undefined4 param_1,undefined4 param_2)

{
  return CONCAT44(param_2,param_1);
}

// FUNC 0x100007f0  FUN_100007f0

undefined8 FUN_100007f0(undefined4 param_1,undefined4 param_2)

{
  return CONCAT44(param_2,param_1);
}

// FUNC 0x10000804  aeabi_uidivmod

/* Unsigned 32-bit divide and remainder */

undefined8 aeabi_uidivmod(uint param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  undefined4 uVar4;
  int iVar5;
  bool bVar6;
  bool bVar7;
  bool bVar8;
  bool bVar9;
  bool bVar10;
  
  iVar5 = 0;
  if (param_2 <= param_1 >> 1) {
    if (param_2 <= param_1 >> 4) {
      if (param_2 <= param_1 >> 8) {
        if (param_1 >> 0xc < param_2) goto LAB_10000870;
        if (param_2 <= param_1 >> 0x10) {
          iVar5 = -0x1000000;
          uVar1 = param_2 << 8;
          if (param_2 << 8 <= param_1 >> 0x10) {
            iVar5 = -0x10000;
            uVar1 = param_2 << 0x10;
            if (param_2 << 0x10 == 0) {
              uVar4 = aeabi_idiv0(0);
              return CONCAT44(param_1,uVar4);
            }
          }
          param_2 = uVar1;
          if (param_1 >> 0xc < param_2) goto LAB_10000870;
        }
        while( true ) {
          bVar6 = param_2 <= param_1 >> 0xf;
          uVar1 = param_1;
          if (bVar6) {
            uVar1 = param_1 + param_2 * -0x8000;
          }
          bVar10 = param_2 * 0x8000 <= param_1;
          bVar7 = param_2 <= uVar1 >> 0xe;
          uVar2 = uVar1;
          if (bVar7) {
            uVar2 = uVar1 + param_2 * -0x4000;
          }
          bVar8 = param_2 <= uVar2 >> 0xd;
          uVar3 = uVar2;
          if (bVar8) {
            uVar3 = uVar2 + param_2 * -0x2000;
          }
          bVar9 = param_2 <= uVar3 >> 0xc;
          param_1 = uVar3;
          if (bVar9) {
            param_1 = uVar3 + param_2 * -0x1000;
          }
          iVar5 = (((iVar5 * 2 + (uint)(bVar6 && bVar10)) * 2 +
                   (uint)(bVar7 && param_2 * 0x4000 <= uVar1)) * 2 +
                  (uint)(bVar8 && param_2 * 0x2000 <= uVar2)) * 2 +
                  (uint)(bVar9 && param_2 * 0x1000 <= uVar3);
LAB_10000870:
          bVar6 = param_2 <= param_1 >> 0xb;
          uVar1 = param_1;
          if (bVar6) {
            uVar1 = param_1 + param_2 * -0x800;
          }
          bVar10 = param_2 <= uVar1 >> 10;
          uVar2 = uVar1;
          if (bVar10) {
            uVar2 = uVar1 + param_2 * -0x400;
          }
          bVar7 = param_2 <= uVar2 >> 9;
          uVar3 = uVar2;
          if (bVar7) {
            uVar3 = uVar2 + param_2 * -0x200;
          }
          uVar1 = ((iVar5 * 2 + (uint)(bVar6 && param_2 * 0x800 <= param_1)) * 2 +
                  (uint)(bVar10 && param_2 * 0x400 <= uVar1)) * 2 +
                  (uint)(bVar7 && param_2 * 0x200 <= uVar2);
          bVar6 = param_2 <= uVar3 >> 8;
          param_1 = uVar3;
          if (bVar6) {
            param_1 = uVar3 + param_2 * -0x100;
          }
          bVar6 = bVar6 && param_2 * 0x100 <= uVar3;
          iVar5 = uVar1 * 2 + (uint)bVar6;
          if (!CARRY4(uVar1,uVar1) && !CARRY4(uVar1 * 2,(uint)bVar6)) break;
          param_2 = param_2 >> 8;
        }
      }
      bVar6 = param_2 <= param_1 >> 7;
      uVar1 = param_1;
      if (bVar6) {
        uVar1 = param_1 + param_2 * -0x80;
      }
      bVar10 = param_2 * 0x80 <= param_1;
      bVar7 = param_2 <= uVar1 >> 6;
      uVar2 = uVar1;
      if (bVar7) {
        uVar2 = uVar1 + param_2 * -0x40;
      }
      bVar8 = param_2 <= uVar2 >> 5;
      uVar3 = uVar2;
      if (bVar8) {
        uVar3 = uVar2 + param_2 * -0x20;
      }
      bVar9 = param_2 <= uVar3 >> 4;
      param_1 = uVar3;
      if (bVar9) {
        param_1 = uVar3 + param_2 * -0x10;
      }
      iVar5 = (((iVar5 * 2 + (uint)(bVar6 && bVar10)) * 2 + (uint)(bVar7 && param_2 * 0x40 <= uVar1)
               ) * 2 + (uint)(bVar8 && param_2 * 0x20 <= uVar2)) * 2 +
              (uint)(bVar9 && param_2 * 0x10 <= uVar3);
    }
    bVar6 = param_2 <= param_1 >> 3;
    uVar1 = param_1;
    if (bVar6) {
      uVar1 = param_1 + param_2 * -8;
    }
    bVar10 = param_2 * 8 <= param_1;
    bVar7 = param_2 <= uVar1 >> 2;
    uVar2 = uVar1;
    if (bVar7) {
      uVar2 = uVar1 + param_2 * -4;
    }
    bVar8 = param_2 <= uVar2 >> 1;
    param_1 = uVar2;
    if (bVar8) {
      param_1 = uVar2 + param_2 * -2;
    }
    iVar5 = ((iVar5 * 2 + (uint)(bVar6 && bVar10)) * 2 + (uint)(bVar7 && param_2 * 4 <= uVar1)) * 2
            + (uint)(bVar8 && param_2 * 2 <= uVar2);
  }
  uVar1 = param_1 - param_2;
  if (param_2 > param_1) {
    uVar1 = param_1;
  }
  return CONCAT44(uVar1,iVar5 * 2 + (uint)(param_2 <= param_1));
}

// FUNC 0x10000910  aeabi_uidiv

/* Unsigned 32-bit divide */

undefined8 aeabi_uidiv(uint param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  undefined4 uVar4;
  int iVar5;
  bool bVar6;
  bool bVar7;
  bool bVar8;
  bool bVar9;
  bool bVar10;
  
  if (param_2 != 0) {
    iVar5 = 0;
    if (param_2 <= param_1 >> 1) {
      if (param_2 <= param_1 >> 4) {
        if (param_2 <= param_1 >> 8) {
          if (param_1 >> 0xc < param_2) goto LAB_10000870;
          if (param_2 <= param_1 >> 0x10) {
            iVar5 = -0x1000000;
            uVar1 = param_2 << 8;
            if (param_2 << 8 <= param_1 >> 0x10) {
              iVar5 = -0x10000;
              uVar1 = param_2 << 0x10;
              if (param_2 << 0x10 == 0) goto LAB_10000904;
            }
            param_2 = uVar1;
            if (param_1 >> 0xc < param_2) goto LAB_10000870;
          }
          while( true ) {
            bVar6 = param_2 <= param_1 >> 0xf;
            uVar1 = param_1;
            if (bVar6) {
              uVar1 = param_1 + param_2 * -0x8000;
            }
            bVar10 = param_2 * 0x8000 <= param_1;
            bVar7 = param_2 <= uVar1 >> 0xe;
            uVar2 = uVar1;
            if (bVar7) {
              uVar2 = uVar1 + param_2 * -0x4000;
            }
            bVar8 = param_2 <= uVar2 >> 0xd;
            uVar3 = uVar2;
            if (bVar8) {
              uVar3 = uVar2 + param_2 * -0x2000;
            }
            bVar9 = param_2 <= uVar3 >> 0xc;
            param_1 = uVar3;
            if (bVar9) {
              param_1 = uVar3 + param_2 * -0x1000;
            }
            iVar5 = (((iVar5 * 2 + (uint)(bVar6 && bVar10)) * 2 +
                     (uint)(bVar7 && param_2 * 0x4000 <= uVar1)) * 2 +
                    (uint)(bVar8 && param_2 * 0x2000 <= uVar2)) * 2 +
                    (uint)(bVar9 && param_2 * 0x1000 <= uVar3);
LAB_10000870:
            bVar6 = param_2 <= param_1 >> 0xb;
            uVar1 = param_1;
            if (bVar6) {
              uVar1 = param_1 + param_2 * -0x800;
            }
            bVar10 = param_2 <= uVar1 >> 10;
            uVar2 = uVar1;
            if (bVar10) {
              uVar2 = uVar1 + param_2 * -0x400;
            }
            bVar7 = param_2 <= uVar2 >> 9;
            uVar3 = uVar2;
            if (bVar7) {
              uVar3 = uVar2 + param_2 * -0x200;
            }
            uVar1 = ((iVar5 * 2 + (uint)(bVar6 && param_2 * 0x800 <= param_1)) * 2 +
                    (uint)(bVar10 && param_2 * 0x400 <= uVar1)) * 2 +
                    (uint)(bVar7 && param_2 * 0x200 <= uVar2);
            bVar6 = param_2 <= uVar3 >> 8;
            param_1 = uVar3;
            if (bVar6) {
              param_1 = uVar3 + param_2 * -0x100;
            }
            bVar6 = bVar6 && param_2 * 0x100 <= uVar3;
            iVar5 = uVar1 * 2 + (uint)bVar6;
            if (!CARRY4(uVar1,uVar1) && !CARRY4(uVar1 * 2,(uint)bVar6)) break;
            param_2 = param_2 >> 8;
          }
        }
        bVar6 = param_2 <= param_1 >> 7;
        uVar1 = param_1;
        if (bVar6) {
          uVar1 = param_1 + param_2 * -0x80;
        }
        bVar10 = param_2 * 0x80 <= param_1;
        bVar7 = param_2 <= uVar1 >> 6;
        uVar2 = uVar1;
        if (bVar7) {
          uVar2 = uVar1 + param_2 * -0x40;
        }
        bVar8 = param_2 <= uVar2 >> 5;
        uVar3 = uVar2;
        if (bVar8) {
          uVar3 = uVar2 + param_2 * -0x20;
        }
        bVar9 = param_2 <= uVar3 >> 4;
        param_1 = uVar3;
        if (bVar9) {
          param_1 = uVar3 + param_2 * -0x10;
        }
        iVar5 = (((iVar5 * 2 + (uint)(bVar6 && bVar10)) * 2 +
                 (uint)(bVar7 && param_2 * 0x40 <= uVar1)) * 2 +
                (uint)(bVar8 && param_2 * 0x20 <= uVar2)) * 2 +
                (uint)(bVar9 && param_2 * 0x10 <= uVar3);
      }
      bVar6 = param_2 <= param_1 >> 3;
      uVar1 = param_1;
      if (bVar6) {
        uVar1 = param_1 + param_2 * -8;
      }
      bVar10 = param_2 * 8 <= param_1;
      bVar7 = param_2 <= uVar1 >> 2;
      uVar2 = uVar1;
      if (bVar7) {
        uVar2 = uVar1 + param_2 * -4;
      }
      bVar8 = param_2 <= uVar2 >> 1;
      param_1 = uVar2;
      if (bVar8) {
        param_1 = uVar2 + param_2 * -2;
      }
      iVar5 = ((iVar5 * 2 + (uint)(bVar6 && bVar10)) * 2 + (uint)(bVar7 && param_2 * 4 <= uVar1)) *
              2 + (uint)(bVar8 && param_2 * 2 <= uVar2);
    }
    uVar1 = param_1 - param_2;
    if (param_2 > param_1) {
      uVar1 = param_1;
    }
    return CONCAT44(uVar1,iVar5 * 2 + (uint)(param_2 <= param_1));
  }
LAB_10000904:
  uVar4 = aeabi_idiv0(0);
  return CONCAT44(param_1,uVar4);
}

// FUNC 0x10000918  aeabi_idiv0

/* Divide-by-zero helper, returns zero */

void aeabi_idiv0(void)

{
  return;
}

// FUNC 0x1000091c  aeabi_llsl

/* 64-bit shift left */

undefined8 aeabi_llsl(uint param_1,int param_2,uint param_3)

{
  return CONCAT44(param_2 << (param_3 & 0xff) | param_1 << (param_3 - 0x20 & 0xff) |
                  param_1 >> (-(param_3 - 0x20) & 0xff),param_1 << (param_3 & 0xff));
}

// FUNC 0x10000934  aeabi_uldivmod

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Unsigned 64-bit divide and remainder */

undefined8 aeabi_uldivmod(int param_1,int param_2,int param_3,int param_4)

{
  undefined8 uVar1;
  
  if ((param_4 == 0) && (param_3 == 0)) {
    if (param_2 != 0 || param_1 != 0) {
      param_1 = -1;
      param_2 = param_1;
    }
    return CONCAT44(param_2,param_1);
  }
  uVar1 = udivmoddi4(param_1);
  return uVar1;
}

// FUNC 0x10000974  udivmoddi4

/* Core of the 64-bit divide */

undefined8 udivmoddi4(uint param_1,uint param_2,uint param_3,uint param_4,uint *param_5)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  bool bVar9;
  uint uStack_30;
  uint uStack_2c;
  
  if ((param_2 <= param_4 && param_4 != param_2) || ((param_4 == param_2 && (param_1 < param_3)))) {
    uStack_30 = 0;
    uStack_2c = 0;
    goto LAB_100009f8;
  }
  iVar1 = clzdi2(param_3,param_4);
  iVar2 = clzdi2(param_1,param_2);
  uVar4 = iVar1 - iVar2;
  uVar5 = uVar4 - 0x20;
  if ((int)uVar5 < 0) {
    uVar6 = param_4 << (uVar4 & 0xff) | param_3 >> (0x20 - uVar4 & 0xff);
    param_3 = param_3 << (uVar4 & 0xff);
    if (uVar6 <= param_2) goto LAB_100009c0;
LAB_10000a36:
    uStack_30 = 0;
    uStack_2c = 0;
  }
  else {
    uVar6 = param_3 << (uVar5 & 0xff);
    param_3 = param_3 << (uVar4 & 0xff);
    if (param_2 < uVar6) goto LAB_10000a36;
LAB_100009c0:
    if ((uVar6 == param_2) && (param_1 < param_3)) goto LAB_10000a36;
    bVar9 = param_1 < param_3;
    param_1 = param_1 - param_3;
    param_2 = (param_2 - uVar6) - (uint)bVar9;
    if ((int)uVar5 < 0) {
      uStack_2c = 1 >> (0x20 - uVar4 & 0xff);
    }
    else {
      uStack_2c = 1 << (uVar5 & 0xff);
    }
    uStack_30 = 1 << (uVar4 & 0xff);
  }
  if (uVar4 == 0) goto LAB_100009f8;
  uVar3 = param_3 >> 1 | uVar6 << 0x1f;
  uVar6 = uVar6 >> 1;
  uVar8 = uVar4;
  do {
    while ((uVar6 <= param_2 && ((uVar6 != param_2 || (uVar3 <= param_1))))) {
      bVar9 = param_1 < uVar3;
      uVar7 = param_1 - uVar3;
      uVar8 = uVar8 - 1;
      param_1 = uVar7 * 2 + 1;
      param_2 = ((param_2 - uVar6) - (uint)bVar9) * 2 + (uint)CARRY4(uVar7,uVar7) +
                (uint)(0xfffffffe < uVar7 * 2);
      if (uVar8 == 0) goto LAB_10000a7c;
    }
    uVar8 = uVar8 - 1;
    bVar9 = CARRY4(param_1,param_1);
    param_1 = param_1 * 2;
    param_2 = param_2 * 2 + (uint)bVar9;
  } while (uVar8 != 0);
LAB_10000a7c:
  bVar9 = CARRY4(uStack_30,param_1);
  uVar6 = uStack_30 + param_1;
  iVar1 = uStack_2c + param_2;
  if ((int)uVar5 < 0) {
    param_1 = param_1 >> (uVar4 & 0xff) | param_2 << (0x20 - uVar4 & 0xff);
    param_2 = param_2 >> (uVar4 & 0xff);
    if (-1 < (int)uVar5) goto LAB_10000aa0;
LAB_10000af6:
    uVar5 = param_2 << (uVar4 & 0xff) | param_1 >> (0x20 - uVar4 & 0xff);
  }
  else {
    param_1 = param_2 >> (uVar5 & 0xff);
    param_2 = param_2 >> (uVar4 & 0xff);
    if ((int)uVar5 < 0) goto LAB_10000af6;
LAB_10000aa0:
    uVar5 = param_1 << (uVar5 & 0xff);
  }
  uVar4 = param_1 << (uVar4 & 0xff);
  uStack_30 = uVar6 - uVar4;
  uStack_2c = ((iVar1 + (uint)bVar9) - uVar5) - (uint)(uVar6 < uVar4);
LAB_100009f8:
  if (param_5 != (uint *)0x0) {
    *param_5 = param_1;
    param_5[1] = param_2;
  }
  return CONCAT44(uStack_2c,uStack_30);
}

// FUNC 0x10000b0c  clzdi2

/* Count leading zeros in a 64-bit value */

int clzdi2(undefined4 param_1,int param_2)

{
  int iVar1;
  
  if (param_2 == 0) {
    iVar1 = clzsi2();
    iVar1 = iVar1 + 0x20;
  }
  else {
    iVar1 = clzsi2(param_2);
  }
  return iVar1;
}

// FUNC 0x10000b24  clzsi2

/* Count leading zeros in a 32-bit value */

int clzsi2(uint param_1)

{
  int iVar1;
  
  iVar1 = 0x1c;
  if (0xffff < param_1) {
    param_1 = param_1 >> 0x10;
    iVar1 = 0xc;
  }
  if (0xff < param_1) {
    param_1 = param_1 >> 8;
    iVar1 = iVar1 + -8;
  }
  if (0xf < param_1) {
    param_1 = param_1 >> 4;
    iVar1 = iVar1 + -4;
  }
  return (uint)*(byte *)(param_1 + 0x10000b50) + iVar1;
}

// FUNC 0x10000b60  hardfault_handler

void hardfault_handler(void)

{
  boot_printf(uRam10000b6c);
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}

// FUNC 0x10000b70  boot_jump_to_app

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Sets VTOR and calls the app reset vector */

void boot_jump_to_app(undefined4 param_1)

{
  *(undefined4 *)(_DAT_10000b84 + 0x7c) = 0xffffffff;
  *(undefined4 *)(_DAT_10000b88 + 8) = param_1;
  call_app_reset_vector();
  return;
}

// FUNC 0x10000b8c  bootloader_boot_app

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Reads OTA info from the KV store, applies it if valid, then hands control to the app */

void bootloader_boot_app(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  
  uVar1 = _DAT_10000bb8;
  iVar3 = kv_read(3,_DAT_10000bb8,0x6c);
  uVar2 = _DAT_10000bbc;
  if (iVar3 == 0) {
    ota_image_verify(uVar1,_DAT_10000bbc);
  }
  boot_printf(_DAT_10000bc0);
  boot_app_select(uVar2);
  return;
}

// FUNC 0x10000bc4  bootloader_main

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Prints the banner and boot reason, reads the boot info, then boots or updates the app */

void bootloader_main(void)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  
  boot_clock_init();
  uart_init(_DAT_10000c44,0x1c200);
  uart_pinmux_select();
  puVar1 = _DAT_10000c48;
  memset(_DAT_10000c48,0,0x1c);
  iVar2 = kv_store_init(0);
  if (iVar2 == 0) {
    kv_read(2,puVar1,0x1c);
  }
  image_header_build(*puVar1,puVar1[2],puVar1[3]);
  boot_printf(_DAT_10000c50,_DAT_10000c4c);
  iVar2 = boot_reason_get();
  uVar3 = _DAT_10000c54;
  if ((((iVar2 != 2) && (uVar3 = _DAT_10000c5c, iVar2 != 3)) && (uVar3 = _DAT_10000c60, iVar2 != 1))
     && (uVar3 = _DAT_10000c68, iVar2 == 0)) {
    uVar3 = _DAT_10000c64;
  }
  boot_printf(uVar3);
  boot_printf(_DAT_10000c58);
  bootloader_boot_app();
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}

// FUNC 0x10000c6c  heap_alloc

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Bump allocator over the heap area */

uint heap_alloc(int param_1)

{
  uint uVar1;
  
  uVar1 = *_DAT_10000c84;
  if (_DAT_10000c88 < uVar1 + param_1) {
    uVar1 = 0xffffffff;
  }
  else {
    *_DAT_10000c84 = uVar1 + param_1;
  }
  return uVar1;
}

// FUNC 0x10000c8c  boot_delay_us

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Calibrated busy-wait delay */

void boot_delay_us(int param_1)

{
  int iVar1;
  uint uVar2;
  undefined4 uStack_c;
  
  iVar1 = aeabi_uidivmod(*_DAT_10000cdc,_DAT_10000ce0);
  uVar2 = aeabi_uidivmod(iVar1 * param_1,0x11);
  if (uVar2 < 0xc) {
    uVar2 = 0xc;
  }
  for (uStack_c = uVar2 - 0xc; uStack_c != 0; uStack_c = uStack_c + -1) {
  }
  return;
}

// FUNC 0x10000ce4  call_app_reset_vector

/* Calls the word at app_base + 4 */

void call_app_reset_vector(int param_1)

{
                    /* WARNING: Could not recover jumptable at 0x10000cea. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(param_1 + 4))();
  return;
}

// FUNC 0x10000cf0  format_padded

/* Formats a number with padding and prefixes into the output buffer */

int format_padded(code *param_1,undefined4 param_2,int param_3,undefined4 param_4,int param_5,
                 uint param_6,char param_7,int param_8,uint param_9,uint param_10,uint param_11)

{
  uint uVar1;
  undefined1 uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  
  if ((param_11 & 2) == 0) {
    if (((param_10 != 0) && ((param_11 & 1) != 0)) && ((param_7 != '\0' || ((param_11 & 0xc) != 0)))
       ) {
      param_10 = param_10 - 1;
    }
    for (; (param_6 < param_9 && (param_6 != 0x20)); param_6 = param_6 + 1) {
      *(undefined1 *)(param_5 + param_6) = 0x30;
    }
    for (; (((param_11 & 1) != 0 && (param_6 < param_10)) && (param_6 != 0x20));
        param_6 = param_6 + 1) {
      *(undefined1 *)(param_5 + param_6) = 0x30;
    }
  }
  if ((int)(param_11 << 0x1b) < 0) {
    uVar1 = param_6;
    if (((((int)(param_11 << 0x15) < 0) || (param_6 == 0)) ||
        ((param_6 != param_9 && (param_6 != param_10)))) || (uVar1 = param_6 - 1, param_6 == 1)) {
      uVar4 = uVar1;
      if (param_8 == 0x10) goto LAB_10000d86;
      if (param_8 == 2) {
        if (0x1f < uVar1) goto LAB_10000d90;
        goto LAB_10000dd8;
      }
    }
    else {
      uVar4 = param_6 - 2;
      if (param_8 == 0x10) {
LAB_10000d86:
        if ((int)(param_11 << 0x1a) < 0) {
          uVar2 = 0x58;
        }
        else {
          uVar2 = 0x78;
        }
        uVar1 = uVar4;
        if (0x1f < uVar4) goto LAB_10000d90;
      }
      else {
        if (param_8 != 2) goto LAB_10000de8;
LAB_10000dd8:
        uVar2 = 0x62;
        uVar4 = uVar1;
      }
      *(undefined1 *)(param_5 + uVar4) = uVar2;
      uVar1 = uVar4 + 1;
    }
LAB_10000de8:
    if (0x1f < uVar1) goto LAB_10000d90;
    *(undefined1 *)(param_5 + uVar1) = 0x30;
    param_6 = uVar1 + 1;
  }
  uVar1 = param_6;
  if (param_6 != 0x20) {
    uVar2 = 0x2d;
    if (param_7 == '\0') {
      if ((int)(param_11 << 0x1d) < 0) {
        uVar2 = 0x2b;
      }
      else {
        if (-1 < (int)(param_11 << 0x1c)) goto LAB_10000d90;
        uVar2 = 0x20;
      }
    }
    *(undefined1 *)(param_5 + param_6) = uVar2;
    uVar1 = param_6 + 1;
  }
LAB_10000d90:
  uVar4 = uVar1;
  uVar6 = uVar1;
  iVar3 = param_3;
  if ((param_11 & 3) == 0) {
    for (; uVar4 < param_10; uVar4 = uVar4 + 1) {
      (*param_1)(0x20,param_2,(param_3 - uVar1) + uVar4,param_4);
    }
    iVar3 = 0;
    if (uVar1 <= param_10) {
      iVar3 = param_10 - uVar1;
    }
    iVar3 = iVar3 + param_3;
  }
  while( true ) {
    iVar5 = uVar1 + iVar3;
    if (uVar6 == 0) break;
    (*param_1)(*(undefined1 *)(param_5 + (uVar6 - 1)),param_2,iVar5 - uVar6,param_4);
    uVar6 = uVar6 - 1;
  }
  if ((param_11 & 2) != 0) {
    for (uVar1 = iVar5 - param_3; uVar1 < param_10; uVar1 = uVar1 + 1) {
      (*param_1)(0x20,param_2,uVar1 + param_3,param_4);
    }
    iVar3 = 0;
    if ((uint)(iVar5 - param_3) <= param_10) {
      iVar3 = (param_10 + param_3) - iVar5;
    }
    iVar5 = iVar5 + iVar3;
  }
  return iVar5;
}

// FUNC 0x10000e5a  utoa

/* Unsigned int to string for the boot printf */

void utoa(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,uint param_5,
         undefined1 param_6,uint param_7,undefined4 param_8,undefined4 param_9,uint param_10)

{
  char cVar1;
  char cVar2;
  char cVar3;
  uint uVar4;
  ulonglong uVar5;
  char acStack_38 [36];
  
  if (param_5 == 0) {
    param_10 = param_10 & 0xffffffef;
  }
  if ((-1 < (int)(param_10 << 0x15)) || (param_5 != 0)) {
    cVar3 = 'a';
    if ((int)(param_10 << 0x1a) < 0) {
      cVar3 = 'A';
    }
    uVar4 = param_5;
    param_5 = 0;
    do {
      uVar5 = aeabi_uidiv(uVar4,param_7);
      cVar2 = (char)(uVar5 >> 0x20);
      cVar1 = cVar2 + cVar3 + -10;
      if (uVar5 < 0xa00000000) {
        cVar1 = cVar2 + '0';
      }
      acStack_38[param_5] = cVar1;
      param_5 = param_5 + 1;
    } while ((param_7 <= uVar4) && (uVar4 = (uint)uVar5, param_5 != 0x20));
  }
  format_padded(param_1,param_2,param_3,param_4,acStack_38,param_5,param_6,param_7,param_8,param_9,
                param_10);
  return;
}

// FUNC 0x10000eee  ulltoa

/* WARNING: Removing unreachable block (ram,0x10000f74) */
/* Unsigned long long to string for the boot printf */

void ulltoa(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,int param_5,
           int param_6,undefined1 param_7,undefined4 param_8,uint param_9,undefined4 param_10,
           undefined4 param_11,undefined4 param_12,uint param_13)

{
  ulonglong uVar1;
  uint uVar2;
  char cVar3;
  char cVar4;
  int iVar5;
  ulonglong uVar6;
  int iStack_5c;
  char acStack_38 [36];
  
  if (param_5 == 0 && param_6 == 0) {
    param_13 = param_13 & 0xffffffef;
  }
  if ((-1 < (int)(param_13 << 0x15)) || (iVar5 = 0, param_5 != 0 || param_6 != 0)) {
    cVar3 = 'a';
    if ((int)(param_13 << 0x1a) < 0) {
      cVar3 = 'A';
    }
    iStack_5c = 0;
    uVar1 = CONCAT44(param_6,param_5);
    do {
      uVar2 = param_9;
      uVar6 = aeabi_uldivmod((int)uVar1,(int)(uVar1 >> 0x20),param_9,param_10);
      cVar4 = (char)uVar2 + cVar3 + -10;
      if ((uVar2 & 0xff) < 10) {
        cVar4 = (char)uVar2 + '0';
      }
      iVar5 = iStack_5c + 1;
      acStack_38[iStack_5c] = cVar4;
    } while ((CONCAT44(param_10,param_9) <= uVar1) &&
            (iStack_5c = iVar5, uVar1 = uVar6, iVar5 != 0x20));
  }
  format_padded(param_1,param_2,param_3,param_4,acStack_38,iVar5,param_7,param_9,param_11,param_12,
                param_13);
  return;
}

// FUNC 0x10000fc0  vprintf_core

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Format engine behind boot_printf */

uint vprintf_core(code *param_1,int param_2,uint param_3,byte *param_4,uint *param_5)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  byte *pbVar4;
  uint uVar5;
  uint uVar6;
  undefined4 uVar7;
  uint uVar8;
  uint uVar9;
  uint uStack_54;
  byte *pbStack_50;
  uint uStack_4c;
  code *pcStack_48;
  
  pcStack_48 = param_1;
  if (param_2 == 0) {
    pcStack_48 = _DAT_1000128c;
  }
  uVar3 = 0;
  pbStack_50 = param_4;
LAB_10000ff2:
  do {
    while( true ) {
      bVar1 = *pbStack_50;
      if (bVar1 == 0) {
        uVar5 = uVar3;
        if (param_3 <= uVar3) {
          uVar5 = param_3 - 1;
        }
        (*pcStack_48)(0,param_2,uVar5,param_3);
        return uVar3;
      }
      pbStack_50 = pbStack_50 + 1;
      if (bVar1 == 0x25) break;
      (*pcStack_48)(bVar1,param_2,uVar3,param_3);
      uVar3 = uVar3 + 1;
    }
    uVar5 = 0;
LAB_10001026:
    while( true ) {
      uVar6 = (uint)*pbStack_50;
      pbVar4 = pbStack_50 + 1;
      if (uVar6 != 0x2b) break;
      uVar6 = 4;
LAB_1000104e:
      uVar5 = uVar5 | uVar6;
      pbStack_50 = pbVar4;
    }
    if (0x2b < uVar6) {
      if (uVar6 == 0x2d) {
        uVar6 = 2;
        goto LAB_1000104e;
      }
      if (uVar6 != 0x30) goto LAB_1000103c;
      uVar5 = uVar5 | 1;
      pbStack_50 = pbVar4;
      goto LAB_10001026;
    }
    if (uVar6 == 0x20) {
      uVar5 = uVar5 | 8;
      pbStack_50 = pbVar4;
      goto LAB_10001026;
    }
    if (uVar6 == 0x23) {
      uVar6 = 0x10;
      goto LAB_1000104e;
    }
LAB_1000103c:
    if (uVar6 - 0x30 < 10) {
      uStack_54 = 0;
      while( true ) {
        if (9 < *pbStack_50 - 0x30) break;
        uStack_54 = (uint)*pbStack_50 + uStack_54 * 10 + -0x30;
        pbStack_50 = pbStack_50 + 1;
      }
    }
    else {
      uStack_54 = 0;
      if (uVar6 == 0x2a) {
        uStack_54 = *param_5;
        param_5 = param_5 + 1;
        pbStack_50 = pbVar4;
        if ((int)uStack_54 < 0) {
          uVar5 = uVar5 | 2;
          uStack_54 = -uStack_54;
        }
      }
    }
    uStack_4c = 0;
    pbVar4 = pbStack_50;
    if (*pbStack_50 == 0x2e) {
      uVar5 = uVar5 | 0x400;
      pbVar4 = pbStack_50 + 1;
      if (pbStack_50[1] - 0x30 < 10) {
        while( true ) {
          if (9 < *pbVar4 - 0x30) break;
          uStack_4c = (uint)*pbVar4 + uStack_4c * 10 + -0x30;
          pbVar4 = pbVar4 + 1;
        }
      }
      else if (pbStack_50[1] == 0x2a) {
        uStack_4c = *param_5;
        param_5 = param_5 + 1;
        uStack_4c = uStack_4c & (int)~uStack_4c >> 0x1f;
        pbVar4 = pbStack_50 + 2;
      }
    }
    pbStack_50 = pbVar4;
    bVar1 = *pbStack_50;
    if (bVar1 == 0x6c) {
      if (pbStack_50[1] != 0x6c) {
LAB_10001134:
        uVar6 = 0x100;
        goto LAB_10001158;
      }
      uVar6 = 0x300;
LAB_10001146:
      uVar5 = uVar5 | uVar6;
      pbStack_50 = pbStack_50 + 2;
    }
    else if (bVar1 < 0x6d) {
      if (bVar1 == 0x68) {
        if (pbStack_50[1] == 0x68) {
          uVar6 = 0xc0;
          goto LAB_10001146;
        }
        uVar6 = 0x80;
      }
      else {
        if (bVar1 != 0x6a) goto LAB_100010f0;
        uVar6 = 0x200;
      }
LAB_10001158:
      uVar5 = uVar5 | uVar6;
      pbStack_50 = pbStack_50 + 1;
    }
    else if ((bVar1 == 0x74) || (bVar1 == 0x7a)) goto LAB_10001134;
LAB_100010f0:
    uVar6 = (uint)*pbStack_50;
    pbStack_50 = pbStack_50 + 1;
    if (uVar6 < 0x79) {
      if (uVar6 < 0x62) {
        if ((uVar6 != 0x25) && (uVar6 == 0x58)) {
          uVar5 = uVar5 | 0x20;
          uVar7 = 0x10;
          goto LAB_100011c0;
        }
      }
      else if (uVar6 - 0x62 < 0x17) {
        iVar2 = FUN_100007f0();
        param_5 = (uint *)(uVar3 << 5);
        uVar3 = iVar2 << 6;
        if (uVar6 == 0x78) {
          uVar7 = 0x10;
LAB_100011c0:
          uVar5 = uVar5 & 0xfffffff3;
        }
        else {
          if (uVar6 == 0x6f) {
            uVar7 = 8;
            goto LAB_100011c0;
          }
          if (uVar6 == 0x62) {
            uVar7 = 2;
            goto LAB_100011c0;
          }
          uVar5 = uVar5 & 0xffffffef;
          uVar7 = 10;
          if ((uVar6 != 0x69) && (uVar6 != 100)) goto LAB_100011c0;
        }
        if ((int)(uVar5 << 0x15) < 0) {
          uVar5 = uVar5 & 0xfffffffe;
        }
        if ((uVar6 == 0x69) || (uVar6 == 100)) {
          if ((uVar5 & 0x200) == 0) {
            if ((int)(uVar5 << 0x17) < 0) {
              uVar6 = *param_5;
            }
            else {
              uVar6 = *param_5;
              if ((int)(uVar5 << 0x19) < 0) {
                uVar6 = uVar6 & 0xff;
              }
              else if ((int)(uVar5 << 0x18) < 0) {
                uVar6 = (uint)(short)uVar6;
              }
            }
            uVar8 = uVar6 >> 0x1f;
            uVar6 = uVar6 + ((int)uVar6 >> 0x1f) ^ (int)uVar6 >> 0x1f;
            goto LAB_100012a8;
          }
          param_5 = (uint *)((int)param_5 + 7U & 0xfffffff8);
          uVar5 = param_5[1];
          uVar8 = uVar5 >> 0x1f;
          uVar9 = (int)uVar5 >> 0x1f;
          uVar6 = (uVar9 ^ *param_5) - uVar9;
          uVar5 = ((uVar9 ^ uVar5) - uVar9) - (uint)((uVar9 ^ *param_5) < uVar9);
        }
        else {
          if ((uVar5 & 0x200) == 0) {
            if ((int)(uVar5 << 0x17) < 0) {
              uVar6 = *param_5;
              uVar8 = 0;
            }
            else {
              uVar6 = *param_5;
              if ((int)(uVar5 << 0x19) < 0) {
                uVar6 = uVar6 & 0xff;
              }
              else if ((int)(uVar5 << 0x18) < 0) {
                uVar6 = uVar6 & 0xffff;
              }
              uVar8 = 0;
            }
LAB_100012a8:
            param_5 = param_5 + 1;
            uVar3 = utoa(pcStack_48,param_2,uVar3,param_3,uVar6,uVar8,uVar7,uStack_4c,uStack_54,
                         uVar5);
            goto LAB_10000ff2;
          }
          param_5 = (uint *)((int)param_5 + 7U & 0xfffffff8);
          uVar8 = 0;
          uVar6 = *param_5;
          uVar5 = param_5[1];
        }
        param_5 = param_5 + 2;
        uVar3 = ulltoa(pcStack_48,param_2,uVar3,param_3,uVar6,uVar5,uVar8);
        goto LAB_10000ff2;
      }
    }
    (*pcStack_48)(uVar6,param_2,uVar3,param_3);
    uVar3 = uVar3 + 1;
  } while( true );
}

// FUNC 0x100014a0  boot_printf

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Variadic printf over UART1 at 115200 */

void boot_printf(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  code *UNRECOVERED_JUMPTABLE;
  undefined4 uStack_20;
  undefined4 *puStack_1c;
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  puStack_1c = &uStack_c;
  uStack_20 = param_3;
  uStack_c = param_2;
  uStack_8 = param_3;
  uStack_4 = param_4;
  vprintf_core(_DAT_100014c0,&uStack_20,0xffffffff,param_1,puStack_1c,param_2);
                    /* WARNING: Could not recover jumptable at 0x100014be. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}

// FUNC 0x100014c4  reset_handler

/* Vector table reset entry: calls startup_init, then bootloader_main */

void reset_handler(void)

{
  startup_init();
  bootloader_main();
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}

// FUNC 0x100014ce  default_handler

/* Infinite loop for unused vectors */

void default_handler(void)

{
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}

// FUNC 0x100014d0  startup_init

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Calls the early image check, copies .data, zeroes .bss, calls flash_driver_init and
   bootloader_main */

void startup_init(void)

{
  int iVar1;
  undefined4 *puVar2;
  
  boot_early_image_check();
  for (iVar1 = 0; (uint)(_DAT_10001538 + iVar1) < _DAT_1000153c; iVar1 = iVar1 + 4) {
    *(undefined4 *)(_DAT_10001538 + iVar1) = *(undefined4 *)(_DAT_10001534 + iVar1);
  }
  for (iVar1 = 0; puVar2 = _DAT_1000154c, (uint)(_DAT_10001544 + iVar1) < _DAT_10001548;
      iVar1 = iVar1 + 4) {
    *(undefined4 *)(_DAT_10001544 + iVar1) = *(undefined4 *)(_DAT_10001540 + iVar1);
  }
  for (; puVar2 < _DAT_10001550; puVar2 = puVar2 + 1) {
    *puVar2 = 0;
  }
  *_DAT_10001528 = 1;
  *_DAT_1000152c = 2;
  *_DAT_10001530 = 2;
  flash_driver_init();
  return;
}

// FUNC 0x10001554  crc32

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Bitwise CRC-32 over a buffer, polynomial 0x4C11DB7 */

uint crc32(void)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  byte *pbVar4;
  char cVar5;
  
  uVar3 = 0xffffffff;
  pbVar4 = _DAT_10001588;
  do {
    bVar1 = *pbVar4;
    pbVar4 = pbVar4 + 1;
    cVar5 = '\b';
    uVar2 = uVar3 ^ (uint)bVar1 << 0x18;
    do {
      uVar3 = uVar2 << 1;
      if ((int)uVar2 < 0) {
        uVar3 = uVar3 ^ _DAT_1000158c;
      }
      cVar5 = cVar5 + -1;
      uVar2 = uVar3;
    } while (cVar5 != '\0');
  } while (pbVar4 != _DAT_10001590);
  return ~uVar3;
}

// FUNC 0x10001594  boot_clock_init

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Configures the clock and power block at 0x40160024 */

void boot_clock_init(void)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  
  piVar1 = _DAT_10001604;
  uVar2 = *_DAT_10001600 >> 0x18 & 1;
  if (*_DAT_10001604 == 1) {
    if (uVar2 == 0) {
      *_DAT_10001600 = *_DAT_10001600 | 0x1000000;
      piVar1[1] = 1;
      piVar1[2] = 1;
      return;
    }
    iVar3 = 2;
  }
  else if (*_DAT_10001604 == 2) {
    if (uVar2 == 0) {
LAB_100015da:
      *_DAT_10001600 = *_DAT_10001600 | 0x1000000;
      *piVar1 = 1;
      piVar1[1] = 0;
      piVar1[2] = 0;
      return;
    }
    iVar3 = 3;
    *_DAT_10001604 = 1;
  }
  else {
    if (uVar2 == 0) goto LAB_100015da;
    *_DAT_10001600 = *_DAT_10001600 | 0x1000000;
    iVar3 = 0xff;
    *piVar1 = 1;
  }
  piVar1[1] = iVar3;
  piVar1[2] = iVar3;
  return;
}

// FUNC 0x10001608  boot_reason_get

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Returns the boot reason word at 0x20030004 */

undefined4 boot_reason_get(void)

{
  return *(undefined4 *)(_DAT_10001610 + 4);
}

// FUNC 0x10001614  image_header_build

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Stores base, size and CRC-32 in the image header descriptor */

void image_header_build(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = _DAT_10001628;
  *(undefined4 *)(_DAT_10001628 + 0x10) = param_1;
  *(undefined4 *)(iVar1 + 0x14) = param_2;
  *(undefined4 *)(iVar1 + 0x18) = param_3;
  uVar2 = crc32();
  *(undefined4 *)(iVar1 + 0x1c) = uVar2;
  return;
}

// FUNC 0x1000162c  boot_early_image_check

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Reads the boot mode strap and a RAM image header; maps and jumps to the app when the CRC matches
    */

void boot_early_image_check(void)

{
  int iVar1;
  
  if (((((*_DAT_10001678 << 8) >> 0x1e != 0) || ((*_DAT_1000167c & 0xf) == 0)) &&
      ((*_DAT_10001678 >> 0x16 & 3) != 1)) && ((*_DAT_10001678 >> 0x16 & 3) != 2)) {
    return;
  }
  iVar1 = crc32();
  if (iVar1 == *(int *)(_uart_pins_config_alt + 0x1c)) {
    if (*(int *)(_uart_pins_config_alt + 0x10) == 1) {
      boot_map_exec_region
                (*(undefined4 *)(_uart_pins_config_alt + 0x14),
                 *(undefined4 *)(_uart_pins_config_alt + 0x18));
    }
    boot_jump_to_app(uRam10001684);
  }
  return;
}

// FUNC 0x10001680  uart_pins_config_alt

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Alternate UART pin setup; not referenced by the boot path */

void uart_pins_config_alt(void)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  uint uVar4;
  byte *pbVar5;
  byte abStack_70 [64];
  undefined1 auStack_30 [40];
  undefined4 uStack_8;
  
  uRam00000003 = 3;
  uStack_8 = 0;
  disableIRQinterrupts();
  iVar1 = reg_read_indexed(1);
  uVar3 = _DAT_10001734;
  if (iVar1 << 1 < 0) {
    uVar3 = _DAT_1000172c;
  }
  reg_write_indexed(1,uVar3);
  uVar2 = reg_read_indexed(1);
  reg_write_indexed(1,_DAT_10001730 & uVar2);
  uVar2 = reg_read_indexed(7);
  reg_write_indexed(7,uVar2 | 0x800000);
  iVar1 = 0;
  uVar2 = 0;
  while( true ) {
    auStack_30[uVar2] = (char)iVar1;
    uVar4 = uVar2 + 1;
    if (uVar4 == 0x25) break;
    iVar1 = (uVar4 & 1) << 4;
    uVar2 = uVar4;
  }
  iVar1 = 0;
  pbVar5 = abStack_70 + uVar2;
  do {
    if (iVar1 < 0x10) {
      pbVar5[0x1c] = pbVar5[0x1c] | 5;
      pbVar5[0x1d] = pbVar5[0x1d] | 5;
    }
    else {
      *pbVar5 = *pbVar5 | 10;
      pbVar5[1] = pbVar5[1] | 10;
    }
    iVar1 = iVar1 + 1;
    pbVar5 = pbVar5 + 2;
  } while (iVar1 != 0x20);
  iVar1 = 0;
  do {
    reg_write_indexed(0x14,auStack_30[iVar1]);
    iVar1 = iVar1 + 1;
    boot_delay_us(10);
  } while (iVar1 != 0x25);
  return;
}

// FUNC 0x10001688  uart_pins_config

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Builds the pin bitmap and programs the UART pin mux */

void uart_pins_config(void)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  uint uVar4;
  byte *pbVar5;
  byte abStack_70 [64];
  undefined1 auStack_30 [40];
  
  disableIRQinterrupts();
  iVar1 = reg_read_indexed(1);
  uVar3 = _DAT_10001734;
  if (iVar1 << 1 < 0) {
    uVar3 = _DAT_1000172c;
  }
  reg_write_indexed(1,uVar3);
  uVar2 = reg_read_indexed(1);
  reg_write_indexed(1,_DAT_10001730 & uVar2);
  uVar2 = reg_read_indexed(7);
  reg_write_indexed(7,uVar2 | 0x800000);
  iVar1 = 0;
  uVar2 = 0;
  while( true ) {
    auStack_30[uVar2] = (char)iVar1;
    uVar4 = uVar2 + 1;
    if (uVar4 == 0x25) break;
    iVar1 = (uVar4 & 1) << 4;
    uVar2 = uVar4;
  }
  iVar1 = 0;
  pbVar5 = abStack_70 + uVar2;
  do {
    if (iVar1 < 0x10) {
      pbVar5[0x1c] = pbVar5[0x1c] | 5;
      pbVar5[0x1d] = pbVar5[0x1d] | 5;
    }
    else {
      *pbVar5 = *pbVar5 | 10;
      pbVar5[1] = pbVar5[1] | 10;
    }
    iVar1 = iVar1 + 1;
    pbVar5 = pbVar5 + 2;
  } while (iVar1 != 0x20);
  iVar1 = 0;
  do {
    reg_write_indexed(0x14,auStack_30[iVar1]);
    iVar1 = iVar1 + 1;
    boot_delay_us(10);
  } while (iVar1 != 0x25);
  return;
}

// FUNC 0x10001738  uart_pinmux_select

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Selects the UART pin group from the boot reason and applies it */

void uart_pinmux_select(void)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  
  uVar2 = boot_reason_get();
  iVar1 = _DAT_10001784;
  if ((1 < uVar2) && (uVar2 != 0xff)) {
    return;
  }
  iVar3 = *(int *)(_DAT_10001784 + 0xc);
  if (iVar3 == _DAT_10001788) {
    uVar4 = 0;
  }
  else {
    if (iVar3 == _DAT_1000178c) goto LAB_10001766;
    if (iVar3 != _DAT_10001790) {
      if (uVar2 == 0) {
        *(int *)(_DAT_10001784 + 0xc) = _DAT_10001788;
      }
      else if (uVar2 == 1) {
        *(int *)(_DAT_10001784 + 0xc) = _DAT_1000178c;
      }
      else {
        *(int *)(_DAT_10001784 + 0xc) = _DAT_10001790;
      }
      uart_pins_config();
      return;
    }
    uVar4 = 0xff;
  }
  *(undefined4 *)(_DAT_10001784 + 4) = uVar4;
LAB_10001766:
  *(undefined4 *)(iVar1 + 0xc) = 0;
  return;
}

// FUNC 0x10001794  uart_baud_divider

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Converts a baud rate to the divisor written to the UART */

uint uart_baud_divider(uint param_1)

{
  uint uVar1;
  undefined8 uVar2;
  
  if (param_1 != 0) {
    if (*_DAT_100017c8 < param_1 << 4) {
      param_1 = 0;
    }
    else {
      uVar2 = aeabi_uidiv();
      uVar1 = aeabi_uidivmod((int)((ulonglong)uVar2 >> 0x20) << 3,param_1);
      param_1 = (uVar1 >> 1) + (uVar1 & 1) & 0xffff | (int)uVar2 << 0x10;
    }
  }
  return param_1;
}

// FUNC 0x100017cc  uart_init

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Configures the bootloader console UART at 115200 */

void uart_init(int param_1,undefined4 param_2)

{
  uint *puVar1;
  uint uVar2;
  uint uVar3;
  
  puVar1 = _DAT_1000188c;
  if (param_1 == 0x40000000) {
    uVar2 = _DAT_10001890 & *_DAT_1000188c;
    uVar3 = 0x1100;
  }
  else if (param_1 == _DAT_10001898) {
    uVar2 = _DAT_1000189c & *_DAT_1000188c;
    uVar3 = 0x110000;
  }
  else {
    if (param_1 != _DAT_100018a0) goto LAB_100017ec;
    uVar2 = *_DAT_100018a4 & 0xffffff00;
    uVar3 = 0x11;
    puVar1 = _DAT_100018a4;
  }
  *puVar1 = uVar3 | uVar2;
LAB_100017ec:
  do {
  } while ((*(uint *)(param_1 + 0x18) & 8) != 0);
  *(uint *)(param_1 + 0x30) = *(uint *)(param_1 + 0x30) & 0xfffffffe;
  *(uint *)(param_1 + 0x2c) = *(uint *)(param_1 + 0x2c) & 0xffffffef;
  uVar2 = uart_baud_divider(param_2);
  *(uint *)(param_1 + 0x24) = uVar2 >> 0x10;
  *(uint *)(param_1 + 0x28) = uVar2 & 0x3f;
  *(uint *)(param_1 + 0x2c) = *(uint *)(param_1 + 0x2c) | 0x70;
  *(uint *)(param_1 + 0x2c) = *(uint *)(param_1 + 0x2c) & 0xfffffff3;
  *(uint *)(param_1 + 0x30) = *(uint *)(param_1 + 0x30) | 0x300;
  *(uint *)(param_1 + 0x38) = *(uint *)(param_1 + 0x38) | 0x50;
  if (param_1 == 0x40000000) {
    *_DAT_10001894 = 8;
  }
  else if (param_1 == _DAT_10001898) {
    *_DAT_10001894 = 4;
  }
  else if (param_1 == _DAT_100018a0) {
    *_DAT_10001894 = 0x10;
  }
  *(uint *)(param_1 + 0x30) = *(uint *)(param_1 + 0x30) | 1;
  return;
}

// FUNC 0x100018a8  reg_write_wait

/* Waits for status bit 0x20, then writes the register */

void reg_write_wait(undefined4 *param_1,undefined4 param_2)

{
  do {
  } while ((param_1[6] & 0x20) != 0);
  *param_1 = param_2;
  return;
}

// FUNC 0x100018b4  reg_write_indexed

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Writes a 32-bit register selected by index */

void reg_write_indexed(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 * 4 + _DAT_100018c0) = param_2;
  return;
}

// FUNC 0x100018c4  reg_read_indexed

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Reads a 32-bit register selected by index */

undefined4 reg_read_indexed(int param_1)

{
  return *(undefined4 *)(param_1 * 4 + _DAT_100018d0);
}

// FUNC 0x1000193c  flash_driver_init

/* Calls the flash controller init in the RAM blob */

void flash_driver_init(void)

{
  flash_controller_init_veneer();
  return;
}

// FUNC 0x10001944  flash_region_get

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Returns the 0x14-byte region descriptor for an index */

int flash_region_get(int param_1)

{
  return param_1 * 0x14 + _DAT_10001950;
}

// FUNC 0x10001954  flash_region_find

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Finds a region index by name, 16 entries maximum */

int flash_region_find(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = 0;
  iVar3 = _DAT_1000197c;
  do {
    iVar1 = strcmp(param_1,*(undefined4 *)(iVar3 + 4));
    if (iVar1 == 0) {
      return (int)(char)iVar2;
    }
    iVar2 = iVar2 + 1;
    iVar3 = iVar3 + 0x14;
  } while (iVar2 != 0x10);
  return -1;
}

// FUNC 0x10001980  flash_region_erase

int flash_region_erase(int param_1,int param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  iVar1 = iRam100019c8 + param_1 * 0x14;
  if (*(uint *)(iVar1 + 0xc) < (uint)(param_3 + param_2)) {
    iVar1 = -1;
  }
  else {
    uVar2 = param_2 + *(int *)(iVar1 + 8);
    for (uVar3 = uVar2 & 0xfffff000; uVar3 <= (param_3 + -1 + uVar2 & 0xfffff000);
        uVar3 = uVar3 + 0x1000) {
      iVar1 = flash_erase_sector_veneer(uRam100019cc,uVar3);
      if (iVar1 != 0) {
        return iVar1;
      }
    }
    iVar1 = 0;
  }
  return iVar1;
}

// FUNC 0x100019d0  flash_region_write

undefined4 flash_region_write(int param_1,int *param_2,int param_3,int param_4)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  
  iVar1 = flash_status_veneer();
  if ((param_2 != (int *)0x0) && (param_3 != 0)) {
    iVar3 = iRam10001a68 + param_1 * 0x14;
    if ((uint)(*param_2 + param_4) <= *(uint *)(iVar3 + 0xc)) {
      uVar2 = *param_2 + *(int *)(iVar3 + 8);
      uVar4 = param_4 + uVar2;
      if (iVar1 != 0) {
        flash_end_veneer();
      }
      for (iVar3 = param_4; iVar3 != 0; iVar3 = iVar3 - iVar5) {
        iVar5 = iVar3;
        if (uVar2 >> 8 < uVar4 >> 8) {
          iVar5 = 0x100 - (uVar2 & 0xff);
        }
        flash_program_page_veneer(uVar2,iVar5,param_3);
        param_3 = param_3 + iVar5;
        uVar2 = uVar2 + iVar5;
      }
      if (iVar1 != 0) {
        flash_begin_veneer();
      }
      *param_2 = param_4 + *param_2;
      return 0;
    }
  }
  return 0xffffffff;
}

// FUNC 0x10001a6c  flash_region_read

undefined4 flash_region_read(int param_1,int *param_2,int param_3,int param_4)

{
  int iVar1;
  
  if ((param_2 != (int *)0x0) && (param_3 != 0)) {
    iVar1 = iRam10001ab8 + param_1 * 0x14;
    if (((uint)(*param_2 + param_4) <= *(uint *)(iVar1 + 0xc)) &&
       (0x7ffffff < param_3 + 0xf0000000U)) {
      iVar1 = *(int *)(iVar1 + 8);
      memcpy(param_3,*param_2 + iVar1,param_4,iVar1,param_4);
      *param_2 = *param_2 + param_4;
      return 0;
    }
  }
  return 0xffffffff;
}

// FUNC 0x10001abc  watchdog_config

void watchdog_config(void)

{
  int iVar1;
  
  iVar1 = iRam10001ad0;
  *(undefined4 *)(iRam10001ad0 + 0xc00) = uRam10001ad4;
  *(undefined4 *)(iVar1 + 0xc) = 1;
  *(undefined4 *)(iVar1 + 0xc00) = uRam10001ad8;
  return;
}

// FUNC 0x10001b54  crc16_ccitt

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* CRC-16 CCITT over a buffer, polynomial 0x1021 */

uint crc16_ccitt(byte *param_1,int param_2)

{
  byte *pbVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  
  uVar4 = 0;
  pbVar1 = param_1 + param_2;
  for (; pbVar1 != param_1; param_1 = param_1 + 1) {
    iVar2 = 8;
    uVar4 = uVar4 ^ (uint)*param_1 << 8;
    do {
      uVar3 = uVar4 << 1;
      if ((short)uVar4 < 0) {
        uVar3 = uVar3 ^ _DAT_10001b8c;
      }
      uVar4 = uVar3 & 0xffff;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
  }
  boot_printf(_DAT_10001b90,uVar4);
  return uVar4;
}

// FUNC 0x10001b94  boot_info_save

/* Writes the boot info record to the KV store and updates the header */

void boot_info_save(undefined4 *param_1)

{
  int iVar1;
  
  iVar1 = kv_write(2,param_1,0x1c);
  if (iVar1 == 0) {
    image_header_build(*param_1,param_1[2],param_1[3]);
  }
  return;
}

// FUNC 0x10001bb4  flash_erase_range

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Erases a range using the largest aligned block size */

void flash_erase_range(uint param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  bool bVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  
  uVar3 = param_1 & 0xfffff000;
  uVar5 = (param_1 + param_2) - uVar3;
  while( true ) {
    if (uVar5 == 0) {
      return;
    }
    if (((uVar3 & 0xffff) == 0) && (0xf000 < (int)uVar5)) {
      uVar4 = 0x10000;
      uVar2 = _DAT_10001c24;
    }
    else if (((uVar3 & 0x7fff) == 0) && (0x7000 < (int)uVar5)) {
      uVar4 = 0x8000;
      uVar2 = _DAT_10001c28;
    }
    else {
      uVar4 = 0x1000;
      uVar2 = _DAT_10001c20;
    }
    iVar6 = 0;
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      iVar6 = isIRQinterruptsEnabled();
    }
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      enableIRQinterrupts(1);
    }
    flash_erase_sector_veneer(uVar2,uVar3,param_3,1,param_4);
    if (iVar6 == 0) {
      bVar1 = (bool)isCurrentModePrivileged();
      if (bVar1) {
        enableIRQinterrupts(0);
      }
    }
    else {
      bVar1 = (bool)isCurrentModePrivileged();
      if (bVar1) {
        enableIRQinterrupts(1);
      }
    }
    uVar3 = uVar3 + uVar4;
    if (uVar5 <= uVar4) break;
    uVar5 = uVar5 - uVar4;
  }
  return;
}

// FUNC 0x10001c2c  ota_region_clear

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Erases the OTA staging region and clears its flag */

undefined4 ota_region_clear(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (((*(uint *)(param_1 + 4) & 0xffffff00) != _DAT_10001c68) && (*(int *)(param_1 + 0x10) == 0)) {
    boot_printf(_DAT_10001c6c,*(undefined4 *)(param_1 + 0x14),*(undefined4 *)(param_1 + 0x18));
    flash_erase_range(*(undefined4 *)(param_1 + 0x14),*(undefined4 *)(param_1 + 0x18));
    *(undefined4 *)(param_1 + 0x10) = 0xffffffff;
    boot_info_save(param_1);
    uVar1 = 1;
  }
  return uVar1;
}

// FUNC 0x10001c70  flash_program_bytes

/* Programs a byte range with interrupts disabled */

undefined4 flash_program_bytes(uint param_1,int param_2,int param_3)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  undefined4 uStack_24;
  
  iVar2 = flash_status_veneer();
  uVar3 = param_3 + param_1;
  if (iVar2 != 0) {
    flash_end_veneer();
  }
  uStack_24 = param_2;
  for (; param_3 != 0; param_3 = param_3 - iVar4) {
    iVar4 = param_3;
    if (param_1 >> 8 < uVar3 >> 8) {
      iVar4 = 0x100 - (param_1 & 0xff);
    }
    iVar5 = 0;
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      iVar5 = isIRQinterruptsEnabled();
    }
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      enableIRQinterrupts(1);
    }
    flash_program_page_veneer(param_1,iVar4,uStack_24,1);
    if (iVar5 == 0) {
      bVar1 = (bool)isCurrentModePrivileged();
      if (bVar1) {
        enableIRQinterrupts(0);
      }
    }
    else {
      bVar1 = (bool)isCurrentModePrivileged();
      if (bVar1) {
        enableIRQinterrupts(1);
      }
    }
    param_1 = param_1 + iVar4;
    uStack_24 = uStack_24 + iVar4;
  }
  if (iVar2 != 0) {
    flash_begin_veneer();
  }
  return 0;
}

// FUNC 0x10001ce6  image_copy

/* Copies the staged image into the app region */

undefined4 image_copy(undefined4 param_1,undefined4 param_2)

{
  memcpy(param_2,param_1);
  return 0;
}

// FUNC 0x10001cf8  boot_map_exec_region

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Programs the IOMUX exec window for the app base and length */

void boot_map_exec_region(uint param_1,int param_2)

{
  *_DAT_10001d1c = _DAT_10001d20;
  *_DAT_10001d24 = param_1 & 0xfffffc00;
  *_DAT_10001d30 = param_2 + _DAT_10001d28 & _DAT_10001d2c | 0x1000000;
  return;
}

// FUNC 0x10001d34  boot_rollback_update

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Increments the rollback counter, then falls back to the previous image */

void boot_rollback_update(int *param_1)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  
  uVar1 = _DAT_10001d80;
  uVar2 = param_1[1];
  if (((uVar2 & 0xffffff00) == _DAT_10001d7c) && ((uVar2 & 0xff) != 0)) {
    if ((uVar2 & 0xff) < 3) {
      param_1[1] = uVar2 + 1;
      boot_printf(_DAT_10001d84);
    }
    else {
      iVar3 = *param_1 + -1;
      *param_1 = (iVar3 - (*param_1 + -2)) - (uint)(iVar3 == 0);
      param_1[1] = 0;
      boot_printf(uVar1);
    }
    boot_info_save(param_1);
  }
  return;
}

// FUNC 0x10001d88  ota_image_handler

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Copies or decompresses the staged image and verifies its CRC16 */

void ota_image_handler(int param_1,uint *param_2)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  int iStack_120;
  int iStack_11c;
  undefined1 auStack_118 [260];
  
  uVar2 = _DAT_10001ec4;
  if (*(int *)(param_1 + 0x40) == 1) {
LAB_10001ebc:
    boot_printf(uVar2);
  }
  else {
    uVar4 = *(uint *)(param_1 + 0x44);
    if (uVar4 - 2 < 2) {
      boot_printf(_DAT_10001ec8);
      uVar2 = _DAT_10001ecc;
      if (*(int *)(param_1 + 0x44) == 3) {
        flash_erase_range(_DAT_10001ed0,*(undefined4 *)(param_1 + 0x5c));
        boot_printf(uVar2);
        boot_printf(_DAT_10001ed4);
        iVar1 = xz_decompress_mem(*(undefined4 *)(param_1 + 0x48),_DAT_10001ed0,
                                  *(undefined4 *)(param_1 + 0x5c));
        if (iVar1 != 0) {
          boot_printf(_DAT_10001ed8);
          DataSynchronizationBarrier(0xf);
          *(undefined4 *)(_DAT_10001edc + 0xc) = _DAT_10001ee0;
          DataSynchronizationBarrier(0xf);
          do {
                    /* WARNING: Do nothing block with infinite loop */
          } while( true );
        }
      }
      else {
        flash_erase_range(_DAT_10001ed0,*(undefined4 *)(param_1 + 0x5c));
        boot_printf(uVar2);
        boot_printf(_DAT_10001ee4);
        iStack_120 = *(int *)(param_1 + 0x48);
        uVar4 = *(uint *)(param_1 + 0x5c);
        iStack_11c = _DAT_10001ed0;
        for (; uVar4 != 0; uVar4 = uVar4 - uVar3) {
          uVar3 = 0x100;
          if (uVar4 < 0x100) {
            uVar3 = uVar4;
          }
          memcpy(auStack_118,iStack_120,uVar3);
          flash_program_bytes(iStack_11c,auStack_118,uVar3);
          iStack_120 = iStack_120 + uVar3;
          iStack_11c = iStack_11c + uVar3;
        }
      }
      uVar4 = crc16_ccitt(_DAT_10001ed0,*(undefined4 *)(param_1 + 0x5c));
      if ((*(uint *)(param_1 + 0x60) & 0xffff) != uVar4) {
        boot_printf(_DAT_10001ef0);
        DataSynchronizationBarrier(0xf);
        *(undefined4 *)(_DAT_10001edc + 0xc) = _DAT_10001ee0;
        DataSynchronizationBarrier(0xf);
        do {
                    /* WARNING: Do nothing block with infinite loop */
        } while( true );
      }
      boot_printf(_DAT_10001ee8);
      uVar4 = 0;
      uVar3 = *(uint *)(param_1 + 0x48);
      *param_2 = 0;
      param_2[2] = uVar3;
      param_2[3] = *(uint *)(param_1 + 0x5c);
LAB_10001e28:
      param_2[1] = uVar4;
    }
    else {
      uVar2 = _DAT_10001efc;
      if (1 < uVar4) goto LAB_10001ebc;
      *param_2 = uVar4;
      param_2[2] = *(uint *)(param_1 + 0x48);
      param_2[3] = *(uint *)(param_1 + 0x5c);
      param_2[1] = 0;
      param_2[4] = 0;
      if (*(int *)(param_1 + 0x68) == _DAT_10001ef4) {
        boot_printf(_DAT_10001ef8);
        uVar4 = *(uint *)(param_1 + 0x68);
        goto LAB_10001e28;
      }
    }
    uVar3 = *(uint *)(param_1 + 100);
    uVar4 = *(uint *)(param_1 + 0x4c);
    param_2[4] = uVar3;
    param_2[5] = uVar4;
    param_2[6] = *(uint *)(param_1 + 0x50);
    boot_printf(_DAT_10001eec,*param_2,param_2[2],param_2[3],param_2[1],uVar3);
    boot_info_save(param_2);
  }
  return;
}

// FUNC 0x10001f00  boot_app_select

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Applies the rollback policy, maps the exec region and jumps to the app */

void boot_app_select(int *param_1)

{
  boot_rollback_update();
  if (*param_1 == 1) {
    boot_map_exec_region(param_1[2],param_1[3]);
    flash_exit_powerdown_veneer();
  }
  boot_jump_to_app(_DAT_10001f24);
  return;
}

// FUNC 0x10001f28  ota_image_verify

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Checks the OTA tag and CRC16, applies the image, then clears the staging area */

void ota_image_verify(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  
  iVar1 = strcmp(param_1,_DAT_10001fc4);
  if (iVar1 == 0) {
    boot_printf(_DAT_10001fcc,param_1,param_1 + 0x20,*(undefined4 *)(param_1 + 0x40),
                *(undefined4 *)(param_1 + 0x44),*(undefined4 *)(param_1 + 0x48),
                *(undefined4 *)(param_1 + 0x54),*(undefined4 *)(param_1 + 0x58),
                *(undefined4 *)(param_1 + 0x5c),*(undefined4 *)(param_1 + 0x60),
                *(undefined4 *)(param_1 + 0x68));
    if (*(int *)(param_1 + 0x40) == -1) {
      boot_printf(_DAT_10001fd0);
    }
    else {
      uVar3 = crc16_ccitt(*(undefined4 *)(param_1 + 0x48),*(undefined4 *)(param_1 + 0x54));
      if ((*(uint *)(param_1 + 0x58) & 0xffff) != uVar3) {
        kv_delete(3);
        uVar2 = _DAT_10001fd8;
        goto LAB_10001f42;
      }
      boot_printf(_DAT_10001fd4);
      ota_image_handler(param_1,param_2);
      *(undefined4 *)(param_1 + 0x40) = 0xffffffff;
      kv_write(3,param_1,0x6c);
    }
    ota_region_clear(param_2);
  }
  else {
    kv_delete(3);
    uVar2 = _DAT_10001fc8;
LAB_10001f42:
    boot_printf(uVar2);
  }
  return;
}

// FUNC 0x10002030  xz_decompress_mem

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Decompresses an XZ stream from one buffer to another */

void xz_decompress_mem(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  *_DAT_10002048 = param_1;
  uVar1 = _DAT_10002050;
  *_DAT_1000204c = param_2;
  uVar2 = _DAT_10002058;
  *_DAT_10002054 = param_3;
  xz_decompress_buffer(uVar1,uVar2);
  return;
}

// FUNC 0x1000205c  crc32_table_init

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Builds the 256-entry CRC-32 table */

void crc32_table_init(void)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  
  iVar2 = _DAT_10002090;
  uVar1 = _DAT_1000208c;
  uVar4 = 0;
  do {
    iVar3 = 8;
    uVar5 = uVar4;
    do {
      iVar3 = iVar3 + -1;
      uVar5 = -(uVar5 & 1) & uVar1 ^ uVar5 >> 1;
    } while (iVar3 != 0);
    iVar3 = uVar4 * 4;
    uVar4 = uVar4 + 1;
    *(uint *)(iVar2 + iVar3) = uVar5;
  } while (uVar4 != 0x100);
  return;
}

// FUNC 0x10002094  crc32_update

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Table-driven CRC-32 update */

uint crc32_update(byte *param_1,int param_2,uint param_3)

{
  byte *pbVar1;
  
  param_3 = ~param_3;
  pbVar1 = param_1 + param_2;
  for (; param_1 != pbVar1; param_1 = param_1 + 1) {
    param_3 = param_3 >> 8 ^ *(uint *)(((uint)*param_1 ^ param_3 & 0xff) * 4 + _DAT_100020bc);
  }
  return ~param_3;
}

// FUNC 0x100020c0  lzma_len

/* LZMA length bittree decode */

undefined8 lzma_len(uint *param_1,ushort *param_2,int param_3)

{
  ushort uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  ushort *puVar5;
  uint uVar6;
  uint uVar7;
  
  if (*param_1 < 0x1000000) {
    *param_1 = *param_1 << 8;
    uVar4 = param_1[4];
    param_1[4] = uVar4 + 1;
    param_1[1] = (uint)*(byte *)(param_1[3] + uVar4) + param_1[1] * 0x100;
  }
  uVar1 = *param_2;
  uVar4 = (uint)uVar1 * (*param_1 >> 0xb);
  uVar6 = param_1[1];
  if (uVar4 < uVar6 || uVar4 - uVar6 == 0) {
    uVar3 = *param_1 - uVar4;
    *param_1 = uVar3;
    param_1[1] = uVar6 - uVar4;
    *param_2 = uVar1 - (uVar1 >> 5);
    if (uVar3 < 0x1000000) {
      *param_1 = uVar3 * 0x100;
      uVar3 = param_1[4];
      param_1[4] = uVar3 + 1;
      param_1[1] = (uint)*(byte *)(param_1[3] + uVar3) + (uVar6 - uVar4) * 0x100;
    }
    uVar1 = param_2[1];
    uVar6 = (uint)uVar1 * (*param_1 >> 0xb);
    uVar4 = param_1[1];
    if (uVar6 < uVar4 || uVar6 - uVar4 == 0) {
      *param_1 = *param_1 - uVar6;
      param_1[1] = uVar4 - uVar6;
      param_2[1] = uVar1 - (uVar1 >> 5);
      iVar2 = 0x204;
      param_1[0x19] = 0x12;
      uVar4 = 0x100;
      goto LAB_1000210a;
    }
    iVar2 = param_3 * 0x10 + 0x104;
    *param_1 = uVar6;
    param_2[1] = uVar1 + (short)((int)(0x800 - (uint)uVar1) >> 5);
    uVar6 = 10;
  }
  else {
    uVar6 = 2;
    iVar2 = param_3 * 0x10 + 4;
    *param_1 = uVar4;
    *param_2 = uVar1 + (short)((int)(0x800 - (uint)uVar1) >> 5);
  }
  uVar4 = 8;
  param_1[0x19] = uVar6;
LAB_1000210a:
  uVar6 = 1;
  do {
    puVar5 = (ushort *)((int)param_2 + uVar6 * 2 + iVar2);
    if (*param_1 < 0x1000000) {
      *param_1 = *param_1 << 8;
      uVar3 = param_1[4];
      param_1[4] = uVar3 + 1;
      param_1[1] = (uint)*(byte *)(param_1[3] + uVar3) + param_1[1] * 0x100;
    }
    uVar7 = param_1[1];
    uVar1 = *puVar5;
    uVar3 = (uint)uVar1 * (*param_1 >> 0xb);
    uVar6 = uVar6 * 2;
    if (uVar3 < uVar7 || uVar3 - uVar7 == 0) {
      *param_1 = *param_1 - uVar3;
      uVar6 = uVar6 + 1;
      param_1[1] = uVar7 - uVar3;
      *puVar5 = uVar1 - (uVar1 >> 5);
    }
    else {
      *param_1 = uVar3;
      *puVar5 = uVar1 + (short)((int)(0x800 - (uint)uVar1) >> 5);
    }
  } while (uVar6 < uVar4);
  param_1[0x19] = (param_1[0x19] - uVar4) + uVar6;
  return CONCAT44(uVar7,param_1);
}

// FUNC 0x100021ea  dict_repeat

/* Repeats bytes from the LZMA dictionary */

undefined4 dict_repeat(int *param_1,uint *param_2,uint param_3)

{
  undefined1 *puVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  
  uVar3 = *param_2;
  uVar6 = param_1[2];
  uVar5 = param_1[4] - uVar6;
  if (uVar3 < param_1[4] - uVar6) {
    uVar5 = uVar3;
  }
  *param_2 = uVar3 - uVar5;
  iVar4 = ~param_3 + uVar6;
  if (uVar6 <= param_3) {
    iVar4 = iVar4 + param_1[5];
  }
  do {
    iVar2 = param_1[2];
    param_1[2] = iVar2 + 1;
    puVar1 = (undefined1 *)(*param_1 + iVar4);
    iVar4 = iVar4 + 1;
    *(undefined1 *)(*param_1 + iVar2) = *puVar1;
    if (iVar4 == param_1[5]) {
      iVar4 = 0;
    }
    uVar5 = uVar5 - 1;
  } while (uVar5 != 0);
  if ((uint)param_1[3] < (uint)param_1[2]) {
    param_1[3] = param_1[2];
  }
  return 1;
}

// FUNC 0x10002234  lzma_main

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* LZMA symbol decode loop */

undefined4 lzma_main(uint *param_1)

{
  ushort uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  byte bVar8;
  undefined1 uVar9;
  uint uVar10;
  int iVar11;
  int iVar12;
  ushort *puVar13;
  uint uVar14;
  uint uStack_2c;
  
  if ((((param_1[8] < param_1[10]) && (param_1[0x19] != 0)) && (param_1[0x14] < param_1[9])) &&
     (param_1[0x14] < param_1[0xc])) {
    dict_repeat(param_1 + 6,param_1 + 0x19);
  }
  do {
    while( true ) {
      uVar5 = param_1[8];
      uVar10 = *param_1;
      if ((param_1[10] <= uVar5) || (uVar6 = param_1[4], param_1[5] < uVar6)) {
        if (0xffffff < uVar10) {
          return 1;
        }
        *param_1 = uVar10 << 8;
        uVar5 = param_1[4];
        param_1[4] = uVar5 + 1;
        param_1[1] = (uint)*(byte *)(param_1[3] + uVar5) + param_1[1] * 0x100;
        return 1;
      }
      uVar2 = param_1[0x1c] & uVar5;
      uVar3 = (uint)(byte)param_1[0x18];
      if (uVar10 < 0x1000000) {
        *param_1 = uVar10 << 8;
        param_1[4] = uVar6 + 1;
        param_1[1] = (uint)*(byte *)(param_1[3] + uVar6) + param_1[1] * 0x100;
      }
      iVar4 = uVar3 * 0x10 + uVar2;
      puVar13 = (ushort *)((int)param_1 + iVar4 * 2 + 0x74);
      uVar1 = *puVar13;
      uVar6 = (uint)uVar1 * (*param_1 >> 0xb);
      uVar10 = param_1[1];
      if (uVar6 < uVar10 || uVar6 - uVar10 == 0) break;
      *param_1 = uVar6;
      *puVar13 = uVar1 + (short)((int)(0x800 - (uint)uVar1) >> 5);
      iVar4 = uVar5 - 1;
      if (uVar5 == 0) {
        iVar4 = param_1[0xb] - 1;
      }
      uVar10 = param_1[6];
      uStack_2c = param_1[9];
      uVar6 = 0;
      if (uStack_2c != 0) {
        uVar6 = (uint)*(byte *)(uVar10 + iVar4);
      }
      iVar4 = (((param_1[0x1b] & uVar5) << (param_1[0x1a] & 0xff)) +
              (uVar6 >> (8 - param_1[0x1a] & 0xff))) * 0x600 + 0xee0;
      if (uVar3 < 7) {
        uVar2 = 1;
        do {
          puVar13 = (ushort *)((int)param_1 + uVar2 * 2 + iVar4);
          if (*param_1 < 0x1000000) {
            *param_1 = *param_1 << 8;
            uVar6 = param_1[4];
            param_1[4] = uVar6 + 1;
            param_1[1] = (uint)*(byte *)(param_1[3] + uVar6) + param_1[1] * 0x100;
          }
          uVar1 = *puVar13;
          uVar6 = (uint)uVar1 * (*param_1 >> 0xb);
          uVar3 = param_1[1];
          uVar2 = uVar2 * 2;
          if (uVar6 < uVar3 || uVar6 - uVar3 == 0) {
            param_1[1] = uVar3 - uVar6;
            *param_1 = *param_1 - uVar6;
            uVar2 = uVar2 + 1;
            *puVar13 = uVar1 - (uVar1 >> 5);
          }
          else {
            *param_1 = uVar6;
            *puVar13 = uVar1 + (short)((int)(0x800 - (uint)uVar1) >> 5);
          }
        } while (uVar2 < 0x100);
      }
      else {
        iVar11 = (uVar5 - 1) - param_1[0x14];
        if (uVar5 <= param_1[0x14]) {
          iVar11 = iVar11 + param_1[0xb];
        }
        if (uStack_2c != 0) {
          uStack_2c = (uint)*(byte *)(uVar10 + iVar11);
        }
        uVar2 = 1;
        uVar6 = 0x100;
        do {
          uStack_2c = uStack_2c << 1;
          uVar3 = uVar6 & uStack_2c;
          puVar13 = (ushort *)((int)param_1 + (uVar6 + uVar2 + uVar3) * 2 + iVar4);
          if (*param_1 < 0x1000000) {
            *param_1 = *param_1 << 8;
            uVar7 = param_1[4];
            param_1[4] = uVar7 + 1;
            param_1[1] = (uint)*(byte *)(param_1[3] + uVar7) + param_1[1] * 0x100;
          }
          uVar14 = param_1[1];
          uVar1 = *puVar13;
          uVar7 = (uint)uVar1 * (*param_1 >> 0xb);
          uVar2 = uVar2 * 2;
          if (uVar7 < uVar14 || uVar7 - uVar14 == 0) {
            uVar2 = uVar2 + 1;
            *param_1 = *param_1 - uVar7;
            param_1[1] = uVar14 - uVar7;
            *puVar13 = uVar1 - (uVar1 >> 5);
          }
          else {
            *param_1 = uVar7;
            *puVar13 = uVar1 + (short)((int)(0x800 - (uint)uVar1) >> 5);
            uVar3 = uVar6 & ~uVar3;
          }
          uVar6 = uVar3;
        } while (uVar2 < 0x100);
      }
      param_1[8] = uVar5 + 1;
      *(char *)(uVar10 + uVar5) = (char)uVar2;
      if (param_1[9] < param_1[8]) {
        param_1[9] = param_1[8];
      }
      bVar8 = (byte)param_1[0x18];
      if (bVar8 < 4) {
        bVar8 = 0;
      }
      else if (bVar8 < 10) {
        bVar8 = bVar8 - 3;
      }
      else {
        bVar8 = bVar8 - 6;
      }
      *(byte *)(param_1 + 0x18) = bVar8;
    }
    uVar5 = *param_1 - uVar6;
    *param_1 = uVar5;
    param_1[1] = uVar10 - uVar6;
    *puVar13 = uVar1 - (uVar1 >> 5);
    if (uVar5 < 0x1000000) {
      *param_1 = uVar5 * 0x100;
      uVar5 = param_1[4];
      param_1[4] = uVar5 + 1;
      param_1[1] = (uint)*(byte *)(param_1[3] + uVar5) + (uVar10 - uVar6) * 0x100;
    }
    uVar1 = *(ushort *)((int)param_1 + uVar3 * 2 + 500);
    uVar10 = (uint)uVar1 * (*param_1 >> 0xb);
    uVar5 = param_1[1];
    if (uVar10 < uVar5 || uVar10 - uVar5 == 0) {
      uVar6 = *param_1 - uVar10;
      *param_1 = uVar6;
      param_1[1] = uVar5 - uVar10;
      *(ushort *)((int)param_1 + uVar3 * 2 + 500) = uVar1 - (uVar1 >> 5);
      if (uVar6 < 0x1000000) {
        *param_1 = uVar6 * 0x100;
        uVar6 = param_1[4];
        param_1[4] = uVar6 + 1;
        param_1[1] = (uint)*(byte *)(param_1[3] + uVar6) + (uVar5 - uVar10) * 0x100;
      }
      uVar1 = *(ushort *)((int)param_1 + uVar3 * 2 + 0x20c);
      uVar5 = (uint)uVar1 * (*param_1 >> 0xb);
      uVar10 = param_1[1];
      if (uVar5 < uVar10 || uVar5 - uVar10 == 0) {
        uVar6 = *param_1 - uVar5;
        *param_1 = uVar6;
        param_1[1] = uVar10 - uVar5;
        *(ushort *)((int)param_1 + uVar3 * 2 + 0x20c) = uVar1 - (uVar1 >> 5);
        if (uVar6 < 0x1000000) {
          uVar7 = param_1[4];
          param_1[4] = uVar7 + 1;
          *param_1 = uVar6 * 0x100;
          param_1[1] = (uint)*(byte *)(param_1[3] + uVar7) + (uVar10 - uVar5) * 0x100;
        }
        uVar1 = *(ushort *)((int)param_1 + uVar3 * 2 + 0x224);
        uVar6 = (uint)uVar1 * (*param_1 >> 0xb);
        uVar5 = param_1[1];
        uVar10 = param_1[0x15];
        if (uVar6 < uVar5 || uVar6 - uVar5 == 0) {
          uVar7 = *param_1 - uVar6;
          *param_1 = uVar7;
          param_1[1] = uVar5 - uVar6;
          *(ushort *)((int)param_1 + uVar3 * 2 + 0x224) = uVar1 - (uVar1 >> 5);
          if (uVar7 < 0x1000000) {
            *param_1 = uVar7 * 0x100;
            uVar7 = param_1[4];
            param_1[4] = uVar7 + 1;
            param_1[1] = (uint)*(byte *)(param_1[3] + uVar7) + (uVar5 - uVar6) * 0x100;
          }
          uVar1 = *(ushort *)((int)param_1 + uVar3 * 2 + 0x23c);
          uVar6 = param_1[1];
          uVar5 = (uint)uVar1 * (*param_1 >> 0xb);
          uVar7 = param_1[0x16];
          if (uVar5 < uVar6 || uVar5 - uVar6 == 0) {
            param_1[1] = uVar6 - uVar5;
            *param_1 = *param_1 - uVar5;
            *(ushort *)((int)param_1 + uVar3 * 2 + 0x23c) = uVar1 - (uVar1 >> 5);
            uVar5 = param_1[0x17];
            param_1[0x17] = uVar7;
          }
          else {
            *param_1 = uVar5;
            *(ushort *)((int)param_1 + uVar3 * 2 + 0x23c) =
                 uVar1 + (short)((int)(0x800 - (uint)uVar1) >> 5);
            uVar5 = uVar7;
          }
          param_1[0x16] = uVar10;
        }
        else {
          *param_1 = uVar6;
          *(ushort *)((int)param_1 + uVar3 * 2 + 0x224) =
               uVar1 + (short)((int)(0x800 - (uint)uVar1) >> 5);
          uVar5 = uVar10;
        }
        uVar10 = param_1[0x14];
        param_1[0x14] = uVar5;
        param_1[0x15] = uVar10;
      }
      else {
        *param_1 = uVar5;
        *(ushort *)((int)param_1 + uVar3 * 2 + 0x20c) =
             uVar1 + (short)((int)(0x800 - (uint)uVar1) >> 5);
        if (uVar5 < 0x1000000) {
          uVar6 = param_1[4];
          *param_1 = uVar5 * 0x100;
          param_1[4] = uVar6 + 1;
          param_1[1] = (uint)*(byte *)(param_1[3] + uVar6) + uVar10 * 0x100;
        }
        uVar1 = *(ushort *)((int)param_1 + iVar4 * 2 + 0x254);
        uVar10 = (uint)uVar1 * (*param_1 >> 0xb);
        uVar5 = param_1[1];
        if (uVar5 <= uVar10 && uVar10 - uVar5 != 0) {
          *param_1 = uVar10;
          *(ushort *)((int)param_1 + iVar4 * 2 + 0x254) =
               uVar1 + (short)((int)(0x800 - (uint)uVar1) >> 5);
          uVar9 = 9;
          if (6 < uVar3) {
            uVar9 = 0xb;
          }
          *(undefined1 *)(param_1 + 0x18) = uVar9;
          param_1[0x19] = 1;
          goto LAB_1000253a;
        }
        param_1[1] = uVar5 - uVar10;
        *param_1 = *param_1 - uVar10;
        *(ushort *)((int)param_1 + iVar4 * 2 + 0x254) = uVar1 - (uVar1 >> 5);
      }
      uVar9 = 8;
      if (6 < uVar3) {
        uVar9 = 0xb;
      }
      *(undefined1 *)(param_1 + 0x18) = uVar9;
      lzma_len(param_1,(int)param_1 + _DAT_10002874,uVar2);
    }
    else {
      *param_1 = uVar10;
      *(ushort *)((int)param_1 + uVar3 * 2 + 500) = uVar1 + (short)((int)(0x800 - (uint)uVar1) >> 5)
      ;
      uVar9 = 7;
      if (6 < uVar3) {
        uVar9 = 10;
      }
      *(undefined1 *)(param_1 + 0x18) = uVar9;
      param_1[0x17] = param_1[0x16];
      param_1[0x16] = param_1[0x15];
      param_1[0x15] = param_1[0x14];
      lzma_len(param_1,param_1 + 0x1b6,uVar2);
      uVar5 = param_1[0x19];
      if (5 < uVar5) {
        uVar5 = 5;
      }
      uVar10 = 1;
      do {
        uVar10 = uVar10 * 2;
        puVar13 = (ushort *)((int)param_1 + uVar10 + uVar5 * 0x80 + 0x2d4);
        if (*param_1 < 0x1000000) {
          *param_1 = *param_1 << 8;
          uVar6 = param_1[4];
          param_1[4] = uVar6 + 1;
          param_1[1] = (uint)*(byte *)(param_1[3] + uVar6) + param_1[1] * 0x100;
        }
        uVar1 = *puVar13;
        uVar6 = (uint)uVar1 * (*param_1 >> 0xb);
        uVar2 = param_1[1];
        if (uVar6 < uVar2 || uVar6 - uVar2 == 0) {
          param_1[1] = uVar2 - uVar6;
          *param_1 = *param_1 - uVar6;
          uVar10 = uVar10 + 1;
          *puVar13 = uVar1 - (uVar1 >> 5);
        }
        else {
          *param_1 = uVar6;
          *puVar13 = uVar1 + (short)((int)(0x800 - (uint)uVar1) >> 5);
        }
        iVar4 = _DAT_1000286c;
      } while (uVar10 < 0x40);
      uVar10 = uVar10 - 0x40;
      if (uVar10 < 4) {
        param_1[0x14] = uVar10;
      }
      else {
        uVar5 = (uVar10 & 1) + 2;
        if (uVar10 < 0xe) {
          uVar6 = (uVar10 >> 1) - 1;
          uVar5 = uVar5 << (uVar6 & 0xff);
          param_1[0x14] = uVar5;
          iVar11 = (uVar5 - uVar10) + _DAT_10002870;
          uVar5 = 0;
          iVar12 = 1;
          do {
            puVar13 = (ushort *)((int)param_1 + (iVar11 + iVar12) * 2 + iVar4);
            if (*param_1 < 0x1000000) {
              *param_1 = *param_1 << 8;
              uVar10 = param_1[4];
              param_1[4] = uVar10 + 1;
              param_1[1] = (uint)*(byte *)(param_1[3] + uVar10) + param_1[1] * 0x100;
            }
            uVar1 = *puVar13;
            uVar10 = (uint)uVar1 * (*param_1 >> 0xb);
            uVar2 = param_1[1];
            iVar12 = iVar12 * 2;
            if (uVar10 < uVar2 || uVar10 - uVar2 == 0) {
              *param_1 = *param_1 - uVar10;
              uVar3 = param_1[0x14];
              param_1[1] = uVar2 - uVar10;
              *puVar13 = uVar1 - (uVar1 >> 5);
              iVar12 = iVar12 + 1;
              param_1[0x14] = (1 << (uVar5 & 0xff)) + uVar3;
            }
            else {
              *param_1 = uVar10;
              *puVar13 = uVar1 + (short)((int)(0x800 - (uint)uVar1) >> 5);
            }
            uVar5 = uVar5 + 1;
          } while (uVar5 < uVar6);
        }
        else {
          param_1[0x14] = uVar5;
          iVar4 = (uVar10 >> 1) - 5;
          do {
            if (*param_1 < 0x1000000) {
              *param_1 = *param_1 << 8;
              uVar5 = param_1[4];
              param_1[4] = uVar5 + 1;
              param_1[1] = (uint)*(byte *)(param_1[3] + uVar5) + param_1[1] * 0x100;
            }
            iVar4 = iVar4 + -1;
            uVar10 = *param_1 >> 1;
            *param_1 = uVar10;
            uVar5 = (int)(param_1[1] - uVar10) >> 0x1f;
            param_1[1] = (uVar10 & uVar5) + (param_1[1] - uVar10);
            uVar5 = param_1[0x14] * 2 + 1 + uVar5;
            param_1[0x14] = uVar5;
          } while (iVar4 != 0);
          param_1[0x14] = uVar5 * 0x10;
          iVar4 = 1;
          uVar5 = 0;
          do {
            puVar13 = (ushort *)((int)param_1 + iVar4 * 2 + 0x6b8);
            if (*param_1 < 0x1000000) {
              *param_1 = *param_1 << 8;
              uVar10 = param_1[4];
              param_1[4] = uVar10 + 1;
              param_1[1] = (uint)*(byte *)(param_1[3] + uVar10) + param_1[1] * 0x100;
            }
            uVar1 = *puVar13;
            uVar10 = (uint)uVar1 * (*param_1 >> 0xb);
            uVar6 = param_1[1];
            iVar4 = iVar4 * 2;
            if (uVar10 < uVar6 || uVar10 - uVar6 == 0) {
              uVar2 = param_1[0x14];
              *param_1 = *param_1 - uVar10;
              param_1[1] = uVar6 - uVar10;
              *puVar13 = uVar1 - (uVar1 >> 5);
              iVar4 = iVar4 + 1;
              param_1[0x14] = (1 << (uVar5 & 0xff)) + uVar2;
            }
            else {
              *param_1 = uVar10;
              *puVar13 = uVar1 + (short)((int)(0x800 - (uint)uVar1) >> 5);
            }
            uVar5 = uVar5 + 1;
          } while (uVar5 != 4);
        }
      }
    }
LAB_1000253a:
    if (((param_1[9] <= param_1[0x14]) || (param_1[0xc] <= param_1[0x14])) ||
       (iVar4 = dict_repeat(param_1 + 6,param_1 + 0x19), iVar4 == 0)) {
      return 0;
    }
  } while( true );
}

// FUNC 0x10002878  xz_dec_lzma2_run

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* LZMA2 chunk state machine */

undefined8 xz_dec_lzma2_run(undefined4 *param_1,int *param_2,undefined4 param_3)

{
  undefined4 uVar1;
  int extraout_r1;
  char *pcVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  byte *pbVar7;
  undefined4 *puVar8;
  int *piVar9;
  undefined4 *puVar10;
  uint uVar11;
  uint uVar12;
  undefined8 unaff_d11;
  undefined8 in_d30;
  undefined4 *puVar13;
  
  puVar13 = param_1;
  piVar9 = param_2;
LAB_1000287e:
  do {
    iVar3 = _DAT_10002bb4;
    pbVar7 = (byte *)(param_1 + 0x10);
    uVar12 = param_2[2];
    do {
      if (uVar12 <= (uint)param_2[1]) {
        if (*pbVar7 == 7) {
          uVar11 = param_2[5] - param_2[4];
          if ((uint)param_1[0x11] < (uint)(param_2[5] - param_2[4])) {
            uVar11 = param_1[0x11];
          }
          iVar4 = param_1[0xb];
          if (uVar11 < (uint)(iVar4 - param_1[8])) {
            iVar4 = uVar11 + param_1[8];
          }
          param_1[10] = iVar4;
          iVar3 = *(int *)((int)param_1 + iVar3);
          if ((iVar3 == 0) && (param_1[0x12] != 0)) {
LAB_10002bce:
            iVar3 = param_2[1];
            uVar12 = param_2[2] - iVar3;
            if (0x14 < uVar12) {
              iVar4 = param_2[2] + -0x15;
              param_1[3] = *param_2;
              param_1[4] = iVar3;
              if (param_1[0x12] + 0x15 <= uVar12) {
                iVar4 = iVar3 + param_1[0x12];
              }
              param_1[5] = iVar4;
              iVar3 = lzma_main(param_1);
              if (iVar3 == 0) goto LAB_10002a3a;
              iVar3 = param_1[4];
              if ((uint)param_1[0x12] < (uint)(iVar3 - param_2[1])) goto LAB_10002a3a;
              param_1[0x12] = (param_2[1] - iVar3) + param_1[0x12];
              param_2[1] = iVar3;
            }
            uVar11 = param_2[2] - param_2[1];
            if (uVar11 < 0x15) {
              uVar12 = param_1[0x12];
              if (uVar11 < (uint)param_1[0x12]) {
                uVar12 = uVar11;
              }
              memcpy((int)param_1 + _DAT_10002cf4,*param_2 + param_2[1],uVar12,_DAT_10002cf4,puVar13
                     ,piVar9,param_3);
              *(uint *)((int)param_1 + _DAT_10002cf0) = uVar12;
LAB_10002ba6:
              param_2[1] = param_2[1] + uVar12;
            }
          }
          else {
            uVar11 = param_1[0x12] - iVar3;
            if (0x2aU - iVar3 < uVar11) {
              uVar11 = 0x2aU - iVar3;
            }
            uVar12 = uVar12 - param_2[1];
            if (uVar11 < uVar12) {
              uVar12 = uVar11;
            }
            iVar4 = (int)param_1 + _DAT_10002bb8;
            memcpy(iVar4 + iVar3,*param_2 + param_2[1],uVar12,*param_2,puVar13,piVar9,param_3);
            piVar9 = *(int **)((int)param_1 + _DAT_10002bb4);
            uVar11 = uVar12 + (int)piVar9;
            if (uVar11 != param_1[0x12]) {
              if (0x14 < uVar11) {
                param_1[5] = uVar11 - 0x15;
                goto LAB_1000290c;
              }
              *(uint *)((int)param_1 + _DAT_10002bb4) = uVar11;
              goto LAB_10002ba6;
            }
            memset(iVar4 + uVar11,0,0x3f - uVar11,param_1[0x12],puVar13,piVar9);
            piVar9 = *(int **)((int)param_1 + _DAT_10002bb4);
            param_1[5] = (int)piVar9 + uVar12;
LAB_1000290c:
            param_1[3] = iVar4;
            param_1[4] = 0;
            iVar3 = lzma_main(param_1);
            if (iVar3 == 0) goto LAB_10002a3a;
            uVar11 = param_1[4];
            uVar5 = *(uint *)((int)param_1 + _DAT_10002bb4);
            if (uVar12 + uVar5 < uVar11) goto LAB_10002a3a;
            param_1[0x12] = param_1[0x12] - uVar11;
            iVar3 = _DAT_10002cf0;
            if (uVar5 <= uVar11) {
              param_2[1] = (param_2[1] - uVar5) + uVar11;
              *(undefined4 *)((int)param_1 + iVar3) = 0;
              goto LAB_10002bce;
            }
            *(uint *)((int)param_1 + _DAT_10002bb4) = uVar5 - uVar11;
            memmove(iVar4,iVar4 + uVar11);
          }
          iVar4 = param_1[8];
          iVar3 = param_1[7];
          piVar9 = (int *)(iVar4 - iVar3);
          if (*(char *)(param_1 + 0xf) != '\0') {
            if (iVar4 == param_1[0xb]) {
              param_1[8] = 0;
            }
            memcpy(param_2[3] + param_2[4],param_1[6] + iVar3,iVar4 - iVar3,param_1[6],puVar13,
                   piVar9,param_3);
          }
          iVar6 = param_2[4];
          param_1[7] = param_1[8];
          iVar6 = (iVar4 - iVar3) + iVar6;
          iVar4 = (iVar3 + param_1[0x11]) - iVar4;
          param_2[4] = iVar6;
          param_1[0x11] = iVar4;
          if (iVar4 == 0) {
            if (((param_1[0x12] != 0) || (param_1[0x19] != 0)) || (param_1[1] != 0))
            goto LAB_10002a3a;
            *param_1 = 0xffffffff;
            param_1[2] = 5;
            *(undefined1 *)(param_1 + 0x10) = 0;
            goto LAB_1000287e;
          }
          if ((param_2[5] != iVar6) &&
             ((param_2[1] != param_2[2] ||
              ((uint)param_1[0x12] <= *(uint *)((int)param_1 + _DAT_10002cf0))))) goto LAB_1000287e;
        }
        uVar1 = 0;
        goto LAB_10002a3c;
      }
    } while (8 < *pbVar7);
    FUN_100007dc();
    param_1 = (undefined4 *)(extraout_r1 * 8);
    VectorRoundHalvingAdd(in_d30,unaff_d11,4,1);
    param_2[1] = (int)param_2 * 2 + 1;
    uVar12 = (uint)*(byte *)(*param_2 + (int)param_2 * 2);
    if (uVar12 == 0) {
      uVar1 = 1;
      goto LAB_10002a3c;
    }
    pcVar2 = (char *)(param_1 + 0x13);
    if ((uVar12 < 0xe0) && (uVar12 != 1)) {
      if (*pcVar2 == '\0') goto LAB_10002a0c;
LAB_10002a3a:
      uVar1 = 7;
LAB_10002a3c:
      return CONCAT44(puVar13,uVar1);
    }
    pcVar2[0] = '\0';
    pcVar2[1] = '\x01';
    if (*(char *)(param_1 + 0xf) == '\0') {
      iVar3 = param_2[4];
      param_1[6] = param_2[3] + iVar3;
      param_1[0xb] = param_2[5] - iVar3;
    }
    param_1[7] = 0;
    param_1[8] = 0;
    param_1[10] = 0;
    param_1[9] = 0;
LAB_10002a0c:
    if (uVar12 < 0x80) {
      if (2 < uVar12) goto LAB_10002a3a;
      *(short *)(param_1 + 0x10) = (short)_DAT_10002bbc;
    }
    else {
      param_1[0x11] = (uVar12 & 0x1f) << 0x10;
      *pbVar7 = 1;
      if (uVar12 < 0xc0) {
        if (*(char *)((int)param_1 + 0x4d) != '\0') goto LAB_10002a3a;
        *(undefined1 *)((int)param_1 + 0x41) = 6;
        if (0x9f < uVar12) {
          *(undefined1 *)(param_1 + 0x18) = 0;
          param_1[0x14] = 0;
          param_1[0x15] = 0;
          param_1[0x16] = 0;
          param_1[0x17] = 0;
          puVar10 = param_1 + 0x1d;
          puVar8 = (undefined4 *)((int)param_1 + _DAT_10002bb4);
          do {
            *(undefined2 *)puVar10 = 0x400;
            puVar10 = (undefined4 *)((int)puVar10 + 2);
          } while (puVar8 != puVar10);
          *param_1 = 0xffffffff;
          param_1[1] = 0;
          param_1[2] = 5;
        }
      }
      else {
        *(char *)((int)param_1 + 0x4d) = '\0';
        *(undefined1 *)((int)param_1 + 0x41) = 5;
      }
    }
  } while( true );
}

// FUNC 0x10002cf8  lzma2_create

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Allocates the LZMA2 dictionary state */

int lzma2_create(int param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = FUN_100043bc(_DAT_10002d38);
  if (iVar1 != 0) {
    *(char *)(iVar1 + 0x3c) = (char)param_1;
    *(undefined4 *)(iVar1 + 0x34) = param_2;
    if (param_1 == 1) {
      iVar2 = FUN_100043bc(param_2);
      *(int *)(iVar1 + 0x18) = iVar2;
      if (iVar2 == 0) {
        FUN_100043d0(iVar1);
        iVar1 = 0;
      }
    }
    else if (param_1 == 2) {
      *(undefined4 *)(iVar1 + 0x18) = 0;
      *(undefined4 *)(iVar1 + 0x38) = 0;
    }
  }
  return iVar1;
}

// FUNC 0x10002d3c  lzma2_reset

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Resets the dictionary and LZMA properties */

undefined4 lzma2_reset(int param_1,uint param_2)

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
    *(undefined4 *)(param_1 + _DAT_10002da0) = 0;
  }
  return uVar1;
}

// FUNC 0x10002da4  lzma2_end

/* Frees the LZMA2 dictionary state */

void lzma2_end(int param_1)

{
  if (*(char *)(param_1 + 0x3c) != '\0') {
    FUN_100043d0(*(undefined4 *)(param_1 + 0x18));
  }
  FUN_100043d0(param_1);
  return;
}

// FUNC 0x10002dc0  lzma2_get_value

/* Returns the first field of the LZMA2 state */

undefined4 lzma2_get_value(undefined4 *param_1)

{
  return *param_1;
}

// FUNC 0x10002dd6  lzma_props

/* Parses the five LZMA property bytes */

undefined8 lzma_props(int param_1,int param_2,uint *param_3,uint param_4)

{
  byte bVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  undefined8 uVar5;
  
  if (*(int *)(param_1 + 4) == 0) {
    *(undefined4 *)(param_1 + 8) = 0;
    *(undefined4 *)(param_1 + 0xc) = 0;
  }
  while( true ) {
    uVar3 = *param_3;
    if (param_4 <= uVar3) {
      uVar2 = 0;
      goto LAB_10002e2c;
    }
    iVar4 = *(int *)(param_1 + 4);
    bVar1 = *(byte *)(param_2 + uVar3);
    *param_3 = uVar3 + 1;
    uVar5 = aeabi_llsl(bVar1 & 0x7f,0,iVar4);
    *(uint *)(param_1 + 8) = (uint)uVar5 | *(uint *)(param_1 + 8);
    *(uint *)(param_1 + 0xc) = (uint)((ulonglong)uVar5 >> 0x20) | *(uint *)(param_1 + 0xc);
    if (-1 < (char)bVar1) break;
    *(int *)(param_1 + 4) = iVar4 + 7;
    if (iVar4 + 7 == 0x3f) {
LAB_10002e2a:
      uVar2 = 7;
LAB_10002e2c:
      return CONCAT44(param_2,uVar2);
    }
  }
  if ((bVar1 != 0) || (iVar4 == 0)) {
    uVar2 = 1;
    *(undefined4 *)(param_1 + 4) = 0;
    goto LAB_10002e2c;
  }
  goto LAB_10002e2a;
}

// FUNC 0x10002e40  xz_dec_crc_update

void xz_dec_crc_update(int param_1,int *param_2,undefined4 param_3,undefined4 param_4)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  
  uVar4 = param_2[1] - *(int *)(param_1 + 0x10);
  uVar1 = *(uint *)(param_1 + 0x70);
  iVar2 = *param_2;
  *(uint *)(param_1 + 0x70) = uVar4 + uVar1;
  *(uint *)(param_1 + 0x74) = *(int *)(param_1 + 0x74) + (uint)CARRY4(uVar4,uVar1);
  uVar3 = crc32_update(iVar2 + *(int *)(param_1 + 0x10),uVar4,*(undefined4 *)(param_1 + 0x18),
                       param_2,param_4);
  *(undefined4 *)(param_1 + 0x18) = uVar3;
  return;
}

// FUNC 0x10002e6c  bcj_fill_temp

/* Fills the branch-converter temporary buffer */

bool bcj_fill_temp(int param_1,int *param_2,undefined4 param_3,undefined4 param_4)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int *piVar4;
  bool bVar5;
  
  piVar4 = (int *)(param_1 + 0x98);
  uVar1 = param_2[2] - param_2[1];
  uVar2 = *(int *)(param_1 + 0x9c) - *piVar4;
  if (uVar1 < uVar2) {
    uVar2 = uVar1;
  }
  memcpy(param_1 + 0xa0 + *piVar4,*param_2 + param_2[1],uVar2,*param_2,param_4);
  param_2[1] = param_2[1] + uVar2;
  iVar3 = uVar2 + *piVar4;
  *piVar4 = iVar3;
  bVar5 = iVar3 == *(int *)(param_1 + 0x9c);
  if (bVar5) {
    *piVar4 = 0;
  }
  return bVar5;
}

// FUNC 0x10002eb2  bcj_reset

/* Resets the branch-converter state */

void bcj_reset(undefined1 *param_1)

{
  *param_1 = 0;
  param_1[0x1e] = 0;
  *(undefined4 *)(param_1 + 4) = 0;
  *(undefined4 *)(param_1 + 0x18) = 0;
  memset(param_1 + 0x38,0,0x30);
  memset(param_1 + 0x68,0,0x30);
  *(undefined4 *)(param_1 + 0x98) = 0;
  *(undefined4 *)(param_1 + 0x9c) = 0xc;
  return;
}

// FUNC 0x10002ee8  xz_dec_run

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* XZ container state machine: headers, blocks and checks */

int xz_dec_run(byte *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  int extraout_r1;
  uint uVar5;
  uint uVar6;
  byte bVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  undefined4 uVar11;
  int *piVar12;
  byte *pbVar13;
  byte *pbVar14;
  int iVar15;
  uint *puVar16;
  uint uVar17;
  
  if (param_1[0x1d] == 0) {
    bcj_reset();
  }
  iVar8 = *(int *)(param_2 + 4);
  iVar9 = *(int *)(param_2 + 0x10);
  *(int *)(param_1 + 0x10) = iVar8;
  while( true ) {
    do {
    } while (9 < *param_1);
    FUN_100007f0();
    piVar12 = (int *)(extraout_r1 * 0x2000);
    iVar1 = bcj_fill_temp(param_1,piVar12,extraout_r1 << 7,extraout_r1 << 0x10);
    uVar4 = _DAT_10003280;
    if (iVar1 == 0) goto LAB_10002f30;
    *param_1 = 1;
    iVar1 = memcmp(param_1 + 0xa0,uVar4,6);
    if (iVar1 != 0) {
      iVar1 = 5;
      goto LAB_10002f66;
    }
    iVar1 = crc32_update(param_1 + 0xa6,2);
    iVar2 = lzma2_get_value(param_1 + 0xa8);
    if (iVar1 != iVar2) goto LAB_10002f64;
    if ((param_1[0xa6] != 0) || (param_1[0x1c] = param_1[0xa7], 1 < param_1[0xa7]))
    goto LAB_10002f90;
    iVar1 = piVar12[1];
    if (iVar1 == piVar12[2]) goto LAB_10002f30;
    if (*(byte *)(*piVar12 + iVar1) != 0) break;
    piVar12[1] = iVar1 + 1;
    bVar7 = 6;
    *(int *)(param_1 + 0x10) = iVar1;
LAB_10002fb8:
    *param_1 = bVar7;
  }
  iVar1 = (*(byte *)(*piVar12 + iVar1) + 1) * 4;
  *(int *)(param_1 + 0x30) = iVar1;
  *(int *)(param_1 + 0x9c) = iVar1;
  param_1[0x98] = 0;
  param_1[0x99] = 0;
  param_1[0x9a] = 0;
  param_1[0x9b] = 0;
  *param_1 = 2;
  iVar1 = bcj_fill_temp(param_1,piVar12);
  if (iVar1 == 0) {
LAB_10002f30:
    iVar1 = 0;
LAB_10002f66:
    if (param_1[0x1d] == 0) {
      if (iVar1 == 0) {
        iVar1 = 8 - (uint)(piVar12[1] == piVar12[2]);
      }
      else if (iVar1 == 1) {
        return 1;
      }
      piVar12[1] = iVar8;
      piVar12[4] = iVar9;
    }
    else {
      if (((iVar1 == 0) && (piVar12[1] == iVar8)) && (piVar12[4] == iVar9)) {
        if (param_1[0x1e] != 0) {
          iVar1 = 8;
        }
        bVar7 = 1;
      }
      else {
        bVar7 = 0;
      }
      param_1[0x1e] = bVar7;
    }
    return iVar1;
  }
  pbVar14 = param_1 + 0x9c;
  iVar1 = *(int *)pbVar14;
  pbVar13 = param_1 + 0xa0;
  *(int *)pbVar14 = iVar1 + -4;
  iVar1 = crc32_update(pbVar13,iVar1 + -4,0);
  iVar15 = *(int *)pbVar14;
  iVar2 = lzma2_get_value(pbVar13 + iVar15);
  if (iVar1 == iVar2) {
    pbVar14 = param_1 + 0x98;
    pbVar14[0] = 2;
    pbVar14[1] = 0;
    pbVar14[2] = 0;
    pbVar14[3] = 0;
    if ((param_1[0xa1] & 0x3f) == 0) {
      if ((int)((uint)param_1[0xa1] << 0x19) < 0) {
        iVar1 = lzma_props(param_1,pbVar13,pbVar14,iVar15);
        if (iVar1 != 1) goto LAB_10002f64;
        uVar4 = *(undefined4 *)(param_1 + 8);
        uVar11 = *(undefined4 *)(param_1 + 0xc);
      }
      else {
        uVar4 = 0xffffffff;
        uVar11 = 0xffffffff;
      }
      *(undefined4 *)(param_1 + 0x20) = uVar4;
      *(undefined4 *)(param_1 + 0x24) = uVar11;
      if (param_1[0xa1] < 0x80) {
        uVar4 = 0xffffffff;
        uVar11 = 0xffffffff;
      }
      else {
        iVar1 = lzma_props(param_1,pbVar13,param_1 + 0x98,*(undefined4 *)(param_1 + 0x9c));
        if (iVar1 != 1) goto LAB_10002f64;
        uVar4 = *(undefined4 *)(param_1 + 8);
        uVar11 = *(undefined4 *)(param_1 + 0xc);
      }
      *(undefined4 *)(param_1 + 0x28) = uVar4;
      *(undefined4 *)(param_1 + 0x2c) = uVar11;
      puVar16 = (uint *)(param_1 + 0x98);
      uVar3 = *(uint *)(param_1 + 0x9c);
      uVar5 = *puVar16;
      if (uVar3 - uVar5 < 2) goto LAB_10002f64;
      *puVar16 = uVar5 + 1;
      if (param_1[uVar5 + 0xa0] == 0x21) {
        *puVar16 = uVar5 + 2;
        if (param_1[uVar5 + 0xa1] == 1) {
          if (uVar3 == uVar5 + 2) goto LAB_10002f64;
          *puVar16 = uVar5 + 3;
          iVar1 = lzma2_reset(*(undefined4 *)(param_1 + 0x4a0),param_1[uVar5 + 0xa2]);
          if (iVar1 != 0) goto LAB_10002f66;
          while (uVar3 = *puVar16, uVar3 < *(uint *)(param_1 + 0x9c)) {
            *puVar16 = uVar3 + 1;
            if (param_1[uVar3 + 0xa0] != 0) goto LAB_10002f90;
          }
          *puVar16 = 0;
          param_1[0x38] = 0;
          param_1[0x39] = 0;
          param_1[0x3a] = 0;
          param_1[0x3b] = 0;
          param_1[0x3c] = 0;
          param_1[0x3d] = 0;
          param_1[0x3e] = 0;
          param_1[0x3f] = 0;
          param_1[0x40] = 0;
          param_1[0x41] = 0;
          param_1[0x42] = 0;
          param_1[0x43] = 0;
          param_1[0x44] = 0;
          param_1[0x45] = 0;
          param_1[0x46] = 0;
          param_1[0x47] = 0;
          *param_1 = 3;
          *(int *)(param_1 + 0x10) = piVar12[1];
          *(int *)(param_1 + 0x14) = piVar12[4];
          iVar1 = xz_dec_lzma2_run(*(undefined4 *)(param_1 + 0x4a0),piVar12);
          uVar3 = (piVar12[1] - *(int *)(param_1 + 0x10)) + *(uint *)(param_1 + 0x38);
          uVar5 = *(int *)(param_1 + 0x3c) +
                  (uint)CARRY4(piVar12[1] - *(int *)(param_1 + 0x10),*(uint *)(param_1 + 0x38));
          *(uint *)(param_1 + 0x38) = uVar3;
          *(uint *)(param_1 + 0x3c) = uVar5;
          uVar17 = piVar12[4] - *(int *)(param_1 + 0x14);
          uVar6 = uVar17 + *(uint *)(param_1 + 0x40);
          uVar10 = *(int *)(param_1 + 0x44) + (uint)CARRY4(uVar17,*(uint *)(param_1 + 0x40));
          *(uint *)(param_1 + 0x40) = uVar6;
          *(uint *)(param_1 + 0x44) = uVar10;
          if (((uVar5 <= *(uint *)(param_1 + 0x24)) &&
              (((*(uint *)(param_1 + 0x24) != uVar5 || (uVar3 <= *(uint *)(param_1 + 0x20))) &&
               (uVar10 <= *(uint *)(param_1 + 0x2c))))) &&
             ((*(uint *)(param_1 + 0x2c) != uVar10 || (uVar6 <= *(uint *)(param_1 + 0x28))))) {
            if (param_1[0x1c] == 1) {
              uVar4 = crc32_update(*(int *)(param_1 + 0x14) + piVar12[3],uVar17,
                                   *(undefined4 *)(param_1 + 0x18));
              *(undefined4 *)(param_1 + 0x18) = uVar4;
            }
            if (iVar1 != 1) goto LAB_10002f66;
            if (((*(int *)(param_1 + 0x20) == -1) && (*(int *)(param_1 + 0x24) == -1)) ||
               ((*(int *)(param_1 + 0x38) == *(int *)(param_1 + 0x20) &&
                (*(int *)(param_1 + 0x3c) == *(int *)(param_1 + 0x24))))) {
              uVar3 = *(uint *)(param_1 + 0x40);
              if (((*(uint *)(param_1 + 0x28) == 0xffffffff) && (*(int *)(param_1 + 0x2c) == -1)) ||
                 ((uVar3 == *(uint *)(param_1 + 0x28) &&
                  (*(int *)(param_1 + 0x44) == *(int *)(param_1 + 0x2c))))) {
                uVar5 = *(uint *)(param_1 + 0x50) + *(uint *)(param_1 + 0x38);
                uVar6 = uVar5 + *(uint *)(param_1 + 0x30);
                iVar1 = *(int *)(param_1 + 0x54) + *(int *)(param_1 + 0x3c) +
                        (uint)CARRY4(*(uint *)(param_1 + 0x50),*(uint *)(param_1 + 0x38)) +
                        (uint)CARRY4(uVar5,*(uint *)(param_1 + 0x30));
                *(uint *)(param_1 + 0x50) = uVar6;
                *(int *)(param_1 + 0x54) = iVar1;
                if (param_1[0x1c] == 1) {
                  *(uint *)(param_1 + 0x50) = uVar6 + 4;
                  *(uint *)(param_1 + 0x54) = iVar1 + (uint)(0xfffffffb < uVar6);
                }
                uVar5 = *(uint *)(param_1 + 0x58);
                *(uint *)(param_1 + 0x58) = uVar3 + uVar5;
                *(uint *)(param_1 + 0x5c) =
                     *(int *)(param_1 + 0x44) + *(int *)(param_1 + 0x5c) + (uint)CARRY4(uVar3,uVar5)
                ;
                uVar4 = crc32_update(param_1 + 0x50,0x18,*(undefined4 *)(param_1 + 0x60));
                uVar3 = *(uint *)(param_1 + 0x48);
                *(undefined4 *)(param_1 + 0x60) = uVar4;
                *(uint *)(param_1 + 0x48) = uVar3 + 1;
                *(uint *)(param_1 + 0x4c) = *(int *)(param_1 + 0x4c) + (uint)(0xfffffffe < uVar3);
                *param_1 = 4;
                while( true ) {
                  uVar3 = *(uint *)(param_1 + 0x38);
                  iVar1 = *(int *)(param_1 + 0x3c);
                  if ((uVar3 & 3) == 0) break;
                  iVar2 = piVar12[1];
                  if (iVar2 == piVar12[2]) goto LAB_10002f30;
                  piVar12[1] = iVar2 + 1;
                  if (*(char *)(*piVar12 + iVar2) != '\0') goto LAB_10002f64;
                  *(uint *)(param_1 + 0x38) = uVar3 + 1;
                  *(uint *)(param_1 + 0x3c) = iVar1 + (uint)(0xfffffffe < uVar3);
                }
                *param_1 = 5;
                if (param_1[0x1c] == 1) {
                  iVar1 = piVar12[2];
                  do {
                    iVar2 = piVar12[1];
                    if (iVar2 == iVar1) goto LAB_10002f30;
                    uVar5 = *(uint *)(param_1 + 4);
                    uVar3 = *(uint *)(param_1 + 0x18);
                    piVar12[1] = iVar2 + 1;
                    if ((uVar3 >> (uVar5 & 0xff) & 0xff) != (uint)*(byte *)(*piVar12 + iVar2))
                    goto LAB_10002f64;
                    uVar5 = uVar5 + 8;
                    *(uint *)(param_1 + 4) = uVar5;
                  } while (uVar5 < 0x20);
                  param_1[0x18] = 0;
                  param_1[0x19] = 0;
                  param_1[0x1a] = 0;
                  param_1[0x1b] = 0;
                  param_1[4] = 0;
                  param_1[5] = 0;
                  param_1[6] = 0;
                  param_1[7] = 0;
                }
                bVar7 = 1;
                goto LAB_10002fb8;
              }
            }
          }
          goto LAB_10002f64;
        }
      }
    }
LAB_10002f90:
    iVar1 = 6;
    goto LAB_10002f66;
  }
LAB_10002f64:
  iVar1 = 7;
  goto LAB_10002f66;
}

// FUNC 0x100034a4  xz_dec_lzma2_create

/* Allocates the XZ decoder state */

int xz_dec_lzma2_create(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = FUN_100043bc(0x4a8);
  if (iVar1 != 0) {
    *(char *)(iVar1 + 0x1d) = (char)param_1;
    iVar2 = lzma2_create(param_1,param_2);
    *(int *)(iVar1 + 0x4a0) = iVar2;
    if (iVar2 == 0) {
      FUN_100043d0();
      iVar1 = 0;
    }
    else {
      bcj_reset(iVar1);
    }
  }
  return iVar1;
}

// FUNC 0x100034de  xz_dec_lzma2_end

/* Frees the XZ decoder state */

void xz_dec_lzma2_end(int param_1)

{
  if (param_1 != 0) {
    lzma2_end(*(undefined4 *)(param_1 + 0x4a0));
    FUN_100043d0(param_1);
  }
  return;
}

// FUNC 0x100034f8  xz_decompress_buffer

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Allocates I/O buffers and drives the XZ decoder */

undefined4 xz_decompress_buffer(code *param_1,code *param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int iStack_30;
  int iStack_2c;
  int iStack_28;
  int iStack_24;
  int iStack_20;
  undefined4 uStack_1c;
  
  crc32_table_init();
  iVar1 = xz_dec_lzma2_create(2,0x4000);
  uVar4 = _DAT_10003618;
  if (iVar1 != 0) {
    iStack_30 = FUN_100043bc(0x1000);
    iStack_2c = 0;
    iStack_28 = 0;
    iStack_24 = FUN_100043bc(0x1000);
    iStack_20 = 0;
    uStack_1c = 0x1000;
    do {
      if (iStack_2c == iStack_28) {
        iStack_28 = (*param_1)(iStack_30,1,0x1000,0);
        iStack_2c = 0;
      }
      iVar2 = xz_dec_run(iVar1,&iStack_30);
      if (iStack_20 == 0x1000) {
        iVar3 = (*param_2)(iStack_24,1,0x1000,0);
        uVar4 = _DAT_100035fc;
        if (iVar3 != iStack_20) goto LAB_1000357a;
        iStack_20 = 0;
      }
    } while (iVar2 == 0);
    iVar3 = (*param_2)(iStack_24,1,iStack_20,0);
    uVar4 = _DAT_100035fc;
    if ((iVar3 == iStack_20) && (uVar4 = _DAT_10003614, iVar2 - 1U < 8)) {
      FUN_100007c8();
      uVar4 = _DAT_10003604;
    }
  }
LAB_1000357a:
  xz_dec_lzma2_end(iVar1);
  if (iStack_30 != 0) {
    FUN_100043d0();
  }
  if (iStack_24 != 0) {
    FUN_100043d0();
  }
  boot_printf(_DAT_10003600,uVar4);
  return 1;
}

// FUNC 0x10003644  kv_store_init

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Registers the SYS ENV and SYS KV callbacks and mounts the store */

int kv_store_init(int param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  
  *_DAT_10003680 = param_1;
  uVar1 = _DAT_10003688;
  *_DAT_10003684 = param_2;
  if (param_1 != 0) {
    kv_set_callback(uVar1,2,_DAT_1000368c);
  }
  if (param_2 != 0) {
    kv_set_callback(uVar1,3,_DAT_10003690);
  }
  iVar2 = kv_mount(uVar1,_DAT_10003698,_DAT_10003694);
  return -(uint)(iVar2 != 0);
}

// FUNC 0x1000369c  kv_read

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Reads a KV record by id into a caller buffer */

int kv_read(undefined4 param_1)

{
  undefined4 uVar1;
  undefined1 auStack_1c [16];
  int iStack_c;
  
  uVar1 = FUN_1000439c(auStack_1c);
  xz_decode_finish(_DAT_100036c0,param_1,uVar1);
  return -(uint)(iStack_c == 0);
}

// FUNC 0x100036c4  kv_write

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Writes a KV record by id, magic KV10 */

void kv_write(undefined4 param_1)

{
  undefined4 uVar1;
  undefined1 auStack_1c [20];
  
  uVar1 = FUN_1000439c(auStack_1c);
  FUN_10003ef4(_DAT_100036e0,param_1,uVar1);
  return;
}

// FUNC 0x100036e4  kv_delete

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Deletes a KV record by id */

void kv_delete(undefined4 param_1)

{
  kv_erase_entry(_DAT_100036f0,param_1);
  return;
}

// FUNC 0x10003726  xz_block_decode

/* Decodes one XZ block header and its compressed data */

undefined4 xz_block_decode(undefined4 param_1,undefined2 *param_2)

{
  undefined1 uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  undefined1 auStack_4c [8];
  int iStack_44;
  uint uStack_40;
  undefined2 uStack_3c;
  undefined1 auStack_38 [36];
  
  xz_hdr_validate(param_1,*(undefined4 *)(param_2 + 8),auStack_4c,0x14);
  uVar1 = xz_block_data_done(auStack_4c,6);
  *(undefined1 *)param_2 = uVar1;
  if (uStack_40 < 0x81) {
    uVar3 = 0;
    iVar4 = 0;
    *(uint *)(param_2 + 4) = uStack_40;
    uVar2 = uStack_40 + 8;
    do {
      iVar5 = 0x20;
      if (uVar2 <= uVar3 + 0x20) {
        iVar5 = uVar2 - uVar3;
      }
      xz_hdr_validate(param_1,*(int *)(param_2 + 8) + 0xc + uVar3,auStack_38,iVar5);
      iVar4 = xz_crc32_ccitt_update(iVar4,auStack_38,iVar5);
      uVar3 = uVar3 + iVar5;
    } while (uVar3 < uVar2);
    if (iStack_44 == iVar4) {
      *(undefined1 *)((int)param_2 + 1) = 1;
      param_2[6] = uStack_3c;
      *(int *)(param_2 + 10) = *(int *)(param_2 + 8) + 0x14;
      return 0;
    }
    *(undefined1 *)((int)param_2 + 1) = 0;
  }
  else {
    *(undefined4 *)(param_2 + 4) = 0x80;
    *param_2 = 5;
  }
  return 2;
}

// FUNC 0x100037b0  FUN_100037b0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_100037b0(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int extraout_r1;
  undefined4 uVar2;
  undefined4 uStack_18;
  undefined4 uStack_14;
  
  uStack_18 = param_3;
  uStack_14 = param_4;
  memset(&uStack_18,0,8,param_4,param_1,param_2);
  uVar2 = *(undefined4 *)(param_1 + 8);
  aeabi_uidiv(param_2,uVar2);
  if (extraout_r1 != 0) {
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  iVar1 = xz_hdr_crc_update(param_1,param_2,uVar2);
  if (iVar1 == 0) {
    memset(&uStack_18,0xff,8);
    xz_crc32_ccitt_init(&uStack_18,4,1);
    xz_crc32_ccitt_init((int)&uStack_18 + 1,4,1);
    uStack_14 = _DAT_10003818;
    xz_block_len_update(param_1,param_2,&uStack_18,8,1);
  }
  return;
}

// FUNC 0x10003874  xz_block_decode_hdr

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Parses the XZ block header fields */

uint xz_block_decode_hdr(int param_1,int param_2,uint *param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  undefined1 auStack_2c [4];
  int iStack_28;
  
  if (*(char *)(param_2 + 1) != '\x01') {
    uVar1 = *param_3;
    if (uVar1 == 0xffffffff) {
      return *(int *)(param_2 + 4) + 8;
    }
    uVar3 = *(int *)(param_2 + 4) + *(int *)(param_1 + 8);
    if (uVar1 <= uVar3) {
      uVar3 = uVar3 - 8;
      uVar1 = uVar1 + 0x94;
      do {
        uVar2 = uVar1;
        if ((uVar3 <= uVar2) || (uVar3 <= uVar2 + 0x94)) {
          uVar2 = 0xffffffff;
          break;
        }
        xz_hdr_validate(param_1,uVar2,auStack_2c,0x14);
        uVar1 = uVar2 + 0x94;
      } while (iStack_28 != _DAT_100038dc);
      if (uVar2 <= (uint)(*(int *)(param_2 + 4) + *(int *)(param_1 + 8))) {
        return uVar2;
      }
    }
  }
  return 0xffffffff;
}

// FUNC 0x100038e0  FUN_100038e0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1 FUN_100038e0(int param_1,undefined4 param_2,undefined1 *param_3,int param_4)

{
  int iVar1;
  undefined1 uVar2;
  int extraout_r1;
  undefined1 uStack_38;
  undefined1 auStack_37 [3];
  int iStack_34;
  byte bStack_30;
  char cStack_2f;
  int aiStack_20 [3];
  
  memset(&uStack_38,0,8);
  aeabi_uidiv(param_2,*(undefined4 *)(param_1 + 8));
  if (extraout_r1 != 0) {
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  xz_hdr_validate(param_1,param_2,&uStack_38,8);
  iVar1 = _DAT_100039a8;
  *(undefined4 *)(param_3 + 4) = param_2;
  *(int *)(param_3 + 8) = iStack_34;
  if (iStack_34 == iVar1) {
    *param_3 = 1;
    uVar2 = xz_block_data_done(&uStack_38,4);
    param_3[1] = uVar2;
    uVar2 = xz_block_data_done(auStack_37,4);
    param_3[2] = uVar2;
    if (param_4 != 0) {
      aiStack_20[0] = *(int *)(param_3 + 4) + 8;
      *(undefined4 *)(param_3 + 0xc) = 0;
      *(int *)(param_3 + 0x10) = aiStack_20[0];
      if (param_3[1] == '\x01') {
        *(int *)(param_3 + 0xc) = *(int *)(param_1 + 8) + -8;
      }
      else if (param_3[1] == '\x02') {
        *(int *)(param_3 + 0xc) = *(int *)(param_1 + 8) + -8;
        do {
          xz_block_decode(param_1,&bStack_30);
          if ((cStack_2f == '\0') && ((bStack_30 & 0xfb) != 1)) {
            *(undefined4 *)(param_3 + 0xc) = 0;
            return 2;
          }
          *(int *)(param_3 + 0x10) = *(int *)(param_3 + 0x10) + 0x94;
          *(int *)(param_3 + 0xc) = *(int *)(param_3 + 0xc) + -0x94;
          aiStack_20[0] = xz_block_decode_hdr(param_1,param_3,aiStack_20);
        } while (aiStack_20[0] != -1);
      }
    }
    uVar2 = 0;
  }
  else {
    uVar2 = 8;
    *param_3 = 0;
  }
  return uVar2;
}

// FUNC 0x100039ac  xz_block_decode_loop

/* Main decode loop for XZ compressed data */

void xz_block_decode_loop
               (int param_1,int param_2,undefined4 param_3,undefined4 param_4,code *param_5)

{
  int iVar1;
  uint uVar2;
  undefined1 uStack_2c;
  byte bStack_2b;
  int iStack_28;
  
  do {
    uVar2 = 0;
    while( true ) {
      iVar1 = FUN_100038e0(param_1,uVar2,&uStack_2c,0);
      if ((iVar1 == 0) && (bStack_2b - 2 < 2)) {
        *(int *)(param_2 + 0x10) = iStack_28 + 8;
        do {
          xz_block_decode(param_1,param_2);
          iVar1 = (*param_5)(param_2,param_3,param_4);
          if (iVar1 != 0) {
            return;
          }
          iVar1 = xz_block_decode_hdr(param_1,&uStack_2c,param_2 + 0x10);
          *(int *)(param_2 + 0x10) = iVar1;
        } while (iVar1 != -1);
      }
      if (iStack_28 == -1) break;
      uVar2 = iStack_28 + *(int *)(param_1 + 8);
      if ((*(uint *)(param_1 + 0xc) <= uVar2) || (uVar2 == 0xffffffff)) {
        return;
      }
    }
  } while( true );
}

// FUNC 0x10003a1c  FUN_10003a1c

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1 FUN_10003a1c(undefined4 param_1,undefined2 param_2,undefined4 param_3)

{
  undefined2 auStack_12 [4];
  undefined1 uStack_9;
  
  uStack_9 = 0;
  auStack_12[0] = param_2;
  xz_block_decode_loop(param_1,param_3,auStack_12,&uStack_9,_DAT_10003a44);
  return uStack_9;
}

// FUNC 0x10003a48  FUN_10003a48

int FUN_10003a48(int param_1,undefined4 param_2,undefined1 *param_3,int param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined1 auStack_34 [4];
  undefined1 auStack_30 [28];
  
  if (param_3 == (undefined1 *)0x0) {
    iVar1 = FUN_10003a1c(param_1,param_2,auStack_30);
    if (iVar1 == 0) {
      return 5;
    }
    param_3 = auStack_30;
  }
  if (param_4 != 0) {
    iVar1 = xz_stream_done(param_1,*(undefined4 *)(param_3 + 0x10),auStack_34,6,4,1);
  }
  else {
    iVar1 = xz_stream_done(param_1,*(undefined4 *)(param_3 + 0x10),auStack_34,6,3,0);
  }
  *(bool *)(param_1 + 0x58) = param_4 == 0;
  if (iVar1 == 0) {
    iVar3 = (*(uint *)(param_3 + 0x10) & -*(int *)(param_1 + 8)) + 1;
    iVar2 = FUN_10004380(param_1,iVar3,auStack_34,4);
    if (iVar2 == 1) {
      iVar1 = xz_stream_done(param_1,iVar3,auStack_34,4,2,1);
    }
  }
  return iVar1;
}

// FUNC 0x10003af4  FUN_10003af4

undefined4 FUN_10003af4(undefined4 param_1,int param_2,undefined1 *param_3)

{
  undefined4 uVar1;
  undefined1 auStack_14 [8];
  
  if (*(char *)(param_2 + 1) == '\x01') {
    uVar1 = xz_stream_done(param_1,*(undefined4 *)(param_2 + 4),auStack_14,4,2,1);
  }
  else {
    uVar1 = 0;
    if (*(char *)(param_2 + 1) == '\x02') {
      if (*(uint *)(param_2 + 0xc) < 0x128) {
        uVar1 = xz_stream_done(param_1,*(undefined4 *)(param_2 + 4),auStack_14,4,3,1);
        if (param_3 != (undefined1 *)0x0) {
          *param_3 = 1;
        }
      }
      else if (param_3 != (undefined1 *)0x0) {
        *param_3 = 0;
      }
    }
  }
  return uVar1;
}

// FUNC 0x10003b4c  xz_container_decode

/* Decodes the XZ container format: stream headers and blocks */

undefined8
xz_container_decode(int param_1,int param_2,uint param_3,undefined4 param_4,undefined4 param_5,
                   code *param_6,byte param_7)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar2 = (uint)param_7;
  uVar4 = param_3;
  do {
    uVar3 = 0;
    while( true ) {
      FUN_100038e0(param_1,uVar3,param_2,0,param_4,uVar2,uVar4);
      if ((param_3 == 0) || (*(byte *)(param_2 + 1) == param_3)) {
        if (uVar2 != 0) {
          FUN_100038e0(param_1,uVar3,param_2,1,param_4,uVar2,uVar4);
        }
        iVar1 = (*param_6)(param_2,param_4,param_5);
        if (iVar1 != 0) goto LAB_10003ba8;
      }
      if (*(int *)(param_2 + 4) == -1) break;
      uVar3 = *(int *)(param_2 + 4) + *(int *)(param_1 + 8);
      if ((*(uint *)(param_1 + 0xc) <= uVar3) || (uVar3 == 0xffffffff)) {
LAB_10003ba8:
        return CONCAT44(uVar2,param_4);
      }
    }
  } while( true );
}

// FUNC 0x10003bac  FUN_10003bac

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_10003bac(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iStack_28;
  uint uStack_24;
  int iStack_20;
  int iStack_1c;
  undefined4 uStack_18;
  int *piStack_14;
  
  iStack_28 = -1;
  piStack_14 = &iStack_28;
  uStack_24 = 0;
  iStack_20 = 0;
  iStack_1c = param_1;
  uStack_18 = param_3;
  xz_container_decode(param_1,param_2,0,&uStack_24,&iStack_20,_DAT_10003c34,0);
  if (iStack_20 != 0) {
    xz_container_decode(param_1,param_2,2,&iStack_1c,0,_DAT_10003c38,1);
  }
  if ((uStack_24 != 0) && (iStack_28 == -1)) {
    if ((uStack_24 < 2) && (*(char *)(param_1 + 0x28) == '\0')) {
      *(char *)(param_1 + 0x28) = '\x01';
    }
    else {
      xz_container_decode(param_1,param_2,1,&iStack_1c,0,_DAT_10003c38,1);
    }
  }
  return iStack_28;
}

// FUNC 0x10003c3c  xz_container_dispatch

undefined4 xz_container_dispatch(int param_1,char *param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  undefined4 uStack_5c;
  undefined1 auStack_50 [4];
  undefined1 auStack_4c [20];
  undefined1 auStack_38 [36];
  
  if (*param_2 == '\x02') {
    FUN_10003a48(param_1,0,param_2);
  }
  iVar1 = FUN_10003bac(param_1,auStack_4c,0x94);
  uStack_5c = 7;
  if (iVar1 != -1) {
    if ((*(char *)(param_1 + 0x29) == '\0') ||
       (iVar2 = FUN_10003a1c(param_1,*(undefined2 *)(param_2 + 0xc),auStack_38), iVar2 == 0)) {
      iVar2 = *(int *)(param_2 + 8);
      FUN_10003af4(param_1,auStack_4c,0);
      xz_stream_done(param_1,iVar1,auStack_50,6,1,0);
      uVar3 = iVar2 + 0x10;
      uStack_5c = 0;
      for (uVar4 = 0; uVar4 < uVar3; uVar4 = uVar4 + iVar2) {
        iVar2 = 0x20;
        if (uVar3 <= uVar4 + 0x20) {
          iVar2 = uVar3 - uVar4;
        }
        xz_hdr_validate(param_1,*(int *)(param_2 + 0x10) + 4 + uVar4,auStack_38,iVar2);
        uStack_5c = xz_block_len_update(param_1,iVar1 + 4 + uVar4,auStack_38,iVar2,1);
      }
      xz_stream_done(param_1,iVar1,auStack_50,6,2,1);
    }
    else {
      uStack_5c = 0;
    }
    FUN_10003a48(param_1,0,param_2,1);
  }
  return uStack_5c;
}

// FUNC 0x10003dc8  xz_block_decode_done

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Finalizes an XZ block after decoding */

void xz_block_decode_done(int param_1)

{
  uint uStack_28;
  undefined1 auStack_24 [24];
  
  uStack_28 = 0;
  xz_container_decode(param_1,auStack_24,1,&uStack_28,0,_DAT_10003e08,0);
  if (uStack_28 < 2) {
    xz_container_decode(param_1,auStack_24,0,param_1,0,_DAT_10003e0c,0);
  }
  *(undefined1 *)(param_1 + 0x28) = 0;
  return;
}

// FUNC 0x10003e10  xz_stream_decode_done

/* Finalizes an XZ stream after all blocks */

void xz_stream_decode_done(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  
  iVar1 = FUN_10003bac();
  if (iVar1 == -1) {
    if (*(char *)(param_1 + 0x28) != '\0') {
      xz_block_decode_done(param_1);
      iVar1 = FUN_10003bac(param_1,param_2,param_3);
      if (iVar1 == -1) {
        *(char *)(param_1 + 0x28) = '\0';
      }
    }
  }
  return;
}

// FUNC 0x10003e66  xz_decode_finish

/* Checks completion and returns the result code */

uint xz_decode_finish(int param_1,undefined4 param_2,int *param_3)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  undefined1 auStack_30 [8];
  uint uStack_28;
  undefined4 uStack_1c;
  
  uVar2 = (uint)*(byte *)(param_1 + 0x10);
  if (uVar2 != 0) {
    if (*(code **)(param_1 + 0x14) != (code *)0x0) {
      (**(code **)(param_1 + 0x14))();
    }
    iVar3 = *param_3;
    uVar2 = param_3[1];
    iVar1 = FUN_10003a1c(param_1,param_2,auStack_30);
    if (iVar1 == 0) {
      param_3[4] = 0;
      uVar2 = 0;
    }
    else {
      param_3[4] = uStack_28;
      if (uStack_28 < uVar2) {
        uVar2 = uStack_28;
      }
      if (iVar3 != 0) {
        xz_hdr_validate(param_1,uStack_1c,iVar3,uVar2);
      }
    }
    if (*(code **)(param_1 + 0x18) != (code *)0x0) {
      (**(code **)(param_1 + 0x18))(param_1);
    }
  }
  return uVar2;
}

// FUNC 0x10003ec0  kv_erase_entry

/* Erases one KV entry */

undefined4 kv_erase_entry(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  uVar1 = 8;
  if (*(char *)(param_1 + 0x10) != '\0') {
    if (*(code **)(param_1 + 0x14) != (code *)0x0) {
      (**(code **)(param_1 + 0x14))();
    }
    uVar1 = FUN_10003a48(param_1,param_2,0,1);
    if (*(code **)(param_1 + 0x18) != (code *)0x0) {
      (**(code **)(param_1 + 0x18))(param_1);
    }
  }
  return uVar1;
}

// FUNC 0x10003ef4  FUN_10003ef4

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_10003ef4(int param_1,undefined4 param_2,int *param_3)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  char cStack_2d;
  undefined1 auStack_2c [4];
  undefined4 uStack_28;
  undefined4 uStack_24;
  uint uStack_20;
  undefined2 uStack_1c;
  
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
      iVar1 = xz_stream_decode_done(param_1,iVar4,uVar3 + 0x14);
      iVar6 = 7;
      if (iVar1 != -1) {
        iVar5 = param_1 + 0x2c;
        iVar1 = FUN_10003a1c(param_1,param_2,iVar5);
        if ((iVar1 == 0) || (iVar6 = FUN_10003a48(param_1,param_2,iVar5,0), iVar6 == 0)) {
          cStack_2d = '\0';
          iVar7 = *(int *)(param_1 + 0x54);
          memset(auStack_2c,0xff,0x14);
          uStack_28 = _DAT_10004074;
          uStack_1c = (undefined2)param_2;
          uStack_20 = uVar3;
          if (((*(int *)(param_1 + 8) - 8U < uVar3) || (0x80 < uVar3)) ||
             ((iVar7 == -1 && (iVar7 = xz_stream_decode_done(param_1,iVar4,0x94), iVar7 == -1)))) {
            iVar6 = 7;
          }
          else {
            iVar6 = FUN_10003af4(param_1,iVar4,&cStack_2d);
            if (iVar6 == 0) {
              uStack_24 = xz_crc32_ccitt_update(0,&uStack_20,8);
              uStack_24 = xz_crc32_ccitt_update(uStack_24,iVar2,uStack_20);
              iVar6 = xz_stream_done(param_1,iVar7,auStack_2c,6,1,0);
              if (iVar6 == 0) {
                iVar6 = xz_block_len_update(param_1,iVar7 + 4,&uStack_28,0x10,0);
                if (iVar6 == 0) {
                  iVar6 = xz_block_len_update(param_1,iVar7 + 0x14,iVar2,uStack_20,0);
                  if (iVar6 == 0) {
                    iVar6 = xz_stream_done(param_1,iVar7,auStack_2c,6,2,1);
                    if (iVar6 == 0) {
                      if (cStack_2d != '\0') {
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
          xz_block_decode_done(param_1);
        }
      }
    }
    if (*(code **)(param_1 + 0x18) != (code *)0x0) {
      (**(code **)(param_1 + 0x18))(param_1);
    }
  }
  return iVar6;
}

// FUNC 0x10004078  kv_scan_entries

/* Scans all KV sectors for valid entries */

int kv_scan_entries(int param_1)

{
  int iVar1;
  uint uVar2;
  
  if (*(code **)(param_1 + 0x14) != (code *)0x0) {
    (**(code **)(param_1 + 0x14))();
  }
  for (uVar2 = 0; uVar2 < *(uint *)(param_1 + 0xc); uVar2 = uVar2 + *(int *)(param_1 + 8)) {
    iVar1 = FUN_100037b0(param_1,uVar2);
    if (iVar1 != 0) goto LAB_1000408e;
  }
  iVar1 = 0;
LAB_1000408e:
  if (*(code **)(param_1 + 0x18) != (code *)0x0) {
    (**(code **)(param_1 + 0x18))(param_1);
  }
  return iVar1;
}

// FUNC 0x100040b0  kv_recover

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Rebuilds the KV index from the sector contents */

undefined4 kv_recover(int param_1)

{
  int iVar1;
  int iStack_40;
  undefined1 auStack_3c [20];
  undefined1 auStack_28 [28];
  
  *(undefined1 *)(param_1 + 0x29) = 1;
  iStack_40 = 0;
  xz_container_decode(param_1,auStack_3c,0,&iStack_40,param_1,_DAT_10004138,0);
  iVar1 = aeabi_uidivmod(*(undefined4 *)(param_1 + 0xc),*(undefined4 *)(param_1 + 8));
  if (iVar1 == iStack_40) {
    kv_scan_entries(param_1);
  }
  if (*(code **)(param_1 + 0x14) != (code *)0x0) {
    (**(code **)(param_1 + 0x14))(param_1);
  }
  xz_container_decode(param_1,auStack_3c,0,param_1,0,_DAT_1000413c,0);
  while( true ) {
    xz_block_decode_loop(param_1,auStack_28,param_1,0,_DAT_10004140);
    if (*(char *)(param_1 + 0x28) == '\0') break;
    xz_block_decode_done(param_1);
  }
  *(undefined1 *)(param_1 + 0x29) = 0;
  if (*(code **)(param_1 + 0x18) != (code *)0x0) {
    (**(code **)(param_1 + 0x18))(param_1);
  }
  return 0;
}

// FUNC 0x10004144  kv_set_callback

/* Stores or returns the read, write and erase callbacks */

void kv_set_callback(int param_1,uint param_2)

{
  uint uVar1;
  
  if (param_1 == 0) {
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  if (param_2 < 4) {
    uVar1 = FUN_100007c8(param_2);
    if (*(char *)(param_1 + 0x10) != '\0') {
      do {
                    /* WARNING: Do nothing block with infinite loop */
      } while( true );
    }
    *(undefined4 *)(param_1 + 8) = *(undefined4 *)(uVar1 >> 4);
  }
  return;
}

// FUNC 0x10004178  kv_mount

/* Mounts the KV store, recovering it when needed */

int kv_mount(int param_1)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = xz_header_parse();
  if (iVar1 == 0) {
    *(undefined2 *)(param_1 + 0x28) = 0;
    uVar2 = aeabi_uidivmod(*(undefined4 *)(param_1 + 0xc),*(undefined4 *)(param_1 + 8));
    if (uVar2 < 2) {
      do {
                    /* WARNING: Do nothing block with infinite loop */
      } while( true );
    }
    iVar1 = kv_recover(param_1);
  }
  kv_mark_ready(param_1,iVar1);
  return iVar1;
}

// FUNC 0x1000421e  xz_hdr_validate

/* Validates an XZ header CRC */

undefined4 xz_hdr_validate(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = 2;
  if (*(code **)(param_1 + 0x1c) != (code *)0x0) {
    uVar1 = (**(code **)(param_1 + 0x1c))(param_1);
  }
  return uVar1;
}

// FUNC 0x10004230  xz_hdr_crc_update

/* Updates the header CRC over parsed bytes */

undefined4 xz_hdr_crc_update(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = 1;
  if (*(code **)(param_1 + 0x24) != (code *)0x0) {
    uVar1 = (**(code **)(param_1 + 0x24))(param_1);
  }
  return uVar1;
}

// FUNC 0x10004242  xz_block_len_update

/* Updates the block length CRC */

undefined4 xz_block_len_update(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = 3;
  if (*(code **)(param_1 + 0x20) != (code *)0x0) {
    uVar1 = (**(code **)(param_1 + 0x20))(param_1);
  }
  return uVar1;
}

// FUNC 0x10004254  xz_header_parse

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Parses the XZ stream header: magic, blocks, streams */

undefined4 xz_header_parse(int *param_1,int param_2,int param_3)

{
  int iVar1;
  undefined8 uVar2;
  
  iVar1 = _DAT_100042b4;
  if (param_1 == (int *)0x0) {
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  if (param_2 == 0) {
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  if (param_3 == 0) {
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  if ((char)param_1[4] == '\0') {
    *param_1 = param_2;
    param_1[7] = iVar1;
    param_1[8] = _DAT_100042b8;
    param_1[9] = _DAT_100042bc;
    iVar1 = flash_region_find(param_3);
    *(char *)(param_1 + 1) = (char)iVar1;
    if (iVar1 == -1) {
      return 4;
    }
    param_1[2] = 0x1000;
    iVar1 = flash_region_get();
    iVar1 = *(int *)(iVar1 + 0xc);
    param_1[3] = iVar1;
    uVar2 = aeabi_uidiv(iVar1,param_1[2]);
    if ((int)((ulonglong)uVar2 >> 0x20) != 0) {
      do {
                    /* WARNING: Do nothing block with infinite loop */
      } while( true );
    }
    if ((uint)uVar2 < 2) {
      do {
                    /* WARNING: Do nothing block with infinite loop */
      } while( true );
    }
  }
  return 0;
}

// FUNC 0x100042c0  xz_crc32_ccitt_update

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* CCITT CRC-32 update over decoded bytes */

uint xz_crc32_ccitt_update(uint param_1,byte *param_2,int param_3)

{
  uint uVar1;
  byte *pbVar2;
  char cVar3;
  
  param_1 = ~param_1;
  pbVar2 = param_2 + param_3;
  for (; param_2 != pbVar2; param_2 = param_2 + 1) {
    cVar3 = '\b';
    uVar1 = param_1 ^ (uint)*param_2 << 0x18;
    do {
      param_1 = uVar1 << 1;
      if ((int)uVar1 < 0) {
        param_1 = param_1 ^ _DAT_100042f0;
      }
      cVar3 = cVar3 + -1;
      uVar1 = param_1;
    } while (cVar3 != '\0');
  }
  return ~param_1;
}

// FUNC 0x100042f4  xz_crc32_ccitt_init

/* Initializes the CCITT CRC-32 context */

uint xz_crc32_ccitt_init(undefined1 *param_1,undefined4 param_2,uint param_3)

{
  uint uVar1;
  
  *param_1 = 0xff;
  if (param_3 == 0) {
    uVar1 = 0xffffffff;
  }
  else {
    uVar1 = param_3 - 1 >> 3;
    param_1[uVar1] = (byte)(0xff >> (param_3 & 7)) & param_1[uVar1];
  }
  return uVar1;
}

// FUNC 0x10004318  xz_block_data_done

/* Marks an XZ data block as complete */

int xz_block_data_done(int param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = param_2 - 2U;
  do {
    uVar2 = uVar1;
    if (uVar2 == 0xffffffff) break;
    uVar1 = uVar2 - 1;
  } while ((0x80 >> (uVar2 & 7) & (uint)*(byte *)(param_1 + (uVar2 >> 3))) != 0);
  return (uVar2 - (param_2 - 2U)) + param_2 + -1;
}

// FUNC 0x10004346  xz_stream_done

/* Marks the final XZ stream as complete */

undefined8
xz_stream_done(uint param_1,int param_2,int param_3,uint param_4,uint param_5,byte param_6)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  
  uVar3 = (uint)param_6;
  if (param_4 <= param_5) {
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  if (param_3 == 0) {
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  uVar4 = param_1;
  iVar5 = param_2;
  iVar6 = param_3;
  iVar1 = xz_crc32_ccitt_init(param_3);
  uVar2 = 0;
  if (iVar1 != -1) {
    uVar2 = xz_block_len_update(param_1,iVar1 + param_2,param_3 + iVar1,1,uVar3,iVar5,iVar6);
    uVar4 = uVar3;
  }
  return CONCAT44(uVar4,uVar2);
}

// FUNC 0x10004380  FUN_10004380

void FUN_10004380(undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  if (param_3 == 0) {
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  xz_hdr_validate();
  xz_block_data_done(param_3,param_4);
  return;
}

// FUNC 0x1000439c  FUN_1000439c

void FUN_1000439c(undefined4 *param_1,undefined4 param_2,undefined4 param_3)

{
  *param_1 = param_2;
  param_1[1] = param_3;
  return;
}

// FUNC 0x100043a4  kv_mark_ready

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Marks the KV store as initialized */

void kv_mark_ready(int param_1,int param_2)

{
  char *pcVar1;
  
  pcVar1 = _DAT_100043b8;
  if (param_2 == 0) {
    *(undefined1 *)(param_1 + 0x10) = 1;
    if (*pcVar1 == '\0') {
      *pcVar1 = '\x01';
    }
  }
  return;
}

// FUNC 0x100043bc  FUN_100043bc

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_100043bc(undefined4 param_1)

{
  FUN_100043e4(*_DAT_100043cc,param_1);
  return;
}

// FUNC 0x100043d0  FUN_100043d0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_100043d0(undefined4 param_1)

{
  FUN_10004c90(*_DAT_100043e0,param_1);
  return;
}

// FUNC 0x100043e4  FUN_100043e4

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int * FUN_100043e4(undefined4 *param_1,uint param_2)

{
  uint *puVar1;
  uint *puVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  int *piVar8;
  uint uVar9;
  int iVar10;
  int *piVar11;
  int iVar12;
  int *piVar13;
  uint uVar14;
  uint uVar15;
  uint *puVar16;
  uint uStack_30;
  
  uVar14 = param_2 + 0xb;
  if (uVar14 < 0x17) {
    if (0x10 < param_2) {
LAB_10004568:
      *param_1 = 0xc;
      return (int *)0x0;
    }
    FUN_10004bb0();
    uVar15 = 0x10;
    uVar14 = 2;
    iVar10 = 0x18;
LAB_1000440c:
    iVar10 = _DAT_1000473c + iVar10;
    iVar12 = *(int *)(iVar10 + 4);
    if (iVar12 == iVar10 + -8) {
      iVar12 = *(int *)(iVar10 + 0xc);
      uVar14 = uVar14 + 2;
      if (iVar10 == iVar12) {
        iVar12 = *(int *)(_DAT_1000473c + 0x10);
        iVar10 = _DAT_1000473c + 8;
        if (iVar12 == iVar10) goto LAB_1000459e;
LAB_100044ac:
        uVar3 = _DAT_1000473c;
        uVar4 = *(uint *)(iVar12 + 4);
        uVar6 = uVar4 & 0xfffffffc;
        uVar5 = uVar6 - uVar15;
        if (0xf < (int)uVar5) {
          iVar7 = iVar12 + uVar15;
          *(uint *)(iVar12 + 4) = uVar15 | 1;
          *(int *)(uVar3 + 0x14) = iVar7;
          *(int *)(uVar3 + 0x10) = iVar7;
          *(int *)(iVar7 + 0xc) = iVar10;
          *(int *)(iVar7 + 8) = iVar10;
          *(uint *)(iVar7 + 4) = uVar5 | 1;
          *(uint *)(iVar12 + uVar6) = uVar5;
          FUN_10004bc0(param_1);
          return (int *)(iVar12 + 8);
        }
        *(int *)(_DAT_1000473c + 0x14) = iVar10;
        *(int *)(uVar3 + 0x10) = iVar10;
        if (-1 < (int)uVar5) goto LAB_1000442c;
        if (uVar6 < 0x200) {
          iVar7 = (uVar4 & 0xfffffff8) + uVar3;
          uVar4 = 1 << (uVar4 >> 5 & 0xff) | *(uint *)(uVar3 + 4);
          iVar10 = *(int *)(iVar7 + 8);
          *(uint *)(uVar3 + 4) = uVar4;
          *(int *)(iVar12 + 0xc) = iVar7;
          *(int *)(iVar12 + 8) = iVar10;
          *(int *)(iVar7 + 8) = iVar12;
          *(int *)(iVar10 + 0xc) = iVar12;
        }
        else {
          uVar5 = uVar4 >> 9;
          if (uVar5 < 5) {
            iVar10 = (uVar4 >> 6) + 0x38;
            iVar7 = ((uVar4 >> 6) + 0x39) * 8;
          }
          else if (uVar5 < 0x15) {
            iVar10 = uVar5 + 0x5b;
            iVar7 = (uVar5 + 0x5c) * 8;
          }
          else if (uVar5 < 0x55) {
            iVar10 = (uVar4 >> 0xc) + 0x6e;
            iVar7 = ((uVar4 >> 0xc) + 0x6f) * 8;
          }
          else if (uVar5 < 0x155) {
            iVar10 = (uVar4 >> 0xf) + 0x77;
            iVar7 = ((uVar4 >> 0xf) + 0x78) * 8;
          }
          else if (_DAT_10004960 < uVar5) {
            iVar10 = 0x7e;
            iVar7 = 0x3f8;
          }
          else {
            iVar10 = (uVar4 >> 0x12) + 0x7c;
            iVar7 = ((uVar4 >> 0x12) + 0x7d) * 8;
          }
          piVar11 = (int *)(uVar3 + iVar7) + -2;
          piVar8 = *(int **)(uVar3 + iVar7);
          if (piVar11 == piVar8) {
            uVar4 = 1 << (iVar10 >> 2 & 0xffU) | *(uint *)(uVar3 + 4);
            *(uint *)(uVar3 + 4) = uVar4;
          }
          else {
            do {
              if ((piVar8[1] & 0xfffffffcU) <= uVar6) break;
              piVar8 = (int *)piVar8[2];
            } while (piVar11 != piVar8);
            piVar11 = (int *)piVar8[3];
            uVar4 = *(uint *)(uVar3 + 4);
          }
          *(int **)(iVar12 + 8) = piVar8;
          *(int **)(iVar12 + 0xc) = piVar11;
          piVar11[2] = iVar12;
          piVar8[3] = iVar12;
        }
        uVar6 = 1 << ((int)uVar14 >> 2 & 0xffU);
        if (uVar6 <= uVar4) goto LAB_100044f6;
        goto LAB_100045aa;
      }
    }
    uVar6 = *(uint *)(iVar12 + 4) & 0xfffffffc;
LAB_10004424:
    iVar7 = *(int *)(iVar12 + 0xc);
    iVar10 = *(int *)(iVar12 + 8);
    *(int *)(iVar10 + 0xc) = iVar7;
    *(int *)(iVar7 + 8) = iVar10;
LAB_1000442c:
    *(uint *)(iVar12 + uVar6 + 4) = *(uint *)(iVar12 + uVar6 + 4) | 1;
    FUN_10004bc0(param_1);
    return (int *)(iVar12 + 8);
  }
  uVar15 = uVar14 & 0xfffffff8;
  if (((int)uVar15 < 0) || (uVar15 < param_2)) goto LAB_10004568;
  FUN_10004bb0();
  if (uVar15 < 0x1f8) {
    uVar14 = uVar14 >> 3;
    iVar10 = uVar15 + 8;
    goto LAB_1000440c;
  }
  uVar3 = uVar14 >> 9;
  if (uVar3 == 0) {
    uVar4 = 0x3f;
    uVar3 = 0x40;
    iVar10 = 0x200;
  }
  else if (uVar3 < 5) {
    uVar4 = (uVar14 >> 6) + 0x38;
    uVar3 = (uVar14 >> 6) + 0x39;
    iVar10 = uVar3 * 8;
  }
  else if (uVar3 < 0x15) {
    uVar4 = uVar3 + 0x5b;
    uVar3 = uVar3 + 0x5c;
    iVar10 = uVar3 * 8;
  }
  else if (uVar3 < 0x55) {
    uVar4 = (uVar14 >> 0xc) + 0x6e;
    uVar3 = (uVar14 >> 0xc) + 0x6f;
    iVar10 = uVar3 * 8;
  }
  else if (uVar3 < 0x155) {
    uVar4 = (uVar14 >> 0xf) + 0x77;
    uVar3 = (uVar14 >> 0xf) + 0x78;
    iVar10 = uVar3 * 8;
  }
  else if (_DAT_10004960 < uVar3) {
    uVar3 = 0x7f;
    uVar4 = 0x7e;
    iVar10 = 0x3f8;
  }
  else {
    uVar4 = (uVar14 >> 0x12) + 0x7c;
    uVar3 = (uVar14 >> 0x12) + 0x7d;
    iVar10 = uVar3 * 8;
  }
  for (iVar12 = *(int *)(_DAT_1000473c + iVar10 + 4); uVar14 = uVar3,
      _DAT_1000473c + iVar10 + -8 != iVar12; iVar12 = *(int *)(iVar12 + 0xc)) {
    uVar6 = *(uint *)(iVar12 + 4) & 0xfffffffc;
    uVar14 = uVar4;
    if (0xf < (int)(uVar6 - uVar15)) break;
    if (-1 < (int)(uVar6 - uVar15)) goto LAB_10004424;
  }
  iVar12 = *(int *)(_DAT_1000473c + 0x10);
  iVar10 = _DAT_1000473c + 8;
  if (iVar12 != iVar10) goto LAB_100044ac;
LAB_1000459e:
  uVar4 = *(uint *)(_DAT_1000473c + 4);
  uVar6 = 1 << ((int)uVar14 >> 2 & 0xffU);
  uVar3 = _DAT_1000473c;
  if (uVar6 <= uVar4) {
LAB_100044f6:
    if ((uVar4 & uVar6) == 0) {
      uVar14 = uVar14 & 0xfffffffc;
      do {
        uVar6 = uVar6 << 1;
        uVar14 = uVar14 + 4;
      } while ((uVar4 & uVar6) == 0);
    }
    do {
      piVar8 = (int *)(uVar14 * 8 + uVar3);
      uVar4 = uVar14;
      piVar11 = piVar8;
      do {
        for (piVar13 = (int *)piVar11[3]; piVar11 != piVar13; piVar13 = (int *)piVar13[3]) {
          uVar9 = piVar13[1] & 0xfffffffc;
          uVar5 = uVar9 - uVar15;
          if (0xf < (int)uVar5) {
            iVar12 = (int)piVar13 + uVar15;
            piVar13[1] = uVar15 | 1;
            iVar10 = piVar13[2];
            iVar7 = piVar13[3];
            *(int *)(iVar10 + 0xc) = iVar7;
            *(int *)(iVar7 + 8) = iVar10;
            *(int *)(uVar3 + 0x14) = iVar12;
            *(int *)(uVar3 + 0x10) = iVar12;
            *(uint *)(iVar12 + 4) = uVar5 | 1;
            *(uint *)(iVar12 + 0xc) = uVar3 + 8;
            *(uint *)(iVar12 + 8) = uVar3 + 8;
            *(uint *)((int)piVar13 + uVar9) = uVar5;
            FUN_10004bc0(param_1);
            return piVar13 + 2;
          }
          if (-1 < (int)uVar5) {
            *(uint *)((int)piVar13 + uVar9 + 4) = *(uint *)((int)piVar13 + uVar9 + 4) | 1;
            iVar12 = piVar13[3];
            iVar10 = piVar13[2];
            *(int *)(iVar10 + 0xc) = iVar12;
            *(int *)(iVar12 + 8) = iVar10;
            FUN_10004bc0(param_1);
            return piVar13 + 2;
          }
        }
        piVar11 = piVar11 + 2;
        uVar4 = uVar4 + 1;
      } while ((uVar4 & 3) != 0);
      do {
        if ((uVar14 & 3) == 0) {
          uVar5 = *(uint *)(uVar3 + 4) & ~uVar6;
          *(uint *)(uVar3 + 4) = uVar5;
          goto LAB_10004832;
        }
        piVar13 = piVar8 + -2;
        piVar11 = (int *)*piVar8;
        uVar14 = uVar14 - 1;
        piVar8 = piVar13;
      } while (piVar11 == piVar13);
      uVar5 = *(uint *)(uVar3 + 4);
LAB_10004832:
      uVar6 = uVar6 * 2;
      if ((uVar5 <= uVar6 && uVar6 - uVar5 != 0) || (uVar14 = uVar4, uVar6 == 0)) break;
      for (; (uVar5 & uVar6) == 0; uVar6 = uVar6 << 1) {
        uVar14 = uVar14 + 4;
      }
    } while( true );
  }
LAB_100045aa:
  puVar1 = _DAT_10004740;
  uVar14 = *(uint *)(uVar3 + 8);
  uVar4 = *(uint *)(uVar14 + 4) & 0xfffffffc;
  if ((uVar15 <= uVar4) && (uVar6 = uVar4 - uVar15, 0xf < (int)uVar6)) goto LAB_100046d2;
  uVar6 = uVar14 + uVar4;
  if (*_DAT_10004740 == 0xffffffff) {
    uStack_30 = uVar15 + *_DAT_10004744 + 0x10;
  }
  else {
    uStack_30 = uVar15 + *_DAT_10004744 + _DAT_10004748 & 0xfffff000;
  }
  uVar5 = FUN_10004bd0(param_1,uStack_30);
  puVar2 = _DAT_1000495c;
  puVar16 = _DAT_1000474c;
  if (uVar5 == 0xffffffff) {
LAB_100047e8:
    uVar5 = *(uint *)(uVar3 + 8);
    uStack_30 = *(uint *)(uVar5 + 4);
  }
  else {
    if (uVar5 < uVar6) {
      if (uVar14 == uVar3) {
        uVar9 = uStack_30 + *_DAT_1000495c;
        *_DAT_1000495c = uVar9;
        puVar16 = puVar2;
        goto LAB_1000461a;
      }
      goto LAB_100047e8;
    }
    uVar9 = uStack_30 + *_DAT_1000474c;
    *_DAT_1000474c = uVar9;
    if ((uVar6 == uVar5) && ((uVar6 & 0xfff) == 0)) {
      uVar5 = *(uint *)(uVar3 + 8);
      uStack_30 = uStack_30 + uVar4 | 1;
      *(uint *)(uVar5 + 4) = uStack_30;
    }
    else {
LAB_1000461a:
      if (*puVar1 == 0xffffffff) {
        *puVar1 = uVar5;
      }
      else {
        *puVar16 = (uVar5 - uVar6) + uVar9;
      }
      uVar6 = uVar5 & 7;
      if ((uVar5 & 7) == 0) {
        uVar9 = -(uStack_30 + uVar5) & 0xfff;
        iVar10 = FUN_10004bd0(param_1,uVar9);
        if (iVar10 == -1) {
          uVar9 = 0;
        }
        else {
LAB_10004668:
          uStack_30 = (iVar10 - uVar5) + uVar9;
        }
      }
      else {
        uVar5 = (uVar5 - uVar6) + 8;
        uVar9 = (_DAT_10004750 - uVar6) - (uStack_30 + uVar5) & 0xfff;
        iVar10 = FUN_10004bd0(param_1,uVar9);
        if (iVar10 != -1) goto LAB_10004668;
        uStack_30 = ((uVar6 - 8) + uStack_30 + uVar5) - uVar5;
        uVar9 = 0;
      }
      uVar9 = *puVar16 + uVar9;
      *puVar16 = uVar9;
      *(uint *)(uVar3 + 8) = uVar5;
      uStack_30 = uStack_30 | 1;
      *(uint *)(uVar5 + 4) = uStack_30;
      if (uVar14 != uVar3) {
        if (uVar4 < 0x10) {
          *(undefined4 *)(uVar5 + 4) = 1;
          goto LAB_100047fc;
        }
        uVar4 = uVar4 - 0xc & 0xfffffff8;
        *(uint *)(uVar14 + 4) = *(uint *)(uVar14 + 4) & 1 | uVar4;
        *(undefined4 *)(uVar14 + uVar4 + 4) = 5;
        *(undefined4 *)(uVar14 + uVar4 + 8) = 5;
        if (uVar4 < 0x10) {
          uStack_30 = *(uint *)(uVar5 + 4);
        }
        else {
          FUN_10004c90(param_1,uVar14 + 8);
          uVar5 = *(uint *)(uVar3 + 8);
          uVar9 = *puVar16;
          uStack_30 = *(uint *)(uVar5 + 4);
        }
      }
    }
    if (*_DAT_10004754 < uVar9) {
      *_DAT_10004754 = uVar9;
    }
    if (*_DAT_10004758 < uVar9) {
      *_DAT_10004758 = uVar9;
    }
  }
  uVar6 = (uStack_30 & 0xfffffffc) - uVar15;
  if ((uVar15 <= (uStack_30 & 0xfffffffc)) && (uVar14 = uVar5, 0xf < (int)uVar6)) {
LAB_100046d2:
    *(uint *)(uVar14 + 4) = uVar15 | 1;
    *(uint *)(uVar3 + 8) = uVar14 + uVar15;
    *(uint *)(uVar14 + uVar15 + 4) = uVar6 | 1;
    FUN_10004bc0(param_1);
    return (int *)(uVar14 + 8);
  }
LAB_100047fc:
  FUN_10004bc0(param_1);
  return (int *)0x0;
}

// FUNC 0x10004964  memcmp

/* Byte compare */

int memcmp(int *param_1,int *param_2,uint param_3)

{
  int iVar1;
  bool bVar2;
  
  if (3 < param_3) {
    if ((((uint)param_1 | (uint)param_2) & 3) != 0) goto LAB_1000498a;
    do {
      if (*param_1 != *param_2) goto LAB_1000498a;
      param_3 = param_3 - 4;
      param_1 = param_1 + 1;
      param_2 = param_2 + 1;
    } while (3 < param_3);
  }
  if (param_3 == 0) {
    return 0;
  }
LAB_1000498a:
  iVar1 = 0;
  do {
    if ((uint)*(byte *)((int)param_1 + iVar1) != (uint)*(byte *)((int)param_2 + iVar1)) {
      return (uint)*(byte *)((int)param_1 + iVar1) - (uint)*(byte *)((int)param_2 + iVar1);
    }
    bVar2 = param_3 - 1 != iVar1;
    iVar1 = iVar1 + 1;
  } while (bVar2);
  return 0;
}

// FUNC 0x100049ac  memcpy

/* Forward copy */

void memcpy(undefined4 *param_1,undefined4 *param_2,uint param_3)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  undefined4 uVar7;
  bool bVar8;
  
  uVar4 = param_3;
  if (0xf < param_3) {
    uVar6 = ((uint)param_2 | (uint)param_1) & 3;
    if ((((uint)param_2 | (uint)param_1) & 3) != 0) {
      iVar5 = param_3 - 1;
      goto LAB_10004a26;
    }
    uVar4 = param_3 - 0x10 >> 4;
    puVar1 = param_1;
    puVar3 = param_2;
    do {
      uVar7 = puVar3[1];
      *puVar1 = *puVar3;
      puVar1[1] = uVar7;
      uVar7 = puVar3[3];
      puVar1[2] = puVar3[2];
      puVar1[3] = uVar7;
      puVar3 = puVar3 + 4;
      bVar8 = puVar1 != param_1 + uVar4 * 4;
      puVar1 = puVar1 + 4;
    } while (bVar8);
    iVar5 = uVar4 + 1;
    param_2 = param_2 + iVar5 * 4;
    uVar4 = param_3 & 0xf;
    param_1 = param_1 + iVar5 * 4;
    if ((param_3 & 0xc) != 0) {
      do {
        *(undefined4 *)((int)param_1 + uVar6) = *(undefined4 *)((int)param_2 + uVar6);
        uVar6 = uVar6 + 4;
      } while (3 < uVar4 - uVar6);
      iVar5 = (uVar4 - 4 >> 2) + 1;
      param_1 = param_1 + iVar5;
      param_2 = param_2 + iVar5;
      uVar4 = param_3 & 3;
    }
  }
  iVar5 = uVar4 - 1;
  if (uVar4 == 0) {
    return;
  }
LAB_10004a26:
  iVar2 = 0;
  do {
    *(undefined1 *)((int)param_1 + iVar2) = *(undefined1 *)((int)param_2 + iVar2);
    bVar8 = iVar5 != iVar2;
    iVar2 = iVar2 + 1;
  } while (bVar8);
  return;
}

// FUNC 0x10004a50  memmove

/* Overlapping copy */

void memmove(undefined4 *param_1,undefined4 *param_2,uint param_3)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  uint uVar6;
  uint uVar7;
  bool bVar8;
  
  if ((param_2 < param_1) && (param_1 < (undefined4 *)((int)param_2 + param_3))) {
    iVar2 = param_3 - 1;
    if (param_3 == 0) {
      return;
    }
    do {
      *(undefined1 *)((int)param_1 + iVar2) = *(undefined1 *)((int)param_2 + iVar2);
      bVar8 = iVar2 != 0;
      iVar2 = iVar2 + -1;
    } while (bVar8);
    return;
  }
  uVar6 = param_3;
  if (0xf < param_3) {
    uVar7 = ((uint)param_2 | (uint)param_1) & 3;
    if ((((uint)param_2 | (uint)param_1) & 3) != 0) {
      iVar2 = param_3 - 1;
      goto LAB_10004a80;
    }
    uVar6 = param_3 - 0x10 >> 4;
    puVar4 = param_1;
    puVar5 = param_2;
    do {
      *puVar4 = *puVar5;
      puVar4[1] = puVar5[1];
      puVar4[2] = puVar5[2];
      puVar1 = puVar5 + 3;
      puVar5 = puVar5 + 4;
      puVar4[3] = *puVar1;
      bVar8 = puVar4 != param_1 + uVar6 * 4;
      puVar4 = puVar4 + 4;
    } while (bVar8);
    iVar2 = uVar6 + 1;
    param_2 = param_2 + iVar2 * 4;
    uVar6 = param_3 & 0xf;
    param_1 = param_1 + iVar2 * 4;
    if ((param_3 & 0xc) != 0) {
      do {
        *(undefined4 *)((int)param_1 + uVar7) = *(undefined4 *)((int)param_2 + uVar7);
        uVar7 = uVar7 + 4;
      } while (3 < uVar6 - uVar7);
      iVar2 = (uVar6 - 4 >> 2) + 1;
      param_1 = param_1 + iVar2;
      param_2 = param_2 + iVar2;
      uVar6 = param_3 & 3;
    }
  }
  iVar2 = uVar6 - 1;
  if (uVar6 == 0) {
    return;
  }
LAB_10004a80:
  iVar3 = 0;
  do {
    *(undefined1 *)((int)param_1 + iVar3) = *(undefined1 *)((int)param_2 + iVar3);
    bVar8 = iVar2 != iVar3;
    iVar3 = iVar3 + 1;
  } while (bVar8);
  return;
}

// FUNC 0x10004b08  memset

/* Byte fill */

void memset(undefined4 *param_1,undefined1 param_2,uint param_3)

{
  uint uVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  uint uVar4;
  bool bVar5;
  
  if (((uint)param_1 & 3) != 0) {
    uVar1 = param_3 - 1;
    puVar2 = param_1;
    if (param_3 == 0) {
      return;
    }
    while( true ) {
      param_1 = (undefined4 *)((int)param_1 + 1);
      *(undefined1 *)puVar2 = param_2;
      param_3 = uVar1;
      if (((uint)param_1 & 3) == 0) break;
      bVar5 = uVar1 == 0;
      uVar1 = uVar1 - 1;
      puVar2 = (undefined4 *)((int)puVar2 + 1);
      if (bVar5) {
        return;
      }
    }
  }
  uVar1 = param_3;
  if (3 < param_3) {
    uVar3 = CONCAT22(CONCAT11(param_2,param_2),CONCAT11(param_2,param_2));
    if (0xf < param_3) {
      uVar4 = param_3 - 0x10 >> 4;
      puVar2 = param_1;
      do {
        *puVar2 = uVar3;
        puVar2[1] = uVar3;
        puVar2[2] = uVar3;
        puVar2[3] = uVar3;
        puVar2 = puVar2 + 4;
      } while (puVar2 != param_1 + uVar4 * 4 + 4);
      uVar1 = param_3 & 0xf;
      param_1 = param_1 + (uVar4 + 1) * 4;
      uVar4 = param_3 & 0xc;
      param_3 = uVar1;
      if (uVar4 == 0) goto LAB_10004b90;
    }
    uVar1 = param_3 - 4 >> 2;
    puVar2 = param_1;
    do {
      *puVar2 = uVar3;
      puVar2 = puVar2 + 1;
    } while (puVar2 != param_1 + uVar1 + 1);
    param_1 = param_1 + uVar1 + 1;
    uVar1 = param_3 & 3;
  }
LAB_10004b90:
  if (uVar1 != 0) {
    puVar2 = (undefined4 *)((int)param_1 + uVar1);
    do {
      *(undefined1 *)param_1 = param_2;
      param_1 = (undefined4 *)((int)param_1 + 1);
    } while (puVar2 != param_1);
  }
  return;
}

// FUNC 0x10004bb0  FUN_10004bb0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10004bb0(void)

{
  null_callback_1(_DAT_10004bbc);
  return;
}

// FUNC 0x10004bc0  FUN_10004bc0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10004bc0(void)

{
  null_callback_2(_DAT_10004bcc);
  return;
}

// FUNC 0x10004bd0  FUN_10004bd0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10004bd0(int *param_1,undefined4 param_2)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = _DAT_10004bf0;
  *_DAT_10004bf0 = 0;
  iVar2 = heap_alloc(param_2);
  if ((iVar2 == -1) && (*piVar1 != 0)) {
    *param_1 = *piVar1;
  }
  return;
}

// FUNC 0x10004bf4  FUN_10004bf4

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_10004bf4(undefined4 param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  
  FUN_10004bb0();
  iVar2 = _DAT_10004c80;
  uVar4 = *(uint *)(*(int *)(_DAT_10004c80 + 8) + 4) & 0xfffffffc;
  iVar3 = ((uVar4 - param_2) + _DAT_10004c84 >> 0xc) - 1;
  if ((_DAT_10004c84 + 0x11 <= iVar3 * 0x1000) &&
     (iVar1 = FUN_10004bd0(param_1,0), iVar1 == *(int *)(iVar2 + 8) + uVar4)) {
    iVar1 = FUN_10004bd0(param_1,iVar3 * -0x1000);
    if (iVar1 != -1) {
      *(uint *)(*(int *)(iVar2 + 8) + 4) = uVar4 + iVar3 * -0x1000 | 1;
      *_DAT_10004c88 = *_DAT_10004c88 + iVar3 * -0x1000;
      FUN_10004bc0(param_1);
      return 1;
    }
    iVar3 = FUN_10004bd0(param_1,0);
    iVar2 = *(int *)(iVar2 + 8);
    uVar4 = iVar3 - iVar2;
    if (0xf < (int)uVar4) {
      *_DAT_10004c88 = iVar3 - *_DAT_10004c8c;
      *(uint *)(iVar2 + 4) = uVar4 | 1;
    }
  }
  FUN_10004bc0(param_1);
  return 0;
}

// FUNC 0x10004c90  FUN_10004c90

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10004c90(undefined4 param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  int *piVar7;
  uint uVar8;
  int iVar9;
  int *piVar10;
  uint *puVar11;
  
  if (param_2 == 0) {
    return;
  }
  FUN_10004bb0();
  iVar1 = _DAT_10004e40;
  piVar2 = (int *)(param_2 + -8);
  uVar8 = *(uint *)(param_2 + -4);
  uVar3 = uVar8 & 0xfffffffe;
  puVar11 = (uint *)((int)piVar2 + uVar3);
  uVar5 = puVar11[1] & 0xfffffffc;
  if (*(uint **)(_DAT_10004e40 + 8) == puVar11) {
    uVar3 = uVar3 + uVar5;
    if ((uVar8 & 1) == 0) {
      iVar9 = *piVar2;
      piVar2 = (int *)((int)piVar2 - iVar9);
      iVar6 = piVar2[2];
      uVar3 = uVar3 + iVar9;
      iVar9 = piVar2[3];
      *(int *)(iVar6 + 0xc) = iVar9;
      *(int *)(iVar9 + 8) = iVar6;
    }
    piVar2[1] = uVar3 | 1;
    puVar11 = _DAT_10004e48;
    *(int **)(iVar1 + 8) = piVar2;
    if (*puVar11 <= uVar3) {
      FUN_10004bf4(param_1,*_DAT_10004e4c);
    }
    goto LAB_10004d38;
  }
  puVar11[1] = uVar5;
  if ((uVar8 & 1) == 0) {
    iVar9 = *piVar2;
    piVar2 = (int *)((int)piVar2 - iVar9);
    uVar3 = uVar3 + iVar9;
    iVar9 = piVar2[2];
    if (iVar9 == iVar1 + 8) {
      if ((*(uint *)((int)puVar11 + uVar5 + 4) & 1) == 0) {
        uVar8 = puVar11[2];
        uVar4 = puVar11[3];
        uVar3 = uVar3 + uVar5;
        *(uint *)(uVar8 + 0xc) = uVar4;
        *(uint *)(uVar4 + 8) = uVar8;
        piVar2[1] = uVar3 | 1;
        *(uint *)((int)piVar2 + uVar3) = uVar3;
      }
      else {
        piVar2[1] = uVar3 | 1;
        *puVar11 = uVar3;
      }
      goto LAB_10004d38;
    }
    iVar6 = piVar2[3];
    *(int *)(iVar9 + 0xc) = iVar6;
    *(int *)(iVar6 + 8) = iVar9;
    if ((*(uint *)((int)puVar11 + uVar5 + 4) & 1) != 0) goto LAB_10004d0e;
LAB_10004cea:
    uVar8 = puVar11[2];
    uVar3 = uVar3 + uVar5;
    if (uVar8 == _DAT_10004e44) {
      *(int **)(uVar8 + 0xc) = piVar2;
      *(int **)(uVar8 + 8) = piVar2;
      piVar2[3] = uVar8;
      piVar2[2] = uVar8;
      piVar2[1] = uVar3 | 1;
      *(uint *)((int)piVar2 + uVar3) = uVar3;
      goto LAB_10004d38;
    }
    uVar5 = puVar11[3];
    *(uint *)(uVar8 + 0xc) = uVar5;
    *(uint *)(uVar5 + 8) = uVar8;
    piVar2[1] = uVar3 | 1;
    *(uint *)((int)piVar2 + uVar3) = uVar3;
  }
  else {
    if ((*(uint *)((int)puVar11 + uVar5 + 4) & 1) == 0) goto LAB_10004cea;
LAB_10004d0e:
    piVar2[1] = uVar3 | 1;
    *puVar11 = uVar3;
  }
  if (uVar3 < 0x200) {
    *(uint *)(iVar1 + 4) = 1 << (uVar3 >> 5 & 0xff) | *(uint *)(iVar1 + 4);
    iVar1 = (uVar3 & 0xfffffff8) + iVar1;
    iVar9 = *(int *)(iVar1 + 8);
    piVar2[3] = iVar1;
    piVar2[2] = iVar9;
    *(int **)(iVar1 + 8) = piVar2;
    *(int **)(iVar9 + 0xc) = piVar2;
  }
  else {
    uVar5 = uVar3 >> 9;
    if (uVar5 < 5) {
      iVar6 = (uVar3 >> 6) + 0x38;
      iVar9 = ((uVar3 >> 6) + 0x39) * 8;
    }
    else if (uVar5 < 0x15) {
      iVar6 = uVar5 + 0x5b;
      iVar9 = (uVar5 + 0x5c) * 8;
    }
    else if (uVar5 < 0x55) {
      iVar6 = (uVar3 >> 0xc) + 0x6e;
      iVar9 = ((uVar3 >> 0xc) + 0x6f) * 8;
    }
    else if (uVar5 < 0x155) {
      iVar6 = (uVar3 >> 0xf) + 0x77;
      iVar9 = ((uVar3 >> 0xf) + 0x78) * 8;
    }
    else if (_DAT_10004e50 < uVar5) {
      iVar6 = 0x7e;
      iVar9 = 0x3f8;
    }
    else {
      iVar6 = (uVar3 >> 0x12) + 0x7c;
      iVar9 = ((uVar3 >> 0x12) + 0x7d) * 8;
    }
    piVar7 = *(int **)(iVar1 + iVar9);
    piVar10 = (int *)(iVar1 + iVar9) + -2;
    if (piVar10 == piVar7) {
      *(uint *)(iVar1 + 4) = 1 << (iVar6 >> 2 & 0xffU) | *(uint *)(iVar1 + 4);
    }
    else {
      do {
        if ((piVar7[1] & 0xfffffffcU) <= uVar3) break;
        piVar7 = (int *)piVar7[2];
      } while (piVar10 != piVar7);
      piVar10 = (int *)piVar7[3];
    }
    piVar2[3] = (int)piVar10;
    piVar2[2] = (int)piVar7;
    piVar10[2] = (int)piVar2;
    piVar7[3] = (int)piVar2;
  }
LAB_10004d38:
  FUN_10004bc0(param_1);
  return;
}

// FUNC 0x10004e54  null_callback_1

/* Empty callback used by the libc stubs */

void null_callback_1(void)

{
  return;
}

// FUNC 0x10004e58  null_callback_2

/* Empty callback used by the libc stubs */

void null_callback_2(void)

{
  return;
}

// FUNC 0x10004e60  flash_program_page_veneer

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Veneer to flash_program_page at 0x10000450 */

void flash_program_page_veneer(undefined4 param_1)

{
                    /* WARNING: Could not recover jumptable at 0x10004e68. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*_DAT_10004e6c)(param_1);
  return;
}

// FUNC 0x10004e70  flash_controller_init_veneer

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Veneer to flash_controller_init at 0x100003B8 */

void flash_controller_init_veneer(undefined4 param_1)

{
                    /* WARNING: Could not recover jumptable at 0x10004e78. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*_DAT_10004e7c)(param_1);
  return;
}

// FUNC 0x10004e80  flash_erase_sector_veneer

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Veneer to flash_erase_sector at 0x100003D8 */

void flash_erase_sector_veneer(undefined4 param_1)

{
                    /* WARNING: Could not recover jumptable at 0x10004e88. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*_DAT_10004e8c)(param_1);
  return;
}

// FUNC 0x10004e90  flash_exit_powerdown_veneer

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Veneer to flash_exit_powerdown at 0x1000015C */

void flash_exit_powerdown_veneer(undefined4 param_1)

{
                    /* WARNING: Could not recover jumptable at 0x10004e98. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*_DAT_10004e9c)(param_1);
  return;
}

// FUNC 0x10004ea0  flash_begin_veneer

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Veneer to flash_begin at 0x10000120 */

void flash_begin_veneer(undefined4 param_1)

{
                    /* WARNING: Could not recover jumptable at 0x10004ea8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*_DAT_10004eac)(param_1);
  return;
}

// FUNC 0x10004eb0  flash_end_veneer

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Veneer to flash_end at 0x10000134 */

void flash_end_veneer(undefined4 param_1)

{
                    /* WARNING: Could not recover jumptable at 0x10004eb8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*_DAT_10004ebc)(param_1);
  return;
}

// FUNC 0x10004ec0  flash_status_veneer

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Veneer to flash_status at 0x1000014C */

void flash_status_veneer(undefined4 param_1)

{
                    /* WARNING: Could not recover jumptable at 0x10004ec8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*_DAT_10004ecc)(param_1);
  return;
}

