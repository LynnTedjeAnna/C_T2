#include "parity.h"

// Parity Bit Masks and Positions
#define PARITY_BIT_0_MASK 0b1
#define PARITY_BIT_0_POS  0
#define PARITY_BIT_1_MASK 0b10
#define PARITY_BIT_1_POS  1
#define PARITY_BIT_2_MASK 0b100
#define PARITY_BIT_2_POS  2

// Nibble Data Masks and Positions
#define NIBBLE_DATA_0_MASK 0b1
#define NIBBLE_DATA_0_POS  0
#define NIBBLE_DATA_1_MASK 0b10
#define NIBBLE_DATA_1_POS  1
#define NIBBLE_DATA_2_MASK 0b100
#define NIBBLE_DATA_2_POS  2
#define NIBBLE_DATA_3_MASK 0b1000
#define NIBBLE_DATA_3_POS  3

// nibble comes in as 00001111

uint8_t get(uint8_t* nibble) {
    uint8_t parities = 0b0;

    // Extract individual bits from the nibble using masks and positions
    uint8_t data0 = (*nibble & NIBBLE_DATA_0_MASK) >> NIBBLE_DATA_0_POS;
    uint8_t data1 = (*nibble & NIBBLE_DATA_1_MASK) >> NIBBLE_DATA_1_POS;
    uint8_t data2 = (*nibble & NIBBLE_DATA_2_MASK) >> NIBBLE_DATA_2_POS;
    uint8_t data3 = (*nibble & NIBBLE_DATA_3_MASK) >> NIBBLE_DATA_3_POS;

    // Calculate parity bits and update parities variable
    parities &= ~PARITY_BIT_0_MASK;
    parities |= ((data0 ^ data1 ^ data2) << PARITY_BIT_0_POS);

    parities &= ~PARITY_BIT_1_MASK;
    parities |= ((data0 ^ data1 ^ data3) << PARITY_BIT_1_POS);

    parities &= ~PARITY_BIT_2_MASK;
    parities |= ((data1 ^ data2 ^ data3) << PARITY_BIT_2_POS);

    return parities;
}