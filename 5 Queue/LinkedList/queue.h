#include "node.h"
class Queue
{
    Node *front;
    Node *rear;
    bool isEmpty();

public:
    Queue();
    void enqueue(int data);
    int dequeue();
    friend std::ostream &operator<<(std::ostream &, Queue);
};