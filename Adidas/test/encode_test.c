#include <stdlib.h>
#include <unistd.h>		// for close()

#include "unity.h"
#include "unity_test_module.h"
#include "encode.h"
#include "parity.h"

// I rather dislike keeping line numbers updated, so I made my own macro to ditch the line number
#define MY_RUN_TEST(func) RUN_TEST(func, 0)

extern void encode_setUp(void)
{
    // This is run before EACH test
}

extern void encode_tearDown(void)
{
    // This is run after EACH test
}

// todo: test encode
void test_encode(void)
{
    TEST_ASSERT_EQUAL(0, 0);
}
// todo: loop through all values -15
void test_get_parity_0101(void) {
    uint8_t nibble = 0b0101;
    uint8_t result = get(&nibble);
    TEST_ASSERT_EQUAL_HEX(0b110, result);  // Expected result for this nibble
}
void test_get_parity_1111(void) {
    uint8_t nibble = 0b1111;
    uint8_t result = get(&nibble);
    TEST_ASSERT_EQUAL_HEX(0b111, result);  // Expected result for this nibble
}
void test_get_parity(void) {
    uint8_t nibble[16] = {
            0b0000, 0b0001, 0b0010, 0b0011,
            0b0100, 0b0101, 0b0110, 0b0111,
            0b1000, 0b1001, 0b1010, 0b1011,
            0b1100, 0b1101, 0b1110, 0b1111
    };

    // Expected parity results precomputed
    uint8_t parities[16] = {
            0b000,  // Parity for 0b0000
            0b011,  // Parity for 0b0001
            0b111,  // Parity for 0b0010
            0b100,  // Parity for 0b0011
            0b101,  // Parity for 0b0100
            0b110,  // Parity for 0b0101
            0b010,  // Parity for 0b0110
            0b001,  // Parity for 0b0111
            0b110,  // Parity for 0b1000
            0b101,  // Parity for 0b1001
            0b001,  // Parity for 0b1010
            0b010,  // Parity for 0b1011
            0b011,  // Parity for 0b1100
            0b000,  // Parity for 0b1101
            0b100,  // Parity for 0b1110
            0b111   // Parity for 0b1111
    };

    for (int i = 0; i < 16; ++i) {
        uint8_t result = get(&nibble[i]);
        TEST_ASSERT_EQUAL_HEX8(parities[i], result);
    }
}



void run_encode_tests()
{
    UnityRegisterSetupTearDown( encode_setUp, encode_tearDown);

    MY_RUN_TEST(test_encode);
    MY_RUN_TEST(test_get_parity_0101);
    MY_RUN_TEST(test_get_parity);


    UnityUnregisterSetupTearDown();
}
