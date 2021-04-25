#include "AVLTree.h"
#include "queue.h"
AVLTree::AVLTree()
{
    this->root = nullptr;
}
void AVLTree::preorder()
{
    this->preorder(this->root);
}
void AVLTree::inorder()
{
    this->inorder(this->root);
}
void AVLTree::postorder()
{
    this->postorder(this->root);
}
void AVLTree::levelorder()
{
    Queue q;
    q.enqueue(root);
    while (!q.isEmpty())
    {
        Node *temp = q.dequeue();
        if (temp->getLeft() != nullptr)
            q.enqueue(temp->getLeft());
        if (temp->getRight() != nullptr)
            q.enqueue(temp->getRight());
        std::cout << temp->getData() << " ";
    }
}
void AVLTree::preorder(Node *root)
{
    if (root != nullptr)
    {
        std::cout << root->getData() << " ";
        preorder(root->getLeft());
        preorder(root->getRight());
    }
}
void AVLTree::inorder(Node *root)
{
    if (root != nullptr)
    {
        inorder(root->getLeft());
        std::cout << root->getData() << " ";
        inorder(root->getRight());
    }
}
void AVLTree::postorder(Node *root)
{
    if (root != nullptr)
    {
        postorder(root->getLeft());
        postorder(root->getRight());
        std::cout << root->getData() << " ";
    }
}
Node *AVLTree::search(int key)
{
    return search(root, key);
}
Node *AVLTree::search(Node *root, int key)
{
    if (root == nullptr)
        return nullptr;
    else if (root->getData() == key)
        return root;
    else if (root->getData() > key)
        search(root->getRight(), key);
    else if (root->getData() < key)
        search(root->getLeft(), key);
}
void AVLTree::insert(int data)
{
    root = insert(root, data);
}
Node *AVLTree::insert(Node *currentNode, int data)
{
    /////////////////////////
    return currentNode;
}
void AVLTree::remove(int data)
{
    root = remove(root, data);
}
Node *AVLTree::remove(Node *root, int key)
{
    ////////////////////////////////////
    return root;
}
Node *AVLTree::minValueNode(Node *node)
{
    Node *current = node;
    while (current && current->getLeft() != NULL)
        current = current->getLeft();

    return current;
}