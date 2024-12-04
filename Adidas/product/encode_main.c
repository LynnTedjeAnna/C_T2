#include "encode.h"
#include "io.h"

extern void my_exit(uint8_t result);

uint8_t encode_main(uint8_t argc, char* argv[])
{
    char* input_file_name = argv[2];
    char* output_file_name = argv[3];

    bool success = io_open_file_for_reading(input_file_name);
    if (!success)
        my_exit(1);

    success = io_open_file_for_writing(output_file_name);
    if (!success)
        my_exit(1);

    uint8_t high = 0, low = 0;
    uint8_t byteRead = 0;
    while (io_read_byte(&byteRead))
    {
        encode_value(byteRead, &high, &low);

        success = io_write_byte(high);
        if (!success)
            my_exit(1);
        success = io_write_byte(low);
        if (!success)
            my_exit(1);
    }

    my_exit(0);

    return 0;
}
