#ifndef STACK_HPP
#define STACK_HPP

#include "auxiliary.h"
class Stack
{
    cellType* top;
public:
    Stack();
    ~Stack();
    void push(long int);
    long int pop(void);
    void makenull(void);
    bool empty(void);
};

#endif // STACK_HPP
