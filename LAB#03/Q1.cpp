#include <iostream>
using namespace std;
int linearSearch(int arr[], int n, int key)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == key)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    int n = 4;
    int arr[n] = {2, 4, 6, 8};
    int key;
    cout << "\nEnter key to be searched: ";
    cin >> key;
    int result = linearSearch(arr, n, key);
    if (result == -1)
    {
        cout << "\nKey not found ";
    }
    else
    {
        cout << "\nkey is found at: " << result << " index";
    }

    return 0;
}