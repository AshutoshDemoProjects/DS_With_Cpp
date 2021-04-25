#include "stack.h"
Stack::Stack()
{
    this->size = 5;
    this->top = -1;
    this->arr = new int[this->size];
    for (int i = 0; i < this->size; i++)
        this->arr[i] = 0;
}
Stack::Stack(int size)
{
    this->size = size;
    this->top = -1;
    this->arr = new int[this->size];
    for (int i = 0; i < this->size; i++)
        this->arr[i] = 0;
}
bool Stack::isEmpty()
{
    return this->top == -1;
}
bool Stack::isFull()
{
    return this->top + 1 == size;
}
void Stack::push(int data)
{
    if (isFull())
    {
        throw "Stack overflow";
    }
    else
    {
        top++;
        arr[top] = data;
    }
}
int Stack::pop()
{
    if (isEmpty())
    {
        throw "Stack is empty";
    }
    else
    {
        int data = arr[top];
        arr[top] = 0;
        top--;
        return data;
    }
}
int Stack::peek()
{
    if (isEmpty())
    {
        throw "Stack is empty";
    }
    else
    {
        return arr[top];
    }
}
std::ostream &operator<<(std::ostream &out, Stack s)
{
    if (s.isEmpty())
    {
        out << "Stack is underflow" << std::endl;
    }
    else
    {
        for (int i = s.top; i >= 0; i--)
        {
            out << s.arr[i] << std::endl;
        }
    }
    return out;
}