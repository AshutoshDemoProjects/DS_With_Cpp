#include <iostream>
#include "stack.h"

int main()
{
    Stack stack;
    int ch;
    int data;
    int pos;
    while (true)
    {
        std::cout << "1. push" << std::endl;        //O(n)
        std::cout << "2. pop" << std::endl;         //O(n)
        std::cout << "3. peek" << std::endl;        //O(n)
        std::cout << "4. display all" << std::endl; //O(n)
        std::cout << "5. exit" << std::endl;
        std::cin >> ch;
        switch (ch)
        {
        case 1:
            try
            {
                std::cout << "Enter data to insert: ";
                std::cin >> data;
                //append(al,data);
                stack.push(data);
            }
            catch (char const *err)
            {
                std::cout << "Error: " << err << std::endl;
            }
            break;
        case 2:
            try
            {
                data = stack.pop();
                std::cout << "delete item is " << data << std::endl;
            }
            catch (char const *err)
            {
                std::cout << "Error: " << err << std::endl;
            }
            break;

        case 3:
            try
            {
                data = stack.peek();
                std::cout << "Data at top " << data << std::endl;
            }
            catch (char const *err)
            {
                std::cout << "Error: " << err << std::endl;
            }
            break;
        case 4:
            std::cout << stack << std::endl;
            break;
        case 5:
            exit(0);
        default:
            break;
        }
    }
    return 0;
}
