#include "decode.h"
#include "parity.h"

#include "stdio.h"

uint8_t decode_combine_nibbles(uint8_t high, uint8_t low){ return (high << 4) | low; }

void decode_byte(uint8_t in, uint8_t* nibble){
    in &= ~0b10000000;
    *nibble = (in >> 3);
    uint8_t parities = get(nibble);
    uint8_t syndrome = parities ^ (in & 0b111);
    if (syndrome == 0) { return; }
    if (syndrome == 1) { return; }
    if (syndrome == 2) { return; }
    if (syndrome == 4) { return; }
    uint8_t off_set = syndrome - 3;
    off_set >>= (2*(off_set >> 2));
    *nibble = *nibble ^ (0b1 << off_set);
}