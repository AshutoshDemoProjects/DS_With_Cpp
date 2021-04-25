#include "node.h"
#ifndef __binarySearch_h__
#define __binarySearch_h__
class BinarySearchTree
{
    Node *root;
    void preorder(Node *);
    void inorder(Node *);
    void postorder(Node *);
    Node *remove(Node *, int);
    void deleteDeepest(Node *, Node *);
    Node *search(Node *, int);
    Node *insert(Node *, int);
    Node *minValueNode(Node *);

public:
    BinarySearchTree();
    void preorder();
    void inorder();
    void postorder();
    void levelorder();
    Node *search(int);
    void insert(int);
    void remove(int);
};
#endif