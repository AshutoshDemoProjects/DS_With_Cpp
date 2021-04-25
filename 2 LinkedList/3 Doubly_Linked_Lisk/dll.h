#include "node.h"
class DoublyLinkedList
{
    Node *head;
    Node *tail;
    bool isEmpty();

public:
    DoublyLinkedList();
    void insertFirst(int data);
    void insert(int, int);
    void insertEnd(int data);
    int deleteFirst();
    int remove(int);
    int deleteLast();
    int operator[](int);
    friend std::ostream &operator<<(std::ostream &, DoublyLinkedList);
};