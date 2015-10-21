#ifndef QUEUE_HPP
#define QUEUE_HPP

#include <iostream>
#include <stdexcept>
#include <string>
#include <sstream>
#include "auxiliary.h"

class Queue
{
    cellType* front;
    cellType* rear;
public:
    Queue();
    ~Queue();
    void enqueue(long int);
    long int dequeue(void);
    void makenull(void);
    bool empty(void);
    std::string list(void);
};

#endif // QUEUE_HPP
