#include "sll.h"
SinglyLinkedList::SinglyLinkedList()
{
    this->head = nullptr;
    this->tail = nullptr;
}
bool SinglyLinkedList::isEmpty()
{
    return this->head == nullptr && this->tail == nullptr;
}
void SinglyLinkedList::insertFirst(int data)
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
        this->head = nn;
    }
}
void SinglyLinkedList::insert(int data, int pos) //O(n)
{
    int i = 1;
    Node *it = this->head;
    Node *nn = new Node(data);
    /* for (it = head, i = 1; it != nullptr && i != pos - 1; it = it->getNext(), i++)
        ; */
    while (it != nullptr && i < pos - 1)
    {
        it = it->getNext();
        i++;
    }
    if (it == nullptr)
        throw "Invalid Position";
    else if (it->getNext() == nullptr)
    {
        it->setNext(nn);
        this->tail = nn;
    }
    else
    {
        nn->setNext(it->getNext());
        it->setNext(nn);
    }
}
void SinglyLinkedList::insertEnd(int data)
{
    Node *nn = new Node(data);
    if (this->isEmpty())
    {
        this->head = nn;
        this->tail = nn;
    }
    else
    {
        this->tail->setNext(nn);
        this->tail = nn;
    }
}
int SinglyLinkedList::deleteFirst()
{

    if (this->isEmpty())
    {
        throw "Linked list is empty";
    }
    else
    {
        Node *temp;
        temp = this->head;
        this->head = temp->getNext(); //this->head->getNext();
        if (this->head == nullptr)
        {
            this->tail = nullptr;
        }
        int data = temp->getData();
        delete temp;
        return data;
    }
}
int SinglyLinkedList::remove(int pos)
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
        while (it != nullptr && i < pos - 1)
        {
            it = it->getNext();
            i++;
        }
        Node *temp = it->getNext();
        it->setNext(temp->getNext());
        if (it->getNext() == nullptr)
            this->tail = nullptr;
        int data = temp->getData();
        delete temp;
        return data;
    }
}
int SinglyLinkedList::deleteLast()
{
    if (this->isEmpty())
    {
        throw "Linked list is empty";
    }
    else
    {
        Node *it;
        it = this->head;
        if (it->getNext() == nullptr)
        {
            this->head = nullptr;
            this->tail = nullptr;
        }
        else
        {
            while (it->getNext() != tail)
            {
                it = it->getNext();
            }
            this->tail = it;
            it = it->getNext();
            this->tail->setNext(nullptr);
        }
        int data = it->getData();
        delete it;
        return data;
    }
}
int SinglyLinkedList::operator[](int pos)
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
std::ostream &operator<<(std::ostream &out, SinglyLinkedList ll)
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