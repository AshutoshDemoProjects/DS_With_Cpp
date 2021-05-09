#include "queueNode.h"

#ifndef __queue_h__
#define __queue_h__
class Queue
{
    QueueNode *front;
    QueueNode *rear;

public:
    bool isEmpty();
    Queue();
    void enqueue(Node *);
    Node *dequeue();
    friend std::ostream &operator<<(std::ostream &, Queue);
};
#endif