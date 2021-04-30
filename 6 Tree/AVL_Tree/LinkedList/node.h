#include <iostream>
#ifndef __node_h__
#define __node_h__
class Node
{
    Node *left;
    int data;
    Node *right;
    int height;

public:
    Node();
    Node(int);
    ~Node();
    Node *getLeft();
    void setLeft(Node *);
    int getData();
    void setData(int data);
    Node *getRight();
    void setRight(Node *);
    int getHeight();
    void setHeight(int height);
    friend std::ostream &operator<<(std::ostream &, Node);
};
#endif