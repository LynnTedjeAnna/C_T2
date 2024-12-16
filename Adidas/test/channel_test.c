#include "unity.h"
#include "unity_test_module.h"
#include "channel.h"


// I rather dislike keeping line numbers updated, so I made my own macro to ditch the line number
#define MY_RUN_TEST(func) RUN_TEST(func, 0)

extern void channel_setUp(void)
{
    // This is run before EACH test
}

extern void channel_tearDown(void)
{
    // This is run after EACH test
}

static void test_channel(void){
    uint8_t test = 0b10101010;
    uint8_t res = channel_change_one_random_bit(test);
    TEST_ASSERT_NOT_EQUAL(test, res);
}

void run_channel_tests()
{
    UnityRegisterSetupTearDown( channel_setUp, channel_tearDown);

    MY_RUN_TEST(test_channel);

    UnityUnregisterSetupTearDown();
}
