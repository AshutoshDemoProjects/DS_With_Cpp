#include "queueNode.h"
QueueNode::QueueNode()
{
    this->prev = nullptr;
    this->data = 0;
    this->next = nullptr;
}
QueueNode::QueueNode(Node *data)
{
    this->prev = nullptr;
    this->data = data;
    this->next = nullptr;
}
QueueNode::~QueueNode()
{
    this->data = 0;
    this->next = nullptr;
}
QueueNode *QueueNode::getPrev()
{
    return this->prev;
}
void QueueNode::setPrev(QueueNode *prev)
{
    this->prev = prev;
}
Node *QueueNode::getData()
{
    return this->data;
}
void QueueNode::setData(Node *data)
{
    this->data = data;
}
QueueNode *QueueNode::getNext()
{
    return this->next;
}
void QueueNode::setNext(QueueNode *next)
{
    this->next = next;
}