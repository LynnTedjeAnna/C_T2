#include "encode.h"
#include "parity.h"

void encode_get_nibbles(uint8_t value, uint8_t* high, uint8_t* low){
    *high = (value & (0b1111 << 4)) >> 4;
    *low = value & 0b1111;
}

void encode_value(uint8_t input, uint8_t* high, uint8_t* low){{
        encode_get_nibbles(input, high, low);

        uint8_t parities = get(high);
        *high = (*high << 3) | parities;

        parities = get(low);
        *low = (*low << 3) | parities;
    }
}