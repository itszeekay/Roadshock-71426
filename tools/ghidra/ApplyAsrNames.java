// Apply verified names and comments from the ASR5601S analysis.
// Usage: -postScript ApplyAsrNames.java
// @category ASR
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;
import ghidra.program.model.symbol.SourceType;

public class ApplyAsrNames extends GhidraScript {

    private static final Object[][] APP = new Object[][] {
        {0x1004AEFCL, "reset_handler", "Copies init image 0x10059118 -> 0x20000800, then calls system_init and main"},
        {0x1004B008L, "system_init", ""},
        {0x1004B2D0L, "uart_putc_indexed", "Writes one byte to UART0..3 selected by the first argument"},
        {0x1004BF28L, "log_printf", "Formatted log output; used for IND DATA SEND and boot messages"},
        {0x1004C544L, "uart_apply_baud", ""},
        {0x1004C55CL, "uart_baud_divider", "Converts a baud rate to the divisor written to the UART"},
        {0x1004C5A0L, "uart_enable", ""},
        {0x1004C5ACL, "uart_putc", ""},
        {0x1004C5BCL, "uart_set_config", ""},
        {0x1004C5CEL, "uart_nvic_priority", ""},
        {0x1004C5E4L, "uart_irq_enable", ""},
        {0x1004C630L, "uart_init", "uart_init(struct: index, baud, parity, stop)"},
        {0x1004C788L, "uart_driver_init", ""},
        {0x1004C918L, "pinmux_set", "pinmux_set(pin, class); 4-bit field at 0x40110068..0x40110074"},
        {0x1004CBE8L, "pin_config", "Secondary pin configuration select"},
        {0x1004D690L, "mic_pins_config", "Configures P27/P28/P29 for the audio front end"},
        {0x1004E7F0L, "uart1_log_init", "UART1 on P04/P05 at 921600; the J3 log/console port"},
        {0x1004E8A4L, "uart0_base_link_init", "UART0 on P02/P03 at 2400; the base board link"},
        {0x1004E1A0L, "app_msg_dispatch", "App message handler for ids 0x28..0x37 (not wire bytes): 0x28 base frame ready, copies 11 bytes and posts 0x0B; 0x29 key highlight tick; 0x2b LED animation tick; 0x34 all LEDs red; 0x35 all LEDs green flash; 0x36 all LEDs red flash; 0x37 clear key highlight"},
        {0x10053918L, "app_msg_post", "Posts app message id (0xF00 + code + 0x27) with a payload and a delay in ms"},
        {0x10053930L, "app_msg_cancel", ""},
        {0x10053944L, "app_msg_release", ""},
        {0x10053958L, "task_queue_add", "Appends an entry to the 0x20-slot task queue"},
        {0x100539D4L, "ble_get_mac", "Returns the 6-byte BLE MAC through a caller buffer"},
        {0x1004F7E0L, "key_highlight_tick", "Decrements the per-key highlight counters, one 0x26-byte entry each"},
        {0x1004F7BCL, "key_highlight_clear", "Stops the highlight timer and clears the active flag"},
        {0x1004FE40L, "all_leds_flash_green", "Sends 0x55 (green on all LEDs) up to three times, then the stored frame"},
        {0x10051B7CL, "led_anim_finish", "Sends the encoder A frame, clears the animation flag, cancels the 0x2b tick"},
        {0x1004E344L, "ble_legacy_adv_config", "app_ble_config_legacy_advertising: 0x1c-byte legacy advertising parameters"},
        {0x1004F814L, "sum8_checksum", "Low byte of the byte sum, used as the frame checksum"},
        {0x1004FCF8L, "tx_frame_enqueue", "Builds seq/dir/type/flag/payload/sum into a 0x14-entry TX queue with a per-frame timer"},
        {0x1004F0B0L, "led_mask_apply", "Applies a 6-byte LED mask to the 12-nibble payload: each nibble replaces the LED state, 8 leaves it unchanged, then re-sends the resulting bytes"},
        {0x1004E2E0L, "app_ota_start_callback", "Registered OTA start handler; logs the app version and the callback result"},
        {0x1004E640L, "ble_complete_event_handler", "Handles BLE complete events by option id and advances advertising"},
        {0x1004EE2CL, "ble_custom_service_add", "Logs app custom svc add request and registers the custom service"},
        {0x1004C4E8L, "uart_irq_dispatch", "Per-UART interrupt dispatch: drains RX and calls the registered byte callback"},
        {0x1004C4ACL, "irq_dispatch_32", "Scans 32 pending IRQ bits and calls the registered handler for the first one"},
        {0x1004CE00L, "gpio_pin_irq_enable", "Sets the interrupt enable bit for a GPIO pin descriptor: 0..15 on one block, 16..30 on the other"},
        {0x1004CE38L, "gpio_pin_irq_disable", "Clears the interrupt enable bit for a GPIO pin descriptor"},
        {0x1004DC24L, "keypad_irq_enable", "Sets or clears the keypad interrupt enable bit"},
        {0x1004DCECL, "keypad_read_matrix", "Copies the keypad matrix registers into a caller buffer"},
        {0x100511BAL, "backlight_change_handler", "Backlight change state machine; logs BL change 10 and 30 times"},
        {0x10051588L, "console_command_handler", "Parses CRLF console commands: '?' queries three bytes, '=' sets six hex digits"},
        {0x100556E8L, "otas_task_init", "OTAS task init; allocates the task block and sets the entry point"},
        {0x10055A18L, "image_header_verify", "Verifies image length and CRC before a jump"},
        {0x10055B84L, "bootloader_version_check", "Parses ASRBOOTLOADER-560X and the version or slip string"},
        {0x10055E0CL, "sys_env_kv_init", "Registers two callbacks and initializes the SYS ENV and SYS KV areas"},
        {0x1004CB00L, "syscfg_write", "Writes a 32-bit value to a SYSCFG register by index"},
        {0x1004CB10L, "syscfg_read", "Reads a 32-bit SYSCFG register by index"},
        {0x1004CB20L, "reg_field_write", "Writes a bit field: block, shift, width, value"},
        {0x1004CB54L, "reg_field_read", "Reads a bit field: block, shift, width"},
        {0x10056DE8L, "rom_memcpy", "Indirect jump into the ROM/runtime copy routine; called as (dst, src, len)"},
        {0x10056E88L, "rom_memcmp", "Indirect jump into the ROM/runtime compare routine; called as (a, b, len), 0 on match"},
        {0x1004F728L, "uart0_rx_callback", "Feeds received UART0 bytes into the 0x20003481 ring buffer"},
        {0x1004F788L, "uart1_rx_callback", "Feeds received UART1 log bytes into a second ring buffer"},
        {0x1004E888L, "uart3_write", "Writes a buffer to UART3, the display link"},
        {0x1004DD24L, "keypad_irq", "Matrix scan interrupt: compares state and calls the key callback with row, column, pressed"},
        {0x100505B4L, "key_event_handler", "Per-key actions: modes, backlight settings, multi-press work mode, temp all off/restore"},
        {0x10051B04L, "led_update", "Encodes 6 color bytes and sends the 9-byte UART3 LED frame"},
        {0x10051734L, "led_nibble_encode_a", "Odd to even nibble remap"},
        {0x1005187CL, "led_nibble_encode_b", "Even to odd nibble encode"},
        {0x1004F710L, "rx_buffer_toggle", "Flips the receive buffer selector"},
        {0x100516D8L, "led_frame_send", "Builds 5A 00 <6 bytes> EE and sends it to UART3"},
        {0x1004E854L, "uart3_init", "P13/P14, 115200; display link to the panel STM8"},
        {0x10050160L, "led_color_set", "Stores a color nibble for one LED: selector 0..3 -> 1, 2, 5, 7"},
        {0x10051754L, "led_encode_a_send", "Applies encoder A to the six LED payload bytes"},
        {0x1005189CL, "led_encode_b_send", "Applies encoder B to the six LED payload bytes"},
        {0x10051674L, "led_state_reset", "Clears the LED state block at 0x20003908"},
        {0x1004FFE0L, "led_mode_update", "Updates one channel nibble and sends the frame"},
        {0x1004FE88L, "all_leds_set", "Sends 0x11 (red) to all eight LEDs, then posts 0x36 to start the flash loop"},
        {0x1004FDF8L, "all_leds_blink", "Alternates an all-off frame and 0x11 (all red) every 200 ms; global only, no per-channel flash"},
        {0x100501FCL, "mode_query", "Searches the per-channel mode list for a value"},
        {0x100538E8L, "post_task_msg", "Allocates a queue entry and posts message with payload to the task queue"},
        {0x100539D4L, "post_msg_payload", "Allocates a queue entry and posts message with payload to the task queue"},
        {0x1004FD78L, "base_frame_send", "Builds an 11-byte base-link frame: seq, dir, type 0x08, flag, 6 payload bytes, checksum"},
        {0x10050354L, "base_frame_process", "Processes 5 base frame payload bytes into per-channel mode and color values"},
        {0x100519ECL, "led_frame_remap", "Remaps a single nibble to its encoder-encoded byte value"},
        {0x1005147CL, "periodic_ui_update", "100 ms periodic UI update handler (message 0x2D); advances per-channel phase counter and re-emits the LED frame when not in blink mode"},
        {0x1004E9A8L, "led_channel4_send_now", "Per-channel LED frame writer: sends channel 4 payload to UART3 immediately when arg=0"},
        {0x1004E968L, "led_channel3_send_now", "Per-channel LED frame writer: sends channel 3 payload to UART3 immediately when arg=0"},
        {0x100502D4L, "led_channels_flush", "Sends all three channel payloads to UART3 immediately (arg=0 path); net effect is LEDs off only if channel payloads were previously cleared"},
        {0x1004E9F0L, "led_channel0_send_now", "Per-channel LED frame writer: sends channel 0 payload to UART3 immediately when arg=0"},
        {0x1004EA30L, "led_channel1_send_now", "Per-channel LED frame writer: sends channel 1 payload to UART3 immediately when arg=0"},
        {0x1004EA70L, "led_channel2_send_now", "Per-channel LED frame writer: sends channel 2 payload to UART3 immediately when arg=0"},
        {0x1004D190L, "led_channel_payload_send", "Builds 12-nibble payload from channel block and calls led_frame_send via uart3_write"},
        {0x1004D0ECL, "led_channel_schedule_cancel", "Clears bit in channel mask and calls FUN_1004cf6c (led_update path) to schedule the channel"},
        {0x1004D148L, "led_channel_schedule_set", "Sets bit in channel mask to include channel in next update cycle"},
        {0x1004CF6CL, "led_update_core", "Core LED update: formats payload, writes to UART3 via uart3_write (the 5A 00 ... EE frame)"},
        {0x100502ECL, "setting_mode_exit", "Exit setting work mode (message 0x33); cancels periodic update and clears state"},
        {0x1005032CL, "setting_mode_exit_confirm", "Second stage of setting mode exit (message 0x32); confirms and clears remaining state"},
        {0x100512ECL, "key_event_handler_main", "Main key event handler (message 0x33); parses key state and dispatches to per-key handlers"},
        {0x1004D16CL, "led_channel_payload_update", "Updates the channel payload buffer and clears the channel's send bit in the mask"},
        {0x10050448L, "ui_state_reset", "UI state reset (message 0x2E); clears animation state and re-sends LED frame"},
        {0x10050488L, "ui_countdown", "UI countdown handler (message 0x2F); decrements a per-channel countdown and re-emits the LED frame"},
        {0x10050530L, "key_event_dispatch", "Dispatches a key press event to the appropriate per-key handler"},
        {0x100507A0L, "key_log_loop", "Logs key state repeatedly and advances per-channel color cycle"},
        {0x10050EA2L, "key_event_handler_temp_off", "Handles key event type 0x0C (temporary all off); re-arms the blink cycle"},
        {0x10050EC4L, "temp_all_off", "Temporary all-off handler (message 0x2E); saves/restore per-channel LED state"},
        {0x10051294L, "key_event_tick", "Key event tick (calls key_event_handler); 500 ms periodic"},
        {0x1005129EL, "key_event_noop", "Key event handler with no-op (used for unused key positions)"},
        {0x1005152CL, "key_event_post", "Posts a key event message with 500 ms delay"},
        {0x10051564L, "key_event_post_500ms", "Posts one-shot key event (message 0x31) with 500 ms delay"},
        {0x10051578L, "hex_decode", "Converts a hex digit (0-15) to its ASCII code"},
        {0x10051654L, "key_event_post_100ms", "Posts a key event message with 100 ms delay"},
        {0x1004DAE4L, "tim4_configure", "Configures the TIM4 hardware timer for 15 ms ticks"},
        {0x1004DA58L, "tim4_enable", "Enable/disable TIM4 interrupt"},
        {0x1004DA74L, "tim4_status", "Returns the TIM4 status word"},
        {0x1004DA80L, "tim4_count", "Returns the TIM4 counter value"},
        {0x10048188L, "log_state_1", "Log buffer state checker (returns 1 when log buffer has room)"},
        {0x10048194L, "log_state_2", "Log buffer state checker (returns 0 when log buffer is full)"},
        {0x100481a8L, "log_state_3", "Log buffer state checker (returns 0 when log buffer is empty)"},
        {0x100481bcL, "log_state_4", "Log buffer state checker (returns 0 when log buffer is full or empty)"},
        {0x100481e4L, "log_error", "Log buffer error handler; writes error message to log buffer"},
        {0x1004b9e0L, "log_format", "Core printf-style format handler; parses format string and writes to log buffer"},
        {0x1004b338L, "log_format_int", "Integer formatting handler; handles signed integer format specifiers (%d, %i)"},
        {0x1004b638L, "log_format_helper", "Format string parsing helper; validates format specifiers and dispatches to handlers"},
        {0x1004b184L, "log_emit", "Log emit function; converts integer to ASCII and writes to log buffer"},
        {0x1004b02eL, "log_write", "Log write function; writes formatted string to log buffer"},
        {0x10048410L, "fmt_s", "Signed integer formatting; converts signed integer to ASCII"},
        {0x10048b58L, "fmt_int", "Integer formatting; converts integer to ASCII with fractional part"},
        {0x10048f38L, "fmt_int_2", "Integer formatting; converts integer to ASCII with fractional part"},
        {0x10048930L, "fmt_int_3", "Integer formatting; converts integer to ASCII"},
        {0x10048fb4L, "fmt_int_4", "Integer formatting; converts integer to ASCII with fractional part"},
        {0x1004a348L, "fmt_int_5", "Integer formatting; converts integer to ASCII with fractional part"},
        {0x1004a9f0L, "fmt_int_6", "Integer formatting; converts integer to ASCII"},
        {0x1004aa5cL, "fmt_int_7", "Integer formatting; converts integer to ASCII with fractional part"},
        {0x1004aae0L, "fmt_int_8", "Integer formatting; converts integer to ASCII with fractional part"},
        {0x1004ab50L, "fmt_int_9", "Integer formatting; converts integer to ASCII"},
        {0x1004abf8L, "fmt_int_10", "Integer formatting; converts integer to ASCII with fractional part"},
        {0x10049e54L, "fmt_int_11", "Integer formatting; converts integer to ASCII with fractional part"},
        {0x1004960cL, "fmt_int_12", "Integer formatting; converts integer to ASCII with fractional part"},
        {0x1004ad70L, "fmt_int_13", "Integer formatting; validates and formats integer"},
        {0x1004adecL, "fmt_int_14", "Integer comparison; compares two integers and returns result"},
        {0x10048e64L, "fmt_int_15", "Fractional part formatting; formats the fractional component of a number"},
        {0x10048224L, "led_update_fmt", "LED update formatting; formats clock tick and writes to UART3"},
        {0x10048254L, "led_update_format", "LED update main format; validates and formats LED update data"},
        {0x10056d58L, "fmt_int_18", "Format string lookup; finds and validates format string"},
        {0x10056d68L, "fmt_int_19", "Format string lookup; finds and validates format string (alternate)"},
    };

