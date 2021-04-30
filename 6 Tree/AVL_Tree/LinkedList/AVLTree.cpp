#include "AVLTree.h"
#include "queue.h"
AVLTree::AVLTree()
{
    this->root = nullptr;
}
int AVLTree::height(Node *cn)
{
    if (cn == nullptr)
        return 0;
    return cn->getHeight();
}
int AVLTree::max(Node *left, Node *right)
{
    int lh = height(left);
    int rh = height(right);
    return lh > rh ? lh : rh;
}
int AVLTree::calculateHeight(Node *cn)
{
    return max(cn->getLeft(), cn->getRight()) + 1;
}
Node *AVLTree::rightRotate(Node *currentDisbalaceNode)
{
    Node *newRoot = currentDisbalaceNode->getLeft();

    currentDisbalaceNode->setLeft(currentDisbalaceNode->getLeft()->getRight());
    newRoot->setRight(currentDisbalaceNode);

    currentDisbalaceNode->setHeight(calculateHeight(currentDisbalaceNode));
    newRoot->setHeight(calculateHeight(newRoot));

    return newRoot;
}
Node *AVLTree::leftRotate(Node *currentDisbalaceNode)
{
    Node *newRoot = currentDisbalaceNode->getRight();

    currentDisbalaceNode->setRight(currentDisbalaceNode->getRight()->getLeft());
    newRoot->setLeft(currentDisbalaceNode);

    currentDisbalaceNode->setHeight(calculateHeight(currentDisbalaceNode));
    newRoot->setHeight(calculateHeight(newRoot));

    return newRoot;
}

void AVLTree::insert(int data)
{
    root = insert(root, data);
}
Node *AVLTree::insert(Node *cn, int data)
{
    if (cn == nullptr)
        return new Node(data);
    if (data < cn->getData())
        cn->setLeft(insert(cn->getLeft(), data));
    else if (data > cn->getData())
        cn->setRight(insert(cn->getRight(), data));

    int balance = checkBalance(cn);
    if (balance > 1)
    {
        if (checkBalance(cn->getLeft()) > 0)
            cn = rightRotate(cn);
        else
        {
            cn->setLeft(leftRotate(cn->getLeft()));
            cn = rightRotate(cn);
        }
    }
    else if (balance < -1)
    {
        if (checkBalance(cn->getRight()) < 0)
            cn = leftRotate(cn);
        else
        {
            cn->setRight(rightRotate(cn->getRight()));
            cn = leftRotate(cn);
        }
    }
    cn->setHeight(calculateHeight(cn));
    return cn;
}
int AVLTree::checkBalance(Node *cn)
{
    return height(cn->getLeft()) - height(cn->getRight());
}

void AVLTree::remove(int data)
{
    root = remove(root, data);
}
Node *AVLTree::remove(Node *cn, int key)
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
        return cn;
    }
    int balance = checkBalance(cn);
    if (balance > 1)
    {
        if (checkBalance(cn->getLeft()) > 0)
            cn = rightRotate(cn);
        else
        {
            cn->setLeft(leftRotate(cn->getLeft()));
            cn = rightRotate(cn);
        }
    }
    else if (balance < -1)
    {
        if (checkBalance(cn->getRight()) < 0)
            cn = leftRotate(cn);
        else
        {
            cn->setRight(rightRotate(cn->getRight()));
            cn = leftRotate(cn);
        }
    }
    if (cn->getLeft() != nullptr)
        cn->getLeft()->setHeight(calculateHeight(cn->getLeft()));
    if (cn->getLeft() != nullptr)
        cn->getRight()->setHeight(calculateHeight(cn->getRight()));
    cn->setHeight(calculateHeight(cn));
    return cn;
}

Node *AVLTree::minValueNode(Node *node)
{
    Node *current = node;
    while (current && current->getLeft() != NULL)
        current = current->getLeft();

    return current;
}

void AVLTree::preorder()
{
    this->preorder(this->root);
    std::cout << std::endl;
}
void AVLTree::inorder()
{
    this->inorder(this->root);
    std::cout << std::endl;
}
void AVLTree::postorder()
{
    this->postorder(this->root);
    std::cout << std::endl;
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
    std::cout << std::endl;
}
void AVLTree::preorder(Node *cn)
{
    if (cn != nullptr)
    {
        std::cout << cn->getData() << " ";
        preorder(cn->getLeft());
        preorder(cn->getRight());
    }
}
void AVLTree::inorder(Node *cn)
{
    if (cn != nullptr)
    {
        inorder(cn->getLeft());
        std::cout << cn->getData() << " ";
        inorder(cn->getRight());
    }
}
void AVLTree::postorder(Node *cn)
{
    if (cn != nullptr)
    {
        postorder(cn->getLeft());
        postorder(cn->getRight());
        std::cout << cn->getData() << " ";
    }
}
Node *AVLTree::search(int key)
{
    return search(root, key);
}
Node *AVLTree::search(Node *cn, int key)
{
    if (cn == nullptr)
        return nullptr;
    else if (cn->getData() == key)
        return cn;
    else if (cn->getData() > key)
        search(cn->getRight(), key);
    else //if (cn->getData() < key)
        search(cn->getLeft(), key);
    return nullptr;
}