#include <stdio.h>
#include <string.h>

#include "terminal_io.h"

#define MAX_STRLEN 80

static const char* SpeciesNames[] = { "Cat", "Dog", "Guinea pig", "Parrot" };

static const char* SexNames[] = { "Male", "Female" };


static const char* MenuStrings[] = {
    "Show animals",
    "Add animal",
    "Remove animal",
    "Sort animals by age",
    "Sort animals by year found",
    "Sort animals by sex",
    "Find animal",
    "Load administration from disk",
    "Save administration to disk",
    "Quit"
};
static const size_t NrMenuStrings =
            sizeof(MenuStrings) / sizeof(MenuStrings[0]);

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
        for (int i = 0; i < nrItems; i++)
        {
            printf("  [%d] %s\n", i, items[i]);
        }
        choice = getInt(message);
    } while (choice < 0 || choice >= nrItems);

    return choice;
}

MenuOptions getMenuChoice(void)
{
    return (MenuOptions)getLimitedInt("choice: ", MenuStrings, NrMenuStrings);
}

Date getDate(const char* message)
{
    Date temp = { 0, 0, 0 };
    printf("%s", message);
    temp.Day = getInt("  enter day: ");
    temp.Month = getInt("  enter month: ");
    temp.Year = getInt("  enter year: ");
    return temp;
}

void printAnimals(const Animal* animals, int nrAnimals)
{
    if (animals != NULL)
    {
        if (nrAnimals <= 0)
        {
            printf("\nAnimal array is empty, or nrAnimals is less than 0\n\n");
        }
        else
        {
            for (int i = 0; i < nrAnimals; i++)
            {
                printf("\nAnimal %d:\n", i + 1);
                printf("Id:     %d\n", animals[i].Id);
                printf("Species:  %s\n", SpeciesNames[animals[i].Species]);
                printf("Sex:      %s\n", SexNames[animals[i].Sex]);
                printf("Age:      %d\n", animals[i].Age);
                printf("Animal was found:\n");
                printf("  at date:     %02d-%02d-%02d\n",
                       animals[i].DateFound.Day, animals[i].DateFound.Month,
                       animals[i].DateFound.Year);
            }
        }
    }
} 
