#include "stack.h"
bool Stack::isEmpty()
{
    return this->top == nullptr;
}
Stack::Stack()
{
    this->top = nullptr;
}
void Stack::push(int data)
{
    Node *nn = new Node(data);
    if (!isEmpty())
    {
        nn->setNext(this->top);
    }
    this->top = nn;
}
int Stack::pop()
{
    if (isEmpty())
    {
        throw "Stack underflow";
    }
    else
    {
        int data = top->getData();
        Node *temp = top;
        top = top->getNext();
        delete temp;
        return data;
    }
}
int Stack::peek()
{
    return top->getData();
}
std::ostream &operator<<(std::ostream &out, Stack s)
{
    if (s.isEmpty())
    {
        throw "Stack underflow";
    }
    else
    {
        Node *it = s.top;
        while (it != nullptr)
        {
            out << (*it) << std::endl;
            it = it->getNext();
        }
    }
    return out;
}