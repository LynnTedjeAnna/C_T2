#include <stdio.h>
#include <string.h>

#include "io.h"

extern int encode_main(int argc, char* argv[]);
extern int channel_main(int argc, char* argv[]);
extern int decode_main(int argc, char* argv[]);

void my_exit(uint8_t result)
{
    io_close_file_for_reading();
    io_close_file_for_writing();
    exit(result);
}

int main(int argc, char* argv[])
{
    if (argc < 4)
    {
      printf("Please provide file name arguments:\n");
      printf("[encode|channel|decode] inputfile outpfile\n\n");
      printf("Example:\n");
      printf("main encode input.txt output.txt\n");
      exit(0);
    }

    printf("%s: %s --> %s\n", argv[1], argv[2], argv[3]);

    if(strcmp("encode", argv[1]) == 0)
    {
      return encode_main(argc,argv);
    }
    else if(strcmp("channel", argv[1]) == 0)
    {
      return channel_main(argc,argv);
    }
    else if(strcmp("decode", argv[1]) == 0)
    {
      return decode_main(argc,argv);
    }

    return 0;
}
