#include <string.h>
// add your include here
#include "unity.h"
#include "unity_test_module.h"
#include "skater.h"


// I rather dislike keeping line numbers updated, so I made my own
// macro to ditch the line number
#define MY_RUN_TEST(func) RUN_TEST(func, 0)

void skater_setUp(void)
{
    // This is run before EACH test
}

void skater_tearDown(void)
{
    // This is run after EACH test
}


// TODO:
//  - Rename and change this test to something usefull
//  - Add more tests
//  - Remove this comment :)
// Should you need a list of all TEST_ASSERT macros: take a look
// at unity.h
void test_skater_EmptyTest(void)
{
    TEST_ASSERT_EQUAL(1, 0);
}

void run_skater_tests()
{
    UnityRegisterSetupTearDown( skater_setUp, skater_tearDown);

    MY_RUN_TEST(test_skater_EmptyTest);

    UnityUnregisterSetupTearDown();
}
