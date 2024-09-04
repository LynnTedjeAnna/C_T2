#ifndef TERMINAL_IO_H
#define TERMINAL_IO_H

#include "animal.h"

typedef enum
{
    MO_SHOW_ANIMALS,
    MO_ADD_ANIMAL,
    MO_REMOVE_ANIMAL,
    MO_SORT_ANIMALS_BY_AGE,
    MO_SORT_ANIMALS_BY_YEAR_FOUND,
    MO_SORT_ANIMALS_BY_SEX,
    MO_FIND_ANIMAL,
    MO_LOAD,
    MO_SAVE,
    MO_QUIT
} MenuOptions;

 
MenuOptions getMenuChoice(void);
void printAnimals(const Animal* animals, int nrAnimals);
//add the missing functions

#endif
