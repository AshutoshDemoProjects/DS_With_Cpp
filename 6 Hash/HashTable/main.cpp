#include <iostream>
#include "HashTable.h"

int main()
{
    HashTable hashMap;
    int ch;
    int key;
    while (true)
    {
        std::cout << "1. put" << std::endl;    //O(n)
        std::cout << "2. remove" << std::endl; //O(n)
        std::cout << "3. search" << std::endl; //O(n)
        std::cout << "4. exit" << std::endl;
        std::cin >> ch;
        switch (ch)
        {
        case 1:
            try
            {
                std::cout << "Enter key to insert: ";
                std::cin >> key;
                //append(al,data);
                hashMap.put(key);
            }
            catch (char const *err)
            {
                std::cout << "Error: " << err << std::endl;
            }
            break;
        case 2:
            try
            {
                std::cout << "Enter key to insert: ";
                std::cin >> key;
                std::cout << "delete item is " << hashMap.remove(key) << std::endl;
            }
            catch (char const *err)
            {
                std::cout << "Error: " << err << std::endl;
            }
            break;

        case 3:
            try
            {
                std::cout << "Enter key to insert: ";
                std::cin >> key;
                std::cout << "Data at top " << hashMap.search(key) << std::endl;
            }
            catch (char const *err)
            {
                std::cout << "Error: " << err << std::endl;
            }
            break;
        case 4:
            exit(0);
        default:
            break;
        }
    }
    return 0;
}
