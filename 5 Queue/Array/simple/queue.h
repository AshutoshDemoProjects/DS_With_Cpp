#include <iostream>
class Queue
{
    int *arr;
    int size;
    int front;
    int rear;

    bool isFull();
    bool isEmpty();

public:
    Queue();
    Queue(int);
    void enqueue(int);
    int dequeue();
    friend std::ostream &operator<<(std::ostream &, Queue);
};