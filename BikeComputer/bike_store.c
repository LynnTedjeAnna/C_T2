//
// Created by Lynn Meindertsma on 03/09/2024.
//

#include "include/bike_store.h"
 uint16_t bike_store_number_of_measurements_present = 0;

bike_store_measurement bike_store_array[BIKE_STORE_MAX_NUMBER_MEASUREMENTS] = {
    { 0, },
};

uint16_t bike_store_get_maximum_bike_store_size(void)
{
    return BIKE_STORE_MAX_NUMBER_MEASUREMENTS;
}

void bike_store_add_measurement(bike_store_measurement value)
{
    if (bike_store_number_of_measurements_present >=
        bike_store_get_maximum_bike_store_size())
    {
        bike_store_number_of_measurements_present = 0;
    }

    bike_store_array[bike_store_number_of_measurements_present] = value;
    bike_store_number_of_measurements_present++;
}

uint16_t bike_store_get_number_of_measurements_present(void)
{
    return bike_store_number_of_measurements_present;
}

bike_store_measurement bike_store_get_measurement(uint16_t index_position)
{
    bike_store_measurement value = bike_store_array[index_position];

    return value;
}

