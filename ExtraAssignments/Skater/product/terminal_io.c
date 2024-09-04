#include <limits.h>
#include <stdio.h>
#include <string.h>

#include "terminal_io.h"


#define MAX_STRLEN 80

static const char* MenuStrings[] =
{
    "Show Iceskaters",
    "Add Iceskater",
    "Remove Iceskater",
    "Add time",
    "Show classification",
    "Show final classification",
    "Load ...",
    "Save ...",
    "Quit"
};
static const size_t NrMenuStrings =
            sizeof(MenuStrings) / sizeof(MenuStrings[0]);

void clearScreen()
{
    printf("\033[2J\033[1;1H");
}

int getInt(const char* message)
{
    char line[MAX_STRLEN];
    char* result = NULL;
    int value = -1;

    printf("%s", message);
    result = fgets(line, sizeof(line), stdin);
    if (result != NULL)
    {
        sscanf(result, "%d", &value);
    }

    return value;
}

int getLimitedInt(const char* message, const char* items[], int nrItems)
{
    int choice = -1;
    do
    {
        if (items != NULL)
        {
            for (int i = 0; i < nrItems; i++)
            {
                printf("  [%d] %s\n", i, items[i]);
            }
        }
        choice = getInt(message);
    } while (choice < 0 || choice >= nrItems);

    return choice;
}

void getStr(const char* message, char* str, int maxLength)
{
    char line[maxLength];
    char* result = NULL;

    printf("%s", message);
    result = fgets(line, sizeof(line), stdin);
    if (result != NULL)
    {
        if (result[strlen(result) - 1] == '\n')
        {
            result[strlen(result) - 1] = '\0';
        }
        strncpy(str, result, maxLength);
        str[maxLength - 1] = '\0';
    }
}

MenuOptions getMenuChoice()
{
    printf("\n\nMENU\n====\n");
    return (MenuOptions)getLimitedInt("choice: ", MenuStrings, NrMenuStrings);
}

void printProgramHeader()
{
    printf("PRC2 opdracht 'Schaatsen'\n"
           "-------------------------");
}
