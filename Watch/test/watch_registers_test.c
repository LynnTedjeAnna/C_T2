#include <stdio.h>
#include <string.h>

#include "unity.h"
#include "unity_test_module.h"
#include "watch_registers.h"

// leave resource_detector.h as last include!
#include "resource_detector.h"

// I rather dislike keeping line numbers updated, so I made my own macro to
// ditch the line number
#define MY_RUN_TEST(func) RUN_TEST(func, 0)

void watch_setUp(void)
{
}

void watch_tearDown(void)
{
    // This is run after EACH test
}

void test_setting_time_hours(void)
{
    const uint8_t hours = 0xA5;
    uint8_t time_bits_high = 0xA5;
    uint8_t time_bits_low = 0x5A;

    watch_registers_set_time_hours(&time_bits_low, &time_bits_high, hours);
    TEST_ASSERT_EQUAL_HEX8(0xA5, time_bits_high);
    TEST_ASSERT_EQUAL_HEX8(0x5A, time_bits_low);
}

void test_get_time(void)
{
    const uint8_t hours = 11;
    const uint8_t minutes = 55;
    const uint8_t seconds = 42;
    uint8_t time_bits_low = 0;
    uint8_t time_bits_high = 0b00;

    watch_registers_set_time_seconds(&time_bits_low, &time_bits_high, seconds);
    watch_registers_set_time_minutes(&time_bits_low, &time_bits_high, minutes);
    watch_registers_set_time_hours(&time_bits_low, &time_bits_high, hours);

    uint8_t h;
    uint8_t m;
    uint8_t s;
    watch_registers_get_time(time_bits_low, time_bits_high, &h, &m, &s);
    TEST_ASSERT_EQUAL(hours, h);
    TEST_ASSERT_EQUAL(minutes, m);
    TEST_ASSERT_EQUAL(seconds, s);
}

