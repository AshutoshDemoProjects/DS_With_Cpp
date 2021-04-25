#include "dll.h"
bool DoublyLinkedList::isEmpty()
{
    return this->head == nullptr && this->tail == nullptr;
}
DoublyLinkedList::DoublyLinkedList()
{
    this->head = nullptr;
    this->tail = nullptr;
}
void DoublyLinkedList::insertFirst(int data)
{
    Node *nn = new Node(data);
    if (this->isEmpty())
    {
        this->head = nn;
        this->tail = nn;
    }
    else
    {
        nn->setNext(this->head);
        head->setPrev(nn);
        head = nn;
    }
}
void DoublyLinkedList::insert(int data, int pos)
{
    int i = 1;
    Node *it = this->head;
    Node *nn = new Node(data);
    while (it != nullptr && i < pos - 1)
    {
        it = it->getNext();
        i++;
    }
    if (it == nullptr)
        throw "Invalid Position";
    else if (it->getNext() == nullptr)
    {
        nn->setPrev(it);
        it->setNext(nn);
        this->tail = nn;
    }
    else
    {
        nn->setPrev(it);
        nn->setNext(it->getNext());
        it->getNext()->setPrev(nn);
        it->setNext(nn);
    }
}
void DoublyLinkedList::insertEnd(int data)
{
    Node *nn = new Node(data);
    if (this->isEmpty())
    {
        this->head = nn;
        this->tail = nn;
    }
    else
    {
        tail->setNext(nn);
        nn->setPrev(tail);
        tail = nn;
    }
}
int DoublyLinkedList::deleteFirst()
{
    int data;
    if (this->isEmpty())
        throw "List is empty";
    else
    {
        Node *temp = this->head;
        head = head->getNext();
        head->setPrev(nullptr);
        data = temp->getData();
        delete temp;
        return data;
    }
}
int DoublyLinkedList::remove(int pos)
{
    if (this->isEmpty())
    {
        throw "Linked list is empty";
    }
    else
    {
        Node *it;
        int i = 1;
        it = this->head;
        while (it != nullptr && i < pos)
        {
            it = it->getNext();
            i++;
        }
        it->getPrev()->setNext(it->getNext());
        it->getNext()->setPrev(it->getPrev());
        int data = it->getData();
        delete it;
        return data;
    }
}
int DoublyLinkedList::deleteLast()
{
    int data;
    if (this->isEmpty())
        throw "List is empty";
    else
    {
        Node *temp = this->tail;
        tail = tail->getPrev();
        tail->setNext(nullptr);
        data = temp->getData();
        delete temp;
        return data;
    }
}
int DoublyLinkedList::operator[](int pos)
{
    if (this->isEmpty())
    {
        throw "Linked list is empty";
    }
    else
    {
        Node *it;
        int i = 0;
        it = this->head;
        while (it != nullptr && i < pos)
        {
            it = it->getNext();
            i++;
        }
        if (it == nullptr)
            throw "invalid Position...";
        else
        {
            int data = it->getData();
            return data;
        }
    }
}
std::ostream &operator<<(std::ostream &out, DoublyLinkedList ll)
{
    if (ll.isEmpty())
    {
        out << "Linked List is empty";
    }
    else
    {
        Node *i;
        for (i = ll.head; i != ll.tail; i = i->getNext())
        {
            out << (*i) << "->";
        }
        out << (*i);
    }
    return out;
}