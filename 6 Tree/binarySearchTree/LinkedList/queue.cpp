#include "queue.h"
bool Queue::isEmpty()
{
    return this->front == nullptr && this->rear == nullptr;
}
Queue::Queue()
{
    this->front = nullptr;
    this->rear = nullptr;
}
void Queue::enqueue(Node *data)
{
    QueueNode *nn = new QueueNode(data);
    if (this->isEmpty())
    {
        this->front = nn;
        this->rear = nn;
    }
    else
    {
        rear->setNext(nn);
        nn->setPrev(rear);
        rear = nn;
    }
}
Node *Queue::dequeue()
{
    Node *data;
    if (this->isEmpty())
        throw "List is empty";
    else
    {
        QueueNode *temp = this->front;
        front = front->getNext();
        if (front == nullptr)
            rear = nullptr;
        else
            front->setPrev(nullptr);
        data = temp->getData();
        delete temp;
        return data;
    }
}