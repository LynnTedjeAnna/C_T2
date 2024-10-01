//
// Created by Lynn Meindertsma on 03/09/2024.
//

#ifndef BIKECOMPUTER_BIKE_MATH_H
#define BIKECOMPUTER_BIKE_MATH_H
#include <stdint.h>
#include "bike_store.h"

typedef enum {
    BIKE_SPEED,
    BIKE_HEART_RATE,
    BIKE_CADENCE,
    BIKE_POWER
} bike_data_type;

/*uint16_t bike_math_get_value_for_data_type(
            bike_store_measurement measurement, bike_data_type data_type);
            */
uint16_t bike_math_calculate_min_value(bike_data_type data_type);
uint16_t bike_math_calculate_max_value(bike_data_type data_type);
uint16_t bike_math_calculate_average_value(bike_data_type data_type);


#endif //BIKECOMPUTER_BIKE_MATH_H
