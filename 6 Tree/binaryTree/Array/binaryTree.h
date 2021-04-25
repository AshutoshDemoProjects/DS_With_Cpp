#include <iostream>
#ifndef __binarySearch_h__
#define __binarySearch_h__
class BinaryTree
{
    int *arr;
    int size;
    int lastUsedIndex;
    bool isFull();

    void inorder(int);
    void preorder(int);
    void postorder(int);

public:
    BinaryTree(int = 5);
    void preorder();
    void inorder();
    void postorder();
    void levelorder();
    int search(int);
    void insert(int);
    void remove(int);
};

#endif