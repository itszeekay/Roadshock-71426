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
        {0x1004CE00L, "nvic_enable_irq", "Sets one NVIC enable bit for IRQ 0..30"},
        {0x1004CE38L, "nvic_disable_irq", "Clears one NVIC enable bit for IRQ 0..30"},
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
        {0x10000000L, "boot_vectors", ""},
        {0x10004E60L, "flash_write_page", ""},
        {0x10004EA0L, "flash_begin", ""},
        {0x10004EB0L, "flash_end", ""},
        {0x10004EC0L, "flash_status", ""},
        {0x100019D0L, "flash_write", "flash_write(region, offset, data, len)"},
    };

    private void VECTORS() {
        // placeholder
    }

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
