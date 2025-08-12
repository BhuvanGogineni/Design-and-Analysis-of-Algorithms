#include <iostream>
using namespace std;

int main() {
    int n, key;
    cout << "Size: ";
    cin >> n;

    int arr[n];
    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Find: ";
    cin >> key;

    bool found = false;
    for (int i = 0; i < n; i++) {
        if (key == arr[i]) {
            cout << "Found at index " << i << "\n";
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Not found\n";
    }

    return 0;
}
