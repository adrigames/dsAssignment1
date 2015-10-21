#ifndef AUXILIARY_H
#define AUXILIARY_H
#include <string>
#include <iostream>

struct cellType
{
    int value;
    cellType* next;
    };

std::string convertToString(long int);
int countDigits(long int);

#endif