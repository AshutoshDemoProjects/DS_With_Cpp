#include <iostream>
#include "Array.h"

int main()
{
    ArrayList al;
    int ch;
    int data;
    int pos;
    while (true)
    {
        std::cout << "1. insert at end" << std::endl;          //O(n)
        std::cout << "2. insert at starting" << std::endl;     //O(n)
        std::cout << "3. insert at possession" << std::endl;   //O(n)
        std::cout << "4. delete from end" << std::endl;        //O(n)
        std::cout << "5. delete from start" << std::endl;      //O(n)
        std::cout << "6. delete from possession" << std::endl; //O(n)
        std::cout << "7. display all" << std::endl;            //O(n)
        std::cout << "8. display index value" << std::endl;    //O(1)
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
                al.insert(data);
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
                al.insert(data, 1);
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
                al.insert(data, pos);
            }
            catch (char const *err)
            {
                std::cout << "Error: " << err << std::endl;
            }
            break;
        case 4:
            try
            {
                data = al.remove();
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
                data = al.remove(1);
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
                data = al.remove(pos);
                std::cout << "delete item is " << data << std::endl;
            }
            catch (char const *err)
            {
                std::cout << "Error: " << err << std::endl;
            }
            break;
        case 7:
            std::cout << al << std::endl;
            break;
        case 8:
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
            break;
        case 9:
            exit(0);
        default:
            break;
        }
    }
    return 0;
}
