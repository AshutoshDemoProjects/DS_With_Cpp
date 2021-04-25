#include <iostream>
#include "queue.h"

int main()
{
    Queue queue;
    int ch;
    int data;
    int pos;
    while (true)
    {
        std::cout << "1. Enqueue" << std::endl;     //O(n)
        std::cout << "2. Dequeue" << std::endl;     //O(n)
        std::cout << "3. display all" << std::endl; //O(n)
        std::cout << "4. exit" << std::endl;
        std::cin >> ch;
        switch (ch)
        {
        case 1:
            try
            {
                std::cout << "Enter data to insert: ";
                std::cin >> data;
                //append(al,data);
                queue.enqueue(data);
            }
            catch (char const *err)
            {
                std::cout << "Error: " << err << std::endl;
            }
            break;
        case 2:
            try
            {
                data = queue.dequeue();
                std::cout << "delete item is " << data << std::endl;
            }
            catch (char const *err)
            {
                std::cout << "Error: " << err << std::endl;
            }
            break;

        case 3:
            std::cout << queue << std::endl;
            break;
        case 4:
            exit(0);
        default:
            break;
        }
    }
    return 0;
}
