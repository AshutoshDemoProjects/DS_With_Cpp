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
void Queue::enqueue(int data)
{
    Node *nn = new Node(data);
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
int Queue::dequeue()
{
    int data;
    if (this->isEmpty())
        throw "List is empty";
    else
    {
        Node *temp = this->front;
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
std::ostream &operator<<(std::ostream &out, Queue ll)
{
    if (ll.isEmpty())
    {
        out << "Linked List is empty";
    }
    else
    {
        Node *i;
        for (i = ll.front; i != ll.rear; i = i->getNext())
        {
            out << (*i) << "->";
        }
        out << (*i);
    }
    return out;
}