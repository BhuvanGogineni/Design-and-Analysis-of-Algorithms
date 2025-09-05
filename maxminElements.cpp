#include <iostream>
using namespace std;

struct Pair {
    int min;
    int max;
};

Pair findMinMax(int arr[], int low, int high) {
    Pair result, left, right;
    
    // If only one element
    if (low == high) {
        result.min = result.max = arr[low];
        return result;
    }

    // If only two elements
    if (high == low + 1) {
        if (arr[low] < arr[high]) {
            result.min = arr[low];
            result.max = arr[high];
        } else {
            result.min = arr[high];
            result.max = arr[low];
        }
        return result;
    }

    // If more than 2 elements, divide
    int mid = (low + high) / 2;
    left = findMinMax(arr, low, mid);
    right = findMinMax(arr, mid + 1, high);

    result.min = (left.min < right.min) ? left.min : right.min;
    result.max = (left.max > right.max) ? left.max : right.max;

    return result;
}

int main() {
    int arr[] = {1000, 11, 445, 1, 330, 3000};
    int n = sizeof(arr) / sizeof(arr[0]);

    Pair ans = findMinMax(arr, 0, n - 1);

    cout << "Minimum element: " << ans.min << endl;
    cout << "Maximum element: " << ans.max << endl;

    return 0;
}