/*------------------------------------------------------------------------------------------------------------------*/
void test_watch_registers_toggle_config_is_paused() {
    uint8_t config = 0b0;

    watch_registers_toggle_config_is_paused(&config);
    TEST_ASSERT_EQUAL(0b1000, config);
}
/*------------------------------------------------------------------------------------------------------------------*/
void test_watch_registers_set_config_time_format_0(){
    uint8_t config = 0b1100;
    time_format format = 0;

    watch_registers_set_config_time_format(&config, format);
    TEST_ASSERT_EQUAL(0b1100, config);
}
void test_watch_registers_set_config_time_format_1(){
    uint8_t config = 0b1100;
    time_format format = 1;

    watch_registers_set_config_time_format(&config, format);
    TEST_ASSERT_EQUAL(0b1101, config);
}
/*------------------------------------------------------------------------------------------------------------------*/
void test_watch_registers_set_config_time_update_interval_11(){
    uint8_t config = 0b11100;
    time_update_interval interval = 3;
    watch_registers_set_config_time_update_interval(&config, interval);

    TEST_ASSERT_EQUAL(0b11110, config);
}
void test_watch_registers_set_config_time_update_interval_10(){
    uint8_t config = 0b11000;
    time_update_interval interval = 2;
    watch_registers_set_config_time_update_interval(&config, interval);

    TEST_ASSERT_EQUAL(0b11100, config);
}
/*------------------------------------------------------------------------------------------------------------------*/
void test_watch_registers_get_config_settings(){
    uint8_t config = 0b11101;
    bool is_paused;
    time_format format;
    time_update_interval interval;

    watch_registers_get_config_settings(config, &is_paused, &format, &interval);

    TEST_ASSERT_EQUAL(0b1, format);
    TEST_ASSERT_EQUAL(0b10, interval);
    TEST_ASSERT_EQUAL(0b1, is_paused);
}
/*------------------------------------------------------------------------------------------------------------------*/
void test_watch_registers_set_time_hours(){
    uint8_t time_bits_low = 0b0;
    uint8_t time_bits_high = 0b0;
    uint8_t hours = 10;

    watch_registers_set_time_hours(&time_bits_low, &time_bits_high, hours);

    TEST_ASSERT_EQUAL(0b10100000, time_bits_high);
}
/*------------------------------------------------------------------------------------------------------------------*/
void test_watch_registers_set_time_minutes(){
    uint8_t time_bits_low = 0b0;
    uint8_t time_bits_high = 0b110;
    uint8_t minutes = 10;

    watch_registers_set_time_minutes(&time_bits_low, &time_bits_high, minutes);
    TEST_ASSERT_EQUAL(0b10000000, time_bits_low);
    TEST_ASSERT_EQUAL(0b00000010, time_bits_high);
}
/*------------------------------------------------------------------------------------------------------------------*/
void test_watch_registers_set_time_seconds(){
    uint8_t time_bits_low = 0b100;
    uint8_t time_bits_high = 0b0;
    uint8_t seconds = 10;

    watch_registers_set_time_seconds(&time_bits_low, &time_bits_high, seconds);
    TEST_ASSERT_EQUAL(0b1010, time_bits_low);
}
/*------------------------------------------------------------------------------------------------------------------*/
void test_watch_registers_set_date_year(){
    uint8_t date_bits_low = 0b10;
    uint8_t date_bits_high = 0b0;
    uint8_t year = 1;       //2001

    watch_registers_set_date_year(&date_bits_low, &date_bits_high, year);

    TEST_ASSERT_EQUAL(0b1, date_bits_low);
}
/*------------------------------------------------------------------------------------------------------------------*/
void test_watch_registers_set_date_month(){
    uint8_t date_bits_low = 0b10;
    uint8_t date_bits_high = 0b01;
    uint8_t month = 10;

    watch_registers_set_date_month(&date_bits_low, &date_bits_high, month);

    TEST_ASSERT_EQUAL(0b10, date_bits_low);
    TEST_ASSERT_EQUAL(0b101, date_bits_high);
}
/*------------------------------------------------------------------------------------------------------------------*/
void test_watch_registers_set_date_day_of_month(){
    uint8_t date_bits_low = 0b0;
    uint8_t date_bits_high = 0b1;
    uint8_t day_of_month = 10;

    watch_registers_set_date_day_of_month(&date_bits_low, &date_bits_high, day_of_month);

    TEST_ASSERT_EQUAL(0b1010001, date_bits_high);
}
/*------------------------------------------------------------------------------------------------------------------*/
void test_watch_registers_get_date()
{
    const uint8_t year = 1;        //2001
    const uint8_t month = 10;
    const uint8_t day_of_month = 10;
    uint8_t time_bits_low = 0b1111;
    uint8_t time_bits_high = 0b1111;

    watch_registers_set_date_year(&time_bits_low, &time_bits_high, year);
    watch_registers_set_date_month(&time_bits_low, &time_bits_high, month);
    watch_registers_set_date_day_of_month(&time_bits_low, &time_bits_high, day_of_month);

    uint8_t y;
    uint8_t m;
    uint8_t d;
    watch_registers_get_date(time_bits_low, time_bits_high, &y, &m, &d);
    TEST_ASSERT_EQUAL(year, y);
    TEST_ASSERT_EQUAL(month, m);
    TEST_ASSERT_EQUAL(day_of_month, d);
}
/*------------------------------------------------------------------------------------------------------------------*/

void run_watch_tests()
{
    UnityRegisterSetupTearDown( watch_setUp, watch_tearDown);

    MY_RUN_TEST(test_setting_time_hours);
    MY_RUN_TEST(test_get_time);
    MY_RUN_TEST(test_watch_registers_toggle_config_is_paused);
    MY_RUN_TEST(test_watch_registers_set_config_time_format_1);
    MY_RUN_TEST(test_watch_registers_set_config_time_format_0);
    MY_RUN_TEST(test_watch_registers_set_config_time_update_interval_11);
    MY_RUN_TEST(test_watch_registers_set_config_time_update_interval_10);
    MY_RUN_TEST(test_watch_registers_get_config_settings);
    MY_RUN_TEST(test_watch_registers_set_time_hours);
    MY_RUN_TEST(test_watch_registers_set_time_minutes);
    MY_RUN_TEST(test_watch_registers_set_time_seconds);
    MY_RUN_TEST(test_watch_registers_set_date_year);
    MY_RUN_TEST(test_watch_registers_set_date_month);
    MY_RUN_TEST(test_watch_registers_set_date_day_of_month);
    MY_RUN_TEST(test_watch_registers_get_date);

    UnityUnregisterSetupTearDown();
}
