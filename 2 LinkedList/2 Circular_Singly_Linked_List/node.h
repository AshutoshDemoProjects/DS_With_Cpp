#include <iostream>
class Node
{
    int data;
    Node *next;

public:
    Node();
    Node(int);
    ~Node();
    int getData();
    void setData(int data);
    Node *getNext();
    void setNext(Node *next);
    friend std::ostream &operator<<(std::ostream &, Node);
};
