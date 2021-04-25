
#include <iostream>
int search(int, int *, int);
int main()
{
    int arr[] = {
        1,   //0
        3,   //1
        4,   //2
        8,   //3
        21,  //4
        32,  //5
        32,  //6
        34,  //7
        45,  //8
        54,  //9
        65,  //10
        67,  //11
        67,  //12
        90,  //13
        354, //14
    };
    int size = sizeof(arr) / sizeof(arr[0]);
    int key;
    std::cout << "Enter data tobe search: ";
    std::cin >> key;
    int index = search(key, arr, size);
    if (index >= 0)
        std::cout << "Key found at " << index << std::endl;
    else
        std::cout << "Key not found" << std::endl;
    return 0;
}
int search(int key, int *arr, int size)
{
    int l = 0;
    int r = size - 1;
    int mid;
    while (l <= r)
    {
        mid = (l + r) / 2;
        if (arr[mid] == key)
            return mid;
        else if (arr[mid] > key)
        {
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    return -1;
}