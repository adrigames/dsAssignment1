#ifndef QUEUE_HPP
#define QUEUE_HPP

#include <string>
#include <runtime_error>

struct cellType
{
    int value;
    celltype* next;
    }

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
