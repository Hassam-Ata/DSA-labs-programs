#include <iostream>
using namespace std;

void insertElement(int arr[], int &n, int item, int index) {
    if (index >= 0 && index <= n) {
        for (int i = n; i > index; i--) {
            arr[i] = arr[i - 1];
        }
        arr[index] = item;
        n++;
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

    // Insert 1 at index 0
    insertElement(LA, n, 1, 0);

    // Insert 5 at index 2
    insertElement(LA, n, 5, 2);

    // Insert 3 at index 4
    insertElement(LA, n, 3, 4);

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
