#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "administration.h"
#include "animal.h"
#include "terminal_io.h"


static void addTestData(Animal* animals, size_t* nrAnimals)
{
    Animal a1 = { 1, Dog, Male, 12, { 1, 2, 3 } };
    Animal a2 = { 2, Cat, Female, 4, { 4, 3, 2 } };
    Animal a3 = { 3, Parrot, Male, 40, { 8, 9, 10 } };
    Animal a4 = { 4, Dog, Female, 1, { 1, 1, 100 } };
    Animal a5 = { 5, GuineaPig, Male, 3, { 3, 4, 1 } };

    animals[(*nrAnimals)++] = a1;
    animals[(*nrAnimals)++] = a2;
    animals[(*nrAnimals)++] = a3;
    animals[(*nrAnimals)++] = a4;
    animals[(*nrAnimals)++] = a5;
}

int main(int argc, char* argv[])
{
    const size_t MaxNrAnimals = 20;
    Animal animals[MaxNrAnimals];
    size_t nrAnimals = 0;
    MenuOptions choice = MO_SHOW_ANIMALS;

    addTestData(animals, &nrAnimals);

    printf("PRC assignment 'Animal Shelter'\n"
           "-------------------------------------------");

    if (argc != 1)
    {
        fprintf(stderr, "%s: argc=%d\n", argv[0], argc);
    }

    while (choice != MO_QUIT)
    {
        printf("\n\nMENU\n====\n\n");
        choice = getMenuChoice();

        switch (choice)
        {
            case MO_SHOW_ANIMALS:
                break;
            case MO_ADD_ANIMAL:
                break;
            case MO_REMOVE_ANIMAL:
                break;
            case MO_SORT_ANIMALS_BY_AGE:
                break;
            case MO_SORT_ANIMALS_BY_YEAR_FOUND:
                break;
            case MO_SORT_ANIMALS_BY_SEX:
                break;
            case MO_FIND_ANIMAL:
                break;
            case MO_SAVE:
                break;
            case MO_LOAD:
                break;
            case MO_QUIT:
                break;
            default:
                printf("ERROR: invalid choice: %d\n", choice);
                break;
        }
    }
    return 0;
}
