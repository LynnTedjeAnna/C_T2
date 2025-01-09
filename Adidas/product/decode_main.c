#include <stdio.h>
#include "decode.h"
#include "io.h"

extern void myExit(int result);

int decode_main(int argc, char* argv[])
{
    char* input_file_name = argv[2];
    char* output_file_name = argv[3];

    bool success = io_open_file_for_reading(input_file_name);
    if (!success){ exit(1);}

    success = io_open_file_for_writing(output_file_name);
    if (!success){ exit(1);}

    uint8_t high = 0, low = 0;
    uint8_t nibbe_high = 0, nibbe_low = 0;
    while (true)
    {
        success = io_read_byte(&high);
        if (!success){ break;}

        success = io_read_byte(&low);
        if (!success){
            printf("Expecting another byte in the file!\n");
            printf("Will not decode previous nibble.\n");
            break;
        }

        decode_byte(high, &nibbe_high);
        decode_byte(low, &nibbe_low);

        char decoded = decode_combine_nibbles(nibbe_high, nibbe_low);

        success = io_write_byte(decoded);
        if (!success){ exit(1);}
    }
    exit(0);
    return 0;
}
