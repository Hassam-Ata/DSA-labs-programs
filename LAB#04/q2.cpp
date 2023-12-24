#include <iostream>
using namespace std;

void bubble_sort(int *arr, int size)
{
    if (size == 1)
    {
        return;
    }
    for (int i = 0; i < size - 1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            swap(arr[i], arr[i + 1]);
        }
    }
    bubble_sort(arr, size - 1);
}

void print(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    int *arr = new int[size];
    cout << "Enter " << size << " elements for the array:" << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }

    cout << "Array before sorting: ";
    print(arr, size);

    bubble_sort(arr, size);

    cout << "Array after sorting: ";
    print(arr, size);

    delete[] arr;

    return 0;
}
