#include <iostream>
void display(int *, int);
void sort(int *, int);
void quickSort(int *, int, int);
int partition(int *, int, int);
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
    quickSort(arr, 0, size - 1);
}
void quickSort(int *arr, int l, int r)
{
    if (l < r)
    {
        int pi = partition(arr, l, r);
        quickSort(arr, l, pi - 1);
        quickSort(arr, pi + 1, r);
    }
}
int partition(int *arr, int l, int r)
{
    int pivot = arr[r];
    int i = l - 1;
    for (int j = l; j <= r - 1; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    i++;
    swap(arr[i], arr[r]);
    return i;
}
void swap(int &a, int &b)
{
    int t = a;
    a = b;
    b = t;
}
void display(int *arr, int size)
{
    for (int i = 0; i < size; i++)
        std::cout << arr[i] << ", ";
}