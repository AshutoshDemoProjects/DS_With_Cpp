#include "binarySearchTree.h"
#include "queue.h"
BinarySearchTree::BinarySearchTree()
{
    this->root = nullptr;
}
void BinarySearchTree::preorder()
{
    this->preorder(this->root);
}
void BinarySearchTree::inorder()
{
    this->inorder(this->root);
}
void BinarySearchTree::postorder()
{
    this->postorder(this->root);
}
void BinarySearchTree::levelorder()
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
void BinarySearchTree::preorder(Node *root)
{
    if (root != nullptr)
    {
        std::cout << root->getData() << " ";
        preorder(root->getLeft());
        preorder(root->getRight());
    }
}
void BinarySearchTree::inorder(Node *root)
{
    if (root != nullptr)
    {
        inorder(root->getLeft());
        std::cout << root->getData() << " ";
        inorder(root->getRight());
    }
}
void BinarySearchTree::postorder(Node *root)
{
    if (root != nullptr)
    {
        postorder(root->getLeft());
        postorder(root->getRight());
        std::cout << root->getData() << " ";
    }
}
Node *BinarySearchTree::search(int key)
{
    return search(root, key);
}
Node *BinarySearchTree::search(Node *root, int key)
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
void BinarySearchTree::insert(int data)
{
    root = insert(root, data);
}
Node *BinarySearchTree::insert(Node *currentNode, int data)
{
    if (currentNode == nullptr)
        currentNode = new Node(data);
    else if (data < currentNode->getData())
        currentNode->setLeft(insert(currentNode->getLeft(), data));
    else
        currentNode->setRight(insert(currentNode->getRight(), data));
    return currentNode;
}
void BinarySearchTree::remove(int data)
{
    root = remove(root, data);
}
Node *BinarySearchTree::remove(Node *root, int key)
{
    if (root == nullptr)
        return nullptr;
    if (key > root->getData())
        root->setRight(remove(root->getRight(), key));
    else if (key < root->getData())
        root->setLeft(remove(root->getLeft(), key));
    else
    {
        Node *temp;
        if (root->getLeft() == nullptr)
        {
            temp = root->getRight();
            delete root;
            return temp;
        }
        else if (root->getRight() == nullptr)
        {
            temp = root->getLeft();
            delete root;
            return temp;
        }
        temp = minValueNode(root->getRight());
        root->setData(temp->getData());
        root->setRight(remove(root->getRight(), temp->getData()));
    }
    return root;
}
Node *BinarySearchTree::minValueNode(Node *node)
{
    Node *current = node;
    while (current && current->getLeft() != NULL)
        current = current->getLeft();

    return current;
}
void BinarySearchTree::deleteDeepest(Node *root, Node *d_node)
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