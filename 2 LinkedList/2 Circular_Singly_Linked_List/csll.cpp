#include "csll.h"
CircularSinglyLinkedList::CircularSinglyLinkedList()
{
    this->tail = nullptr;
}
bool CircularSinglyLinkedList::isEmpty()
{
    return this->tail == nullptr;
}
void CircularSinglyLinkedList::insertFirst(int data)
{
    Node *nn = new Node(data);
    if (this->isEmpty())
    {
        this->tail = nn;
        nn->setNext(nn);
    }
    else
    {
        nn->setNext(tail->getNext());
        tail->setNext(nn);
    }
}
void CircularSinglyLinkedList::insert(int data, int pos)
{
    Node *nn = new Node(data);
    if (this->isEmpty())
    {
        if (pos == 1)
        {
            this->tail = nn;
            nn->setNext(nn);
        }
        else
        {
            throw "Invalid position";
        }
    }
    else
    {
        Node *it = tail->getNext();
        int i = 1;
        while (it != tail && i < pos - 1)
        {
            it = it->getNext();
            i++;
        }
        if (it == tail)
        {
            throw "invalid position";
        }
        else
        {
            nn->setNext(it->getNext());
            it->setNext(nn);
        }
    }
}
void CircularSinglyLinkedList::insertEnd(int data)
{
    Node *nn = new Node(data);
    if (this->isEmpty())
    {
        tail = nn;
        nn->setNext(nn);
    }
    else
    {
        nn->setNext(tail->getNext());
        tail->setNext(nn);
        tail = nn;
    }
}
int CircularSinglyLinkedList::deleteFirst()
{
    if (isEmpty())
    {
        throw "List is empty";
    }
    else
    {
        Node *temp = tail->getNext();
        tail->setNext(temp->getNext());
        int data = temp->getData();
        delete temp;
        return data;
    }
}
int CircularSinglyLinkedList::remove(int pos)
{
    if (this->isEmpty())
    {
        throw "Linked list is empty";
    }
    else
    {
        int i = 1;
        Node *it = tail->getNext();
        while (it != tail && i < pos - 1)
        {
            it = it->getNext();
            i++;
        }
        Node *temp = it->getNext();
        it->setNext(temp->getNext());
        int data = temp->getData();
        delete temp;
        return data;
    }
}
int CircularSinglyLinkedList::deleteLast()
{
    int data;
    if (this->isEmpty())
    {
        throw "Linked list is empty";
    }
    else if (tail->getNext() == tail)
    {
        data = tail->getData();
        delete tail;
        tail = nullptr;
        return data;
    }
    else
    {
        Node *it = tail->getNext();
        while (it->getNext() != tail)
        {
            it = it->getNext();
        }
        tail = it;
        it = it->getNext();
        tail->setNext(it->getNext());
        data = it->getData();
        delete it;
        return data;
    }
}
std::ostream &operator<<(std::ostream &out, CircularSinglyLinkedList ll)
{
    if (ll.isEmpty())
    {
        out << "Linked List is empty";
    }
    else
    {
        Node *i;
        for (i = ll.tail->getNext(); i != ll.tail; i = i->getNext())
        {
            out << (*i) << "->";
        }
        out << (*i);
    }
    return out;
}