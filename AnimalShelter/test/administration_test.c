#include <string.h>

#include "administration.h"
#include "unity.h"
#include "unity_test_module.h"

// I rather dislike keeping line numbers updated, so I made my own macro to ditch the line number
#define MY_RUN_TEST(func) RUN_TEST(func, 0)

void administration_setUp(void)
{
    // This is run before EACH test
}

void administration_tearDown(void)
{
    // This is run after EACH test
}

void test_EmptyTest(void)
{
    TEST_ASSERT_EQUAL(1, 0);
}

//add here your testcases

void run_administration_tests()
{
    UnityRegisterSetupTearDown(administration_setUp, administration_tearDown);

    MY_RUN_TEST(test_EmptyTest);

    UnityUnregisterSetupTearDown();
}

