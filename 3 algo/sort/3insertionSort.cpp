#include <iostream>
void display(int *, int);
void sort(int *, int);
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
    std::cout << "Array before sort:";
    display(arr, size);

    sort(arr, size);

    std::cout << "\nArray after sort:";
    display(arr, size);
    return 0;
}
void sort(int *arr, int size)
{
    int key, j;
    for (int i = 1; i < size; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}
void display(int *arr, int size)
{
    for (int i = 0; i < size; i++)
        std::cout << arr[i] << ", ";
}