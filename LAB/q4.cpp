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
    int LA[10] = {2, 4, 6, 8};
    int n = 4;

    cout << "The original array elements are: {";
    for (int i = 0; i < n; i++) {
        cout << LA[i];
        if (i < n - 1) {
            cout << ", ";
        }
    }
    cout << "}" << endl;

    int index;
    
    cout << "Enter the index of the element to delete: ";
    cin >> index;

    deleteElement(LA, n, index);

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
