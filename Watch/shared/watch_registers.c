#include "watch_registers.h"

// leave resource_detector.h as last include!
#include "resource_detector.h"

void watch_registers_toggle_config_is_paused(uint8_t* config){
    if (config == NULL){ return;}
    *config ^= (0b1 << 3);
}

void watch_registers_set_config_time_format(uint8_t* config, time_format format){
    if (config == NULL){ return;}
    *config = ((*config & ~(0b1)) | format);
}

void watch_registers_set_config_time_update_interval(uint8_t* config, time_update_interval interval){
    if (config == NULL){ return;}
    *config = ((*config & ~(0b11 << 1)) | (interval << 1));
}

void watch_registers_get_config_settings(uint8_t config, bool* is_paused, time_format* format, time_update_interval* interval){
    if (is_paused == NULL || format == NULL || interval == NULL){ return;}
    *format = config & 0b1;
    *interval = ((config >> 1) & 0b11);
    *is_paused = ((config >> 3) & 0b1 );
}

void watch_registers_set_time_hours(uint8_t* time_bits_low, uint8_t* time_bits_high, uint8_t hours){
    if (time_bits_low == NULL || time_bits_high == NULL){ return;}
    if (hours > 11){ return;}
    *time_bits_high |= (hours & 0b1111) << 4;
}

void watch_registers_set_time_minutes(uint8_t* time_bits_low, uint8_t* time_bits_high, uint8_t minutes){
    if (time_bits_low == NULL || time_bits_high == NULL){ return;}
    if (minutes > 59){ return;}

    *time_bits_low &= ~(0b11 << 6);
    *time_bits_low |= ((minutes & 0b11) << 6);

    *time_bits_high &= ~(0b1111);
    *time_bits_high |= (minutes >> 2) & 0b1111;
}

void watch_registers_set_time_seconds(uint8_t* time_bits_low, uint8_t* time_bits_high, uint8_t seconds){
    if (time_bits_low == NULL || time_bits_high == NULL){ return;}
    if (seconds > 59){ return;}
    *time_bits_low &= ~(0b111111);
    *time_bits_low |= seconds;
}

void watch_registers_get_time(uint8_t time_bits_low, uint8_t time_bits_high, uint8_t* hours, uint8_t* minutes, uint8_t* seconds){
    if (hours == NULL || minutes == NULL || seconds == NULL){ return;}
    *hours = time_bits_high >> 4;
    *minutes = time_bits_low >> 6;
    *minutes |= (time_bits_high & 0b1111) << 2;
    *seconds = time_bits_low & ~(0b11 << 6);
}

void watch_registers_set_date_year(uint8_t* date_bits_low, uint8_t* date_bits_high, uint8_t year){
    if (date_bits_low == NULL || date_bits_high == NULL){ return;}
    if (year > 127){ return;}

    *date_bits_low &= ~(0b1111111);
    *date_bits_low |= year;
}

void watch_registers_set_date_month(uint8_t* date_bits_low, uint8_t* date_bits_high, uint8_t month){
    if (date_bits_low == NULL || date_bits_high == NULL){ return;}
    if (month > 12){ return;}

    *date_bits_low &= ~((0b1) << 7);
    *date_bits_low |= month << 7;

    *date_bits_high &= ~(0b111);
    *date_bits_high |= ((month >> 1) & 0b111);
}

void watch_registers_set_date_day_of_month(uint8_t* date_bits_low, uint8_t* date_bits_high, uint8_t day_of_month){
    if (date_bits_low == NULL || date_bits_high == NULL){ return;}
    if (day_of_month > 31){ return;}

    *date_bits_high &= ~(0b11111 << 3);
    *date_bits_high |= day_of_month << 3;
}

void watch_registers_get_date(uint8_t date_bits_low, uint8_t date_bits_high, uint8_t* year, uint8_t* month, uint8_t* day_of_month){
    if (year == NULL || month == NULL || day_of_month == NULL){ return;}

    *year = date_bits_low & ~(0b1 << 7);

    *month = date_bits_low >> 7;
    *month |= (date_bits_high & 0b111);

    *day_of_month = (date_bits_high & ~(0b111)) >> 3;
}
