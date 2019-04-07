//
// Created by DENIS LALLEMAND on 2019-04-07.
//
#include "tools.h"

int isLittleEndian()
{
    short int number = 0x1;
    char *numPtr = (char*)&number;
    return (numPtr[0] == 1);
}
