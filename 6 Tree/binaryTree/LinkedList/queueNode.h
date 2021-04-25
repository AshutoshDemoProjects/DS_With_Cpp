#include "node.h"
#ifndef __queueNode_h__
#define __queueNode_h__
class QueueNode
{
    QueueNode *prev;
    Node *data;
    QueueNode *next;

public:
    QueueNode();
    QueueNode(Node *);
    ~QueueNode();
    QueueNode *getPrev();
    void setPrev(QueueNode *next);
    Node *getData();
    void setData(Node *data);
    QueueNode *getNext();
    void setNext(QueueNode *next);
};
#endif