    private static final Object[][] DATA = new Object[][] {
        {0x100573B0L, "pinmux_class_table", "Per-pin default function table used by pinmux_set"},
        {0x10057F01L, "hex_digit_table", "ASCII 0-9A-F used when formatting the BLE name"},
        {0x10059122L, "ble_adv_template", "19 09 Controller8 Wired-xxxxxx"},
        {0x20003908L, "led_state_block", "Per-channel LED state; payload at +0x57"},
        {0x2000395FL, "led_payload", "Six bytes, 12 nibbles, sent to UART3"},
        {0x20003481L, "uart0_rx_ring", "32-byte receive slots for the base link"},
        {0x20003904L, "led_encode_toggle", "Alternates encoder A and B"},
        {0x1004FE38L, "all_leds_blink_phase", "Toggles the all-LED blink between off and red"},
        {0x1004FE80L, "all_leds_flash_phase", "Counts the all-LED green flashes"},
        {0x1004F7D8L, "key_highlight_active", "Set while a key highlight timer is running"},
    };

    private static final Object[][] BOOT = new Object[][] {
        {0x100014C4L, "reset_handler", "Vector table reset entry: calls startup_init, then bootloader_main"},
        {0x100014CEL, "default_handler", "Infinite loop for unused vectors"},
        {0x100014D0L, "startup_init", "Calls the early image check, copies .data, zeroes .bss, calls flash_driver_init and bootloader_main"},
        {0x1000162CL, "boot_early_image_check", "Reads the boot mode strap and a RAM image header; maps and jumps to the app when the CRC matches"},
        {0x10001594L, "boot_clock_init", "Configures the clock and power block at 0x40160024"},
        {0x10001608L, "boot_reason_get", "Returns the boot reason word at 0x20030004"},
        {0x10001680L, "uart_pins_config_alt", "Alternate UART pin setup; not referenced by the boot path"},
        {0x10001688L, "uart_pins_config", "Builds the pin bitmap and programs the UART pin mux"},
        {0x10001738L, "uart_pinmux_select", "Selects the UART pin group from the boot reason and applies it"},
        {0x10001794L, "uart_baud_divider", "Converts a baud rate to the divisor written to the UART"},
        {0x100017CCL, "uart_init", "Configures the bootloader console UART at 115200"},
        {0x100018A8L, "reg_write_wait", "Waits for status bit 0x20, then writes the register"},
        {0x100018B4L, "reg_write_indexed", "Writes a 32-bit register selected by index"},
        {0x100018C4L, "reg_read_indexed", "Reads a 32-bit register selected by index"},
        {0x1000193CL, "flash_driver_init", "Calls the flash controller init in the RAM blob"},
        {0x10000BC4L, "bootloader_main", "Prints the banner and boot reason, reads the boot info, then boots or updates the app"},
        {0x10000B8CL, "bootloader_boot_app", "Reads OTA info from the KV store, applies it if valid, then hands control to the app"},
        {0x10000B70L, "boot_jump_to_app", "Sets VTOR and calls the app reset vector"},
        {0x10000CE4L, "call_app_reset_vector", "Calls the word at app_base + 4"},
        {0x10000B60L, "hardfault_handler", "Prints the hard fault message and loops"},
        {0x10000C6CL, "heap_alloc", "Bump allocator over the heap area"},
        {0x10000C8CL, "boot_delay_us", "Calibrated busy-wait delay"},
        {0x10000CF0L, "format_padded", "Formats a number with padding and prefixes into the output buffer"},
        {0x10000E5AL, "utoa", "Unsigned int to string for the boot printf"},
        {0x10000EEEL, "ulltoa", "Unsigned long long to string for the boot printf"},
        {0x10000FC0L, "vprintf_core", "Format engine behind boot_printf"},
        {0x100014A0L, "boot_printf", "Variadic printf over UART1 at 115200"},
        {0x10000740L, "strcmp", "Word-optimized string compare with a byte tail"},
        {0x10000804L, "aeabi_uidivmod", "Unsigned 32-bit divide and remainder"},
        {0x10000910L, "aeabi_uidiv", "Unsigned 32-bit divide"},
        {0x10000918L, "aeabi_idiv0", "Divide-by-zero helper, returns zero"},
        {0x1000091CL, "aeabi_llsl", "64-bit shift left"},
        {0x10000934L, "aeabi_uldivmod", "Unsigned 64-bit divide and remainder"},
        {0x10000974L, "udivmoddi4", "Core of the 64-bit divide"},
        {0x10000B0CL, "clzdi2", "Count leading zeros in a 64-bit value"},
        {0x10000B24L, "clzsi2", "Count leading zeros in a 32-bit value"},
        {0x10004964L, "memcmp", "Byte compare"},
        {0x100049ACL, "memcpy", "Forward copy"},
        {0x10004A50L, "memmove", "Overlapping copy"},
        {0x10004B08L, "memset", "Byte fill"},
        {0x10000720L, "rom_memcpy", "Veneer into the ROM copy routine"},
        {0x10000730L, "rom_memset", "Veneer into the ROM fill routine"},
        {0x10000120L, "flash_begin", "Re-enables the flash controller after a direct access"},
        {0x10000134L, "flash_end", "Releases the flash controller and clears its state"},
        {0x1000014CL, "flash_status", "Returns the flash busy/ready flag"},
        {0x1000015CL, "flash_exit_powerdown", "Leaves flash deep power-down"},
        {0x10000178L, "delay_loop", "Short calibrated busy loop"},
        {0x10000186L, "flash_wait_ready", "Waits for the flash controller bit 0x20"},
        {0x100001B0L, "flash_wait_ready_long", "Waits for the flash controller bit 0x40 with a longer timeout"},
        {0x100001D4L, "flash_run_command", "Strobes the flash command register"},
        {0x100001E8L, "flash_arm_command", "Arms the flash controller for a command"},
        {0x10000200L, "flash_set_read_mode", "Configures the flash controller for reads"},
        {0x1000023CL, "flash_set_write_mode", "Configures the flash controller for writes"},
        {0x1000035CL, "flash_set_window", "Programs the flash address window and timing"},
        {0x100003B8L, "flash_controller_init", "Initializes the flash controller after reset"},
        {0x100003D8L, "flash_erase_sector", "Erases one flash sector through the controller"},
        {0x10000450L, "flash_program_page", "Programs one flash page, handling unaligned sources"},
        {0x10001944L, "flash_region_get", "Returns the 0x14-byte region descriptor for an index"},
        {0x10001954L, "flash_region_find", "Finds a region index by name, 16 entries maximum"},
        {0x10001980L, "flash_region_erase", "Erases every 4 KB page covering the requested range"},
        {0x100019D0L, "flash_region_write", "Writes a buffer into a named flash region"},
        {0x10001A6CL, "flash_region_read", "Reads a buffer from a named flash region"},
        {0x10001ABCL, "watchdog_config", "Unlocks and configures the watchdog block at 0x40008000"},
        {0x10001B54L, "crc16_ccitt", "CRC-16 CCITT over a buffer, polynomial 0x1021"},
        {0x10001B94L, "boot_info_save", "Writes the boot info record to the KV store and updates the header"},
        {0x10001BB4L, "flash_erase_range", "Erases a range using the largest aligned block size"},
        {0x10001C2CL, "ota_region_clear", "Erases the OTA staging region and clears its flag"},
        {0x10001C70L, "flash_program_bytes", "Programs a byte range with interrupts disabled"},
        {0x10001CE6L, "image_copy", "Copies the staged image into the app region"},
        {0x10001CF8L, "boot_map_exec_region", "Programs the IOMUX exec window for the app base and length"},
        {0x10001D34L, "boot_rollback_update", "Increments the rollback counter, then falls back to the previous image"},
        {0x10001D88L, "ota_image_handler", "Copies or decompresses the staged image and verifies its CRC16"},
        {0x10001F00L, "boot_app_select", "Applies the rollback policy, maps the exec region and jumps to the app"},
        {0x10001F28L, "ota_image_verify", "Checks the OTA tag and CRC16, applies the image, then clears the staging area"},
        {0x10001554L, "crc32", "Bitwise CRC-32 over a buffer, polynomial 0x4C11DB7"},
        {0x10001614L, "image_header_build", "Stores base, size and CRC-32 in the image header descriptor"},
        {0x10002030L, "xz_decompress_mem", "Decompresses an XZ stream from one buffer to another"},
        {0x1000205CL, "crc32_table_init", "Builds the 256-entry CRC-32 table"},
        {0x10002094L, "crc32_update", "Table-driven CRC-32 update"},
        {0x100020C0L, "lzma_len", "LZMA length bittree decode"},
        {0x100021EAL, "dict_repeat", "Repeats bytes from the LZMA dictionary"},
        {0x10002234L, "lzma_main", "LZMA symbol decode loop"},
        {0x10002878L, "xz_dec_lzma2_run", "LZMA2 chunk state machine"},
        {0x10002CF8L, "lzma2_create", "Allocates the LZMA2 dictionary state"},
        {0x10002D3CL, "lzma2_reset", "Resets the dictionary and LZMA properties"},
        {0x10002DA4L, "lzma2_end", "Frees the LZMA2 dictionary state"},
        {0x10002DC0L, "lzma2_get_value", "Returns the first field of the LZMA2 state"},
        {0x10002DD6L, "lzma_props", "Parses the five LZMA property bytes"},
        {0x10002E40L, "xz_dec_crc_update", "Updates the running check value over decoded bytes"},
        {0x10002E6CL, "bcj_fill_temp", "Fills the branch-converter temporary buffer"},
        {0x10002EB2L, "bcj_reset", "Resets the branch-converter state"},
        {0x10002EE8L, "xz_dec_run", "XZ container state machine: headers, blocks and checks"},
        {0x100034A4L, "xz_dec_lzma2_create", "Allocates the XZ decoder state"},
        {0x100034DEL, "xz_dec_lzma2_end", "Frees the XZ decoder state"},
        {0x100034F8L, "xz_decompress_buffer", "Allocates I/O buffers and drives the XZ decoder"},
        {0x10003726L, "xz_block_decode", "Decodes one XZ block header and its compressed data"},
        {0x10003874L, "xz_block_decode_hdr", "Parses the XZ block header fields"},
        {0x100039ACL, "xz_block_decode_loop", "Main decode loop for XZ compressed data"},
        {0x10003B4CL, "xz_container_decode", "Decodes the XZ container format: stream headers and blocks"},
        {0x10003C3CL, "xz_container_dispatch", "Dispatches on the XZ block type for header or data blocks"},
        {0x10003DC8L, "xz_block_decode_done", "Finalizes an XZ block after decoding"},
        {0x10003E10L, "xz_stream_decode_done", "Finalizes an XZ stream after all blocks"},
        {0x10003E66L, "xz_decode_finish", "Checks completion and returns the result code"},
        {0x10004078L, "kv_scan_entries", "Scans all KV sectors for valid entries"},
        {0x100040B0L, "kv_recover", "Rebuilds the KV index from the sector contents"},
        {0x10004144L, "kv_set_callback", "Stores or returns the read, write and erase callbacks"},
        {0x10004178L, "kv_mount", "Mounts the KV store, recovering it when needed"},
        {0x1000421EL, "xz_hdr_validate", "Validates an XZ header CRC"},
        {0x10004230L, "xz_hdr_crc_update", "Updates the header CRC over parsed bytes"},
        {0x10004242L, "xz_block_len_update", "Updates the block length CRC"},
        {0x10004254L, "xz_header_parse", "Parses the XZ stream header: magic, blocks, streams"},
        {0x100042C0L, "xz_crc32_ccitt_update", "CCITT CRC-32 update over decoded bytes"},
        {0x100042F4L, "xz_crc32_ccitt_init", "Initializes the CCITT CRC-32 context"},
        {0x10004318L, "xz_block_data_done", "Marks an XZ data block as complete"},
        {0x10004346L, "xz_stream_done", "Marks the final XZ stream as complete"},
        {0x10003644L, "kv_store_init", "Registers the SYS ENV and SYS KV callbacks and mounts the store"},
        {0x1000369CL, "kv_read", "Reads a KV record by id into a caller buffer"},
        {0x100036C4L, "kv_write", "Writes a KV record by id, magic KV10"},
        {0x100036E4L, "kv_delete", "Deletes a KV record by id"},
        {0x10003EC0L, "kv_erase_entry", "Erases one KV entry"},
        {0x10004078L, "kv_scan_entries", "Scans all KV sectors for valid entries"},
        {0x100040B0L, "kv_recover", "Rebuilds the KV index from the sector contents"},
        {0x10004144L, "kv_set_callback", "Stores or returns the read, write and erase callbacks"},
        {0x10004178L, "kv_mount", "Mounts the KV store, recovering it when needed"},
        {0x100043A4L, "kv_mark_ready", "Marks the KV store as initialized"},
        {0x10004E54L, "null_callback_1", "Empty callback used by the libc stubs"},
        {0x10004E58L, "null_callback_2", "Empty callback used by the libc stubs"},
        {0x10004E60L, "flash_program_page_veneer", "Veneer to flash_program_page at 0x10000450"},
        {0x10004E70L, "flash_controller_init_veneer", "Veneer to flash_controller_init at 0x100003B8"},
        {0x10004E80L, "flash_erase_sector_veneer", "Veneer to flash_erase_sector at 0x100003D8"},
        {0x10004E90L, "flash_exit_powerdown_veneer", "Veneer to flash_exit_powerdown at 0x1000015C"},
        {0x10004EA0L, "flash_begin_veneer", "Veneer to flash_begin at 0x10000120"},
        {0x10004EB0L, "flash_end_veneer", "Veneer to flash_end at 0x10000134"},
        {0x10004EC0L, "flash_status_veneer", "Veneer to flash_status at 0x1000014C"},
    };



