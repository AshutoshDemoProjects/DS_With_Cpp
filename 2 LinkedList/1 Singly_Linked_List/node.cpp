#include "node.h"
Node::Node()
{
    this->data = 0;
    this->next = nullptr;
}
Node::Node(int data)
{
    this->data = data;
    this->next = nullptr;
}
Node::~Node()
{
    this->data = 0;
    this->next = nullptr;
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
    out << "(" << node.data << "|" << node.next << ")";
    return out;
}