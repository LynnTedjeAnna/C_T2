#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Add your includes here:
#include "terminal_io.h"


int main(int argc, char* argv[])
{
    MenuOptions choice = MO_SHOW_ICESKATERS;
    printProgramHeader();

    while (choice != MO_QUIT)
    {
        choice = getMenuChoice();

        switch (choice)
        {
        case MO_SHOW_ICESKATERS:
            fprintf(stderr, "not yet implemented\n");
            break;
        case MO_ADD_ICESKATER:
            fprintf(stderr, "not yet implemented\n");
            break;
        case MO_REMOVE_ICESKATER:
            fprintf(stderr, "not yet implemented\n");
            break;
        case MO_ADD_TIME:
            fprintf(stderr, "not yet implemented\n");
            break;
        case MO_SHOW_CLASSIFICATION:
            fprintf(stderr, "not yet implemented\n");
            break;
        case MO_SHOW_FINAL_CLASSIFICATION:
            fprintf(stderr, "not yet implemented\n");
            break;
        case MO_LOAD:
            fprintf(stderr, "not yet implemented\n");
            break;
        case MO_SAVE:
            fprintf(stderr, "not yet implemented\n");
            break;
        case MO_QUIT:
            // nothing to do here
            break;
        default:
            fprintf(stderr, "ERROR: invalid choice: %d\n", choice);
            break;
        }
    }
    return 0;
}
