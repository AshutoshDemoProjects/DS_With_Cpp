#include <iostream>
#include "csll.h"
int main()
{
    CircularSinglyLinkedList ll;
    int ch;
    int data;
    int pos;
    while (true)
    {
        std::cout << "1. insert at end";                         //O(n)
        std::cout << "\t2. insert at starting";                  //O(n)
        std::cout << "\t3. insert at possession" << std::endl;   //O(n)
        std::cout << "4. delete from end";                       //O(1)
        std::cout << "\t5. delete from start";                   //O(n)
        std::cout << "\t6. delete from possession" << std::endl; //O(n)
        std::cout << "7. display all";                           //O(n)
        std::cout << "\t8. display index value" << std::endl;    //O(1)
        std::cout << "9. exit" << std::endl;
        std::cin >> ch;
        switch (ch)
        {
        case 1:
            try
            {
                std::cout << "Enter data to insert: ";
                std::cin >> data;
                //append(al,data);
                ll.insertEnd(data);
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
                ll.insertFirst(data);
            }
            catch (char const *err)
            {
                std::cout << "Error: " << err << std::endl;
            }
            break;
        case 3:
            try
            {
                std::cout << "Enter data to insert: ";
                std::cin >> data;
                std::cout << "enter possession : ";
                std::cin >> pos;
                ll.insert(data, pos);
            }
            catch (char const *err)
            {
                std::cout << "Error: " << err << std::endl;
            }
            break;
        case 4:
            try
            {
                data = ll.deleteLast();
                std::cout << "delete item is " << data << std::endl;
            }
            catch (char const *err)
            {
                std::cout << "Error: " << err << std::endl;
            }
            break;
        case 5:
            try
            {
                data = ll.deleteFirst();
                std::cout << "delete item is " << data << std::endl;
            }
            catch (char const *err)
            {
                std::cout << "Error: " << err << std::endl;
            }
            break;
        case 6:
            try
            {
                std::cout << "enter possession : ";
                std::cin >> pos;
                data = ll.remove(pos);
                std::cout << "delete item is " << data << std::endl;
            }
            catch (char const *err)
            {
                std::cout << "Error: " << err << std::endl;
            }
            break;
        case 7:
            std::cout << ll << std::endl;
            break;
        /*case 8:
            try
            {
                std::cout << "enter index : ";
                std::cin >> pos;
                data = al[pos];
                std::cout << "Data is " << data << " at index " << pos << std::endl;
            }
            catch (char const *err)
            {
                std::cout << "Error: " << err << std::endl;
            }
            break; */
        case 9:
            exit(0);
            break;
        case 10:
            system("cls");
            break;
        default:
            std::cout << "Invalid choice..." << std::endl;
            break;
        }
    }
    return 0;
}
