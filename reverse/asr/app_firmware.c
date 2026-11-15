/*
 * ASR5601S ASR5601S application reconstruction - reconstructed from the SWD dump.
 * Image base 0x10048000, Ghidra 11.3.1, language ARM:LE:32:Cortex.
 * 496 functions, address order.
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
  if ((*flash_pwr_ctrl & 2) == 0) {
    *flash_pwr_ctrl = 2;
  }
  return;
}

// FUNC 0x10000134  flash_end

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Releases the flash controller and clears its state */

void flash_end(void)

{
  int *piVar1;
  
  piVar1 = flash_pwr_ctrl_2;
  if (*flash_pwr_ctrl_2 << 0x1e < 0) {
    *flash_pwr_ctrl_2 = 3;
    *piVar1 = 0;
  }
  return;
}

// FUNC 0x1000014c  flash_status

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Returns the flash busy/ready flag */

uint flash_status(void)

{
  return ~(*flash_pwr_ctrl_3 >> 1) & 1;
}

// FUNC 0x1000015c  flash_exit_powerdown

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Leaves flash deep power-down */

void flash_exit_powerdown(void)

{
  uint *puVar1;
  uint uVar2;
  
  puVar1 = flash_pwr_ctrl_4;
  uVar2 = *flash_pwr_ctrl_4;
  if ((uVar2 & 2) == 0) {
    *flash_pwr_ctrl_4 = 2;
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
  
  uVar2 = *(uint *)(flash_reg_base + 8);
  iVar1 = flash_delay_loop;
  do {
    if ((uVar2 & 0x20) == 0) {
      return uVar2 & 0x20;
    }
    iVar1 = iVar1 + -1;
    uVar2 = *(uint *)(flash_reg_base + 8);
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
  uVar2 = *(uint *)(flash_reg_base_2 + 8);
  do {
    if ((uVar2 & 0x40) == 0) {
      return uVar2 & 0x40;
    }
    iVar1 = iVar1 + -1;
    uVar2 = *(uint *)(flash_reg_base_2 + 8);
  } while (iVar1 != 0);
  return 1;
}

// FUNC 0x100001d4  flash_run_command

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Strobes the flash command register */

void flash_run_command(void)

{
  int iVar1;
  
  iVar1 = flash_reg_base_3;
  *(undefined4 *)(flash_reg_base_3 + 0xc) = flash_cmd_word;
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
  
  puVar1 = flash_reg_base_4;
  uVar2 = *flash_reg_base_4;
  *flash_reg_base_4 = (uVar2 & 0xfffffffd) + 2;
  *puVar1 = uVar2 & 0xfffffffd;
  return 0;
}

// FUNC 0x10000200  flash_set_read_mode

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Configures the flash controller for reads */

undefined4 flash_set_read_mode(void)

{
  uint *puVar1;
  
  puVar1 = flash_reg_base_5;
  flash_reg_base_5[5] = flash_mode_word;
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
  
  puVar1 = flash_reg_base_6;
  flash_reg_base_6[5] = flash_mode_word_2;
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
  iVar2 = flash_timing_magic;
  piVar1 = flash_reg_base_7;
  iVar3 = *lit_ptr_ram_20000ef4;
  if (*lit_ptr_ram_20000ef4 == 0) {
    iVar3 = flash_window_default;
  }
  *flash_reg_base_7 = iVar3;
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
  piVar1[0xc] = flash_cfg_limit;
  *flash_window_size = 0x200;
  return;
}

// FUNC 0x100003b8  flash_controller_init

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Initializes the flash controller after reset */

undefined4 flash_controller_init(void)

{
  *lit_ptr_ram_20000ef4_03d4 = 0;
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
  puVar2 = flash_addr_ptr;
  iVar1 = flash_reg_base_8;
  *(undefined4 *)(flash_reg_base_8 + 0x14) = 0x106;
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
    iVar2 = flash_reg_base_9;
    *(undefined4 *)(flash_reg_base_9 + 0x14) = 0x106;
    flash_run_command();
    puVar3 = flash_addr_ptr_2;
    *flash_addr_ptr_2 = 1;
    delay_loop(10);
    flash_wait_ready();
    flash_set_write_mode();
    uVar5 = uVar6 - 0x20;
    *(undefined4 *)(iVar2 + 0x14) = flash_const_1002502;
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
  (*lit_fn_memcpy_plus_1)(param_1);
  return;
}

// FUNC 0x10000730  rom_memset

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Veneer into the ROM fill routine */

void rom_memset(undefined4 param_1)

{
                    /* WARNING: Could not recover jumptable at 0x10000738. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*lit_fn_memset_plus_1)(param_1);
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
      uVar4 = uVar2 - bitspread_test & ~uVar2 & bitspread_test << 7;
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

// FUNC 0x100007c8  aeabi_nop

void aeabi_nop(void)

{
  return;
}

// FUNC 0x100007dc  aeabi_concat

undefined8 aeabi_concat(undefined4 param_1,undefined4 param_2)

{
  return CONCAT44(param_2,param_1);
}

// FUNC 0x100007f0  aeabi_concat_2

undefined8 aeabi_concat_2(undefined4 param_1,undefined4 param_2)

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
  *(undefined4 *)(misc_const_e000e104 + 0x7c) = 0xffffffff;
  *(undefined4 *)(lit_sys_scb_cpuid + 8) = param_1;
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
  
  uVar1 = lit_ptr_ram_20000e84;
  iVar3 = kv_read(3,lit_ptr_ram_20000e84,0x6c);
  uVar2 = lit_ptr_ram_20000e68;
  if (iVar3 == 0) {
    ota_image_verify(uVar1,lit_ptr_ram_20000e68);
  }
  boot_printf(lit_fn_flash_status_veneer_plus_cf);
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
  uart_init(uart1_base,0x1c200);
  uart_pinmux_select();
  puVar1 = lit_ptr_ram_20000e68_0c48;
  memset(lit_ptr_ram_20000e68_0c48,0,0x1c);
  iVar2 = kv_store_init(0);
  if (iVar2 == 0) {
    kv_read(2,puVar1,0x1c);
  }
  image_header_build(*puVar1,puVar1[2],puVar1[3]);
  boot_printf(lit_fn_flash_status_veneer_plus_27,lit_boot_10000100);
  iVar2 = boot_reason_get();
  uVar3 = lit_fn_flash_status_veneer_plus_44;
  if ((((iVar2 != 2) && (uVar3 = lit_fn_flash_status_veneer_plus_5d, iVar2 != 3)) && (uVar3 = lit_fn_flash_status_veneer_plus_78, iVar2 != 1))
     && (uVar3 = lit_fn_flash_status_veneer_plus_ac, iVar2 == 0)) {
    uVar3 = lit_fn_flash_status_veneer_plus_95;
  }
  boot_printf(uVar3);
  boot_printf(lit_fn_flash_status_veneer_plus_c4);
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
  
  uVar1 = *lit_ptr_ram_20000620;
  if (lit_ptr_ram_20011c00 < uVar1 + param_1) {
    uVar1 = 0xffffffff;
  }
  else {
    *lit_ptr_ram_20000620 = uVar1 + param_1;
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
  
  iVar1 = aeabi_uidivmod(*lit_ptr_ram_20000624,clk_1mhz);
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
    pcStack_48 = lit_fn_call_app_reset_vector_plus_b;
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
        iVar2 = aeabi_concat_2();
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
  vprintf_core(lit_fn_ulltoa_plus_bf,&uStack_20,0xffffffff,param_1,puStack_1c,param_2);
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
  for (iVar1 = 0; (uint)(lit_ptr_ram_20000000 + iVar1) < lit_ptr_ram_20000620_153c; iVar1 = iVar1 + 4) {
    *(undefined4 *)(lit_ptr_ram_20000000 + iVar1) = *(undefined4 *)(lit_fn_flash_begin + iVar1);
  }
  for (iVar1 = 0; puVar2 = lit_ptr_ram_20000e68_154c, (uint)(lit_ptr_ram_20000620_1544 + iVar1) < lit_ptr_ram_20000e68_1548;
      iVar1 = iVar1 + 4) {
    *(undefined4 *)(lit_ptr_ram_20000620_1544 + iVar1) = *(undefined4 *)(lit_fn_flash_status_veneer_plus_528 + iVar1);
  }
  for (; puVar2 < lit_ptr_ram_200015e0; puVar2 = puVar2 + 1) {
    *puVar2 = 0;
  }
  *flash_pwr_ctrl_5 = 1;
  *clk_cfg_a = 2;
  *clk_cfg_b = 2;
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
  pbVar4 = lit_ptr_ram_20030010;
  do {
    bVar1 = *pbVar4;
    pbVar4 = pbVar4 + 1;
    cVar5 = '\b';
    uVar2 = uVar3 ^ (uint)bVar1 << 0x18;
    do {
      uVar3 = uVar2 << 1;
      if ((int)uVar2 < 0) {
        uVar3 = uVar3 ^ crc32_poly;
      }
      cVar5 = cVar5 + -1;
      uVar2 = uVar3;
    } while (cVar5 != '\0');
  } while (pbVar4 != lit_ptr_ram_2003001c);
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
  
  piVar1 = lit_ptr_ram_20030000;
  uVar2 = *syscfg_clock_sel >> 0x18 & 1;
  if (*lit_ptr_ram_20030000 == 1) {
    if (uVar2 == 0) {
      *syscfg_clock_sel = *syscfg_clock_sel | 0x1000000;
      piVar1[1] = 1;
      piVar1[2] = 1;
      return;
    }
    iVar3 = 2;
  }
  else if (*lit_ptr_ram_20030000 == 2) {
    if (uVar2 == 0) {
LAB_100015da:
      *syscfg_clock_sel = *syscfg_clock_sel | 0x1000000;
      *piVar1 = 1;
      piVar1[1] = 0;
      piVar1[2] = 0;
      return;
    }
    iVar3 = 3;
    *lit_ptr_ram_20030000 = 1;
  }
  else {
    if (uVar2 == 0) goto LAB_100015da;
    *syscfg_clock_sel = *syscfg_clock_sel | 0x1000000;
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
  return *(undefined4 *)(lit_ptr_ram_20030000_1610 + 4);
}

// FUNC 0x10001614  image_header_build

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Stores base, size and CRC-32 in the image header descriptor */

void image_header_build(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = lit_ptr_ram_20030000_1628;
  *(undefined4 *)(lit_ptr_ram_20030000_1628 + 0x10) = param_1;
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
  
  if (((((*syscfg_boot_mode << 8) >> 0x1e != 0) || ((*syscfg_image_flags & 0xf) == 0)) &&
      ((*syscfg_boot_mode >> 0x16 & 3) != 1)) && ((*syscfg_boot_mode >> 0x16 & 3) != 2)) {
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
  uVar3 = misc_const_2e408c04;
  if (iVar1 << 1 < 0) {
    uVar3 = misc_const_6e408c04;
  }
  reg_write_indexed(1,uVar3);
  uVar2 = reg_read_indexed(1);
  reg_write_indexed(1,lit_mask_dfffffff & uVar2);
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
  uVar3 = misc_const_2e408c04;
  if (iVar1 << 1 < 0) {
    uVar3 = misc_const_6e408c04;
  }
  reg_write_indexed(1,uVar3);
  uVar2 = reg_read_indexed(1);
  reg_write_indexed(1,lit_mask_dfffffff & uVar2);
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
  iVar1 = lit_ptr_ram_20030000_1784;
  if ((1 < uVar2) && (uVar2 != 0xff)) {
    return;
  }
  iVar3 = *(int *)(lit_ptr_ram_20030000_1784 + 0xc);
  if (iVar3 == misc_const_27da826e) {
    uVar4 = 0;
  }
  else {
    if (iVar3 == misc_const_6932842f) goto LAB_10001766;
    if (iVar3 != misc_const_efa576ca) {
      if (uVar2 == 0) {
        *(int *)(lit_ptr_ram_20030000_1784 + 0xc) = misc_const_27da826e;
      }
      else if (uVar2 == 1) {
        *(int *)(lit_ptr_ram_20030000_1784 + 0xc) = misc_const_6932842f;
      }
      else {
        *(int *)(lit_ptr_ram_20030000_1784 + 0xc) = misc_const_efa576ca;
      }
      uart_pins_config();
      return;
    }
    uVar4 = 0xff;
  }
  *(undefined4 *)(lit_ptr_ram_20030000_1784 + 4) = uVar4;
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
    if (*lit_ptr_ram_20000624_17c8 < param_1 << 4) {
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
  
  puVar1 = iomux_func_sel_0;
  if (param_1 == 0x40000000) {
    uVar2 = misc_const_ffff00ff & *iomux_func_sel_0;
    uVar3 = 0x1100;
  }
  else if (param_1 == uart1_base_2) {
    uVar2 = mask_clear_bits16_23 & *iomux_func_sel_0;
    uVar3 = 0x110000;
  }
  else {
    if (param_1 != uart2_base) goto LAB_100017ec;
    uVar2 = *iomux_func_sel_1 & 0xffffff00;
    uVar3 = 0x11;
    puVar1 = iomux_func_sel_1;
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
    *lit_sys_nvic_iser = 8;
  }
  else if (param_1 == uart1_base_2) {
    *lit_sys_nvic_iser = 4;
  }
  else if (param_1 == uart2_base) {
    *lit_sys_nvic_iser = 0x10;
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
  *(undefined4 *)(param_1 * 4 + syscfg_regs) = param_2;
  return;
}

// FUNC 0x100018c4  reg_read_indexed

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Reads a 32-bit register selected by index */

undefined4 reg_read_indexed(int param_1)

{
  return *(undefined4 *)(param_1 * 4 + syscfg_regs_2);
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
  return param_1 * 0x14 + lit_fn_flash_status_veneer_plus_138;
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
  iVar3 = lit_fn_flash_status_veneer_plus_138_197c;
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
        uVar3 = uVar3 ^ crc_const_1021;
      }
      uVar4 = uVar3 & 0xffff;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
  }
  boot_printf(lit_fn_flash_status_veneer_plus_278,uVar4);
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
      uVar2 = flash_const_25d8;
    }
    else if (((uVar3 & 0x7fff) == 0) && (0x7000 < (int)uVar5)) {
      uVar4 = 0x8000;
      uVar2 = flash_const_2552;
    }
    else {
      uVar4 = 0x1000;
      uVar2 = fmt_const_2520;
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
  if (((*(uint *)(param_1 + 4) & 0xffffff00) != image_tag_pattern) && (*(int *)(param_1 + 0x10) == 0)) {
    boot_printf(lit_fn_flash_status_veneer_plus_28c,*(undefined4 *)(param_1 + 0x14),*(undefined4 *)(param_1 + 0x18));
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
  *exec_region_attr = lit_code_10048000;
  *exec_region_base = param_1 & 0xfffffc00;
  *exec_region_dst = param_2 + lit_mask_000003ff & misc_const_fffc00 | 0x1000000;
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
  
  uVar1 = lit_fn_flash_status_veneer_plus_2b3;
  uVar2 = param_1[1];
  if (((uVar2 & 0xffffff00) == image_tag_pattern_2) && ((uVar2 & 0xff) != 0)) {
    if ((uVar2 & 0xff) < 3) {
      param_1[1] = uVar2 + 1;
      boot_printf(lit_fn_flash_status_veneer_plus_2d1);
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
  
  uVar2 = lit_fn_flash_status_veneer_plus_2e8;
  if (*(int *)(param_1 + 0x40) == 1) {
LAB_10001ebc:
    boot_printf(uVar2);
  }
  else {
    uVar4 = *(uint *)(param_1 + 0x44);
    if (uVar4 - 2 < 2) {
      boot_printf(lit_fn_flash_status_veneer_plus_30b);
      uVar2 = lit_fn_flash_status_veneer_plus_320;
      if (*(int *)(param_1 + 0x44) == 3) {
        flash_erase_range(lit_code_10048000_1ed0,*(undefined4 *)(param_1 + 0x5c));
        boot_printf(uVar2);
        boot_printf(lit_fn_flash_status_veneer_plus_331);
        iVar1 = xz_decompress_mem(*(undefined4 *)(param_1 + 0x48),lit_code_10048000_1ed0,
                                  *(undefined4 *)(param_1 + 0x5c));
        if (iVar1 != 0) {
          boot_printf(lit_fn_flash_status_veneer_plus_38c);
          DataSynchronizationBarrier(0xf);
          *(undefined4 *)(lit_sys_scb_cpuid_1edc + 0xc) = flash_cmd_word_2;
          DataSynchronizationBarrier(0xf);
          do {
                    /* WARNING: Do nothing block with infinite loop */
          } while( true );
        }
      }
      else {
        flash_erase_range(lit_code_10048000_1ed0,*(undefined4 *)(param_1 + 0x5c));
        boot_printf(uVar2);
        boot_printf(lit_fn_flash_status_veneer_plus_345);
        iStack_120 = *(int *)(param_1 + 0x48);
        uVar4 = *(uint *)(param_1 + 0x5c);
        iStack_11c = lit_code_10048000_1ed0;
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
      uVar4 = crc16_ccitt(lit_code_10048000_1ed0,*(undefined4 *)(param_1 + 0x5c));
      if ((*(uint *)(param_1 + 0x60) & 0xffff) != uVar4) {
        boot_printf(lit_fn_flash_status_veneer_plus_36a);
        DataSynchronizationBarrier(0xf);
        *(undefined4 *)(lit_sys_scb_cpuid_1edc + 0xc) = flash_cmd_word_2;
        DataSynchronizationBarrier(0xf);
        do {
                    /* WARNING: Do nothing block with infinite loop */
        } while( true );
      }
      boot_printf(lit_fn_flash_status_veneer_plus_352);
      uVar4 = 0;
      uVar3 = *(uint *)(param_1 + 0x48);
      *param_2 = 0;
      param_2[2] = uVar3;
      param_2[3] = *(uint *)(param_1 + 0x5c);
LAB_10001e28:
      param_2[1] = uVar4;
    }
    else {
      uVar2 = lit_fn_flash_status_veneer_plus_3b0;
      if (1 < uVar4) goto LAB_10001ebc;
      *param_2 = uVar4;
      param_2[2] = *(uint *)(param_1 + 0x48);
      param_2[3] = *(uint *)(param_1 + 0x5c);
      param_2[1] = 0;
      param_2[4] = 0;
      if (*(int *)(param_1 + 0x68) == image_tag_pattern_3) {
        boot_printf(lit_fn_flash_status_veneer_plus_2d1_1ef8);
        uVar4 = *(uint *)(param_1 + 0x68);
        goto LAB_10001e28;
      }
    }
    uVar3 = *(uint *)(param_1 + 100);
    uVar4 = *(uint *)(param_1 + 0x4c);
    param_2[4] = uVar3;
    param_2[5] = uVar4;
    param_2[6] = *(uint *)(param_1 + 0x50);
    boot_printf(lit_fn_flash_status_veneer_plus_3cb,*param_2,param_2[2],param_2[3],param_2[1],uVar3);
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
  boot_jump_to_app(lit_code_10048000_1f24);
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
  
  iVar1 = strcmp(param_1,lit_fn_flash_status_veneer_plus_3ec);
  if (iVar1 == 0) {
    boot_printf(lit_fn_flash_status_veneer_plus_40c,param_1,param_1 + 0x20,*(undefined4 *)(param_1 + 0x40),
                *(undefined4 *)(param_1 + 0x44),*(undefined4 *)(param_1 + 0x48),
                *(undefined4 *)(param_1 + 0x54),*(undefined4 *)(param_1 + 0x58),
                *(undefined4 *)(param_1 + 0x5c),*(undefined4 *)(param_1 + 0x60),
                *(undefined4 *)(param_1 + 0x68));
    if (*(int *)(param_1 + 0x40) == -1) {
      boot_printf(lit_fn_flash_status_veneer_plus_453);
    }
    else {
      uVar3 = crc16_ccitt(*(undefined4 *)(param_1 + 0x48),*(undefined4 *)(param_1 + 0x54));
      if ((*(uint *)(param_1 + 0x58) & 0xffff) != uVar3) {
        kv_delete(3);
        uVar2 = lit_fn_flash_status_veneer_plus_465;
        goto LAB_10001f42;
      }
      boot_printf(lit_fn_flash_status_veneer_plus_356);
      ota_image_handler(param_1,param_2);
      *(undefined4 *)(param_1 + 0x40) = 0xffffffff;
      kv_write(3,param_1,0x6c);
    }
    ota_region_clear(param_2);
  }
  else {
    kv_delete(3);
    uVar2 = lit_fn_flash_status_veneer_plus_3f9;
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
  
  *lit_ptr_ram_20000ef8 = param_1;
  uVar1 = lit_fn_ota_image_verify_plus_d5;
  *lit_ptr_ram_20000f00 = param_2;
  uVar2 = lit_fn_ota_image_verify_plus_b5;
  *lit_ptr_ram_20000efc = param_3;
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
  
  iVar2 = lit_ptr_ram_20000f04;
  uVar1 = crc32_poly_reflected;
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
    param_3 = param_3 >> 8 ^ *(uint *)(((uint)*param_1 ^ param_3 & 0xff) * 4 + lit_ptr_ram_20000f04_20bc);
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
      lzma_len(param_1,(int)param_1 + misc_const_0adc,uVar2);
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
        iVar4 = misc_const_05d4;
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
          iVar11 = (uVar5 - uVar10) + lit_mask_7fffffff;
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
    iVar3 = misc_const_6ee0;
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
              memcpy((int)param_1 + misc_const_6ee4_2,*param_2 + param_2[1],uVar12,misc_const_6ee4_2,puVar13
                     ,piVar9,param_3);
              *(uint *)((int)param_1 + misc_const_6ee0_2) = uVar12;
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
            iVar4 = (int)param_1 + misc_const_6ee4;
            memcpy(iVar4 + iVar3,*param_2 + param_2[1],uVar12,*param_2,puVar13,piVar9,param_3);
            piVar9 = *(int **)((int)param_1 + misc_const_6ee0);
            uVar11 = uVar12 + (int)piVar9;
            if (uVar11 != param_1[0x12]) {
              if (0x14 < uVar11) {
                param_1[5] = uVar11 - 0x15;
                goto LAB_1000290c;
              }
              *(uint *)((int)param_1 + misc_const_6ee0) = uVar11;
              goto LAB_10002ba6;
            }
            memset(iVar4 + uVar11,0,0x3f - uVar11,param_1[0x12],puVar13,piVar9);
            piVar9 = *(int **)((int)param_1 + misc_const_6ee0);
            param_1[5] = (int)piVar9 + uVar12;
LAB_1000290c:
            param_1[3] = iVar4;
            param_1[4] = 0;
            iVar3 = lzma_main(param_1);
            if (iVar3 == 0) goto LAB_10002a3a;
            uVar11 = param_1[4];
            uVar5 = *(uint *)((int)param_1 + misc_const_6ee0);
            if (uVar12 + uVar5 < uVar11) goto LAB_10002a3a;
            param_1[0x12] = param_1[0x12] - uVar11;
            iVar3 = misc_const_6ee0_2;
            if (uVar5 <= uVar11) {
              param_2[1] = (param_2[1] - uVar5) + uVar11;
              *(undefined4 *)((int)param_1 + iVar3) = 0;
              goto LAB_10002bce;
            }
            *(uint *)((int)param_1 + misc_const_6ee0) = uVar5 - uVar11;
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
              ((uint)param_1[0x12] <= *(uint *)((int)param_1 + misc_const_6ee0_2))))) goto LAB_1000287e;
        }
        uVar1 = 0;
        goto LAB_10002a3c;
      }
    } while (8 < *pbVar7);
    aeabi_concat();
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
      *(short *)(param_1 + 0x10) = (short)misc_const_0803;
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
          puVar8 = (undefined4 *)((int)param_1 + misc_const_6ee0);
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
  
  iVar1 = heap_alloc_callback(misc_const_6f24);
  if (iVar1 != 0) {
    *(char *)(iVar1 + 0x3c) = (char)param_1;
    *(undefined4 *)(iVar1 + 0x34) = param_2;
    if (param_1 == 1) {
      iVar2 = heap_alloc_callback(param_2);
      *(int *)(iVar1 + 0x18) = iVar2;
      if (iVar2 == 0) {
        heap_free_callback(iVar1);
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
        heap_free_callback(*(undefined4 *)(param_1 + 0x18));
        iVar2 = heap_alloc_callback(*(undefined4 *)(param_1 + 0x30));
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
    *(undefined4 *)(param_1 + misc_const_6ee0_3) = 0;
  }
  return uVar1;
}

// FUNC 0x10002da4  lzma2_end

/* Frees the LZMA2 dictionary state */

void lzma2_end(int param_1)

{
  if (*(char *)(param_1 + 0x3c) != '\0') {
    heap_free_callback(*(undefined4 *)(param_1 + 0x18));
  }
  heap_free_callback(param_1);
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
    aeabi_concat_2();
    piVar12 = (int *)(extraout_r1 * 0x2000);
    iVar1 = bcj_fill_temp(param_1,piVar12,extraout_r1 << 7,extraout_r1 << 0x10);
    uVar4 = lit_fn_flash_status_veneer_plus_479;
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
  
  iVar1 = heap_alloc_callback(0x4a8);
  if (iVar1 != 0) {
    *(char *)(iVar1 + 0x1d) = (char)param_1;
    iVar2 = lzma2_create(param_1,param_2);
    *(int *)(iVar1 + 0x4a0) = iVar2;
    if (iVar2 == 0) {
      heap_free_callback();
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
    heap_free_callback(param_1);
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
  uVar4 = lit_fn_flash_status_veneer_plus_4a6;
  if (iVar1 != 0) {
    iStack_30 = heap_alloc_callback(0x1000);
    iStack_2c = 0;
    iStack_28 = 0;
    iStack_24 = heap_alloc_callback(0x1000);
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
        uVar4 = lit_fn_flash_status_veneer_plus_499;
        if (iVar3 != iStack_20) goto LAB_1000357a;
        iStack_20 = 0;
      }
    } while (iVar2 == 0);
    iVar3 = (*param_2)(iStack_24,1,iStack_20,0);
    uVar4 = lit_fn_flash_status_veneer_plus_499;
    if ((iVar3 == iStack_20) && (uVar4 = lit_fn_flash_status_veneer_plus_482, iVar2 - 1U < 8)) {
      aeabi_nop();
      uVar4 = lit_fn_flash_status_veneer_plus_4f8;
    }
  }
LAB_1000357a:
  xz_dec_lzma2_end(iVar1);
  if (iStack_30 != 0) {
    heap_free_callback();
  }
  if (iStack_24 != 0) {
    heap_free_callback();
  }
  boot_printf(lit_fn_flash_status_veneer_plus_514,uVar4);
  return 1;
}

// FUNC 0x10003644  kv_store_init

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Registers the SYS ENV and SYS KV callbacks and mounts the store */

int kv_store_init(int param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  
  *lit_ptr_ram_20001304 = param_1;
  uVar1 = lit_ptr_ram_2000130c;
  *lit_ptr_ram_20001308 = param_2;
  if (param_1 != 0) {
    kv_set_callback(uVar1,2,lit_fn_xz_decompress_buffer_plus_125);
  }
  if (param_2 != 0) {
    kv_set_callback(uVar1,3,lit_fn_xz_decompress_buffer_plus_139);
  }
  iVar2 = kv_mount(uVar1,lit_fn_flash_status_veneer_plus_517,lit_fn_flash_status_veneer_plus_107);
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
  
  uVar1 = heap_alloc_return(auStack_1c);
  xz_decode_finish(lit_ptr_ram_2000130c_36c0,param_1,uVar1);
  return -(uint)(iStack_c == 0);
}

// FUNC 0x100036c4  kv_write

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Writes a KV record by id, magic KV10 */

void kv_write(undefined4 param_1)

{
  undefined4 uVar1;
  undefined1 auStack_1c [20];
  
  uVar1 = heap_alloc_return(auStack_1c);
  xz_decode_main(lit_ptr_ram_2000130c_36e0,param_1,uVar1);
  return;
}

// FUNC 0x100036e4  kv_delete

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Deletes a KV record by id */

void kv_delete(undefined4 param_1)

{
  kv_erase_entry(lit_ptr_ram_2000130c_36f0,param_1);
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

// FUNC 0x100037b0  xz_block_data_done

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void xz_block_data_done(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

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
    uStack_14 = lit_tag_fdb0;
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
      } while (iStack_28 != lit_tag_kv10);
      if (uVar2 <= (uint)(*(int *)(param_2 + 4) + *(int *)(param_1 + 8))) {
        return uVar2;
      }
    }
  }
  return 0xffffffff;
}

// FUNC 0x100038e0  xz_block_decode_hdr

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1 xz_block_decode_hdr(int param_1,undefined4 param_2,undefined1 *param_3,int param_4)

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
  iVar1 = lit_tag_fdb0_39a8;
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
      iVar1 = xz_block_decode_hdr(param_1,uVar2,&uStack_2c,0);
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

// FUNC 0x10003a1c  xz_block_decode_loop

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1 xz_block_decode_loop(undefined4 param_1,undefined2 param_2,undefined4 param_3)

{
  undefined2 auStack_12 [4];
  undefined1 uStack_9;
  
  uStack_9 = 0;
  auStack_12[0] = param_2;
  xz_block_decode_loop(param_1,param_3,auStack_12,&uStack_9,lit_fn_kv_delete_plus_11);
  return uStack_9;
}

// FUNC 0x10003a48  xz_stream_decode_done

int xz_stream_decode_done(int param_1,undefined4 param_2,undefined1 *param_3,int param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined1 auStack_34 [4];
  undefined1 auStack_30 [28];
  
  if (param_3 == (undefined1 *)0x0) {
    iVar1 = xz_block_decode_loop(param_1,param_2,auStack_30);
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
    iVar2 = xz_block_hdr_call(param_1,iVar3,auStack_34,4);
    if (iVar2 == 1) {
      iVar1 = xz_stream_done(param_1,iVar3,auStack_34,4,2,1);
    }
  }
  return iVar1;
}

// FUNC 0x10003af4  xz_stream_decode

undefined4 xz_stream_decode(undefined4 param_1,int param_2,undefined1 *param_3)

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
      xz_block_decode_hdr(param_1,uVar3,param_2,0,param_4,uVar2,uVar4);
      if ((param_3 == 0) || (*(byte *)(param_2 + 1) == param_3)) {
        if (uVar2 != 0) {
          xz_block_decode_hdr(param_1,uVar3,param_2,1,param_4,uVar2,uVar4);
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

// FUNC 0x10003bac  xz_container_decode

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int xz_container_decode(int param_1,undefined4 param_2,undefined4 param_3)

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
  xz_container_decode(param_1,param_2,0,&uStack_24,&iStack_20,lit_fn_xz_block_data_done_plus_6d,0);
  if (iStack_20 != 0) {
    xz_container_decode(param_1,param_2,2,&iStack_1c,0,lit_fn_xz_block_data_done_plus_8f,1);
  }
  if ((uStack_24 != 0) && (iStack_28 == -1)) {
    if ((uStack_24 < 2) && (*(char *)(param_1 + 0x28) == '\0')) {
      *(char *)(param_1 + 0x28) = '\x01';
    }
    else {
      xz_container_decode(param_1,param_2,1,&iStack_1c,0,lit_fn_xz_block_data_done_plus_8f,1);
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
    xz_stream_decode_done(param_1,0,param_2);
  }
  iVar1 = xz_container_decode(param_1,auStack_4c,0x94);
  uStack_5c = 7;
  if (iVar1 != -1) {
    if ((*(char *)(param_1 + 0x29) == '\0') ||
       (iVar2 = xz_block_decode_loop(param_1,*(undefined2 *)(param_2 + 0xc),auStack_38), iVar2 == 0)) {
      iVar2 = *(int *)(param_2 + 8);
      xz_stream_decode(param_1,auStack_4c,0);
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
    xz_stream_decode_done(param_1,0,param_2,1);
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
  xz_container_decode(param_1,auStack_24,1,&uStack_28,0,lit_fn_kv_delete_plus_33,0);
  if (uStack_28 < 2) {
    xz_container_decode(param_1,auStack_24,0,param_1,0,lit_fn_xz_container_dispatch_plus_11b,0);
  }
  *(undefined1 *)(param_1 + 0x28) = 0;
  return;
}

// FUNC 0x10003e10  xz_stream_decode_done

/* Finalizes an XZ stream after all blocks */

void xz_stream_decode_done(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  
  iVar1 = xz_container_decode();
  if (iVar1 == -1) {
    if (*(char *)(param_1 + 0x28) != '\0') {
      xz_block_decode_done(param_1);
      iVar1 = xz_container_decode(param_1,param_2,param_3);
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
    iVar1 = xz_block_decode_loop(param_1,param_2,auStack_30);
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
    uVar1 = xz_stream_decode_done(param_1,param_2,0,1);
    if (*(code **)(param_1 + 0x18) != (code *)0x0) {
      (**(code **)(param_1 + 0x18))(param_1);
    }
  }
  return uVar1;
}

// FUNC 0x10003ef4  xz_decode_main

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int xz_decode_main(int param_1,undefined4 param_2,int *param_3)

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
      iVar6 = xz_stream_decode_done(param_1,param_2,0,1);
    }
    else {
      uVar3 = param_3[1];
      iVar4 = param_1 + 0x44;
      iVar1 = xz_stream_decode_done(param_1,iVar4,uVar3 + 0x14);
      iVar6 = 7;
      if (iVar1 != -1) {
        iVar5 = param_1 + 0x2c;
        iVar1 = xz_block_decode_loop(param_1,param_2,iVar5);
        if ((iVar1 == 0) || (iVar6 = xz_stream_decode_done(param_1,param_2,iVar5,0), iVar6 == 0)) {
          cStack_2d = '\0';
          iVar7 = *(int *)(param_1 + 0x54);
          memset(auStack_2c,0xff,0x14);
          uStack_28 = lit_tag_kv10_4074;
          uStack_1c = (undefined2)param_2;
          uStack_20 = uVar3;
          if (((*(int *)(param_1 + 8) - 8U < uVar3) || (0x80 < uVar3)) ||
             ((iVar7 == -1 && (iVar7 = xz_stream_decode_done(param_1,iVar4,0x94), iVar7 == -1)))) {
            iVar6 = 7;
          }
          else {
            iVar6 = xz_stream_decode(param_1,iVar4,&cStack_2d);
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
                        iVar6 = xz_stream_decode_done(param_1,param_2,iVar5,1);
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
    iVar1 = xz_block_data_done(param_1,uVar2);
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
  xz_container_decode(param_1,auStack_3c,0,&iStack_40,param_1,lit_fn_xz_stream_decode_done_plus_91,0);
  iVar1 = aeabi_uidivmod(*(undefined4 *)(param_1 + 0xc),*(undefined4 *)(param_1 + 8));
  if (iVar1 == iStack_40) {
    kv_scan_entries(param_1);
  }
  if (*(code **)(param_1 + 0x14) != (code *)0x0) {
    (**(code **)(param_1 + 0x14))(param_1);
  }
  xz_container_decode(param_1,auStack_3c,0,param_1,0,lit_fn_xz_stream_decode_done_plus_35,0);
  while( true ) {
    xz_block_decode_loop(param_1,auStack_28,param_1,0,lit_fn_xz_container_dispatch_plus_db);
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
    uVar1 = aeabi_nop(param_2);
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
  
  iVar1 = lit_fn_kv_mount_plus_91;
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
    param_1[8] = lit_fn_kv_mount_plus_5d;
    param_1[9] = lit_fn_kv_mount_plus_31;
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
        param_1 = param_1 ^ crc32_poly_2;
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

// FUNC 0x10004380  xz_block_hdr_call

void xz_block_hdr_call(undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4)

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

// FUNC 0x1000439c  heap_alloc_return

void heap_alloc_return(undefined4 *param_1,undefined4 param_2,undefined4 param_3)

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
  
  pcVar1 = lit_ptr_ram_20001368;
  if (param_2 == 0) {
    *(undefined1 *)(param_1 + 0x10) = 1;
    if (*pcVar1 == '\0') {
      *pcVar1 = '\x01';
    }
  }
  return;
}

// FUNC 0x100043bc  heap_alloc_callback

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void heap_alloc_callback(undefined4 param_1)

{
  heap_alloc_impl(*lit_ptr_ram_20000a38,param_1);
  return;
}

// FUNC 0x100043d0  heap_free_callback

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void heap_free_callback(undefined4 param_1)

{
  heap_free(*lit_ptr_ram_20000a38_43e0,param_1);
  return;
}

// FUNC 0x100043e4  heap_alloc_impl

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int * heap_alloc_impl(undefined4 *param_1,uint param_2)

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
    heap_lock();
    uVar15 = 0x10;
    uVar14 = 2;
    iVar10 = 0x18;
LAB_1000440c:
    iVar10 = lit_ptr_ram_20000628 + iVar10;
    iVar12 = *(int *)(iVar10 + 4);
    if (iVar12 == iVar10 + -8) {
      iVar12 = *(int *)(iVar10 + 0xc);
      uVar14 = uVar14 + 2;
      if (iVar10 == iVar12) {
        iVar12 = *(int *)(lit_ptr_ram_20000628 + 0x10);
        iVar10 = lit_ptr_ram_20000628 + 8;
        if (iVar12 == iVar10) goto LAB_1000459e;
LAB_100044ac:
        uVar3 = lit_ptr_ram_20000628;
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
          heap_unlock(param_1);
          return (int *)(iVar12 + 8);
        }
        *(int *)(lit_ptr_ram_20000628 + 0x14) = iVar10;
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
          else if (misc_const_0554 < uVar5) {
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
    heap_unlock(param_1);
    return (int *)(iVar12 + 8);
  }
  uVar15 = uVar14 & 0xfffffff8;
  if (((int)uVar15 < 0) || (uVar15 < param_2)) goto LAB_10004568;
  heap_lock();
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
  else if (misc_const_0554 < uVar3) {
    uVar3 = 0x7f;
    uVar4 = 0x7e;
    iVar10 = 0x3f8;
  }
  else {
    uVar4 = (uVar14 >> 0x12) + 0x7c;
    uVar3 = (uVar14 >> 0x12) + 0x7d;
    iVar10 = uVar3 * 8;
  }
  for (iVar12 = *(int *)(lit_ptr_ram_20000628 + iVar10 + 4); uVar14 = uVar3,
      lit_ptr_ram_20000628 + iVar10 + -8 != iVar12; iVar12 = *(int *)(iVar12 + 0xc)) {
    uVar6 = *(uint *)(iVar12 + 4) & 0xfffffffc;
    uVar14 = uVar4;
    if (0xf < (int)(uVar6 - uVar15)) break;
    if (-1 < (int)(uVar6 - uVar15)) goto LAB_10004424;
  }
  iVar12 = *(int *)(lit_ptr_ram_20000628 + 0x10);
  iVar10 = lit_ptr_ram_20000628 + 8;
  if (iVar12 != iVar10) goto LAB_100044ac;
LAB_1000459e:
  uVar4 = *(uint *)(lit_ptr_ram_20000628 + 4);
  uVar6 = 1 << ((int)uVar14 >> 2 & 0xffU);
  uVar3 = lit_ptr_ram_20000628;
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
            heap_unlock(param_1);
            return piVar13 + 2;
          }
          if (-1 < (int)uVar5) {
            *(uint *)((int)piVar13 + uVar9 + 4) = *(uint *)((int)piVar13 + uVar9 + 4) | 1;
            iVar12 = piVar13[3];
            iVar10 = piVar13[2];
            *(int *)(iVar10 + 0xc) = iVar12;
            *(int *)(iVar12 + 8) = iVar10;
            heap_unlock(param_1);
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
  puVar1 = lit_ptr_ram_20000a30;
  uVar14 = *(uint *)(uVar3 + 8);
  uVar4 = *(uint *)(uVar14 + 4) & 0xfffffffc;
  if ((uVar15 <= uVar4) && (uVar6 = uVar4 - uVar15, 0xf < (int)uVar6)) goto LAB_100046d2;
  uVar6 = uVar14 + uVar4;
  if (*lit_ptr_ram_20000a30 == 0xffffffff) {
    uStack_30 = uVar15 + *lit_ptr_ram_2000139c + 0x10;
  }
  else {
    uStack_30 = uVar15 + *lit_ptr_ram_2000139c + misc_const_100f & 0xfffff000;
  }
  uVar5 = heap_alloc_helper(param_1,uStack_30);
  puVar2 = lit_ptr_ram_2000136c_495c;
  puVar16 = lit_ptr_ram_2000136c;
  if (uVar5 == 0xffffffff) {
LAB_100047e8:
    uVar5 = *(uint *)(uVar3 + 8);
    uStack_30 = *(uint *)(uVar5 + 4);
  }
  else {
    if (uVar5 < uVar6) {
      if (uVar14 == uVar3) {
        uVar9 = uStack_30 + *lit_ptr_ram_2000136c_495c;
        *lit_ptr_ram_2000136c_495c = uVar9;
        puVar16 = puVar2;
        goto LAB_1000461a;
      }
      goto LAB_100047e8;
    }
    uVar9 = uStack_30 + *lit_ptr_ram_2000136c;
    *lit_ptr_ram_2000136c = uVar9;
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
        iVar10 = heap_alloc_helper(param_1,uVar9);
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
        uVar9 = (misc_const_1008 - uVar6) - (uStack_30 + uVar5) & 0xfff;
        iVar10 = heap_alloc_helper(param_1,uVar9);
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
          heap_free(param_1,uVar14 + 8);
          uVar5 = *(uint *)(uVar3 + 8);
          uVar9 = *puVar16;
          uStack_30 = *(uint *)(uVar5 + 4);
        }
      }
    }
    if (*lit_ptr_ram_20001394 < uVar9) {
      *lit_ptr_ram_20001394 = uVar9;
    }
    if (*lit_ptr_ram_20001398 < uVar9) {
      *lit_ptr_ram_20001398 = uVar9;
    }
  }
  uVar6 = (uStack_30 & 0xfffffffc) - uVar15;
  if ((uVar15 <= (uStack_30 & 0xfffffffc)) && (uVar14 = uVar5, 0xf < (int)uVar6)) {
LAB_100046d2:
    *(uint *)(uVar14 + 4) = uVar15 | 1;
    *(uint *)(uVar3 + 8) = uVar14 + uVar15;
    *(uint *)(uVar14 + uVar15 + 4) = uVar6 | 1;
    heap_unlock(param_1);
    return (int *)(uVar14 + 8);
  }
LAB_100047fc:
  heap_unlock(param_1);
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

// FUNC 0x10004bb0  heap_lock

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void heap_lock(void)

{
  null_callback_1(lit_ptr_ram_200015c8);
  return;
}

// FUNC 0x10004bc0  heap_unlock

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void heap_unlock(void)

{
  null_callback_2(lit_ptr_ram_200015c8_4bcc);
  return;
}

// FUNC 0x10004bd0  heap_alloc_helper

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void heap_alloc_helper(int *param_1,undefined4 param_2)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = lit_ptr_ram_200015dc;
  *lit_ptr_ram_200015dc = 0;
  iVar2 = heap_alloc(param_2);
  if ((iVar2 == -1) && (*piVar1 != 0)) {
    *param_1 = *piVar1;
  }
  return;
}

// FUNC 0x10004bf4  heap_alloc

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 heap_alloc(undefined4 param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  
  heap_lock();
  iVar2 = lit_ptr_ram_20000628_4c80;
  uVar4 = *(uint *)(*(int *)(lit_ptr_ram_20000628_4c80 + 8) + 4) & 0xfffffffc;
  iVar3 = ((uVar4 - param_2) + misc_const_0fef >> 0xc) - 1;
  if ((misc_const_0fef + 0x11 <= iVar3 * 0x1000) &&
     (iVar1 = heap_alloc_helper(param_1,0), iVar1 == *(int *)(iVar2 + 8) + uVar4)) {
    iVar1 = heap_alloc_helper(param_1,iVar3 * -0x1000);
    if (iVar1 != -1) {
      *(uint *)(*(int *)(iVar2 + 8) + 4) = uVar4 + iVar3 * -0x1000 | 1;
      *lit_ptr_ram_2000136c_4c88 = *lit_ptr_ram_2000136c_4c88 + iVar3 * -0x1000;
      heap_unlock(param_1);
      return 1;
    }
    iVar3 = heap_alloc_helper(param_1,0);
    iVar2 = *(int *)(iVar2 + 8);
    uVar4 = iVar3 - iVar2;
    if (0xf < (int)uVar4) {
      *lit_ptr_ram_2000136c_4c88 = iVar3 - *lit_ptr_ram_20000a30_4c8c;
      *(uint *)(iVar2 + 4) = uVar4 | 1;
    }
  }
  heap_unlock(param_1);
  return 0;
}

// FUNC 0x10004c90  heap_free

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void heap_free(undefined4 param_1,int param_2)

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
  heap_lock();
  iVar1 = lit_ptr_ram_20000628_4e40;
  piVar2 = (int *)(param_2 + -8);
  uVar8 = *(uint *)(param_2 + -4);
  uVar3 = uVar8 & 0xfffffffe;
  puVar11 = (uint *)((int)piVar2 + uVar3);
  uVar5 = puVar11[1] & 0xfffffffc;
  if (*(uint **)(lit_ptr_ram_20000628_4e40 + 8) == puVar11) {
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
    puVar11 = lit_ptr_ram_20000a34;
    *(int **)(iVar1 + 8) = piVar2;
    if (*puVar11 <= uVar3) {
      heap_alloc(param_1,*lit_ptr_ram_2000139c_4e4c);
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
    if (uVar8 == lit_ptr_ram_20000630) {
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
    else if (misc_const_0554_2 < uVar5) {
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
  heap_unlock(param_1);
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
  (*lit_ptr_ram_20000331)(param_1);
  return;
}

// FUNC 0x10004e70  flash_controller_init_veneer

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Veneer to flash_controller_init at 0x100003B8 */

void flash_controller_init_veneer(undefined4 param_1)

{
                    /* WARNING: Could not recover jumptable at 0x10004e78. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*lit_ptr_ram_20000299)(param_1);
  return;
}

// FUNC 0x10004e80  flash_erase_sector_veneer

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Veneer to flash_erase_sector at 0x100003D8 */

void flash_erase_sector_veneer(undefined4 param_1)

{
                    /* WARNING: Could not recover jumptable at 0x10004e88. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*lit_ptr_ram_200002b9)(param_1);
  return;
}

// FUNC 0x10004e90  flash_exit_powerdown_veneer

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Veneer to flash_exit_powerdown at 0x1000015C */

void flash_exit_powerdown_veneer(undefined4 param_1)

{
                    /* WARNING: Could not recover jumptable at 0x10004e98. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*lit_ptr_ram_2000003d)(param_1);
  return;
}

// FUNC 0x10004ea0  flash_begin_veneer

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Veneer to flash_begin at 0x10000120 */

void flash_begin_veneer(undefined4 param_1)

{
                    /* WARNING: Could not recover jumptable at 0x10004ea8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*lit_ptr_ram_20000015)(param_1);
  return;
}

// FUNC 0x10004eb0  flash_end_veneer

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Veneer to flash_end at 0x10000134 */

void flash_end_veneer(undefined4 param_1)

{
                    /* WARNING: Could not recover jumptable at 0x10004eb8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*lit_ptr_ram_20000001)(param_1);
  return;
}

// FUNC 0x10004ec0  flash_status_veneer

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Veneer to flash_status at 0x1000014C */

void flash_status_veneer(undefined4 param_1)

{
                    /* WARNING: Could not recover jumptable at 0x10004ec8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*lit_ptr_ram_2000002d)(param_1);
  return;
}

// FUNC 0x100480b0  log_bytecmp

int log_bytecmp(uint *param_1,uint *param_2)

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
      uVar4 = uVar2 - bitspread_test_2 & ~uVar2 & bitspread_test_2 << 7;
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

// FUNC 0x10048188  log_state_1

int log_state_1(void)

{
  int iVar1;
  
  iVar1 = log_cmp();
  return 1 - iVar1;
}

// FUNC 0x10048194  log_state_2

undefined4 log_state_2(void)

{
  int iVar1;
  
  iVar1 = log_state_check_alt();
  if (-1 < iVar1) {
    return 0;
  }
  return 1;
}

// FUNC 0x100481a8  log_state_3

undefined4 log_state_3(void)

{
  int iVar1;
  
  iVar1 = log_state_check_alt();
  if (0 < iVar1) {
    return 0;
  }
  return 1;
}

// FUNC 0x100481bc  log_state_4

undefined4 log_state_4(void)

{
  int iVar1;
  
  iVar1 = log_state_check();
  if (iVar1 < 1) {
    return 0;
  }
  return 1;
}

// FUNC 0x100481d0  log_empty_check

undefined4 log_empty_check(void)

{
  int iVar1;
  
  iVar1 = log_state_check();
  if (iVar1 < 0) {
    return 0;
  }
  return 1;
}

// FUNC 0x100481e4  log_error

void log_error(int param_1,int param_2,int param_3,int param_4)

{
  if ((param_4 == 0) && (param_3 == 0)) {
    if (param_2 != 0 || param_1 != 0) {
      param_1 = -1;
      param_2 = param_1;
    }
                    /* WARNING: Could not recover jumptable at 0x10048204. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)((int)&log_error_fn_offset + log_error_fn_offset))(param_1,param_2);
    return;
  }
  log_shift(param_1);
  return;
}

// FUNC 0x10048224  led_update_fmt

int led_update_fmt(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = fmt_int_13(param_1,0x4f000000);
  if (iVar1 == 0) {
    iVar1 = fmt_int_15(param_1);
  }
  else {
    fmt_int(param_1,0x4f000000);
    iVar1 = fmt_int_15();
    iVar1 = iVar1 + -0x80000000;
  }
  return iVar1;
}

// FUNC 0x10048254  led_update_format

int led_update_format(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = log_empty_check(param_1,param_2,0,lit_float_28);
  if (iVar1 == 0) {
    iVar1 = fmt_int_6(param_1,param_2);
  }
  else {
    fmt_int_5(param_1,param_2,0,lit_float_28);
    iVar1 = fmt_int_6();
    iVar1 = iVar1 + -0x80000000;
  }
  return iVar1;
}

// FUNC 0x10048290  log_shift

undefined8 log_shift(uint param_1,uint param_2,uint param_3,uint param_4,uint *param_5)

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
  uint local_30;
  uint local_2c;
  
  if ((param_2 <= param_4 && param_4 != param_2) || ((param_4 == param_2 && (param_1 < param_3)))) {
    local_30 = 0;
    local_2c = 0;
  }
  else {
    iVar1 = log_div(param_3,param_4);
    iVar2 = log_div(param_1,param_2);
    uVar4 = iVar1 - iVar2;
    uVar5 = uVar4 - 0x20;
    if ((int)uVar5 < 0) {
      uVar8 = param_4 << (uVar4 & 0xff) | param_3 >> (0x20 - uVar4 & 0xff);
    }
    else {
      uVar8 = param_3 << (uVar5 & 0xff);
    }
    param_3 = param_3 << (uVar4 & 0xff);
    if ((param_2 <= uVar8 && uVar8 != param_2) || ((uVar8 == param_2 && (param_1 < param_3)))) {
      local_30 = 0;
      local_2c = 0;
    }
    else {
      bVar9 = param_1 < param_3;
      param_1 = param_1 - param_3;
      param_2 = (param_2 - uVar8) - (uint)bVar9;
      if ((int)uVar5 < 0) {
        local_2c = 1 >> (0x20 - uVar4 & 0xff);
      }
      else {
        local_2c = 1 << (uVar5 & 0xff);
      }
      local_30 = 1 << (uVar4 & 0xff);
    }
    if (uVar4 != 0) {
      uVar3 = param_3 >> 1 | uVar8 << 0x1f;
      uVar8 = uVar8 >> 1;
      uVar7 = uVar4;
      do {
        while ((param_2 < uVar8 || ((uVar8 == param_2 && (param_1 < uVar3))))) {
          uVar7 = uVar7 - 1;
          bVar9 = CARRY4(param_1,param_1);
          param_1 = param_1 * 2;
          param_2 = param_2 * 2 + (uint)bVar9;
          if (uVar7 == 0) goto LAB_10048378;
        }
        bVar9 = param_1 < uVar3;
        uVar6 = param_1 - uVar3;
        uVar7 = uVar7 - 1;
        param_1 = uVar6 * 2 + 1;
        param_2 = ((param_2 - uVar8) - (uint)bVar9) * 2 + (uint)CARRY4(uVar6,uVar6) +
                  (uint)(0xfffffffe < uVar6 * 2);
      } while (uVar7 != 0);
LAB_10048378:
      bVar9 = CARRY4(local_30,param_1);
      uVar8 = local_30 + param_1;
      iVar1 = local_2c + param_2;
      if ((int)uVar5 < 0) {
        param_1 = param_1 >> (uVar4 & 0xff) | param_2 << (0x20 - uVar4 & 0xff);
      }
      else {
        param_1 = param_2 >> (uVar5 & 0xff);
      }
      param_2 = param_2 >> (uVar4 & 0xff);
      if ((int)uVar5 < 0) {
        uVar5 = param_2 << (uVar4 & 0xff) | param_1 >> (0x20 - uVar4 & 0xff);
      }
      else {
        uVar5 = param_1 << (uVar5 & 0xff);
      }
      uVar4 = param_1 << (uVar4 & 0xff);
      local_30 = uVar8 - uVar4;
      local_2c = ((iVar1 + (uint)bVar9) - uVar5) - (uint)(uVar8 < uVar4);
    }
  }
  if (param_5 != (uint *)0x0) {
    *param_5 = param_1;
    param_5[1] = param_2;
  }
  return CONCAT44(local_2c,local_30);
}

// FUNC 0x10048410  fmt_s

uint fmt_s(uint param_1,uint param_2)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  
  iVar6 = -((int)param_1 >> 0x1f);
  uVar5 = (param_1 << 1) >> 0x18;
  uVar4 = (param_1 << 9) >> 6;
  uVar7 = (param_2 << 1) >> 0x18;
  iVar2 = -((int)param_2 >> 0x1f);
  uVar3 = (param_2 << 9) >> 6;
  uVar8 = uVar4;
  if (iVar6 == iVar2) {
    uVar1 = uVar5 - uVar7;
    if ((int)uVar1 < 1) {
      if (uVar1 != 0) {
        if (uVar5 == 0) {
          uVar8 = uVar3;
          uVar5 = uVar7;
          if (uVar4 == 0) goto LAB_1004843e;
          uVar1 = ~uVar1;
          if (uVar1 == 0) goto LAB_10048640;
          if (uVar7 != 0xff) goto LAB_1004862c;
        }
        else if (uVar7 != 0xff) {
          uVar1 = -uVar1;
          uVar4 = uVar4 | 0x4000000;
LAB_1004862c:
          if ((int)uVar1 < 0x1c) {
            uVar4 = (uint)(uVar4 << (0x20 - uVar1 & 0xff) != 0) | uVar4 >> (uVar1 & 0xff);
          }
          else {
            uVar4 = 1;
          }
LAB_10048640:
          uVar8 = uVar4 + uVar3;
          goto LAB_1004850c;
        }
LAB_100486ce:
        uVar8 = uVar3;
        uVar5 = 0xff;
        goto LAB_1004843e;
      }
      uVar7 = uVar5 + 1;
      if ((uVar7 & 0xff) < 2) {
        if (uVar5 == 0) {
          uVar8 = uVar3;
          if ((uVar4 != 0) && (uVar8 = uVar4, uVar3 != 0)) {
            uVar8 = uVar4 + uVar3;
            if (-1 < (int)(uVar8 * 0x20)) goto LAB_100484be;
            uVar8 = uVar8 & lit_mask_fbffffff;
            uVar5 = uVar7;
          }
        }
        else {
          if (uVar4 == 0) goto LAB_100486ce;
          uVar5 = 0xff;
          if (uVar3 != 0) {
            uVar8 = param_1 & 0x7fffff;
            if (((param_1 & 0x400000) != 0) && ((param_2 & 0x400000) == 0)) {
              uVar8 = param_2 & 0x7fffff;
            }
            goto LAB_100486a0;
          }
        }
        goto LAB_1004843e;
      }
      if (uVar7 != 0xff) {
        uVar8 = uVar4 + uVar3 >> 1;
        uVar5 = uVar7;
        goto LAB_1004843e;
      }
    }
    else {
      if (uVar7 == 0) {
        if (uVar3 != 0) {
          uVar1 = uVar1 - 1;
          if (uVar1 == 0) goto LAB_1004850a;
          if (uVar5 != 0xff) goto LAB_100484f4;
        }
      }
      else if (uVar5 != 0xff) {
        uVar3 = uVar3 | 0x4000000;
LAB_100484f4:
        if ((int)uVar1 < 0x1c) {
          uVar3 = (uint)(uVar3 << (0x20 - uVar1 & 0xff) != 0) | uVar3 >> (uVar1 & 0xff);
        }
        else {
          uVar3 = 1;
        }
LAB_1004850a:
        uVar8 = uVar4 + uVar3;
        uVar7 = uVar5;
LAB_1004850c:
        uVar5 = uVar7;
        if (-1 < (int)(uVar8 << 5)) goto LAB_100484be;
        if (uVar7 + 1 == 0xff) goto LAB_100485e0;
        uVar8 = uVar8 >> 1 & mask_clear_bits25_30 | uVar8 & 1;
        uVar5 = uVar7 + 1;
      }
LAB_1004843e:
      if ((uVar8 & 7) != 0) {
LAB_10048442:
        if ((uVar8 & 0xf) != 4) {
          uVar8 = uVar8 + 4;
        }
      }
      if ((int)(uVar8 << 5) < 0) {
        if (uVar5 + 1 == 0xff) {
          uVar8 = 0;
          uVar5 = 0xff;
        }
        else {
          uVar8 = (uVar8 << 6) >> 9;
          uVar5 = uVar5 + 1 & 0xff;
        }
        goto LAB_10048460;
      }
LAB_100484c2:
      uVar8 = uVar8 >> 3;
      if (uVar5 != 0xff) goto LAB_1004852a;
      if (uVar8 != 0) {
LAB_100484d0:
        uVar8 = uVar8 & 0x7fffff | 0x400000;
        uVar5 = 0xff;
        goto LAB_10048460;
      }
    }
LAB_100485e0:
    uVar5 = 0xff;
    uVar8 = 0;
  }
  else {
    uVar1 = uVar5 - uVar7;
    if (0 < (int)uVar1) {
      if (uVar7 == 0) {
        if (uVar3 != 0) {
          uVar1 = uVar1 - 1;
          if (uVar1 == 0) goto LAB_1004848e;
          if (uVar5 != 0xff) goto LAB_10048478;
        }
      }
      else if (uVar5 != 0xff) {
        uVar3 = uVar3 | 0x4000000;
LAB_10048478:
        if ((int)uVar1 < 0x1c) {
          uVar3 = (uint)(uVar3 << (0x20 - uVar1 & 0xff) != 0) | uVar3 >> (uVar1 & 0xff);
        }
        else {
          uVar3 = 1;
        }
LAB_1004848e:
        uVar8 = uVar4 - uVar3;
        goto LAB_10048490;
      }
      goto LAB_1004843e;
    }
    if (uVar1 != 0) {
      if (uVar5 == 0) {
        uVar8 = uVar3;
        uVar5 = uVar7;
        iVar6 = iVar2;
        if (uVar4 == 0) goto LAB_1004843e;
        uVar1 = ~uVar1;
        if (uVar1 != 0) {
          if (uVar7 == 0xff) goto LAB_100486a6;
          goto LAB_100485a8;
        }
      }
      else {
        if (uVar7 == 0xff) {
LAB_100486a6:
          uVar8 = uVar3;
          uVar5 = 0xff;
          iVar6 = iVar2;
          goto LAB_1004843e;
        }
        uVar1 = -uVar1;
        uVar4 = uVar4 | 0x4000000;
LAB_100485a8:
        if ((int)uVar1 < 0x1c) {
          uVar4 = (uint)(uVar4 << (0x20 - uVar1 & 0xff) != 0) | uVar4 >> (uVar1 & 0xff);
        }
        else {
          uVar4 = 1;
        }
      }
      uVar8 = uVar3 - uVar4;
      uVar5 = uVar7;
      iVar6 = iVar2;
LAB_10048490:
      if ((int)(uVar8 << 5) < 0) {
        uVar8 = uVar8 & 0x3ffffff;
        goto LAB_10048498;
      }
LAB_100484be:
      if ((uVar8 & 7) != 0) goto LAB_10048442;
      goto LAB_100484c2;
    }
    if (1 < (uVar5 + 1 & 0xff)) {
      uVar8 = uVar4 - uVar3;
      if ((uVar8 & 0x4000000) == 0) {
        if (uVar8 == 0) {
          iVar6 = 0;
          uVar5 = 0;
          uVar8 = 0;
          goto LAB_1004852a;
        }
      }
      else {
        uVar8 = uVar3 - uVar4;
        iVar6 = iVar2;
      }
LAB_10048498:
      iVar2 = mem_fill(uVar8);
      uVar7 = iVar2 - 5;
      uVar8 = uVar8 << (uVar7 & 0xff);
      if ((int)uVar7 < (int)uVar5) {
        uVar8 = lit_mask_fbffffff & uVar8;
        uVar5 = uVar5 - uVar7;
      }
      else {
        uVar5 = (uVar7 - uVar5) + 1;
        uVar8 = uVar8 >> (uVar5 & 0xff) | (uint)(uVar8 << (0x20 - uVar5 & 0xff) != 0);
        uVar5 = 0;
      }
      goto LAB_1004843e;
    }
    if (uVar5 != 0) {
      if (uVar4 != 0) {
        uVar5 = 0xff;
        if (uVar3 != 0) {
          uVar8 = param_1 & 0x7fffff;
          if (((param_1 & 0x400000) != 0) && ((param_2 & 0x400000) == 0)) {
            uVar8 = param_2 & 0x7fffff;
            iVar6 = iVar2;
          }
LAB_100486a0:
          uVar8 = uVar8 << 3;
          uVar5 = 0xff;
        }
        goto LAB_1004843e;
      }
      if (uVar3 != 0) {
        uVar8 = uVar3;
        uVar5 = 0xff;
        iVar6 = iVar2;
        goto LAB_1004843e;
      }
      iVar6 = 0;
      uVar8 = 0x400000;
      goto LAB_100484d0;
    }
    if (uVar4 != 0) {
      if (uVar3 != 0) {
        uVar8 = uVar4 - uVar3;
        if ((uVar8 & 0x4000000) == 0) {
          if (uVar8 != 0) goto LAB_100484be;
          iVar6 = 0;
          uVar8 = 0;
          goto LAB_1004852a;
        }
        uVar8 = uVar3 - uVar4;
        iVar6 = iVar2;
      }
      goto LAB_1004843e;
    }
    uVar8 = uVar3;
    iVar6 = iVar2;
    if (uVar3 != 0) goto LAB_1004843e;
    uVar8 = 0;
    iVar6 = 0;
LAB_1004852a:
    uVar8 = uVar8 & 0x7fffff;
    uVar5 = uVar5 & 0xff;
  }
LAB_10048460:
  return iVar6 << 0x1f | uVar8 | uVar5 << 0x17;
}

// FUNC 0x100486fc  log_bit_test

void log_bit_test(uint param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar2 = param_1 & 0x7fffff;
  uVar3 = (param_1 << 1) >> 0x18;
  if (uVar3 == 0) {
    if (uVar2 == 0) {
      uVar2 = 4;
    }
    else {
      mem_fill(uVar2);
      uVar2 = 0;
    }
  }
  else if (uVar3 == 0xff) {
    if (uVar2 == 0) {
      uVar2 = 8;
    }
    else {
      uVar2 = 0xc;
    }
  }
  else {
    uVar2 = 0;
  }
  uVar1 = param_2 & 0x7fffff;
  uVar3 = (param_2 << 1) >> 0x18;
  if (uVar3 == 0) {
    if (uVar1 == 0) {
      uVar3 = 1;
LAB_100487b2:
                    /* WARNING: Could not recover jumptable at 0x100487c4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (**(code **)(PTR_PTR_LAB_10048928 + (uVar2 | uVar3) * 4))();
      return;
    }
    mem_fill(uVar1);
    uVar3 = 0;
  }
  else if (uVar3 == 0xff) {
    if (uVar1 == 0) {
      uVar3 = 2;
      goto LAB_100487b2;
    }
    uVar3 = 3;
  }
  else {
    uVar3 = 0;
  }
                    /* WARNING: Could not recover jumptable at 0x10048762. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(PTR_PTR_LAB_10048924 + (uVar2 | uVar3) * 4))();
  return;
}

// FUNC 0x10048930  fmt_int_3

uint fmt_int_3(uint param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  
  uVar4 = param_1 & 0x7fffff;
  uVar5 = (param_1 << 1) >> 0x18;
  if (uVar5 == 0) {
    if (uVar4 == 0) {
      uVar7 = 4;
    }
    else {
      iVar6 = mem_fill(uVar4);
      uVar4 = uVar4 << (iVar6 - 5U & 0xff);
      uVar5 = -(iVar6 + 0x76);
      uVar7 = 0;
    }
  }
  else if (uVar5 == 0xff) {
    if (uVar4 == 0) {
      uVar7 = 8;
    }
    else {
      uVar7 = 0xc;
    }
  }
  else {
    uVar7 = 0;
    uVar4 = uVar4 << 3 | 0x4000000;
    uVar5 = uVar5 - 0x7f;
  }
  uVar3 = param_2 & 0x7fffff;
  uVar2 = (param_2 << 1) >> 0x18;
  if (uVar2 == 0) {
    uVar1 = 1;
    if (uVar3 != 0) {
      iVar6 = mem_fill(uVar3);
      uVar3 = uVar3 << (iVar6 - 5U & 0xff);
      uVar2 = -(iVar6 + 0x76);
      uVar1 = 0;
    }
  }
  else if (uVar2 == 0xff) {
    uVar1 = 3 - (uVar3 == 0);
  }
  else {
    uVar1 = 0;
    uVar3 = uVar3 << 3 | 0x4000000;
    uVar2 = uVar2 - 0x7f;
  }
  if ((uVar7 | uVar1) < 0x10) {
                    /* WARNING: Could not recover jumptable at 0x10048998. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar5 = (**(code **)(lit_rodata_10057000 + (uVar7 | uVar1) * 4))();
    return uVar5;
  }
  uVar1 = (uVar4 >> 0x10) * (uVar3 & 0xffff);
  uVar7 = (uVar4 & 0xffff) * (uVar3 & 0xffff);
  iVar6 = (uVar3 >> 0x10) * (uVar4 >> 0x10);
  uVar4 = (uVar7 >> 0x10) + (uVar4 & 0xffff) * (uVar3 >> 0x10) + uVar1;
  if (uVar4 <= uVar1 && uVar1 - uVar4 != 0) {
    iVar6 = iVar6 + 0x10000;
  }
  uVar3 = uVar4 * 0x10000 + (uVar7 & 0xffff);
  uVar7 = (uint)((uVar3 & 0x3ffffff) != 0);
  uVar3 = uVar3 >> 0x1a;
  uVar4 = ((uVar4 >> 0x10) + iVar6) * 0x40 | uVar3 | uVar7;
  iVar6 = uVar5 + uVar2;
  if ((int)(uVar4 << 4) < 0) {
    uVar4 = uVar3 & 1 | uVar7 | uVar4 >> 1;
    iVar6 = uVar5 + uVar2 + 1;
  }
  uVar5 = iVar6 + 0x7f;
  if ((int)uVar5 < 1) {
    uVar5 = 1 - uVar5;
    if ((int)uVar5 < 0x1c) {
      uVar7 = uVar4 >> (uVar5 & 0xff);
      uVar5 = (uint)(uVar4 << (0x20 - uVar5 & 0xff) != 0);
      uVar4 = uVar7 | uVar5;
      if (((uVar7 & 7) != 0 || uVar5 != 0) && ((uVar7 & 0xf | uVar5) != 4)) {
        uVar4 = uVar4 + 4;
      }
      if ((int)(uVar4 << 5) < 0) {
        uVar5 = 1;
        uVar4 = 0;
      }
      else {
        uVar4 = (uVar4 << 6) >> 9;
        uVar5 = 0;
      }
    }
    else {
      uVar5 = 0;
      uVar4 = 0;
    }
  }
  else {
    if (((uVar4 & 7) != 0) && ((uVar4 & 0xf) != 4)) {
      uVar4 = uVar4 + 4;
    }
    if ((int)(uVar4 << 4) < 0) {
      uVar5 = iVar6 + 0x80;
      uVar4 = uVar4 & lit_mask_f7ffffff;
    }
    if ((int)uVar5 < 0xff) {
      uVar4 = (uVar4 << 6) >> 9;
      uVar5 = uVar5 & 0xff;
    }
    else {
      uVar5 = 0xff;
      uVar4 = 0;
    }
  }
  return uVar4 | uVar5 << 0x17 | (param_2 ^ param_1) & 0x80000000;
}

// FUNC 0x10048b58  fmt_int

uint fmt_int(uint param_1,uint param_2)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  
  uVar6 = (param_1 << 1) >> 0x18;
  uVar7 = -((int)param_1 >> 0x1f);
  uVar5 = (param_1 << 9) >> 6;
  uVar8 = (param_2 << 1) >> 0x18;
  uVar3 = param_2 >> 0x1f;
  uVar4 = (param_2 << 9) >> 6;
  if ((uVar8 != 0xff) || (uVar4 == 0)) {
    uVar3 = uVar3 ^ 1;
  }
  uVar1 = uVar6 - uVar8;
  uVar9 = uVar5;
  if (uVar3 == uVar7) {
    if ((int)uVar1 < 1) {
      if (uVar1 != 0) {
        if (uVar6 == 0) {
          uVar9 = uVar4;
          uVar6 = uVar8;
          if (uVar5 == 0) goto LAB_10048b8e;
          uVar1 = ~uVar1;
          if (uVar1 == 0) goto LAB_10048daa;
          if (uVar8 != 0xff) goto LAB_10048d96;
        }
        else if (uVar8 != 0xff) {
          uVar1 = -uVar1;
          uVar5 = uVar5 | 0x4000000;
LAB_10048d96:
          if ((int)uVar1 < 0x1c) {
            uVar5 = (uint)(uVar5 << (0x20 - uVar1 & 0xff) != 0) | uVar5 >> (uVar1 & 0xff);
          }
          else {
            uVar5 = 1;
          }
LAB_10048daa:
          uVar9 = uVar5 + uVar4;
          goto LAB_10048c62;
        }
LAB_10048e36:
        uVar9 = uVar4;
        uVar6 = 0xff;
        goto LAB_10048b8e;
      }
      uVar1 = uVar6 + 1;
      if ((uVar1 & 0xff) < 2) {
        if (uVar6 == 0) {
          uVar9 = uVar4;
          if ((uVar5 != 0) && (uVar9 = uVar5, uVar4 != 0)) {
            uVar9 = uVar5 + uVar4;
            uVar8 = uVar6;
            uVar3 = uVar7;
            if (-1 < (int)(uVar9 * 0x20)) goto LAB_10048c14;
            uVar9 = uVar9 & lit_mask_fbffffff_8e60;
            uVar6 = uVar1;
          }
        }
        else {
          if (uVar5 == 0) goto LAB_10048e36;
          uVar6 = 0xff;
          if (uVar4 != 0) {
            uVar6 = param_1 & 0x7fffff;
            if (((param_1 & 0x400000) != 0) && ((param_2 & 0x400000) == 0)) {
              uVar6 = param_2 & 0x7fffff;
            }
            uVar9 = uVar6 << 3;
            uVar6 = 0xff;
            uVar7 = uVar3;
          }
        }
        goto LAB_10048b8e;
      }
      if (uVar1 != 0xff) {
        uVar9 = uVar5 + uVar4 >> 1;
        uVar6 = uVar1;
        goto LAB_10048b8e;
      }
    }
    else {
      if (uVar8 == 0) {
        if (uVar4 != 0) {
          uVar1 = uVar1 - 1;
          if (uVar1 == 0) goto LAB_10048c60;
          if (uVar6 != 0xff) goto LAB_10048c4a;
        }
      }
      else if (uVar6 != 0xff) {
        uVar4 = uVar4 | 0x4000000;
LAB_10048c4a:
        if ((int)uVar1 < 0x1c) {
          uVar4 = (uint)(uVar4 << (0x20 - uVar1 & 0xff) != 0) | uVar4 >> (uVar1 & 0xff);
        }
        else {
          uVar4 = 1;
        }
LAB_10048c60:
        uVar9 = uVar5 + uVar4;
        uVar8 = uVar6;
LAB_10048c62:
        if (-1 < (int)(uVar9 << 5)) goto LAB_10048c14;
        if (uVar8 + 1 == 0xff) goto LAB_10048d4a;
        uVar9 = uVar9 >> 1 & mask_clear_bits25_30_2 | uVar9 & 1;
        uVar6 = uVar8 + 1;
        uVar7 = uVar3;
      }
LAB_10048b8e:
      uVar8 = uVar6;
      uVar3 = uVar7;
      if ((uVar9 & 7) != 0) {
LAB_10048b92:
        if ((uVar9 & 0xf) != 4) {
          uVar9 = uVar9 + 4;
        }
      }
      uVar6 = uVar8;
      if ((int)(uVar9 << 5) < 0) {
        if (uVar8 + 1 == 0xff) {
          uVar9 = 0;
          uVar6 = 0xff;
        }
        else {
          uVar9 = (uVar9 << 6) >> 9;
          uVar6 = uVar8 + 1 & 0xff;
        }
        goto LAB_10048bb2;
      }
LAB_10048c18:
      uVar9 = uVar9 >> 3;
      if (uVar6 != 0xff) goto LAB_10048c8a;
      if (uVar9 != 0) {
LAB_10048c28:
        uVar9 = uVar9 & 0x7fffff | 0x400000;
        uVar6 = 0xff;
        goto LAB_10048bb2;
      }
    }
LAB_10048d4a:
    uVar6 = 0xff;
    uVar9 = 0;
  }
  else {
    if (0 < (int)uVar1) {
      if (uVar8 == 0) {
        if (uVar4 != 0) {
          uVar1 = uVar1 - 1;
          if (uVar1 == 0) goto LAB_10048be2;
          if (uVar6 != 0xff) goto LAB_10048bcc;
        }
      }
      else if (uVar6 != 0xff) {
        uVar4 = uVar4 | 0x4000000;
LAB_10048bcc:
        if ((int)uVar1 < 0x1c) {
          uVar4 = (uint)(uVar4 << (0x20 - uVar1 & 0xff) != 0) | uVar4 >> (uVar1 & 0xff);
        }
        else {
          uVar4 = 1;
        }
LAB_10048be2:
        uVar9 = uVar5 - uVar4;
        goto LAB_10048be4;
      }
      goto LAB_10048b8e;
    }
    if (uVar1 != 0) {
      if (uVar6 == 0) {
        uVar9 = uVar4;
        uVar6 = uVar8;
        uVar7 = uVar3;
        if (uVar5 == 0) goto LAB_10048b8e;
        uVar1 = ~uVar1;
        if (uVar1 != 0) {
          if (uVar8 == 0xff) goto LAB_10048d40;
          goto LAB_10048d08;
        }
      }
      else {
        if (uVar8 == 0xff) {
LAB_10048d40:
          uVar9 = uVar4;
          uVar6 = 0xff;
          uVar7 = uVar3;
          goto LAB_10048b8e;
        }
        uVar1 = -uVar1;
        uVar5 = uVar5 | 0x4000000;
LAB_10048d08:
        if ((int)uVar1 < 0x1c) {
          uVar5 = (uint)(uVar5 << (0x20 - uVar1 & 0xff) != 0) | uVar5 >> (uVar1 & 0xff);
        }
        else {
          uVar5 = 1;
        }
      }
      uVar9 = uVar4 - uVar5;
      uVar6 = uVar8;
      uVar7 = uVar3;
LAB_10048be4:
      uVar8 = uVar6;
      uVar3 = uVar7;
      if ((int)(uVar9 << 5) < 0) {
        uVar9 = uVar9 & 0x3ffffff;
        goto LAB_10048bec;
      }
LAB_10048c14:
      uVar6 = uVar8;
      if ((uVar9 & 7) != 0) goto LAB_10048b92;
      goto LAB_10048c18;
    }
    if (1 < (uVar6 + 1 & 0xff)) {
      uVar9 = uVar5 - uVar4;
      if ((uVar9 & 0x4000000) == 0) {
        if (uVar9 == 0) {
          uVar3 = 0;
          uVar6 = 0;
          uVar9 = 0;
          goto LAB_10048c8a;
        }
      }
      else {
        uVar9 = uVar4 - uVar5;
        uVar7 = uVar3;
      }
LAB_10048bec:
      iVar2 = mem_fill(uVar9);
      uVar8 = iVar2 - 5;
      uVar9 = uVar9 << (uVar8 & 0xff);
      if ((int)uVar8 < (int)uVar6) {
        uVar9 = lit_mask_fbffffff_8e60 & uVar9;
        uVar6 = uVar6 - uVar8;
      }
      else {
        uVar6 = (uVar8 - uVar6) + 1;
        uVar9 = uVar9 >> (uVar6 & 0xff) | (uint)(uVar9 << (0x20 - uVar6 & 0xff) != 0);
        uVar6 = 0;
      }
      goto LAB_10048b8e;
    }
    if (uVar6 != 0) {
      if (uVar5 != 0) {
        uVar6 = 0xff;
        if (uVar4 != 0) {
          uVar6 = param_1 & 0x7fffff;
          if (((param_1 & 0x400000) != 0) && ((param_2 & 0x400000) == 0)) {
            uVar6 = param_2 & 0x7fffff;
            uVar7 = uVar3;
          }
          uVar9 = uVar6 << 3;
          uVar6 = 0xff;
        }
        goto LAB_10048b8e;
      }
      if (uVar4 != 0) {
        uVar9 = uVar4;
        uVar6 = 0xff;
        uVar7 = uVar3;
        goto LAB_10048b8e;
      }
      uVar3 = 0;
      uVar9 = 0x400000;
      goto LAB_10048c28;
    }
    if (uVar5 != 0) {
      if (uVar4 != 0) {
        uVar9 = uVar5 - uVar4;
        if ((uVar9 & 0x4000000) == 0) {
          uVar8 = uVar6;
          uVar3 = uVar7;
          if (uVar9 != 0) goto LAB_10048c14;
          uVar3 = 0;
          uVar9 = 0;
          goto LAB_10048c8a;
        }
        uVar9 = uVar4 - uVar5;
        uVar7 = uVar3;
      }
      goto LAB_10048b8e;
    }
    uVar9 = uVar4;
    uVar7 = uVar3;
    if (uVar4 != 0) goto LAB_10048b8e;
    uVar9 = 0;
    uVar3 = 0;
LAB_10048c8a:
    uVar9 = uVar9 & 0x7fffff;
    uVar6 = uVar6 & 0xff;
  }
LAB_10048bb2:
  return uVar9 | uVar6 << 0x17 | uVar3 << 0x1f;
}

// FUNC 0x10048e64  fmt_int_15

uint fmt_int_15(uint param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar3 = (param_1 << 1) >> 0x18;
  uVar1 = 0;
  if (0x7e < uVar3) {
    if (uVar3 < 0x9e) {
      uVar2 = param_1 & 0x7fffff | 0x800000;
      if (uVar3 < 0x96) {
        uVar2 = uVar2 >> (0x96 - uVar3 & 0xff);
      }
      else {
        uVar2 = uVar2 << (uVar3 - 0x96 & 0xff);
      }
      uVar1 = -uVar2;
      if (-1 < (int)param_1) {
        uVar1 = uVar2;
      }
    }
    else {
      uVar1 = lit_mask_7fffffff_8ea4 - ((int)param_1 >> 0x1f);
    }
  }
  return uVar1;
}

// FUNC 0x10048ea8  log_rotate

uint log_rotate(uint param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  if (param_1 == 0) {
    param_1 = 0;
    uVar3 = 0;
    uVar4 = 0;
  }
  else {
    uVar4 = param_1 + ((int)param_1 >> 0x1f) ^ (int)param_1 >> 0x1f;
    param_1 = param_1 >> 0x1f;
    iVar1 = mem_fill(uVar4);
    uVar3 = 0x9e - iVar1;
    if ((int)uVar3 < 0x97) {
      uVar4 = uVar4 << (0x96 - uVar3 & 0xff) & 0x7fffff;
      uVar3 = uVar3 & 0xff;
    }
    else {
      if ((int)uVar3 < 0x9a) {
        uVar4 = uVar4 << (0x99 - uVar3 & 0xff);
      }
      else {
        uVar4 = uVar4 >> (5U - iVar1 & 0xff) | (uint)(uVar4 << (0xb9 - uVar3 & 0xff) != 0);
      }
      uVar2 = lit_mask_fbffffff_8f34 & uVar4;
      if (((uVar4 & 7) != 0) && ((uVar4 & 0xf) != 4)) {
        uVar2 = uVar2 + 4;
      }
      if ((int)(uVar2 << 5) < 0) {
        uVar2 = uVar2 & lit_mask_fbffffff_8f34;
        uVar3 = 0x9f - iVar1;
      }
      uVar4 = (uVar2 << 6) >> 9;
      uVar3 = uVar3 & 0xff;
    }
  }
  return uVar4 | uVar3 << 0x17 | param_1 << 0x1f;
}

// FUNC 0x10048f38  fmt_int_2

uint fmt_int_2(uint param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  if (param_1 == 0) {
    uVar3 = 0;
    uVar2 = 0;
  }
  else {
    iVar1 = mem_fill();
    uVar3 = 0x9e - iVar1;
    if ((int)uVar3 < 0x97) {
      uVar2 = param_1 << (0x96 - uVar3 & 0xff) & 0x7fffff;
      uVar3 = uVar3 & 0xff;
    }
    else {
      if ((int)uVar3 < 0x9a) {
        param_1 = param_1 << (0x99 - uVar3 & 0xff);
      }
      else {
        param_1 = param_1 >> (5U - iVar1 & 0xff) | (uint)(param_1 << (0xb9 - uVar3 & 0xff) != 0);
      }
      uVar2 = lit_mask_fbffffff_8fb0 & param_1;
      if (((param_1 & 7) != 0) && ((param_1 & 0xf) != 4)) {
        uVar2 = uVar2 + 4;
      }
      if ((int)(uVar2 << 5) < 0) {
        uVar2 = uVar2 & lit_mask_fbffffff_8fb0;
        uVar3 = 0x9f - iVar1;
      }
      uVar2 = (uVar2 << 6) >> 9;
      uVar3 = uVar3 & 0xff;
    }
  }
  return uVar3 << 0x17 | uVar2;
}

// FUNC 0x10048fb4  fmt_int_4

undefined8 fmt_int_4(uint param_1,uint param_2,uint param_3,uint param_4)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  
  iVar9 = -((int)param_2 >> 0x1f);
  uVar10 = param_1 >> 0x1d;
  uVar13 = (param_4 << 1) >> 0x15;
  uVar3 = (param_2 << 0xc) >> 9 | uVar10;
  uVar11 = param_1 * 8;
  uVar14 = param_3 >> 0x1d;
  uVar8 = (param_2 << 1) >> 0x15;
  iVar6 = -((int)param_4 >> 0x1f);
  uVar1 = (param_4 << 0xc) >> 9 | uVar14;
  uVar5 = param_3 * 8;
  uVar4 = uVar3;
  uVar12 = uVar11;
  if (iVar9 == iVar6) {
    uVar7 = uVar8 - uVar13;
    if (0 < (int)uVar7) {
      if (uVar13 == 0) {
        if (uVar1 != 0 || uVar5 != 0) {
          uVar7 = uVar7 - 1;
          if (uVar7 == 0) {
            uVar10 = uVar11 + uVar5;
            uVar4 = (uint)(uVar10 < uVar11) + uVar3 + uVar1;
            goto LAB_10049184;
          }
          if (uVar8 != lit_mask_000007ff_9604) goto LAB_10049164;
        }
      }
      else if (uVar8 != lit_mask_000007ff) {
        uVar1 = uVar1 | 0x800000;
LAB_10049164:
        if ((int)uVar7 < 0x39) {
          if ((int)uVar7 < 0x20) {
            uVar10 = (uint)(uVar5 << (0x20 - uVar7 & 0xff) != 0) |
                     uVar1 << (0x20 - uVar7 & 0xff) | uVar5 >> (uVar7 & 0xff);
            uVar1 = uVar1 >> (uVar7 & 0xff);
          }
          else {
            if (uVar7 == 0x20) {
              iVar6 = 0;
            }
            else {
              iVar6 = uVar1 << (0x40 - uVar7 & 0xff);
            }
            uVar10 = uVar1 >> (uVar7 - 0x20 & 0xff) | (uint)(uVar5 != 0 || iVar6 != 0);
            uVar1 = 0;
          }
        }
        else {
          uVar10 = (uint)(uVar5 != 0 || uVar1 != 0);
          uVar1 = 0;
        }
        uVar10 = uVar10 + uVar11;
        uVar4 = (uint)(uVar10 < uVar11) + uVar1 + uVar3;
LAB_10049184:
        if (-1 < (int)(uVar4 << 8)) goto LAB_10049124;
        uVar13 = uVar8 + 1;
        if (uVar13 == lit_mask_000007ff) goto LAB_1004940e;
        uVar11 = lit_mask_ff7fffff & uVar4;
        uVar4 = uVar11 >> 1;
        uVar8 = uVar13;
        uVar12 = uVar11 << 0x1f | uVar10 & 1 | uVar10 >> 1;
      }
LAB_10049006:
      uVar10 = uVar12;
      if ((uVar12 & 7) != 0) {
LAB_1004900a:
        uVar10 = uVar12;
        if ((uVar12 & 0xf) != 4) {
          uVar10 = uVar12 + 4;
          uVar4 = uVar4 + (uVar10 < uVar12);
        }
      }
      if ((int)(uVar4 << 8) < 0) {
        uVar8 = uVar8 + 1;
        if (uVar8 == lit_mask_000007ff) {
          uVar11 = 0;
          uVar12 = 0;
        }
        else {
          uVar12 = uVar10 >> 3 | (uVar4 & lit_mask_ff7fffff) << 0x1d;
          uVar11 = ((uVar4 & lit_mask_ff7fffff) << 9) >> 0xc;
          uVar8 = uVar8 & 0x7ff;
        }
        goto LAB_10049044;
      }
      goto LAB_1004912a;
    }
    if (uVar7 != 0) {
      if (uVar8 == 0) {
        uVar4 = uVar1;
        uVar8 = uVar13;
        uVar12 = uVar5;
        if (uVar3 != 0 || uVar11 != 0) {
          uVar7 = ~uVar7;
          if (uVar7 == 0) goto LAB_1004949c;
          if (uVar13 != lit_mask_000007ff_9604) goto LAB_1004946c;
        }
      }
      else {
        uVar4 = uVar1;
        uVar8 = uVar13;
        uVar12 = uVar5;
        if (uVar13 != lit_mask_000007ff_9604) {
          uVar7 = -uVar7;
          uVar3 = uVar3 | 0x800000;
LAB_1004946c:
          if ((int)uVar7 < 0x39) {
            if ((int)uVar7 < 0x20) {
              uVar12 = uVar3 << (0x20 - uVar7 & 0xff);
              uVar3 = uVar3 >> (uVar7 & 0xff);
              uVar11 = (uint)(uVar11 << (0x20 - uVar7 & 0xff) != 0) |
                       uVar12 | uVar11 >> (uVar7 & 0xff);
            }
            else {
              uVar12 = uVar3 >> (uVar7 - 0x20 & 0xff);
              if (uVar7 == 0x20) {
                iVar6 = 0;
              }
              else {
                iVar6 = uVar3 << (0x40 - uVar7 & 0xff);
              }
              uVar3 = 0;
              uVar11 = (uVar11 != 0 || iVar6 != 0) | uVar12;
            }
          }
          else {
            uVar11 = (uint)(uVar11 != 0 || uVar3 != 0);
            uVar3 = 0;
          }
LAB_1004949c:
          uVar10 = uVar11 + uVar5;
          uVar4 = (uint)(uVar10 < uVar5) + uVar3 + uVar1;
          uVar8 = uVar13;
          goto LAB_10049184;
        }
      }
      goto LAB_10049006;
    }
    uVar13 = uVar8 + 1;
    if ((uVar13 & 0x7ff) < 2) {
      if (uVar8 == 0) {
        uVar4 = uVar1;
        uVar12 = uVar5;
        if ((uVar3 != 0 || uVar11 != 0) &&
           (uVar4 = uVar3, uVar12 = uVar11, uVar1 != 0 || uVar5 != 0)) {
          uVar10 = uVar11 + uVar5;
          uVar4 = (uint)(uVar10 < uVar11) + uVar3 + uVar1;
          if (-1 < (int)(uVar4 * 0x100)) goto LAB_10049124;
          uVar4 = uVar4 & lit_mask_ff7fffff_9608;
          uVar8 = uVar13;
          uVar12 = uVar10;
        }
      }
      else {
        uVar4 = uVar1;
        uVar8 = lit_mask_000007ff_9604;
        uVar12 = uVar5;
        if ((uVar3 != 0 || uVar11 != 0) &&
           (uVar4 = uVar3, uVar12 = uVar11, uVar1 != 0 || uVar5 != 0)) {
          uVar12 = uVar10 << 0x1d | param_1 & 0x1fffffff;
          uVar11 = param_2 & 0xfffff;
          if (((param_2 & 0x80000) != 0) && ((param_4 & 0x80000) == 0)) {
            uVar12 = uVar14 << 0x1d | param_3 & 0x1fffffff;
            uVar11 = param_4 & 0xfffff;
          }
          uVar4 = uVar11 << 3 | uVar12 >> 0x1d;
          uVar12 = uVar12 << 3;
        }
      }
      goto LAB_10049006;
    }
    if (uVar13 != lit_mask_000007ff) {
      uVar12 = (uint)(uVar11 + uVar5 < uVar11) + uVar3 + uVar1;
      uVar4 = uVar12 >> 1;
      uVar8 = uVar13;
      uVar12 = uVar12 * -0x80000000 | uVar11 + uVar5 >> 1;
      goto LAB_10049006;
    }
LAB_1004940e:
    uVar11 = 0;
    uVar12 = 0;
    uVar8 = uVar13;
  }
  else {
    uVar7 = uVar8 - uVar13;
    if ((int)uVar7 < 1) {
      if (uVar7 == 0) {
        if ((uVar8 + 1 & 0x7ff) < 2) {
          if (uVar8 == 0) {
            if (uVar3 == 0 && uVar11 == 0) {
              uVar4 = uVar1;
              uVar12 = uVar5;
              iVar9 = iVar6;
              if (uVar1 == 0 && uVar5 == 0) {
LAB_1004958a:
                uVar11 = 0;
                iVar9 = 0;
                uVar12 = 0;
                goto LAB_10049134;
              }
            }
            else if (uVar1 != 0 || uVar5 != 0) {
              uVar10 = uVar11 + param_3 * -8;
              uVar4 = (uVar3 - uVar1) - (uint)(uVar11 < uVar10);
              if (-1 < (int)(uVar4 * 0x100)) {
                if (uVar10 != 0 || uVar4 != 0) goto LAB_10049124;
                goto LAB_1004958a;
              }
              uVar12 = uVar5 + param_1 * -8;
              uVar4 = (uVar1 - uVar3) - (uint)(uVar5 < uVar12);
              iVar9 = iVar6;
            }
          }
          else if (uVar3 == 0 && uVar11 == 0) {
            uVar4 = uVar1;
            uVar8 = lit_mask_000007ff_9604;
            uVar12 = uVar5;
            iVar9 = iVar6;
            if (uVar1 == 0 && uVar5 == 0) {
              iVar9 = 0;
              uVar11 = 0x80000;
              uVar12 = 0;
              goto LAB_10049134;
            }
          }
          else {
            uVar8 = lit_mask_000007ff_9604;
            if (uVar1 != 0 || uVar5 != 0) {
              uVar12 = uVar10 << 0x1d | param_1 & 0x1fffffff;
              uVar11 = param_2 & 0xfffff;
              if (((param_2 & 0x80000) != 0) && ((param_4 & 0x80000) == 0)) {
                uVar12 = uVar14 << 0x1d | param_3 & 0x1fffffff;
                uVar11 = param_4 & 0xfffff;
                iVar9 = iVar6;
              }
              uVar4 = uVar11 << 3 | uVar12 >> 0x1d;
              uVar12 = uVar12 << 3;
            }
          }
        }
        else {
          uVar10 = uVar11 + param_3 * -8;
          uVar4 = (uVar3 - uVar1) - (uint)(uVar11 < uVar10);
          if ((int)(uVar4 * 0x100) < 0) {
            uVar10 = uVar5 + param_1 * -8;
            uVar4 = (uVar1 - uVar3) - (uint)(uVar5 < uVar10);
            iVar9 = iVar6;
          }
          else if (uVar10 == 0 && uVar4 == 0) {
            iVar9 = 0;
            uVar8 = 0;
            uVar12 = 0;
            uVar11 = 0;
            goto LAB_10049134;
          }
LAB_100490c4:
          if (uVar4 == 0) {
            iVar2 = mem_fill(uVar10);
            iVar6 = iVar2 + 0x20;
            uVar11 = iVar2 + 0x18;
            if ((int)uVar11 < 0x20) goto LAB_100490da;
LAB_10049246:
            uVar10 = uVar10 << (iVar6 - 0x28U & 0xff);
            uVar12 = 0;
          }
          else {
            iVar6 = mem_fill(uVar4);
            uVar11 = iVar6 - 8;
            if (0x1f < (int)uVar11) goto LAB_10049246;
LAB_100490da:
            uVar12 = uVar10 << (uVar11 & 0xff);
            uVar10 = uVar10 >> (0x20 - uVar11 & 0xff) | uVar4 << (uVar11 & 0xff);
          }
          if ((int)uVar11 < (int)uVar8) {
            uVar4 = lit_mask_ff7fffff & uVar10;
            uVar8 = uVar8 - uVar11;
          }
          else {
            uVar1 = (uVar11 - uVar8) + 1;
            if (0x1f < (int)uVar1) {
              if (uVar1 == 0x20) {
                iVar6 = 0;
              }
              else {
                iVar6 = uVar10 << (0x40 - uVar1 & 0xff);
              }
              uVar4 = 0;
              uVar10 = (uint)(uVar12 != 0 || iVar6 != 0) |
                       uVar10 >> ((uVar11 - uVar8) - 0x1f & 0xff);
              uVar8 = 0;
              goto LAB_10049124;
            }
            uVar4 = uVar10 >> (uVar1 & 0xff);
            uVar8 = 0;
            uVar12 = (uint)(uVar12 << (0x20 - uVar1 & 0xff) != 0) |
                     uVar10 << (0x20 - uVar1 & 0xff) | uVar12 >> (uVar1 & 0xff);
          }
        }
      }
      else if (uVar8 == 0) {
        uVar4 = uVar1;
        uVar8 = uVar13;
        uVar12 = uVar5;
        iVar9 = iVar6;
        if (uVar3 != 0 || uVar11 != 0) {
          uVar7 = ~uVar7;
          if (uVar7 == 0) {
            uVar10 = uVar5 + param_1 * -8;
            uVar4 = (uVar1 - uVar3) - (uint)(uVar5 < uVar10);
            goto LAB_100490bc;
          }
          if (uVar13 != lit_mask_000007ff_9604) goto LAB_100492fc;
        }
      }
      else {
        uVar4 = uVar1;
        uVar8 = uVar13;
        uVar12 = uVar5;
        iVar9 = iVar6;
        if (uVar13 != lit_mask_000007ff) {
          uVar7 = -uVar7;
          uVar3 = uVar3 | 0x800000;
LAB_100492fc:
          if ((int)uVar7 < 0x39) {
            if ((int)uVar7 < 0x20) {
              uVar12 = uVar3 >> (uVar7 & 0xff);
              uVar10 = uVar11 >> (uVar7 & 0xff) | uVar3 << (0x20 - uVar7 & 0xff) |
                       (uint)(uVar11 << (0x20 - uVar7 & 0xff) != 0);
            }
            else {
              if (uVar7 == 0x20) {
                iVar9 = 0;
              }
              else {
                iVar9 = uVar3 << (0x40 - uVar7 & 0xff);
              }
              uVar12 = 0;
              uVar10 = uVar3 >> (uVar7 - 0x20 & 0xff) | (uint)(uVar11 != 0 || iVar9 != 0);
            }
          }
          else {
            uVar10 = (uint)(uVar11 != 0 || uVar3 != 0);
            uVar12 = 0;
          }
          uVar10 = uVar5 - uVar10;
          uVar4 = (uVar1 - uVar12) - (uint)(uVar5 < uVar10);
          uVar8 = uVar13;
          iVar9 = iVar6;
          goto LAB_100490bc;
        }
      }
      goto LAB_10049006;
    }
    if (uVar13 == 0) {
      if (uVar1 != 0 || uVar5 != 0) {
        uVar7 = uVar7 - 1;
        if (uVar7 == 0) {
          uVar10 = uVar11 + param_3 * -8;
          uVar4 = (uVar3 - uVar1) - (uint)(uVar11 < uVar10);
          goto LAB_100490bc;
        }
        if (uVar8 != lit_mask_000007ff) goto LAB_1004907e;
      }
      goto LAB_10049006;
    }
    if (uVar8 == lit_mask_000007ff) goto LAB_10049006;
    uVar1 = uVar1 | 0x800000;
LAB_1004907e:
    if ((int)uVar7 < 0x39) {
      if ((int)uVar7 < 0x20) {
        uVar10 = uVar5 >> (uVar7 & 0xff) | uVar1 << (0x20 - uVar7 & 0xff) |
                 (uint)(uVar5 << (0x20 - uVar7 & 0xff) != 0);
        uVar1 = uVar1 >> (uVar7 & 0xff);
      }
      else {
        if (uVar7 == 0x20) {
          iVar6 = 0;
        }
        else {
          iVar6 = uVar1 << (0x40 - uVar7 & 0xff);
        }
        uVar10 = uVar1 >> (uVar7 - 0x20 & 0xff) | (uint)(uVar5 != 0 || iVar6 != 0);
        uVar1 = 0;
      }
    }
    else {
      uVar10 = (uint)(uVar5 != 0 || uVar1 != 0);
      uVar1 = 0;
    }
    uVar10 = uVar11 - uVar10;
    uVar4 = (uVar3 - uVar1) - (uint)(uVar11 < uVar10);
LAB_100490bc:
    if ((int)(uVar4 << 8) < 0) {
      uVar4 = uVar4 & 0x7fffff;
      goto LAB_100490c4;
    }
LAB_10049124:
    uVar12 = uVar10;
    if ((uVar10 & 7) != 0) goto LAB_1004900a;
LAB_1004912a:
    uVar11 = uVar4 >> 3;
    uVar12 = uVar10 >> 3 | uVar4 << 0x1d;
  }
LAB_10049134:
  if (uVar8 == lit_mask_000007ff) {
    if (uVar12 == 0 && uVar11 == 0) {
      uVar11 = 0;
      uVar12 = 0;
    }
    else {
      uVar11 = uVar11 & 0xfffff | 0x80000;
    }
  }
  else {
    uVar11 = uVar11 & 0xfffff;
    uVar8 = uVar8 & 0x7ff;
  }
LAB_10049044:
  return CONCAT44(mask_float_high & uVar11 | (uVar8 << 0x15) >> 1 | iVar9 << 0x1f,uVar12);
}

// FUNC 0x1004960c  fmt_int_12

undefined8 fmt_int_12(uint param_1,uint param_2,uint param_3,uint param_4)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int extraout_r1;
  int extraout_r1_00;
  int extraout_r1_01;
  int extraout_r1_02;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  undefined8 uVar14;
  int local_3c;
  uint local_38;
  uint local_34;
  
  uVar12 = param_2 & 0xfffff;
  uVar10 = (param_2 << 1) >> 0x15;
  if (uVar10 == 0) {
    if (uVar12 == 0 && param_1 == 0) {
      uVar5 = 0;
      uVar13 = 4;
      uVar12 = 0;
    }
    else {
      if (uVar12 == 0) {
        iVar4 = mem_fill();
        iVar4 = iVar4 + 0x20;
      }
      else {
        iVar4 = mem_fill(uVar12);
      }
      if (iVar4 + -0xb < 0x1d) {
        uVar5 = param_1 << (iVar4 - 8U & 0xff);
        uVar12 = uVar12 << (iVar4 - 8U & 0xff) | param_1 >> (0x1dU - (iVar4 + -0xb) & 0xff);
      }
      else {
        uVar12 = param_1 << (iVar4 - 0x28U & 0xff);
        uVar5 = 0;
      }
      uVar13 = 0;
      uVar10 = -(iVar4 + fmt_const_03f3);
    }
  }
  else if (uVar10 == lit_mask_000007ff_97e8) {
    if (param_1 == 0 && uVar12 == 0) {
      uVar5 = 0;
      uVar13 = 8;
      uVar12 = 0;
    }
    else {
      uVar13 = 0xc;
      uVar5 = param_1;
    }
  }
  else {
    uVar12 = uVar12 << 3 | param_1 >> 0x1d | 0x800000;
    uVar13 = 0;
    uVar10 = uVar10 + fmt_const_fffffc01;
    uVar5 = param_1 << 3;
  }
  uVar6 = param_4 & 0xfffff;
  uVar1 = (param_4 << 1) >> 0x15;
  if (uVar1 == 0) {
    if (uVar6 == 0 && param_3 == 0) {
      uVar6 = 0;
      param_3 = 0;
      uVar7 = 1;
    }
    else {
      if (uVar6 == 0) {
        iVar4 = mem_fill(param_3);
        iVar4 = iVar4 + 0x20;
      }
      else {
        iVar4 = mem_fill(uVar6);
      }
      if (iVar4 + -0xb < 0x1d) {
        uVar6 = param_3 >> (0x1dU - (iVar4 + -0xb) & 0xff) | uVar6 << (iVar4 - 8U & 0xff);
        param_3 = param_3 << (iVar4 - 8U & 0xff);
      }
      else {
        uVar6 = param_3 << (iVar4 - 0x28U & 0xff);
        param_3 = 0;
      }
      uVar1 = -(iVar4 + fmt_const_03f3);
      uVar7 = 0;
    }
  }
  else if (uVar1 == lit_mask_000007ff_97e8) {
    if (param_3 == 0 && uVar6 == 0) {
      param_3 = 0;
      uVar6 = 0;
      uVar7 = 2;
    }
    else {
      uVar7 = 3;
    }
  }
  else {
    uVar6 = param_3 >> 0x1d | 0x800000 | uVar6 << 3;
    param_3 = param_3 << 3;
    uVar7 = 0;
    uVar1 = uVar1 + fmt_const_fffffc01;
  }
  local_3c = uVar10 - uVar1;
  if ((uVar13 | uVar7) < 0x10) {
                    /* WARNING: Could not recover jumptable at 0x100496a0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar14 = (**(code **)(lit_rodata_10057040 + (uVar13 | uVar7) * 4))();
    return uVar14;
  }
  if ((uVar6 < uVar12) || ((uVar12 == uVar6 && (param_3 <= uVar5)))) {
    uVar10 = uVar12 << 0x1f;
    local_38 = uVar5 << 0x1f;
    uVar12 = uVar12 >> 1;
    uVar5 = uVar10 | uVar5 >> 1;
  }
  else {
    local_3c = local_3c + -1;
    local_38 = 0;
  }
  uVar6 = uVar6 << 8;
  uVar7 = uVar6 | param_3 >> 0x18;
  uVar10 = param_3 * 0x100;
  uVar13 = uVar6 >> 0x10;
  uVar6 = uVar6 & 0xffff | param_3 >> 0x18;
  iVar2 = fmt_int_18(uVar12,uVar13);
  uVar1 = iVar2 * uVar6;
  fmt_int_19(uVar12,uVar13);
  uVar12 = uVar5 >> 0x10 | extraout_r1 << 0x10;
  iVar4 = iVar2;
  if (uVar12 <= uVar1 && uVar1 - uVar12 != 0) {
    uVar12 = uVar12 + uVar7;
    iVar4 = iVar2 + -1;
    if ((uVar7 <= uVar12) && (uVar12 <= uVar1 && uVar1 - uVar12 != 0)) {
      iVar4 = iVar2 + -2;
      uVar12 = uVar12 + uVar7;
    }
  }
  uVar3 = fmt_int_18(uVar12 - uVar1,uVar13);
  uVar8 = uVar6 * uVar3;
  fmt_int_19(uVar12 - uVar1,uVar13);
  uVar5 = uVar5 & 0xffff | extraout_r1_00 << 0x10;
  uVar12 = uVar3;
  if (uVar5 <= uVar8 && uVar8 - uVar5 != 0) {
    uVar5 = uVar5 + uVar7;
    uVar12 = uVar3 - 1;
    if ((uVar7 <= uVar5) && (uVar5 <= uVar8 && uVar8 - uVar5 != 0)) {
      uVar5 = uVar5 + uVar7;
      uVar12 = uVar3 - 2;
    }
  }
  uVar5 = uVar5 - uVar8;
  uVar1 = uVar12 | iVar4 << 0x10;
  uVar9 = uVar10 >> 0x10;
  uVar3 = uVar10 & 0xffff;
  uVar11 = (uVar1 >> 0x10) * uVar3;
  uVar8 = (uVar12 & 0xffff) * uVar3;
  iVar4 = uVar9 * (uVar1 >> 0x10);
  uVar12 = (uVar8 >> 0x10) + uVar9 * (uVar12 & 0xffff) + uVar11;
  if (uVar12 <= uVar11 && uVar11 - uVar12 != 0) {
    iVar4 = iVar4 + 0x10000;
  }
  uVar11 = (uVar12 >> 0x10) + iVar4;
  uVar12 = uVar12 * 0x10000 + (uVar8 & 0xffff);
  if (uVar5 < uVar11) {
LAB_10049ab6:
    local_38 = local_38 + uVar10;
    uVar5 = (local_38 < uVar10) + uVar7 + uVar5;
    uVar8 = uVar1 - 1;
    if (uVar7 < uVar5) {
LAB_10049ad4:
      if (uVar11 <= uVar5) {
        if (uVar11 != uVar5) goto LAB_10049adc;
        if (uVar12 <= local_38) {
          iVar4 = 0;
          uVar1 = uVar8;
          goto LAB_100498fe;
        }
      }
      uVar1 = uVar1 - 2;
      local_38 = local_38 + uVar10;
      uVar5 = (local_38 < uVar10) + uVar7 + uVar5;
LAB_100498fc:
      iVar4 = uVar5 - uVar11;
    }
    else {
      if (uVar7 == uVar5) {
        if (local_38 < uVar10) {
          iVar4 = uVar7 - uVar11;
          uVar1 = uVar8;
          goto LAB_100498fe;
        }
        goto LAB_10049ad4;
      }
LAB_10049adc:
      iVar4 = uVar5 - uVar11;
      uVar1 = uVar8;
    }
  }
  else {
    if (uVar5 != uVar11) goto LAB_100498fc;
    iVar4 = 0;
    if (local_38 < uVar12) goto LAB_10049ab6;
  }
LAB_100498fe:
  uVar12 = local_38 - uVar12;
  uVar5 = iVar4 - (uint)(local_38 < uVar12);
  if (uVar7 == uVar5) {
    uVar13 = 0xffffffff;
  }
  else {
    iVar2 = fmt_int_18(uVar5,uVar13);
    uVar8 = iVar2 * uVar6;
    fmt_int_19(uVar5,uVar13);
    uVar5 = uVar12 >> 0x10 | extraout_r1_01 << 0x10;
    iVar4 = iVar2;
    if (uVar5 <= uVar8 && uVar8 - uVar5 != 0) {
      uVar5 = uVar5 + uVar7;
      iVar4 = iVar2 + -1;
      if ((uVar7 <= uVar5) && (uVar5 <= uVar8 && uVar8 - uVar5 != 0)) {
        iVar4 = iVar2 + -2;
        uVar5 = uVar5 + uVar7;
      }
    }
    uVar11 = fmt_int_18(uVar5 - uVar8,uVar13);
    uVar6 = uVar11 * uVar6;
    fmt_int_19(uVar5 - uVar8,uVar13);
    uVar5 = uVar12 & 0xffff | extraout_r1_02 << 0x10;
    uVar12 = uVar11;
    if (uVar5 <= uVar6 && uVar6 - uVar5 != 0) {
      uVar5 = uVar5 + uVar7;
      uVar12 = uVar11 - 1;
      if ((uVar7 <= uVar5) && (uVar5 <= uVar6 && uVar6 - uVar5 != 0)) {
        uVar12 = uVar11 - 2;
        uVar5 = uVar5 + uVar7;
      }
    }
    uVar8 = iVar4 << 0x10 | uVar12;
    uVar5 = uVar5 - uVar6;
    uVar13 = (uVar12 & 0xffff) * uVar3;
    uVar3 = (uVar8 >> 0x10) * uVar3;
    iVar4 = uVar9 * (uVar8 >> 0x10);
    uVar12 = (uVar13 >> 0x10) + uVar9 * (uVar12 & 0xffff) + uVar3;
    if (uVar12 <= uVar3 && uVar3 - uVar12 != 0) {
      iVar4 = iVar4 + 0x10000;
    }
    uVar6 = (uVar12 >> 0x10) + iVar4;
    uVar12 = uVar12 * 0x10000 + (uVar13 & 0xffff);
    if (uVar5 < uVar6) {
LAB_10049a68:
      uVar5 = uVar7 + uVar5;
      uVar13 = uVar8 - 1;
      local_34 = uVar10;
      if (uVar5 < uVar7) {
LAB_10049a70:
        if (uVar5 != uVar6) goto LAB_100499c8;
      }
      else {
        if (uVar5 < uVar6) {
LAB_10049b98:
          uVar13 = uVar8 - 2;
          local_34 = param_3 << 9;
          uVar5 = uVar5 + (local_34 < uVar10) + uVar7;
          goto LAB_10049a70;
        }
        if (uVar6 != uVar5) goto LAB_100499c8;
        if (uVar10 < uVar12) goto LAB_10049b98;
      }
      if (local_34 == uVar12) goto LAB_100499cc;
    }
    else {
      uVar13 = uVar8;
      if (uVar5 == uVar6) {
        if (uVar12 == 0) goto LAB_100499cc;
        goto LAB_10049a68;
      }
    }
LAB_100499c8:
    uVar13 = uVar13 | 1;
  }
LAB_100499cc:
  uVar10 = local_3c + lit_mask_000003ff_9c28;
  if (0 < (int)uVar10) {
    uVar12 = uVar13;
    if (((uVar13 & 7) != 0) && ((uVar13 & 0xf) != 4)) {
      uVar12 = uVar13 + 4;
      uVar1 = uVar1 + (uVar12 < uVar13);
    }
    if ((int)(uVar1 << 7) < 0) {
      uVar1 = uVar1 & lit_mask_feffffff;
      uVar10 = local_3c + 0x400;
    }
    if (fmt_const_07fe < (int)uVar10) {
      uVar5 = 0;
      uVar12 = 0;
      uVar10 = lit_mask_000007ff_97e8;
    }
    else {
      uVar12 = uVar1 << 0x1d | uVar12 >> 3;
      uVar5 = (uVar1 << 9) >> 0xc;
      uVar10 = uVar10 & 0x7ff;
    }
    goto LAB_100496d8;
  }
  uVar12 = 1 - uVar10;
  if (0x38 < (int)uVar12) {
    uVar5 = 0;
    uVar12 = 0;
    uVar10 = 0;
    goto LAB_100496d8;
  }
  if ((int)uVar12 < 0x20) {
    uVar5 = uVar13 >> (uVar12 & 0xff) | uVar1 << (0x20 - uVar12 & 0xff);
    uVar10 = (uint)(uVar13 << (0x20 - uVar12 & 0xff) != 0);
    uVar6 = uVar10 | uVar5;
    uVar1 = uVar1 >> (uVar12 & 0xff);
    if ((uVar10 != 0 || (uVar5 & 7) != 0) && (uVar12 = uVar6, (uVar10 | uVar5 & 0xf) != 4)) {
LAB_10049b5a:
      uVar6 = uVar12 + 4;
      uVar1 = uVar1 + (uVar6 < uVar12);
    }
    if ((int)(uVar1 << 8) < 0) {
      uVar12 = 0;
      uVar5 = 0;
      uVar10 = 1;
      goto LAB_100496d8;
    }
LAB_10049be2:
    uVar12 = uVar1 << 0x1d;
    uVar5 = (uVar1 << 9) >> 0xc;
  }
  else {
    uVar10 = uVar1 >> (-uVar10 - 0x1f & 0xff);
    if (uVar12 == 0x20) {
      iVar4 = 0;
    }
    else {
      iVar4 = uVar1 << (0x40 - uVar12 & 0xff);
    }
    uVar13 = (uint)(uVar13 != 0 || iVar4 != 0);
    uVar6 = uVar10 | uVar13;
    uVar12 = uVar10 & 7 | uVar13;
    uVar5 = 0;
    if (uVar12 != 0) {
      uVar1 = 0;
      uVar12 = uVar6;
      if ((uVar10 & 0xf | uVar13) != 4) goto LAB_10049b5a;
      goto LAB_10049be2;
    }
  }
  uVar12 = uVar6 >> 3 | uVar12;
  uVar10 = 0;
LAB_100496d8:
  return CONCAT44(uVar5 & mask_float_high_2 | (uVar10 & 0x7ff) << 0x14 | (param_2 ^ param_4) & 0x80000000
                  ,uVar12);
}

// FUNC 0x10049c38  log_cmp

bool log_cmp(int param_1,uint param_2,int param_3,uint param_4)

{
  bool bVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar4 = param_2 & 0xfffff;
  uVar3 = (param_2 << 1) >> 0x15;
  uVar2 = (param_4 << 1) >> 0x15;
  if ((((uVar3 != lit_mask_000007ff_9cb4) || (bVar1 = true, uVar4 == 0 && param_1 == 0)) &&
      ((uVar2 != lit_mask_000007ff_9cb4 || (bVar1 = true, param_3 == 0 && (param_4 & 0xfffff) == 0)))) &&
     (((bVar1 = true, uVar3 == uVar2 && (uVar4 == (param_4 & 0xfffff))) && (param_1 == param_3)))) {
    if (-((int)param_2 >> 0x1f) == -((int)param_4 >> 0x1f)) {
      bVar1 = false;
    }
    else if (uVar3 == 0) {
      bVar1 = param_1 != 0 || uVar4 != 0;
    }
  }
  return bVar1;
}

// FUNC 0x10049cb8  log_state_check

uint log_state_check(uint param_1,uint param_2,uint param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar1 = param_4 & 0xfffff;
  uVar4 = param_2 & 0xfffff;
  uVar3 = (param_2 << 1) >> 0x15;
  uVar2 = (param_4 << 1) >> 0x15;
  if (((uVar3 == lit_mask_000007ff_9d7c) && (uVar4 != 0 || param_1 != 0)) ||
     ((uVar2 == lit_mask_000007ff_9d7c && (uVar1 != 0 || param_3 != 0)))) {
    return 0xfffffffe;
  }
  if (uVar3 == 0) {
    if ((uVar2 == 0) && (param_3 == 0 && uVar1 == 0)) {
      if (param_1 == 0 && uVar4 == 0) {
        return 0;
      }
      goto LAB_10049d1a;
    }
    if (param_1 == 0 && uVar4 == 0) {
      return -(uint)(-1 < (int)param_4) | 1;
    }
  }
  else if ((uVar2 == 0) && (param_3 == 0 && uVar1 == 0)) goto LAB_10049d1a;
  if (((int)param_4 >> 0x1f == (int)param_2 >> 0x1f) && (uVar3 <= uVar2)) {
    if (uVar2 <= uVar3) {
      if (uVar1 <= uVar4 && uVar4 != uVar1) goto LAB_10049d1a;
      if (uVar4 == uVar1) {
        if (param_3 < param_1) goto LAB_10049d1a;
        if (param_3 <= param_1) {
          return 0;
        }
      }
      else if (uVar1 <= uVar4) {
        return 0;
      }
    }
    return -(uint)(-1 < (int)param_2) | 1;
  }
LAB_10049d1a:
  return (int)param_2 >> 0x1f | 1;
}

// FUNC 0x10049d80  log_state_check_alt

uint log_state_check_alt(uint param_1,uint param_2,uint param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar1 = param_4 & 0xfffff;
  uVar4 = param_2 & 0xfffff;
  uVar2 = (param_2 << 1) >> 0x15;
  uVar3 = (param_4 << 1) >> 0x15;
  if ((uVar2 == lit_mask_000007ff_9e50) && (uVar4 != 0 || param_1 != 0)) {
    return 2;
  }
  if ((uVar3 == lit_mask_000007ff_9e50) && (uVar1 != 0 || param_3 != 0)) {
    return 2;
  }
  if (uVar2 == 0) {
    if ((uVar3 == 0) && (param_3 == 0 && uVar1 == 0)) {
      if (param_1 == 0 && uVar4 == 0) {
        return 0;
      }
      goto LAB_10049de6;
    }
    if (param_1 == 0 && uVar4 == 0) goto LAB_10049dc6;
  }
  else if ((uVar3 == 0) && (param_3 == 0 && uVar1 == 0)) goto LAB_10049de6;
  if ((int)param_2 >> 0x1f == (int)param_4 >> 0x1f) {
    if (uVar3 < uVar2) {
      return (int)param_4 >> 0x1f | 1;
    }
    if (uVar2 < uVar3) {
LAB_10049dc6:
      return -(uint)(-1 < (int)param_4) | 1;
    }
    if (uVar4 <= uVar1) {
      if (uVar4 == uVar1) {
        if (param_3 < param_1) goto LAB_10049de6;
        if (param_3 <= param_1) {
          return 0;
        }
      }
      else if (uVar1 <= uVar4) {
        return 0;
      }
      return -(uint)(-1 < (int)param_2) | 1;
    }
  }
LAB_10049de6:
  return (int)param_2 >> 0x1f | 1;
}

// FUNC 0x10049e54  fmt_int_11

undefined8 fmt_int_11(uint param_1,uint param_2,uint param_3,uint param_4)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  undefined8 uVar16;
  int local_34;
  
  uVar7 = param_2 & 0xfffff;
  uVar12 = (param_2 << 1) >> 0x15;
  if (uVar12 == 0) {
    if (uVar7 == 0 && param_1 == 0) {
      uVar7 = 0;
      param_1 = 0;
      uVar13 = 4;
    }
    else {
      if (uVar7 == 0) {
        iVar2 = mem_fill();
        iVar2 = iVar2 + 0x20;
      }
      else {
        iVar2 = mem_fill(uVar7);
      }
      if (iVar2 + -0xb < 0x1d) {
        uVar12 = param_1 >> (0x1dU - (iVar2 + -0xb) & 0xff);
        param_1 = param_1 << (iVar2 - 8U & 0xff);
        uVar7 = uVar12 | uVar7 << (iVar2 - 8U & 0xff);
      }
      else {
        uVar7 = param_1 << (iVar2 - 0x28U & 0xff);
        param_1 = 0;
      }
      uVar13 = 0;
      uVar12 = -(iVar2 + fmt_const_03f3_2);
    }
  }
  else if (uVar12 == lit_mask_000007ff_a030) {
    if (param_1 == 0 && uVar7 == 0) {
      uVar7 = 0;
      param_1 = 0;
      uVar13 = 8;
    }
    else {
      uVar13 = 0xc;
    }
  }
  else {
    uVar7 = param_1 >> 0x1d | 0x800000 | uVar7 << 3;
    param_1 = param_1 << 3;
    uVar13 = 0;
    uVar12 = uVar12 + fmt_const_fffffc01_2;
  }
  uVar10 = param_4 & 0xfffff;
  uVar1 = (param_4 << 1) >> 0x15;
  if (uVar1 == 0) {
    if (param_3 == 0 && uVar10 == 0) {
      uVar10 = 0;
      param_3 = 0;
      uVar3 = 1;
    }
    else {
      if (uVar10 == 0) {
        iVar2 = mem_fill(param_3);
        iVar2 = iVar2 + 0x20;
      }
      else {
        iVar2 = mem_fill(uVar10);
      }
      if (iVar2 + -0xb < 0x1d) {
        uVar1 = param_3 >> (0x1dU - (iVar2 + -0xb) & 0xff);
        param_3 = param_3 << (iVar2 - 8U & 0xff);
        uVar10 = uVar10 << (iVar2 - 8U & 0xff) | uVar1;
      }
      else {
        uVar10 = param_3 << (iVar2 - 0x28U & 0xff);
        param_3 = 0;
      }
      uVar1 = -(iVar2 + fmt_const_03f3_2);
      uVar3 = 0;
    }
  }
  else if (uVar1 == lit_mask_000007ff_a030) {
    if (param_3 == 0 && uVar10 == 0) {
      uVar10 = 0;
      param_3 = 0;
      uVar3 = 2;
    }
    else {
      uVar3 = 3;
    }
  }
  else {
    uVar10 = uVar10 << 3 | param_3 >> 0x1d | 0x800000;
    uVar3 = 0;
    param_3 = param_3 << 3;
    uVar1 = uVar1 + fmt_const_fffffc01_2;
  }
  if ((uVar13 | uVar3) < 0x10) {
                    /* WARNING: Could not recover jumptable at 0x10049eea. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar16 = (**(code **)(lit_rodata_10057080 + (uVar13 | uVar3) * 4))();
    return uVar16;
  }
  uVar13 = param_1 >> 0x10;
  uVar3 = param_3 >> 0x10;
  param_3 = param_3 & 0xffff;
  uVar4 = param_3 * uVar13;
  local_34 = uVar3 * uVar13;
  param_1 = param_1 & 0xffff;
  uVar5 = param_1 * uVar3 + uVar4 + (param_1 * param_3 >> 0x10);
  if (uVar5 <= uVar4 && uVar4 - uVar5 != 0) {
    local_34 = local_34 + 0x10000;
  }
  uVar6 = uVar10 >> 0x10;
  uVar10 = uVar10 & 0xffff;
  uVar4 = uVar10 * uVar13;
  iVar2 = uVar6 * uVar13;
  uVar13 = uVar6 * param_1 + uVar4 + (param_1 * uVar10 >> 0x10);
  if (uVar13 <= uVar4 && uVar4 - uVar13 != 0) {
    iVar2 = iVar2 + 0x10000;
  }
  uVar4 = (uVar13 >> 0x10) + iVar2;
  uVar14 = uVar13 * 0x10000 + (param_1 * uVar10 & 0xffff);
  uVar13 = uVar7 >> 0x10;
  uVar7 = uVar7 & 0xffff;
  uVar8 = uVar13 * param_3;
  iVar2 = uVar13 * uVar3;
  uVar3 = uVar7 * uVar3 + uVar8 + (param_3 * uVar7 >> 0x10);
  if (uVar3 <= uVar8 && uVar8 - uVar3 != 0) {
    iVar2 = iVar2 + 0x10000;
  }
  uVar9 = uVar3 * 0x10000 + (param_3 * uVar7 & 0xffff);
  uVar8 = uVar10 * uVar13;
  iVar11 = uVar6 * uVar13;
  uVar13 = uVar7 * uVar6 + uVar8 + (uVar10 * uVar7 >> 0x10);
  uVar3 = (uVar3 >> 0x10) + iVar2;
  if (uVar13 <= uVar8 && uVar8 - uVar13 != 0) {
    iVar11 = iVar11 + 0x10000;
  }
  uVar15 = local_34 + (uVar5 >> 0x10) + uVar14;
  uVar6 = (uint)(uVar15 < uVar14);
  uVar10 = (uVar10 * uVar7 & 0xffff) + uVar13 * 0x10000 + uVar4;
  uVar15 = uVar15 + uVar9;
  uVar7 = (uint)(uVar15 < uVar9);
  uVar9 = uVar10 + uVar6;
  uVar14 = uVar3 + uVar9;
  uVar8 = uVar7 + uVar14;
  uVar10 = ((uint)(uVar10 < uVar4 || uVar9 < uVar6) + (uVar13 >> 0x10) +
            (uint)(uVar14 < uVar3 || uVar8 < uVar7) + iVar11) * 0x200 | uVar8 >> 0x17;
  uVar7 = (uint)((uVar15 & 0x7fffff) != 0 || uVar5 * 0x10000 + (param_1 * param_3 & 0xffff) != 0);
  uVar13 = uVar8 * 0x200 | uVar7 | uVar15 >> 0x17;
  iVar2 = uVar12 + uVar1;
  if ((int)(uVar10 << 7) < 0) {
    uVar13 = uVar7 | uVar15 >> 0x17 & 1 | uVar13 >> 1 | (uVar8 >> 0x17) << 0x1f;
    uVar10 = uVar10 >> 1;
    iVar2 = uVar12 + uVar1 + 1;
  }
  uVar12 = iVar2 + lit_mask_000003ff_a338;
  if (0 < (int)uVar12) {
    uVar7 = uVar13;
    if (((uVar13 & 7) != 0) && ((uVar13 & 0xf) != 4)) {
      uVar7 = uVar13 + 4;
      uVar10 = uVar10 + (uVar7 < uVar13);
    }
    if ((int)(uVar10 << 7) < 0) {
      uVar10 = uVar10 & lit_mask_feffffff_a33c;
      uVar12 = iVar2 + 0x400;
    }
    if (fmt_const_07fe_2 < (int)uVar12) {
      uVar7 = 0;
      uVar13 = 0;
      uVar12 = lit_mask_000007ff_a030;
    }
    else {
      uVar7 = uVar10 << 0x1d | uVar7 >> 3;
      uVar13 = (uVar10 << 9) >> 0xc;
      uVar12 = uVar12 & 0x7ff;
    }
    goto LAB_10049f20;
  }
  uVar7 = 1 - uVar12;
  if (0x38 < (int)uVar7) {
    uVar12 = 0;
    uVar13 = 0;
    uVar7 = 0;
    goto LAB_10049f20;
  }
  if ((int)uVar7 < 0x20) {
    uVar1 = uVar10 << (0x20 - uVar7 & 0xff) | uVar13 >> (uVar7 & 0xff);
    uVar12 = (uint)(uVar13 << (0x20 - uVar7 & 0xff) != 0);
    uVar3 = uVar1 | uVar12;
    uVar10 = uVar10 >> (uVar7 & 0xff);
    if (((uVar1 & 7) != 0 || uVar12 != 0) && ((uVar1 & 0xf | uVar12) != 4)) {
LAB_1004a2ba:
      uVar10 = uVar10 + (uVar3 + 4 < uVar3);
      uVar3 = uVar3 + 4;
    }
    if ((int)(uVar10 << 8) < 0) {
      uVar12 = 1;
      uVar13 = 0;
      uVar7 = 0;
      goto LAB_10049f20;
    }
LAB_1004a308:
    uVar7 = uVar10 << 0x1d;
    uVar13 = (uVar10 << 9) >> 0xc;
  }
  else {
    uVar12 = uVar10 >> (-uVar12 - 0x1f & 0xff);
    if (uVar7 == 0x20) {
      iVar2 = 0;
    }
    else {
      iVar2 = uVar10 << (0x40 - uVar7 & 0xff);
    }
    uVar1 = (uint)(uVar13 != 0 || iVar2 != 0);
    uVar3 = uVar1 | uVar12;
    uVar7 = uVar1 | uVar12 & 7;
    uVar13 = 0;
    if (uVar7 != 0) {
      uVar10 = 0;
      if ((uVar1 | uVar12 & 0xf) != 4) goto LAB_1004a2ba;
      goto LAB_1004a308;
    }
  }
  uVar7 = uVar3 >> 3 | uVar7;
  uVar12 = 0;
LAB_10049f20:
  return CONCAT44(uVar13 & mask_float_high_3 | (uVar12 & 0x7ff) << 0x14 |
                  (param_4 ^ param_2) & 0x80000000,uVar7);
}

// FUNC 0x1004a348  fmt_int_5

undefined8 fmt_int_5(uint param_1,uint param_2,uint param_3,uint param_4)

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
  if ((uVar7 != lit_mask_000007ff_a6ac) || (uVar2 == 0 && uVar4 == 0)) {
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
          if (uVar9 != lit_mask_000007ff_a9e8) goto LAB_1004a506;
        }
      }
      else {
        uVar15 = uVar14;
        if (uVar9 != lit_mask_000007ff_a6ac) {
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
          if (uVar7 == lit_mask_000007ff_a6ac) goto LAB_1004a7d4;
          uVar9 = uVar7;
          uVar11 = (lit_mask_ff7fffff_a6b0 & uVar15) << 0x1f | uVar11 & 1 | uVar11 >> 1;
          uVar15 = (lit_mask_ff7fffff_a6b0 & uVar15) >> 1;
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
        if (uVar9 == lit_mask_000007ff_a6ac) {
          uVar5 = 0;
          uVar10 = 0;
        }
        else {
          uVar5 = uVar11 >> 3 | (uVar15 & lit_mask_ff7fffff_a6b0) << 0x1d;
          uVar10 = ((uVar15 & lit_mask_ff7fffff_a6b0) << 9) >> 0xc;
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
          if (uVar7 != lit_mask_000007ff_a9e8) goto LAB_1004a82c;
        }
      }
      else {
        uVar9 = uVar7;
        uVar11 = uVar4;
        if (uVar7 != lit_mask_000007ff_a9e8) {
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
          uVar15 = uVar15 & lit_mask_ff7fffff_a9ec;
        }
      }
      else {
        uVar9 = lit_mask_000007ff_a9e8;
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
    if (uVar7 != lit_mask_000007ff_a6ac) {
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
            uVar9 = lit_mask_000007ff_a9e8;
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
            uVar9 = lit_mask_000007ff_a9e8;
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
            iVar3 = mem_fill(uVar11);
            iVar16 = iVar3 + 0x20;
            uVar10 = iVar3 + 0x18;
            if ((int)uVar10 < 0x20) goto LAB_1004a47c;
LAB_1004a608:
            uVar2 = uVar11 << (iVar16 - 0x28U & 0xff);
            uVar8 = 0;
          }
          else {
            iVar16 = mem_fill(uVar15);
            uVar10 = iVar16 - 8;
            if (0x1f < (int)uVar10) goto LAB_1004a608;
LAB_1004a47c:
            uVar8 = uVar11 << (uVar10 & 0xff);
            uVar2 = uVar11 >> (0x20 - uVar10 & 0xff) | uVar15 << (uVar10 & 0xff);
          }
          if ((int)uVar10 < (int)uVar9) {
            uVar9 = uVar9 - uVar10;
            uVar11 = uVar8;
            uVar15 = lit_mask_ff7fffff_a6b0 & uVar2;
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
          if (uVar7 != lit_mask_000007ff_a9e8) goto LAB_1004a6ce;
        }
      }
      else {
        uVar9 = uVar7;
        uVar11 = uVar4;
        uVar5 = uVar8;
        if (uVar7 != lit_mask_000007ff_a9e8) {
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
        if (uVar9 != lit_mask_000007ff_a6ac) goto LAB_1004a41a;
      }
      goto LAB_1004a3a0;
    }
    uVar15 = uVar14;
    if (uVar9 == lit_mask_000007ff_a6ac) goto LAB_1004a3a0;
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
  if (uVar9 == lit_mask_000007ff_a6ac) {
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
  return CONCAT44(mask_float_high_4 & uVar10 | (uVar9 << 0x15) >> 1 | uVar8 << 0x1f,uVar5);
}

// FUNC 0x1004a9f0  fmt_int_6

uint fmt_int_6(uint param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar2 = (param_2 << 1) >> 0x15;
  uVar3 = 0;
  if (fmt_const_03fe < (int)uVar2) {
    if (fmt_const_041d < (int)uVar2) {
      uVar3 = lit_mask_7fffffff_aa54 - ((int)param_2 >> 0x1f);
    }
    else {
      uVar1 = param_2 & 0xfffff | 0x100000;
      if ((int)(fmt_const_0433 - uVar2) < 0x20) {
        uVar1 = uVar1 << (uVar2 + fmt_const_fffffbed & 0xff) | param_1 >> (fmt_const_0433 - uVar2 & 0xff);
      }
      else {
        uVar1 = uVar1 >> (fmt_const_0413 - uVar2 & 0xff);
      }
      uVar3 = -uVar1;
      if (-1 < (int)param_2) {
        uVar3 = uVar1;
      }
    }
  }
  return uVar3;
}

// FUNC 0x1004aa5c  fmt_int_7

undefined8 fmt_int_7(uint param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  
  if (param_1 == 0) {
    param_1 = 0;
    uVar3 = 0;
    uVar4 = 0;
    iVar2 = 0;
  }
  else {
    uVar4 = param_1 + ((int)param_1 >> 0x1f) ^ (int)param_1 >> 0x1f;
    param_1 = param_1 >> 0x1f;
    iVar1 = mem_fill(uVar4);
    uVar3 = fmt_const_041e - iVar1;
    if ((int)(fmt_const_0433_2 - uVar3) < 0x20) {
      iVar2 = uVar4 << (fmt_const_0433_2 - uVar3 & 0xff);
      uVar4 = uVar4 >> (0xbU - iVar1 & 0xff) & 0xfffff;
      uVar3 = uVar3 & 0x7ff;
    }
    else {
      iVar2 = 0;
      uVar4 = uVar4 << (fmt_const_0413_2 - uVar3 & 0xff) & 0xfffff;
      uVar3 = uVar3 & 0x7ff;
    }
  }
  return CONCAT44(uVar4 & mask_float_high_5 | uVar3 << 0x14 | param_1 << 0x1f,iVar2);
}

// FUNC 0x1004aae0  fmt_int_8

undefined8 fmt_int_8(uint param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  
  if (param_1 == 0) {
    uVar2 = 0;
    uVar3 = 0;
    iVar4 = 0;
  }
  else {
    iVar1 = mem_fill();
    uVar2 = fmt_const_041e_2 - iVar1;
    if ((int)(fmt_const_0433_3 - uVar2) < 0x20) {
      iVar4 = param_1 << (fmt_const_0433_3 - uVar2 & 0xff);
      uVar3 = param_1 >> (0xbU - iVar1 & 0xff) & 0xfffff;
      uVar2 = uVar2 & 0x7ff;
    }
    else {
      iVar4 = 0;
      uVar3 = param_1 << (fmt_const_0413_3 - uVar2 & 0xff) & 0xfffff;
      uVar2 = uVar2 & 0x7ff;
    }
  }
  return CONCAT44(uVar3 & mask_float_high_6 | uVar2 << 0x14,iVar4);
}

// FUNC 0x1004ab50  fmt_int_9

undefined8 fmt_int_9(uint param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar2 = (param_1 << 1) >> 0x18;
  uVar4 = param_1 & 0x7fffff;
  if ((uVar2 + 1 & 0xff) < 2) {
    if (uVar2 == 0) {
      if (uVar4 == 0) {
        uVar3 = 0;
        uVar2 = 0;
      }
      else {
        iVar1 = mem_fill(uVar4);
        if (iVar1 < 0xb) {
          uVar3 = uVar4 >> (0xbU - iVar1 & 0xff);
          uVar4 = uVar4 << (iVar1 + 0x15U & 0xff);
        }
        else {
          uVar3 = uVar4 << (iVar1 - 0xbU & 0xff);
          uVar4 = 0;
        }
        uVar3 = uVar3 & 0xfffff;
        uVar2 = fmt_const_0389 - iVar1 & 0x7ff;
      }
    }
    else {
      uVar2 = lit_mask_000007ff_abf4;
      if (uVar4 == 0) {
        uVar3 = 0;
      }
      else {
        uVar3 = (param_1 << 9) >> 0xc | 0x80000;
        uVar4 = uVar4 << 0x1d;
      }
    }
  }
  else {
    uVar4 = uVar4 << 0x1d;
    uVar3 = (param_1 << 9) >> 0xc;
    uVar2 = uVar2 + 0x380;
  }
  return CONCAT44(uVar3 & mask_float_high_7 | (uVar2 << 0x15) >> 1 | param_1 & 0x80000000,uVar4);
}

// FUNC 0x1004abf8  fmt_int_10

uint fmt_int_10(uint param_1,uint param_2)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  
  uVar7 = (param_2 << 1) >> 0x15;
  uVar3 = param_1 >> 0x1d | (param_2 << 0xc) >> 9;
  uVar6 = param_1 << 3;
  if ((uVar7 + 1 & 0x7ff) < 2) {
    if (uVar7 == 0) {
      uVar3 = uVar3 | uVar6;
      uVar5 = 0;
      if (uVar3 != 0) {
LAB_1004ac86:
        uVar5 = 0;
        uVar3 = 0;
        goto LAB_1004ac88;
      }
LAB_1004ac8e:
      uVar3 = uVar3 & 0x7fffff;
      uVar5 = uVar5 & 0xff;
      goto LAB_1004ac56;
    }
    if (uVar6 != 0 || uVar3 != 0) {
      uVar3 = uVar3 << 3 | 0x2000000;
      uVar5 = 0xff;
      goto LAB_1004ac2e;
    }
  }
  else {
    uVar5 = uVar7 + fmt_const_fffffc80;
    if ((int)uVar5 < 0xff) {
      if ((int)uVar5 < 1) {
        if ((int)(uVar5 + 0x17) < 0 != SCARRY4(uVar5,0x17)) goto LAB_1004ac86;
        uVar3 = uVar3 | 0x800000;
        uVar2 = 0x1e - uVar5;
        if ((int)uVar2 < 0x20) {
          uVar3 = uVar6 >> (uVar2 & 0xff) |
                  (uint)(uVar6 << (uVar7 + fmt_const_fffffc82 & 0xff) != 0) |
                  uVar3 << (uVar7 + fmt_const_fffffc82 & 0xff);
          uVar5 = 0;
        }
        else {
          iVar1 = -uVar5;
          if (uVar2 == 0x20) {
            iVar4 = 0;
          }
          else {
            iVar4 = uVar3 << (uVar7 + fmt_const_fffffca2 & 0xff);
          }
          uVar5 = 0;
          uVar3 = (uint)(uVar6 != 0 || iVar4 != 0) | uVar3 >> (iVar1 - 2U & 0xff);
        }
      }
      else {
        uVar3 = uVar6 >> 0x1d | (uint)((param_1 & 0x3ffffff) != 0) | uVar3 << 3;
      }
LAB_1004ac2e:
      if (((uVar3 & 7) != 0) && ((uVar3 & 0xf) != 4)) {
        uVar3 = uVar3 + 4;
      }
      if ((uVar3 & 0x4000000) == 0) {
LAB_1004ac88:
        uVar3 = uVar3 >> 3;
        if (uVar5 == 0xff) {
          uVar5 = 0xff;
          if (uVar3 == 0) {
            uVar3 = 0;
          }
          else {
            uVar3 = uVar3 & 0x7fffff | 0x400000;
          }
          goto LAB_1004ac56;
        }
        goto LAB_1004ac8e;
      }
      if (uVar5 + 1 != 0xff) {
        uVar3 = (uVar3 << 6) >> 9;
        uVar5 = uVar5 + 1 & 0xff;
        goto LAB_1004ac56;
      }
    }
  }
  uVar5 = 0xff;
  uVar3 = 0;
LAB_1004ac56:
  return uVar5 << 0x17 | uVar3 | param_2 & 0x80000000;
}

// FUNC 0x1004ad70  fmt_int_13

undefined4 fmt_int_13(void)

{
  int iVar1;
  
  iVar1 = fmt_int_14();
  if (iVar1 < 0) {
    return 0;
  }
  return 1;
}

// FUNC 0x1004ad84  log_div

int log_div(undefined4 param_1,int param_2)

{
  int iVar1;
  
  if (param_2 == 0) {
    iVar1 = mem_fill();
    iVar1 = iVar1 + 0x20;
  }
  else {
    iVar1 = mem_fill(param_2);
  }
  return iVar1;
}

// FUNC 0x1004adec  fmt_int_14

uint fmt_int_14(uint param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar4 = param_1 & 0x7fffff;
  uVar3 = param_2 & 0x7fffff;
  uVar2 = (param_1 << 1) >> 0x18;
  uVar1 = (param_2 << 1) >> 0x18;
  if (((uVar2 == 0xff) && (uVar4 != 0)) || ((uVar1 == 0xff && (uVar3 != 0)))) {
    return 0xfffffffe;
  }
  if (uVar2 == 0) {
    if ((uVar1 == 0) && (uVar3 == 0)) {
      if (uVar4 == 0) {
        return 0;
      }
      goto LAB_1004ae2e;
    }
    if (uVar4 == 0) {
      return -(uint)(-1 < (int)param_2) | 1;
    }
  }
  else if ((uVar1 == 0) && (uVar3 == 0)) goto LAB_1004ae2e;
  if (((int)param_2 >> 0x1f == (int)param_1 >> 0x1f) && (uVar2 <= uVar1)) {
    if (uVar1 <= uVar2) {
      if (uVar3 < uVar4) goto LAB_1004ae2e;
      if (uVar3 <= uVar4) {
        return 0;
      }
    }
    return -(uint)(-1 < (int)param_1) | 1;
  }
LAB_1004ae2e:
  return (int)param_1 >> 0x1f | 1;
}

// FUNC 0x1004aefc  reset_handler

/* Copies init image 0x10059118 -> 0x20000800, then calls system_init and main */

void reset_handler(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  *puRam1004af68 = 4;
  for (iVar1 = 0; (uint)(iRam1004af70 + iVar1) < uRam1004af74; iVar1 = iVar1 + 4) {
    *(undefined4 *)(iRam1004af70 + iVar1) = *(undefined4 *)(iRam1004af6c + iVar1);
  }
  for (iVar1 = 0; puVar3 = puRam1004af84, (uint)(iRam1004af7c + iVar1) < uRam1004af80;
      iVar1 = iVar1 + 4) {
    *(undefined4 *)(iRam1004af7c + iVar1) = *(undefined4 *)(iRam1004af78 + iVar1);
  }
  for (; puVar2 = puRam1004af8c, puVar3 < puRam1004af88; puVar3 = puVar3 + 1) {
    *puVar3 = 0;
  }
  for (; puVar3 = puRam1004af94, puVar2 < puRam1004af90; puVar2 = puVar2 + 1) {
    *puVar2 = 0;
  }
  for (; puVar3 < puRam1004af9c; puVar3 = puVar3 + 1) {
    *puVar3 = uRam1004af98;
  }
  system_init();
  func_0x10056ec8();
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}

// FUNC 0x1004afa0  log_infinite

void log_infinite(void)

{
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}

// FUNC 0x1004afa2  log_delay

void log_delay(int param_1)

{
  for (; param_1 != 0; param_1 = param_1 + -1) {
  }
  return;
}

// FUNC 0x1004afb0  log_delay_2

void log_delay_2(int param_1)

{
  int iVar1;
  uint uVar2;
  undefined4 local_c;
  
  iVar1 = fmt_int_18(*lit_ptr_ram_20000804,clk_1mhz_2);
  uVar2 = fmt_int_18(iVar1 * param_1,0x11);
  if (uVar2 < 0xc) {
    local_c = 0;
  }
  else {
    local_c = uVar2 - 0xc;
  }
  for (; local_c != 0; local_c = local_c + -1) {
  }
  return;
}

// FUNC 0x1004b008  system_init

void system_init(void)

{
  *puRam1004b020 = 1;
  *puRam1004b024 = 2;
  *puRam1004b028 = 2;
  func_0x1004c794();
  return;
}

// FUNC 0x1004b02c  log_nop

void log_nop(void)

{
  return;
}

// FUNC 0x1004b02e  log_write

void log_write(code *param_1,undefined4 param_2,int param_3,undefined4 param_4,int param_5,
                 int param_6,uint param_7,uint param_8)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar2 = param_3;
  iVar3 = param_6;
  iVar4 = param_3;
  if ((param_8 & 3) == 0) {
    for (; (uint)(iVar2 + (param_6 - param_3)) < param_7; iVar2 = iVar2 + 1) {
      (*param_1)(0x20,param_2,iVar2,param_4,param_2,param_4,iVar4);
    }
  }
  while( true ) {
    iVar1 = param_6 + iVar2;
    if (iVar3 == 0) break;
    (*param_1)(*(undefined1 *)(param_5 + iVar3 + -1),param_2,iVar1 - iVar3,param_4,param_2,param_4,
               iVar4);
    iVar3 = iVar3 + -1;
  }
  if ((int)(param_8 << 0x1e) < 0) {
    for (; (uint)(iVar1 - param_3) < param_7; iVar1 = iVar1 + 1) {
      (*param_1)(0x20,param_2,iVar1,param_4,param_2,param_4,iVar4);
    }
  }
  return;
}

// FUNC 0x1004b098  log_fmt_int

void log_fmt_int(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 int param_5,uint param_6,char param_7,int param_8,uint param_9,uint param_10,
                 uint param_11)

{
  undefined1 uVar1;
  uint uVar2;
  
  if (-1 < (int)(param_11 << 0x1e)) {
    if (((param_10 != 0) && ((int)(param_11 << 0x1f) < 0)) &&
       ((param_7 != '\0' || ((param_11 & 0xc) != 0)))) {
      param_10 = param_10 - 1;
    }
    for (; (param_6 < param_9 && (param_6 < 0x20)); param_6 = param_6 + 1) {
      *(undefined1 *)(param_5 + param_6) = 0x30;
    }
    for (; (((param_11 & 1) != 0 && (param_6 < param_10)) && (param_6 < 0x20));
        param_6 = param_6 + 1) {
      *(undefined1 *)(param_5 + param_6) = 0x30;
    }
  }
  if ((int)(param_11 << 0x1b) < 0) {
    uVar2 = param_6;
    if (((((int)(param_11 << 0x15) < 0) || (param_6 == 0)) ||
        ((param_6 != param_9 && (param_6 != param_10)))) || (uVar2 = param_6 - 1, uVar2 == 0)) {
      param_6 = uVar2;
      if (param_8 == 0x10) goto LAB_1004b120;
LAB_1004b136:
      if (param_8 == 2) {
        param_6 = uVar2;
        if (0x1f < uVar2) goto LAB_1004b170;
        uVar1 = 0x62;
        goto LAB_1004b142;
      }
    }
    else {
      param_6 = param_6 - 2;
      if (param_8 != 0x10) goto LAB_1004b136;
LAB_1004b120:
      if ((int)(param_11 << 0x1a) < 0) {
        uVar1 = 0x58;
      }
      else {
        uVar1 = 0x78;
      }
      uVar2 = param_6;
      if (0x1f < param_6) goto LAB_1004b170;
LAB_1004b142:
      *(undefined1 *)(param_5 + uVar2) = uVar1;
      uVar2 = uVar2 + 1;
    }
    param_6 = uVar2;
    if (0x1f < uVar2) goto LAB_1004b170;
    *(undefined1 *)(param_5 + uVar2) = 0x30;
    param_6 = uVar2 + 1;
  }
  if (param_6 < 0x20) {
    if (param_7 == '\0') {
      if ((int)(param_11 << 0x1d) < 0) {
        uVar1 = 0x2b;
      }
      else {
        if (-1 < (int)(param_11 << 0x1c)) goto LAB_1004b170;
        uVar1 = 0x20;
      }
    }
    else {
      uVar1 = 0x2d;
    }
    *(undefined1 *)(param_5 + param_6) = uVar1;
    param_6 = param_6 + 1;
  }
LAB_1004b170:
  log_write(param_1,param_2,param_3,param_4,param_5,param_6,param_10,param_11);
  return;
}

// FUNC 0x1004b184  log_emit

void log_emit(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 int param_5,undefined1 param_6,undefined4 param_7,undefined4 param_8,
                 undefined4 param_9,uint param_10)

{
  char cVar1;
  byte extraout_r1;
  char cVar2;
  int iVar3;
  int iVar4;
  char local_38 [36];
  
  if (param_5 == 0) {
    param_10 = param_10 & 0xffffffef;
  }
  if ((-1 < (int)(param_10 << 0x15)) || (iVar3 = 0, param_5 != 0)) {
    cVar2 = 'a';
    if ((int)(param_10 << 0x1a) < 0) {
      cVar2 = 'A';
    }
    iVar4 = 0;
    do {
      fmt_int_19(param_5,param_7);
      iVar3 = iVar4 + 1;
      cVar1 = cVar2 + -10;
      if (extraout_r1 < 10) {
        cVar1 = '0';
      }
      local_38[iVar4] = extraout_r1 + cVar1;
      param_5 = fmt_int_18(param_5,param_7);
    } while ((param_5 != 0) && (iVar4 = iVar3, iVar3 != 0x20));
  }
  log_fmt_int(param_1,param_2,param_3,param_4,local_38,iVar3,param_6,param_7,param_8,param_9,
               param_10);
  return;
}

// FUNC 0x1004b218  log_fmt_int64

void log_fmt_int64(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 int param_5,int param_6,undefined1 param_7,undefined4 param_8,uint param_9,
                 undefined4 param_10,undefined4 param_11,undefined4 param_12,uint param_13)

{
  char cVar1;
  uint uVar2;
  char cVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  longlong lVar7;
  char local_38 [36];
  
  lVar7 = CONCAT44(param_6,param_5);
  if (param_5 == 0 && param_6 == 0) {
    param_13 = param_13 & 0xffffffef;
  }
  if ((-1 < (int)(param_13 << 0x15)) || (iVar5 = 0, param_5 != 0 || param_6 != 0)) {
    cVar3 = 'a';
    if ((int)(param_13 << 0x1a) < 0) {
      cVar3 = 'A';
    }
    iVar6 = 0;
    do {
      uVar4 = (undefined4)((ulonglong)lVar7 >> 0x20);
      uVar2 = param_9;
      log_error((int)lVar7,uVar4,param_9,param_10);
      cVar1 = (char)uVar2 + cVar3 + -10;
      iVar5 = iVar6 + 1;
      if ((uVar2 & 0xff) < 10) {
        cVar1 = (char)uVar2 + '0';
      }
      local_38[iVar6] = cVar1;
      lVar7 = log_error((int)lVar7,uVar4,param_9,param_10);
    } while ((lVar7 != 0) && (iVar6 = iVar5, iVar5 != 0x20));
  }
  log_fmt_int(param_1,param_2,param_3,param_4,local_38,iVar5,param_7,param_9,param_11,param_12,
               param_13);
  return;
}

// FUNC 0x1004b2d0  uart_putc_indexed

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Writes one byte to UART0..3 selected by the first argument */

void uart_putc_indexed(int param_1)

{
  char cVar1;
  int *piVar2;
  
  if (param_1 != 0) {
    cVar1 = *lit_ptr_ram_20000808;
    if (cVar1 == '\0') {
      do {
      } while ((clk_status & 0x20) != 0);
      piVar2 = (int *)&clk_rst_base;
    }
    else if (cVar1 == '\x01') {
      do {
        piVar2 = uart1_base_3;
      } while ((uart1_base_3[6] & 0x20U) != 0);
    }
    else if (cVar1 == '\x02') {
      do {
        piVar2 = uart2_base_2;
      } while ((uart2_base_2[6] & 0x20U) != 0);
    }
    else {
      if (cVar1 != '\x03') {
        return;
      }
      do {
        piVar2 = uart3_base;
      } while ((uart3_base[6] & 0x20U) != 0);
    }
    *piVar2 = param_1;
  }
  return;
}

// FUNC 0x1004b338  log_format_int

void log_format_int(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,uint param_7,uint param_8,uint param_9)

{
  int iVar1;
  int iVar2;
  char extraout_r1;
  char extraout_r1_00;
  undefined4 uVar3;
  char cVar4;
  undefined4 *puVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  uint uVar8;
  bool bVar9;
  undefined8 uVar10;
  undefined8 uVar11;
  char *pcVar12;
  uint uVar13;
  uint local_58;
  char local_38 [36];
  
  uVar10 = CONCAT44(param_6,param_5);
  iVar1 = log_state_1(param_5,param_6);
  if (iVar1 == 0) {
    uVar13 = 3;
    pcVar12 = lit_str_nan;
    goto LAB_1004b5f4;
  }
  iVar1 = log_state_2(param_5,param_6,0xffffffff,lit_mask_ffefffff);
  if (iVar1 != 0) {
    uVar13 = 4;
    pcVar12 = lit_str_fni;
    goto LAB_1004b5f4;
  }
  iVar1 = log_state_4(param_5,param_6,0xffffffff,mask_float_low);
  if (iVar1 != 0) {
    uVar13 = 4;
    pcVar12 = lit_str_fni_b620;
    if ((param_9 & 4) == 0) {
      uVar13 = 3;
      pcVar12 = lit_str_fni_b624;
    }
    goto LAB_1004b5f4;
  }
  iVar1 = log_state_4(param_5,param_6,0,lit_float_25_7253);
  if ((iVar1 != 0) || (iVar1 = log_state_2(param_5,param_6,0,lit_float_neg_25_7253), iVar1 != 0)) {
    log_format_helper(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9);
    return;
  }
  iVar1 = log_state_2(param_5,param_6,0,0);
  bVar9 = iVar1 != 0;
  if (bVar9) {
    uVar10 = fmt_int_5(0,0,param_5,param_6);
  }
  param_6 = (undefined4)((ulonglong)uVar10 >> 0x20);
  param_5 = (undefined4)uVar10;
  if (-1 < (int)(param_9 << 0x15)) {
    param_7 = 6;
  }
  uVar8 = 0;
  do {
    if (param_7 < 10) break;
    local_38[uVar8] = '0';
    uVar8 = uVar8 + 1;
    param_7 = param_7 - 1;
  } while (uVar8 != 0x20);
  local_58 = fmt_int_6(param_5,param_6);
  puVar5 = (undefined4 *)(lit_rodata_100570e0 + param_7 * 8);
  uVar7 = puVar5[1];
  uVar6 = *puVar5;
  uVar10 = fmt_int_7();
  uVar10 = fmt_int_5(param_5,param_6,(int)uVar10,(int)((ulonglong)uVar10 >> 0x20));
  uVar10 = fmt_int_11((int)uVar10,(int)((ulonglong)uVar10 >> 0x20),uVar6,uVar7);
  iVar2 = led_update_format();
  uVar11 = fmt_int_8();
  uVar10 = fmt_int_5((int)uVar10,(int)((ulonglong)uVar10 >> 0x20),(int)uVar11,
                        (int)((ulonglong)uVar11 >> 0x20));
  uVar3 = (undefined4)((ulonglong)uVar10 >> 0x20);
  iVar1 = log_state_4((int)uVar10,uVar3,0,lit_float_1_75);
  if (iVar1 == 0) {
    iVar1 = log_state_2((int)uVar10,uVar3,0,lit_float_1_75);
    if ((iVar1 == 0) && ((iVar2 == 0 || (iVar2 << 0x1f < 0)))) {
      iVar2 = iVar2 + 1;
    }
  }
  else {
    iVar2 = iVar2 + 1;
    uVar10 = fmt_int_8(iVar2);
    iVar1 = log_state_3(uVar6,uVar7,(int)uVar10,(int)((ulonglong)uVar10 >> 0x20));
    if (iVar1 != 0) {
      iVar2 = 0;
      local_58 = local_58 + 1;
    }
  }
  if (param_7 == 0) {
    uVar10 = fmt_int_7(local_58);
    uVar10 = fmt_int_5(param_5,param_6,(int)uVar10,(int)((ulonglong)uVar10 >> 0x20));
    uVar3 = (undefined4)((ulonglong)uVar10 >> 0x20);
    iVar1 = log_state_2((int)uVar10,uVar3,0,lit_float_1_75);
    if ((iVar1 == 0) || (iVar1 = log_state_4((int)uVar10,uVar3,0,lit_float_1_75), iVar1 != 0)) {
      local_58 = local_58 + (local_58 & 1);
    }
LAB_1004b584:
    do {
      if (uVar8 == 0x20) goto LAB_1004b588;
      uVar13 = uVar8 + 1;
      call_table_15(local_58,10);
      local_38[uVar8] = extraout_r1_00 + '0';
      local_58 = call_table_13(local_58,10);
      uVar8 = uVar13;
    } while (local_58 != 0);
  }
  else {
    do {
      if (uVar8 == 0x20) goto LAB_1004b588;
      param_7 = param_7 - 1;
      uVar13 = uVar8 + 1;
      fmt_int_19(iVar2,10);
      local_38[uVar8] = extraout_r1 + '0';
      iVar2 = fmt_int_18(iVar2,10);
      uVar8 = uVar13;
    } while (iVar2 != 0);
    param_7 = param_7 + uVar13;
    for (; uVar13 != 0x20; uVar13 = uVar13 + 1) {
      if (param_7 == uVar13) {
        local_38[param_7] = '.';
        uVar8 = param_7 + 1;
        goto LAB_1004b584;
      }
      local_38[uVar13] = '0';
    }
LAB_1004b588:
    uVar13 = 0x20;
  }
  if (((param_9 & 3) == 1) && (param_8 != 0)) {
    if ((bVar9) || ((param_9 & 0xc) != 0)) {
      param_8 = param_8 - 1;
    }
    for (; uVar13 < param_8; uVar13 = uVar13 + 1) {
      if (uVar13 == 0x20) goto LAB_1004b5e6;
      local_38[uVar13] = '0';
    }
  }
  if (uVar13 < 0x20) {
    if (bVar9) {
      cVar4 = '-';
    }
    else if ((int)(param_9 << 0x1d) < 0) {
      cVar4 = '+';
    }
    else {
      if (-1 < (int)(param_9 << 0x1c)) goto LAB_1004b5e6;
      cVar4 = ' ';
    }
    local_38[uVar13] = cVar4;
    uVar13 = uVar13 + 1;
  }
LAB_1004b5e6:
  pcVar12 = local_38;
LAB_1004b5f4:
  log_write(param_1,param_2,param_3,param_4,pcVar12,uVar13,param_8,param_9);
  return;
}

// FUNC 0x1004b638  log_format_helper

int log_format_helper(code *param_1,undefined4 param_2,int param_3,undefined4 param_4,undefined4 param_5,
                uint param_6,int param_7,uint param_8,uint param_9)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  undefined8 uVar10;
  undefined8 uVar11;
  undefined8 uVar12;
  undefined8 uVar13;
  int local_4c;
  undefined4 local_40;
  undefined4 local_30;
  undefined4 local_2c;
  
  iVar1 = log_state_1(param_5,param_6,param_5,param_6);
  if (((iVar1 == 0) || (iVar1 = log_state_4(param_5,param_6,0xffffffff,mask_float_low_2), iVar1 != 0))
     || (iVar1 = log_state_2(param_5,param_6,0xffffffff,lit_mask_ffefffff_b97c), iVar1 != 0)) {
    iVar1 = log_format_int(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9);
  }
  else {
    iVar1 = log_state_2(param_5,param_6,0,0);
    uVar7 = param_6;
    if (iVar1 != 0) {
      uVar7 = param_6 + 0x80000000;
    }
    uVar13 = CONCAT44(uVar7,param_5);
    if ((param_9 & 0x400) == 0) {
      param_7 = 6;
    }
    uVar10 = fmt_int_7(((uVar7 << 1) >> 0x15) + fmt_const_fffffc01_3);
    uVar10 = fmt_int_11((int)uVar10,(int)((ulonglong)uVar10 >> 0x20),fmt_scale_const_e,lit_float_1_65051);
    uVar10 = fmt_int_4((int)uVar10,(int)((ulonglong)uVar10 >> 0x20),fmt_scale_const_c,lit_float_1_55109);
    uVar11 = fmt_int_5(param_5,lit_float_1_875 | uVar7 & 0xfffff,0,lit_float_1_9375);
    uVar11 = fmt_int_11((int)uVar11,(int)((ulonglong)uVar11 >> 0x20),lit_tag_acoc,lit_float_1_64476);
    fmt_int_4((int)uVar10,(int)((ulonglong)uVar10 >> 0x20),(int)uVar11,
                 (int)((ulonglong)uVar11 >> 0x20));
    uVar2 = fmt_int_6();
    uVar10 = fmt_int_7();
    uVar4 = (undefined4)((ulonglong)uVar10 >> 0x20);
    uVar11 = fmt_int_11((int)uVar10,uVar4,fmt_scale_const_d,float_fmt_scale_2_16524);
    fmt_int_4((int)uVar11,(int)((ulonglong)uVar11 >> 0x20),0,lit_float_1_75_b9ac);
    iVar1 = fmt_int_6();
    uVar10 = fmt_int_11((int)uVar10,uVar4,lit_float_neg_0_00553382,float_fmt_scale_2_03782);
    uVar11 = fmt_int_7(iVar1);
    uVar11 = fmt_int_11((int)uVar11,(int)((ulonglong)uVar11 >> 0x20),fmt_scale_const_g,lit_float_1_79829);
    uVar10 = fmt_int_5((int)uVar10,(int)((ulonglong)uVar10 >> 0x20),(int)uVar11,
                          (int)((ulonglong)uVar11 >> 0x20));
    uVar5 = (undefined4)((ulonglong)uVar10 >> 0x20);
    uVar4 = (undefined4)uVar10;
    uVar10 = fmt_int_11(uVar4,uVar5,uVar4,uVar5);
    uVar6 = (undefined4)((ulonglong)uVar10 >> 0x20);
    uVar3 = (undefined4)uVar10;
    uVar10 = fmt_int_4(uVar4,uVar5);
    uVar11 = fmt_int_12(uVar3,uVar6,0,lit_float_2_6875);
    uVar11 = fmt_int_4((int)uVar11,(int)((ulonglong)uVar11 >> 0x20),0,lit_float_2_5625);
    uVar11 = fmt_int_12(uVar3,uVar6,(int)uVar11,(int)((ulonglong)uVar11 >> 0x20));
    uVar11 = fmt_int_4((int)uVar11,(int)((ulonglong)uVar11 >> 0x20),0,float_fmt_scale_2_375);
    uVar11 = fmt_int_12(uVar3,uVar6,(int)uVar11,(int)((ulonglong)uVar11 >> 0x20));
    uVar12 = fmt_int_5(0,0x40000000,uVar4,uVar5);
    uVar11 = fmt_int_4((int)uVar11,(int)((ulonglong)uVar11 >> 0x20),(int)uVar12,
                          (int)((ulonglong)uVar12 >> 0x20));
    uVar10 = fmt_int_12((int)uVar10,(int)((ulonglong)uVar10 >> 0x20),(int)uVar11,
                          (int)((ulonglong)uVar11 >> 0x20));
    uVar10 = fmt_int_4((int)uVar10,(int)((ulonglong)uVar10 >> 0x20),0,lit_float_1_875);
    uVar10 = fmt_int_11((int)uVar10,(int)((ulonglong)uVar10 >> 0x20),0,
                          (iVar1 + lit_mask_000003ff_b9cc) * 0x100000);
    uVar4 = (undefined4)((ulonglong)uVar10 >> 0x20);
    iVar1 = log_state_2(param_5,uVar7,(int)uVar10,uVar4);
    if (iVar1 != 0) {
      uVar10 = fmt_int_12((int)uVar10,uVar4,0,lit_float_2_5625);
      uVar2 = uVar2 - 1;
    }
    local_2c = (undefined4)((ulonglong)uVar10 >> 0x20);
    local_30 = (undefined4)uVar10;
    uVar8 = 5 - (uVar2 + 99 < 199);
    if ((int)(param_9 << 0x14) < 0) {
      iVar1 = log_empty_check(param_5,uVar7,fmt_scale_const_f,lit_float_0_6024);
      if ((iVar1 == 0) || (iVar1 = log_state_2(param_5,uVar7,0,lit_float_10_9073), iVar1 == 0)) {
        if (param_7 != 0) {
          param_7 = param_7 - (uint)((param_9 & 0x400) != 0);
        }
      }
      else {
        if ((int)uVar2 < param_7) {
          param_7 = (param_7 - uVar2) + -1;
        }
        else {
          param_7 = 0;
        }
        uVar8 = 0;
        param_9 = param_9 | 0x400;
        uVar2 = 0;
      }
    }
    uVar9 = 0;
    if (uVar8 < param_8) {
      uVar9 = param_8 - uVar8;
    }
    if ((param_9 & 2) != 0) {
      uVar9 = uVar9 & -(uint)(uVar8 == 0);
    }
    if (uVar2 != 0) {
      uVar13 = fmt_int_12(param_5,uVar7,local_30,local_2c);
    }
    local_4c = (int)((ulonglong)uVar13 >> 0x20);
    local_40 = (undefined4)uVar13;
    iVar1 = log_state_2(param_5,param_6,0,0);
    if (iVar1 != 0) {
      local_4c = local_4c + -0x80000000;
    }
    iVar1 = log_format_int(param_1,param_2,param_3,param_4,local_40,local_4c,param_7,uVar9,
                         lit_mask_fffff7ff & param_9);
    if (uVar8 != 0) {
      uVar4 = 0x45;
      if (-1 < (int)(param_9 << 0x1a)) {
        uVar4 = 0x65;
      }
      (*param_1)(uVar4,param_2,iVar1,param_4);
      iVar1 = log_emit(param_1,param_2,iVar1 + 1,param_4,
                           uVar2 + ((int)uVar2 >> 0x1f) ^ (int)uVar2 >> 0x1f,uVar2 >> 0x1f,10,0,
                           uVar8 - 1,5);
      if ((param_9 & 2) != 0) {
        for (; (uint)(iVar1 - param_3) < param_8; iVar1 = iVar1 + 1) {
          (*param_1)(0x20,param_2,iVar1,param_4);
        }
      }
    }
  }
  return iVar1;
}

// FUNC 0x1004b9e0  log_format

uint log_format(code *param_1,int param_2,uint param_3,byte *param_4,uint *param_5)

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
    local_4c = lit_fn_log_nop_plus_1;
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
      puVar11 = (uint *)log_format_helper(local_4c,param_2,puVar11,param_3,*puVar9,puVar9[1],uVar2,
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
        puVar11 = (uint *)log_format_int(local_4c,param_2,puVar11,param_3,*puVar9,puVar9[1],uVar2,
                                       local_44,uVar8);
      }
      else {
        if (bVar1 == 0x73) {
          param_5 = local_40 + 1;
          local_3c = (char *)*local_40;
          if (local_3c == (char *)0x0) {
            local_3c = lit_str_null;
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
          puVar11 = (uint *)log_emit(local_4c,param_2,puVar11,param_3,*local_40,0,0x10,uVar2,8,
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
            puVar11 = (uint *)log_fmt_int64(local_4c,param_2,puVar11,param_3,uVar2,uVar5,uVar8);
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
            puVar11 = (uint *)log_emit(local_4c,param_2,puVar11,param_3,uVar5,uVar7,uVar6,uVar2,
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
        puVar11 = (uint *)log_emit(local_4c,param_2,puVar11,param_3,uVar7,uVar5,uVar6,uVar2,
                                       local_44,uVar8);
        param_5 = local_40;
      }
    }
LAB_1004bd2c:
    param_4 = local_54 + 1;
  } while( true );
}

// FUNC 0x1004bf28  log_printf

/* Formatted log output; used for IND DATA SEND and boot messages */

void log_printf(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uStack_20;
  undefined4 *local_1c;
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  local_1c = &uStack_c;
  uStack_20 = param_3;
  uStack_c = param_2;
  uStack_8 = param_3;
  uStack_4 = param_4;
  log_format(lit_fn_uart_putc_indexed_plus_1,&uStack_20,0xffffffff,param_1,local_1c,param_2);
  return;
}

// FUNC 0x1004c0a4  log_bkpt

void log_bkpt(void)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)getMainStackPointer();
  log_printf(lit_str_in_hard_fault_handler);
  log_printf(lit_str_r0_0x_8x,*puVar1);
  log_printf(lit_str_r1_0x_8x,puVar1[1]);
  log_printf(lit_str_r2_0x_8x,puVar1[2]);
  log_printf(lit_str_r3_0x_8x,puVar1[3]);
  log_printf(lit_str_r12_0x_8x,puVar1[4]);
  log_printf(lit_str_lr_0x_8x,puVar1[5]);
  log_printf(lit_str_pc_0x_8x,puVar1[6]);
  log_printf(lit_str_psr_0x_8x,puVar1[7]);
  software_bkpt(1);
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}

// FUNC 0x1004c120  log_set_bit

void log_set_bit(uint param_1)

{
  uint *puVar1;
  uint uVar2;
  
  puVar1 = iomux_set;
  uVar2 = 1 << (param_1 & 0xff);
  *iomux_set = *iomux_set | uVar2;
  *puVar1 = *puVar1 & ~uVar2;
  return;
}

// FUNC 0x1004c4ac  irq_dispatch_32

/* Scans 32 pending IRQ bits and calls the registered handler for the first one */

void irq_dispatch_32(void)

{
  code *pcVar1;
  uint uVar2;
  uint uVar3;
  
  uVar2 = 0;
  uVar3 = *iomux_irq_pending;
  do {
    if ((uVar3 & 1 << (uVar2 & 0xff)) != 0) {
      log_set_bit(uVar2);
      pcVar1 = *(code **)(uVar2 * 8 + lit_ptr_ram_20003104);
      if (pcVar1 != (code *)0x0) {
        (*pcVar1)(*(undefined4 *)(lit_ptr_ram_20003104 + uVar2 * 8 + 4));
        return;
      }
    }
    uVar2 = uVar2 + 1;
  } while (uVar2 != 0x20);
  return;
}

// FUNC 0x1004c4e8  uart_irq_dispatch

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Per-UART interrupt dispatch: drains RX and calls the registered byte callback */

void uart_irq_dispatch(uint param_1)

{
  code *pcVar1;
  uint *puVar2;
  
  if (param_1 < 4) {
    puVar2 = *(uint **)(param_1 * 4 + lit_rodata_1005720c);
    if (((int)(puVar2[0x10] << 0x1b) < 0) || ((int)(puVar2[0x10] << 0x19) < 0)) {
      puVar2[0xe] = puVar2[0xe] & 0xffffffaf;
      puVar2[0x11] = puVar2[0x11] | 0x50;
      while ((puVar2[6] & 0x10) == 0) {
        pcVar1 = *(code **)(lit_ptr_ram_20003204 + param_1 * 4);
        if (pcVar1 != (code *)0x0) {
          (*pcVar1)(*puVar2 & 0xff);
        }
      }
      puVar2[0xe] = puVar2[0xe] | 0x50;
    }
    return;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)software_udf(0xff,0x1004c536);
  (*pcVar1)();
}

// FUNC 0x1004c544  uart_apply_baud

void uart_apply_baud(int param_1)

{
  *(undefined4 *)(param_1 + 4) = 0x1c200;
  *(undefined1 *)(param_1 + 8) = 3;
  *(undefined1 *)(param_1 + 9) = 0;
  *(undefined1 *)(param_1 + 10) = 0;
  *(undefined1 *)(param_1 + 0xb) = 0;
  *(undefined1 *)(param_1 + 0xc) = 3;
  *(undefined4 *)(param_1 + 0x10) = 0;
  return;
}

// FUNC 0x1004c55c  uart_baud_divider

/* Converts a baud rate to the divisor written to the UART */

uint uart_baud_divider(int param_1)

{
  uint uVar1;
  int iVar2;
  int extraout_r1;
  uint uVar3;
  uint uVar4;
  
  uVar1 = 0;
  uVar3 = *lit_ptr_ram_20000804_c59c;
  if ((param_1 != 0) && (uVar4 = param_1 << 4, uVar4 <= uVar3)) {
    fmt_int_19(uVar3,uVar4);
    uVar1 = fmt_int_18(extraout_r1 << 3,param_1);
    iVar2 = fmt_int_18(uVar3,uVar4);
    uVar1 = iVar2 << 0x10 | (uVar1 >> 1) + (uVar1 & 1) & 0xffff;
  }
  return uVar1;
}

// FUNC 0x1004c5a0  uart_enable

void uart_enable(undefined1 param_1)

{
  *lit_ptr_ram_20000808_c5a8 = param_1;
  return;
}

// FUNC 0x1004c5ac  uart_putc

void uart_putc(undefined4 *param_1,undefined4 param_2)

{
  if (param_1 != (undefined4 *)0x0) {
    do {
    } while ((param_1[6] & 0x20) != 0);
    *param_1 = param_2;
  }
  return;
}

// FUNC 0x1004c5bc  uart_set_config

void uart_set_config(int param_1,uint param_2,int param_3)

{
  if (param_3 == 0) {
    *(uint *)(param_1 + 0x38) = *(uint *)(param_1 + 0x38) & ~param_2;
  }
  else {
    *(uint *)(param_1 + 0x38) = param_2 | *(uint *)(param_1 + 0x38);
  }
  return;
}

// FUNC 0x1004c5ce  uart_nvic_priority

undefined4 uart_nvic_priority(int param_1,int param_2)

{
  *(uint *)(param_1 + 0x34) = *(uint *)(param_1 + 0x34) & 0xffffffc7;
  *(uint *)(param_1 + 0x34) = param_2 << 3 | *(uint *)(param_1 + 0x34);
  return 0;
}

// FUNC 0x1004c5e4  uart_irq_enable

undefined4 uart_irq_enable(char *param_1,uint param_2,int param_3)

{
  char cVar1;
  int iVar2;
  
  cVar1 = *param_1;
  if (cVar1 == '\0') {
    iVar2 = 0x40000000;
  }
  else {
    iVar2 = uart1_base_4;
    if (((cVar1 != '\x01') && (iVar2 = uart2_base_3, cVar1 != '\x02')) &&
       (iVar2 = uart3_base_2, cVar1 != '\x03')) {
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

// FUNC 0x1004c630  uart_init

/* uart_init(struct: index, baud, parity, stop) */

undefined4 uart_init(byte *param_1)

{
  byte bVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  
  bVar1 = *param_1;
  if (bVar1 == 0) {
    iVar6 = 0x40000000;
  }
  else {
    iVar6 = uart1_base_5;
    if (((bVar1 != 1) && (iVar6 = uart2_base_4, bVar1 != 2)) && (iVar6 = uart3_base_3, bVar1 != 3))
    {
      return 0xffffffff;
    }
  }
  do {
  } while ((*(uint *)(iVar6 + 0x18) & 8) != 0);
  *(undefined4 *)(iVar6 + 0x38) = 0;
  *(undefined4 *)(iVar6 + 0x30) = 0;
  *(undefined4 *)(iVar6 + 0x2c) = 0;
  uVar2 = *(undefined4 *)(param_1 + 4);
  *(uint *)(iVar6 + 0x48) = *(uint *)(iVar6 + 0x48) & 0xfffffffc;
  uVar3 = uart_baud_divider(uVar2);
  *(uint *)(iVar6 + 0x24) = uVar3 >> 0x10;
  *(uint *)(iVar6 + 0x28) = uVar3 & 0x3f;
  *(uint *)(iVar6 + 0x2c) = (uint)param_1[8] << 5 | (uint)param_1[10] << 3 | *(uint *)(iVar6 + 0x2c)
  ;
  bVar1 = param_1[9];
  if (bVar1 == 1) {
    *(uint *)(iVar6 + 0x2c) = *(uint *)(iVar6 + 0x2c) & 0xfffffff9;
    uVar3 = *(uint *)(iVar6 + 0x2c);
    uVar5 = 2;
LAB_1004c6ac:
    uVar3 = uVar3 | uVar5;
  }
  else {
    if (bVar1 != 0) {
      if (bVar1 != 2) goto LAB_1004c6bc;
      uVar5 = 6;
      uVar3 = *(uint *)(iVar6 + 0x2c);
      goto LAB_1004c6ac;
    }
    uVar3 = *(uint *)(iVar6 + 0x2c) & 0xfffffffd;
  }
  *(uint *)(iVar6 + 0x2c) = uVar3;
LAB_1004c6bc:
  if (param_1[0xc] == 0) {
    param_1[0xc] = 3;
  }
  *(uint *)(iVar6 + 0x30) = misc_const_fffffcff & *(uint *)(iVar6 + 0x30);
  uVar2 = 0x10;
  *(uint *)(iVar6 + 0x30) =
       (uint)param_1[0xb] << 0xe | (uint)param_1[0xc] << 8 | *(uint *)(iVar6 + 0x30);
  *(uint *)(iVar6 + 0x2c) = *(uint *)(iVar6 + 0x2c) | 0x10;
  *(uint *)(iVar6 + 0x34) = *(uint *)(iVar6 + 0x34) & 0xfffffff8;
  *(uint *)(iVar6 + 0x34) = *(uint *)(iVar6 + 0x34) | 2;
  *(uint *)(iVar6 + 0x34) = *(uint *)(iVar6 + 0x34) & 0xffffffc7;
  iVar4 = *(int *)(param_1 + 0x10);
  *(uint *)(iVar6 + 0x34) = *(uint *)(iVar6 + 0x34) | 0x10;
  if (iVar4 != 0) {
    *(uint *)(iVar6 + 0x38) = *(uint *)(iVar6 + 0x38) | 0x50;
    if (iVar6 == 0x40000000) {
      uVar2 = 8;
    }
    else if (iVar6 == uart1_base_5) {
      uVar2 = 4;
    }
    else if (iVar6 != uart2_base_4) {
      uVar2 = 0x20;
    }
    *lit_sys_nvic_iser_c758 = uVar2;
    *(int *)((uint)*param_1 * 4 + lit_ptr_ram_20003204_c75c) = iVar4;
  }
  *(uint *)(iVar6 + 0x30) = *(uint *)(iVar6 + 0x30) | 1;
  return 0;
}

// FUNC 0x1004c760  uart0_irq

void uart0_irq(void)

{
  uart_irq_dispatch(0);
  return;
}

// FUNC 0x1004c76a  uart1_irq

void uart1_irq(void)

{
  uart_irq_dispatch(1);
  return;
}

// FUNC 0x1004c774  uart2_irq

void uart2_irq(void)

{
  uart_irq_dispatch(2);
  return;
}

// FUNC 0x1004c77e  uart3_irq

void uart3_irq(void)

{
  uart_irq_dispatch(3);
  return;
}

// FUNC 0x1004c788  uart_driver_init

void uart_driver_init(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 * 4 + lit_ptr_ram_20003204_c790) = param_2;
  return;
}

// FUNC 0x1004c79c  log_table_idx

int log_table_idx(int param_1)

{
  return param_1 * 0x14 + lit_rodata_1005721c;
}

// FUNC 0x1004c7ac  log_table_search

int log_table_search(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = lit_rodata_1005721c_c7d8;
  iVar3 = 0;
  do {
    iVar2 = iVar3 * 0x14 + iVar1;
    iVar2 = log_bytecmp(param_1,*(undefined4 *)(iVar2 + 4),param_3,iVar2,param_4);
    if (iVar2 == 0) {
      return (int)(char)iVar3;
    }
    iVar3 = iVar3 + 1;
  } while (iVar3 != 0x10);
  return -1;
}

// FUNC 0x1004c7dc  log_range_search

int log_range_search(int param_1,int param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  iVar1 = lit_rodata_1005721c_c824 + param_1 * 0x14;
  if (*(uint *)(iVar1 + 0xc) < (uint)(param_3 + param_2)) {
    iVar1 = -1;
  }
  else {
    uVar2 = param_2 + *(int *)(iVar1 + 8);
    for (uVar3 = uVar2 & 0xfffff000; uVar3 <= ((param_3 + uVar2) - 1 & 0xfffff000);
        uVar3 = uVar3 + 0x1000) {
      iVar1 = call_table_1(fmt_const_2520_2,uVar3);
      if (iVar1 != 0) {
        return iVar1;
      }
    }
    iVar1 = 0;
  }
  return iVar1;
}

// FUNC 0x1004c82c  log_read

undefined4 log_read(int param_1,int *param_2,int param_3,int param_4)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  
  iVar1 = call_table_2();
  if ((param_2 != (int *)0x0) && (param_3 != 0)) {
    iVar3 = lit_rodata_1005721c_c8c0 + param_1 * 0x14;
    if ((uint)(param_4 + *param_2) <= *(uint *)(iVar3 + 0xc)) {
      uVar2 = *param_2 + *(int *)(iVar3 + 8);
      uVar4 = param_4 + uVar2;
      if (iVar1 != 0) {
        call_table_4();
      }
      for (iVar3 = param_4; iVar3 != 0; iVar3 = iVar3 - iVar5) {
        iVar5 = iVar3;
        if (uVar2 >> 8 < uVar4 >> 8) {
          iVar5 = 0x100 - (uVar2 & 0xff);
        }
        call_table_7(uVar2,iVar5,param_3);
        param_3 = param_3 + iVar5;
        uVar2 = uVar2 + iVar5;
      }
      if (iVar1 != 0) {
        call_table_3();
      }
      *param_2 = param_4 + *param_2;
      return 0;
    }
  }
  return 0xffffffff;
}

// FUNC 0x1004c8c4  log_copy

undefined4 log_copy(int param_1,int *param_2,int param_3,int param_4)

{
  int iVar1;
  
  if ((param_2 != (int *)0x0) && (param_3 != 0)) {
    iVar1 = lit_rodata_1005721c_c910 + param_1 * 0x14;
    if (((uint)(*param_2 + param_4) <= *(uint *)(iVar1 + 0xc)) &&
       (lit_mask_07ffffff < param_3 + 0xf0000000U)) {
      rom_memcpy(param_3,*param_2 + *(int *)(iVar1 + 8),param_4);
      *param_2 = *param_2 + param_4;
      return 0;
    }
  }
  return 0xffffffff;
}

// FUNC 0x1004c918  pinmux_set

/* pinmux_set(pin, class); 4-bit field at 0x40110068..0x40110074 */

void pinmux_set(undefined4 *param_1,uint param_2)

{
  uint *puVar1;
  int iVar2;
  code *UNRECOVERED_JUMPTABLE;
  
  puVar1 = (uint *)((((uint)param_1 >> 3) + lit_boot_1004401a) * 4);
  iVar2 = ((uint)param_1 & 7) << 2;
  if (param_2 < 0x19) {
    iVar2 = call_table_16(param_2);
    *param_1 = 0xd;
                    /* WARNING: Could not recover jumptable at 0x1004c948. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*UNRECOVERED_JUMPTABLE)(iVar2 + -0x31);
    return;
  }
  *puVar1 = *puVar1 & ~(0xf << iVar2);
  *puVar1 = 0 << iVar2 | *puVar1;
  return;
}

// FUNC 0x1004ca2c  syscfg_clear

void syscfg_clear(void)

{
  uint uVar1;
  
  uVar1 = syscfg_read(2);
  syscfg_write(2,uVar1 & lit_mask_fffff7ff_ca4c);
  log_delay(1000);
  return;
}

// FUNC 0x1004ca50  syscfg_write_2

void syscfg_write_2(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  uVar2 = clk_100khz;
  iVar1 = timer_pwm_cfg;
  *(undefined4 *)(timer_pwm_cfg + 0xc) = 5;
  iVar3 = *lit_ptr_ram_20000804_ca8c;
  uVar2 = fmt_int_18(iVar3,uVar2);
  *(undefined4 *)(iVar1 + 0x10) = uVar2;
  *(undefined4 *)(iVar1 + 0x14) = 0;
  uVar2 = fmt_int_18(iVar3 * 6,clk_1mhz_3);
  *(undefined4 *)(iVar1 + 0x18) = uVar2;
  if (param_1 != 0) {
    syscfg_clear();
  }
  return;
}

// FUNC 0x1004ca94  event_queue

uint event_queue(undefined4 param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  puVar1 = timer_pwm_cfg_2;
  *timer_pwm_cfg_2 = 0;
  puVar1[1] = 0;
  puVar1[7] = param_1;
  puVar1[2] = 1;
  puVar2 = timer_pwm_cfg_2;
  do {
  } while (puVar1[0xc] == 0);
  timer_pwm_cfg_2[0xb] = 1;
  return puVar2[9] & 0xff;
}

// FUNC 0x1004cab8  event_queue_2

undefined4 event_queue_2(undefined4 param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  puVar1 = timer_pwm_cfg_3;
  *timer_pwm_cfg_3 = 0;
  puVar1[1] = 1;
  puVar1[7] = param_1;
  puVar1[2] = 1;
  puVar2 = timer_pwm_cfg_3;
  do {
  } while (puVar1[0xc] == 0);
  timer_pwm_cfg_3[0xb] = 1;
  return puVar2[9];
}

// FUNC 0x1004cad8  event_bulk_read

void event_bulk_read(int param_1,uint param_2,int param_3)

{
  undefined1 uVar1;
  uint uVar2;
  
  syscfg_write_2(0);
  for (uVar2 = 0; (uVar2 & 0xffff) < param_2; uVar2 = uVar2 + 1) {
    uVar1 = event_queue(param_1 + uVar2 & 0xff);
    *(undefined1 *)(param_3 + uVar2) = uVar1;
  }
  return;
}

// FUNC 0x1004cb00  syscfg_write

/* Writes a 32-bit value to a SYSCFG register by index */

void syscfg_write(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 * 4 + syscfg_regs_3) = param_2;
  return;
}

// FUNC 0x1004cb10  syscfg_read

/* Reads a 32-bit SYSCFG register by index */

undefined4 syscfg_read(int param_1)

{
  return *(undefined4 *)(param_1 * 4 + syscfg_regs_4);
}

// FUNC 0x1004cb20  reg_field_write

/* Writes a bit field: block, shift, width, value */

void reg_field_write(int param_1,uint param_2,uint param_3,uint param_4)

{
  uint *puVar1;
  uint uVar2;
  
  if ((((param_1 != 0xff) && (param_2 < 0x20)) && (param_3 < 0x21)) &&
     (uVar2 = 1 << (param_3 & 0xff), param_4 < uVar2)) {
    puVar1 = (uint *)(param_1 * 4 + syscfg_regs_5);
    *puVar1 = param_4 << (param_2 & 0xff) | *puVar1 & ~(uVar2 - 1 << (param_2 & 0xff));
  }
  return;
}

// FUNC 0x1004cb54  reg_field_read

/* Reads a bit field: block, shift, width */

uint reg_field_read(int param_1,uint param_2,uint param_3)

{
  uint uVar1;
  
  if (((param_1 == 0xff) || (0x1f < param_2)) || (0x20 < param_3)) {
    uVar1 = 0xffffffff;
  }
  else {
    uVar1 = ((1 << (param_3 & 0xff)) + -1 << (param_2 & 0xff) &
            *(uint *)(param_1 * 4 + syscfg_regs_6)) >> (param_2 & 0xff);
  }
  return uVar1;
}

// FUNC 0x1004cb80  event_dispatch

void event_dispatch(void)

{
  int iVar1;
  uint uVar2;
  code *pcVar3;
  uint uVar4;
  
  uVar4 = 0;
  do {
    iVar1 = lit_ptr_ram_20003218;
    uVar2 = 1 << (uVar4 & 0xff);
    if ((uVar2 & *(uint *)(intc_base + 0x38)) != 0) {
      *(uint *)(intc_base + 0x38) = uVar2;
      pcVar3 = *(code **)(uVar4 * 8 + iVar1);
      if (pcVar3 != (code *)0x0) {
        (*pcVar3)(*(undefined4 *)(iVar1 + uVar4 * 8 + 4));
      }
    }
    uVar4 = uVar4 + 1;
  } while (uVar4 != 0x10);
  return;
}

// FUNC 0x1004cbb4  event_dispatch_2

void event_dispatch_2(void)

{
  uint uVar1;
  undefined4 *puVar2;
  uint uVar3;
  
  uVar3 = 0;
  puVar2 = (undefined4 *)(lit_ptr_ram_20003218_cbe0 + 0x80);
  do {
    uVar1 = 1 << (uVar3 & 0xff);
    if ((uVar1 & *(uint *)(gpio_base + 0x38)) != 0) {
      *(uint *)(gpio_base + 0x38) = uVar1;
      if ((code *)*puVar2 != (code *)0x0) {
        (*(code *)*puVar2)(puVar2[1]);
      }
    }
    uVar3 = uVar3 + 1;
    puVar2 = puVar2 + 2;
  } while (uVar3 != 0x10);
  return;
}

// FUNC 0x1004cbe8  pin_config

/* Secondary pin configuration select */

undefined4 pin_config(byte *param_1)

{
  uint uVar1;
  int iVar2;
  int extraout_r1;
  uint uVar3;
  uint *puVar4;
  uint unaff_r6;
  
  if (param_1 != (byte *)0x0) {
    uVar3 = (uint)*param_1;
    if (uVar3 < 8) {
      uVar3 = uVar3 * 4;
      uVar3 = *(int *)(uVar3 + lit_tbl_pinmux_class_table) << (uVar3 & 0xff) |
              *iomux_func_sel_0_2 & ~(0xf << (uVar3 & 0xff));
      puVar4 = iomux_func_sel_0_2;
    }
    else {
      if (uVar3 < 0x10) {
        iVar2 = uVar3 - 8;
        uVar1 = *iomux_func_sel_1_2;
        puVar4 = iomux_func_sel_1_2;
      }
      else if (uVar3 < 0x18) {
        iVar2 = uVar3 - 0x10;
        uVar1 = *iomux_func_sel_2;
        puVar4 = iomux_func_sel_2;
      }
      else {
        if (0x1e < uVar3) {
          return 0xffffffff;
        }
        iVar2 = uVar3 - 0x18;
        uVar1 = *iomux_func_sel_3;
        puVar4 = iomux_func_sel_3;
      }
      uVar3 = *(int *)(uVar3 * 4 + lit_tbl_pinmux_class_table) << (iVar2 << 2 & 0xffU) |
              uVar1 & ~(0xf << (iVar2 << 2 & 0xffU));
    }
    *puVar4 = uVar3;
    uVar3 = (uint)*param_1;
    if (uVar3 < 0x10) {
      if (param_1[1] < 8) {
        call_table_16();
        uVar3 = 1 << (uVar3 & 0xff);
        if ((uVar3 & *(uint *)(intc_base_2 + 0x10)) != 0) {
          *(uint *)(intc_base_2 + 0x14) = uVar3;
        }
        *gpio_pin_ctl_lo =
             *gpio_pin_ctl_lo & ~(3 << ((uint)*param_1 << 1 & 0xff)) |
             1 << ((uint)*param_1 << 1 & 0xff);
        *gpio_pin_enable = 1 << *param_1 | *gpio_pin_enable;
        return 0;
      }
    }
    else if (param_1[1] < 8) {
      call_table_16();
      puVar4[0x11] = (uint)puVar4;
      *(int *)(extraout_r1 + 100) = extraout_r1;
      puVar4[0x1a] = unaff_r6;
      uVar3 = 1 << (uVar3 - 0x10 & 0xff);
      if ((uVar3 & *(uint *)(gpio_base_2 + 0x10)) != 0) {
        *(uint *)(gpio_base_2 + 0x14) = uVar3;
      }
      uVar3 = (*param_1 - 0x10) * 2;
      *gpio_pin_ctl_hi = 1 << (uVar3 & 0xff) | *gpio_pin_ctl_hi & ~(3 << (uVar3 & 0xff));
      *gpio_pin_enable = *gpio_pin_enable | 1 << *param_1;
      if (*param_1 < 0x1b) {
        return 0;
      }
      uVar3 = 1 << (uint)*param_1;
      *iomux_pin_mask_a = *iomux_pin_mask_a & ~uVar3 | uVar3;
      *iomux_pin_mask_b = 1 << *param_1 | *iomux_pin_mask_b & ~(1 << *param_1);
      return 0;
    }
  }
  return 0xffffffff;
}

// FUNC 0x1004ce00  gpio_pin_irq_enable

/* Sets the interrupt enable bit for a GPIO pin descriptor: 0..15 on one block, 16..30 on the other
    */

undefined4 gpio_pin_irq_enable(byte *param_1)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  byte bVar4;
  
  if (param_1 == (byte *)0x0) {
LAB_1004ce28:
    uVar2 = 0xffffffff;
  }
  else {
    bVar4 = *param_1;
    if (bVar4 < 0x10) {
      uVar3 = *(uint *)(intc_base_3 + 4);
      iVar1 = intc_base_3;
    }
    else {
      if (0x1e < bVar4) goto LAB_1004ce28;
      bVar4 = bVar4 - 0x10;
      uVar3 = *(uint *)(gpio_base_3 + 4);
      iVar1 = gpio_base_3;
    }
    *(uint *)(iVar1 + 4) = 1 << (uint)bVar4 | uVar3;
    uVar2 = 0;
  }
  return uVar2;
}

// FUNC 0x1004ce38  gpio_pin_irq_disable

/* Clears the interrupt enable bit for a GPIO pin descriptor */

undefined4 gpio_pin_irq_disable(byte *param_1)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  byte bVar4;
  
  if (param_1 == (byte *)0x0) {
LAB_1004ce5e:
    uVar2 = 0xffffffff;
  }
  else {
    bVar4 = *param_1;
    if (bVar4 < 0x10) {
      uVar3 = *(uint *)(intc_base_4 + 4);
      iVar1 = intc_base_4;
    }
    else {
      if (0x1e < bVar4) goto LAB_1004ce5e;
      bVar4 = bVar4 - 0x10;
      uVar3 = *(uint *)(gpio_base_4 + 4);
      iVar1 = gpio_base_4;
    }
    *(uint *)(iVar1 + 4) = uVar3 & ~(1 << (uint)bVar4);
    uVar2 = 0;
  }
  return uVar2;
}

// FUNC 0x1004cec8  event_init

void event_init(void)

{
  int iVar1;
  
  iVar1 = crypto_key_block;
  *(undefined4 *)(crypto_key_block + 0xc00) = event_key_word0;
  *(undefined4 *)(iVar1 + 0xc) = 1;
  *(undefined4 *)(iVar1 + 0xc00) = event_key_word1;
  return;
}

// FUNC 0x1004cee8  event_init_2

void event_init_2(void)

{
  event_init();
  return;
}

// FUNC 0x1004cf2c  event_init_3

void event_init_3(void)

{
  event_init();
  return;
}

// FUNC 0x1004cf34  event_dispatch_3

void event_dispatch_3(void)

{
  uint uVar1;
  code *pcVar2;
  uint uVar3;
  
  uVar3 = 0;
  do {
    uVar1 = 1 << (uVar3 & 0xff);
    if ((uVar1 & *(uint *)(event_pending + 0x7c)) != 0) {
      *(uint *)(event_clear + 0x7c) = uVar1;
      pcVar2 = *(code **)(uVar3 * 4 + lit_ptr_ram_20003310);
      if (pcVar2 != (code *)0x0) {
        (*pcVar2)();
      }
    }
    uVar3 = uVar3 + 1;
  } while (uVar3 != 6);
  return;
}

// FUNC 0x1004cf6c  led_update_core

void led_update_core(byte *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  ushort uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  undefined8 uVar8;
  
  iVar2 = fmt_int_18(*lit_ptr_ram_20000804_d0dc,*(undefined4 *)(param_1 + 8),param_3,lit_ptr_ram_20000804_d0dc,param_4);
  uVar3 = fmt_int(0x3f800000,*(undefined4 *)(param_1 + 4));
  uVar4 = fmt_int_2(iVar2);
  fmt_int_3(uVar3,uVar4);
  uVar8 = fmt_int_9();
  uVar8 = fmt_int_4((int)uVar8,(int)((ulonglong)uVar8 >> 0x20),0,lit_float_1_75_d0e0);
  fmt_int_5((int)uVar8,(int)((ulonglong)uVar8 >> 0x20),0,lit_float_1_875_d0e4);
  uVar1 = led_update_format();
  iVar7 = led_hw_chan_mask;
  uVar6 = (uint)uVar1;
  if (*param_1 < 0xc) {
    *(undefined4 *)(led_hw_chan_mask + 0x34) = *(undefined4 *)(led_hw_chan_mask + 0x34);
    iVar5 = call_table_16();
    param_1 = param_1 + iVar5;
    param_1[0] = 0x1d;
    param_1[1] = 0;
    param_1[2] = 0;
    param_1[3] = 0;
    *(uint *)(iVar7 + 0x38) = iVar2 - 0x33U | *(uint *)(iVar7 + 0x38) & 0xffff0000;
    *(uint *)(iVar7 + 0x50) = *(uint *)(iVar7 + 0x50) & 0xffff0000 | uVar6;
    *(undefined4 *)(iVar7 + 0x68) = 0;
  }
  return;
}

// FUNC 0x1004d0ec  led_channel_schedule_cancel

undefined4 led_channel_schedule_cancel(byte *param_1)

{
  uint *puVar1;
  undefined4 uVar2;
  
  puVar1 = led_hw_chan_mask_2;
  if ((param_1 == (byte *)0x0) || (0xb < *param_1)) {
    uVar2 = 0xffffffff;
  }
  else {
    *led_hw_cmd_a = led_hw_cancel_id_a;
    *led_hw_cmd_b = led_hw_cancel_id_b;
    *iomux_clear = lit_mask_fbffffff_d144 & *iomux_clear;
    *puVar1 = *puVar1 & ~(1 << (uint)*param_1);
    led_update_core();
    uVar2 = 0;
    puVar1[1] = 0;
  }
  return uVar2;
}

// FUNC 0x1004d148  led_channel_schedule_set

undefined4 led_channel_schedule_set(byte *param_1)

{
  undefined4 uVar1;
  
  if ((param_1 == (byte *)0x0) || (0xb < *param_1)) {
    uVar1 = 0xffffffff;
  }
  else {
    uVar1 = 0;
    *led_hw_chan_mask_3 = 1 << (uint)*param_1 | *led_hw_chan_mask_3;
  }
  return uVar1;
}

// FUNC 0x1004d16c  led_channel_payload_update

undefined4 led_channel_payload_update(byte *param_1)

{
  undefined4 uVar1;
  
  if ((param_1 == (byte *)0x0) || (0xb < *param_1)) {
    uVar1 = 0xffffffff;
  }
  else {
    uVar1 = 0;
    *led_hw_chan_mask_4 = *led_hw_chan_mask_4 & ~(1 << (uint)*param_1);
  }
  return uVar1;
}

// FUNC 0x1004d190  led_channel_payload_send

undefined4 led_channel_payload_send(byte *param_1)

{
  undefined4 uVar1;
  
  if ((param_1 == (byte *)0x0) || (0xb < *param_1)) {
    uVar1 = 0xffffffff;
  }
  else {
    uVar1 = led_channel_payload_update();
  }
  return uVar1;
}

// FUNC 0x1004d1a8  event_delay

void event_delay(void)

{
  char cVar1;
  
  cVar1 = '@';
  do {
    if ((*(uint *)(timer_ctrl_b + 0x2c) & 0x10) != 0) {
      return;
    }
    cVar1 = cVar1 + -1;
  } while (cVar1 != '\0');
  return;
}

// FUNC 0x1004d1c4  event_delay_2

void event_delay_2(void)

{
  char cVar1;
  
  cVar1 = '@';
  do {
    if ((*(uint *)(timer_ctrl_a + 0xc) & 0x10) != 0) {
      return;
    }
    cVar1 = cVar1 + -1;
  } while (cVar1 != '\0');
  return;
}

// FUNC 0x1004d1e0  uart_syscfg

void uart_syscfg(void)

{
  reg_field_write(2,0xc,1);
  reg_field_write(0x15,0xd,4,0);
  reg_field_write(0x23,0x1c,1,0);
  reg_field_write(0x23,0x19,3,1);
  reg_field_write(0x23,10,1,0);
  reg_field_write(0x23,0,1);
  reg_field_write(0x23,0x1d,1,0);
  reg_field_write(0x32,0xd,4,7);
  reg_field_write(0x23,9,1);
  return;
}

// FUNC 0x1004d250  gpio_syscfg

void gpio_syscfg(int param_1,uint param_2)

{
  if (param_1 == 2) {
    if (7 < param_2) {
      return;
    }
    if (param_2 - 1 < 7) {
      call_table_16();
    }
    reg_field_write(0x21,8,1,0);
    reg_field_write(0x21,0x13,1,0);
  }
  else {
    if (param_1 != 3) {
      return;
    }
    if (param_2 < 8) {
      return;
    }
    if (7 < param_2 - 8) {
      return;
    }
    call_table_16(param_2 - 8,8,1,0);
    reg_field_write(0x21);
    reg_field_write(0x21,0x13,1);
  }
  reg_field_write(0x21,9,2,0);
  return;
}

// FUNC 0x1004d376  timer_syscfg

void timer_syscfg(void)

{
  uint uVar1;
  
  reg_field_write(0x15,0x1d,3,7);
  log_delay(2);
  reg_field_write(0x15,0x1d,3,0);
  log_delay(5);
  reg_field_write(0x15,0xb,2,3);
  reg_field_write(0x31,0x17,1);
  reg_field_write(0x16,0x1f,1,0);
  reg_field_write(0x16,0x1c,1,0);
  reg_field_write(0x16,9,3,0);
  reg_field_write(0x16,2,1,0);
  reg_field_write(0x32,0x1e,1);
  reg_field_write(0x32,0,4,0xb);
  reg_field_write(0x1b,0x12,1);
  reg_field_write(0x1c,0x18,4,0xf);
  reg_field_write(0x16,7,1,0);
  reg_field_write(0x1b,0x12,1,0);
  reg_field_write(0x15,0xb,2,0);
  reg_field_write(0x1c,0x18,4,0);
  reg_field_write(0x32,0x1e,1,0);
  reg_field_write(0x32,0,4);
  reg_field_write(0x16,7,1);
  reg_field_write(0x16,0x1f,1);
  reg_field_write(0x16,0x1c,1);
  reg_field_write(0x16,9,3,7);
  reg_field_write(0x16,2,1);
  reg_field_write(0x31,0x17,1,0);
  do {
    uVar1 = syscfg_read(0x38);
  } while ((uVar1 & 0x40000000) == 0);
  return;
}

// FUNC 0x1004d4b4  dma_syscfg

void dma_syscfg(uint param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  int unaff_r5;
  
  if (param_1 < 0xe) {
    call_table_16();
    *(ushort *)(param_4 + unaff_r5) = (ushort)param_4 | 0x24;
    reg_field_write(0x22,0x11,1);
    reg_field_write(0x22,0xb,3,0);
    reg_field_write(0x20,0x1a,1,0);
  }
  return;
}

// FUNC 0x1004d5c0  gpio_bulk_write

ulonglong gpio_bulk_write(int param_1,uint param_2)

{
  int iVar1;
  uint *puVar2;
  uint uVar3;
  uint uVar4;
  uint local_20;
  
  iVar1 = timer_ctrl_b_2;
  if (0x10 < param_2) {
    param_2 = 0;
  }
  *(uint *)(timer_ctrl_b_2 + 8) = param_2;
  local_20 = 0;
  uVar4 = 0;
  while ((uVar4 & 0xff) < param_2) {
    pinmux_set(*(undefined1 *)(param_1 + uVar4),3);
    puVar2 = gpio_pin_enable_2;
    uVar3 = (uint)*(byte *)(param_1 + uVar4);
    if (uVar3 < 0x10) {
      *(int *)(intc_base_5 + 0x14) = 1 << uVar3;
      *puVar2 = *puVar2 & ~(1 << *(sbyte *)(param_1 + uVar4));
      *gpio_pin_ctl_lo_2 = 3 << ((*(byte *)(param_1 + uVar4) & 0x7f) << 1) | *gpio_pin_ctl_lo_2;
    }
    else {
      *(int *)(gpio_base_5 + 0x14) = 1 << (uVar3 - 0x10 & 0xff);
      *puVar2 = *puVar2 | 1 << *(sbyte *)(param_1 + uVar4);
      *gpio_pin_ctl_hi_2 = 3 << ((*(byte *)(param_1 + uVar4) - 0x10) * 2 & 0xff) | *gpio_pin_ctl_hi_2;
    }
    if (*(byte *)(param_1 + uVar4) < 0xe) {
      local_20 = (uint)(byte)(*(byte *)(param_1 + uVar4) - 6);
    }
    uVar3 = uVar4 + 1;
    if ((uVar4 & 0xff) < 7) {
      *(uint *)(iVar1 + 8) = *(uint *)(iVar1 + 8) | local_20 << (uVar3 * 4 & 0xff);
      uVar4 = uVar3;
    }
    else {
      *(uint *)(iVar1 + 0xc) =
           *(uint *)(iVar1 + 0xc) | local_20 << ((uVar4 + lit_float_2) * 4 & 0xff);
      uVar4 = uVar3;
    }
  }
  return CONCAT44(uVar4,local_20) & 0xffffffffff;
}

// FUNC 0x1004d690  mic_pins_config

/* Configures P27/P28/P29 for the audio front end */

undefined8 mic_pins_config(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined1 uVar1;
  undefined1 local_18;
  undefined1 local_17;
  undefined2 uStack_16;
  undefined4 local_14;
  undefined4 uStack_10;
  
  uStack_16 = (undefined2)((uint)param_1 >> 0x10);
  local_18 = 0x1c;
  uVar1 = (undefined1)param_1;
  local_14 = 0;
  local_17 = uVar1;
  uStack_10 = param_3;
  pin_config(&local_18);
  local_18 = 0x1d;
  local_14 = 0;
  local_17 = uVar1;
  pin_config(&local_18);
  local_18 = 0x1b;
  local_14 = 0;
  local_17 = uVar1;
  pin_config(&local_18);
  log_delay(600);
  reg_field_write(1,0x1f,1);
  return CONCAT44(local_14,CONCAT22(uStack_16,CONCAT11(local_17,local_18)));
}

// FUNC 0x1004d6e0  wdog_syscfg

void wdog_syscfg(uint param_1,uint param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  
  if (param_2 < 2) {
    if (0xf < param_1) {
      return;
    }
    reg_field_write(0x15,0xe,1);
    reg_field_write(0x15,0x10,1);
    reg_field_write(0x15,0xf,1);
    log_delay(1);
    reg_field_write(0x15,0xd,1,0);
    reg_field_write(0x15,0xe,1,0);
    reg_field_write(0x15,0x10,1,0);
    reg_field_write(0x15,0xf,1,0);
    reg_field_write(0x23,0xf,2,3);
    reg_field_write(2,0xc,1);
    if (param_2 == 0) {
      reg_field_write(0x23,0x1c,1,0);
      reg_field_write(0x23,0x15,4,param_1);
      if (param_1 != 0xf) {
        uart_syscfg();
        return;
      }
      iVar1 = reg_field_read(3,0x1c,1);
      if (iVar1 != 1) {
        uart_syscfg();
        reg_field_write(0x23,0,1);
        uVar5 = 1;
        uVar3 = 0xc;
        uVar4 = 1;
        uVar2 = 2;
        goto LAB_1004d9d8;
      }
      reg_field_write(2,0xc,1,0);
      reg_field_write(0x15,0xd,4,0);
      reg_field_write(0x23,0x1c,1,0);
      reg_field_write(0x23,0x19,3,1);
      reg_field_write(0x23,0x15,4,0xf);
      reg_field_write(0x23,10,1,0);
      reg_field_write(0x23,0,1,1);
      reg_field_write(0x23,0x1d,1,1);
      reg_field_write(0x32,0xd,4);
      uVar3 = 9;
      uVar4 = 1;
      uVar5 = 1;
    }
    else {
      reg_field_write(0x23,0x1c,1);
      uVar5 = 3;
      uVar4 = 2;
      uVar3 = 0xf;
    }
    uVar2 = 0x23;
  }
  else {
    mic_pins_config(4);
    reg_field_write(0x17,0xb,1);
    reg_field_write(0x17,0x16,1,0);
    if (param_2 == 2) {
      timer_syscfg();
      reg_field_write(0x15,0x19,1,0);
      reg_field_write(0x15,0x17,1,0);
      reg_field_write(0x15,0x11,2,0);
      reg_field_write(0x15,0x14,1,0);
      reg_field_write(0x15,0x15,1,0);
      reg_field_write(0x15,0x18,1,0);
      reg_field_write(0x15,9,1);
      reg_field_write(0x15,9,1,0);
      syscfg_write(0x20,syscfg_val_20);
      syscfg_write(0x21,syscfg_val_21_a);
      reg_field_write(0x21,4,3,5);
      reg_field_write(0x20,0x12,2,1);
      log_delay(600);
    }
    else {
      if (param_2 != 3) {
        return;
      }
      reg_field_write(0x15,0xd,1,0);
      reg_field_write(0x20,0x1c,4,0xb);
      reg_field_write(0x15,0x19,7,0);
      reg_field_write(0x15,0x17,1,0);
      reg_field_write(0x15,0xb,2,3);
      reg_field_write(0x15,0xb,1,0);
      reg_field_write(0x15,0xc,1,0);
      log_delay(log_delay_6000);
      reg_field_write(0x15,0x11,2,0);
      reg_field_write(0x15,0x14,1,0);
      reg_field_write(0x15,0x15,2,0);
      reg_field_write(0x15,0x18,1,0);
      reg_field_write(0x15,9,1);
      reg_field_write(0x15,9,1,0);
      syscfg_write(0x20,syscfg_val_20);
      syscfg_write(0x21,syscfg_val_21_b);
      reg_field_write(0x21,4,3,5);
      reg_field_write(0x20,0x12,2,1);
      log_delay(600);
    }
    uVar5 = 3;
    uVar4 = 2;
    uVar3 = 0x12;
    uVar2 = 0x20;
  }
LAB_1004d9d8:
  reg_field_write(uVar2,uVar3,uVar4,uVar5);
  return;
}

// FUNC 0x1004d9f0  pinmux_pin

void pinmux_pin(uint param_1)

{
  uint *puVar1;
  uint uVar2;
  
  pinmux_set(param_1,3);
  puVar1 = gpio_pin_enable_3;
  if (param_1 < 0x10) {
    uVar2 = 1 << (param_1 & 0xff);
    *(uint *)(intc_base_6 + 0x14) = uVar2;
    *puVar1 = *puVar1 & ~uVar2;
    *gpio_pin_ctl_lo_3 = 3 << ((param_1 & 0x7f) << 1) | *gpio_pin_ctl_lo_3;
  }
  else {
    *(int *)(gpio_base_6 + 0x14) = 1 << (param_1 - 0x10 & 0xff);
    *puVar1 = 1 << (param_1 & 0xff) | *puVar1;
    *gpio_pin_ctl_hi_3 = 3 << ((param_1 - 0x10) * 2 & 0xff) | *gpio_pin_ctl_hi_3;
  }
  return;
}

// FUNC 0x1004da58  tim4_enable

void tim4_enable(int param_1)

{
  if (param_1 == 1) {
    *(uint *)(timer_ctrl_b_3 + 4) = *(uint *)(timer_ctrl_b_3 + 4) | 1;
  }
  else {
    *(uint *)(timer_ctrl_b_3 + 4) = *(uint *)(timer_ctrl_b_3 + 4) & 0xfffffffe;
  }
  return;
}

// FUNC 0x1004da74  tim4_status

undefined4 tim4_status(void)

{
  return *(undefined4 *)(timer_ctrl_b_4 + 0x2c);
}

// FUNC 0x1004da80  tim4_count

uint tim4_count(void)

{
  int iVar1;
  ushort uVar2;
  int iVar3;
  uint uVar4;
  undefined8 uVar5;
  
  iVar3 = reg_field_read(3,0x1c,1);
  iVar1 = timer_ctrl_b_5;
  if ((iVar3 == 1) && (iVar3 = reg_field_read(0x23,0x15,4), iVar3 == 0xf)) {
    uVar5 = fmt_int_7(*(uint *)(iVar1 + 0x20) & 0xffff);
    fmt_int_11((int)uVar5,(int)((ulonglong)uVar5 >> 0x20),fmt_scale_const_a,lit_float_1_95875);
    fmt_int_10();
    uVar2 = led_update_fmt();
    uVar4 = (uint)uVar2;
  }
  else {
    uVar4 = *(uint *)(iVar1 + 0x20);
  }
  return uVar4;
}

// FUNC 0x1004dacc  gpio_dir_syscfg

void gpio_dir_syscfg(int param_1)

{
  bool bVar1;
  
  bVar1 = param_1 != 1;
  if (bVar1) {
    param_1 = 1;
  }
  reg_field_write(0x15,0x13,param_1,bVar1);
  return;
}

// FUNC 0x1004dae4  tim4_configure

void tim4_configure(undefined4 *param_1)

{
  char cVar1;
  byte bVar2;
  undefined1 uVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined4 *puVar6;
  uint *puVar7;
  undefined4 uVar8;
  undefined1 auStack_19 [5];
  
  puVar6 = lit_sys_nvic_iser_dbd8;
  puVar4 = lit_ptr_ram_20003328;
  cVar1 = *(char *)(param_1 + 2);
  if (cVar1 == '\0') {
    bVar2 = *(byte *)(param_1 + 4);
    event_delay();
    if (bVar2 < 8) {
      pinmux_pin(bVar2 + 6,auStack_19);
    }
    wdog_syscfg(bVar2,0);
    iVar5 = timer_ctrl_b_6;
    *(uint *)(timer_ctrl_b_6 + 4) = *(uint *)(timer_ctrl_b_6 + 4) & 0xfffffff7;
    *(uint *)(iVar5 + 4) = *(uint *)(iVar5 + 4) & 0xffffffef;
    *(uint *)(iVar5 + 0x28) = *(uint *)(iVar5 + 0x28) | 4;
  }
  else {
    if (cVar1 != '\x01') {
      event_delay_2();
      wdog_syscfg(3,cVar1);
      puVar7 = timer_ctrl_a_2;
      *timer_ctrl_a_2 = *timer_ctrl_a_2 | 4;
      *puVar7 = *puVar7 & 0xffffffdf;
      puVar7[2] = puVar7[2] | 4;
      *puVar6 = 0x800000;
      event_delay_2();
      gpio_syscfg(*(undefined1 *)(param_1 + 2),*(undefined1 *)((int)param_1 + 0x13));
      if (*(byte *)((int)param_1 + 0x11) < 0xe) {
        dma_syscfg();
      }
      gpio_dir_syscfg(*(undefined1 *)((int)param_1 + 0x12));
      puVar4[2] = *param_1;
      puVar4[3] = param_1[1];
      return;
    }
    uVar8 = param_1[5];
    uVar3 = *(undefined1 *)(param_1 + 6);
    event_delay();
    wdog_syscfg(3,1);
    gpio_bulk_write(uVar8,uVar3);
    iVar5 = timer_ctrl_b_6;
    *(uint *)(timer_ctrl_b_6 + 4) = *(uint *)(timer_ctrl_b_6 + 4) | 8;
    *(uint *)(iVar5 + 4) = *(uint *)(iVar5 + 4) & 0xffffffef;
    *(uint *)(iVar5 + 0x28) = *(uint *)(iVar5 + 0x28) | 4;
    *puVar6 = 0x400000;
    event_delay();
  }
  *puVar4 = *param_1;
  puVar4[1] = param_1[1];
  return;
}

// FUNC 0x1004dbe0  event_callback

void event_callback(void)

{
  if ((code *)*lit_ptr_ram_20003328_dbf0 != (code *)0x0) {
    (*(code *)*lit_ptr_ram_20003328_dbf0)(lit_ptr_ram_20003328_dbf0[1]);
  }
  return;
}

// FUNC 0x1004dbf4  event_callback_2

void event_callback_2(void)

{
  if (*(code **)(lit_ptr_ram_20003328_dc04 + 8) != (code *)0x0) {
    (**(code **)(lit_ptr_ram_20003328_dc04 + 8))(*(undefined4 *)(lit_ptr_ram_20003328_dc04 + 0xc));
  }
  return;
}

// FUNC 0x1004dc24  keypad_irq_enable

/* Sets or clears the keypad interrupt enable bit */

void keypad_irq_enable(int param_1)

{
  uint uVar1;
  
  if (param_1 == 1) {
    uVar1 = *keypad_ctrl | 0x800;
  }
  else {
    uVar1 = lit_mask_fffff7ff_dc44 & *keypad_ctrl;
  }
  *keypad_ctrl = uVar1;
  return;
}

// FUNC 0x1004dcec  keypad_read_matrix

/* Copies the keypad matrix registers into a caller buffer */

void keypad_read_matrix(int param_1)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  
  iVar2 = *keypad_ctrl_2;
  uVar3 = 0;
  do {
    uVar1 = uVar3 >> 1;
    uVar4 = uVar3 & 1;
    iVar5 = uVar3 * 4;
    uVar3 = uVar3 + 1 & 0xff;
    *(uint *)(iVar5 + param_1) = *(uint *)(uVar1 * 8 + keypad_row_data) >> (uVar4 << 4) & 0xffff;
  } while (uVar3 <= (uint)(iVar2 << 6) >> 0x1d);
  return;
}

// FUNC 0x1004dd24  keypad_irq

/* Matrix scan interrupt: compares state and calls the key callback with row, column, pressed */

void keypad_irq(void)

{
  uint *puVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  undefined4 *puVar7;
  undefined4 uVar8;
  int iVar9;
  uint uVar10;
  undefined4 *puVar11;
  
  puVar1 = keypad_ctrl_3;
  keypad_irq_enable(0);
  log_printf(lit_str_keypad_irq);
  puVar2 = lit_ptr_ram_20003358;
  puVar7 = lit_ptr_ram_20003348;
  if (*lit_ptr_ram_20000809 == '\x01') {
    uVar3 = lit_ptr_ram_20003348[1];
    uVar8 = lit_ptr_ram_20003348[2];
    puVar11 = lit_ptr_ram_20003348 + 3;
    *lit_ptr_ram_20003358 = *lit_ptr_ram_20003348;
    puVar2[1] = uVar3;
    puVar2[2] = uVar8;
    iVar9 = 0;
    puVar2[3] = *puVar11;
    keypad_read_matrix(puVar7);
    do {
      uVar5 = puVar2[iVar9];
      uVar6 = lit_ptr_ram_20003348[iVar9];
      if ((uVar5 ^ uVar6) != 0) {
        uVar10 = 0;
        do {
          uVar4 = 1 << (uVar10 & 0xff);
          if (((uVar4 & (uVar5 ^ uVar6)) != 0) && ((code *)*lit_ptr_ram_2000333c != (code *)0x0)) {
            (*(code *)*lit_ptr_ram_2000333c)(iVar9,uVar10,(uVar4 & lit_ptr_ram_20003348[iVar9]) != 0);
          }
          uVar10 = uVar10 + 1;
        } while (uVar10 != 5);
      }
      iVar9 = iVar9 + 1;
    } while (iVar9 != 4);
  }
  else {
    uVar5 = (puVar1[8] << 1) >> 0x1b;
    puVar7 = lit_ptr_ram_20003340;
    if ((uVar5 != 0) && (puVar7 = lit_ptr_ram_20003338, uVar5 == 1)) {
      puVar7 = lit_ptr_ram_20003344;
    }
    if ((code *)*puVar7 != (code *)0x0) {
      (*(code *)*puVar7)();
    }
  }
  *puVar1 = *puVar1 | 0x800;
  return;
}

// FUNC 0x1004ddf8  event_log

void event_log(void)

{
  log_printf(lit_str_otas_ota_stop);
  return;
}

// FUNC 0x1004e1a0  app_msg_dispatch

/* App message handler for ids 0x28..0x37 (not wire bytes): 0x28 base frame ready, copies 11 bytes
   and posts 0x0B; 0x29 key highlight tick; 0x2b LED animation tick; 0x34 all LEDs red; 0x35 all
   LEDs green flash; 0x36 all LEDs red flash; 0x37 clear key highlight */

undefined4 app_msg_dispatch(int param_1)

{
  byte bVar1;
  byte bVar2;
  char cVar3;
  byte *pbVar4;
  byte *pbVar5;
  ushort *puVar6;
  undefined4 uVar7;
  uint uVar8;
  
  if (param_1 == 0x28) {
    log_printf(lit_str_atcmd_uart_timeout);
    pbVar5 = lit_ptr_ram_20003472;
    pbVar4 = lit_ptr_ram_20003470;
    bVar1 = *lit_ptr_ram_20003470;
    bVar2 = *lit_ptr_ram_20003472;
    uVar8 = (uint)bVar2;
    *(byte *)(lit_ptr_ram_2000346e + uVar8) = bVar1;
    *pbVar4 = 0;
    puVar6 = lit_ptr_ram_20003474;
    *lit_ptr_ram_20003474 = (ushort)bVar1;
    *(uint *)(puVar6 + 2) = uVar8 * 0x20 + lit_ptr_uart0_rx_ring;
    *(undefined4 *)(puVar6 + 4) = lit_fn_rx_buffer_toggle_plus_1;
    if (uVar8 == 1) {
      *pbVar5 = 0;
    }
    else {
      *pbVar5 = bVar2 + 1;
    }
    post_task_msg(0xb);
    return 0;
  }
  if (param_1 == 0x29) {
    key_highlight_tick(0);
    uVar7 = 0x4b;
  }
  else if (param_1 == 0x2d) {
    periodic_ui_update(0);
    if (*lit_ptr_ram_2000336f == '\0') {
      return 0;
    }
    uVar7 = 100;
  }
  else if (param_1 == 0x30) {
    blink_init(0);
    uVar7 = 0x28;
  }
  else {
    if (param_1 == 0x2a) {
      led_anim_finish(0);
      return 0;
    }
    if (param_1 == 0x2f) {
      ui_countdown(0);
      uVar7 = 0x21;
      cVar3 = *lit_ptr_ram_20003369;
    }
    else {
      if (param_1 == 0x2e) {
        ui_state_reset(0);
        return 0;
      }
      if (param_1 != 0x2b) {
        if (param_1 == 0x31) {
          key_event_post_100ms(0);
          return 0;
        }
        if (param_1 == 0x32) {
          setting_mode_exit_confirm(0);
          return 0;
        }
        if (param_1 == 0x33) {
          setting_mode_exit();
          return 0;
        }
        if (param_1 == 0x34) {
          all_leds_set();
          return 0;
        }
        if (param_1 == 0x35) {
          all_leds_flash_green();
          return 0;
        }
        if (param_1 == 0x36) {
          all_leds_blink();
          return 0;
        }
        if (param_1 != 0x37) {
          return 0;
        }
        key_highlight_clear();
        return 0;
      }
      led_update(0);
      uVar7 = 200;
      cVar3 = *lit_ptr_ram_2000336a;
    }
    if (cVar3 == '\0') {
      return 0;
    }
  }
  app_msg_post(param_1,uVar7);
  return 0;
}

// FUNC 0x1004e2e0  app_ota_start_callback

/* Registered OTA start handler; logs the app version and the callback result */

undefined4 app_ota_start_callback(undefined4 param_1,undefined4 param_2)

{
  undefined *puVar1;
  undefined4 uVar2;
  
  puVar1 = PTR_s_app_ota_start_callback_1004e304;
  log_printf(PTR_s__s__s__s_1004e30c,PTR_s_app_ota_start_callback_1004e304,
             PTR_s_app_1_0_2_20240319_1000_1004e308,param_2);
  uVar2 = status_get();
  log_printf(PTR_s__s__s_1004e310,puVar1,uVar2);
  return 0;
}

// FUNC 0x1004e344  ble_legacy_adv_config

/* app_ble_config_legacy_advertising: 0x1c-byte legacy advertising parameters */

void ble_legacy_adv_config(void)

{
  undefined *puVar1;
  int iVar2;
  undefined1 local_2c [2];
  undefined2 local_2a;
  undefined1 local_28;
  undefined4 local_1c;
  undefined4 local_18;
  undefined1 local_14;
  undefined1 local_13;
  
  puVar1 = PTR_s_app_ble_config_legacy_advertisin_1004e390;
  log_printf(PTR_s_APP___s_1004e394,PTR_s_app_ble_config_legacy_advertisin_1004e390);
  call_table_19(local_2c,0,0x1c);
  local_2a = 3;
  local_28 = 0xe2;
  local_1c = 0x40;
  local_18 = 0x40;
  local_14 = 7;
  local_2c[0] = 1;
  local_13 = 1;
  iVar2 = blink_tx_build(0,local_2c);
  if (iVar2 != 0) {
    log_printf(PTR_s_APP___s_ERROR__02X_1004e398,puVar1);
  }
  return;
}

// FUNC 0x1004e46c  event_diag

void event_diag(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined1 *puVar4;
  undefined1 local_3c [2];
  undefined2 local_3a;
  undefined1 local_21;
  undefined2 local_1c;
  undefined2 local_1a;
  undefined2 local_18;
  undefined1 local_16;
  
  uVar1 = lit_str_app_s;
  log_printf(lit_str_app_s,lit_str_app_init);
  blink_set_byte(5);
  log_set_1(lit_ptr_ram_200008b4);
  blink_set_u32(lit_ptr_ram_20000824);
  log_set_2(lit_ptr_ram_20000888);
  status_set(lit_ptr_ram_20000994);
  log_set_3(lit_ptr_ram_20000990);
  gpio_init_5(lit_ptr_ram_2000088c);
  uVar2 = lit_str_app_ble_on;
  log_printf(uVar1,lit_str_app_ble_on);
  call_table_19(local_3c,0,0x2a);
  local_3a = 0x96;
  local_21 = 3;
  local_1c = 0x80;
  local_1a = 0x2a0;
  local_18 = 0x2a0;
  local_16 = 10;
  local_3c[0] = 10;
  iVar3 = blink_init_3(local_3c);
  if (iVar3 != 0) {
    log_printf(lit_str_app_s_error_02x,uVar2);
  }
  puVar4 = (undefined1 *)ble_get_mac();
  log_printf(lit_str_ble_mac_02x_02x_02x_02x_02x,puVar4[5],puVar4[4],puVar4[3],puVar4[2],puVar4[1],*puVar4);
  log_printf(lit_rodata_10058156);
  iVar3 = lit_ptr_ram_2000089c;
  task_queue_add(lit_ptr_ram_2000089c);
  task_queue_add(iVar3 + 8);
  task_queue_add(iVar3 + 0x10);
  return;
}

// FUNC 0x1004e608  event_init_4

void event_init_4(void)

{
  app_msg_post(0x29,0x4b);
  app_msg_post(0x30,0x28);
  if (*(char *)(lit_ptr_led_state_block + 0x12) == '\0') {
    gpio_irq_disable_2();
  }
  else {
    *lit_ptr_ram_2000336f_e63c = 1;
    app_msg_post(0x2d,100);
  }
  return;
}

// FUNC 0x1004e640  ble_complete_event_handler

/* Handles BLE complete events by option id and advances advertising */

undefined4
ble_complete_event_handler(uint param_1,undefined4 param_2,undefined4 param_3,uint param_4)

{
  undefined1 uVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  undefined *puVar4;
  undefined *puVar5;
  int iVar6;
  undefined *puVar7;
  uint uVar8;
  undefined *puVar9;
  char *pcVar10;
  undefined1 auStack_2c [24];
  
  puVar9 = PTR_s_app_ble_complete_event_handler_1004e7a0;
  log_printf(PTR_s_APP_COMPLETE___s_opt_id__04X_sta_1004e7a4,
             PTR_s_app_ble_complete_event_handler_1004e7a0,param_1,param_2,param_3,param_4);
  puVar5 = PTR_s_app_ble_start_advertising_1004e7dc;
  puVar4 = PTR_s_APP___s_1004e7c0;
  puVar7 = PTR_s_app_ble_set_adv_data_1004e7bc;
  if (param_1 == misc_const_0412) {
    param_4 = param_4 & 0xffff;
    puVar7 = lit_str_app_complete_s_sonata_gatt_c;
  }
  else {
    if (misc_const_0412 < param_1) {
      if (param_1 != misc_const_0f02) {
        if (param_1 != misc_const_0f06) {
          if (param_1 != misc_const_0f01) {
            return 0;
          }
          blink_start(10);
          if (*lit_ptr_ram_20000998 != '\0') {
            ble_legacy_adv_config();
          }
          event_init_4();
          return 0;
        }
        if (*lit_ptr_ram_2000336e == '\0') {
          uart_init_5();
        }
        if (*lit_ptr_ram_20003368 != '\0') {
          return 0;
        }
        gpio_init_4();
        return 0;
      }
      log_printf(PTR_s_APP___s_1004e7c0,PTR_s_app_ble_set_adv_data_1004e7bc);
      rom_memcpy(auStack_2c,PTR_hex_digit_table_1004e7c4,0x11);
      iVar6 = lit_ptr_ram_2000080a;
      uVar8 = *(uint *)(lit_ptr_ram_2000396c + 4);
      uVar1 = auStack_2c[uVar8 >> 0x10 & 0xf];
      uVar2 = auStack_2c[uVar8 >> 8 & 0xf];
      *(undefined1 *)(lit_ptr_ram_2000080a + 0x14) = auStack_2c[(uVar8 >> 0x10 & 0xff) >> 4];
      *(undefined1 *)(iVar6 + 0x15) = uVar1;
      uVar1 = auStack_2c[uVar8 & 0xf];
      uVar3 = auStack_2c[(uVar8 >> 8 & 0xff) >> 4];
      *(undefined1 *)(iVar6 + 0x18) = auStack_2c[(uVar8 & 0xff) >> 4];
      *(undefined1 *)(iVar6 + 0x19) = uVar1;
      *(undefined1 *)(iVar6 + 0x16) = uVar3;
      *(undefined1 *)(iVar6 + 0x17) = uVar2;
      iVar6 = status_send_3(0x1a);
      if (iVar6 != 0) {
        log_printf(PTR_s_APP___s_ERROR__02X_1004e7d0,puVar7);
      }
      puVar9 = PTR_s_app_ble_set_scan_response_data_1004e7d4;
      log_printf(puVar4,PTR_s_app_ble_set_scan_response_data_1004e7d4);
      rom_memcpy(auStack_2c,PTRlit_fn_call_table_21_plus_10,4);
      param_4 = status_send_4(4,auStack_2c);
      puVar7 = PTR_s_APP___s_ERROR__02X_1004e7d0;
    }
    else {
      if (param_1 == 0x11b) {
        pcVar10 = lit_ptr_ram_2000336e;
        if ((param_4 == 0x14) || (pcVar10 = lit_ptr_ram_20003368, param_4 == 0x50)) {
          *pcVar10 = '\x01';
        }
        if (*lit_ptr_ram_2000336c != 0) {
          return 0;
        }
        if (param_4 != 0x14) {
          return 0;
        }
        ble_custom_service_add();
        return 0;
      }
      if (param_1 != 0x1a9) {
        return 0;
      }
      log_printf(PTR_s_APP___s_1004e7c0,PTR_s_app_ble_start_advertising_1004e7dc);
      param_4 = status_send_2(0);
      puVar7 = PTR_s_APP___s_ERROR__02X_1004e7d0;
      puVar9 = puVar5;
    }
    PTR_s_APP___s_ERROR__02X_1004e7d0 = puVar7;
    if (param_4 == 0) {
      return 0;
    }
  }
  log_printf(puVar7,puVar9,param_4);
  return 0;
}

// FUNC 0x1004e7f0  uart1_log_init

/* UART1 on P04/P05 at 921600; the J3 log/console port */

void uart1_log_init(void)

{
  undefined1 local_24 [4];
  undefined4 local_20;
  undefined1 local_1c;
  undefined1 local_18;
  
  uart_driver_init(1,lit_fn_uart1_rx_callback_plus_1);
  pinmux_set(4,0xe);
  pinmux_set(5,0xe);
  call_table_19(local_24,0,0x14);
  local_20 = 0xe1000;
  local_1c = 3;
  local_18 = 3;
  local_24[0] = 1;
  uart_init(local_24);
  uart_enable(1);
  uart_set_config(uart1_base_6,0x50,1);
  *lit_sys_nvic_iser_e850 = 4;
  return;
}

// FUNC 0x1004e854  uart3_init

/* P13/P14, 115200; display link to the panel STM8 */

void uart3_init(void)

{
  undefined1 auStack_1c [20];
  
  pinmux_set(0xd,0x10);
  pinmux_set(0xe,0x10);
  call_table_19(auStack_1c,0,0x14);
  auStack_1c[0] = 3;
  uart_apply_baud(auStack_1c);
  uart_init(auStack_1c);
  return;
}

// FUNC 0x1004e888  uart3_write

/* Writes a buffer to UART3, the display link */

void uart3_write(undefined1 *param_1,int param_2)

{
  undefined1 *puVar1;
  
  puVar1 = param_1 + param_2;
  for (; param_1 != puVar1; param_1 = param_1 + 1) {
    uart_putc(uart3_base_4,*param_1);
  }
  return;
}

// FUNC 0x1004e8a4  uart0_base_link_init

/* UART0 on P02/P03 at 2400; the base board link */

void uart0_base_link_init(void)

{
  undefined1 auStack_24 [4];
  undefined4 local_20;
  undefined1 local_1c;
  undefined1 local_18;
  
  uart_driver_init(0,lit_fn_uart0_rx_callback_plus_1);
  pinmux_set(2,0xd);
  pinmux_set(3,0xd);
  call_table_19(auStack_24,0,0x14);
  local_20 = 0x960;
  local_1c = 3;
  local_18 = 3;
  uart_init(auStack_24);
  uart_set_config(0x40000000,0x50,1);
  *lit_sys_nvic_iser_e90c = 8;
  uart_irq_enable(auStack_24,2,1);
  uart_nvic_priority(0x40000000,0);
  return;
}

// FUNC 0x1004e968  led_channel3_send_now

void led_channel3_send_now(int param_1)

{
  undefined1 *puVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  puVar1 = lit_ptr_ram_200033e0;
  *lit_ptr_ram_200033e0 = 7;
  uVar2 = log_rotate();
  uVar3 = log_bit_test(uVar2,lit_float_100);
  uVar2 = led_step_period;
  *(undefined4 *)(puVar1 + 4) = uVar3;
  *(undefined4 *)(puVar1 + 8) = uVar2;
  if (param_1 == 0) {
    led_channel_payload_send(puVar1);
  }
  else {
    led_channel_schedule_cancel();
    led_channel_schedule_set(puVar1);
  }
  return;
}

// FUNC 0x1004e9a8  led_channel4_send_now

void led_channel4_send_now(int param_1)

{
  undefined1 *puVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  puVar1 = lit_ptr_ram_20003374;
  *lit_ptr_ram_20003374 = 6;
  uVar2 = log_rotate();
  uVar2 = log_bit_test(uVar2,lit_float_255);
  uVar3 = fmt_int(0x3f800000,uVar2);
  uVar2 = led_step_period_2;
  *(undefined4 *)(puVar1 + 4) = uVar3;
  *(undefined4 *)(puVar1 + 8) = uVar2;
  if (param_1 == 0) {
    led_channel_payload_send(puVar1);
  }
  else {
    led_channel_schedule_cancel();
    led_channel_schedule_set(puVar1);
  }
  return;
}

// FUNC 0x1004e9f0  led_channel0_send_now

void led_channel0_send_now(int param_1)

{
  undefined1 *puVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  puVar1 = lit_ptr_ram_200033c0;
  *lit_ptr_ram_200033c0 = 3;
  uVar2 = log_rotate();
  uVar3 = log_bit_test(uVar2,lit_float_100_ea28);
  uVar2 = led_step_period_3;
  *(undefined4 *)(puVar1 + 4) = uVar3;
  *(undefined4 *)(puVar1 + 8) = uVar2;
  if (param_1 == 0) {
    led_channel_payload_send(puVar1);
  }
  else {
    led_channel_schedule_cancel();
    led_channel_schedule_set(puVar1);
  }
  return;
}

// FUNC 0x1004ea30  led_channel1_send_now

void led_channel1_send_now(int param_1)

{
  undefined1 *puVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  puVar1 = lit_ptr_ram_20003384;
  *lit_ptr_ram_20003384 = 5;
  uVar2 = log_rotate();
  uVar3 = log_bit_test(uVar2,lit_float_100_ea68);
  uVar2 = led_step_period_4;
  *(undefined4 *)(puVar1 + 4) = uVar3;
  *(undefined4 *)(puVar1 + 8) = uVar2;
  if (param_1 == 0) {
    led_channel_payload_send(puVar1);
  }
  else {
    led_channel_schedule_cancel();
    led_channel_schedule_set(puVar1);
  }
  return;
}

// FUNC 0x1004ea70  led_channel2_send_now

void led_channel2_send_now(int param_1)

{
  undefined1 *puVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  puVar1 = lit_ptr_ram_2000339c;
  *lit_ptr_ram_2000339c = 4;
  uVar2 = log_rotate();
  uVar3 = log_bit_test(uVar2,lit_float_100_eaa8);
  uVar2 = led_step_period_5;
  *(undefined4 *)(puVar1 + 4) = uVar3;
  *(undefined4 *)(puVar1 + 8) = uVar2;
  if (param_1 == 0) {
    led_channel_payload_send(puVar1);
  }
  else {
    led_channel_schedule_cancel();
    led_channel_schedule_set(puVar1);
  }
  return;
}

// FUNC 0x1004eab0  gpio_irq_disable

void gpio_irq_disable(void)

{
  gpio_pin_irq_disable(lit_ptr_ram_200033d8);
  return;
}

// FUNC 0x1004eac0  gpio_irq_enable

void gpio_irq_enable(void)

{
  gpio_pin_irq_enable(lit_ptr_ram_200033d8_eacc);
  return;
}

// FUNC 0x1004ead0  gpio_irq_disable_2

void gpio_irq_disable_2(void)

{
  gpio_pin_irq_disable(lit_ptr_ram_200033b8);
  return;
}

// FUNC 0x1004eae0  gpio_irq_enable_2

void gpio_irq_enable_2(void)

{
  gpio_pin_irq_enable(lit_ptr_ram_200033b8_eaec);
  return;
}

// FUNC 0x1004eaf0  gpio_irq_disable_3

void gpio_irq_disable_3(void)

{
  gpio_pin_irq_disable(lit_ptr_ram_200033d0);
  return;
}

// FUNC 0x1004eb00  gpio_irq_enable_3

void gpio_irq_enable_3(void)

{
  gpio_pin_irq_enable(lit_ptr_ram_200033d0_eb0c);
  return;
}

// FUNC 0x1004ee2c  ble_custom_service_add

/* Logs app custom svc add request and registers the custom service */

void ble_custom_service_add
               (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  log_printf(PTRlit_str_appsvc_s,PTR_s_app_custom_svc_add_request_1004ee48,param_3,param_4,param_1,
             param_2,param_3);
  blink_send_2(0,0,lit_ptr_ram_20000b3c,0x13,lit_ptr_ram_2000099a);
  return;
}

// FUNC 0x1004ee58  blink_phase_update

void blink_phase_update(undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  short sVar1;
  
  if (param_2 == 4) {
    if (*lit_ptr_ram_200033f4 == '\0') {
      return;
    }
    sVar1 = *lit_ptr_ram_20003432 + 4;
  }
  else if (param_2 == 9) {
    if (*lit_ptr_ram_2000340b == '\0') {
      return;
    }
    sVar1 = *lit_ptr_ram_20003432 + 9;
  }
  else {
    if (param_2 != 0xe) {
      return;
    }
    if (*lit_ptr_ram_20003436 == '\0') {
      return;
    }
    sVar1 = *lit_ptr_ram_20003432 + 0xe;
  }
  blink_send_seq(param_1,sVar1,param_4,param_3);
  return;
}

// FUNC 0x1004eeb4  blink_phase_transition

bool blink_phase_transition(undefined4 param_1,short param_2)

{
  bool bVar1;
  ushort uVar2;
  int unaff_r4;
  uint uVar3;
  int unaff_r7;
  undefined4 in_stack_00000004;
  undefined2 uStack_1c;
  
  uVar2 = *lit_ptr_ram_20003432_f05c;
  uVar3 = (uint)(ushort)(param_2 + ~uVar2);
  log_printf(lit_str_appsvc_s_localhandle_0x_04x,lit_str_app_custom_svc_read_request,uVar3);
  bVar1 = uVar3 - 1 < 0x12;
  if (bVar1) {
    call_table_16();
    *(ushort *)(unaff_r7 + uVar3) = (short)unaff_r7 - (param_2 + ~uVar2);
    *(undefined2 *)(unaff_r4 + 0x34) = uStack_1c;
    blink_send_2(in_stack_00000004,*(undefined2 *)(unaff_r4 + 0x14),0,*lit_ptr_ram_20003457);
  }
  return !bVar1;
}

// FUNC 0x1004f0b0  led_mask_apply

/* Applies a 6-byte LED mask to the 12-nibble payload: each nibble replaces the LED state, 8 leaves
   it unchanged, then re-sends the resulting bytes */

undefined4
led_mask_apply(undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4,
              undefined1 *param_5)

{
  byte bVar1;
  undefined4 extraout_r1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  byte *pbVar5;
  int iVar6;
  char cVar7;
  uint uVar8;
  undefined1 *puVar9;
  byte local_20 [12];
  
  rom_memcpy(local_20,lit_fn_call_table_21_plus_14 + 8,6);
  uVar8 = param_2 + ~(uint)*lit_ptr_ram_20003432_f408 & 0xffff;
  uVar2 = uVar8;
  log_printf(lit_str_appsvc_s_localhandle_0x_04x_f410,lit_str_app_custom_svc_write_request,uVar8,param_2,param_3);
  event_init_3();
  if (uVar8 - 1 < 0x10) {
    call_table_6();
    log_printf(lit_str_execute_cmd_1,extraout_r1,uVar2 << 0x1a,(int)param_5 << 2,param_3);
    for (puVar9 = param_5; (int)puVar9 - (int)param_5 < 0; puVar9 = puVar9 + 1) {
      log_printf(lit_str_02x,*puVar9);
    }
    log_printf(lit_rodata_10058156_f41c);
    uVar3 = lit_str_setting_mode_exit_control_cm;
    if (*(char *)(lit_ptr_led_state_block_f420 + 0x11) != '\x02') {
      cVar7 = '\x02';
      iVar6 = 0;
      rom_memcpy(lit_ptr_ram_2000341b,param_5,0);
      *lit_ptr_ram_20003457_f42c = 0;
      do {
        iVar4 = lit_ptr_ram_2000341b + iVar6;
        bVar1 = *(byte *)(iVar4 + 1);
        if (bVar1 >> 4 != 8) {
          pbVar5 = (byte *)(iVar6 + 0x57 + lit_ptr_led_state_block_f420);
          *pbVar5 = *pbVar5 & 0xf | bVar1 & 0xf0;
          local_20[iVar6] = bVar1;
          if ((bVar1 >> 4) - 2 < 2) {
            blink_search(cVar7 + -1);
          }
          else {
            led_encode_b_send();
          }
        }
        bVar1 = *(byte *)(iVar4 + 1);
        uVar2 = bVar1 & 0xf;
        if (uVar2 != 8) {
          pbVar5 = (byte *)(iVar6 + 0x57 + lit_ptr_led_state_block_f420);
          *pbVar5 = *pbVar5 & 0xf0 | (byte)uVar2;
          local_20[iVar6] = bVar1;
          if (uVar2 - 2 < 2) {
            blink_search(cVar7);
          }
          else {
            led_encode_b_send();
          }
        }
        iVar4 = lit_ptr_led_state_block_f420;
        cVar7 = cVar7 + '\x02';
        iVar6 = iVar6 + 1;
      } while (iVar6 != 6);
      if (*(char *)(lit_ptr_led_state_block_f420 + 0x12) == '\0') {
        base_frame_process(*(undefined1 *)(lit_ptr_led_state_block_f420 + 8),*(undefined1 *)(lit_ptr_led_state_block_f420 + 9),
                     *(undefined1 *)(lit_ptr_led_state_block_f420 + 10),*(undefined1 *)(lit_ptr_led_state_block_f420 + 0xb),
                     *(undefined1 *)(lit_ptr_led_state_block_f420 + 0xc));
        *(undefined1 *)(iVar4 + 0x12) = 1;
        gpio_irq_enable_2();
        if (*lit_ptr_ram_20000b4c != '\0') {
          *lit_ptr_ram_2000336f_f434 = 1;
          app_msg_post(0x2d,100);
        }
        key_event_post_500ms();
      }
      base_frame_send(local_20[0],local_20[1],local_20[2],local_20[3],local_20[4],local_20[5]);
      uVar3 = lit_str_control_cmd_d;
    }
    log_printf(uVar3,0);
    uVar3 = 0;
  }
  else {
    uVar3 = 10;
  }
  blink_send_3(param_1,param_2,uVar3);
  return 0;
}

// FUNC 0x1004f6c8  blink_set

void blink_set(undefined2 param_1)

{
  *lit_ptr_ram_20003432_f6d0 = param_1;
  return;
}

// FUNC 0x1004f710  rx_buffer_toggle

/* Flips the receive buffer selector */

void rx_buffer_toggle(void)

{
  char cVar1;
  
  if (*lit_ptr_ram_20003480 == '\x01') {
    cVar1 = '\0';
  }
  else {
    cVar1 = *lit_ptr_ram_20003480 + '\x01';
  }
  *lit_ptr_ram_20003480 = cVar1;
  return;
}

// FUNC 0x1004f728  uart0_rx_callback

/* Feeds received UART0 bytes into the 0x20003481 ring buffer */

void uart0_rx_callback(undefined1 param_1)

{
  byte bVar1;
  byte *pbVar2;
  byte *pbVar3;
  uint uVar4;
  int iVar5;
  
  app_msg_cancel(0x28);
  app_msg_post(0x28,0x14);
  pbVar2 = lit_ptr_ram_20003472_f778;
  if ((*lit_ptr_ram_20003472_f778 + 1 & 1) != *lit_ptr_ram_20003480_f77c) {
    app_msg_cancel(0x28);
    app_msg_post(0x28,0x14);
    pbVar3 = lit_ptr_ram_20003470_f780;
    bVar1 = *lit_ptr_ram_20003470_f780;
    uVar4 = bVar1 + 1;
    iVar5 = lit_ptr_uart0_rx_ring_f784 + (uint)*pbVar2 * 0x20;
    *lit_ptr_ram_20003470_f780 = (byte)uVar4;
    *(undefined1 *)(iVar5 + (uint)bVar1) = param_1;
    if (0x1f < (uVar4 & 0xff)) {
      *pbVar3 = 0;
    }
  }
  return;
}

// FUNC 0x1004f788  uart1_rx_callback

/* Feeds received UART1 log bytes into a second ring buffer */

void uart1_rx_callback(undefined1 param_1)

{
  byte bVar1;
  
  app_msg_cancel(0x37);
  app_msg_post(0x37,0x14);
  bVar1 = *lit_ptr_ram_20003471;
  if (bVar1 < 0x20) {
    *lit_ptr_ram_20003471 = bVar1 + 1;
    *(undefined1 *)(lit_ptr_ram_200034c1 + (uint)bVar1) = param_1;
  }
  else {
    *lit_ptr_ram_20003471 = 0;
  }
  return;
}

// FUNC 0x1004f7bc  key_highlight_clear

/* Stops the highlight timer and clears the active flag */

void key_highlight_clear(int param_1)

{
  char *pcVar1;
  
  pcVar1 = key_highlight_active;
  if (param_1 == 0x37) {
    if (*key_highlight_active != '\0') {
      console_command_handler(lit_ptr_ram_200034c1_f7dc);
      *pcVar1 = '\0';
    }
  }
  return;
}

// FUNC 0x1004f7e0  key_highlight_tick

/* Decrements the per-key highlight counters, one 0x26-byte entry each */

void key_highlight_tick(void)

{
  short *psVar1;
  short *psVar2;
  
  post_task_msg(0xc,0);
  psVar2 = (short *)(lit_ptr_ram_20003504 + 2);
  psVar1 = (short *)(lit_ptr_ram_20003504 + misc_const_02fa);
  do {
    if (((char)psVar2[-1] != '\0') && (*psVar2 != 0)) {
      *psVar2 = *psVar2 + -1;
    }
    psVar2 = psVar2 + 0x13;
  } while (psVar2 != psVar1);
  return;
}

// FUNC 0x1004f814  sum8_checksum

/* Low byte of the byte sum, used as the frame checksum */

char sum8_checksum(char *param_1,int param_2)

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

// FUNC 0x1004fcf8  tx_frame_enqueue

/* Builds seq/dir/type/flag/payload/sum into a 0x14-entry TX queue with a per-frame timer */

void tx_frame_enqueue(undefined1 param_1,undefined1 param_2,undefined1 param_3,undefined1 param_4,
                     undefined4 param_5,byte param_6)

{
  undefined1 uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  
  iVar3 = lit_ptr_ram_20003504_fd74;
  uVar5 = (uint)param_6;
  uVar4 = (uint)*lit_ptr_ram_20003503;
  while( true ) {
    if (0x13 < uVar4) {
      return;
    }
    iVar2 = uVar4 * 0x26;
    if (*(char *)(iVar2 + lit_ptr_ram_20003504_fd74) == '\0') break;
    uVar4 = uVar4 + 1 & 0xff;
    if (uVar4 == 0x14) {
      uVar4 = 0;
    }
    if (uVar4 == *lit_ptr_ram_20003503) {
      return;
    }
  }
  *(undefined1 *)(lit_ptr_ram_20003504_fd74 + iVar2) = 1;
  iVar3 = iVar3 + iVar2;
  *(undefined2 *)(iVar3 + 2) = 0;
  *(undefined1 *)(iVar3 + 6) = param_2;
  *(undefined1 *)(iVar3 + 4) = param_4;
  *(undefined1 *)(iVar3 + 5) = param_1;
  *(undefined1 *)(iVar3 + 7) = param_3;
  rom_memcpy(iVar3 + 8,param_5,uVar5);
  uVar1 = sum8_checksum(iVar3 + 5,uVar5 + 3 & 0xff);
  *(undefined1 *)(iVar3 + uVar5 + 8) = uVar1;
  *(byte *)(iVar3 + 0x25) = param_6 + 4;
  return;
}

// FUNC 0x1004fd78  base_frame_send

void base_frame_send(undefined1 param_1,undefined1 param_2,undefined1 param_3,undefined1 param_4,
                 undefined1 param_5,undefined1 param_6)

{
  char cVar1;
  undefined1 local_20;
  undefined1 local_1f;
  undefined1 local_1e;
  undefined1 local_1d;
  undefined1 local_1c;
  undefined1 local_1b;
  undefined1 local_1a;
  
  cVar1 = *lit_ptr_ram_200034e1;
  *lit_ptr_ram_200034e1 = cVar1 + '\x01';
  local_20 = 0xc;
  local_1b = param_5;
  local_1a = param_6;
  local_1f = param_1;
  local_1e = param_2;
  local_1d = param_3;
  local_1c = param_4;
  tx_frame_enqueue(cVar1,0,8,2,&local_20,7);
  return;
}

// FUNC 0x1004fdb8  blink_tx

void blink_tx(undefined1 param_1,undefined1 param_2,undefined1 param_3,undefined1 param_4,
                 undefined1 param_5,undefined1 param_6,undefined1 param_7)

{
  char cVar1;
  undefined1 local_20;
  undefined1 local_1f;
  undefined1 local_1e;
  undefined1 local_1d;
  undefined1 local_1c;
  undefined1 local_1b;
  undefined1 local_1a;
  
  cVar1 = *lit_ptr_ram_200034e1_fdf4;
  *lit_ptr_ram_200034e1_fdf4 = cVar1 + '\x01';
  local_1c = param_5;
  local_1b = param_6;
  local_1a = param_7;
  local_20 = param_1;
  local_1f = param_2;
  local_1e = param_3;
  local_1d = param_4;
  tx_frame_enqueue(cVar1,0,7,2,&local_20,7);
  return;
}

// FUNC 0x1004fdf8  all_leds_blink

/* Alternates an all-off frame and 0x11 (all red) every 200 ms; global only, no per-channel flash */

undefined8 all_leds_blink(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  byte bVar1;
  undefined1 local_10;
  undefined1 local_f;
  undefined1 local_e;
  undefined1 local_d;
  undefined1 local_c;
  undefined1 local_b;
  undefined2 uStack_a;
  undefined4 uStack_8;
  
  local_c = (undefined1)param_2;
  local_b = (undefined1)((uint)param_2 >> 8);
  uStack_a = (undefined2)((uint)param_2 >> 0x10);
  local_10 = (undefined1)param_1;
  local_f = (undefined1)((uint)param_1 >> 8);
  local_e = (undefined1)((uint)param_1 >> 0x10);
  local_d = (undefined1)((uint)param_1 >> 0x18);
  bVar1 = *all_leds_blink_phase + 1;
  *all_leds_blink_phase = bVar1;
  uStack_8 = param_3;
  if ((int)((uint)bVar1 << 0x1f) < 0) {
    local_10 = 0;
  }
  else {
    if (3 < bVar1) {
      led_frame_send(lit_ptr_led_payload);
      goto LAB_1004fe36;
    }
    local_10 = 0x11;
  }
  local_f = local_10;
  local_e = local_10;
  local_d = local_10;
  local_c = local_10;
  local_b = local_10;
  led_frame_send(&local_10);
  app_msg_post(0x36,200);
LAB_1004fe36:
  return CONCAT26(uStack_a,CONCAT15(local_b,CONCAT14(local_c,CONCAT13(local_d,CONCAT12(local_e,
                                                  CONCAT11(local_f,local_10))))));
}

// FUNC 0x1004fe40  all_leds_flash_green

/* Sends 0x55 (green on all LEDs) up to three times, then the stored frame */

undefined8 all_leds_flash_green(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  byte bVar1;
  undefined1 local_10;
  undefined1 local_f;
  undefined1 local_e;
  undefined1 local_d;
  undefined1 local_c;
  undefined1 local_b;
  undefined2 uStack_a;
  undefined4 uStack_8;
  
  local_c = (undefined1)param_2;
  local_b = (undefined1)((uint)param_2 >> 8);
  uStack_a = (undefined2)((uint)param_2 >> 0x10);
  local_10 = (undefined1)param_1;
  local_f = (undefined1)((uint)param_1 >> 8);
  local_e = (undefined1)((uint)param_1 >> 0x10);
  local_d = (undefined1)((uint)param_1 >> 0x18);
  bVar1 = *all_leds_flash_phase + 1;
  *all_leds_flash_phase = bVar1;
  uStack_8 = param_3;
  if ((int)((uint)bVar1 << 0x1f) < 0) {
    local_10 = 0x44;
  }
  else {
    if (3 < bVar1) {
      led_frame_send(lit_ptr_led_payload_fe84);
      goto LAB_1004fe7e;
    }
    local_10 = 0x55;
  }
  local_f = local_10;
  local_e = local_10;
  local_d = local_10;
  local_c = local_10;
  local_b = local_10;
  led_frame_send(&local_10);
  app_msg_post(0x35,200);
LAB_1004fe7e:
  return CONCAT26(uStack_a,CONCAT15(local_b,CONCAT14(local_c,CONCAT13(local_d,CONCAT12(local_e,
                                                  CONCAT11(local_f,local_10))))));
}

// FUNC 0x1004fe88  all_leds_set

/* Sends 0x11 (red) to all eight LEDs, then posts 0x36 to start the flash loop */

undefined8 all_leds_set(undefined4 param_1,undefined4 param_2)

{
  undefined1 local_10;
  undefined1 local_f;
  undefined1 local_e;
  undefined1 local_d;
  undefined1 local_c;
  undefined1 local_b;
  undefined2 uStack_a;
  
  local_c = (undefined1)param_2;
  local_b = (undefined1)((uint)param_2 >> 8);
  uStack_a = (undefined2)((uint)param_2 >> 0x10);
  local_10 = (undefined1)param_1;
  local_f = (undefined1)((uint)param_1 >> 8);
  local_e = (undefined1)((uint)param_1 >> 0x10);
  local_d = (undefined1)((uint)param_1 >> 0x18);
  *lit_ptr_ram_20003903 = 0;
  gpio_irq_enable();
  local_10 = 0x11;
  local_f = 0x11;
  local_e = 0x11;
  local_d = 0x11;
  local_c = 0x11;
  local_b = 0x11;
  led_frame_send(&local_10);
  *lit_ptr_ram_20003901 = 0;
  app_msg_post(0x36,200);
  return CONCAT26(uStack_a,CONCAT15(local_b,CONCAT14(local_c,CONCAT13(local_d,CONCAT12(local_e,
                                                  CONCAT11(local_f,local_10))))));
}

// FUNC 0x1004fec0  blink_fmt

void blink_fmt(undefined1 *param_1,undefined1 *param_2,undefined1 *param_3,undefined4 param_4,
                 ushort param_5,undefined2 param_6)

{
  byte bVar1;
  undefined1 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  uint extraout_r1;
  
  uVar3 = log_rotate(param_6);
  uVar3 = fmt_int_3(uVar3,lit_float_2_55);
  uVar4 = log_rotate(100 - (uint)param_5);
  uVar4 = fmt_int_3(uVar4,uVar3);
  uVar5 = log_bit_test(uVar4,lit_float_100_ffd8);
  fmt_int_19(param_4,0x3c);
  uVar4 = log_rotate(extraout_r1 & 0xffff);
  uVar6 = fmt_int(uVar3,uVar5);
  uVar4 = fmt_int_3(uVar4,uVar6);
  uVar4 = log_bit_test(uVar4,lit_float_60);
  bVar1 = fmt_int_18(param_4,0x3c);
  if (bVar1 < 5) {
    call_table_16();
    uVar2 = led_update_fmt(uVar3,uVar4);
    *param_1 = uVar2;
    fmt_s(uVar5,uVar4);
    uVar2 = led_update_fmt();
    *param_2 = uVar2;
  }
  else {
    uVar2 = led_update_fmt(uVar3);
    *param_1 = uVar2;
    uVar2 = led_update_fmt(uVar5);
    *param_2 = uVar2;
    uVar5 = fmt_int(uVar3,uVar4);
  }
  uVar2 = led_update_fmt(uVar5);
  *param_3 = uVar2;
  return;
}

// FUNC 0x1004ffe0  led_mode_update

/* Updates one channel nibble and sends the frame */

void led_mode_update(int param_1,int param_2)

{
  byte bVar1;
  byte bVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  byte local_24;
  byte local_20 [4];
  undefined1 local_1c;
  undefined1 local_1b;
  
  rom_memcpy(local_20,lit_fn_call_table_21_plus_22,6);
  iVar3 = lit_ptr_led_state_block_015c;
  uVar5 = param_1 - 1U & 0xff;
  *(undefined1 *)(lit_ptr_led_state_block_015c + 0x5d) = 0;
  uVar6 = uVar5 >> 1;
  if ((int)(uVar5 << 0x1f) < 0) {
    bVar1 = *(byte *)(iVar3 + uVar6 + 0x57);
    uVar5 = bVar1 & 0xf;
    if (1 < uVar5 - 2) {
      rom_memcpy(local_20,iVar3 + 0x57,6);
    }
    if (param_2 == 1) {
      bVar2 = 1;
      if (((bVar1 & 0xf) != 0) && (bVar2 = 0, uVar5 != 1)) {
        local_24 = (byte)(uVar5 - 2);
        bVar2 = 3;
        if ((((1 < local_24) && ((bVar2 = 5, uVar5 != 4 && (bVar2 = 4, uVar5 != 5)))) &&
            (bVar2 = 7, uVar5 != 6)) && (bVar2 = 6, uVar5 != 7)) {
          bVar2 = 8;
        }
      }
      local_20[uVar6] = bVar2 | local_20[uVar6] & 0xf0;
    }
    else {
      if (param_2 != 3) {
        return;
      }
      if (1 < (*(byte *)(lit_ptr_led_state_block_015c + uVar6 + 0x57) & 0xf) - 2) {
        return;
      }
      local_20[uVar6] = local_20[uVar6] & 0xf0 | 2;
    }
    uVar5 = local_20[uVar6] & 0xf;
  }
  else {
    uVar4 = (uint)(*(byte *)(iVar3 + uVar6 + 0x57) >> 4);
    if (1 < uVar4 - 2) {
      rom_memcpy(local_20,iVar3 + 0x57,6);
    }
    if (param_2 == 1) {
      iVar3 = 1;
      if ((uVar4 != 0) && (iVar3 = 0, uVar4 != 1)) {
        local_24 = (byte)(uVar4 - 2);
        iVar3 = 3;
        if ((1 < local_24) &&
           ((((iVar3 = 5, uVar4 != 4 && (iVar3 = 4, uVar4 != 5)) && (iVar3 = 7, uVar4 != 6)) &&
            (iVar3 = 6, uVar4 != 7)))) {
          iVar3 = 8;
        }
      }
      local_20[uVar6] = (byte)(iVar3 << 4) | local_20[uVar6] & 0xf;
    }
    else {
      if (param_2 != 3) {
        return;
      }
      uVar6 = uVar5 >> 1;
      if (1 < (*(byte *)(lit_ptr_led_state_block_015c + uVar6 + 0x57) >> 4) - 2) {
        return;
      }
      local_20[uVar6] = local_20[uVar6] & 0xf | 0x20;
    }
    uVar5 = (uint)(local_20[uVar5 >> 1] >> 4);
  }
  if (uVar5 - 2 < 2) {
    blink_search(param_1,uVar5,local_20);
  }
  else {
    led_encode_b_send(param_1,uVar5,local_20);
  }
  base_frame_send(local_20[0],local_20[1],local_20[2],local_20[3],local_1c,local_1b);
  return;
}

// FUNC 0x10050160  led_color_set

/* Stores a color nibble for one LED: selector 0..3 -> 1, 2, 5, 7 */

void led_color_set(uint param_1,int param_2)

{
  byte bVar1;
  byte bVar2;
  byte *pbVar3;
  
  if (param_2 == 0) {
    pbVar3 = (byte *)(lit_ptr_led_state_block_01f8 + (param_1 >> 1) + 0x57);
    if ((param_1 & 1) != 0) {
      bVar2 = *pbVar3 & 0xf0 | 1;
      goto LAB_100501f4;
    }
    bVar2 = *pbVar3 & 0xf;
    bVar1 = 0x10;
  }
  else if (param_2 == 1) {
    pbVar3 = (byte *)(lit_ptr_led_state_block_01f8 + (param_1 >> 1) + 0x57);
    if ((param_1 & 1) == 0) {
      bVar2 = *pbVar3 & 0xf;
      bVar1 = 0x20;
    }
    else {
      bVar2 = *pbVar3 & 0xf0;
      bVar1 = 2;
    }
  }
  else if (param_2 == 2) {
    pbVar3 = (byte *)(lit_ptr_led_state_block_01f8 + (param_1 >> 1) + 0x57);
    if ((int)(param_1 << 0x1f) < 0) {
      bVar2 = *pbVar3 & 0xf0;
      bVar1 = 5;
    }
    else {
      bVar2 = *pbVar3 & 0xf;
      bVar1 = 0x50;
    }
  }
  else {
    if (param_2 != 3) {
      return;
    }
    pbVar3 = (byte *)(lit_ptr_led_state_block_01f8 + (param_1 >> 1) + 0x57);
    if ((int)(param_1 << 0x1f) < 0) {
      bVar2 = *pbVar3 & 0xf0;
      bVar1 = 7;
    }
    else {
      bVar2 = *pbVar3 & 0xf;
      bVar1 = 0x70;
    }
  }
  bVar2 = bVar2 | bVar1;
LAB_100501f4:
  *pbVar3 = bVar2;
  return;
}

// FUNC 0x100501fc  mode_query

/* Searches the per-channel mode list for a value */

undefined4 mode_query(uint param_1)

{
  undefined4 uVar1;
  uint uVar2;
  char *pcVar3;
  
  uVar1 = 0;
  pcVar3 = lit_ptr_ram_20003927;
  do {
    if (*pcVar3 != '\0') {
      for (uVar2 = 0; (uVar2 & 0xff) < (uint)(byte)pcVar3[1]; uVar2 = uVar2 + 1) {
        if ((byte)pcVar3[uVar2 + 2] == param_1) {
          uVar1 = 1;
        }
      }
    }
    pcVar3 = pcVar3 + 0xe;
  } while (pcVar3 != lit_ptr_led_payload_0238);
  return uVar1;
}

// FUNC 0x1005023c  tick_ms_read

undefined4 tick_ms_read(void)

{
  ushort uVar1;
  uint uVar2;
  undefined4 uVar3;
  char cVar4;
  int iVar5;
  undefined8 uVar6;
  undefined4 local_34;
  undefined4 local_30;
  undefined1 local_2c;
  undefined2 local_2a;
  undefined4 local_28;
  undefined1 local_24;
  
  *(undefined4 *)(misc_const_e000e104_2 + 0x7c) = 0x400000;
  local_28 = 0;
  local_30 = 0;
  local_34 = 0;
  local_2c = 0;
  local_24 = 6;
  local_2a = 10;
  tim4_configure(&local_34);
  tim4_enable(1);
  cVar4 = (char)local_2a;
  iVar5 = misc_const_ea62;
  do {
    uVar2 = tim4_status();
    if ((uVar2 & 4) != 0) {
      iVar5 = 0;
      while (cVar4 != '\0') {
        uVar2 = tim4_status();
        if ((uVar2 & 0x10) == 0) {
          uVar1 = tim4_count();
          cVar4 = cVar4 + -1;
          iVar5 = iVar5 + (uint)uVar1;
        }
      }
      tim4_enable(0);
      fmt_int_18(iVar5,local_2a);
      uVar6 = fmt_int_8();
      fmt_int_11((int)uVar6,(int)((ulonglong)uVar6 >> 0x20),fmt_scale_const_b,lit_float_1_6465);
      uVar3 = fmt_int_6();
      return uVar3;
    }
    iVar5 = iVar5 + -1;
  } while (iVar5 != 0);
  return 0xffffffff;
}

// FUNC 0x100502d4  led_channels_flush

void led_channels_flush(void)

{
  led_channel0_send_now(0);
  led_channel1_send_now(0);
  led_channel2_send_now(0);
  return;
}

// FUNC 0x100502ec  setting_mode_exit

void setting_mode_exit(void)

{
  int iVar1;
  
  iVar1 = lit_ptr_led_state_block_0320;
  if (*(char *)(lit_ptr_led_state_block_0320 + 0x12) == '\x01') {
    led_channels_flush();
    led_channel4_send_now(4);
    *(undefined1 *)(iVar1 + 0x12) = 0;
    gpio_irq_disable_2();
    *lit_ptr_ram_2000336f_0324 = 0;
    app_msg_cancel(0x2d);
    key_event_post_500ms();
  }
  log_printf(lit_str_bl_turn_off);
  return;
}

// FUNC 0x1005032c  setting_mode_exit_confirm

void setting_mode_exit_confirm(void)

{
  int iVar1;
  
  iVar1 = lit_ptr_ram_2000380c;
  if (*(char *)(lit_ptr_ram_2000380c + 0xa4) == '\x01') {
    setting_mode_exit();
  }
  *(undefined1 *)(iVar1 + 0xa4) = 0;
  gpio_irq_enable();
  return;
}

// FUNC 0x10050354  base_frame_process

void base_frame_process(uint param_1,uint param_2,uint param_3,undefined4 param_4,undefined1 param_5)

{
  byte bVar1;
  undefined1 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  uint uVar5;
  uint uVar6;
  
  uVar3 = fmt_int_2(param_5);
  uVar3 = log_bit_test(uVar3,lit_float_255_0440);
  uVar5 = param_1;
  if (param_3 < param_1) {
    uVar5 = param_3 & 0xff;
  }
  bVar1 = (byte)uVar5;
  if (param_2 < (uVar5 & 0xff)) {
    bVar1 = (byte)param_2;
  }
  uVar5 = (uint)bVar1;
  bVar1 = call_table_13(uVar5 << 1,3);
  uVar6 = (uint)bVar1;
  uVar4 = log_rotate((param_1 - uVar5 & 0xff) + uVar6 & 0xff);
  uVar4 = fmt_int_3(uVar4,lit_float_100_0444);
  uVar4 = log_bit_test(uVar4,lit_float_255_0440);
  fmt_int_3(uVar4,uVar3);
  uVar2 = led_update_fmt();
  led_channel0_send_now(uVar2);
  uVar4 = log_rotate(uVar6 + (param_2 - uVar5 & 0xff) & 0xff);
  uVar4 = fmt_int_3(uVar4,lit_float_100_0444);
  uVar4 = log_bit_test(uVar4,lit_float_255_0440);
  fmt_int_3(uVar4,uVar3);
  uVar2 = led_update_fmt();
  led_channel2_send_now(uVar2);
  uVar4 = log_rotate(uVar6 + (param_3 - uVar5 & 0xff) & 0xff);
  uVar4 = fmt_int_3(uVar4,lit_float_100_0444);
  uVar4 = log_bit_test(uVar4,lit_float_255_0440);
  fmt_int_3(uVar4,uVar3);
  uVar2 = led_update_fmt();
  led_channel1_send_now(uVar2);
  uVar4 = log_rotate(param_4);
  uVar4 = fmt_int_3(uVar4,lit_float_100_0444);
  uVar4 = log_bit_test(uVar4,lit_float_255_0440);
  fmt_int_3(uVar4,uVar3);
  uVar2 = led_update_fmt();
  led_channel3_send_now(uVar2);
  led_channel4_send_now(param_5);
  return;
}

// FUNC 0x10050448  ui_state_reset

undefined8 ui_state_reset(undefined4 param_1,undefined4 param_2)

{
  byte bVar1;
  int iVar2;
  undefined1 *puVar3;
  
  gpio_irq_enable_3();
  puVar3 = lit_ptr_ram_20003369_0480;
  iVar2 = lit_ptr_led_state_block_047c;
  *(undefined1 *)(lit_ptr_led_state_block_047c + 0x11) = 0;
  *puVar3 = 0;
  app_msg_cancel(0x2f);
  app_msg_cancel(0x2e);
  bVar1 = *(byte *)(iVar2 + 0xc);
  base_frame_process(*(undefined1 *)(iVar2 + 8),*(undefined1 *)(iVar2 + 9),*(undefined1 *)(iVar2 + 10),
               *(undefined1 *)(iVar2 + 0xb));
  log_printf(lit_str_backlight_mode_timeout_exit);
  return CONCAT44(param_2,(uint)bVar1);
}

// FUNC 0x10050488  ui_countdown

undefined8 ui_countdown(uint param_1,uint param_2)

{
  ushort *puVar1;
  undefined1 *puVar2;
  ushort uVar3;
  uint local_14;
  
  puVar1 = lit_ptr_ram_20003808;
  if (*lit_ptr_ram_20003804 != '\0') {
    *lit_ptr_ram_20003804 = *lit_ptr_ram_20003804 + -1;
    local_14 = param_2;
    goto LAB_1005050c;
  }
  *lit_ptr_ram_20003804 = *lit_ptr_ram_20003805;
  if (*lit_ptr_ram_20003806 == '\0') {
    if (*puVar1 == 0) {
      uVar3 = 0x166;
    }
    else {
      uVar3 = *puVar1 - 1;
    }
LAB_100504b6:
    *puVar1 = uVar3;
  }
  else if (*lit_ptr_ram_20003806 == '\x01') {
    if (*puVar1 < 0x167) {
      uVar3 = *puVar1 + 1;
      goto LAB_100504b6;
    }
    *puVar1 = 1;
  }
  puVar2 = lit_ptr_ram_200037fc;
  local_14 = (uint)*lit_ptr_ram_20000b4e;
  blink_fmt(lit_ptr_ram_200037fc,lit_ptr_ram_200037fc + 1,lit_ptr_ram_200037fc + 2,*puVar1,*lit_ptr_ram_20000b60);
  puVar2[3] = 0;
  puVar2[4] = 0xff;
  base_frame_process(*puVar2,puVar2[1],puVar2[2],0,0xff);
  param_1 = (uint)(byte)puVar2[2];
  log_printf(lit_rodata_10058397,*puVar1,*puVar2,puVar2[1]);
LAB_1005050c:
  return CONCAT44(local_14,param_1);
}

// FUNC 0x10050530  key_event_dispatch

void key_event_dispatch(byte *param_1,int param_2)

{
  char cVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  char cVar4;
  undefined1 uVar5;
  undefined2 uVar6;
  short *psVar7;
  undefined2 *puVar8;
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
  undefined1 *puVar22;
  int unaff_r4;
  int iVar23;
  undefined1 uVar24;
  undefined1 local_20;
  undefined1 uStack_1f;
  undefined1 uStack_1e;
  undefined1 uStack_1d;
  undefined1 uStack_1c;
  
  if (param_2 == 2) {
    puVar22 = (undefined1 *)(uint)param_1[2];
    if (puVar22 == (undefined1 *)0xd) {
      if (*param_1 == 0) goto LAB_100505a8;
      *(undefined1 *)(ui_led_state_2 + 0x11) = 3;
      gpio_irq_disable_3();
      app_msg_post(0x2e,work_mode_msg_param);
      app_msg_cancel(0x2c);
      uVar16 = work_mode_msg_ptr_2;
      puVar22 = work_mode_msg_ptr;
      *work_mode_msg_ptr = 0;
      log_printf(uVar16);
      key_event_noop();
    }
    if ((puVar22 == (undefined1 *)0xe) && (*param_1 != 0)) {
      cVar1 = *backlight_toggle_count;
      *backlight_toggle_count = cVar1 + '\x01';
      unaff_r4 = 1;
      local_20 = 0;
      tx_frame_enqueue(cVar1,0,0xd,0,&local_20,1);
      *backlight_active_flag = 1;
      gpio_irq_disable();
      app_msg_post(0x34,backlight_log_msg);
    }
  }
LAB_100505a8:
  if (param_1 + param_2 * 2 == param_1) {
    key_event_noop();
  }
  log_printf(key_log_fmt_key,key_log_fmt_key_1,*param_1);
  iVar12 = lit_ptr_ram_2000380c_0f74;
  iVar11 = lit_ptr_led_state_block_0f68;
  iVar17 = ui_led_state;
  iVar15 = blink_state;
  iVar23 = key_active_flags;
  uVar14 = (uint)*param_1;
  if (uVar14 != 7) {
    if (uVar14 < 8) {
      if (uVar14 == 3) {
        uVar16 = 3;
        iVar15 = key_active_flags;
        goto LAB_100507a8;
      }
      if (3 < uVar14) {
        if (uVar14 != 5) {
          if (5 < uVar14) {
            if (*(char *)(key_active_flags + 0x48) != '\0') {
              key_event_tick();
            }
            iVar15 = ui_led_state;
            if (*(char *)(ui_led_state + 0x11) != '\x02') {
              if (*(char *)(ui_led_state + 0x11) == '\0') {
                led_mode_update(6,1);
              }
              goto LAB_10050a60;
            }
            iVar17 = mode_query(6);
            cVar1 = *(char *)(iVar15 + 0x18);
            if (iVar17 == 0) {
              bVar18 = cVar1 + 1;
              if (3 < bVar18) {
LAB_10050a30:
                bVar18 = 0;
              }
LAB_10050a3a:
              *(byte *)(iVar15 + 0x18) = bVar18;
              led_color_set(5,*(undefined1 *)(iVar15 + 0x18));
            }
            else if (cVar1 != '\x01') {
              bVar18 = cVar1 + 1;
              if (3 < bVar18) goto LAB_10050a30;
              if (bVar18 == 1) {
                bVar18 = 2;
              }
              goto LAB_10050a3a;
            }
            app_msg_cancel(0x2a);
            app_msg_post(0x2a,key_log_fmt_idle_2);
LAB_10050a60:
            *(undefined1 *)(iVar23 + 0x48) = 1;
            key_log_loop(key_log_fmt_active_4);
            return;
          }
          if (*(char *)(key_active_flags + 0x30) != '\0') {
            key_event_tick();
          }
          iVar23 = ui_led_state_2;
          cVar1 = *(char *)(ui_led_state_2 + 0x11);
          if (cVar1 != '\x02') {
            if (cVar1 == '\0') {
              led_mode_update(4,1);
            }
            else if (cVar1 == '\x03') {
              app_msg_cancel(0x2e);
              pbVar9 = blink_phase_idx;
              if (*lit_ptr_ram_20003807_0bcc == '\0') {
                *lit_ptr_ram_20003804_0bd0 = 0xf;
                *lit_ptr_ram_20003805_0bd4 = 0xf;
                *lit_ptr_ram_20003806_0bd8 = 1;
                *blink_phase_init_1 = 1;
                app_msg_post(0x2f,0x21);
                puVar10 = blink_count;
                if (*blink_count < 0x167) {
                  *blink_count = *blink_count + 1;
                }
                else {
                  *blink_count = 1;
                }
                puVar22 = blink_frame_base;
                blink_fmt(blink_frame_base,blink_frame_base + 1,blink_frame_base + 2,*puVar10,*blink_phase_frame,
                             *lit_ptr_ram_20000b4e_0be4);
                uVar20 = 0;
                puVar22[4] = 0xff;
                puVar22[3] = 0;
                uVar2 = puVar22[2];
                uVar3 = puVar22[1];
                uVar5 = *puVar22;
                uVar24 = 0xff;
              }
              else {
                if (*blink_phase_idx == 7) {
                  bVar18 = 0;
                }
                else {
                  bVar18 = *blink_phase_idx + 1;
                }
                *blink_phase_idx = bVar18;
                iVar23 = blink_phase_array_2 + (uint)*pbVar9 * 5;
                uVar20 = *(undefined1 *)(iVar23 + 3);
                uVar2 = *(undefined1 *)(iVar23 + 2);
                uVar3 = *(undefined1 *)(iVar23 + 1);
                uVar24 = *(undefined1 *)(iVar23 + 4);
                uVar5 = *(undefined1 *)((uint)*pbVar9 * 5 + blink_phase_array_2);
              }
              base_frame_process(uVar5,uVar3,uVar2,uVar20,uVar24);
            }
            goto LAB_1005097e;
          }
          iVar15 = mode_query(4);
          cVar1 = *(char *)(iVar23 + 0x16);
          if (iVar15 == 0) {
            bVar18 = cVar1 + 1;
            if (3 < bVar18) {
LAB_1005084c:
              bVar18 = 0;
            }
LAB_100508be:
            *(byte *)(iVar23 + 0x16) = bVar18;
            led_color_set(3,*(undefined1 *)(iVar23 + 0x16));
          }
          else if (cVar1 != '\x01') {
            bVar18 = cVar1 + 1;
            if (3 < bVar18) goto LAB_1005084c;
            if (bVar18 == 1) {
              bVar18 = 2;
            }
            goto LAB_100508be;
          }
          app_msg_cancel(0x2a);
          app_msg_post(0x2a,key_log_fmt_idle_2);
LAB_1005097e:
          uVar16 = blink_log_fmt;
          *(undefined1 *)(blink_state + 0x30) = 1;
          key_log_loop(uVar16);
          return;
        }
        uVar16 = 5;
        if (*(char *)(key_active_flags + 0x3c) != '\0') {
          uVar16 = key_event_tick();
        }
        iVar15 = ui_led_state;
        if (*(char *)(ui_led_state + 0x11) != '\x02') {
          if (*(char *)(ui_led_state + 0x11) == '\0') {
            led_mode_update(uVar16,1);
          }
          goto LAB_100509ee;
        }
        iVar17 = mode_query();
        cVar1 = *(char *)(iVar15 + 0x17);
        if (iVar17 == 0) {
          bVar18 = cVar1 + 1;
          if (3 < bVar18) {
LAB_100509c0:
            bVar18 = 0;
          }
LAB_100509ca:
          *(byte *)(iVar15 + 0x17) = bVar18;
          led_color_set(4,*(undefined1 *)(iVar15 + 0x17));
        }
        else if (cVar1 != '\x01') {
          bVar18 = cVar1 + 1;
          if (3 < bVar18) goto LAB_100509c0;
          if (bVar18 == 1) {
            bVar18 = 2;
          }
          goto LAB_100509ca;
        }
        app_msg_cancel(0x2a);
        app_msg_post(0x2a,key_log_fmt_idle_2);
LAB_100509ee:
        *(undefined1 *)(iVar23 + 0x3c) = 1;
        key_log_loop(key_log_fmt_active_3);
        return;
      }
      unaff_r4 = key_active_flags;
      if (uVar14 != 1) {
        if (uVar14 < 2) {
          temp_all_off();
        }
        if (*(char *)(iVar23 + 0x18) != '\0') {
          key_event_tick();
        }
        iVar15 = ui_led_state_2;
        if (*(char *)(ui_led_state_2 + 0x11) != '\x02') {
          if (*(char *)(ui_led_state_2 + 0x11) == '\0') {
            led_mode_update(2,1);
          }
          goto LAB_1005079a;
        }
        iVar17 = mode_query();
        cVar1 = *(char *)(iVar15 + 0x14);
        if (iVar17 == 0) {
          bVar18 = cVar1 + 1;
          if (3 < bVar18) {
LAB_1005076a:
            bVar18 = 0;
          }
LAB_10050774:
          *(byte *)(iVar15 + 0x14) = bVar18;
          led_color_set(1,*(undefined1 *)(iVar15 + 0x14));
        }
        else if (cVar1 != '\x01') {
          bVar18 = cVar1 + 1;
          if (3 < bVar18) goto LAB_1005076a;
          if (bVar18 == 1) {
            bVar18 = 2;
          }
          goto LAB_10050774;
        }
        app_msg_cancel(0x2a);
        app_msg_post(0x2a,key_log_fmt_idle);
LAB_1005079a:
        uVar16 = key_log_fmt_active;
        *(undefined1 *)(iVar23 + 0x18) = 1;
        do {
          log_printf(uVar16);
          uVar16 = key_event_tick();
          iVar15 = iVar23;
LAB_100507a8:
          cVar1 = *(char *)(iVar15 + 0x24);
          if (cVar1 != '\0') {
            uVar16 = key_event_tick();
          }
          iVar23 = ui_led_state_2;
          if (*(char *)(ui_led_state_2 + 0x11) == '\x02') {
            iVar17 = mode_query();
            cVar4 = *(char *)(iVar23 + 0x15);
            if (iVar17 == 0) {
              bVar18 = cVar4 + 1;
              if (bVar18 < 4) {
LAB_100507e8:
                *(byte *)(iVar23 + 0x15) = bVar18;
              }
              else {
                *(undefined1 *)(iVar23 + 0x15) = 0;
              }
LAB_100507ea:
              led_color_set(2,*(undefined1 *)(iVar23 + 0x15));
            }
            else if (cVar4 != '\x01') {
              bVar18 = cVar4 + 1;
              if (bVar18 < 4) {
                if (bVar18 == 1) {
                  bVar18 = 2;
                }
                goto LAB_100507e8;
              }
              *(char *)(iVar23 + 0x15) = cVar1;
              goto LAB_100507ea;
            }
            app_msg_cancel(0x2a);
            app_msg_post(0x2a,key_log_fmt_idle);
          }
          else if (*(char *)(ui_led_state_2 + 0x11) == '\0') {
            led_mode_update(uVar16,1);
          }
          iVar23 = iVar15 + 5;
          *(undefined1 *)(iVar15 + 0x24) = 1;
          uVar16 = key_log_fmt_active_2;
        } while( true );
      }
LAB_1005062e:
      if (*(char *)(unaff_r4 + 0xc) != '\0') {
        uVar14 = key_event_tick();
      }
      iVar23 = ui_led_state_2;
      cVar1 = *(char *)(ui_led_state_2 + 0x11);
      if (cVar1 != '\x02') {
        if (cVar1 == '\0') {
          led_mode_update(uVar14,uVar14);
        }
        else if (cVar1 == '\x03') {
          app_msg_cancel(0x2e);
          pbVar9 = blink_frame_idx;
          if (*blink_trigger_flag == '\0') {
            *blink_frame_init_0 = 0xf;
            *blink_frame_init_1 = 0xf;
            *blink_frame_init_2 = 0;
            *blink_frame_init_3 = 1;
            app_msg_post(0x2f,0x21);
            puVar8 = blink_frame_frame;
            psVar7 = blink_frame_count;
            if (*blink_frame_count == 0) {
              sVar19 = 0x166;
            }
            else {
              sVar19 = *blink_frame_count + -1;
            }
            *blink_frame_count = sVar19;
            puVar22 = blink_frame_frame_3;
            blink_fmt(blink_frame_frame_3,blink_frame_frame_3 + 1,blink_frame_frame_3 + 2,*psVar7,*blink_frame_frame_2,
                         *puVar8);
            uVar20 = 0;
            puVar22[4] = 0xff;
            puVar22[3] = 0;
            uVar2 = puVar22[2];
            uVar3 = puVar22[1];
            uVar5 = *puVar22;
            uVar24 = 0xff;
          }
          else {
            if (*blink_frame_idx == 0) {
              cVar1 = '\a';
            }
            else {
              cVar1 = -1;
            }
            *blink_frame_idx = *blink_frame_idx + cVar1;
            iVar23 = blink_phase_array_3 + (uint)*pbVar9 * 5;
            uVar20 = *(undefined1 *)(iVar23 + 3);
            uVar2 = *(undefined1 *)(iVar23 + 2);
            uVar3 = *(undefined1 *)(iVar23 + 1);
            uVar24 = *(undefined1 *)(iVar23 + 4);
            uVar5 = *(undefined1 *)((uint)*pbVar9 * 5 + blink_phase_array_3);
          }
          base_frame_process(uVar5,uVar3,uVar2,uVar20,uVar24);
        }
        goto LAB_1005072e;
      }
      iVar15 = mode_query();
      cVar1 = *(char *)(iVar23 + 0x13);
      if (iVar15 == 0) {
        bVar18 = cVar1 + 1;
        if (3 < bVar18) {
LAB_10050660:
          bVar18 = 0;
        }
LAB_1005066a:
        *(byte *)(iVar23 + 0x13) = bVar18;
        led_color_set(0,*(undefined1 *)(iVar23 + 0x13));
      }
      else if (cVar1 != '\x01') {
        bVar18 = cVar1 + 1;
        if (3 < bVar18) goto LAB_10050660;
        if (bVar18 == 1) {
          bVar18 = 2;
        }
        goto LAB_1005066a;
      }
      app_msg_cancel(0x2a);
      app_msg_post(0x2a,key_log_fmt_idle);
      log_printf(lit_str_snv_data_current_control_mod,*(undefined1 *)(iVar23 + 0x13));
LAB_1005072e:
      uVar16 = lit_str_key1_press;
      *(undefined1 *)(key_active_flags + 0xc) = 1;
      key_log_loop(uVar16);
      return;
    }
    if (uVar14 != 0xb) {
      if (0xb < uVar14) {
        if (uVar14 == 0xd) {
          if (*(char *)(lit_ptr_ram_2000380c_0f74 + 0x9c) != '\0') {
            key_event_tick();
            return;
          }
          if (param_2 == 1) {
            if (*(char *)(lit_ptr_led_state_block_0f68 + 0x11) == '\x03') {
              *key_color_active = 1;
              gpio_irq_enable_3();
              app_msg_cancel(0x2e);
              pcVar13 = key_log_fmt_1;
              *(undefined1 *)(iVar11 + 0x11) = 0;
              iVar23 = key_color_array_3;
              puVar22 = key_color_array;
              if (*pcVar13 == '\0') {
                bVar18 = key_color_array[4];
                uVar14 = (uint)bVar18;
                if (uVar14 != 0) {
                  uVar6 = *key_color_idx;
                  *(undefined1 *)(iVar11 + 8) = *key_color_array;
                  *(undefined2 *)(iVar11 + 0xe) = uVar6;
                  *(undefined1 *)(iVar11 + 9) = puVar22[1];
                  uVar5 = puVar22[2];
                  *(byte *)(iVar11 + 0xc) = bVar18;
                  *(undefined1 *)(iVar11 + 10) = uVar5;
                  *(undefined1 *)(iVar11 + 0xb) = puVar22[3];
                  base_frame_process();
                  key_event_post_500ms();
                  puVar22 = key_color_array_2;
                  *key_color_array_2 = *(undefined1 *)(iVar11 + 0xc);
                  puVar22[1] = *(undefined1 *)(iVar11 + 8);
                  puVar22[2] = *(undefined1 *)(iVar11 + 9);
                  puVar22[3] = *(undefined1 *)(iVar11 + 10);
                  blink_phase_update(0,9,puVar22,4,uVar14);
                }
              }
              else {
                bVar18 = *key_color_index;
                *(byte *)(iVar11 + 0x10) = bVar18;
                iVar15 = (uint)bVar18 * 5;
                iVar17 = iVar23 + iVar15;
                uVar5 = *(undefined1 *)(iVar17 + 1);
                uVar20 = *(undefined1 *)(iVar17 + 2);
                uVar24 = *(undefined1 *)(iVar17 + 3);
                uVar2 = *(undefined1 *)(iVar17 + 4);
                *(undefined1 *)(iVar11 + 8) = *(undefined1 *)(iVar15 + iVar23);
                *(undefined1 *)(iVar11 + 9) = uVar5;
                *(undefined1 *)(iVar11 + 10) = uVar20;
                *(undefined1 *)(iVar11 + 0xb) = uVar24;
                *(undefined1 *)(iVar11 + 0xc) = uVar2;
                base_frame_process();
                key_event_post_500ms();
              }
              *key_color_active = 1;
              local_20 = *(undefined1 *)(lit_ptr_led_state_block_0f68 + 0xc);
              uStack_1f = *(undefined1 *)(lit_ptr_led_state_block_0f68 + 8);
              uStack_1e = *(undefined1 *)(lit_ptr_led_state_block_0f68 + 9);
              uStack_1d = *(undefined1 *)(lit_ptr_led_state_block_0f68 + 10);
              uStack_1c = *(undefined1 *)(lit_ptr_led_state_block_0f68 + 0xb);
              cVar1 = *key_color_idx_2;
              *key_color_idx_2 = cVar1 + '\x01';
              tx_frame_enqueue(cVar1,0xff,0xc,0,&local_20,5);
            }
            puVar22 = temp_all_off_flag;
            iVar23 = lit_ptr_led_state_block_0f68;
            if (*(char *)(lit_ptr_led_state_block_0f68 + 0x11) == '\x02') {
              *(undefined1 *)(lit_ptr_led_state_block_0f68 + 0x11) = 0;
              *puVar22 = 1;
              key_event_post_500ms();
              *work_mode_exit_flag = 0;
              app_msg_cancel(0x2b);
              app_msg_cancel(0x2a);
              base_frame_send(*(undefined1 *)(iVar23 + 0x57),*(undefined1 *)(iVar23 + 0x58),
                           *(undefined1 *)(iVar23 + 0x59),*(undefined1 *)(iVar23 + 0x5a),
                           *(undefined1 *)(iVar23 + 0x5b),*(undefined1 *)(iVar23 + 0x5c));
            }
            uVar16 = key_log_fmt_3;
            *(undefined1 *)(lit_ptr_ram_2000380c_0f74 + 0x9c) = 1;
            key_log_loop(uVar16);
            return;
          }
          key_event_tick();
          return;
        }
        if (0xc < uVar14) {
          if (uVar14 == 0xe) {
            uVar14 = key_event_handler_temp_off();
          }
          if (uVar14 == 0xff) {
            backlight_change_handler();
          }
          uVar14 = key_event_tick();
          goto LAB_1005062e;
        }
        if (*(char *)(lit_ptr_ram_2000380c_0f74 + 0x90) != '\0') {
          key_event_tick();
          return;
        }
        if (*(char *)(lit_ptr_led_state_block_0f68 + 0x11) != '\x02') {
          if (*(char *)(lit_ptr_led_state_block_0f68 + 0x11) == '\0') {
            led_mode_update(0xc,1);
          }
          goto LAB_10050d60;
        }
        iVar23 = mode_query(0xc);
        cVar1 = *(char *)(iVar11 + 0x1e);
        if (iVar23 == 0) {
          bVar18 = cVar1 + 1;
          if (3 < bVar18) {
LAB_10050d30:
            bVar18 = 0;
          }
LAB_10050d3a:
          *(byte *)(iVar11 + 0x1e) = bVar18;
          led_color_set(0xb,*(undefined1 *)(iVar11 + 0x1e));
        }
        else if (cVar1 != '\x01') {
          bVar18 = cVar1 + 1;
          if (3 < bVar18) goto LAB_10050d30;
          if (bVar18 == 1) {
            bVar18 = 2;
          }
          goto LAB_10050d3a;
        }
        app_msg_cancel(0x2a);
        app_msg_post(0x2a,key_log_fmt_7);
LAB_10050d60:
        *(undefined1 *)(iVar12 + 0x90) = 1;
        key_log_loop(key_log_fmt_4);
        return;
      }
      if (uVar14 != 9) {
        if (9 < uVar14) {
          if (*(char *)(key_active_flags + 0x78) != '\0') {
            key_event_tick();
            return;
          }
          if (*(char *)(lit_ptr_led_state_block_0f68 + 0x11) != '\x02') {
            if (*(char *)(lit_ptr_led_state_block_0f68 + 0x11) == '\0') {
              led_mode_update(10,1);
            }
            goto LAB_10050c7e;
          }
          iVar15 = mode_query(10);
          cVar1 = *(char *)(iVar11 + 0x1c);
          if (iVar15 == 0) {
            bVar18 = cVar1 + 1;
            if (3 < bVar18) {
LAB_10050c4e:
              bVar18 = 0;
            }
LAB_10050c58:
            *(byte *)(iVar11 + 0x1c) = bVar18;
            led_color_set(9,*(undefined1 *)(iVar11 + 0x1c));
          }
          else if (cVar1 != '\x01') {
            bVar18 = cVar1 + 1;
            if (3 < bVar18) goto LAB_10050c4e;
            if (bVar18 == 1) {
              bVar18 = 2;
            }
            goto LAB_10050c58;
          }
          app_msg_cancel(0x2a);
          app_msg_post(0x2a,key_log_fmt_7);
LAB_10050c7e:
          *(undefined1 *)(iVar23 + 0x78) = 1;
          key_log_loop(key_log_fmt_6);
          return;
        }
        if (*(char *)(key_active_flags + 0x60) != '\0') {
          key_event_tick();
          return;
        }
        if (*(char *)(ui_led_state + 0x11) != '\x02') {
          if (*(char *)(ui_led_state + 0x11) == '\0') {
            led_mode_update(8,1);
          }
          goto LAB_10050b50;
        }
        iVar15 = mode_query(8);
        cVar1 = *(char *)(iVar17 + 0x1a);
        if (iVar15 == 0) {
          bVar18 = cVar1 + 1;
          if (3 < bVar18) {
LAB_10050b20:
            bVar18 = 0;
          }
LAB_10050b2a:
          *(byte *)(iVar17 + 0x1a) = bVar18;
          led_color_set(7,*(undefined1 *)(iVar17 + 0x1a));
        }
        else if (cVar1 != '\x01') {
          bVar18 = cVar1 + 1;
          if (3 < bVar18) goto LAB_10050b20;
          if (bVar18 == 1) {
            bVar18 = 2;
          }
          goto LAB_10050b2a;
        }
        app_msg_cancel(0x2a);
        app_msg_post(0x2a,key_log_fmt_idle_2);
LAB_10050b50:
        *(undefined1 *)(iVar23 + 0x60) = 1;
        key_log_loop(key_log_fmt_active_6);
        return;
      }
      if (*(char *)(key_active_flags + 0x6c) != '\0') {
        key_event_tick();
        return;
      }
      if (*(char *)(ui_led_state + 0x11) != '\x02') {
        if (*(char *)(ui_led_state + 0x11) == '\0') {
          led_mode_update(9,1);
        }
        goto LAB_10050bbc;
      }
      iVar15 = mode_query();
      cVar1 = *(char *)(iVar17 + 0x1b);
      if (iVar15 == 0) {
        bVar18 = cVar1 + 1;
        if (3 < bVar18) {
LAB_10050b8e:
          bVar18 = 0;
        }
LAB_10050b98:
        *(byte *)(iVar17 + 0x1b) = bVar18;
        led_color_set(8,*(undefined1 *)(iVar17 + 0x1b));
      }
      else if (cVar1 != '\x01') {
        bVar18 = cVar1 + 1;
        if (3 < bVar18) goto LAB_10050b8e;
        if (bVar18 == 1) {
          bVar18 = 2;
        }
        goto LAB_10050b98;
      }
      app_msg_cancel(0x2a);
      app_msg_post(0x2a,key_log_fmt_idle_2);
LAB_10050bbc:
      *(undefined1 *)(iVar23 + 0x60) = 1;
      key_log_loop(key_log_fmt_active_7);
      return;
    }
    if (*(char *)(lit_ptr_ram_2000380c_0f74 + 0x84) != '\0') {
      key_event_tick();
      return;
    }
    if (*(char *)(lit_ptr_led_state_block_0f68 + 0x11) != '\x02') {
      if (*(char *)(lit_ptr_led_state_block_0f68 + 0x11) == '\0') {
        led_mode_update(0xb,1);
      }
      goto LAB_10050cee;
    }
    iVar23 = mode_query();
    cVar1 = *(char *)(iVar11 + 0x1d);
    if (iVar23 == 0) {
      bVar18 = cVar1 + 1;
      if (bVar18 < 4) {
LAB_10050cca:
        *(byte *)(iVar11 + 0x1d) = bVar18;
      }
      else {
        *(undefined1 *)(iVar11 + 0x1d) = 0;
      }
LAB_10050ccc:
      led_color_set(10,*(undefined1 *)(iVar11 + 0x1d));
    }
    else if (cVar1 != '\x01') {
      bVar18 = cVar1 + 1;
      if (bVar18 < 4) {
        if (bVar18 == 1) {
          bVar18 = 2;
        }
        goto LAB_10050cca;
      }
      *(undefined1 *)(iVar11 + 0x1d) = 0;
      goto LAB_10050ccc;
    }
    app_msg_cancel(0x2a);
    app_msg_post(0x2a,key_log_fmt_7);
LAB_10050cee:
    *(undefined1 *)(iVar12 + 0x84) = 1;
    key_log_loop(key_log_fmt_5);
    return;
  }
  bVar18 = *(byte *)(blink_state + 0x54);
  uVar16 = 7;
  if (bVar18 != 0) {
    uVar16 = key_event_tick();
  }
  iVar23 = ui_led_state;
  if (*(char *)(ui_led_state + 0x11) != '\x02') {
    if (*(char *)(ui_led_state + 0x11) == '\0') {
      led_mode_update(uVar16,1);
    }
    goto LAB_10050ae0;
  }
  iVar17 = mode_query();
  cVar1 = *(char *)(iVar23 + 0x19);
  if (iVar17 == 0) {
    if ((byte)(cVar1 + 1U) < 4) {
      *(char *)(iVar23 + 0x19) = cVar1 + '\x01';
    }
    else {
      *(undefined1 *)(iVar23 + 0x19) = 0;
    }
    uVar5 = *(undefined1 *)(iVar23 + 0x19);
LAB_10050ac0:
    led_color_set(6,uVar5);
  }
  else if (cVar1 != '\x01') {
    bVar21 = cVar1 + 1;
    if ((bVar21 < 4) && (bVar18 = bVar21, bVar21 == 1)) {
      *(undefined1 *)(iVar23 + 0x19) = 2;
    }
    else {
      *(byte *)(iVar23 + 0x19) = bVar18;
    }
    uVar5 = *(undefined1 *)(ui_led_state + 0x19);
    goto LAB_10050ac0;
  }
  app_msg_cancel(0x2a);
  app_msg_post(0x2a,key_log_fmt_idle_2);
LAB_10050ae0:
  *(undefined1 *)(iVar15 + 0x54) = 1;
  key_log_loop(key_log_fmt_active_5);
  return;
}

// FUNC 0x100505b4  key_event_handler

/* Per-key actions: modes, backlight settings, multi-press work mode, temp all off/restore */

void key_event_handler(void)

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
    key_event_noop();
  }
  log_printf(key_log_fmt_key,key_log_fmt_key_1,*in_stack_00000010);
  iVar12 = lit_ptr_ram_2000380c_0f74;
  iVar11 = lit_ptr_led_state_block_0f68;
  iVar17 = ui_led_state;
  iVar15 = blink_state;
  iVar22 = key_active_flags;
  uVar14 = (uint)*in_stack_00000010;
  if (uVar14 != 7) {
    if (uVar14 < 8) {
      if (uVar14 == 3) {
        uVar16 = 3;
        iVar15 = key_active_flags;
        goto LAB_100507a8;
      }
      if (3 < uVar14) {
        if (uVar14 != 5) {
          if (5 < uVar14) {
            if (*(char *)(key_active_flags + 0x48) != '\0') {
              key_event_tick();
            }
            iVar15 = ui_led_state;
            if (*(char *)(ui_led_state + 0x11) != '\x02') {
              if (*(char *)(ui_led_state + 0x11) == '\0') {
                led_mode_update(6,1);
              }
              goto LAB_10050a60;
            }
            iVar17 = mode_query(6);
            cVar4 = *(char *)(iVar15 + 0x18);
            if (iVar17 == 0) {
              bVar18 = cVar4 + 1;
              if (3 < bVar18) {
LAB_10050a30:
                bVar18 = 0;
              }
LAB_10050a3a:
              *(byte *)(iVar15 + 0x18) = bVar18;
              led_color_set(5,*(undefined1 *)(iVar15 + 0x18));
            }
            else if (cVar4 != '\x01') {
              bVar18 = cVar4 + 1;
              if (3 < bVar18) goto LAB_10050a30;
              if (bVar18 == 1) {
                bVar18 = 2;
              }
              goto LAB_10050a3a;
            }
            app_msg_cancel(0x2a);
            app_msg_post(0x2a,key_log_fmt_idle_2);
LAB_10050a60:
            *(undefined1 *)(iVar22 + 0x48) = 1;
            key_log_loop(key_log_fmt_active_4);
            return;
          }
          if (*(char *)(key_active_flags + 0x30) != '\0') {
            key_event_tick();
          }
          iVar22 = ui_led_state_2;
          cVar4 = *(char *)(ui_led_state_2 + 0x11);
          if (cVar4 != '\x02') {
            if (cVar4 == '\0') {
              led_mode_update(4,1);
            }
            else if (cVar4 == '\x03') {
              app_msg_cancel(0x2e);
              pbVar9 = blink_phase_idx;
              if (*lit_ptr_ram_20003807_0bcc == '\0') {
                *lit_ptr_ram_20003804_0bd0 = 0xf;
                *lit_ptr_ram_20003805_0bd4 = 0xf;
                *lit_ptr_ram_20003806_0bd8 = 1;
                *blink_phase_init_1 = 1;
                app_msg_post(0x2f,0x21);
                puVar10 = blink_count;
                if (*blink_count < 0x167) {
                  *blink_count = *blink_count + 1;
                }
                else {
                  *blink_count = 1;
                }
                puVar8 = blink_frame_base;
                blink_fmt(blink_frame_base,blink_frame_base + 1,blink_frame_base + 2,*puVar10);
                uVar20 = 0;
                puVar8[4] = 0xff;
                puVar8[3] = 0;
                uVar1 = puVar8[2];
                uVar2 = puVar8[1];
                uVar5 = *puVar8;
              }
              else {
                if (*blink_phase_idx == 7) {
                  bVar18 = 0;
                }
                else {
                  bVar18 = *blink_phase_idx + 1;
                }
                *blink_phase_idx = bVar18;
                iVar22 = blink_phase_array_2 + (uint)*pbVar9 * 5;
                uVar20 = *(undefined1 *)(iVar22 + 3);
                uVar1 = *(undefined1 *)(iVar22 + 2);
                uVar2 = *(undefined1 *)(iVar22 + 1);
                uVar5 = *(undefined1 *)((uint)*pbVar9 * 5 + blink_phase_array_2);
              }
              base_frame_process(uVar5,uVar2,uVar1,uVar20);
            }
            goto LAB_1005097e;
          }
          iVar15 = mode_query(4);
          cVar4 = *(char *)(iVar22 + 0x16);
          if (iVar15 == 0) {
            bVar18 = cVar4 + 1;
            if (3 < bVar18) {
LAB_1005084c:
              bVar18 = 0;
            }
LAB_100508be:
            *(byte *)(iVar22 + 0x16) = bVar18;
            led_color_set(3,*(undefined1 *)(iVar22 + 0x16));
          }
          else if (cVar4 != '\x01') {
            bVar18 = cVar4 + 1;
            if (3 < bVar18) goto LAB_1005084c;
            if (bVar18 == 1) {
              bVar18 = 2;
            }
            goto LAB_100508be;
          }
          app_msg_cancel(0x2a);
          app_msg_post(0x2a,key_log_fmt_idle_2);
LAB_1005097e:
          uVar16 = blink_log_fmt;
          *(undefined1 *)(blink_state + 0x30) = 1;
          key_log_loop(uVar16);
          return;
        }
        uVar16 = 5;
        if (*(char *)(key_active_flags + 0x3c) != '\0') {
          uVar16 = key_event_tick();
        }
        iVar15 = ui_led_state;
        if (*(char *)(ui_led_state + 0x11) != '\x02') {
          if (*(char *)(ui_led_state + 0x11) == '\0') {
            led_mode_update(uVar16,1);
          }
          goto LAB_100509ee;
        }
        iVar17 = mode_query();
        cVar4 = *(char *)(iVar15 + 0x17);
        if (iVar17 == 0) {
          bVar18 = cVar4 + 1;
          if (3 < bVar18) {
LAB_100509c0:
            bVar18 = 0;
          }
LAB_100509ca:
          *(byte *)(iVar15 + 0x17) = bVar18;
          led_color_set(4,*(undefined1 *)(iVar15 + 0x17));
        }
        else if (cVar4 != '\x01') {
          bVar18 = cVar4 + 1;
          if (3 < bVar18) goto LAB_100509c0;
          if (bVar18 == 1) {
            bVar18 = 2;
          }
          goto LAB_100509ca;
        }
        app_msg_cancel(0x2a);
        app_msg_post(0x2a,key_log_fmt_idle_2);
LAB_100509ee:
        *(undefined1 *)(iVar22 + 0x3c) = 1;
        key_log_loop(key_log_fmt_active_3);
        return;
      }
      unaff_r4 = key_active_flags;
      if (uVar14 != 1) {
        if (uVar14 < 2) {
          temp_all_off();
        }
        if (*(char *)(iVar22 + 0x18) != '\0') {
          key_event_tick();
        }
        iVar15 = ui_led_state_2;
        if (*(char *)(ui_led_state_2 + 0x11) != '\x02') {
          if (*(char *)(ui_led_state_2 + 0x11) == '\0') {
            led_mode_update(2,1);
          }
          goto LAB_1005079a;
        }
        iVar17 = mode_query();
        cVar4 = *(char *)(iVar15 + 0x14);
        if (iVar17 == 0) {
          bVar18 = cVar4 + 1;
          if (3 < bVar18) {
LAB_1005076a:
            bVar18 = 0;
          }
LAB_10050774:
          *(byte *)(iVar15 + 0x14) = bVar18;
          led_color_set(1,*(undefined1 *)(iVar15 + 0x14));
        }
        else if (cVar4 != '\x01') {
          bVar18 = cVar4 + 1;
          if (3 < bVar18) goto LAB_1005076a;
          if (bVar18 == 1) {
            bVar18 = 2;
          }
          goto LAB_10050774;
        }
        app_msg_cancel(0x2a);
        app_msg_post(0x2a,key_log_fmt_idle);
LAB_1005079a:
        uVar16 = key_log_fmt_active;
        *(undefined1 *)(iVar22 + 0x18) = 1;
        do {
          log_printf(uVar16);
          uVar16 = key_event_tick();
          iVar15 = iVar22;
LAB_100507a8:
          cVar4 = *(char *)(iVar15 + 0x24);
          if (cVar4 != '\0') {
            uVar16 = key_event_tick();
          }
          iVar22 = ui_led_state_2;
          if (*(char *)(ui_led_state_2 + 0x11) == '\x02') {
            iVar17 = mode_query();
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
              led_color_set(2,*(undefined1 *)(iVar22 + 0x15));
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
            app_msg_cancel(0x2a);
            app_msg_post(0x2a,key_log_fmt_idle);
          }
          else if (*(char *)(ui_led_state_2 + 0x11) == '\0') {
            led_mode_update(uVar16,1);
          }
          iVar22 = iVar15 + 5;
          *(undefined1 *)(iVar15 + 0x24) = 1;
          uVar16 = key_log_fmt_active_2;
        } while( true );
      }
LAB_1005062e:
      if (*(char *)(unaff_r4 + 0xc) != '\0') {
        uVar14 = key_event_tick();
      }
      iVar22 = ui_led_state_2;
      cVar4 = *(char *)(ui_led_state_2 + 0x11);
      if (cVar4 != '\x02') {
        if (cVar4 == '\0') {
          led_mode_update(uVar14,uVar14);
        }
        else if (cVar4 == '\x03') {
          app_msg_cancel(0x2e);
          pbVar9 = blink_frame_idx;
          if (*blink_trigger_flag == '\0') {
            *blink_frame_init_0 = 0xf;
            *blink_frame_init_1 = 0xf;
            *blink_frame_init_2 = 0;
            *blink_frame_init_3 = 1;
            app_msg_post(0x2f,0x21);
            psVar7 = blink_frame_count;
            if (*blink_frame_count == 0) {
              sVar19 = 0x166;
            }
            else {
              sVar19 = *blink_frame_count + -1;
            }
            *blink_frame_count = sVar19;
            puVar8 = blink_frame_frame_3;
            blink_fmt(blink_frame_frame_3,blink_frame_frame_3 + 1,blink_frame_frame_3 + 2,*psVar7);
            uVar20 = 0;
            puVar8[4] = 0xff;
            puVar8[3] = 0;
            uVar1 = puVar8[2];
            uVar2 = puVar8[1];
            uVar5 = *puVar8;
          }
          else {
            if (*blink_frame_idx == 0) {
              cVar4 = '\a';
            }
            else {
              cVar4 = -1;
            }
            *blink_frame_idx = *blink_frame_idx + cVar4;
            iVar22 = blink_phase_array_3 + (uint)*pbVar9 * 5;
            uVar20 = *(undefined1 *)(iVar22 + 3);
            uVar1 = *(undefined1 *)(iVar22 + 2);
            uVar2 = *(undefined1 *)(iVar22 + 1);
            uVar5 = *(undefined1 *)((uint)*pbVar9 * 5 + blink_phase_array_3);
          }
          base_frame_process(uVar5,uVar2,uVar1,uVar20);
        }
        goto LAB_1005072e;
      }
      iVar15 = mode_query();
      cVar4 = *(char *)(iVar22 + 0x13);
      if (iVar15 == 0) {
        bVar18 = cVar4 + 1;
        if (3 < bVar18) {
LAB_10050660:
          bVar18 = 0;
        }
LAB_1005066a:
        *(byte *)(iVar22 + 0x13) = bVar18;
        led_color_set(0,*(undefined1 *)(iVar22 + 0x13));
      }
      else if (cVar4 != '\x01') {
        bVar18 = cVar4 + 1;
        if (3 < bVar18) goto LAB_10050660;
        if (bVar18 == 1) {
          bVar18 = 2;
        }
        goto LAB_1005066a;
      }
      app_msg_cancel(0x2a);
      app_msg_post(0x2a,key_log_fmt_idle);
      log_printf(lit_str_snv_data_current_control_mod,*(undefined1 *)(iVar22 + 0x13));
LAB_1005072e:
      uVar16 = lit_str_key1_press;
      *(undefined1 *)(key_active_flags + 0xc) = 1;
      key_log_loop(uVar16);
      return;
    }
    if (uVar14 != 0xb) {
      if (0xb < uVar14) {
        if (uVar14 == 0xd) {
          if (*(char *)(lit_ptr_ram_2000380c_0f74 + 0x9c) != '\0') {
            key_event_tick();
            return;
          }
          if (unaff_r7 == 1) {
            if (*(char *)(lit_ptr_led_state_block_0f68 + 0x11) == '\x03') {
              *key_color_active = 1;
              gpio_irq_enable_3();
              app_msg_cancel(0x2e);
              pcVar13 = key_log_fmt_1;
              *(undefined1 *)(iVar11 + 0x11) = 0;
              iVar22 = key_color_array_3;
              puVar8 = key_color_array;
              if (*pcVar13 == '\0') {
                cVar4 = key_color_array[4];
                if (cVar4 != '\0') {
                  uVar6 = *key_color_idx;
                  *(undefined1 *)(iVar11 + 8) = *key_color_array;
                  *(undefined2 *)(iVar11 + 0xe) = uVar6;
                  *(undefined1 *)(iVar11 + 9) = puVar8[1];
                  uVar5 = puVar8[2];
                  *(char *)(iVar11 + 0xc) = cVar4;
                  *(undefined1 *)(iVar11 + 10) = uVar5;
                  *(undefined1 *)(iVar11 + 0xb) = puVar8[3];
                  base_frame_process();
                  key_event_post_500ms();
                  puVar8 = key_color_array_2;
                  *key_color_array_2 = *(undefined1 *)(iVar11 + 0xc);
                  puVar8[1] = *(undefined1 *)(iVar11 + 8);
                  puVar8[2] = *(undefined1 *)(iVar11 + 9);
                  puVar8[3] = *(undefined1 *)(iVar11 + 10);
                  blink_phase_update(0,9,puVar8,4);
                }
              }
              else {
                bVar18 = *key_color_index;
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
                base_frame_process();
                key_event_post_500ms();
              }
              *key_color_active = 1;
              cVar4 = *key_color_idx_2;
              *key_color_idx_2 = cVar4 + '\x01';
              tx_frame_enqueue(cVar4,0xff,0xc,0);
            }
            puVar8 = temp_all_off_flag;
            iVar22 = lit_ptr_led_state_block_0f68;
            if (*(char *)(lit_ptr_led_state_block_0f68 + 0x11) == '\x02') {
              *(undefined1 *)(lit_ptr_led_state_block_0f68 + 0x11) = 0;
              *puVar8 = 1;
              key_event_post_500ms();
              *work_mode_exit_flag = 0;
              app_msg_cancel(0x2b);
              app_msg_cancel(0x2a);
              base_frame_send(*(undefined1 *)(iVar22 + 0x57),*(undefined1 *)(iVar22 + 0x58),
                           *(undefined1 *)(iVar22 + 0x59),*(undefined1 *)(iVar22 + 0x5a));
            }
            uVar16 = key_log_fmt_3;
            *(undefined1 *)(lit_ptr_ram_2000380c_0f74 + 0x9c) = 1;
            key_log_loop(uVar16);
            return;
          }
          key_event_tick();
          return;
        }
        if (0xc < uVar14) {
          if (uVar14 == 0xe) {
            uVar14 = key_event_handler_temp_off();
          }
          if (uVar14 == 0xff) {
            backlight_change_handler();
          }
          uVar14 = key_event_tick();
          goto LAB_1005062e;
        }
        if (*(char *)(lit_ptr_ram_2000380c_0f74 + 0x90) != '\0') {
          key_event_tick();
          return;
        }
        if (*(char *)(lit_ptr_led_state_block_0f68 + 0x11) != '\x02') {
          if (*(char *)(lit_ptr_led_state_block_0f68 + 0x11) == '\0') {
            led_mode_update(0xc,1);
          }
          goto LAB_10050d60;
        }
        iVar22 = mode_query(0xc);
        cVar4 = *(char *)(iVar11 + 0x1e);
        if (iVar22 == 0) {
          bVar18 = cVar4 + 1;
          if (3 < bVar18) {
LAB_10050d30:
            bVar18 = 0;
          }
LAB_10050d3a:
          *(byte *)(iVar11 + 0x1e) = bVar18;
          led_color_set(0xb,*(undefined1 *)(iVar11 + 0x1e));
        }
        else if (cVar4 != '\x01') {
          bVar18 = cVar4 + 1;
          if (3 < bVar18) goto LAB_10050d30;
          if (bVar18 == 1) {
            bVar18 = 2;
          }
          goto LAB_10050d3a;
        }
        app_msg_cancel(0x2a);
        app_msg_post(0x2a,key_log_fmt_7);
LAB_10050d60:
        *(undefined1 *)(iVar12 + 0x90) = 1;
        key_log_loop(key_log_fmt_4);
        return;
      }
      if (uVar14 != 9) {
        if (9 < uVar14) {
          if (*(char *)(key_active_flags + 0x78) != '\0') {
            key_event_tick();
            return;
          }
          if (*(char *)(lit_ptr_led_state_block_0f68 + 0x11) != '\x02') {
            if (*(char *)(lit_ptr_led_state_block_0f68 + 0x11) == '\0') {
              led_mode_update(10,1);
            }
            goto LAB_10050c7e;
          }
          iVar15 = mode_query(10);
          cVar4 = *(char *)(iVar11 + 0x1c);
          if (iVar15 == 0) {
            bVar18 = cVar4 + 1;
            if (3 < bVar18) {
LAB_10050c4e:
              bVar18 = 0;
            }
LAB_10050c58:
            *(byte *)(iVar11 + 0x1c) = bVar18;
            led_color_set(9,*(undefined1 *)(iVar11 + 0x1c));
          }
          else if (cVar4 != '\x01') {
            bVar18 = cVar4 + 1;
            if (3 < bVar18) goto LAB_10050c4e;
            if (bVar18 == 1) {
              bVar18 = 2;
            }
            goto LAB_10050c58;
          }
          app_msg_cancel(0x2a);
          app_msg_post(0x2a,key_log_fmt_7);
LAB_10050c7e:
          *(undefined1 *)(iVar22 + 0x78) = 1;
          key_log_loop(key_log_fmt_6);
          return;
        }
        if (*(char *)(key_active_flags + 0x60) != '\0') {
          key_event_tick();
          return;
        }
        if (*(char *)(ui_led_state + 0x11) != '\x02') {
          if (*(char *)(ui_led_state + 0x11) == '\0') {
            led_mode_update(8,1);
          }
          goto LAB_10050b50;
        }
        iVar15 = mode_query(8);
        cVar4 = *(char *)(iVar17 + 0x1a);
        if (iVar15 == 0) {
          bVar18 = cVar4 + 1;
          if (3 < bVar18) {
LAB_10050b20:
            bVar18 = 0;
          }
LAB_10050b2a:
          *(byte *)(iVar17 + 0x1a) = bVar18;
          led_color_set(7,*(undefined1 *)(iVar17 + 0x1a));
        }
        else if (cVar4 != '\x01') {
          bVar18 = cVar4 + 1;
          if (3 < bVar18) goto LAB_10050b20;
          if (bVar18 == 1) {
            bVar18 = 2;
          }
          goto LAB_10050b2a;
        }
        app_msg_cancel(0x2a);
        app_msg_post(0x2a,key_log_fmt_idle_2);
LAB_10050b50:
        *(undefined1 *)(iVar22 + 0x60) = 1;
        key_log_loop(key_log_fmt_active_6);
        return;
      }
      if (*(char *)(key_active_flags + 0x6c) != '\0') {
        key_event_tick();
        return;
      }
      if (*(char *)(ui_led_state + 0x11) != '\x02') {
        if (*(char *)(ui_led_state + 0x11) == '\0') {
          led_mode_update(9,1);
        }
        goto LAB_10050bbc;
      }
      iVar15 = mode_query();
      cVar4 = *(char *)(iVar17 + 0x1b);
      if (iVar15 == 0) {
        bVar18 = cVar4 + 1;
        if (3 < bVar18) {
LAB_10050b8e:
          bVar18 = 0;
        }
LAB_10050b98:
        *(byte *)(iVar17 + 0x1b) = bVar18;
        led_color_set(8,*(undefined1 *)(iVar17 + 0x1b));
      }
      else if (cVar4 != '\x01') {
        bVar18 = cVar4 + 1;
        if (3 < bVar18) goto LAB_10050b8e;
        if (bVar18 == 1) {
          bVar18 = 2;
        }
        goto LAB_10050b98;
      }
      app_msg_cancel(0x2a);
      app_msg_post(0x2a,key_log_fmt_idle_2);
LAB_10050bbc:
      *(undefined1 *)(iVar22 + 0x60) = 1;
      key_log_loop(key_log_fmt_active_7);
      return;
    }
    if (*(char *)(lit_ptr_ram_2000380c_0f74 + 0x84) != '\0') {
      key_event_tick();
      return;
    }
    if (*(char *)(lit_ptr_led_state_block_0f68 + 0x11) != '\x02') {
      if (*(char *)(lit_ptr_led_state_block_0f68 + 0x11) == '\0') {
        led_mode_update(0xb,1);
      }
      goto LAB_10050cee;
    }
    iVar22 = mode_query();
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
      led_color_set(10,*(undefined1 *)(iVar11 + 0x1d));
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
    app_msg_cancel(0x2a);
    app_msg_post(0x2a,key_log_fmt_7);
LAB_10050cee:
    *(undefined1 *)(iVar12 + 0x84) = 1;
    key_log_loop(key_log_fmt_5);
    return;
  }
  bVar18 = *(byte *)(blink_state + 0x54);
  uVar16 = 7;
  if (bVar18 != 0) {
    uVar16 = key_event_tick();
  }
  iVar22 = ui_led_state;
  if (*(char *)(ui_led_state + 0x11) != '\x02') {
    if (*(char *)(ui_led_state + 0x11) == '\0') {
      led_mode_update(uVar16,1);
    }
    goto LAB_10050ae0;
  }
  iVar17 = mode_query();
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
    led_color_set(6,uVar5);
  }
  else if (cVar4 != '\x01') {
    bVar21 = cVar4 + 1;
    if ((bVar21 < 4) && (bVar18 = bVar21, bVar21 == 1)) {
      *(undefined1 *)(iVar22 + 0x19) = 2;
    }
    else {
      *(byte *)(iVar22 + 0x19) = bVar18;
    }
    uVar5 = *(undefined1 *)(ui_led_state + 0x19);
    goto LAB_10050ac0;
  }
  app_msg_cancel(0x2a);
  app_msg_post(0x2a,key_log_fmt_idle_2);
LAB_10050ae0:
  *(undefined1 *)(iVar15 + 0x54) = 1;
  key_log_loop(key_log_fmt_active_5);
  return;
}

// FUNC 0x100507a0  key_log_loop

void key_log_loop(undefined4 param_1)

{
  char cVar1;
  char cVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  byte bVar6;
  int unaff_r4;
  
  do {
    log_printf(param_1);
    uVar4 = key_event_tick();
    cVar1 = *(char *)(unaff_r4 + 0x24);
    if (cVar1 != '\0') {
      uVar4 = key_event_tick();
    }
    iVar3 = ui_led_state_2;
    if (*(char *)(ui_led_state_2 + 0x11) == '\x02') {
      iVar5 = mode_query();
      cVar2 = *(char *)(iVar3 + 0x15);
      if (iVar5 == 0) {
        bVar6 = cVar2 + 1;
        if (bVar6 < 4) {
LAB_100507e8:
          *(byte *)(iVar3 + 0x15) = bVar6;
        }
        else {
          *(undefined1 *)(iVar3 + 0x15) = 0;
        }
LAB_100507ea:
        led_color_set(2,*(undefined1 *)(iVar3 + 0x15));
      }
      else if (cVar2 != '\x01') {
        bVar6 = cVar2 + 1;
        if (bVar6 < 4) {
          if (bVar6 == 1) {
            bVar6 = 2;
          }
          goto LAB_100507e8;
        }
        *(char *)(iVar3 + 0x15) = cVar1;
        goto LAB_100507ea;
      }
      app_msg_cancel(0x2a);
      app_msg_post(0x2a,key_log_fmt_idle);
    }
    else if (*(char *)(ui_led_state_2 + 0x11) == '\0') {
      led_mode_update(uVar4,1);
    }
    *(undefined1 *)(unaff_r4 + 0x24) = 1;
    param_1 = key_log_fmt_active_2;
    unaff_r4 = unaff_r4 + 5;
  } while( true );
}

// FUNC 0x10050ea2  key_event_handler_temp_off

void key_event_handler_temp_off(void)

{
  int iVar1;
  int unaff_r7;
  
  iVar1 = lit_ptr_ram_2000380c_0f74;
  if (*(char *)(lit_ptr_ram_2000380c_0f74 + 0xa8) != '\0') {
    key_event_tick();
    return;
  }
  if (unaff_r7 != 1) {
    key_event_tick();
    return;
  }
  gpio_irq_disable();
  *(undefined1 *)(iVar1 + 0xa8) = 1;
  key_log_loop(lit_str_key14_press);
  return;
}

// FUNC 0x10050ec4  temp_all_off

void temp_all_off(void)

{
  char cVar1;
  int iVar2;
  undefined1 *puVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  undefined *puVar10;
  uint uVar11;
  char *pcVar12;
  int unaff_r4;
  byte *pbVar13;
  int unaff_r7;
  int in_stack_00000010;
  uint uStack00000018;
  
  iVar2 = lit_ptr_led_state_block_0f68;
  uStack00000018 = (uint)*(byte *)(lit_ptr_led_state_block_0f68 + 0x11);
  if (uStack00000018 == 3) {
    if ((*(char *)(unaff_r4 + 0xc) != '\0') || (*(char *)(unaff_r4 + 0x30) != '\0')) {
      *lit_ptr_ram_20003369_0fb0 = 0;
      app_msg_cancel(0x2f);
      app_msg_cancel(0x2e);
      app_msg_post(0x2e,msg_delay_20s);
      uVar4 = app_msg_release(0x2f);
      log_printf(lit_str_bl_rgb_change_timer_d_bl_set,uVar4);
    }
    if (*(char *)(in_stack_00000010 + 1) == '\x01') {
      *(undefined1 *)(unaff_r4 + 0xc) = 0;
      *(undefined4 *)(unaff_r4 + 0x10) = 0;
    }
    if (*(char *)(in_stack_00000010 + 1) == '\x04') {
      *(undefined1 *)(unaff_r4 + 0x30) = 0;
      *(undefined4 *)(unaff_r4 + 0x34) = 0;
    }
    puVar10 = lit_str_bl_mode_release_key;
    if (*(char *)(in_stack_00000010 + 1) == '\r') {
      *(undefined1 *)(unaff_r4 + 0x9c) = 0;
      *(undefined4 *)(unaff_r4 + 0xa0) = 0;
      puVar10 = lit_str_bl_mode_release_key;
    }
  }
  else {
    if (*key_color_active != '\0') {
      *key_color_active = '\0';
      gpio_irq_enable_3();
      goto LAB_100511a0;
    }
    if (*temp_all_off_flag != '\0') {
      gpio_irq_enable_2();
      *temp_all_off_flag = '\0';
      goto LAB_100511a0;
    }
    uVar11 = (uint)*(byte *)(lit_ptr_ram_20000b50 + (uint)*(byte *)(in_stack_00000010 + 1));
    if ((uVar11 == 0xd) && (unaff_r7 == 1)) {
      app_msg_cancel(0x32);
      app_msg_post(0x32,0x15e);
      pcVar12 = (char *)(unaff_r4 + 0xa4);
      cVar1 = *pcVar12;
      *pcVar12 = cVar1 + '\x01';
      if ((char)(cVar1 + '\x01') == '\x02') {
        *pcVar12 = '\0';
        puVar3 = lit_ptr_ram_2000336a_12a8;
        *(undefined4 *)(unaff_r4 + 0xa0) = 0;
        *puVar3 = 1;
        app_msg_post(0x2b,200);
        uVar4 = delay_10000;
        *(undefined1 *)(iVar2 + 0x11) = 2;
        app_msg_post(0x2a,uVar4);
        app_msg_cancel(0x32);
        if (*(char *)(iVar2 + 0x12) == '\0') {
          base_frame_process(*(undefined1 *)(iVar2 + 8),*(undefined1 *)(iVar2 + 9),
                       *(undefined1 *)(iVar2 + 10),*(undefined1 *)(iVar2 + 0xb));
          *(undefined1 *)(iVar2 + 0x12) = 1;
          gpio_irq_enable_2();
          key_event_post_500ms();
        }
        else {
          app_msg_cancel(0x33);
        }
        log_printf(lit_str_key13_d_times_press_enter_se,2);
      }
      goto LAB_100511a0;
    }
    if (1 < uVar11 - 0xd) {
      if (uStack00000018 == 0) {
        led_mode_update((uint)*(byte *)(in_stack_00000010 + 1),3);
      }
      goto LAB_100511a0;
    }
    if ((((uStack00000018 != 0) || (uVar11 != 0xe)) || (unaff_r7 != 1)) || (*lit_ptr_ram_20003903_12b4 != '\0'))
    goto LAB_100511a0;
    gpio_irq_enable();
    if (*(char *)(iVar2 + 0x5d) == '\0') {
      pbVar13 = (byte *)(iVar2 + 0x57);
      rom_memcpy(iVar2 + 0x5e,pbVar13,6);
      iVar5 = led_nibble_encode_a(*pbVar13 >> 4);
      uVar11 = led_nibble_encode_a(*pbVar13 & 0xf);
      iVar6 = led_nibble_encode_a(*(byte *)(iVar2 + 0x58) >> 4);
      uVar7 = led_nibble_encode_a(*(byte *)(iVar2 + 0x58) & 0xf);
      iVar8 = led_nibble_encode_a(*(byte *)(iVar2 + 0x59) >> 4);
      uVar9 = led_nibble_encode_a(*(byte *)(iVar2 + 0x59) & 0xf);
      led_nibble_encode_a(*(byte *)(iVar2 + 0x5a) >> 4);
      led_nibble_encode_a(*(byte *)(iVar2 + 0x5a) & 0xf);
      led_nibble_encode_a(*(byte *)(iVar2 + 0x5b) >> 4);
      led_nibble_encode_a(*(byte *)(iVar2 + 0x5b) & 0xf);
      led_nibble_encode_a(*(byte *)(iVar2 + 0x5c) >> 4);
      led_nibble_encode_a(*(byte *)(iVar2 + 0x5c) & 0xf);
      blink_tx(uStack00000018,(iVar5 << 4 | uVar11) & 0xff,(iVar6 << 4 | uVar7) & 0xff,
                   (iVar8 << 4 | uVar9) & 0xff);
      puVar10 = PTR_s_temp_all_off_100512b8;
    }
    else {
      blink_tx(*(char *)(iVar2 + 0x5d),*(undefined1 *)(iVar2 + 0x5e),
                   *(undefined1 *)(iVar2 + 0x5f),*(undefined1 *)(iVar2 + 0x60));
      puVar10 = PTR_s_temp_all_restore_100512bc;
    }
  }
  log_printf(puVar10);
LAB_100511a0:
  iVar2 = lit_ptr_ram_2000380c_12c0;
  *(undefined1 *)((uint)*(byte *)(in_stack_00000010 + 1) * 0xc + lit_ptr_ram_2000380c_12c0) = 0;
  *(undefined4 *)(iVar2 + (uint)*(byte *)(in_stack_00000010 + 1) * 0xc + 4) = 0;
  key_event_tick();
  return;
}

// FUNC 0x100511ba  backlight_change_handler

/* Backlight change state machine; logs BL change 10 and 30 times */

void backlight_change_handler(void)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  undefined *puVar4;
  undefined1 *puVar5;
  int iVar6;
  uint uVar7;
  uint *puVar8;
  char *pcVar9;
  int unaff_r7;
  int in_stack_00000014;
  
  iVar6 = lit_ptr_led_state_block_12c4;
  iVar2 = lit_ptr_ram_2000380c_12c0;
  if (*(char *)(lit_ptr_led_state_block_12c4 + 0x11) == '\x03') {
    pcVar9 = (char *)(lit_ptr_ram_2000380c_12c0 + 0x30);
    log_printf(lit_str_hold_on_d_d,*(undefined1 *)(lit_ptr_ram_2000380c_12c0 + 0xc),*pcVar9);
    if (*lit_ptr_ram_20003807_12cc == '\0') {
      if (*(char *)(iVar2 + 0xc) == '\0') goto LAB_10051224;
      iVar6 = *(int *)(iVar2 + 0x10);
      puVar5 = (undefined1 *)(iVar6 + 1);
      *(undefined1 **)(iVar2 + 0x10) = puVar5;
      while( true ) {
        uVar3 = lit_str_bl_change_5_times;
        if (puVar5 == (undefined1 *)0x1) {
          iVar6 = 6;
          *lit_ptr_ram_20003804_12d0 = 6;
          puVar5 = lit_ptr_ram_20003805_12d8;
          *lit_ptr_ram_20003805_12d8 = 6;
          key_log_loop(uVar3);
        }
        puVar4 = PTR_s_BL_change_10_times_100512dc;
        if (iVar6 - 1U < 3) {
          *lit_ptr_ram_20003804_12d0 = 3;
          puVar5 = lit_ptr_ram_20003805_12d8;
          *lit_ptr_ram_20003805_12d8 = 3;
          key_log_loop(puVar4);
        }
        puVar4 = PTR_s_BL_change_30_times_100512e0;
        if (puVar5 < (undefined1 *)0x5) break;
        *lit_ptr_ram_20003804_12d0 = 0;
        *lit_ptr_ram_20003805_12d8 = 0;
        key_log_loop(puVar4);
LAB_10051224:
        if (*pcVar9 == '\0') break;
        iVar6 = *(int *)(iVar2 + 0x34);
        puVar5 = (undefined1 *)(iVar6 + 1);
        *(undefined1 **)(iVar2 + 0x34) = puVar5;
      }
    }
  }
  else if ((*(char *)(in_stack_00000014 + 1) == '\x0e') && (unaff_r7 == 1)) {
    pcVar9 = (char *)(lit_ptr_ram_2000380c_12c0 + 0xa8);
    if (*pcVar9 != '\0') {
      puVar8 = (uint *)(lit_ptr_ram_2000380c_12c0 + 0xac);
      uVar7 = *puVar8;
      *puVar8 = uVar7 + 1;
      if (9 < uVar7 + 1) {
        led_state_reset();
        base_frame_process(*(undefined1 *)(iVar6 + 8),*(undefined1 *)(iVar6 + 9),
                     *(undefined1 *)(iVar6 + 10),*(undefined1 *)(iVar6 + 0xb));
        led_frame_send(lit_ptr_led_payload_12e4);
        key_event_post_500ms();
        cVar1 = *lit_ptr_ram_200034e1_12e8;
        *lit_ptr_ram_200034e1_12e8 = cVar1 + '\x01';
        tx_frame_enqueue(cVar1,0,0xd);
        *puVar8 = 0;
        *pcVar9 = '\0';
      }
    }
  }
  key_event_handler();
  return;
}

// FUNC 0x10051294  key_event_tick

void key_event_tick(void)

{
  key_event_handler();
  return;
}

// FUNC 0x1005129e  key_event_noop

void key_event_noop(void)

{
  return;
}

// FUNC 0x100512ec  blink_init

void blink_init(void)

{
  char cVar1;
  char cVar2;
  bool bVar3;
  bool bVar4;
  bool bVar5;
  int iVar6;
  uint uVar7;
  char *pcVar8;
  int iVar9;
  undefined1 local_40;
  undefined1 local_38 [36];
  
  bVar5 = false;
  call_table_19(local_38,0,0x1e);
  iVar9 = 1;
  mem_set();
  uVar7 = 0;
  bVar3 = false;
  bVar4 = false;
  pcVar8 = lit_ptr_ram_200038c5;
  do {
    cVar1 = pcVar8[5];
    cVar2 = pcVar8[6];
    pcVar8[4] = cVar1;
    pcVar8[5] = cVar2;
    local_40 = (undefined1)iVar9;
    if (cVar1 == '\0') {
      if (cVar2 == '\x01') {
        local_38[uVar7 * 2] = *(undefined1 *)(iVar9 + lit_ptr_ram_20000b50_1468);
        local_38[uVar7 * 2 + 1] = local_40;
        uVar7 = uVar7 + 1 & 0xff;
        if (iVar9 == 0xe) {
          bVar5 = true;
        }
        if ((*(char *)(lit_ptr_led_state_block_146c + 0x12) == '\0') && (iVar9 == 0xd)) {
          return;
        }
        log_printf(lit_str_d_d,iVar9);
        bVar3 = true;
      }
    }
    else if (cVar1 == '\x01') {
      if (cVar2 == '\x01') {
        cVar1 = pcVar8[7];
        pcVar8[7] = cVar1 + 1U;
        iVar6 = uVar7 * 2;
        if ((byte)(cVar1 + 1U) < 0x19) {
          local_38[iVar6] = *(undefined1 *)(iVar9 + lit_ptr_ram_20000b50_1468);
          local_38[iVar6 + 1] = local_40;
          bVar4 = true;
        }
        else {
          local_38[iVar6] = 0xff;
          local_38[iVar6 + 1] = local_40;
          pcVar8[7] = '\0';
        }
        uVar7 = uVar7 + 1 & 0xff;
        if (iVar9 == 0xe) {
          bVar5 = true;
        }
      }
      else if (cVar2 == '\0') {
        local_38[uVar7 * 2] = 0;
        local_38[uVar7 * 2 + 1] = local_40;
        uVar7 = uVar7 + 1 & 0xff;
        pcVar8[7] = '\0';
        bVar3 = true;
        if (iVar9 == 0xe) {
          bVar5 = true;
        }
      }
    }
    iVar6 = lit_ptr_led_state_block_146c;
    iVar9 = iVar9 + 1;
    pcVar8 = pcVar8 + 4;
  } while (iVar9 != 0xf);
  if ((!bVar3) && (bVar4)) {
    return;
  }
  if (uVar7 == 0) {
    return;
  }
  if ((bVar5) && (uVar7 == 1)) {
    if (*(char *)(lit_ptr_led_state_block_146c + 0x12) == '\0') {
      base_frame_process(*(undefined1 *)(lit_ptr_led_state_block_146c + 8),*(undefined1 *)(lit_ptr_led_state_block_146c + 9),
                   *(undefined1 *)(lit_ptr_led_state_block_146c + 10),*(undefined1 *)(lit_ptr_led_state_block_146c + 0xb),
                   *(undefined1 *)(lit_ptr_led_state_block_146c + 0xc));
      pcVar8 = lit_ptr_ram_20000b4c_1474;
      *(undefined1 *)(iVar6 + 0x12) = 1;
      if (*pcVar8 != '\0') {
        *lit_ptr_ram_2000336f_1478 = 1;
        app_msg_post(0x2d,100);
      }
      gpio_irq_enable_2();
      key_event_post_500ms();
      goto LAB_10051458;
    }
  }
  else if (*(char *)(lit_ptr_led_state_block_146c + 0x12) == '\0') {
    base_frame_process(*(undefined1 *)(lit_ptr_led_state_block_146c + 8),*(undefined1 *)(lit_ptr_led_state_block_146c + 9),
                 *(undefined1 *)(lit_ptr_led_state_block_146c + 10),*(undefined1 *)(lit_ptr_led_state_block_146c + 0xb),
                 *(undefined1 *)(lit_ptr_led_state_block_146c + 0xc));
    pcVar8 = lit_ptr_ram_20000b4c_1474;
    *(undefined1 *)(iVar6 + 0x12) = 1;
    if (*pcVar8 != '\0') {
      *lit_ptr_ram_2000336f_1478 = 1;
      app_msg_post(0x2d,100);
    }
    gpio_irq_enable_2();
    key_event_post_500ms();
    return;
  }
  app_msg_cancel(0x33);
LAB_10051458:
  key_event_dispatch(local_38,uVar7);
  return;
}

// FUNC 0x1005147c  periodic_ui_update

undefined8 periodic_ui_update(uint param_1,undefined4 param_2)

{
  byte *pbVar1;
  int iVar2;
  uint uVar3;
  byte bVar4;
  char cVar5;
  uint uVar6;
  undefined4 local_10;
  
  uVar3 = tick_ms_read();
  pbVar1 = lit_ptr_ram_20003902;
  bVar4 = 0;
  if (0xb6 < uVar3) {
    if (uVar3 - 0xb7 < 0xb6) {
      bVar4 = 1;
    }
    else if (uVar3 - 0x16d < 0x1b4) {
      bVar4 = 2;
    }
    else if (misc_const_0897 < uVar3 + misc_const_fffffcdf) {
      bVar4 = 4;
    }
    else {
      bVar4 = 3;
    }
  }
  *lit_ptr_ram_20003902 = bVar4;
  iVar2 = lit_ptr_led_state_block_1520;
  bVar4 = *(byte *)(lit_ptr_led_state_block_1520 + 0xc);
  uVar6 = (uint)bVar4;
  uVar3 = (uint)*(byte *)(lit_ptr_ram_20000b62 + (uint)*pbVar1);
  if (uVar3 < uVar6) {
    if (uVar6 < 0x81) {
      if (uVar6 <= uVar3 + 1) {
LAB_100514ea:
        *(byte *)(lit_ptr_led_state_block_1520 + 0xc) = *(byte *)(lit_ptr_ram_20000b62 + (uint)*pbVar1);
        goto LAB_100514f2;
      }
      cVar5 = bVar4 - 2;
    }
    else {
      cVar5 = bVar4 - 10;
    }
  }
  else {
    if (uVar3 <= uVar6) goto LAB_100514f2;
    if (uVar6 < 0x81) {
      cVar5 = bVar4 + 2;
    }
    else {
      cVar5 = bVar4 + 10;
      if ((int)(uVar3 - uVar6) < 10) goto LAB_100514ea;
    }
  }
  *(char *)(lit_ptr_led_state_block_1520 + 0xc) = cVar5;
LAB_100514f2:
  local_10 = param_1;
  if ((*lit_ptr_ram_200038c0_1528 == '\0') && (*(char *)(iVar2 + 0x11) != '\x03')) {
    local_10 = (uint)*(byte *)(iVar2 + 0xc);
    base_frame_process(*(undefined1 *)(iVar2 + 8),*(undefined1 *)(iVar2 + 9),*(undefined1 *)(iVar2 + 10),
                 *(undefined1 *)(iVar2 + 0xb));
  }
  return CONCAT44(param_2,local_10);
}

// FUNC 0x1005152c  key_event_post

undefined8 key_event_post(undefined4 param_1,undefined3 param_2,undefined4 param_3)

{
  int *piVar1;
  undefined4 uStack_14;
  undefined4 uStack_10;
  
  piVar1 = lit_ptr_ram_2000396c_155c;
  uStack_14 = CONCAT13(8,param_2);
  uStack_10 = param_3;
  status_send_7(0x97,(int)&uStack_14 + 3,lit_ptr_ram_2000396c_155c);
  if (*piVar1 != pattern_a5) {
    *piVar1 = pattern_a5;
    piVar1[1] = 0;
    status_send_6(0x97,8,piVar1);
  }
  return CONCAT44(uStack_14,param_1);
}

// FUNC 0x10051564  key_event_post_500ms

void key_event_post_500ms(void)

{
  app_msg_cancel(0x31);
  app_msg_post(0x31,500);
  return;
}

// FUNC 0x10051578  hex_decode

uint hex_decode(uint param_1)

{
  return (param_1 >> 4) * 10 + (param_1 & 0xf) & 0xff;
}

// FUNC 0x10051588  console_command_handler

/* Parses CRLF console commands: '?' queries three bytes, '=' sets six hex digits */

undefined8 console_command_handler(int param_1,int param_2)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  uint uVar5;
  undefined *puVar6;
  byte *pbVar7;
  byte *pbVar8;
  uint uVar9;
  bool bVar10;
  int local_18;
  
  puVar6 = PTR_s_ERROR_10051650;
  if (((*(char *)(param_1 + param_2 + -2) == '\r') && (*(char *)(param_1 + param_2 + -1) == '\n'))
     && (iVar2 = rom_memcmp(param_1,lit_str_at_id,5), puVar6 = PTR_s_ERROR_10051650, iVar2 == 0)) {
    if (*(char *)(param_1 + 5) == '?') {
      key_event_post();
      uVar9 = *(uint *)(lit_ptr_ram_2000396c_1640 + 4);
      uVar3 = hex_decode(uVar9 >> 0x10 & 0xff);
      uVar4 = hex_decode(uVar9 >> 8 & 0xff);
      local_18 = hex_decode(uVar9 & 0xff);
      log_printf(PTR_s__s_02d_02d_02d_10051648,PTRlit_str_id,uVar3,uVar4);
      goto LAB_1005163a;
    }
    if ((*(char *)(param_1 + 5) == '=') && (param_2 == 0xe)) {
      pbVar7 = (byte *)(param_1 + 6);
      cVar1 = '\0';
      pbVar8 = pbVar7;
      do {
        if (9 < *pbVar8 - 0x30) goto LAB_10051636;
        cVar1 = cVar1 + '\x01';
        pbVar8 = pbVar8 + 1;
      } while (cVar1 != '\x06');
      uVar5 = 0;
      uVar9 = 0x10;
      do {
        uVar5 = uVar5 | (((*pbVar7 - 0x30 & 0xff) << 4 | pbVar7[1] - 0x30) & 0xff) << (uVar9 & 0xff)
        ;
        pbVar7 = pbVar7 + 2;
        bVar10 = uVar9 != 0;
        uVar9 = uVar9 - 8;
      } while (bVar10);
      *(uint *)(lit_ptr_ram_2000396c_1640 + 4) = uVar5;
      status_send_6(0x97,8);
      puVar6 = PTRlit_str_ok;
    }
  }
LAB_10051636:
  log_printf(puVar6);
  local_18 = param_1;
LAB_1005163a:
  return CONCAT44(param_2,local_18);
}

// FUNC 0x10051654  key_event_post_100ms

void key_event_post_100ms(void)

{
  int iVar1;
  
  iVar1 = status_send_6(0x96,100,lit_ptr_led_state_block_166c);
  if (iVar1 == 0) {
    log_printf(lit_str_snv_data_tag_write_success);
  }
  return;
}

// FUNC 0x10051674  led_state_reset

/* Clears the LED state block at 0x20003908 */

void led_state_reset(void)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  
  puVar1 = lit_ptr_led_state_block_16d0;
  *(undefined1 *)((int)lit_ptr_led_state_block_16d0 + 9) = 0xff;
  *(undefined1 *)(puVar1 + 3) = 0xff;
  uVar2 = frame_seq_check;
  *(undefined2 *)((int)puVar1 + 0xe) = 0x78;
  *(undefined1 *)((int)puVar1 + 0x12) = 1;
  *puVar1 = uVar2;
  *(undefined1 *)((int)puVar1 + 0x5d) = 0;
  puVar1[1] = 0;
  *(undefined1 *)((int)puVar1 + 10) = 0;
  *(undefined1 *)(puVar1 + 2) = 0;
  *(undefined1 *)((int)puVar1 + 0xb) = 0;
  *(undefined1 *)(puVar1 + 4) = 0;
  *(undefined1 *)((int)puVar1 + 0x11) = 0;
  iVar4 = 0;
  do {
    iVar3 = iVar4 + 1;
    *(undefined1 *)((int)puVar1 + iVar4 + 0x13) = 0;
    iVar4 = iVar3;
  } while (iVar3 != 0xc);
  call_table_19((int)puVar1 + 0x1f,0,0x38);
  iVar4 = 0;
  do {
    iVar3 = iVar4 + 1;
    *(undefined1 *)((int)puVar1 + iVar4 + 0x57) = 0;
    *(undefined1 *)((int)puVar1 + iVar4 + 0x5e) = 0;
    iVar4 = iVar3;
  } while (iVar3 != 6);
  return;
}

// FUNC 0x100516d8  led_frame_send

/* Builds 5A 00 <6 bytes> EE and sends it to UART3 */

void led_frame_send(undefined1 *param_1)

{
  undefined1 *puVar1;
  int iVar2;
  undefined1 local_1c [16];
  
  local_1c[0] = 0x5a;
  local_1c[2] = *param_1;
  iVar2 = 0;
  local_1c[3] = param_1[1];
  local_1c[4] = param_1[2];
  local_1c[1] = 0;
  local_1c[5] = param_1[3];
  local_1c[6] = param_1[4];
  local_1c[7] = param_1[5];
  local_1c[8] = 0xee;
  uart3_write(local_1c,9);
  log_printf(PTR_s_IND_DATA_SEND__10051728);
  do {
    puVar1 = local_1c + iVar2;
    iVar2 = iVar2 + 1;
    log_printf(PTR_s__02x_1005172c,*puVar1);
  } while (iVar2 != 9);
  log_printf(lit_rodata_10058156_1730);
  return;
}

// FUNC 0x10051734  led_nibble_encode_a

/* Odd to even nibble remap */

int led_nibble_encode_a(int param_1)

{
  if (param_1 == 1) {
    param_1 = 0;
  }
  else if (param_1 == 3) {
    param_1 = 2;
  }
  else if (param_1 == 5) {
    param_1 = 4;
  }
  else if (param_1 == 7) {
    param_1 = 6;
  }
  return param_1;
}

// FUNC 0x10051754  led_encode_a_send

/* Applies encoder A to the six LED payload bytes */

undefined8 led_encode_a_send(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int *piVar1;
  byte bVar2;
  int iVar3;
  undefined1 local_19;
  undefined4 uStack_18;
  
  uStack_18 = param_3;
  key_event_post();
  piVar1 = lit_ptr_led_state_block_1850;
  status_send_7(0x96,&local_19,lit_ptr_led_state_block_1850);
  if (*piVar1 != frame_seq_check_2) {
    led_state_reset();
  }
  *lit_ptr_ram_20003808_1858 = *(undefined2 *)((int)piVar1 + 0xe);
  *lit_ptr_ram_20003803_185c = (char)piVar1[4];
  if (*(char *)((int)piVar1 + 0x11) != '\0') {
    *(undefined1 *)((int)piVar1 + 0x11) = 0;
  }
  *(undefined1 *)((int)piVar1 + 0x5d) = 1;
  bVar2 = *lit_ptr_led_payload_1860;
  iVar3 = led_nibble_encode_a(bVar2 >> 4);
  bVar2 = led_nibble_encode_a(bVar2 & 0xf);
  *lit_ptr_led_payload_1860 = bVar2 | (byte)(iVar3 << 4);
  bVar2 = *lit_ptr_ram_20003960;
  iVar3 = led_nibble_encode_a(bVar2 >> 4);
  bVar2 = led_nibble_encode_a(bVar2 & 0xf);
  *lit_ptr_ram_20003960 = bVar2 | (byte)(iVar3 << 4);
  bVar2 = *lit_ptr_ram_20003961;
  iVar3 = led_nibble_encode_a(bVar2 >> 4);
  bVar2 = led_nibble_encode_a(bVar2 & 0xf);
  *lit_ptr_ram_20003961 = bVar2 | (byte)(iVar3 << 4);
  bVar2 = *lit_ptr_ram_20003962;
  iVar3 = led_nibble_encode_a(bVar2 >> 4);
  bVar2 = led_nibble_encode_a(bVar2 & 0xf);
  *lit_ptr_ram_20003962 = bVar2 | (byte)(iVar3 << 4);
  bVar2 = *lit_ptr_ram_20003963;
  iVar3 = led_nibble_encode_a(bVar2 >> 4);
  bVar2 = led_nibble_encode_a(bVar2 & 0xf);
  *lit_ptr_ram_20003963 = bVar2 | (byte)(iVar3 << 4);
  bVar2 = *lit_ptr_ram_20003964;
  iVar3 = led_nibble_encode_a(bVar2 >> 4);
  bVar2 = led_nibble_encode_a(bVar2 & 0xf);
  *lit_ptr_ram_20003964 = bVar2 | (byte)(iVar3 << 4);
  return CONCAT44(param_1,(uint)(*piVar1 + blink_const_fecb4f4d == 0));
}

// FUNC 0x1005187c  led_nibble_encode_b

/* Even to odd nibble encode */

int led_nibble_encode_b(int param_1)

{
  if (param_1 == 0) {
    param_1 = 1;
  }
  else if (param_1 == 2) {
    param_1 = 3;
  }
  else if (param_1 == 4) {
    param_1 = 5;
  }
  else if (param_1 == 6) {
    param_1 = 7;
  }
  return param_1;
}

// FUNC 0x1005189c  led_encode_b_send

/* Applies encoder B to the six LED payload bytes */

void led_encode_b_send(uint param_1,uint param_2,int param_3)

{
  bool bVar1;
  int iVar2;
  byte bVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  char *pcVar7;
  int iVar8;
  byte bVar9;
  uint local_28;
  
  iVar2 = lit_ptr_led_state_block_19e8;
  iVar4 = 0;
  pcVar7 = (char *)(lit_ptr_led_state_block_19e8 + 0x1f);
  do {
    if (*pcVar7 != '\0') {
      bVar1 = false;
      for (uVar5 = 0; (uVar5 & 0xff) < (uint)(byte)pcVar7[1]; uVar5 = uVar5 + 1) {
        if ((byte)pcVar7[uVar5 + 2] == param_1) {
          bVar1 = true;
        }
      }
      if (bVar1) {
        local_28 = 0;
        iVar4 = lit_ptr_led_state_block_19e8 + iVar4 * 0xe;
        break;
      }
    }
    iVar4 = iVar4 + 1;
    pcVar7 = pcVar7 + 0xe;
    if (iVar4 == 4) {
      return;
    }
  } while( true );
LAB_100518f2:
  if (*(byte *)(iVar4 + 0x20) <= local_28) {
    return;
  }
  uVar5 = *(byte *)(iVar4 + local_28 + 0x21) - 1 & 0xff;
  if (uVar5 < 0xc) {
    uVar6 = uVar5 >> 1;
    if ((int)(uVar5 << 0x1f) < 0) {
      if (1 < (*(byte *)(iVar2 + uVar6 + 0x57) & 0xf) - 2) {
        if (((param_2 & 0xfffffffb) == 0) || (param_2 == 6)) {
          bVar9 = *(byte *)(param_3 + uVar6) & 0xf0;
          iVar8 = lit_ptr_led_state_block_19e8 + uVar6;
          *(byte *)(param_3 + uVar6) = bVar9;
          bVar3 = led_nibble_encode_a(*(byte *)(iVar8 + 0x57) & 0xf);
        }
        else {
          if (((param_2 & 0xfffffffb) != 1) && (param_2 != 7)) goto LAB_100519d0;
          iVar8 = lit_ptr_led_state_block_19e8 + uVar6;
          bVar9 = *(byte *)(param_3 + uVar6) & 0xf0;
          *(byte *)(param_3 + uVar6) = bVar9;
          bVar3 = led_nibble_encode_b(*(byte *)(iVar8 + 0x57) & 0xf);
        }
LAB_100519cc:
        *(byte *)(param_3 + uVar6) = bVar9 | bVar3;
      }
    }
    else if (1 < (*(byte *)(iVar2 + uVar6 + 0x57) >> 4) - 2) {
      if (((param_2 & 0xfffffffb) == 0) || (param_2 == 6)) {
        bVar9 = *(byte *)(param_3 + uVar6) & 0xf;
        *(byte *)(param_3 + uVar6) = bVar9;
        iVar8 = led_nibble_encode_a(*(byte *)(iVar2 + uVar6 + 0x57) >> 4);
      }
      else {
        if (((param_2 & 0xfffffffb) != 1) && (param_2 != 7)) goto LAB_100519d0;
        bVar9 = *(byte *)(param_3 + uVar6) & 0xf;
        *(byte *)(param_3 + uVar6) = bVar9;
        iVar8 = led_nibble_encode_b(*(byte *)(iVar2 + uVar6 + 0x57) >> 4);
      }
      bVar3 = (byte)(iVar8 << 4);
      goto LAB_100519cc;
    }
  }
LAB_100519d0:
  local_28 = local_28 + 1 & 0xff;
  goto LAB_100518f2;
}

// FUNC 0x100519ec  blink_search

void blink_search(uint param_1,int param_2,int param_3)

{
  bool bVar1;
  int iVar2;
  byte bVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  byte *pbVar7;
  char *pcVar8;
  uint uVar9;
  byte bVar10;
  
  iVar2 = lit_ptr_led_state_block_1b00;
  iVar5 = 0;
  pcVar8 = (char *)(lit_ptr_led_state_block_1b00 + 0x1f);
  do {
    if (*pcVar8 != '\0') {
      bVar1 = false;
      for (uVar6 = 0; (uVar6 & 0xff) < (uint)(byte)pcVar8[1]; uVar6 = uVar6 + 1) {
        if ((byte)pcVar8[uVar6 + 2] == param_1) {
          bVar1 = true;
        }
      }
      if (bVar1) {
        uVar6 = 0;
        iVar5 = lit_ptr_led_state_block_1b00 + iVar5 * 0xe;
        break;
      }
    }
    iVar5 = iVar5 + 1;
    pcVar8 = pcVar8 + 0xe;
    if (iVar5 == 4) {
      return;
    }
  } while( true );
LAB_10051a42:
  if (*(byte *)(iVar5 + 0x20) <= uVar6) {
    return;
  }
  bVar10 = *(char *)(iVar5 + uVar6 + 0x21) - 1;
  if (bVar10 < 0xc) {
    uVar9 = (uint)(bVar10 >> 1);
    if ((bVar10 & 1) == 0) {
      pbVar7 = (byte *)(iVar2 + uVar9 + 0x57);
      if ((*pbVar7 >> 4) - 2 < 2) {
        if (param_2 == 2) {
          bVar10 = *(byte *)(param_3 + uVar9) & 0xf;
          *(byte *)(param_3 + uVar9) = bVar10;
          iVar4 = led_nibble_encode_a(*pbVar7 >> 4);
        }
        else {
          if (param_2 != 3) goto LAB_10051aee;
          bVar10 = *(byte *)(param_3 + uVar9) & 0xf;
          *(byte *)(param_3 + uVar9) = bVar10;
          iVar4 = led_nibble_encode_b(*pbVar7 >> 4);
        }
        bVar3 = (byte)(iVar4 << 4);
        goto LAB_10051aea;
      }
    }
    else {
      pbVar7 = (byte *)(iVar2 + uVar9 + 0x57);
      if ((*pbVar7 & 0xf) - 2 < 2) {
        if (param_2 == 2) {
          bVar10 = *(byte *)(param_3 + uVar9) & 0xf0;
          *(byte *)(param_3 + uVar9) = bVar10;
          bVar3 = led_nibble_encode_a(*pbVar7 & 0xf);
        }
        else {
          if (param_2 != 3) goto LAB_10051aee;
          bVar10 = *(byte *)(param_3 + uVar9) & 0xf0;
          *(byte *)(param_3 + uVar9) = bVar10;
          bVar3 = led_nibble_encode_b(*pbVar7 & 0xf);
        }
LAB_10051aea:
        *(byte *)(param_3 + uVar9) = bVar10 | bVar3;
      }
    }
  }
LAB_10051aee:
  uVar6 = uVar6 + 1 & 0xff;
  goto LAB_10051a42;
}

// FUNC 0x10051b04  led_update

/* Encodes 6 color bytes and sends the 9-byte UART3 LED frame */

undefined8 led_update(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  undefined4 local_20 [3];
  
  bVar1 = *lit_ptr_led_encode_toggle;
  iVar3 = lit_ptr_led_state_block_1b78 + 0x57;
  *lit_ptr_led_encode_toggle = bVar1 ^ 1;
  local_20[0] = param_1;
  local_20[1] = param_2;
  local_20[2] = param_3;
  rom_memcpy(local_20,iVar3,6);
  if ((bVar1 ^ 1) == 0) {
    iVar3 = 0;
    do {
      bVar1 = *(byte *)((int)local_20 + iVar3);
      iVar2 = led_nibble_encode_a(bVar1 >> 4);
      bVar1 = led_nibble_encode_a(bVar1 & 0xf);
      *(byte *)((int)local_20 + iVar3) = bVar1 | (byte)(iVar2 << 4);
      iVar3 = iVar3 + 1;
    } while (iVar3 != 6);
  }
  else {
    iVar3 = 0;
    do {
      bVar1 = *(byte *)((int)local_20 + iVar3);
      iVar2 = led_nibble_encode_b(bVar1 >> 4);
      bVar1 = led_nibble_encode_b(bVar1 & 0xf);
      *(byte *)((int)local_20 + iVar3) = bVar1 | (byte)(iVar2 << 4);
      iVar3 = iVar3 + 1;
    } while (iVar3 != 6);
  }
  led_frame_send(local_20);
  return CONCAT44(local_20[1],local_20[0]);
}

// FUNC 0x10051b7c  led_anim_finish

/* Sends the encoder A frame, clears the animation flag, cancels the 0x2b tick */

void led_anim_finish(void)

{
  led_encode_a_send();
  *lit_ptr_ram_2000336a_1b90 = 0;
  app_msg_cancel(0x2b);
  return;
}

// FUNC 0x10051b94  blink_set_byte

void blink_set_byte(undefined1 param_1)

{
  *lit_ptr_ram_20000b8f = param_1;
  return;
}

// FUNC 0x10051ba0  blink_start

void blink_start(void)

{
  timer_callback();
  return;
}

// FUNC 0x10051ba8  blink_reg_init

void blink_reg_init(void)

{
  uint *puVar1;
  uint uVar2;
  
  puVar1 = iomux_func_sel_1_3;
  *iomux_func_sel_1_3 = *iomux_func_sel_1_3 & 0xfffffff0;
  *puVar1 = *puVar1 | 8;
  *puVar1 = *puVar1 & 0xffffff0f;
  *puVar1 = *puVar1 | 0x80;
  *puVar1 = mask_clear_bits8_11 & *puVar1;
  *puVar1 = *puVar1 | 0x800;
  *puVar1 = mask_clear_bits12_15 & *puVar1;
  *puVar1 = *puVar1 | 0x8000;
  uVar2 = blink_const_0902;
  puVar1 = iomux_blink_reg;
  *iomux_blink_reg = *iomux_blink_reg & 0xfffff000;
  *puVar1 = *puVar1 | uVar2;
  *blink_ctrl_a = 0xd0;
  *lit_ptr_ram_20003974 = 1;
  return;
}

// FUNC 0x10051c2c  blink_state_init

void blink_state_init(void)

{
  *iomux_blink_reg_2 = blink_const_0602;
  *blink_ctrl_b = *blink_ctrl_b & 0xffffff | 0x12000000;
  *iomux_func_sel_1_4 = blink_const_fff0ffff & *iomux_func_sel_1_4 | 0x80000;
  *iomux_func_sel_2_2 = *iomux_func_sel_2_2 & 0xffffff0f | 0x80;
  *iomux_func_sel_3_2 = *iomux_func_sel_3_2 & 0xffffff0f | 0x80;
  return;
}

// FUNC 0x10051e64  blink_set_u32

undefined4 blink_set_u32(undefined4 param_1)

{
  *lit_ptr_ram_20003978 = param_1;
  return 0;
}

// FUNC 0x10051e70  blink_send

undefined8 blink_send(undefined4 param_1,undefined4 param_2,int param_3,int param_4,int param_5)

{
  undefined2 *puVar1;
  undefined4 uVar2;
  int iVar3;
  undefined2 *puVar4;
  
  if ((param_4 == 0) || (param_5 != 0)) {
    uVar2 = param_1;
    puVar1 = (undefined2 *)call_table_8(0xb00,6,4,(param_4 + 1) * 0x16,param_1,param_2,param_3);
    puVar1[1] = 4;
    *puVar1 = (short)param_1;
    *(char *)(puVar1 + 2) = (char)param_2;
    *(char *)((int)puVar1 + 5) = (char)param_4;
    param_1 = uVar2;
    if (param_3 != 0) {
      rom_memcpy(puVar1 + 3,param_3,0x10);
      param_1 = uVar2;
    }
    iVar3 = param_5 + param_4 * 0x16;
    puVar4 = puVar1;
    for (; param_5 != iVar3; param_5 = param_5 + 0x16) {
      puVar4[0x13] = *(undefined2 *)(param_5 + 0x10);
      puVar4[0x14] = *(undefined2 *)(param_5 + 0x12);
      puVar4[0x15] = *(undefined2 *)(param_5 + 0x14);
      rom_memcpy(puVar4 + 0xb,param_5,0x10);
      puVar4 = puVar4 + 0xb;
    }
    call_table_12(puVar1);
    uVar2 = 0;
  }
  else {
    uVar2 = 0x440;
  }
  return CONCAT44(param_1,uVar2);
}

// FUNC 0x10051eec  blink_send_2

undefined8 blink_send_2(void)

{
  ushort uVar1;
  undefined4 in_stack_00000000;
  
  uVar1 = blink_send();
  return CONCAT44(in_stack_00000000,(uint)uVar1);
}

// FUNC 0x10051f48  blink_dispatch

undefined8 blink_dispatch(int param_1,int param_2)

{
  code *pcVar1;
  int extraout_r1;
  int iVar2;
  int iVar3;
  undefined2 *puVar4;
  int unaff_r7;
  
  iVar3 = *lit_ptr_ram_20003978_2068;
  pcVar1 = (code *)0x1;
  if (iVar3 != 0) {
    if ((uint)(param_2 + blink_const_fffff3fe) < 0x27) {
      iVar2 = blink_const_fffff3fe;
      call_table_16();
      *(char *)(iVar3 + 9) = (char)iVar2;
      *(ushort *)(unaff_r7 + extraout_r1 + -0x2c) = (ushort)*(byte *)(unaff_r7 + 0x15);
      puVar4 = (undefined2 *)(uint)*(byte *)(iVar3 + 0x15);
      pcVar1 = *(code **)(iVar3 + 8);
      if (pcVar1 != (code *)0x0) {
        param_1 = (int)puVar4 + 5;
        pcVar1 = (code *)(*pcVar1)((int)puVar4 << 1,*puVar4,puVar4[1],*(undefined1 *)(puVar4 + 2),
                                   param_1,param_2);
      }
    }
    else {
      pcVar1 = (code *)0x0;
    }
  }
  return CONCAT44(param_1,pcVar1);
}

// FUNC 0x10052166  blink_send_payload

undefined4 blink_send_payload(int param_1,undefined2 param_2,undefined2 param_3,int param_4,int param_5)

{
  undefined1 *puVar1;
  undefined4 uVar2;
  
  if ((param_4 == 0) || (param_5 != 0)) {
    puVar1 = (undefined1 *)call_table_8(0xc10,param_1 << 8 | 7,4,param_4 + 8U & 0xffff,param_4);
    *puVar1 = 0x12;
    *(short *)(puVar1 + 6) = (short)param_4;
    *(undefined2 *)(puVar1 + 2) = param_2;
    *(undefined2 *)(puVar1 + 4) = param_3;
    if (param_5 != 0) {
      rom_memcpy(puVar1 + 8,param_5,param_4);
    }
    call_table_12(puVar1);
    uVar2 = 0;
  }
  else {
    uVar2 = 0x440;
  }
  return uVar2;
}

// FUNC 0x100521b8  blink_send_seq

undefined8 blink_send_seq(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  ushort uVar1;
  short sVar2;
  
  sVar2 = *(short *)(lit_ptr_ram_200039b8 + 4) + 1;
  *(short *)(lit_ptr_ram_200039b8 + 4) = sVar2;
  uVar1 = blink_send_payload(param_1,sVar2,param_2,param_3,param_4,param_2);
  return CONCAT44(param_4,(uint)uVar1);
}

// FUNC 0x1005221c  blink_send_short

undefined4 blink_send_short(int param_1,undefined2 param_2,undefined1 param_3,int param_4,int param_5)

{
  undefined2 *puVar1;
  undefined4 uVar2;
  
  if ((param_4 == 0) || (param_5 != 0)) {
    puVar1 = (undefined2 *)
             call_table_8(blink_const_0c14,param_1 << 8 | 7,4,param_4 + 6U & 0xffff,param_4);
    *puVar1 = param_2;
    puVar1[1] = (short)param_4;
    *(undefined1 *)(puVar1 + 2) = param_3;
    if (param_5 != 0) {
      rom_memcpy((int)puVar1 + 5,param_5,param_4);
    }
    call_table_12(puVar1);
    uVar2 = 0;
  }
  else {
    uVar2 = 0x440;
  }
  return uVar2;
}

// FUNC 0x1005226c  blink_send_2

undefined8 blink_send_2(void)

{
  ushort uVar1;
  undefined4 in_stack_00000000;
  
  uVar1 = blink_send_short();
  return CONCAT44(in_stack_00000000,(uint)uVar1);
}

// FUNC 0x1005227a  blink_dispatch_send

longlong blink_dispatch_send(uint param_1,undefined2 *param_2,undefined4 param_3,uint param_4)

{
  int iVar1;
  
  iVar1 = blink_dispatch(param_4 >> 8,param_1,param_2,param_4,param_1,param_2,param_3);
  if (iVar1 == 1) {
    param_1 = 0;
    blink_send_short(param_4 >> 8,*param_2,1);
  }
  return (ulonglong)param_1 << 0x20;
}

// FUNC 0x100522a0  blink_send_min

undefined4 blink_send_min(int param_1,undefined2 param_2,undefined1 param_3)

{
  undefined2 *puVar1;
  
  puVar1 = (undefined2 *)call_table_8(blink_const_0c16,param_1 << 8 | 7,4);
  *puVar1 = param_2;
  *(undefined1 *)(puVar1 + 1) = param_3;
  call_table_12();
  return 0;
}

// FUNC 0x100522c8  blink_send_3

undefined2 blink_send_3(void)

{
  undefined2 uVar1;
  
  uVar1 = blink_send_min();
  return uVar1;
}

// FUNC 0x100522d2  blink_dispatch_min

undefined4 blink_dispatch_min(undefined4 param_1,undefined2 *param_2,undefined4 param_3,uint param_4)

{
  int iVar1;
  
  iVar1 = blink_dispatch(param_4 >> 8,param_1,param_2);
  if (iVar1 == 1) {
    blink_send_min(param_4 >> 8,*param_2,1);
  }
  return 0;
}

// FUNC 0x100522f4  blink_send_3b

undefined4 blink_send_3b(int param_1,undefined2 param_2,undefined2 param_3,undefined1 param_4)

{
  undefined2 *puVar1;
  
  puVar1 = (undefined2 *)call_table_8(blink_const_0c18,param_1 << 8 | 7,4,6);
  *puVar1 = param_2;
  puVar1[1] = param_3;
  *(undefined1 *)(puVar1 + 2) = param_4;
  call_table_12();
  return 0;
}

// FUNC 0x10052388  blink_dispatch_cb

undefined4 blink_dispatch_cb(undefined4 param_1,uint param_2,char *param_3)

{
  undefined4 uVar1;
  int iVar2;
  int *piVar3;
  code *pcVar4;
  undefined1 local_24 [2];
  undefined2 local_22;
  undefined2 local_20;
  char local_1e;
  
  piVar3 = lit_ptr_ram_20003a4c;
  iVar2 = *lit_ptr_ram_20003a4c;
  if (iVar2 == 0) {
    return 1;
  }
  if (param_2 != blink_const_0e19) {
    if (param_2 <= blink_const_0e19) {
      if (param_2 == blink_const_0e0a) {
        pcVar4 = *(code **)(iVar2 + 0x9c);
        if (pcVar4 == (code *)0x0) {
          return 1;
        }
        goto LAB_1005255a;
      }
      if (blink_const_0e0a < param_2) {
        if (param_2 == blink_const_0e11) {
          if (*(code **)(iVar2 + 0x84) != (code *)0x0) {
            uVar1 = (**(code **)(iVar2 + 0x84))
                              (param_1,*(undefined2 *)param_3,*(undefined2 *)(param_3 + 2),
                               *(undefined2 *)(param_3 + 4));
            return uVar1;
          }
          return 0;
        }
        if (param_2 <= blink_const_0e11) {
          if (param_2 != blink_const_0e0c) {
            if (param_2 != blink_const_0e0f) {
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
        if (param_2 != blink_const_0e15) {
          if (param_2 == blink_const_0e17) goto LAB_10052516;
          if (param_2 != blink_const_0e13) {
            return 0;
          }
          piVar3 = (int *)(iVar2 + 0xac);
          goto LAB_100524ea;
        }
        piVar3 = (int *)(iVar2 + 0xb0);
      }
      else {
        if (param_2 != blink_const_0e06) {
          if (blink_const_0e06 < param_2) {
            piVar3 = (int *)(iVar2 + 0x98);
            if (param_2 == blink_const_0e08) {
              pcVar4 = (code *)*piVar3;
              if (pcVar4 == (code *)0x0) {
                return 0;
              }
              call_table_19(local_24,0,10);
              uVar1 = 8;
              local_24[0] = 4;
              goto LAB_10052602;
            }
            if (param_2 <= blink_const_0e08) {
              pcVar4 = (code *)*piVar3;
              if (pcVar4 == (code *)0x0) {
                return 0;
              }
              call_table_19(local_24,0,10);
              local_24[0] = 3;
              local_1e = param_3[4];
              local_20 = *(undefined2 *)(param_3 + 2);
              goto LAB_10052626;
            }
            pcVar4 = (code *)*piVar3;
            if (pcVar4 == (code *)0x0) {
              return 0;
            }
            call_table_19(local_24,0,10);
            local_24[0] = 7;
            goto LAB_100526dc;
          }
          if (param_2 != blink_const_0e01) {
            if (param_2 != blink_const_0e03) {
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
      call_table_19(local_24,0,10);
      local_24[0] = 0x18;
      local_22._1_1_ = param_3[1];
    }
    else {
      if (param_2 < 0xe31) {
        if (param_2 == blink_const_0e1d) {
          pcVar4 = *(code **)(iVar2 + 0x98);
          if (pcVar4 == (code *)0x0) {
            return 0;
          }
          call_table_19(local_24,0,10);
          uVar1 = 5;
          local_24[0] = 8;
LAB_10052602:
          rom_memcpy(&local_22,param_3,uVar1);
          goto LAB_100526e0;
        }
        if (blink_const_0e1d < param_2) {
          if (param_2 == blink_const_0e2c) {
            if (*(code **)(iVar2 + 0xb4) != (code *)0x0) {
              (**(code **)(iVar2 + 0xb4))
                        (param_1,*(undefined2 *)param_3,*(undefined2 *)(param_3 + 2),
                         *(undefined2 *)(param_3 + 4),*(undefined2 *)(param_3 + 6));
              return 0;
            }
            return 0;
          }
          if (param_2 == blink_const_0e2e) {
            pcVar4 = *(code **)(iVar2 + 200);
            if (pcVar4 == (code *)0x0) {
              return 0;
            }
            goto LAB_1005255a;
          }
          if (param_2 != blink_const_0e29) {
            return 0;
          }
          pcVar4 = *(code **)(iVar2 + 0x98);
          if (pcVar4 == (code *)0x0) {
            return 0;
          }
          call_table_19(local_24,0,10);
          local_24[0] = 0x12;
LAB_10052626:
          local_22 = *(undefined2 *)param_3;
          goto LAB_100526e0;
        }
        if (param_2 != blink_const_0e1b) {
          if (param_2 != blink_const_0e1c) {
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
      if (param_2 == blink_const_0ef1) {
        if (*(code **)(iVar2 + 0xd0) != (code *)0x0) {
          uVar1 = (**(code **)(iVar2 + 0xd0))
                            (param_1,*param_3,*(undefined2 *)(param_3 + 2),param_3 + 4);
          return uVar1;
        }
        return 0;
      }
      if (blink_const_0ef1 < param_2) {
        if (param_2 == blink_const_0ef3) {
          piVar3 = (int *)(iVar2 + 0xd4);
        }
        else {
          if (param_2 < blink_const_0ef3) {
            pcVar4 = *(code **)(iVar2 + 0x88);
            if (pcVar4 == (code *)0x0) {
              return 0;
            }
            goto LAB_1005258e;
          }
          piVar3 = (int *)(iVar2 + 0xd8);
          if (param_2 != blink_const_0ef4) {
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
      if (param_2 != blink_const_0e31) {
        if (param_2 != blink_const_0e3c) {
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
      call_table_19(local_24,0,10);
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

// FUNC 0x100528ec  blink_send_long

undefined4
blink_send_long(int param_1,undefined1 param_2,undefined2 param_3,undefined2 param_4,undefined2 param_5
            ,undefined2 param_6,undefined2 param_7,undefined2 param_8)

{
  undefined1 *puVar1;
  
  puVar1 = (undefined1 *)call_table_8(blink_const_0e0e,param_1 << 8 | 9,4,0xe);
  *puVar1 = 9;
  *(undefined2 *)(puVar1 + 6) = param_5;
  puVar1[1] = param_2;
  *(undefined2 *)(puVar1 + 8) = param_6;
  *(undefined2 *)(puVar1 + 2) = param_3;
  *(undefined2 *)(puVar1 + 10) = param_7;
  *(undefined2 *)(puVar1 + 4) = param_4;
  *(undefined2 *)(puVar1 + 0xc) = param_8;
  call_table_12();
  return 0;
}

// FUNC 0x10052a0c  blink_send_14b

undefined4 blink_send_14b(int param_1,undefined1 param_2,undefined2 param_3,undefined2 param_4)

{
  undefined1 *puVar1;
  
  puVar1 = (undefined1 *)call_table_8(0xe10,param_1 << 8 | 9,4,6);
  *(undefined2 *)(puVar1 + 4) = param_4;
  *(undefined2 *)(puVar1 + 2) = param_3;
  *puVar1 = param_2;
  call_table_12();
  return 0;
}

// FUNC 0x10052a34  blink_send_14b_2

undefined2 blink_send_14b_2(void)

{
  undefined2 uVar1;
  
  uVar1 = blink_send_14b();
  return uVar1;
}

// FUNC 0x10052a78  blink_send_min2

undefined4 blink_send_min2(int param_1,undefined1 param_2,undefined1 param_3)

{
  undefined1 *puVar1;
  
  puVar1 = (undefined1 *)call_table_8(blink_const_0e0d,param_1 << 8 | 9,4,2);
  *puVar1 = param_2;
  puVar1[1] = param_3;
  call_table_12();
  return 0;
}

// FUNC 0x10052aa0  blink_send_min2_2

undefined2 blink_send_min2_2(undefined4 param_1,undefined4 param_2)

{
  undefined2 uVar1;
  
  uVar1 = blink_send_min2(param_1,0,param_2);
  return uVar1;
}

// FUNC 0x10052aae  blink_dispatch_long

undefined4 blink_dispatch_long(undefined4 param_1,undefined4 param_2,undefined4 param_3,uint param_4)

{
  int iVar1;
  
  iVar1 = blink_dispatch_cb(param_4 >> 8,param_1,param_2);
  if (iVar1 == 1) {
    blink_send_min2(param_4 >> 8,0,0x48);
  }
  return 0;
}

// FUNC 0x10052be0  blink_send_10b

undefined4 blink_send_10b(int param_1,int param_2,int param_3)

{
  undefined1 *puVar1;
  undefined4 uVar2;
  
  if ((param_2 == 0) || (param_3 != 0)) {
    puVar1 = (undefined1 *)call_table_8(blink_const_0e0b,param_1 << 8 | 9,4,param_2 + 10U & 0xffff);
    *puVar1 = 0;
    *(short *)(puVar1 + 2) = (short)param_2;
    if (param_3 != 0) {
      rom_memcpy(puVar1 + 4,param_3,param_2);
    }
    call_table_12(puVar1);
    uVar2 = 0;
  }
  else {
    uVar2 = 0x340;
  }
  return uVar2;
}

// FUNC 0x10052c2c  blink_send_10b_2

undefined2 blink_send_10b_2(undefined4 param_1,int param_2,int param_3)

{
  undefined2 uVar1;
  
  if ((param_2 == 0) || (param_3 == 0)) {
    uVar1 = 0x100;
  }
  else {
    uVar1 = blink_send_10b();
  }
  return uVar1;
}

// FUNC 0x10052c44  blink_send_10b_3

undefined4 blink_send_10b_3(int param_1,undefined2 param_2)

{
  undefined1 *puVar1;
  
  puVar1 = (undefined1 *)call_table_8(blink_const_0e0b_2,param_1 << 8 | 9,4,10);
  *(undefined2 *)(puVar1 + 2) = param_2;
  *puVar1 = 1;
  call_table_12();
  return 0;
}

// FUNC 0x10052c6c  blink_send_10b_4

undefined2 blink_send_10b_4(void)

{
  undefined2 uVar1;
  
  uVar1 = blink_send_10b_3();
  return uVar1;
}

// FUNC 0x10052c78  blink_send_10b_5

undefined4
blink_send_10b_5(int param_1,undefined2 param_2,undefined2 param_3,undefined4 param_4,undefined2 param_5
            )

{
  undefined1 *puVar1;
  
  puVar1 = (undefined1 *)call_table_8(blink_const_0e0b_3,param_1 << 8 | 9,4,10,param_4);
  *(undefined2 *)(puVar1 + 2) = param_2;
  *(undefined2 *)(puVar1 + 4) = param_3;
  *(short *)(puVar1 + 6) = (short)param_4;
  *puVar1 = 2;
  *(undefined2 *)(puVar1 + 8) = param_5;
  call_table_12();
  return 0;
}

// FUNC 0x10052cac  blink_send_10b_6

ulonglong blink_send_10b_6(void)

{
  ushort uVar1;
  undefined2 in_stack_00000000;
  
  uVar1 = blink_send_10b_5();
  return (ulonglong)CONCAT24(in_stack_00000000,(uint)uVar1);
}

// FUNC 0x10053204  tx_frame_build

undefined4
tx_frame_build(undefined1 param_1,undefined1 *param_2,undefined4 param_3,undefined4 param_4)

{
  undefined1 *puVar1;
  undefined1 *puVar2;
  
  puVar2 = (undefined1 *)call_table_8(0xda0,8,4,(byte)param_2[0x27] + 0x2c,param_4);
  *puVar2 = 0xa0;
  puVar1 = lit_ptr_ram_200039b8_32b0;
  puVar2[1] = param_1;
  *puVar1 = 0xff;
  puVar2[4] = *param_2;
  puVar2[5] = param_2[1];
  *(undefined2 *)(puVar2 + 6) = *(undefined2 *)(param_2 + 2);
  puVar2[8] = param_2[4];
  puVar2[9] = param_2[5];
  rom_memcpy(puVar2 + 10,param_2 + 6,6);
  puVar2[0x10] = param_2[0xc];
  *(undefined4 *)(puVar2 + 0x14) = *(undefined4 *)(param_2 + 0x10);
  *(undefined4 *)(puVar2 + 0x18) = *(undefined4 *)(param_2 + 0x14);
  puVar2[0x1c] = param_2[0x18];
  puVar2[0x1d] = param_2[0x19];
  puVar2[0x20] = param_2[0x1c];
  puVar2[0x21] = param_2[0x1d];
  puVar2[0x22] = param_2[0x1e];
  *(undefined2 *)(puVar2 + 0x24) = *(undefined2 *)(param_2 + 0x10);
  *(undefined2 *)(puVar2 + 0x26) = *(undefined2 *)(param_2 + 0x14);
  puVar2[0x28] = param_2[0x24];
  puVar2[0x29] = param_2[0x25];
  puVar2[0x2a] = param_2[0x26];
  puVar2[0x2b] = param_2[0x27];
  rom_memcpy(puVar2 + 0x2c,param_2 + 0x28,param_2[0x27]);
  call_table_12(puVar2);
  return 0;
}

// FUNC 0x100533bc  log_set_1

undefined4 log_set_1(undefined4 param_1)

{
  *lit_ptr_ram_20003a4c_33c4 = param_1;
  return 0;
}

// FUNC 0x100533c8  log_set_2

undefined4 log_set_2(undefined4 param_1)

{
  *lit_ptr_ram_20003a40 = param_1;
  return 0;
}

// FUNC 0x100533d4  log_set_3

undefined4 log_set_3(undefined4 param_1)

{
  *lit_ptr_ram_200039b4 = param_1;
  return 0;
}

// FUNC 0x10053454  blink_tx_build

undefined2 blink_tx_build(undefined4 param_1,undefined1 *param_2)

{
  undefined2 uVar1;
  undefined1 local_38;
  undefined1 local_37;
  undefined2 local_36;
  undefined1 local_34;
  undefined1 local_33;
  undefined1 auStack_32 [6];
  undefined1 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined1 local_20;
  undefined1 local_1f;
  
  local_38 = 0;
  local_37 = *param_2;
  local_36 = *(undefined2 *)(param_2 + 2);
  local_34 = param_2[4];
  local_33 = param_2[5];
  rom_memcpy(auStack_32,param_2 + 6);
  local_2c = param_2[0xc];
  local_24 = *(undefined4 *)(param_2 + 0x14);
  local_28 = *(undefined4 *)(param_2 + 0x10);
  local_1f = param_2[0x19];
  local_20 = param_2[0x18];
  uVar1 = tx_frame_build(param_1,&local_38);
  return uVar1;
}

// FUNC 0x100534a4  blink_tx_check

undefined2
blink_tx_check(undefined4 param_1,undefined4 param_2,int param_3,int param_4,ushort param_5,
            short param_6,undefined2 param_7,undefined2 param_8)

{
  undefined2 uVar1;
  
  if ((((blink_const_0c7a < (param_4 - 6U & 0xffff)) || (blink_const_0c7a < (param_3 - 6U & 0xffff))) ||
      (blink_const_0c76 < (ushort)(param_6 - 10))) || (499 < param_5)) {
    uVar1 = 0x340;
  }
  else {
    uVar1 = blink_send_long(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8);
  }
  return uVar1;
}

// FUNC 0x10053544  blink_init_msg

undefined4 blink_init_msg(void)

{
  undefined1 *puVar1;
  
  puVar1 = (undefined1 *)call_table_8(blink_const_0d02,8,4,1);
  *puVar1 = 1;
  call_table_12();
  return 0;
}

// FUNC 0x10053564  blink_init_2

undefined4 blink_init_2(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = lit_ptr_ram_20003980;
  if (param_1 == 0) {
    uVar1 = 0x340;
  }
  else {
    *lit_ptr_ram_20003a44 = *(undefined1 *)(param_1 + 0x28);
    *lit_ptr_ram_20003a50 = 1;
    rom_memcpy(uVar1,param_1,0x2a);
    blink_init_msg();
    uVar1 = 0;
  }
  return uVar1;
}

// FUNC 0x1005359c  blink_init_3

undefined2 blink_init_3(void)

{
  undefined2 uVar1;
  
  uVar1 = blink_init_2();
  return uVar1;
}

// FUNC 0x100535a8  blink_reg_check

void blink_reg_check(void)

{
  if (*lit_ptr_ram_20003a44_35b8 != '\0') {
    blink_state_init();
  }
  return;
}

// FUNC 0x100536a8  status_send

undefined4 status_send(undefined1 param_1,undefined2 param_2,undefined1 param_3)

{
  undefined1 *puVar1;
  
  puVar1 = (undefined1 *)call_table_8(misc_const_0da1,8,4,0x3a);
  puVar1[1] = param_1;
  *(undefined2 *)(puVar1 + 2) = param_2;
  *puVar1 = 0xa4;
  puVar1[4] = param_3;
  call_table_12();
  return 0;
}

// FUNC 0x100536d4  status_send_2

undefined2 status_send_2(undefined4 param_1,undefined4 param_2)

{
  undefined2 uVar1;
  
  uVar1 = status_send(*lit_ptr_ram_200039b8_36e8,param_1,param_2);
  return uVar1;
}

// FUNC 0x10053738  status_send_core

undefined8 status_send_core(undefined4 param_1,undefined1 param_2,int param_3,int param_4)

{
  undefined1 *puVar1;
  undefined4 uVar2;
  
  if ((param_3 == 0) || (param_4 != 0)) {
    uVar2 = param_1;
    puVar1 = (undefined1 *)
             call_table_8(misc_const_0da6,8,4,param_3 + 4U & 0xffff,param_1,param_1,param_3);
    puVar1[1] = param_2;
    *puVar1 = (char)uVar2;
    *(short *)(puVar1 + 2) = (short)param_3;
    if (param_4 != 0) {
      rom_memcpy(puVar1 + 4,param_4,param_3);
    }
    call_table_12(puVar1);
    uVar2 = 0;
  }
  else {
    uVar2 = 0x340;
  }
  return CONCAT44(param_1,uVar2);
}

// FUNC 0x10053788  status_send_3

undefined8 status_send_3(int param_1,int *param_2)

{
  undefined1 uVar1;
  ushort uVar2;
  int iStack_10;
  int *piStack_c;
  
  uVar1 = *lit_ptr_ram_200039b8_37b4;
  iStack_10 = param_1;
  piStack_c = param_2;
  if ((param_1 == 0) || (param_2 == (int *)0x0)) {
    rom_memcpy(&iStack_10,lit_fn_call_table_21_plus_28,8);
    param_1 = 8;
    param_2 = &iStack_10;
  }
  uVar2 = status_send_core(0xa9,uVar1,param_1,param_2);
  return CONCAT44(iStack_10,(uint)uVar2);
}

// FUNC 0x100537bc  status_send_4

undefined8 status_send_4(int param_1,int *param_2)

{
  undefined1 uVar1;
  ushort uVar2;
  int iStack_10;
  int *piStack_c;
  
  uVar1 = *lit_ptr_ram_200039b8_37e8;
  iStack_10 = param_1;
  piStack_c = param_2;
  if ((param_1 == 0) || (param_2 == (int *)0x0)) {
    rom_memcpy(&iStack_10,lit_fn_call_table_21_plus_28_37ec,8);
    param_1 = 8;
    param_2 = &iStack_10;
  }
  uVar2 = status_send_core(0xaa,uVar1,param_1,param_2);
  return CONCAT44(iStack_10,(uint)uVar2);
}

// FUNC 0x100537f0  status_send_5

undefined8
status_send_5(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4,int param_5)

{
  undefined1 *puVar1;
  undefined4 uVar2;
  
  if ((param_4 == 0) || (param_5 != 0)) {
    uVar2 = param_1;
    puVar1 = (undefined1 *)
             call_table_8(misc_const_0d1b,8,4,param_4 + 8U & 0xffff,param_1,param_2,param_3);
    *(undefined2 *)(puVar1 + 4) = 4;
    *puVar1 = 0x1b;
    puVar1[1] = (char)param_2;
    *(short *)(puVar1 + 2) = (short)param_1;
    *(short *)(puVar1 + 6) = (short)param_3;
    param_1 = uVar2;
    if (param_5 != 0) {
      rom_memcpy(puVar1 + 8,param_5,param_4);
      param_1 = uVar2;
    }
    call_table_12(puVar1);
    uVar2 = 0;
  }
  else {
    uVar2 = 0x340;
  }
  return CONCAT44(param_1,uVar2);
}

// FUNC 0x100538e8  post_task_msg

undefined4 post_task_msg(undefined1 param_1,undefined4 param_2)

{
  undefined1 *puVar1;
  undefined4 uVar2;
  
  puVar1 = (undefined1 *)call_table_8(misc_const_0f01_2,4,4,8);
  uVar2 = lit_mask_0000ffff;
  if (puVar1 != (undefined1 *)0x0) {
    *puVar1 = param_1;
    *(undefined4 *)(puVar1 + 4) = param_2;
    call_table_12();
    uVar2 = 0;
  }
  return uVar2;
}

// FUNC 0x10053918  app_msg_post

/* Posts app message id (0xF00 + code + 0x27) with a payload and a delay in ms */

undefined4 app_msg_post(char param_1,undefined4 param_2)

{
  func_0x1000df44((byte)(param_1 + 0x27) + 0xf00,4,param_2);
  return 0;
}

// FUNC 0x10053930  app_msg_cancel

void app_msg_cancel(char param_1)

{
  func_0x1000e050((byte)(param_1 + 0x27) + 0xf00,4);
  return;
}

// FUNC 0x10053944  app_msg_release

void app_msg_release(char param_1)

{
  func_0x1000e0d0((byte)(param_1 + 0x27) + 0xf00,4);
  return;
}

// FUNC 0x10053958  task_queue_add

/* Appends an entry to the 0x20-slot task queue */

undefined4 task_queue_add(int param_1)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  
  piVar1 = lit_ptr_ram_20003a5c;
  iVar3 = *lit_ptr_ram_20003a5c;
  uVar2 = lit_mask_0000ffff_3978;
  if (iVar3 < 0x20) {
    lit_ptr_ram_20003a5c[iVar3 + 1] = param_1;
    *piVar1 = iVar3 + 1;
    uVar2 = 0;
  }
  return uVar2;
}

// FUNC 0x100539ae  status_send_6

undefined4 status_send_6(uint param_1)

{
  undefined4 uVar1;
  
  uVar1 = 7;
  if (param_1 < 0xb1) {
    uVar1 = func_0x1000fe40();
  }
  return uVar1;
}

// FUNC 0x100539c0  status_send_7

undefined4 status_send_7(uint param_1)

{
  undefined4 uVar1;
  
  uVar1 = 7;
  if (param_1 < 0xb1) {
    uVar1 = func_0x1000fd8c();
  }
  return uVar1;
}

// FUNC 0x100539d4  ble_get_mac

/* Returns the 6-byte BLE MAC through a caller buffer */

undefined4 ble_get_mac(void)

{
  int iVar1;
  code *pcVar2;
  char local_20 [20];
  
  if ((((undefined4 *)*lit_ptr_ram_20003ae0 != (undefined4 *)0x0) &&
      (pcVar2 = *(code **)*lit_ptr_ram_20003ae0, pcVar2 != (code *)0x0)) &&
     (iVar1 = (*pcVar2)(), iVar1 == 1)) {
    local_20[8] = 6;
    iVar1 = func_0x1000fd8c(1,local_20 + 8,lit_ptr_ram_2000501e);
    if (iVar1 == 0) {
      return lit_ptr_ram_2000501e;
    }
  }
  syscfg_write_2(0);
  call_table_19(local_20,0,6);
  event_bulk_read(0x16,6,local_20);
  iVar1 = 0;
  do {
    if (local_20[iVar1] != '\0') {
      iVar1 = 0;
      do {
        local_20[iVar1 + 8] = local_20[5 - iVar1];
        iVar1 = iVar1 + 1;
      } while (iVar1 != 6);
      goto LAB_10053a58;
    }
    iVar1 = iVar1 + 1;
  } while (iVar1 != 6);
  event_bulk_read(0x10,6,local_20);
  iVar1 = 0;
  while (local_20[iVar1] == '\0') {
    iVar1 = iVar1 + 1;
    if (iVar1 == 6) {
      local_20[8] = 6;
      func_0x1000fd8c(1,local_20 + 8,lit_ptr_ram_2000501e);
      return lit_ptr_ram_2000501e;
    }
  }
  iVar1 = 0;
  do {
    local_20[iVar1 + 8] = local_20[5 - iVar1];
    iVar1 = iVar1 + 1;
  } while (iVar1 != 6);
LAB_10053a58:
  rom_memcpy(lit_ptr_ram_2000501e);
  return lit_ptr_ram_2000501e;
}

// FUNC 0x10053ae8  status_get

undefined4 status_get(void)

{
  return lit_boot_1000d000;
}

// FUNC 0x10053b6c  status_set

undefined4 status_set(undefined4 param_1)

{
  *lit_ptr_ram_20003b00 = param_1;
  return 0;
}

// FUNC 0x10053b78  status_timeout

void status_timeout(void)

{
  int *piVar1;
  char *pcVar2;
  undefined4 uVar3;
  
  pcVar2 = lit_ptr_ram_20000b90;
  piVar1 = lit_ptr_ram_200192b0;
  if (*lit_ptr_ram_200192b0 != 0) {
    if ((*lit_ptr_ram_20000b90 != '\0') && (-1 < (int)((uint)*(byte *)(*lit_ptr_ram_200192b0 + 0xc) << 0x1f))) {
      (*(code *)*lit_ptr_ram_200192c4)(0x2000);
      uVar3 = 10;
      if (*(char *)(*piVar1 + 2) == '\0') {
        uVar3 = 2000;
      }
      app_msg_post(0xe9,uVar3);
    }
    *pcVar2 = '\0';
  }
  return;
}

// FUNC 0x10053cf8  status_update

void status_update(void)

{
  rom_memcpy(lit_ptr_ram_200182fc + 0x3d4,lit_ptr_ram_2000501e_3d10,6);
  return;
}

// FUNC 0x10053f00  mask_set

void mask_set(int param_1,undefined4 param_2)

{
  *(undefined4 *)((param_1 + lit_boot_10041800) * 4) = param_2;
  call_table_9(10);
  return;
}

// FUNC 0x10053f18  mask_set_bit

void mask_set_bit(int param_1,uint param_2,uint param_3,uint param_4)

{
  uint uVar1;
  
  if (param_3 < 0x20) {
    uVar1 = (1 << (param_3 & 0xff)) - 1;
  }
  else {
    uVar1 = 0xffffffff;
  }
  if ((((param_1 != 0xff) && (param_2 < 0x20)) && (param_3 < 0x21)) && (param_4 <= uVar1)) {
    mask_set(param_1,param_4 << (param_2 & 0xff) |
                         *(uint *)((param_1 + lit_boot_10041800_3f54) * 4) & ~(uVar1 << (param_2 & 0xff)));
  }
  return;
}

// FUNC 0x10053f64  timer_init

void timer_init(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  uint uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  
  if ((code *)*lit_ptr_ram_20003b10 != (code *)0x0) {
    (*(code *)*lit_ptr_ram_20003b10)();
    return;
  }
  call_table_10(0x17,0x12,1,0);
  call_table_10(0x1e,0x11,4,7);
  call_table_10(0x15,0x1a,3,0);
  call_table_10(0x15,10,1);
  uVar3 = *lit_ptr_runtime_image_base;
  if ((uVar3 & 9) != 0) goto LAB_10053ff8;
  if ((uVar3 & 2) == 0) {
    if ((int)(uVar3 << 0x1d) < 0) {
LAB_10053fee:
      uVar5 = 0;
      uVar2 = 1;
    }
    else {
      if ((uVar3 & 0x20) == 0) {
        if (-1 < (int)(uVar3 << 0x1b)) goto LAB_10053ff8;
        call_table_10(0x1d,0xb,1);
        goto LAB_10053fee;
      }
      uVar5 = 1;
      uVar2 = 0xb;
    }
    uVar4 = 1;
    uVar1 = 0x1d;
  }
  else {
    call_table_10(0x1e,1,1);
    uVar5 = 1;
    uVar4 = 2;
    uVar2 = 0x1a;
    uVar1 = 0x1f;
  }
  call_table_10(uVar1,uVar2,uVar4,uVar5);
LAB_10053ff8:
  call_table_9(100);
  call_table_10(0x15,10,1,0);
  do {
  } while (-1 < *syscfg_timer_status);
  return;
}

// FUNC 0x10054020  timer_start

undefined8 timer_start(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  undefined4 uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  
  call_table_10(0x2d,0,1,0,param_1,param_2,param_3);
  call_table_10(0x2d,0,1);
  call_table_9(0x32);
  uVar2 = *blink_timer_val;
  uVar3 = *blink_timer_val;
  uVar5 = *blink_timer_val;
  uVar7 = *blink_timer_val;
  *blink_timer_val = misc_const_a800a80;
  call_table_9(10);
  if (param_1 == 1) {
    mask_set_bit(0,4,3,1);
    uVar4 = 3;
    uVar1 = 0x17;
LAB_10054088:
    call_table_10(0x33,uVar1,4,uVar4);
  }
  else if (param_1 == 2) {
    mask_set_bit(0,4,3);
    uVar4 = 7;
    uVar1 = 0x1b;
    goto LAB_10054088;
  }
  call_table_10(0x2f,0x17,1,0);
  call_table_10(0x2f,0x17,1);
  call_table_9(misc_const_c350);
  call_table_10(0x2f,0x17,1,0);
  uVar6 = *syscfg_timer_val;
  if (param_1 == 1) {
    uVar1 = fmt_int_18(64000,uVar6 >> 10);
    mask_set_bit(6,0x10,8,uVar1);
    mask_set_bit(6,0x18,5,10);
    mask_set_bit(6,0,8,uVar7 & 0xff);
    uVar5 = (uVar5 << 0x13) >> 0x1b;
  }
  else {
    if (param_1 != 2) goto LAB_1005413c;
    mask_set_bit(6,0x10,8,uVar3 >> 0x10 & 0xff);
    mask_set_bit(6,0x18,5,(uVar2 << 3) >> 0x1b);
    uVar1 = fmt_int_18(0x1f400,uVar6 >> 10);
    mask_set_bit(6,0,8,uVar1);
    uVar5 = 10;
  }
  mask_set_bit(6,8,5,uVar5);
LAB_1005413c:
  mask_set_bit(0,4,3);
  return CONCAT44(uVar2,uVar3);
}

// FUNC 0x1005415c  timer_callback

undefined4 timer_callback(int param_1)

{
  byte bVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar2 = 0;
  do {
    if (*(char *)(iVar2 * 2 + lit_rodata_100589b4) == param_1) {
      bVar1 = *(byte *)(lit_rodata_100589b4 + iVar2 * 2 + 1);
      if (bVar1 < 0x10) {
        call_table_10(0x31,0,4,2);
        call_table_10(0x34,0x17,3);
        uVar3 = 7;
      }
      else {
        call_table_10(0x31,0,4,3);
        call_table_10(0x34,0x17,3,6);
        uVar3 = 0xd;
      }
      call_table_10(0x33,1,4,uVar3);
      mask_set_bit(1,0x18,5,bVar1);
      return 1;
    }
    iVar2 = iVar2 + 1;
  } while (iVar2 != 0x20);
  return 0;
}

// FUNC 0x100541d0  timer_update

void timer_update(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  (*(code *)*lit_ptr_ram_2001926c)();
  uVar1 = (*(code *)*lit_ptr_ram_20019270)(0x1c);
  uVar2 = uVar1 >> 0x10 & 0xff;
  uVar3 = uVar1 >> 8 & 0xff;
  if (((uVar2 != 0) || (uVar2 = uVar3, uVar3 != 0)) || (uVar2 = uVar1 & 0xff, (uVar1 & 0xff) != 0))
  {
    call_table_10(0x35,0,8,uVar2);
  }
  return;
}

// FUNC 0x10054214  gpio_init

void gpio_init(void)

{
  uint *puVar1;
  
  call_table_10(2,1,4,8);
  *syscfg_pad_cfg2 = pad_cfg_val_a;
  call_table_9(100);
  call_table_10(0x16,4,1,0);
  call_table_10(0x17,0xe,1,0);
  call_table_10(0x17,0x17,1);
  call_table_10(0x17,0x16,1);
  call_table_10(0x17,0x15,1);
  call_table_10(0x17,0x14,1);
  call_table_10(0x17,0x13,1);
  call_table_10(0x17,0x12,1);
  call_table_10(0x17,0x11,1);
  call_table_10(0x17,0x10,1);
  call_table_10(0x17,0xf,1);
  call_table_10(0x17,0xb,1);
  timer_init();
  call_table_10(0x17,0x15,1,0);
  call_table_10(0x15,0xd,1,0);
  call_table_10(0x16,8,1,0);
  call_table_10(0x3a,0x12,1);
  puVar1 = syscfg_clk_ready;
  do {
  } while ((*syscfg_clk_ready >> 0xe & 1) != 1);
  call_table_10(0x3a,0x12,1,0);
  call_table_10(0x16,8,1,1);
  call_table_10(0x15,0xd,1,1);
  call_table_10(0x30,6,1,1);
  call_table_10(0x30,5,1,0);
  call_table_10(0x17,0x17,1,0);
  call_table_10(0x17,0x11,1,0);
  call_table_10(0x17,0xf,1,0);
  call_table_10(0x31,0x17,1,1);
  call_table_10(0x16,0x1c,1,0);
  call_table_10(0x16,10,1,0);
  call_table_10(0x16,2,1,0);
  call_table_10(0x15,1,2,0);
  call_table_10(0x33,0x15,2);
  call_table_10(0x2d,0x18,1,1);
  call_table_10(0x2d,0,1,1);
  call_table_10(0x2d,2,1,1);
  call_table_10(0x16,5,2,0);
  call_table_10(0x2d,0x19,7,0x28);
  call_table_10(0x2d,0xe,2,3);
  call_table_10(0x2d,0x10,5,0x18);
  call_table_10(0x2d,3,1,0);
  call_table_9(1);
  call_table_10(0x2d,3,1,1);
  call_table_9(1);
  call_table_10(0x2d,3,1,0);
  call_table_9(0x32);
  call_table_10(0x2d,0xe,2,0);
  call_table_10(0x30,0xd,1,0);
  call_table_10(0x2d,5,1,0);
  call_table_9(1);
  call_table_10(0x2d,5,1,1);
  call_table_9(1);
  call_table_10(0x2d,5,1,0);
  call_table_9(1000);
  call_table_10(0x2d,0xf,1,1);
  call_table_10(0x30,0xd,1,1);
  call_table_10(0x2d,0x19,7,0);
  timer_start(1);
  timer_start(2);
  call_table_10(0x31,0x17,1,0);
  call_table_10(0x17,0x17,1,0);
  call_table_10(0x17,0x11,1,0);
  call_table_10(0x17,0xf,1,0);
  call_table_10(0x33,0x16,1,0);
  call_table_10(0x2d,0x18,1,0);
  call_table_10(0x2d,0xf,1,1);
  call_table_10(0x2d,0xe,1,0);
  call_table_10(0x17,0x17,1,0);
  call_table_10(0x17,0x10,1,0);
  call_table_10(0x15,8,1,0);
  call_table_10(0x3a,0xe,1,0);
  call_table_10(0x17,0x15,1,0);
  call_table_10(0x15,0xd,1,0);
  call_table_10(0x16,8,1,0);
  call_table_10(0x3a,0x12,1,1);
  do {
  } while ((*puVar1 >> 0xe & 1) != 1);
  call_table_10(0x3a,0x12,1,0);
  call_table_10(0x16,8,1,1);
  call_table_10(0x15,0xd,1,1);
  call_table_10(0x31,0x17,1,0);
  call_table_10(0x17,0x17,1,0);
  call_table_10(0x17,0xf,1,0);
  call_table_10(0x15,8,1,0);
  call_table_10(0x3a,0xe,1,0);
  call_table_10(0x17,0x15,1,0);
  call_table_10(0x15,0xd,1,0);
  call_table_10(0x16,8,1,0);
  call_table_10(0x3a,0x12,1,1);
  do {
  } while ((*puVar1 >> 0xe & 1) != 1);
  call_table_10(0x3a,0x12,1,0);
  call_table_10(0x16,8,1,1);
  call_table_10(0x15,0xd,1,1);
  call_table_10(0x31,0x17,1,0);
  *syscfg_pad_cfg0 = 0x100;
  call_table_9(100);
  *syscfg_pad_cfg1 = pad_cfg_val_b;
  call_table_9(100);
  *syscfg_pad_cfg3 = pad_cfg_val_c;
  call_table_9(100);
  call_table_10(3,0x16,1,0);
  call_table_10(0x17,0xb,1,1);
  call_table_10(0x16,4,1,0);
  call_table_10(0x15,8,1,0);
  *syscfg_pad_cfg4 = pad_cfg_val_d;
  call_table_9(100);
  call_table_10(1,0xd,6,0x24);
  call_table_10(1,0x17,1,1);
  if ((*lit_ptr_ram_200192b0_4708 == 0) || (*(char *)(*lit_ptr_ram_200192b0_4708 + 0x18) == '\0')) {
    call_table_17();
  }
  log_printf(lit_str_sonata_rf_init_sucess);
  return;
}

// FUNC 0x100549f0  uart_init

undefined4 uart_init(byte param_1)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  
  puVar2 = lit_ptr_ram_20003b1c;
  if (param_1 != 0x26) {
    if (param_1 < 0x27) {
      puVar2 = lit_ptr_ram_20003b28;
      if ((param_1 != 0x14) && (puVar2 = lit_ptr_ram_20003b20, param_1 != 0x24)) {
        return 0;
      }
    }
    else {
      puVar2 = lit_ptr_ram_20003b18;
      if (((param_1 != 0x50) && (puVar2 = lit_ptr_ram_20003b24, param_1 != 200)) &&
         (puVar2 = lit_ptr_ram_20003b14, param_1 != 0x28)) {
        return 0;
      }
    }
  }
  uVar1 = (*(code *)*puVar2)();
  return uVar1;
}

// FUNC 0x10054b14  uart_init_2

void uart_init_2(undefined4 param_1)

{
  int iVar1;
  undefined2 *puVar2;
  undefined2 *puVar3;
  
  puVar3 = (undefined2 *)(lit_ptr_ram_20003b2c + 0xda);
  puVar2 = (undefined2 *)(lit_ptr_ram_20003b2c + 0x12);
  do {
    iVar1 = uart_init(*puVar2);
    if (iVar1 != 0) {
      (**(code **)(iVar1 + 8))(puVar2 + -9,param_1);
    }
    puVar2 = puVar2 + 10;
  } while (puVar2 != puVar3);
  return;
}

// FUNC 0x10054b70  uart_init_3

undefined4 uart_init_3(uint param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  do {
    iVar1 = lit_ptr_ram_20003b2c_4b94 + iVar2 * 0x14;
    if (*(ushort *)(iVar1 + 0x12) == param_1) {
      return *(undefined4 *)(iVar1 + 0xc);
    }
    iVar2 = iVar2 + 1;
  } while (iVar2 != 10);
  return 0;
}

// FUNC 0x10054bdc  uart_init_4

uint uart_init_4(uint param_1)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  
  iVar1 = 0;
  do {
    iVar3 = lit_ptr_ram_20003b2c_4c08 + iVar1 * 0x14;
    if ((uint)*(ushort *)(iVar3 + 0x12) == (param_1 & 0xff)) {
      uVar2 = (uint)*(ushort *)(iVar3 + 0x10);
      goto LAB_10054c00;
    }
    iVar1 = iVar1 + 1;
  } while (iVar1 != 10);
  uVar2 = 0xff;
LAB_10054c00:
  return param_1 & 0xffffff00 | uVar2;
}

// FUNC 0x10054ca8  uart_init_5

void uart_init_5(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined2 local_c;
  undefined2 uStack_a;
  
  _local_c = CONCAT22((short)((uint)param_4 >> 0x10),(short)lit_mask_000001ff);
  status_send_5(0x14,0,0,2,&local_c,param_2,param_3);
  return;
}

// FUNC 0x10054cc8  uart_init_6

void uart_init_6(void)

{
  *lit_ptr_ram_20003b28_4cdc = lit_fn_uart_init_6_plus_49;
  *lit_ptr_ram_20003ae8 = lit_rodata_10058a64;
  return;
}

// FUNC 0x10054d18  uart_init_7

uint uart_init_7(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = 1;
  uVar2 = 0;
  do {
    if ((param_1 >> (uVar2 & 0xff) & 1U) != 0) {
      uVar1 = uVar1 | 3 << (uVar2 * 2 + 1 & 0xff);
    }
    uVar2 = uVar2 + 1;
  } while (uVar2 != 9);
  return uVar1;
}

// FUNC 0x10054d40  uart_init_8

int uart_init_8(int param_1,ushort *param_2,ushort param_3,uint param_4,ushort *param_5)

{
  int iVar1;
  ushort *puVar2;
  undefined4 uVar3;
  undefined4 local_1c [2];
  
  local_1c[0] = uart_init_7(*param_5);
  iVar1 = func_0x1002f20c(param_2,misc_const_180a,local_1c,0x13,0,*(undefined2 *)(param_1 + 0x10),
                          lit_rodata_10058a76,param_4 & 0x1e);
  if (iVar1 == 0) {
    puVar2 = (ushort *)call_table_18(0x20,1);
    *(ushort **)(param_1 + 0xc) = puVar2;
    puVar2[0xc] = *param_2;
    puVar2[0xd] = *param_5;
    uVar3 = sign_extend_16;
    if (-1 < (int)(param_4 << 0x1f)) {
      uVar3 = 0;
    }
    *puVar2 = (ushort)uVar3 | param_3;
    puVar2[1] = *(ushort *)(param_1 + 0x10);
    *(undefined2 *)(param_1 + 0x12) = 0x14;
    gpio_init_2(param_1);
    call_table_20(puVar2 + 2);
    func_0x1000dc44(*(undefined2 *)(param_1 + 0x10),0);
  }
  return iVar1;
}

// FUNC 0x10055030  gpio_init_2

void gpio_init_2(undefined4 *param_1)

{
  int iVar1;
  
  iVar1 = uart_init_3(0x14);
  *param_1 = lit_rodata_10058b20;
  *(undefined2 *)((int)param_1 + 10) = 3;
  param_1[1] = iVar1 + 0x1e;
  *(undefined2 *)(param_1 + 2) = 1;
  return;
}

// FUNC 0x100550d4  gpio_init_3

void gpio_init_3(void)

{
  *lit_ptr_ram_20003b18_50e8 = lit_fn_gpio_init_6_plus_89;
  *lit_ptr_ram_20003aec = lit_rodata_10058b40;
  return;
}

// FUNC 0x100550f4  gpio_init_4

void gpio_init_4(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined1 local_c;
  undefined3 uStack_b;
  
  _local_c = CONCAT31((int3)((uint)param_4 >> 8),3);
  status_send_5(0x50,0,0,1,&local_c,param_2,param_3);
  return;
}

// FUNC 0x10055110  gpio_init_5

undefined4 gpio_init_5(undefined4 param_1)

{
  *lit_ptr_ram_20003bf8 = param_1;
  return 0;
}

// FUNC 0x1005513c  gpio_init_6

int gpio_init_6(int param_1,ushort *param_2,ushort param_3,uint param_4,byte *param_5)

{
  ushort uVar1;
  int iVar2;
  ushort *puVar3;
  undefined4 uVar4;
  undefined1 local_19 [5];
  
  local_19[0] = 0x3f;
  iVar2 = func_0x1002f20c(param_2,*lit_ptr_ram_20000e6c,local_19,6,0,*(undefined2 *)(param_1 + 0x10),
                          lit_rodata_10058b48,param_4 & 0x1e);
  if (iVar2 == 0) {
    puVar3 = (ushort *)call_table_18(10,1);
    uVar1 = *param_2;
    *(ushort **)(param_1 + 0xc) = puVar3;
    puVar3[2] = uVar1;
    puVar3[3] = (ushort)*param_5;
    uVar4 = sign_extend_16_2;
    if (-1 < (int)(param_4 << 0x1f)) {
      uVar4 = 0;
    }
    *puVar3 = (ushort)uVar4 | param_3;
    puVar3[1] = *(ushort *)(param_1 + 0x10);
    *(undefined2 *)(param_1 + 0x12) = 0x50;
    otas_task_init(param_1);
    func_0x1000dc44(*(undefined2 *)(param_1 + 0x10),0);
    uart3_init();
  }
  return iVar2;
}

// FUNC 0x100556b4  uart3_init

void uart3_init(void)

{
  int iVar1;
  undefined1 *puVar2;
  undefined4 uVar3;
  
  iVar1 = lit_ptr_ram_20000e70;
  *lit_ptr_ram_20003bfc = lit_ptr_ram_20000e70;
  puVar2 = lit_ptr_ram_20003c00;
  *lit_ptr_ram_20003c00 = 0;
  *(undefined2 *)(puVar2 + 2) = 0;
  *(undefined4 *)(puVar2 + 4) = 0;
  puVar2[1] = 0;
  uVar3 = (**(code **)(iVar1 + 0x14))();
  log_printf(lit_str_otas_trc_otas_init_ota_s,uVar3);
  return;
}

// FUNC 0x100556e8  otas_task_init

/* OTAS task init; allocates the task block and sets the entry point */

void otas_task_init(undefined4 *param_1)

{
  int iVar1;
  
  log_printf(PTR_s__OTAS_TRC_otas_task_init_1005570c);
  iVar1 = uart_init_3(0x50);
  *param_1 = PTRlit_rodata_10058b88;
  *(undefined2 *)((int)param_1 + 10) = 6;
  param_1[1] = iVar1 + 8;
  *(undefined2 *)(param_1 + 2) = 1;
  return;
}

// FUNC 0x10055714  uart3_init_2

void uart3_init_2(void)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  uint uVar4;
  byte *pbVar5;
  byte local_70 [64];
  undefined1 local_30 [40];
  
  disableIRQinterrupts();
  iVar1 = syscfg_read(1);
  uVar3 = misc_const_2e408c04_2;
  if (iVar1 << 1 < 0) {
    uVar3 = misc_const_6e408c04_2;
  }
  syscfg_write(1,uVar3);
  uVar2 = syscfg_read(1);
  syscfg_write(1,uVar2 & lit_mask_dfffffff_57c4);
  uVar2 = syscfg_read(7);
  syscfg_write(7,uVar2 | 0x800000);
  uVar2 = 0;
  do {
    uVar4 = uVar2;
    if ((uVar4 & 1) == 0) {
      local_30[uVar4] = 0;
    }
    else {
      local_30[uVar4] = 0x10;
    }
    uVar2 = uVar4 + 1;
  } while (uVar4 + 1 != 0x25);
  iVar1 = 0;
  pbVar5 = local_70 + uVar4;
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
    syscfg_write(0x14,local_30[iVar1]);
    iVar1 = iVar1 + 1;
    log_delay_2(10);
  } while (iVar1 != 0x25);
  return;
}

// FUNC 0x100557c8  uart3_init_3

undefined4 uart3_init_3(void)

{
  log_printf(lit_str_ota_rollback);
  log_printf(lit_str_the_feature_is_not_supported);
  return 0xffffffff;
}

// FUNC 0x100557e4  uart3_init_4

undefined4 uart3_init_4(void)

{
  log_printf(lit_str_ota_get_version);
  return lit_str_app_1_0_2_20240319_1000;
}

// FUNC 0x10055a18  image_header_verify

/* Verifies image length and CRC before a jump */

undefined4 image_header_verify(void)

{
  int *piVar1;
  int iVar2;
  undefined *puVar3;
  
  log_printf(lit_str_ota_set_boot);
  piVar1 = lit_ptr_ram_20003cb0;
  uart3_init_9(lit_ptr_ram_20003cb0 + 4,lit_ptr_ram_20003cb0 + 4);
  puVar3 = lit_str_image_size_not_expected;
  if (*piVar1 == piVar1[2] + 0x80) {
    if (piVar1[2] != *(int *)(lit_ptr_ram_20003c30 + 0x50)) {
      log_printf(PTR_s_image_length_compare_fail____d____10055a8c,*(int *)(lit_ptr_ram_20003c30 + 0x50));
      return 0xffffffff;
    }
    puVar3 = PTR_s_image_crc_compare_fail_10055a90;
    if ((*(uint *)(lit_ptr_ram_20003c30 + 0x54) == (uint)*(ushort *)(piVar1 + 4)) &&
       (iVar2 = uart3_init_14(*lit_ptr_ram_20000e6e,lit_ptr_ram_20003c30,(int)*lit_ptr_ram_20003c2d,(int)*lit_ptr_ram_20003c2c),
       puVar3 = lit_str_image_ota_info_save_error, iVar2 == 0)) {
      return 0;
    }
  }
  log_printf(puVar3);
  return 0xffffffff;
}

// FUNC 0x10055aa4  uart3_init_5

uint uart3_init_5(uint param_1,uint param_2)

{
  param_2 = param_2 | 0x100;
  do {
    param_2 = param_2 << 1;
    param_1 = param_1 * 2 + (uint)((param_2 & 0x100) != 0);
    if ((param_1 & 0x10000) != 0) {
      param_1 = param_1 ^ crc_const_1021_2;
    }
  } while ((param_2 & 0x10000) == 0);
  return param_1 & 0xffff;
}

// FUNC 0x10055ad4  uart3_init_6

int uart3_init_6(byte *param_1,byte *param_2,undefined4 *param_3,uint param_4)

{
  byte bVar1;
  byte *pbVar2;
  byte *pbVar3;
  
  for (pbVar3 = param_1; *pbVar3 != 0; pbVar3 = pbVar3 + 1) {
  }
  *param_3 = param_1;
  do {
    do {
      pbVar2 = param_1;
      if (pbVar3 == pbVar2) {
        return -(uint)(*param_2 < 2);
      }
      param_1 = pbVar2 + 1;
    } while ((*pbVar2 != param_4) || (*pbVar2 = 0, pbVar2[1] == param_4));
    param_3[*param_2] = param_1;
    bVar1 = *param_2;
    *param_2 = bVar1 + 1;
  } while ((byte)(bVar1 + 1) < 8);
  return 0;
}

// FUNC 0x10055b20  uart3_init_7

void uart3_init_7(undefined2 *param_1)

{
  *param_1 = 0;
  return;
}

// FUNC 0x10055b26  uart3_init_8

void uart3_init_8(undefined2 *param_1,undefined1 *param_2,int param_3)

{
  undefined2 uVar1;
  undefined1 *puVar2;
  
  puVar2 = param_2 + param_3;
  for (; param_2 < puVar2; param_2 = param_2 + 1) {
    uVar1 = uart3_init_5(*param_1,*param_2);
    *param_1 = uVar1;
  }
  return;
}

// FUNC 0x10055b42  uart3_init_9

void uart3_init_9(undefined2 *param_1,undefined2 *param_2)

{
  undefined2 uVar1;
  undefined4 uVar2;
  
  uVar2 = uart3_init_5(*param_1,0);
  uVar1 = uart3_init_5(uVar2,0);
  *param_1 = uVar1;
  *param_2 = uVar1;
  return;
}

// FUNC 0x10055b5c  uart3_init_10

undefined4 uart3_init_10(void)

{
  undefined4 uVar1;
  
  uVar1 = *lit_sys_nvic_iser_5b6c;
  *lit_sys_nvic_icer = 0xfffffffe;
  return uVar1;
}

// FUNC 0x10055b74  uart3_init_11

void uart3_init_11(uint param_1)

{
  *lit_sys_nvic_iser_5b80 = param_1 & 0xfffffffe;
  return;
}

// FUNC 0x10055b84  bootloader_version_check

/* Parses ASRBOOTLOADER-560X and the version or slip string */

undefined4 bootloader_version_check(undefined1 *param_1)

{
  undefined4 uVar1;
  int iVar2;
  char *pcVar3;
  undefined *puVar4;
  byte *pbVar5;
  byte local_39;
  undefined4 local_38 [9];
  
  local_39 = 0;
  log_printf(lit_str_ota_logic_check_s,lit_boot_10000100_5c4c);
  uVar1 = lit_ptr_ram_20003cc4;
  pbVar5 = lit_boot_10000100_5c4c;
  while (*pbVar5 != 0) {
    if ((0x5e < *pbVar5 - 0x20) || (pbVar5 = pbVar5 + 1, pbVar5 == lit_fn_flash_begin_plus_10)) {
      log_printf(PTR_s_bl_ver_isn_t_str_10055c70);
      return 0xffffffff;
    }
  }
  rom_memcpy(lit_ptr_ram_20003cc4,lit_boot_10000100_5c4c,pbVar5 + ota_copy_len_adj);
  iVar2 = uart3_init_47(uVar1,PTR_s_ASRBOOTLOADER_560X_10055c60,0x12);
  puVar4 = PTR_s_bl_ver_or_slip___error___d_10055c6c;
  if (iVar2 == 0) {
    local_39 = 1;
    iVar2 = uart3_init_6(uVar1,&local_39,local_38,0x2d);
    puVar4 = PTR_s_bl_ver_or_slip___error___d_10055c6c;
    if (iVar2 == 0) {
      if (local_39 < 3) {
        return 0xffffffff;
      }
      pcVar3 = (char *)local_38[local_39 - 1];
      if (*pcVar3 != 'V') {
        return 0xffffffff;
      }
      pcVar3 = pcVar3 + 1;
      puVar4 = PTR_s_bl_slip___error___d_10055c68;
      if (pcVar3 != (char *)0x0) {
        local_39 = 1;
        iVar2 = uart3_init_6(pcVar3,&local_39,local_38,0x2e);
        puVar4 = PTR_s_bl_slip___error___d_10055c68;
        if (iVar2 == 0) {
          iVar2 = uart3_init_49(local_38[0],0,10);
          if (iVar2 < 2) {
            *param_1 = 0;
          }
          else {
            *param_1 = 1;
          }
          log_printf(PTR_s_bl_first_ver__s_10055c64,local_38[0]);
          return 0;
        }
      }
    }
  }
  log_printf(puVar4,local_39);
  return 0xffffffff;
}

// FUNC 0x10055c74  uart3_init_12

void uart3_init_12(int param_1)

{
  int iVar1;
  
  if ((param_1 != 0) && (iVar1 = sys_env_kv_init(0), iVar1 == 0)) {
    log_printf(lit_str_sys_kv_init_ok);
  }
  return;
}

// FUNC 0x10055c94  uart3_init_13

int uart3_init_13(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = 0;
  if (param_2 == 3) {
    iVar1 = -(uint)(*(int *)(param_1 + 0x40) != 0);
  }
  return iVar1;
}

// FUNC 0x10055ca8  uart3_init_14

int uart3_init_14(int param_1,int param_2,undefined4 param_3,int param_4)

{
  uint *puVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  uint uVar6;
  undefined4 uVar7;
  undefined4 local_84 [8];
  undefined1 auStack_64 [32];
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  
  if (param_1 == 0) {
    if (*(int *)(param_2 + 0x40) == 0) {
      uVar5 = 0;
      if (param_4 != 3) {
        uVar5 = 0xffffffff;
      }
      *(undefined4 *)(param_2 + 0x44) = uVar5;
    }
    puVar2 = lit_sys_nvic_icer_5ddc;
    puVar1 = lit_sys_nvic_iser_5dd8;
    *(undefined4 *)(param_2 + 0x48) = 0;
    *(undefined4 *)(param_2 + 0x60) = 0;
    uVar6 = *puVar1;
    *puVar2 = 0xfffffffe;
    local_84[0] = 0x1000;
    iVar3 = log_range_search(5,0x1000,0x80);
    *puVar1 = uVar6 & 0xfffffffe;
    if (iVar3 == 0) {
      uVar6 = *puVar1;
      *puVar2 = 0xfffffffe;
      local_84[0] = 0x1000;
      iVar3 = log_read(5,local_84,param_2,0x80);
      *puVar1 = uVar6 & 0xfffffffe;
      iVar4 = log_table_idx(param_3);
      uVar5 = *(undefined4 *)(iVar4 + 8);
      iVar4 = log_table_idx(param_4);
      uVar7 = *(undefined4 *)(iVar4 + 8);
      iVar4 = log_table_idx(param_4);
      log_printf(lit_str_legacy_ota_info_save_lx_lx_l,uVar5,uVar7,*(undefined4 *)(iVar4 + 0xc),
                 *(undefined4 *)(param_2 + 0x40),*(undefined4 *)(param_2 + 0x44),
                 *(undefined4 *)(param_2 + 0x4c));
    }
  }
  else {
    rom_memcpy(local_84,param_2,0x20);
    rom_memcpy(auStack_64,param_2 + 0x20);
    local_44 = 0;
    local_20 = *(undefined4 *)(param_2 + 0x60);
    local_1c = *(undefined4 *)(param_2 + 100);
    local_28 = *(undefined4 *)(param_2 + 0x58);
    local_24 = *(undefined4 *)(param_2 + 0x5c);
    local_30 = *(undefined4 *)(param_2 + 0x50);
    local_2c = *(undefined4 *)(param_2 + 0x54);
    if (*(int *)(param_2 + 0x40) == 0) {
      local_40 = 0;
      if (param_4 != 3) {
        local_40 = 1;
      }
    }
    else if (*(int *)(param_2 + 0x4c) == 0) {
      local_40 = 3;
    }
    else {
      local_40 = 2;
    }
    iVar3 = log_table_idx(param_3);
    local_3c = *(undefined4 *)(iVar3 + 8);
    iVar3 = log_table_idx(param_4);
    local_38 = *(undefined4 *)(iVar3 + 8);
    iVar3 = log_table_idx(param_4);
    local_34 = *(undefined4 *)(iVar3 + 0xc);
    log_printf(lit_str_new_ota_info_save_lx_lx_lx_l,local_3c,local_38,local_34,local_40);
    iVar3 = uart3_init_15(3,local_84,0x6c);
  }
  return iVar3;
}

// FUNC 0x10055e0c  sys_env_kv_init

/* Registers two callbacks and initializes the SYS ENV and SYS KV areas */

int sys_env_kv_init(int param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  
  *lit_ptr_ram_20003d54 = param_1;
  *lit_ptr_ram_20003cf4 = param_2;
  uVar1 = lit_ptr_ram_20003cf8;
  if (param_1 != 0) {
    uart3_init_34(lit_ptr_ram_20003cf8,2,PTR_LAB_10055de4_1_10055e54);
  }
  if (param_2 != 0) {
    uart3_init_34(uVar1,3,PTR_LAB_10055df8_1_10055e58);
  }
  iVar2 = uart3_init_35(uVar1,PTR_s_SYS_ENV_10055e60,PTR_s_SYS_KV_10055e5c);
  return -(uint)(iVar2 != 0);
}

// FUNC 0x10055e64  uart3_init_15

void uart3_init_15(undefined4 param_1)

{
  undefined4 uVar1;
  undefined1 auStack_1c [20];
  
  uVar1 = uart3_init_41(auStack_1c);
  uart3_init_31(lit_ptr_ram_20003cf8_5e80,param_1,uVar1);
  return;
}

// FUNC 0x10055eb6  uart3_init_16

undefined4 uart3_init_16(undefined4 param_1,undefined1 *param_2)

{
  undefined1 uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int local_58;
  undefined1 auStack_4c [8];
  int local_44;
  uint local_40;
  undefined2 local_3c;
  undefined1 auStack_38 [36];
  
  uart3_init_43(param_1,*(undefined4 *)(param_2 + 0x10),auStack_4c,0x14);
  uVar1 = uart3_init_38(auStack_4c,6);
  *param_2 = uVar1;
  if (local_40 < 0x81) {
    *(uint *)(param_2 + 8) = local_40;
    uVar3 = 0;
    uVar2 = local_40 + 8;
    local_58 = 0;
    do {
      iVar4 = 0x20;
      if (uVar2 <= uVar3 + 0x20) {
        iVar4 = uVar2 - uVar3;
      }
      uart3_init_43(param_1,*(int *)(param_2 + 0x10) + 0xc + uVar3,auStack_38,iVar4);
      local_58 = uart3_init_36(local_58,auStack_38,iVar4);
      uVar3 = uVar3 + iVar4;
    } while (uVar3 < uVar2);
    if (local_58 == local_44) {
      param_2[1] = 1;
      *(undefined2 *)(param_2 + 0xc) = local_3c;
      *(int *)(param_2 + 0x14) = *(int *)(param_2 + 0x10) + 0x14;
      return 0;
    }
  }
  else {
    *(undefined4 *)(param_2 + 8) = 0x80;
    *param_2 = 5;
  }
  param_2[1] = 0;
  return 2;
}

// FUNC 0x10055f3c  uart3_init_17

void uart3_init_17(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int extraout_r1;
  undefined4 uVar2;
  undefined4 uStack_18;
  undefined4 local_14;
  
  uStack_18 = param_3;
  local_14 = param_4;
  call_table_19(&uStack_18,0,8,param_4,param_1,param_2);
  uVar2 = *(undefined4 *)(param_1 + 8);
  fmt_int_19(param_2,uVar2);
  if (extraout_r1 != 0) {
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  iVar1 = uart3_init_44(param_1,param_2,uVar2);
  if (iVar1 == 0) {
    call_table_19(&uStack_18,0xff,8);
    uart3_init_37(&uStack_18,4,1);
    uart3_init_37((int)&uStack_18 + 1,4,1);
    local_14 = lit_tag_fdb0_5fa4;
    uart3_init_45(param_1,param_2,&uStack_18,8,1);
  }
  return;
}

// FUNC 0x10056000  uart3_init_18

uint uart3_init_18(int param_1,int param_2,uint *param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  undefined1 auStack_2c [4];
  int local_28;
  
  uVar3 = *param_3;
  if (uVar3 == 0xffffffff) {
    uVar3 = *(int *)(param_2 + 4) + 8;
  }
  else {
    uVar1 = *(int *)(param_2 + 4) + *(int *)(param_1 + 8);
    if (uVar3 <= uVar1) {
      uVar1 = uVar1 - 8;
      uVar3 = uVar3 + 0x94;
      do {
        uVar2 = uVar3;
        if ((uVar1 <= uVar2) || (uVar1 <= uVar2 + 0x94)) {
          uVar2 = 0xffffffff;
          break;
        }
        uart3_init_43(param_1,uVar2,auStack_2c,0x14);
        uVar3 = uVar2 + 0x94;
      } while (local_28 != lit_tag_kv10_6064);
      if (uVar2 <= (uint)(*(int *)(param_2 + 4) + *(int *)(param_1 + 8))) {
        return uVar2;
      }
    }
    uVar3 = 0xffffffff;
  }
  return uVar3;
}

// FUNC 0x10056068  uart3_init_19

undefined4 uart3_init_19(int param_1,undefined4 param_2,undefined1 *param_3,int param_4)

{
  int iVar1;
  undefined1 uVar2;
  undefined4 uVar3;
  int extraout_r1;
  undefined1 uStack_38;
  undefined1 auStack_37 [3];
  int local_34;
  byte local_30;
  char local_2f;
  int local_20 [3];
  
  call_table_19(&uStack_38,0,8);
  fmt_int_19(param_2,*(undefined4 *)(param_1 + 8));
  if (extraout_r1 != 0) {
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  if (param_3 != (undefined1 *)0x0) {
    uart3_init_43(param_1,param_2,&uStack_38,8);
    iVar1 = lit_tag_fdb0_6140;
    *(undefined4 *)(param_3 + 4) = param_2;
    *(int *)(param_3 + 8) = local_34;
    if (local_34 == iVar1) {
      *param_3 = 1;
      uVar2 = uart3_init_38(&uStack_38,4);
      param_3[1] = uVar2;
      uVar2 = uart3_init_38(auStack_37,4);
      param_3[2] = uVar2;
      if (param_4 != 0) {
        local_20[0] = *(int *)(param_3 + 4) + 8;
        *(undefined4 *)(param_3 + 0xc) = 0;
        *(int *)(param_3 + 0x10) = local_20[0];
        if (param_3[1] == '\x01') {
          *(int *)(param_3 + 0xc) = *(int *)(param_1 + 8) + -8;
        }
        else if (param_3[1] == '\x02') {
          *(int *)(param_3 + 0xc) = *(int *)(param_1 + 8) + -8;
          do {
            uart3_init_16(param_1,&local_30);
            if ((local_2f == '\0') && ((local_30 & 0xfb) != 1)) {
              *(undefined4 *)(param_3 + 0xc) = 0;
              return 2;
            }
            *(int *)(param_3 + 0x10) = *(int *)(param_3 + 0x10) + 0x94;
            *(int *)(param_3 + 0xc) = *(int *)(param_3 + 0xc) + -0x94;
            if (param_3[1] == '\x01') {
              local_20[0] = -1;
            }
            else {
              local_20[0] = uart3_init_18(param_1,param_3,local_20);
            }
          } while (local_20[0] != -1);
        }
      }
      uVar3 = 0;
    }
    else {
      *param_3 = 0;
      uVar3 = 8;
    }
    return uVar3;
  }
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}

// FUNC 0x1005615e  uart3_init_20

undefined4 uart3_init_20(undefined4 param_1,int param_2,undefined1 *param_3)

{
  undefined4 uVar1;
  undefined1 auStack_14 [8];
  
  if (*(char *)(param_2 + 1) == '\x01') {
    uVar1 = uart3_init_39(param_1,*(undefined4 *)(param_2 + 4),auStack_14,4,2,1);
  }
  else {
    uVar1 = 0;
    if (*(char *)(param_2 + 1) == '\x02') {
      if (*(uint *)(param_2 + 0xc) < 0x128) {
        uVar1 = uart3_init_39(param_1,*(undefined4 *)(param_2 + 4),auStack_14,4,3,1);
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

// FUNC 0x100561b6  uart3_init_21

undefined8
uart3_init_21(int param_1,int param_2,uint param_3,undefined4 param_4,undefined4 param_5,
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
      uart3_init_19(param_1,uVar3,param_2,0,param_4,uVar2,uVar4);
      if ((param_3 == 0) || (*(byte *)(param_2 + 1) == param_3)) {
        if (uVar2 != 0) {
          uart3_init_19(param_1,uVar3,param_2,1,param_4,uVar2,uVar4);
        }
        if ((param_6 != (code *)0x0) && (iVar1 = (*param_6)(param_2,param_4,param_5), iVar1 != 0))
        goto LAB_1005621a;
      }
      if (*(int *)(param_2 + 4) == -1) break;
      uVar3 = *(int *)(param_2 + 4) + *(int *)(param_1 + 8);
      if ((*(uint *)(param_1 + 0xc) <= uVar3) || (uVar3 == 0xffffffff)) {
LAB_1005621a:
        return CONCAT44(uVar2,param_4);
      }
    }
  } while( true );
}

// FUNC 0x1005621c  uart3_init_22

int uart3_init_22(int param_1,undefined4 param_2,undefined4 param_3)

{
  int local_28;
  uint local_24;
  int local_20;
  int local_1c;
  undefined4 local_18;
  int *local_14;
  
  local_28 = -1;
  local_14 = &local_28;
  local_24 = 0;
  local_20 = 0;
  local_1c = param_1;
  local_18 = param_3;
  uart3_init_21(param_1,param_2,0,&local_24,&local_20,lit_fn_uart3_init_17_plus_6d,0);
  if (local_20 != 0) {
    uart3_init_21(param_1,param_2,2,&local_1c,0,lit_fn_uart3_init_17_plus_8f,1);
  }
  if ((local_24 != 0) && (local_28 == -1)) {
    if ((local_24 < 2) && (*(char *)(param_1 + 0x28) == '\0')) {
      *(char *)(param_1 + 0x28) = '\x01';
    }
    else {
      uart3_init_21(param_1,param_2,1,&local_1c,0,lit_fn_uart3_init_17_plus_8f,1);
    }
  }
  return local_28;
}

// FUNC 0x100562ac  uart3_init_23

void uart3_init_23(int param_1)

{
  uint local_28;
  undefined1 auStack_24 [24];
  
  local_28 = 0;
  uart3_init_21(param_1,auStack_24,1,&local_28,0,lit_fn_uart3_init_15_plus_43,0);
  if (local_28 < 2) {
    uart3_init_21(param_1,auStack_24,0,param_1,0,lit_fn_uart3_init_30_plus_1,0);
  }
  *(undefined1 *)(param_1 + 0x28) = 0;
  return;
}

// FUNC 0x100562f4  uart3_init_24

void uart3_init_24(int param_1,undefined4 param_2,undefined4 param_3)

{
  bool bVar1;
  int iVar2;
  
  bVar1 = false;
  while( true ) {
    iVar2 = uart3_init_22(param_1,param_2,param_3);
    if (iVar2 != -1) {
      return;
    }
    if (*(char *)(param_1 + 0x28) == '\0') break;
    if (bVar1) goto LAB_10056328;
    uart3_init_23(param_1);
    bVar1 = true;
  }
  if (!bVar1) {
    return;
  }
LAB_10056328:
  *(char *)(param_1 + 0x28) = '\0';
  return;
}

// FUNC 0x1005634e  uart3_init_25

void uart3_init_25(int param_1,int param_2,undefined4 param_3,undefined4 param_4,code *param_5)

{
  int iVar1;
  uint uVar2;
  undefined1 uStack_2c;
  byte local_2b;
  int local_28;
  
  do {
    uVar2 = 0;
    while( true ) {
      iVar1 = uart3_init_19(param_1,uVar2,&uStack_2c,0);
      if (((iVar1 == 0) && (param_5 != (code *)0x0)) && (local_2b - 2 < 2)) {
        *(int *)(param_2 + 0x10) = local_28 + 8;
        do {
          uart3_init_16(param_1,param_2);
          iVar1 = (*param_5)(param_2,param_3,param_4);
          if (iVar1 != 0) {
            return;
          }
          if (local_2b == 1) {
            iVar1 = -1;
          }
          else {
            iVar1 = uart3_init_18(param_1,&uStack_2c,param_2 + 0x10);
          }
          *(int *)(param_2 + 0x10) = iVar1;
        } while (iVar1 != -1);
      }
      if (local_28 == -1) break;
      uVar2 = local_28 + *(int *)(param_1 + 8);
      if ((*(uint *)(param_1 + 0xc) <= uVar2) || (uVar2 == 0xffffffff)) {
        return;
      }
    }
  } while( true );
}

// FUNC 0x100563d0  uart3_init_26

undefined1 uart3_init_26(undefined4 param_1,undefined2 param_2,undefined4 param_3)

{
  undefined2 local_12 [4];
  undefined1 local_9;
  
  local_9 = 0;
  local_12[0] = param_2;
  uart3_init_25(param_1,param_3,local_12,&local_9,lit_fn_uart3_init_15_plus_21);
  return local_9;
}

// FUNC 0x100563fc  uart3_init_27

int uart3_init_27(int param_1,undefined4 param_2,undefined1 *param_3,int param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined1 auStack_34 [4];
  undefined1 auStack_30 [28];
  
  if (param_3 == (undefined1 *)0x0) {
    iVar1 = uart3_init_26(param_1,param_2,auStack_30);
    if (iVar1 == 0) {
      return 5;
    }
    param_3 = auStack_30;
  }
  if (param_4 != 0) {
    iVar1 = uart3_init_39(param_1,*(undefined4 *)(param_3 + 0x10),auStack_34,6,4,1);
  }
  else {
    iVar1 = uart3_init_39(param_1,*(undefined4 *)(param_3 + 0x10),auStack_34,6,3,0);
  }
  *(bool *)(param_1 + 0x58) = param_4 == 0;
  if (iVar1 == 0) {
    iVar3 = (*(uint *)(param_3 + 0x10) & -*(int *)(param_1 + 8)) + 1;
    iVar2 = uart3_init_40(param_1,iVar3,auStack_34,4);
    if (iVar2 == 1) {
      iVar1 = uart3_init_39(param_1,iVar3,auStack_34,4,2,1);
    }
  }
  return iVar1;
}

// FUNC 0x10056486  uart3_init_28

undefined4 uart3_init_28(int param_1,char *param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  undefined4 local_5c;
  undefined1 auStack_50 [4];
  undefined1 auStack_4c [20];
  undefined1 auStack_38 [36];
  
  if (*param_2 == '\x02') {
    uart3_init_27(param_1,0,param_2);
  }
  iVar1 = uart3_init_22(param_1,auStack_4c,0x94);
  local_5c = 7;
  if (iVar1 != -1) {
    if ((*(char *)(param_1 + 0x29) == '\0') ||
       (iVar2 = uart3_init_26(param_1,*(undefined2 *)(param_2 + 0xc),auStack_38), iVar2 == 0)) {
      iVar2 = *(int *)(param_2 + 8);
      uart3_init_20(param_1,auStack_4c,0);
      uart3_init_39(param_1,iVar1,auStack_50,6,1,0);
      uVar3 = iVar2 + 0x10;
      local_5c = 0;
      for (uVar4 = 0; uVar4 < uVar3; uVar4 = uVar4 + iVar2) {
        iVar2 = 0x20;
        if (uVar3 <= uVar4 + 0x20) {
          iVar2 = uVar3 - uVar4;
        }
        uart3_init_43(param_1,*(int *)(param_2 + 0x10) + 4 + uVar4,auStack_38,iVar2);
        local_5c = uart3_init_45(param_1,iVar1 + 4 + uVar4,auStack_38,iVar2,1);
      }
      uart3_init_39(param_1,iVar1,auStack_50,6,2,1);
    }
    else {
      local_5c = 0;
    }
    uart3_init_27(param_1,0,param_2,1);
  }
  return local_5c;
}

// FUNC 0x1005655e  uart3_init_29

bool uart3_init_29(char *param_1,undefined4 param_2)

{
  int iVar1;
  bool bVar2;
  undefined1 auStack_14 [8];
  
  if ((param_1[1] == '\0') || (*param_1 != '\x03')) {
    bVar2 = false;
    if (*param_1 == '\x01') {
      uart3_init_39(param_2,*(undefined4 *)(param_1 + 0x10),auStack_14,6,5,1);
      bVar2 = true;
    }
  }
  else {
    iVar1 = uart3_init_28(param_2,param_1);
    bVar2 = iVar1 != 0;
  }
  return bVar2;
}

// FUNC 0x1005659e  uart3_init_30

undefined4 uart3_init_30(char *param_1,undefined4 param_2)

{
  undefined1 auStack_2c [4];
  byte local_28;
  char local_27;
  int local_18 [2];
  
  if ((*param_1 != '\0') && ((byte)param_1[2] - 2 < 2)) {
    uart3_init_39(param_2,*(int *)(param_1 + 4) + 1,auStack_2c,4,3,1);
    local_18[0] = *(int *)(param_1 + 4) + 8;
    do {
      uart3_init_16(param_2,&local_28);
      if ((local_27 != '\0') && (local_28 - 2 < 2)) {
        uart3_init_28(param_2,&local_28);
      }
      if (param_1[1] == '\x01') {
        local_18[0] = -1;
      }
      else {
        local_18[0] = uart3_init_18(param_2,param_1,local_18);
      }
    } while (local_18[0] != -1);
    uart3_init_17(param_2,*(undefined4 *)(param_1 + 4));
  }
  return 0;
}

// FUNC 0x1005661c  uart3_init_31

int uart3_init_31(int param_1,undefined4 param_2,int *param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  undefined2 local_44;
  char local_2d;
  undefined1 auStack_2c [4];
  undefined4 local_28;
  undefined4 local_24;
  uint local_20;
  undefined2 local_1c;
  
  iVar5 = 8;
  if (*(char *)(param_1 + 0x10) != '\0') {
    if (*(code **)(param_1 + 0x14) != (code *)0x0) {
      (**(code **)(param_1 + 0x14))();
    }
    iVar2 = *param_3;
    uVar6 = param_3[1];
    if (iVar2 == 0) {
      iVar5 = uart3_init_27(param_1,param_2,0,1);
    }
    else {
      iVar3 = param_1 + 0x44;
      iVar1 = uart3_init_24(param_1,iVar3,uVar6 + 0x14);
      iVar5 = 7;
      if (iVar1 != -1) {
        iVar4 = param_1 + 0x2c;
        iVar1 = uart3_init_26(param_1,param_2,iVar4);
        if ((iVar1 == 0) || (iVar5 = uart3_init_27(param_1,param_2,iVar4,0), iVar5 == 0)) {
          local_2d = '\0';
          iVar7 = *(int *)(param_1 + 0x54);
          call_table_19(auStack_2c,0xff,0x14);
          local_28 = lit_tag_kv10_67a0;
          local_44 = (undefined2)param_2;
          local_1c = local_44;
          local_20 = uVar6;
          if (((*(int *)(param_1 + 8) - 8U < uVar6) || (0x80 < uVar6)) ||
             ((iVar7 == -1 && (iVar7 = uart3_init_24(param_1,iVar3,0x94), iVar7 == -1)))) {
            iVar5 = 7;
          }
          else {
            iVar5 = uart3_init_20(param_1,iVar3,&local_2d);
            if (iVar5 == 0) {
              local_24 = uart3_init_36(0,&local_20,8);
              local_24 = uart3_init_36(local_24,iVar2,local_20);
              iVar5 = uart3_init_39(param_1,iVar7,auStack_2c,6,1,0);
              if ((((iVar5 == 0) &&
                   (iVar5 = uart3_init_45(param_1,iVar7 + 4,&local_28,0x10,0), iVar5 == 0)) &&
                  (iVar5 = uart3_init_45(param_1,iVar7 + 0x14,iVar2,local_20,0), iVar5 == 0)) &&
                 ((iVar5 = uart3_init_39(param_1,iVar7,auStack_2c,6,2,1), iVar5 == 0 &&
                  (local_2d != '\0')))) {
                *(undefined1 *)(param_1 + 0x28) = 1;
              }
            }
          }
          if ((iVar1 != 0) && (iVar5 == 0)) {
            iVar5 = uart3_init_27(param_1,param_2,iVar4,1);
          }
        }
        if (*(char *)(param_1 + 0x28) != '\0') {
          uart3_init_23(param_1);
        }
      }
    }
    if (*(code **)(param_1 + 0x18) != (code *)0x0) {
      (**(code **)(param_1 + 0x18))(param_1);
    }
  }
  return iVar5;
}

// FUNC 0x100567a4  uart3_init_32

int uart3_init_32(int param_1)

{
  int iVar1;
  uint uVar2;
  
  if (*(code **)(param_1 + 0x14) != (code *)0x0) {
    (**(code **)(param_1 + 0x14))();
  }
  for (uVar2 = 0; uVar2 < *(uint *)(param_1 + 0xc); uVar2 = uVar2 + *(int *)(param_1 + 8)) {
    iVar1 = uart3_init_17(param_1,uVar2);
    if (iVar1 != 0) goto LAB_100567cc;
  }
  iVar1 = 0;
LAB_100567cc:
  if (*(code **)(param_1 + 0x18) != (code *)0x0) {
    (**(code **)(param_1 + 0x18))(param_1);
  }
  return iVar1;
}

// FUNC 0x100567dc  uart3_init_33

undefined4 uart3_init_33(int param_1)

{
  int iVar1;
  int local_40;
  undefined1 auStack_3c [20];
  undefined1 auStack_28 [28];
  
  *(undefined1 *)(param_1 + 0x29) = 1;
  local_40 = 0;
  uart3_init_21(param_1,auStack_3c,0,&local_40,param_1,PTR_LAB_10056144_1_10056864,0);
  iVar1 = fmt_int_18(*(undefined4 *)(param_1 + 0xc),*(undefined4 *)(param_1 + 8));
  if (iVar1 == local_40) {
    uart3_init_32(param_1);
  }
  if (*(code **)(param_1 + 0x14) != (code *)0x0) {
    (**(code **)(param_1 + 0x14))(param_1);
  }
  uart3_init_21(param_1,auStack_3c,0,param_1,0,PTR_LAB_1005632e_1_10056868,0);
  while( true ) {
    uart3_init_25(param_1,auStack_28,param_1,0,PTR_uart3_init_29_1_1005686c);
    if (*(char *)(param_1 + 0x28) == '\0') break;
    uart3_init_23(param_1);
  }
  *(undefined1 *)(param_1 + 0x29) = 0;
  if (*(code **)(param_1 + 0x18) != (code *)0x0) {
    (**(code **)(param_1 + 0x18))(param_1);
  }
  return 0;
}

// FUNC 0x10056870  uart3_init_34

void uart3_init_34(int param_1,uint param_2)

{
  uint uVar1;
  
  if (param_1 == 0) {
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  if (param_2 < 4) {
    uVar1 = call_table_16(param_2);
    if (*(char *)(param_1 + 0x10) != '\0') {
      do {
                    /* WARNING: Do nothing block with infinite loop */
      } while( true );
    }
    *(undefined4 *)(param_1 + 8) = *(undefined4 *)(uVar1 >> 4);
  }
  return;
}

// FUNC 0x100568a2  uart3_init_35

int uart3_init_35(int param_1)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = uart3_init_46();
  if (iVar1 == 0) {
    *(undefined1 *)(param_1 + 0x28) = 0;
    *(undefined1 *)(param_1 + 0x29) = 0;
    uVar2 = fmt_int_18(*(undefined4 *)(param_1 + 0xc),*(undefined4 *)(param_1 + 8));
    if (uVar2 < 2) {
      do {
                    /* WARNING: Do nothing block with infinite loop */
      } while( true );
    }
    iVar1 = uart3_init_33(param_1);
  }
  uart3_init_42(param_1,iVar1);
  return iVar1;
}

// FUNC 0x100568d8  uart3_init_36

uint uart3_init_36(uint param_1,byte *param_2,int param_3)

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
        param_1 = param_1 ^ crc32_poly_3;
      }
      cVar3 = cVar3 + -1;
      uVar1 = param_1;
    } while (cVar3 != '\0');
  }
  return ~param_1;
}

// FUNC 0x10056910  uart3_init_37

uint uart3_init_37(undefined1 *param_1,undefined4 param_2,uint param_3)

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

// FUNC 0x10056936  uart3_init_38

int uart3_init_38(int param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  
  uVar1 = param_2 - 2U;
  do {
    iVar2 = (param_2 - 2U) - uVar1;
    if (uVar1 == 0xffffffff) break;
    uVar3 = uVar1 & 7;
    uVar4 = uVar1 >> 3;
    uVar1 = uVar1 - 1;
  } while ((0x80 >> uVar3 & (uint)*(byte *)(param_1 + uVar4)) != 0);
  return (param_2 + -1) - iVar2;
}

// FUNC 0x10056960  uart3_init_39

undefined8 uart3_init_39(uint param_1,int param_2,int param_3,uint param_4,uint param_5,byte param_6)

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
  iVar1 = uart3_init_37(param_3,param_4);
  uVar2 = 0;
  if (iVar1 != -1) {
    uVar2 = uart3_init_45(param_1,iVar1 + param_2,param_3 + iVar1,1,uVar3,iVar5,iVar6);
    uVar4 = uVar3;
  }
  return CONCAT44(uVar4,uVar2);
}

// FUNC 0x1005699a  uart3_init_40

void uart3_init_40(undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  if (param_3 == 0) {
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  uart3_init_43();
  uart3_init_38(param_3,param_4);
  return;
}

// FUNC 0x100569b6  uart3_init_41

void uart3_init_41(undefined4 *param_1,undefined4 param_2,undefined4 param_3)

{
  *param_1 = param_2;
  param_1[1] = param_3;
  return;
}

// FUNC 0x100569bc  uart3_init_42

void uart3_init_42(int param_1,int param_2)

{
  char *pcVar1;
  
  pcVar1 = lit_ptr_ram_20003d58;
  if (param_2 == 0) {
    *(undefined1 *)(param_1 + 0x10) = 1;
    if (*pcVar1 == '\0') {
      *pcVar1 = '\x01';
    }
  }
  return;
}

// FUNC 0x10056a4a  uart3_init_43

undefined4 uart3_init_43(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = 2;
  if (*(code **)(param_1 + 0x1c) != (code *)0x0) {
    uVar1 = (**(code **)(param_1 + 0x1c))(param_1);
  }
  return uVar1;
}

// FUNC 0x10056a5c  uart3_init_44

undefined4 uart3_init_44(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = 1;
  if (*(code **)(param_1 + 0x24) != (code *)0x0) {
    uVar1 = (**(code **)(param_1 + 0x24))();
  }
  return uVar1;
}

// FUNC 0x10056a6e  uart3_init_45

undefined4 uart3_init_45(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = 3;
  if (*(code **)(param_1 + 0x20) != (code *)0x0) {
    uVar1 = (**(code **)(param_1 + 0x20))(param_1);
  }
  return uVar1;
}

// FUNC 0x10056a80  uart3_init_46

undefined4 uart3_init_46(int *param_1,int param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  int extraout_r1;
  int iVar3;
  
  iVar1 = lit_fn_uart3_init_42_plus_79;
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
    param_1[8] = lit_fn_uart3_init_42_plus_45;
    param_1[9] = lit_fn_uart3_init_42_plus_19;
    iVar1 = log_table_search(param_3);
    *(char *)(param_1 + 1) = (char)iVar1;
    if (iVar1 == -1) {
      return 4;
    }
    param_1[2] = 0x1000;
    iVar1 = log_table_idx();
    iVar3 = *(int *)(iVar1 + 0xc);
    param_1[3] = iVar3;
    iVar1 = param_1[2];
    fmt_int_19(iVar3,iVar1);
    if (extraout_r1 != 0) {
      do {
                    /* WARNING: Do nothing block with infinite loop */
      } while( true );
    }
    uVar2 = fmt_int_18(iVar3,iVar1);
    if (uVar2 < 2) {
      do {
                    /* WARNING: Do nothing block with infinite loop */
      } while( true );
    }
  }
  return 0;
}

// FUNC 0x10056af4  uart3_init_47

int uart3_init_47(uint *param_1,uint *param_2,uint param_3)

{
  uint *puVar1;
  uint uVar2;
  
  if (param_3 != 0) {
    if ((((((uint)param_1 | (uint)param_2) & 3) == 0) && (3 < param_3)) &&
       (uVar2 = *param_1, uVar2 == *param_2)) {
      param_3 = param_3 - 4;
      if (param_3 == 0) {
        return 0;
      }
      if ((uVar2 + mask_byte_clear & ~uVar2 & mask_byte_spread) != 0) {
        return 0;
      }
      do {
        param_1 = param_1 + 1;
        param_2 = param_2 + 1;
        if ((param_3 < 4) || (uVar2 = *param_1, uVar2 != *param_2)) goto LAB_10056b48;
        param_3 = param_3 - 4;
      } while ((param_3 != 0) && ((uVar2 + mask_byte_clear & ~uVar2 & mask_byte_spread) == 0));
    }
    else {
LAB_10056b48:
      uVar2 = (uint)(byte)*param_2;
      if (uVar2 != (byte)*param_1) {
        return (byte)*param_1 - uVar2;
      }
      if (param_3 - 1 != 0) {
        puVar1 = (uint *)((int)param_2 + (param_3 - 1));
        do {
          if (uVar2 == 0) {
            return 0;
          }
          param_2 = (uint *)((int)param_2 + 1);
          param_1 = (uint *)((int)param_1 + 1);
          uVar2 = (uint)*(byte *)param_1;
          if (uVar2 != *(byte *)param_2) {
            return uVar2 - *(byte *)param_2;
          }
        } while (puVar1 != param_2);
      }
    }
  }
  return 0;
}

// FUNC 0x10056b8c  uart3_init_48

uint uart3_init_48(undefined4 *param_1,byte *param_2,undefined4 *param_3,int param_4,
                 undefined4 param_5)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int extraout_r1;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  byte *pbVar9;
  byte *pbVar10;
  
  pbVar9 = param_2;
  do {
    pbVar10 = pbVar9;
    uVar8 = (uint)*pbVar10;
    iVar2 = uart3_init_50(param_5);
    pbVar9 = pbVar10 + 1;
  } while ((*(byte *)(iVar2 + uVar8 + 1) & 8) != 0);
  if (uVar8 == 0x2d) {
    bVar1 = true;
    pbVar9 = pbVar10 + 2;
    uVar8 = (uint)pbVar10[1];
  }
  else {
    bVar1 = false;
    if (uVar8 == 0x2b) {
      pbVar9 = pbVar10 + 2;
      uVar8 = (uint)pbVar10[1];
    }
  }
  if (param_4 == 0) {
    if (uVar8 != 0x30) {
      iVar2 = 10;
      param_4 = 10;
      goto LAB_10056bd8;
    }
    if ((*pbVar9 & 0xdf) != 0x58) {
      iVar2 = 8;
      param_4 = 8;
      goto LAB_10056bd8;
    }
  }
  else {
    iVar2 = param_4;
    if (param_4 != 0x10) goto LAB_10056bd8;
    if ((uVar8 != 0x30) || ((*pbVar9 & 0xdf) != 0x58)) {
      iVar2 = 0x10;
      goto LAB_10056bd8;
    }
  }
  uVar8 = (uint)pbVar9[1];
  iVar2 = 0x10;
  pbVar9 = pbVar9 + 2;
  param_4 = 0x10;
LAB_10056bd8:
  fmt_int_19(-0x80000000 - (uint)!bVar1,iVar2);
  uVar3 = fmt_int_18(-0x80000000 - (uint)!bVar1,iVar2);
  iVar5 = 0;
  uVar4 = 0;
  do {
    uVar7 = uVar8 - 0x30;
    if (9 < uVar7) {
      if (uVar8 - 0x41 < 0x1a) {
        uVar7 = uVar8 - 0x37;
      }
      else {
        if (0x19 < uVar8 - 0x61) break;
        uVar7 = uVar8 - 0x57;
      }
    }
    if (param_4 <= (int)uVar7) break;
    uVar6 = uVar4;
    if (iVar5 != -1) {
      if ((uVar3 < uVar4) || ((uVar3 == uVar4 && (uVar6 = uVar3, extraout_r1 < (int)uVar7)))) {
        iVar5 = -1;
      }
      else {
        iVar5 = 1;
        uVar6 = uVar7 + iVar2 * uVar4;
      }
    }
    uVar8 = (uint)*pbVar9;
    pbVar9 = pbVar9 + 1;
    uVar4 = uVar6;
  } while( true );
  if (iVar5 == -1) {
    uVar4 = 0x80000000 - !bVar1;
    *param_1 = 0x22;
    if (param_3 == (undefined4 *)0x0) {
      return uVar4;
    }
  }
  else {
    if (bVar1) {
      uVar4 = -uVar4;
    }
    if (param_3 == (undefined4 *)0x0) {
      return uVar4;
    }
    if (iVar5 == 0) goto LAB_10056c46;
  }
  param_2 = pbVar9 + -1;
LAB_10056c46:
  *param_3 = param_2;
  return uVar4;
}

// FUNC 0x10056cd8  uart3_init_49

void uart3_init_49(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  
  iVar1 = *(int *)(*lit_ptr_ram_20005458 + 0x34);
  if (iVar1 == 0) {
    iVar1 = lit_ptr_ram_20000e88;
  }
  uart3_init_48(*lit_ptr_ram_20005458,param_1,param_2,param_3,iVar1);
  return;
}

// FUNC 0x10056d04  uart3_init_50

undefined4 uart3_init_50(int param_1)

{
  return *(undefined4 *)(param_1 + 0xec);
}

// FUNC 0x10056d58  fmt_int_18

void fmt_int_18(undefined4 param_1)

{
                    /* WARNING: Could not recover jumptable at 0x10056d60. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*lit_ptr_ram_20005461)(param_1);
  return;
}

// FUNC 0x10056d68  fmt_int_19

void fmt_int_19(undefined4 param_1)

{
                    /* WARNING: Could not recover jumptable at 0x10056d70. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*lit_ptr_ram_2000556d)(param_1);
  return;
}

// FUNC 0x10056d78  mem_fill

void mem_fill(undefined4 param_1)

{
                    /* WARNING: Could not recover jumptable at 0x10056d80. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*lit_ptr_ram_20005785)(param_1);
  return;
}

// FUNC 0x10056d88  mem_set

void mem_set(undefined4 param_1)

{
                    /* WARNING: Could not recover jumptable at 0x10056d90. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*lit_ptr_ram_20001079)(param_1);
  return;
}

// FUNC 0x10056d98  call_table_1

void call_table_1(undefined4 param_1)

{
                    /* WARNING: Could not recover jumptable at 0x10056da0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*lit_ptr_ram_20002cfd)(param_1);
  return;
}

// FUNC 0x10056da8  call_table_2

void call_table_2(undefined4 param_1)

{
                    /* WARNING: Could not recover jumptable at 0x10056db0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*lit_ptr_ram_20002a85)(param_1);
  return;
}

// FUNC 0x10056dc8  call_table_3

void call_table_3(undefined4 param_1)

{
                    /* WARNING: Could not recover jumptable at 0x10056dd0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*lit_ptr_ram_20002a6d)(param_1);
  return;
}

// FUNC 0x10056dd8  call_table_4

void call_table_4(undefined4 param_1)

{
                    /* WARNING: Could not recover jumptable at 0x10056de0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*lit_ptr_ram_20002a59)(param_1);
  return;
}

// FUNC 0x10056de8  rom_memcpy

/* Indirect jump into the ROM/runtime copy routine; called as (dst, src, len) */

void rom_memcpy(undefined4 param_1)

{
                    /* WARNING: Could not recover jumptable at 0x10056df0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*lit_ptr_ram_2000597d)(param_1);
  return;
}

// FUNC 0x10056df8  call_table_5

void call_table_5(undefined4 param_1)

{
                    /* WARNING: Could not recover jumptable at 0x10056e00. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*lit_ptr_ram_200066dd)(param_1);
  return;
}

// FUNC 0x10056e18  call_table_6

void call_table_6(undefined4 param_1)

{
                    /* WARNING: Could not recover jumptable at 0x10056e20. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*lit_ptr_ram_20005771)(param_1);
  return;
}

// FUNC 0x10056e28  call_table_7

void call_table_7(undefined4 param_1)

{
                    /* WARNING: Could not recover jumptable at 0x10056e30. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*lit_ptr_ram_20002d75)(param_1);
  return;
}

// FUNC 0x10056e38  call_table_8

void call_table_8(undefined4 param_1)

{
                    /* WARNING: Could not recover jumptable at 0x10056e40. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*lit_ptr_ram_20006891)(param_1);
  return;
}

// FUNC 0x10056e48  call_table_9

void call_table_9(undefined4 param_1)

{
                    /* WARNING: Could not recover jumptable at 0x10056e50. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*lit_ptr_ram_200015d9)(param_1);
  return;
}

// FUNC 0x10056e58  call_table_10

void call_table_10(undefined4 param_1)

{
                    /* WARNING: Could not recover jumptable at 0x10056e60. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*lit_ptr_ram_20001635)(param_1);
  return;
}

// FUNC 0x10056e68  call_table_11

void call_table_11(undefined4 param_1)

{
                    /* WARNING: Could not recover jumptable at 0x10056e70. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*lit_ptr_ram_2000161d)(param_1);
  return;
}

// FUNC 0x10056e78  call_table_12

void call_table_12(undefined4 param_1)

{
                    /* WARNING: Could not recover jumptable at 0x10056e80. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*lit_ptr_ram_200068e1)(param_1);
  return;
}

// FUNC 0x10056e88  rom_memcmp

/* Indirect jump into the ROM/runtime compare routine; called as (a, b, len), 0 on match */

void rom_memcmp(undefined4 param_1)

{
                    /* WARNING: Could not recover jumptable at 0x10056e90. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*lit_ptr_ram_2000592d)(param_1);
  return;
}

// FUNC 0x10056e98  call_table_13

void call_table_13(undefined4 param_1)

{
                    /* WARNING: Could not recover jumptable at 0x10056ea0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*lit_ptr_ram_20005575)(param_1);
  return;
}

// FUNC 0x10056ea8  call_table_14

void call_table_14(undefined4 param_1)

{
                    /* WARNING: Could not recover jumptable at 0x10056eb0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*lit_ptr_ram_20006a85)(param_1);
  return;
}

// FUNC 0x10056ed8  call_table_15

void call_table_15(undefined4 param_1)

{
                    /* WARNING: Could not recover jumptable at 0x10056ee0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*lit_ptr_ram_20005741)(param_1);
  return;
}

// FUNC 0x10056ee8  call_table_16

void call_table_16(undefined4 param_1)

{
                    /* WARNING: Could not recover jumptable at 0x10056ef0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*lit_ptr_ram_2000575d)(param_1);
  return;
}

// FUNC 0x10056f08  call_table_17

void call_table_17(undefined4 param_1)

{
                    /* WARNING: Could not recover jumptable at 0x10056f10. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*lit_ptr_ram_200016a5)(param_1);
  return;
}

// FUNC 0x10056f18  call_table_18

void call_table_18(undefined4 param_1)

{
                    /* WARNING: Could not recover jumptable at 0x10056f20. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*lit_ptr_ram_2000653d)(param_1);
  return;
}

// FUNC 0x10056f28  call_table_19

void call_table_19(undefined4 param_1)

{
                    /* WARNING: Could not recover jumptable at 0x10056f30. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*lit_ptr_ram_200057c1)(param_1);
  return;
}

// FUNC 0x10056f38  call_table_20

void call_table_20(undefined4 param_1)

{
                    /* WARNING: Could not recover jumptable at 0x10056f40. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*lit_ptr_ram_20006965)(param_1);
  return;
}

// FUNC 0x10056f48  call_table_21

void call_table_21(undefined4 param_1)

{
                    /* WARNING: Could not recover jumptable at 0x10056f50. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*lit_ptr_ram_20001935)(param_1);
  return;
}

