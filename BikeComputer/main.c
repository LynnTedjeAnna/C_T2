#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <unistd.h>
#include "include/bike_measure.h"
#include "include/bike_math.h"
/*---------------------------------------------------------------*/
//measure
/*---------------------------------------------------------------*/
//store
/*---------------------------------------------------------------*/
//math
/*---------------------------------------------------------------*/
int main(int argc, char* argv[])
{
    bike_store_measurement measurement;
    uint16_t min = 0, max = 0, average = 0;
    bike_data_type data_type;

    while (true)
    {
        measurement.speed = bike_measure_speed_in_kmh();
        measurement.cadence = bike_measure_cadence_in_rpm();
        measurement.heart_rate = bike_measure_heart_rate_in_bpm();
        measurement.power = bike_measure_power_in_watt();

        bike_store_add_measurement(measurement);

        data_type = BIKE_SPEED;
        min = bike_math_calculate_min_value(data_type);
        max = bike_math_calculate_max_value(data_type);
        average = bike_math_calculate_average_value(data_type);
        printf("SPEED:\t\t%d, average = %d, min = %d, max = %d [km/h]\n",
               measurement.speed, average, min, max);

        data_type = BIKE_CADENCE;
        min = bike_math_calculate_min_value(data_type);
        max = bike_math_calculate_max_value(data_type);
        average = bike_math_calculate_average_value(data_type);
        printf("CADENCE:\t%d, average = %d, min = %d, max = %d [rpm]\n",
               measurement.cadence, average, min, max);

        data_type = BIKE_HEART_RATE;
        min = bike_math_calculate_min_value(data_type);
        max = bike_math_calculate_max_value(data_type);
        average = bike_math_calculate_average_value(data_type);
        printf("HEART-RATE:\t%d, average = %d, min = %d, max = %d [hrm]\n",
               measurement.heart_rate, average, min, max);

        data_type = BIKE_POWER;
        min = bike_math_calculate_min_value(data_type);
        max = bike_math_calculate_max_value(data_type);
        average = bike_math_calculate_average_value(data_type);
        printf("POWER:\t\t%d, average = %d, min = %d, max = %d [watt]\n",
               measurement.power, average, min, max);
        printf("\n");

        sleep(1);
    }
}
