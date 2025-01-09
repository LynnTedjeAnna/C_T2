#include "unity.h"
#include "unity_test_module.h"
#include "decode.h"

// I rather dislike keeping line numbers updated, so I made my own macro to ditch the line number
#define MY_RUN_TEST(func) RUN_TEST(func, 0)

extern void decode_setUp(void)
{
    // This is run before EACH test
}

extern void decode_tearDown(void)
{
    // This is run after EACH test
}

void test_decode(void){
    uint8_t in[8] = {
        0b10000000, 0b0101011, 0b0000111, 0b0010100,
        0b0100001, 0b0101100, 0b0110011, 0b11111111
    };
    uint8_t correct_nibble[8] = {
            0b0000, 0b0001, 0b0010, 0b0011,
            0b0100, 0b0101, 0b0110, 0b1111
    };
    uint8_t nibble;
    for (int i = 0; i < 8; ++i) {
        decode_byte(in[i], &nibble);
        TEST_ASSERT_EQUAL_HEX8(correct_nibble[i], nibble);
    }
}


void run_decode_tests()
{
    UnityRegisterSetupTearDown( decode_setUp, decode_tearDown);

    MY_RUN_TEST(test_decode);

    UnityUnregisterSetupTearDown();
}
