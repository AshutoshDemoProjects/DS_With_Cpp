#include "node.h"
class SinglyLinkedList
{
    Node *head;
    Node *tail;
    bool isEmpty();

public:
    SinglyLinkedList();
    void insertFirst(int data);
    void insert(int, int);
    void insertEnd(int data);
    int deleteFirst();
    int remove(int);
    int deleteLast();
    int operator[](int);
    friend std::ostream &operator<<(std::ostream &, SinglyLinkedList);
};