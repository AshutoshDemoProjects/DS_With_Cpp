#include <iostream>
#include "binaryTree.h"

int main()
{
    BinaryTree bt;
    int ch;
    int data;
    while (true)
    {
        std::cout << "1. Insert" << std::endl;     //O(n)
        std::cout << "2. Delete" << std::endl;     //O(n)
        std::cout << "3. PreOrder" << std::endl;   //O(n)
        std::cout << "4. InOrder" << std::endl;    //O(n)
        std::cout << "5. PostOrder" << std::endl;  //O(n)
        std::cout << "6. LevelOrder" << std::endl; //O(n)
        std::cout << "7. Search" << std::endl;
        std::cout << "8. exit" << std::endl;
        std::cin >> ch;
        switch (ch)
        {
        case 1:
            try
            {
                std::cout << "Enter data to insert: ";
                std::cin >> data;
                bt.insert(data);
            }
            catch (char const *err)
            {
                std::cout << "Error: " << err << std::endl;
            }
            break;
        case 2:
            try
            {
                std::cout << "Enter data to insert: ";
                std::cin >> data;
                try
                {
                    bt.remove(data);
                    std::cout << "delete item is " << data << std::endl;
                }
                catch (char const *err)
                {
                    std::cout << err << std::endl;
                }
            }
            catch (char const *err)
            {
                std::cout << "Error: " << err << std::endl;
            }
            break;
        case 3:
            std::cout << "tree traversal in preorder:" << std::endl;
            bt.preorder();
            std::cout << std::endl;
            break;
        case 4:
            std::cout << "tree traversal in inorder:" << std::endl;
            bt.inorder();
            std::cout << std::endl;
            break;
        case 5:
            std::cout << "tree traversal in postorder:" << std::endl;
            bt.postorder();
            std::cout << std::endl;
            break;
        case 6:
            std::cout << "tree traversal in levelorder:" << std::endl;
            bt.levelorder();
            std::cout << std::endl;
            break;
        case 7:
            std::cout << "Enter data to insert: ";
            std::cin >> data;
            if (bt.search(data) > -1)
            {
                std::cout << "data found" << std::endl;
            }
            else
            {
                std::cout << "data not found" << std::endl;
            }
            break;
        case 8:
            exit(0);
        default:
            break;
        }
    }
    return 0;
}
