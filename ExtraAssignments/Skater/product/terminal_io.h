#ifndef TERMINAL_IO_H
#define TERMINAL_IO_H

#include "skater.h"

typedef enum
{
    MO_SHOW_ICESKATERS,
    MO_ADD_ICESKATER,
    MO_REMOVE_ICESKATER,
    MO_ADD_TIME,
    MO_SHOW_CLASSIFICATION,
    MO_SHOW_FINAL_CLASSIFICATION,
    MO_LOAD,
    MO_SAVE,
    MO_QUIT
} MenuOptions;

void clearScreen();
int getInt(const char* message);
int getLimitedInt(const char* message, const char* items[], int nrItems);
void getStr(const char* message, char* str, int maxLength);
MenuOptions getMenuChoice();

void printProgramHeader();

#endif
