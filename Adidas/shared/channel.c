#include <stdlib.h>
#include <time.h>
#include "channel.h"
void channel_init(){
    srand(time(NULL)); // take the current time as seed for random generator
}

uint8_t channel_change_one_random_bit(uint8_t value){
    uint8_t bit = rand() % 8; // get a random bit to change
    value ^= (1 << bit); // change the bit
    return value;
}
