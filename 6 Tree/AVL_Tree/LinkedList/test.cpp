#include <iostream>
#include "AVLTree.h"

int main()
{
    /* int instarr[] = {400, 100, 1000, 80, 200, 500, 2000, 70, 90, 300, 3000, 50};
    int delearr[] = {90, 50, 300, 200, 500}; */
    int instarr[] = {30, 20, 40, 10, 5, 3, 4, 50, 60, 70, 65};
    int delearr[] = {20, 30, 5, 4, 10};

    AVLTree bt;
    int instSize = sizeof(instarr) / sizeof(instarr[0]);
    for (int i = 0; i < instSize; i++)
    {
        try
        {
            std::cout << instarr[i] << " inserting.." << std::endl;
            bt.insert(instarr[i]);
            std::cout << instarr[i] << " inserted.." << std::endl;
            bt.levelorder();
        }
        catch (char const *err)
        {
            std::cerr << err << std::endl;
        }
    }

    int deleSize = sizeof(delearr) / sizeof(delearr[0]);
    for (int i = 0; i < deleSize; i++)
    {
        try
        {
            std::cout << delearr[i] << " deleting.." << std::endl;
            bt.remove(delearr[i]);
            std::cout << delearr[i] << " deleted.." << std::endl;
            bt.levelorder();
        }
        catch (char const *err)
        {
            std::cerr << err << std::endl;
        }
    }
    //10 4 50 3 5 30 65 20 40 60 70
    //10 4 50 3 5 30 65 40 60 70
    //10 4 50 3 5 40 65 60 70
    //10 4 50 3 40 65 60 70
    //10 3 50 40 65 60 70
    //40 3 50 65 60 70
}