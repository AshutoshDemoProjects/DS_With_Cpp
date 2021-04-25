#include <iostream>
int search(int, int *, int);
int main()
{
    int arr[] = {
        34,
        21,
        67,
        8,
        90,
        32,
        54,
        1,
        32,
        354,
        45,
        67,
        65,
        4,
        3,
    };
    int size = sizeof(arr) / sizeof(arr[0]);
    std::cout << size;
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
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == key)
        {
            return i;
        }
    }
    return -1;
}