#include <stdlib.h>
#include <unistd.h>		// for close()

#include "unity.h"
#include "unity_test_module.h"
#include "encode.h"

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

void test_encode(void)
{
    TEST_ASSERT_EQUAL(1, 0);
}


void run_encode_tests()
{
    UnityRegisterSetupTearDown( encode_setUp, encode_tearDown);

    MY_RUN_TEST(test_encode);

    UnityUnregisterSetupTearDown();
}
