#include "node.h"
Node::Node()
{
    this->left = nullptr;
    this->data = 0;
    this->right = nullptr;
    this->height = 1;
}
Node::Node(int data)
{
    this->left = nullptr;
    this->data = data;
    this->right = nullptr;
    this->height = 1;
}
Node::~Node()
{
    this->data = 0;
    this->right = nullptr;
}
Node *Node::getLeft()
{
    return this->left;
}
void Node::setLeft(Node *left)
{
    this->left = left;
}
int Node::getData()
{
    return this->data;
}
void Node::setData(int data)
{
    this->data = data;
}
Node *Node::getRight()
{
    return this->right;
}
void Node::setRight(Node *right)
{
    this->right = right;
}
int Node::getHeight()
{
    return this->height;
}
void Node::setHeight(int height)
{
    this->height = height;
}
std::ostream &operator<<(std::ostream &out, Node node)
{
    out << "(" << node.left << " | " << node.data << " | " << node.right << ")";
    return out;
}