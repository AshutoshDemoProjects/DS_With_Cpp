#include <iostream>
class CircularQueue
{
    int *arr;
    int size;
    int front;
    int rear;

    bool isFull();
    bool isEmpty();

public:
    CircularQueue();
    CircularQueue(int);
    void enqueue(int);
    int dequeue();
    friend std::ostream &operator<<(std::ostream &, CircularQueue);
};