// Roadshock Switch Panel - RP2040 CAN Gateway Firmware
// Acts as MITM between base board and button panel, with CAN bus interface
// 
// Wiring:
//   Base board UART TX -> RP2040 GPIO 1 (UART0 RX)
//   RP2040 GPIO 0 (UART0 TX) -> Button panel UART RX
//   Button panel UART TX -> RP2040 GPIO 5 (UART1 RX)
//   RP2040 GPIO 4 (UART1 TX) -> Base board UART RX (optional)
//   CAN TX -> MCP2515 TX (or built-in CAN if available)
//   CAN RX -> MCP2515 RX

#include <Arduino.h>
#include <SPI.h>
#include <mcp2515.h>

// ===== Configuration =====
#define BAUD_RATE 115200          // UART baud rate (match panel)
#define CAN_BAUD CAN_500KBPS      // CAN bus speed

// RP2040 UART pins (Feather RP2040)
// UART0: TX=GPIO0, RX=GPIO1
// UART1: TX=GPIO4, RX=GPIO5
#define UART_BASE_RX 1   // Base board TX -> RP2040 RX
#define UART_BASE_TX 0   // RP2040 TX -> Button panel RX
#define UART_PANEL_RX 5  // Button panel TX -> RP2040 RX  
#define UART_PANEL_TX 4  // RP2040 TX -> Base board RX (optional)

// MCP2515 CAN controller pins
#define CAN_CS 10
#define CAN_INT 2

// CAN IDs for Roadshock panel
#define CAN_ID_BASE      0x200  // Base board status
#define CAN_ID_BUTTONS   0x201  // Button states
#define CAN_ID_LEDS      0x202  // LED control
#define CAN_ID_CONFIG    0x203  // Configuration

// Protocol parsing state
enum ParseState {
    WAIT_START,
    READ_LEN,
    READ_CMD,
    READ_DATA,
    READ_CRC
};

struct PanelFrame {
    uint8_t start;
    uint8_t len;
    uint8_t cmd;
    uint8_t data[32];
    uint8_t crc;
    bool valid;
};

// ===== Global Objects =====
MCP2515 mcp2515(CAN_CS);

// UART buffers
uint8_t uart0_buf[64];
uint8_t uart1_buf[64];
size_t uart0_len = 0;
size_t uart1_len = 0;

// Protocol parsing
ParseState parse_state = WAIT_START;
PanelFrame current_frame;
size_t data_idx = 0;

// Statistics
uint32_t frames_received = 0;
uint32_t frames_sent = 0;
uint32_t crc_errors = 0;
uint32_t last_can_send = 0;

// ===== CRC Calculation (adjust based on actual protocol) =====
uint8_t calc_crc8(uint8_t *data, size_t len) {
    uint8_t crc = 0x00;
    for (size_t i = 0; i < len; i++) {
        crc ^= data[i];
        for (int j = 0; j < 8; j++) {
            if (crc & 0x80)
                crc = (crc << 1) ^ 0x07;
            else
                crc <<= 1;
        }
    }
    return crc;
}

// ===== CAN Message Handling =====
void send_can_status() {
    struct can_frame frame;
    frame.can_id = CAN_ID_BASE;
    frame.can_dlc = 8;
    frame.data[0] = 0x01;  // Device online
    frame.data[1] = frames_received & 0xFF;
    frame.data[2] = (frames_received >> 8) & 0xFF;
    frame.data[3] = crc_errors & 0xFF;
    frame.data[4] = millis() & 0xFF;
    frame.data[5] = (millis() >> 8) & 0xFF;
    frame.data[6] = 0x00;
    frame.data[7] = 0x00;
    
    if (mcp2515.sendMessage(&frame) == MCP2515::ERROR_OK) {
        frames_sent++;
    }
}

void send_button_state(uint8_t button_mask, uint8_t button_states) {
    struct can_frame frame;
    frame.can_id = CAN_ID_BUTTONS;
    frame.can_dlc = 8;
    frame.data[0] = button_mask;    // Which buttons changed
    frame.data[1] = button_states;  // Current states
    frame.data[2] = 0x00;
    frame.data[3] = 0x00;
    frame.data[4] = 0x00;
    frame.data[5] = 0x00;
    frame.data[6] = 0x00;
    frame.data[7] = 0x00;
    
    mcp2515.sendMessage(&frame);
}

void handle_can_rx() {
    struct can_frame frame;
    if (mcp2515.readMessage(&frame) == MCP2515::ERROR_OK) {
        switch (frame.can_id) {
            case CAN_ID_LEDS:
                // Forward LED commands to base board
                forward_to_base(frame.data, frame.can_dlc);
                break;
            case CAN_ID_CONFIG:
                // Handle configuration commands
                handle_config(frame.data, frame.can_dlc);
                break;
        }
    }
}

void forward_to_base(uint8_t *data, uint8_t len) {
    // Send to base board via UART0
    Serial1.write(data, len);
    Serial1.flush();
}

void forward_to_panel(uint8_t *data, uint8_t len) {
    // Send to button panel via UART1 (if connected)
    // Note: Requires UART1 TX connected to base board RX
}

void handle_config(uint8_t *data, uint8_t len) {
    if (len >= 2) {
        uint8_t cmd = data[0];
        uint8_t param = data[1];
        
        switch (cmd) {
            case 0x01:  // Set UART baud rate
                // Would require UART reinit - not implemented
                break;
            case 0x02:  // Set CAN ID base
                // Update CAN IDs
                break;
            case 0x03:  // Request firmware version
                send_firmware_version();
                break;
        }
    }
}

