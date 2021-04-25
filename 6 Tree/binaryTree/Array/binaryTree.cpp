
#include "binaryTree.h"
BinaryTree::BinaryTree(int s)
{
    size = s;
    arr = new int[size];
    lastUsedIndex = 0;
    for (int i = 0; i < size; i++)
        arr[i] = 0;
}
bool BinaryTree::isFull()
{
    return lastUsedIndex == size - 1;
}
void BinaryTree::preorder()
{
    preorder(1);
}
void BinaryTree::preorder(int index)
{
    if (index > lastUsedIndex)
    {
        return;
    }
    else
    {
        std::cout << arr[index] << " ";
        preorder(index * 2);
        preorder(index * 2 + 1);
    }
}
void BinaryTree::inorder()
{
    inorder(1);
}
void BinaryTree::inorder(int index)
{
    if (index > lastUsedIndex)
    {
        return;
    }
    else
    {
        inorder(index * 2);
        std::cout << arr[index] << " ";
        inorder(index * 2 + 1);
    }
}
void BinaryTree::postorder()
{
    postorder(1);
}
void BinaryTree::postorder(int index)
{
    if (index > lastUsedIndex)
    {
        return;
    }
    else
    {
        postorder(index * 2);
        postorder(index * 2 + 1);
        std::cout << arr[index] << " ";
    }
}
void BinaryTree::levelorder()
{
    for (int i = 1; i <= lastUsedIndex; i++)
    {
        std::cout << arr[i] << " ";
    }
}
int BinaryTree::search(int data)
{
    for (int i = 1; i <= lastUsedIndex; i++)
    {
        if (arr[i] == data)
        {
            return i;
        }
    }
    return -1;
}
void BinaryTree::insert(int data)
{
    if (isFull())
    {
        throw "Tree is full.";
    }
    else
    {
        lastUsedIndex++;
        arr[lastUsedIndex] = data;
    }
}
void BinaryTree::remove(int data)
{
    int index = search(data);
    if (index == -1)
    {
        throw "Node not found";
    }
    else
    {
        arr[index] = arr[lastUsedIndex];
        arr[lastUsedIndex] = 0;
        lastUsedIndex--;
    }
}
