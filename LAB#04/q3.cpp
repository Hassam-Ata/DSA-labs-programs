#include <iostream>
using namespace std;

int partitionArray(int *arr, int start, int end) {
    int pivot = arr[start];
    int i = start;
    int j = end;

    while (i < j) {
        while (arr[i] <= pivot && i < end) {
            i++;
        }
        while (arr[j] > pivot && j > start) {
            j--;
        }
        if (i < j) {
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[start], arr[j]);
    return j;
}

void quickSort(int *arr, int start, int end) {
    if (start < end) {
        int partitionIndex = partitionArray(arr, start, end);
        quickSort(arr, start, partitionIndex - 1);
        quickSort(arr, partitionIndex + 1, end);
    }
}

void print(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    int *arr = new int[size];
    cout << "Enter " << size << " elements for the array:" << endl;
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    cout << "Array before sorting: ";
    print(arr, size);

    quickSort(arr, 0, size - 1);

    cout << "Array after sorting: ";
    print(arr, size);

    delete[] arr;

    return 0;
}