void send_firmware_version() {
    struct can_frame frame;
    frame.can_id = CAN_ID_CONFIG;
    frame.can_dlc = 8;
    frame.data[0] = 0x03;  // Version response
    frame.data[1] = 0x01;  // Major
    frame.data[2] = 0x00;  // Minor
    frame.data[3] = 0x01;  // Patch
    frame.data[4] = 0x52;  // 'R'
    frame.data[5] = 0x4F;  // 'O'
    frame.data[6] = 0x41;  // 'A'
    frame.data[7] = 0x44;  // 'D'
    mcp2515.sendMessage(&frame);
}

// ===== Protocol Parsing =====
void process_uart_byte(uint8_t byte, uint8_t source) {
    // source: 0 = base board, 1 = button panel
    
    switch (parse_state) {
        case WAIT_START:
            if (byte == 0xAA || byte == 0x55) {  // Common start bytes
                current_frame.start = byte;
                parse_state = READ_LEN;
            }
            break;
            
        case READ_LEN:
            current_frame.len = byte;
            if (current_frame.len > 32) {
                parse_state = WAIT_START;  // Invalid length
            } else {
                data_idx = 0;
                parse_state = READ_CMD;
            }
            break;
            
        case READ_CMD:
            current_frame.cmd = byte;
            if (current_frame.len > 1) {
                parse_state = READ_DATA;
            } else {
                parse_state = READ_CRC;
            }
            break;
            
        case READ_DATA:
            current_frame.data[data_idx++] = byte;
            if (data_idx >= current_frame.len - 1) {
                parse_state = READ_CRC;
            }
            break;
            
        case READ_CRC:
            current_frame.crc = byte;
            current_frame.valid = true;
            
            // Verify CRC
            uint8_t calc_data[34];
            calc_data[0] = current_frame.start;
            calc_data[1] = current_frame.len;
            calc_data[2] = current_frame.cmd;
            for (int i = 0; i < current_frame.len - 1; i++) {
                calc_data[3 + i] = current_frame.data[i];
            }
            
            uint8_t expected_crc = calc_crc8(calc_data, 3 + current_frame.len - 1);
            
            if (current_frame.crc == expected_crc) {
                handle_frame(source);
            } else {
                crc_errors++;
                // Try alternative CRC (simple XOR)
                uint8_t xor_crc = 0;
                for (int i = 0; i < 3 + current_frame.len - 1; i++) {
                    xor_crc ^= calc_data[i];
                }
                if (current_frame.crc == xor_crc) {
                    handle_frame(source);
                }
            }
            
            parse_state = WAIT_START;
            break;
    }
}

void handle_frame(uint8_t source) {
    frames_received++;
    
    // Log frame
    char buf[128];
    snprintf(buf, sizeof(buf), "[%s] CMD:0x%02X LEN:%d DATA:", 
             source == 0 ? "BASE" : "PNL", current_frame.cmd, current_frame.len);
    for (int i = 0; i < current_frame.len - 1; i++) {
        char tmp[4];
        snprintf(tmp, sizeof(tmp), " %02X", current_frame.data[i]);
        strcat(buf, tmp);
    }
    Serial.println(buf);
    
    // Forward to CAN bus
    struct can_frame frame;
    if (source == 0) {
        // Base board -> CAN
        frame.can_id = CAN_ID_BASE;
    } else {
        // Button panel -> CAN
        frame.can_id = CAN_ID_BUTTONS;
    }
    
    frame.can_dlc = min(current_frame.len + 1, (uint8_t)8);
    frame.data[0] = current_frame.cmd;
    for (int i = 0; i < current_frame.len - 1 && i < 7; i++) {
        frame.data[i + 1] = current_frame.data[i];
    }
    
    mcp2515.sendMessage(&frame);
    
    // Also relay to other UART (MITM mode)
    // Uncomment for active MITM:
    // if (source == 0) forward_to_panel(...);
    // else forward_to_base(...);
}

// ===== Setup =====
void setup() {
    // USB Serial for debugging
    Serial.begin(115200);
    while (!Serial && millis() < 3000);
    
    Serial.println("\n=== Roadshock CAN Gateway ===");
    Serial.println("STM8S003 MITM + CAN Bridge");
    Serial.println("==============================\n");
    
    // Initialize UART0 (base board)
    Serial1.setRX(UART_BASE_RX);
    Serial1.setTX(UART_BASE_TX);
    Serial1.begin(BAUD_RATE);
    
    // Initialize UART1 (button panel) - if pins available
    // Serial2.setRX(UART_PANEL_RX);
    // Serial2.setTX(UART_PANEL_TX);
    // Serial2.begin(BAUD_RATE);
    
    // Initialize MCP2515 CAN controller
    SPI.begin();
    mcp2515.reset();
    mcp2515.setBitrate(CAN_BAUD);
    mcp2515.setNormalMode();
    
    Serial.printf("UART0 (Base): %d baud on RX=%d TX=%d\n", BAUD_RATE, UART_BASE_RX, UART_BASE_TX);
    Serial.printf("CAN: %d kbps on CS=%d\n", CAN_BAUD == CAN_500KBPS ? 500 : 250, CAN_CS);
    Serial.println("Ready - monitoring UART traffic...\n");
    
    // Send initial status
    send_can_status();
    send_firmware_version();
}

void loop() {
    // Read from base board (UART0)
    while (Serial1.available()) {
        uint8_t byte = Serial1.read();
        process_uart_byte(byte, 0);
    }
    
    // Read from button panel (UART1) - if connected
    // while (Serial2.available()) {
    //     uint8_t byte = Serial2.read();
    //     process_uart_byte(byte, 1);
    // }
    
    // Handle incoming CAN messages
    handle_can_rx();
    
    // Periodic status broadcast
    if (millis() - last_can_send > 1000) {
        send_can_status();
        last_can_send = millis();
    }
    
    // Small delay to prevent tight loop
    delay(1);
}