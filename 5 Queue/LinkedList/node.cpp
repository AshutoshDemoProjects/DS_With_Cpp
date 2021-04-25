#include "node.h"
Node::Node()
{
    this->prev = nullptr;
    this->data = 0;
    this->next = nullptr;
}
Node::Node(int data)
{
    this->prev = nullptr;
    this->data = data;
    this->next = nullptr;
}
Node::~Node()
{
    this->data = 0;
    this->next = nullptr;
}
Node *Node::getPrev()
{
    return this->prev;
}
void Node::setPrev(Node *prev)
{
    this->prev = prev;
}
int Node::getData()
{
    return this->data;
}
void Node::setData(int data)
{
    this->data = data;
}
Node *Node::getNext()
{
    return this->next;
}
void Node::setNext(Node *next)
{
    this->next = next;
}
std::ostream &operator<<(std::ostream &out, Node node)
{
    out << "(" << node.prev << " | " << node.data << " | " << node.next << ")";
    return out;
}