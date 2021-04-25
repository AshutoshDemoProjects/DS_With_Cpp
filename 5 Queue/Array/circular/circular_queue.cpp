#include "circular_queue.h"
bool CircularQueue::isFull()
{
    return (rear + 1) % size == front;
}
bool CircularQueue::isEmpty()
{
    return front == -1;
}
CircularQueue::CircularQueue()
{
    rear = -1;
    front = -1;
    //rear = front = -1;
    size = 5;
    arr = new int[size];
    for (int i = 0; i < size; i++)
        arr[i] = 0;
}
CircularQueue::CircularQueue(int s)
{
    rear = -1;
    front = -1;
    //rear = front = -1;
    size = s;
    arr = new int[size];
    for (int i = 0; i < size; i++)
        arr[i] = 0;
}
void CircularQueue::enqueue(int data)
{
    if (isFull())
        throw "queue is full";
    else
    {
        if (isEmpty())
            front++;
        rear = (rear + 1) % size;
        arr[rear] = data;
    }
}
int CircularQueue::dequeue()
{
    if (isEmpty())
    {
        throw "queue is empty";
    }
    else
    {
        int data = arr[front];
        arr[front] = 0;
        if (rear == front)
        {
            rear = -1;
            front = -1;
        }
        else
            front = (front + 1) % size;
        return data;
    }
}
std::ostream &operator<<(std::ostream &out, CircularQueue q)
{
    if (q.isEmpty())
        out << "Queue is empty";
    else
    {
        for (int i = q.front; i != q.rear; i = (i + 1) % q.size)
        {
            out << i << ":" << q.arr[i] << " ";
        }
        out << q.arr[q.rear];
    }
    return out;
}