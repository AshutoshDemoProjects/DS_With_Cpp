#include "binaryTree.h"
#include "queue.h"
BinaryTree::BinaryTree()
{
    this->root = nullptr;
}
void BinaryTree::preorder()
{
    this->preorder(this->root);
}
void BinaryTree::inorder()
{
    this->inorder(this->root);
}
void BinaryTree::postorder()
{
    this->postorder(this->root);
}
void BinaryTree::levelorder()
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
void BinaryTree::preorder(Node *root)
{
    if (root != nullptr)
    {
        std::cout << root->getData() << " ";
        preorder(root->getLeft());
        preorder(root->getRight());
    }
}
void BinaryTree::inorder(Node *root)
{
    if (root != nullptr)
    {
        inorder(root->getLeft());
        std::cout << root->getData() << " ";
        inorder(root->getRight());
    }
}
void BinaryTree::postorder(Node *root)
{
    if (root != nullptr)
    {
        postorder(root->getLeft());
        postorder(root->getRight());
        std::cout << root->getData() << " ";
    }
}
Node *BinaryTree::search(int data)
{
    if (root == nullptr)
        throw "Empty binary tree";
    else
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
            if (temp->getData() == data)
                return temp;
        }
        return nullptr;
    }
}
void BinaryTree::insert(int data)
{
    if (root == nullptr)
        root = new Node(data);
    else
    {
        Queue q;
        q.enqueue(root);
        Node *nn = new Node(data);
        while (!q.isEmpty())
        {
            Node *temp = q.dequeue();
            if (temp->getLeft()) //(temp->getLeft() != nullptr)
                q.enqueue(temp->getLeft());
            else
            {
                temp->setLeft(nn);
                return;
            }
            if (temp->getRight()) //(temp->getRight() != nullptr)
                q.enqueue(temp->getRight());
            else
            {
                temp->setRight(nn);
                return;
            }
        }
    }
}
void BinaryTree::remove(int data)
{
    root = remove(root, data);
}
Node *BinaryTree::remove(Node *root, int key)
{
    if (root == nullptr)
        return nullptr;
    if (root->getLeft() == nullptr && root->getRight() == nullptr)
    {
        if (root->getData() == key)
            return NULL;
        else
            return root;
    }
    Queue q;
    q.enqueue(root);
    Node *temp;
    Node *keyNode = nullptr;
    while (!q.isEmpty())
    {
        temp = q.dequeue();
        if (temp->getData() == key)
            keyNode = temp;
        if (temp->getLeft())
            q.enqueue(temp->getLeft());
        if (temp->getRight())
            q.enqueue(temp->getRight());
    }
    if (keyNode != nullptr)
    {
        int x = temp->getData();
        deleteDeepest(root, temp);
        keyNode->setData(x);
        return root;
    }
    else
        throw "key node not found";
}
void BinaryTree::deleteDeepest(Node *root, Node *d_node)
{
    Queue q;
    q.enqueue(root);
    Node *temp;
    while (!q.isEmpty())
    {
        temp = q.dequeue();
        if (temp == d_node)
        {
            temp = nullptr;
            delete d_node;
            return;
        }
        if (temp->getRight())
        {
            if (temp->getRight() == d_node)
            {
                temp->setRight(nullptr);
                delete d_node;
                return;
            }
            else
                q.enqueue(temp->getRight());
        }
        if (temp->getLeft())
        {
            if (temp->getLeft() == d_node)
            {
                temp->setLeft(nullptr);
                delete d_node;
                return;
            }
            else
                q.enqueue(temp->getLeft());
        }
    }
}