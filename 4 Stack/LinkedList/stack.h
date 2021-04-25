#include "node.h"
class Stack
{
    Node *top;
    bool isEmpty();

public:
    Stack();
    void push(int);
    int pop();
    int peek();
    friend std::ostream &operator<<(std::ostream &, Stack);
};