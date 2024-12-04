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

void test_decode(void)
{
    TEST_ASSERT_EQUAL(1, 0);
}

void run_decode_tests()
{
    UnityRegisterSetupTearDown( decode_setUp, decode_tearDown);

    MY_RUN_TEST(test_decode);

    UnityUnregisterSetupTearDown();
}
