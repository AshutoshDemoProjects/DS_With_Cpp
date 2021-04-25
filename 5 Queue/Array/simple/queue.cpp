#include "queue.h"
bool Queue::isFull()
{
    return rear + 1 == size;
}
bool Queue::isEmpty()
{
    return front == -1;
}
Queue::Queue()
{
    rear = -1;
    front = -1;
    //rear = front = -1;
    size = 5;
    arr = new int[size];
    for (int i = 0; i < size; i++)
        arr[i] = 0;
}
Queue::Queue(int s)
{
    rear = -1;
    front = -1;
    //rear = front = -1;
    size = s;
    arr = new int[size];
    for (int i = 0; i < size; i++)
        arr[i] = 0;
}
void Queue::enqueue(int data)
{
    if (isFull())
        throw "queue is full";
    else
    {
        if (isEmpty())
            front++;
        rear++;
        arr[rear] = data;
    }
}
int Queue::dequeue()
{
    if (isEmpty())
    {
        throw "queue is empty";
    }
    else
    {
        int data = arr[front];
        arr[front] = 0;
        /* if (rear == front)
        {
            rear = -1;
            front = -1;
        }
        else
        {
            front++;
        } */
        rear == front ? rear = front = -1 : front++;
        return data;
    }
}
std::ostream &operator<<(std::ostream &out, Queue q)
{
    if (q.isEmpty())
        out << "Queue is empty";
    else
    {
        for (int i = q.front; i <= q.rear; i++)
        {
            out << q.arr[i] << " ";
        }
    }
    return out;
}