#include "binarySearchTree.h"
#include "queue.h"
BinarySearchTree::BinarySearchTree()
{
    this->root = nullptr;
}

void BinarySearchTree::preorder()
{
    this->preorder(this->root);
    std::cout << std::endl;
}
void BinarySearchTree::inorder()
{
    this->inorder(this->root);
    std::cout << std::endl;
}
void BinarySearchTree::postorder()
{
    this->postorder(this->root);
    std::cout << std::endl;
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
    std::cout << std::endl;
}
void BinarySearchTree::preorder(Node *cn)
{
    if (cn != nullptr)
    {
        std::cout << cn->getData() << " ";
        preorder(cn->getLeft());
        preorder(cn->getRight());
    }
}
void BinarySearchTree::inorder(Node *cn)
{
    if (cn != nullptr)
    {
        inorder(cn->getLeft());
        std::cout << cn->getData() << " ";
        inorder(cn->getRight());
    }
}
void BinarySearchTree::postorder(Node *cn)
{
    if (cn != nullptr)
    {
        postorder(cn->getLeft());
        postorder(cn->getRight());
        std::cout << cn->getData() << " ";
    }
}
Node *BinarySearchTree::search(int key)
{
    return search(root, key);
}
Node *BinarySearchTree::search(Node *cn, int key)
{
    if (cn == nullptr)
        return nullptr;
    else if (cn->getData() == key)
        return cn;
    else if (cn->getData() > key)
        search(cn->getRight(), key);
    else if (cn->getData() < key)
        search(cn->getLeft(), key);
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
Node *BinarySearchTree::remove(Node *cn, int key)
{
    if (cn == nullptr)
        return nullptr;
    if (key > cn->getData())
        cn->setRight(remove(cn->getRight(), key));
    else if (key < cn->getData())
        cn->setLeft(remove(cn->getLeft(), key));
    else
    {
        Node *temp;
        if (cn->getLeft() == nullptr && cn->getRight() == nullptr)
        {
            delete cn;
            return nullptr;
        }
        else if (cn->getLeft() == nullptr)
        {
            temp = cn->getRight();
            delete cn;
            return temp;
        }
        else if (cn->getRight() == nullptr)
        {
            temp = cn->getLeft();
            delete cn;
            return temp;
        }
        temp = minValueNode(cn->getRight());
        cn->setData(temp->getData());
        cn->setRight(remove(cn->getRight(), temp->getData()));
    }
    return cn;
}
Node *BinarySearchTree::minValueNode(Node *node)
{
    Node *current = node;
    while (current && current->getLeft() != NULL)
        current = current->getLeft();

    return current;
}
