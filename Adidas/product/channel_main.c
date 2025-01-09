#include <stdbool.h>
#include "channel.h"
#include "io.h"

extern void myExit(int result);

int channel_main(int argc, char* argv[])
{
    char* input_file_name = argv[2];
    char* output_file_name = argv[3];

    bool success = io_open_file_for_reading(input_file_name);
    if (!success) { exit(1); }
    success = io_open_file_for_writing(output_file_name);
   if (!success) { exit(1); }
    channel_init();

    uint8_t byte_read = 0;
    bool even = false;
    uint32_t index = 0;

    while (io_read_byte(&byte_read))
    {
        even = (index % 2) == 0;
        if (even){
            byte_read = channel_change_one_random_bit(byte_read);
        }

        success = io_write_byte(byte_read);
       if (!success) { exit(1); }
        index++;
    }

   exit(0);

    return 0;
}
