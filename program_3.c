#include <stdio.h>
#include <stdint.h>

// Define enums for G range, Bandwidth, and Operation Mode
typedef enum {
    G_2 = 0b00,
    G_4 = 0b01,
    G_8 = 0b10,
    G_16 = 0b11
} GRange;

typedef enum {
    BW_7_81Hz = 0b000,
    BW_15_63Hz = 0b001,
    BW_31_25Hz = 0b010,
    BW_62_5Hz = 0b011,
    BW_125Hz = 0b100,
    BW_250Hz = 0b101,
    BW_500Hz = 0b110,
    BW_1000Hz = 0b111
} Bandwidth;

typedef enum {
    Mode_Normal = 0b000,
    Mode_Suspend = 0b001,
    Mode_LowPower1 = 0b010,
    Mode_Standby = 0b011,
    Mode_LowPower2 = 0b100,
    Mode_DeepSuspend = 0b101
} OperationMode;

// Define the struct
typedef struct {
    GRange g_range;
    Bandwidth bandwidth;
    OperationMode mode;
    uint8_t accConfigValue;
} AccConfig;

// Function to print binary representation of a byte
void print_binary(uint8_t value) {
    for(int i = 7; i >= 0; i--) {
        printf("%d", (value >> i) & 0x01);
    }
    printf("\n");
}

int main() {
    // Create an instance of AccConfig with desired values
    AccConfig config = {
        G_8,      // G range set to 8G
        BW_500Hz, // Bandwidth set to 500Hz
        Mode_Normal // Operation Mode set to Normal
    };

    // Calculate accConfigValue by combining the enum values
    config.accConfigValue = (config.mode << 5) | (config.bandwidth << 2) | config.g_range;

    // Display the configuration value in different formats
    printf("AccConfigValue in decimal: %d\n", config.accConfigValue);
    printf("AccConfigValue in hexadecimal: 0x%02X\n", config.accConfigValue);
    printf("AccConfigValue in binary: ");
    print_binary(config.accConfigValue);

    return 0;
}