#include <iostream>
void display(int *, int);
void sort(int *, int);
void quickSort(int *, int, int);
void merge(int *, int, int, int);
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
        int m = l + (r - l) / 2;
        quickSort(arr, l, m);
        quickSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}
void merge(int *arr, int l, int m, int r)
{
    //create left right array
    int n1 = m - l + 1;
    int n2 = r - m;
    int *arr_L = new int[n1];
    int *arr_r = new int[n2];
    //copy left and rigth array
    for (int i = 0; i < n1; i++)
    {
        arr_L[i] = arr[l + i];
    }
    for (int i = 0; i < n2; i++)
    {
        arr_r[i] = arr[(m + 1) + i];
    }
    //merge both array into main array with comp
    int i = 0; //left array
    int j = 0; //right array
    int k = l; //main array

    while (i < n1 && j < n2)
    {
        if (arr_L[i] <= arr_r[j])
        {
            arr[k] = arr_L[i];
            i++;
        }
        else
        {
            arr[k] = arr_r[j];
            j++;
        }
        k++;
    }
    //remaining element
    //left array
    while (i < n1)
    {
        arr[k] = arr_L[i];
        i++;
        k++;
    }
    //right array
    while (j < n2)
    {
        arr[k] = arr_r[j];
        j++;
        k++;
    }
    //delete both left right array;
    delete[] arr_L;
    delete[] arr_r;
}
void display(int *arr, int size)
{
    for (int i = 0; i < size; i++)
        std::cout << arr[i] << ", ";
}