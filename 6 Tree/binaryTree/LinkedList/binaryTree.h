#include "node.h"
#ifndef __binarySearch_h__
#define __binarySearch_h__
class BinaryTree
{
    Node *root;
    void preorder(Node *);
    void inorder(Node *);
    void postorder(Node *);
    Node *remove(Node *, int);
    void deleteDeepest(Node *, Node *);

public:
    BinaryTree();
    void preorder();
    void inorder();
    void postorder();
    void levelorder();
    Node *search(int);
    void insert(int);
    void remove(int);
};
#endif