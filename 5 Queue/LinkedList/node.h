#include <iostream>
class Node
{
    Node *prev;
    int data;
    Node *next;

public:
    Node();
    Node(int);
    ~Node();
    Node *getPrev();
    void setPrev(Node *next);
    int getData();
    void setData(int data);
    Node *getNext();
    void setNext(Node *next);
    friend std::ostream &operator<<(std::ostream &, Node);
};
