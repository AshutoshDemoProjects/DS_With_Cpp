#include <iostream>
void display(int *, int);
void sort(int *, int);
void swap(int &, int &);
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
    int minIndex;
    for (int i = 0; i < size; i++)
    {
        minIndex = i;
        for (int j = i + 1; j < size; j++)
        {
            if (arr[minIndex] > arr[j])
                minIndex = j;
        }
        swap(arr[i], arr[minIndex]);
    }
}
void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}
void display(int *arr, int size)
{
    for (int i = 0; i < size; i++)
        std::cout << arr[i] << ", ";
}