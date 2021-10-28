///////////////////////////////////////////
//                                       //
//  General                              //
//                                       //
///////////////////////////////////////////

// # Ethernet settings
// Hostname of the MCU
#define CUSTOM_HOST_NAME "arduino01"

// MAC address of the MCU
// For example: 74:69:69:2D:30:31 becomes 0x74, 0x69, 0x69, 0x2D, 0x30, 0x31
#define MAC_ADDR_BYTE_1 0x74
#define MAC_ADDR_BYTE_2 0x69
#define MAC_ADDR_BYTE_3 0x69
#define MAC_ADDR_BYTE_4 0x2D
#define MAC_ADDR_BYTE_5 0x30
#define MAC_ADDR_BYTE_6 0x31

///////////////////////////////////////////
//                                       //
//  Inputs                               //
//                                       //
///////////////////////////////////////////
// Inputs - Push Buttons
// You can name these however you want.
// Recommendation: I_PB_<FLOOR>_<ROOM>_<NAME OR NUMBER>
// Example: I_PB_FIRSTFLOOR_BEDROOM1_RIGHT
#define I_PB_1 49
#define I_PB_2 47
#define I_PB_3 45
#define I_PB_4 43
#define I_PB_5 41
#define I_PB_6 39

// Inputs - Switches
// You can name these however you want.
// Recommendation: I_PB_<FLOOR>_<ROOM>_<NAME OR NUMBER>
// Example: I_SW_FIRSTFLOOR_BEDROOM1_LEFT
#define I_SW_1_1 48
#define I_SW_1_2 46
#define I_SW_2_1 44
#define I_SW_2_2 42
#define I_SW_3_1 40
#define I_SW_3_2 38
#define I_SW_4_1 36
#define I_SW_4_2 34

///////////////////////////////////////////
//                                       //
//  Outputs                              //
//                                       //
///////////////////////////////////////////
// Outputs - Digital
// You can name these however you want.
// Recommendation: I_PB_<FLOOR>_<ROOM>_<NAME OR NUMBER>
// Example: Q_FIRSTFLOOR_BEDROOM1_CEILING
#define Q_RELAY_1 2
#define Q_RELAY_2 3
#define Q_RELAY_3 4
#define Q_RELAY_4 5
#define Q_RELAY_5 6
#define Q_RELAY_6 7
#define Q_RELAY_7 8
#define Q_RELAY_8 9

///////////////////////////////////////////
//                                       //
//  Settings                             //
//                                       //
///////////////////////////////////////////
// You can change these if the program does not fit on the MCU.

// Maximum amount of physical outputs that the program supports.
#define MAX_AMOUNT_OF_INSTANCES 100

// Maximum amount of input pins that a single output supports.
#define MAX_AMOUNT_OF_INPUT_PINS 8

// Maximum amount of all off input pins that a single output supports.
#define MAX_AMOUNT_OF_ALL_OFF_INPUT_PINS 8