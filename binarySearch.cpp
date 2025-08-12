#include <iostream>
using namespace std;

int binary_search(int arr[], int size, int key) {

    int low = 0, high = size - 1;
    while (low <= high) {

          int mid = low + (high - low) / 2;

        if (arr[mid] == key) {
            return mid;
        }
        else if (arr[mid] < key) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return -1;
}

int main() {

    int n, key;
    cout << "Size: ";
    cin >> n;

    int arr[n];
    cout << "Enter sorted elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Find: ";
    cin >> key;

    int result = binary_search(arr, n, key);

    if (result == -1) {
        cout << "Not found\n";
    } else {
        cout << "Found at index " << result << "\n";
    }

    return 0;
}


