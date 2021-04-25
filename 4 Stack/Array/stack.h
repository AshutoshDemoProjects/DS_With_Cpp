#include <iostream>
class Stack
{
    int *arr;
    int size;
    int top;
    bool isEmpty();
    bool isFull();

public:
    Stack();
    Stack(int);
    void push(int);
    int pop();
    int peek();
    friend std::ostream &operator<<(std::ostream &, Stack);
};