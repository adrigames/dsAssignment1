#ifndef AUXILIARY_H
#define AUXILIARY_H
#include <iostream>
#include <cstdlib>

struct cellType
{
    int value;
    cellType* next;
    };

int parse(char c, long int*, int, bool*);

#endif