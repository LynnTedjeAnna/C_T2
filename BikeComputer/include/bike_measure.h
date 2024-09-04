//
// Created by Lynn Meindertsma on 03/09/2024.
//

#ifndef BIKECOMPUTER_BIKE_MEASURE_H
#define BIKECOMPUTER_BIKE_MEASURE_H
#include <stdint.h>

uint16_t bike_measure_speed_in_kmh(void);
uint16_t bike_measure_power_in_watt(void);
uint16_t bike_measure_cadence_in_rpm(void);
uint16_t bike_measure_heart_rate_in_bpm(void);


#endif //BIKECOMPUTER_BIKE_MEASURE_H
