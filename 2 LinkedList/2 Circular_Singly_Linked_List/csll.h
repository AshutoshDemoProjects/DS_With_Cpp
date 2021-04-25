#include "node.h"
class CircularSinglyLinkedList
{
    Node *tail;
    bool isEmpty();

public:
    CircularSinglyLinkedList();
    void insertFirst(int data);
    void insert(int, int);
    void insertEnd(int data);
    int deleteFirst();
    int remove(int);
    int deleteLast();
    friend std::ostream &operator<<(std::ostream &, CircularSinglyLinkedList);
};