    private void apply(Object[][] table) {
        for (Object[] row : table) {
            long ea = (Long) row[0];
            String name = (String) row[1];
            String comment = (String) row[2];
            Address a = toAddr(ea);
            if (a == null) {
                continue;
            }
            Function f = getFunctionAt(a);
            if (f != null) {
                try {
                    f.setName(name, SourceType.USER_DEFINED);
                } catch (Exception e) {
                    println("rename failed at " + a + ": " + e);
                }
                if (!comment.isEmpty()) {
                    f.setComment(comment);
                }
            } else if (createFunction(a, name) != null) {
                println("created " + name + " at " + a);
            }
        }
    }

    private static final long[] VECTORS = new long[] {
        0x1004AFA0L, 0x1004C0A4L, 0x20001070L, 0x1004C76AL, 0x1004C760L,
        0x1004C774L, 0x1004C77EL, 0x1004CB80L, 0x1004CBB4L, 0x1004CEE8L,
        0x1004C4ACL, 0x1004CF34L, 0x1004DD24L, 0x1004DBE0L, 0x1004DBF4L,
        0x1004E1A0L, 0x1004F728L, 0x1004F788L, 0x1004C4E8L,
        0x1004DD24L, 0x100505B4L, 0x10051B04L, 0x10051734L, 0x1005187CL, 0x1004F710L
    };

    private void seedVectors() {
        for (long ea : VECTORS) {
            Address a = toAddr(ea);
            if (a == null) {
                continue;
            }
            if (getFunctionAt(a) == null) {
                if (createFunction(a, null) != null) {
                    println("vector function at " + a);
                }
            }
        }
    }

    private void labelData(Object[][] table) {
        for (Object[] row : table) {
            Address a = toAddr((Long) row[0]);
            if (a == null) {
                continue;
            }
            try {
                createLabel(a, (String) row[1], true);
            } catch (Exception e) {
                println("label failed at " + a + ": " + e);
            }
            String c = (String) row[2];
            if (!c.isEmpty()) {
                setPlateComment(a, c);
            }
        }
    }

    @Override
    public void run() throws Exception {
        String name = currentProgram.getName();
        if (name.contains("boot")) {
            apply(BOOT);
        } else {
            apply(APP);
            seedVectors();
            labelData(DATA);
        }
        println("ApplyAsrNames done for " + name);
    }
}
