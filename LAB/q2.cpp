#include <iostream>
using namespace std;

void deleteElement(int arr[], int &n, int index) {
    if (index >= 0 && index < n) {
        for (int i = index; i < n - 1; i++) {
            arr[i] = arr[i + 1];
        }
        n--;
        cout << "Element at index " << index << " deleted." << endl;
    } else {
        cout << "Invalid index. Deletion is not possible." << endl;
    }
}

int main() {
    int LA[] = {1, 2, 5, 4, 3, 6, 8};
    int n = sizeof(LA) / sizeof(LA[0]);

    cout << "The original array elements are: {";
    for (int i = 0; i < n; i++) {
        cout << LA[i];
        if (i < n - 1) {
            cout << ", ";
        }
    }
    cout << "}" << endl;

    // Delete element at index 0
    deleteElement(LA, n, 0);

    // Delete element at index 2
    deleteElement(LA, n, 2);

    // Delete element at index 4
    deleteElement(LA, n, 4);

    cout << "The updated array elements are: {";
    for (int i = 0; i < n; i++) {
        cout << LA[i];
        if (i < n - 1) {
            cout << ", ";
        }
    }
    cout << "}" << endl;

    return 0;
}
