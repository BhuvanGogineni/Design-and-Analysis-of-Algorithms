#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void bucketSort(vector<float>& arr) {
    int n = arr.size();
    if (n <= 0) return;

    vector<vector<float>> buckets(n);

    for (int i = 0; i < n; i++) {
        int index = min(n - 1, static_cast<int>(n * arr[i]));
        buckets[index].push_back(arr[i]);
    }

    for (int i = 0; i < n; i++) {
        sort(buckets[i].begin(), buckets[i].end());
    }

    int idx = 0;
    for (int i = 0; i < n; i++) {
        for (float val : buckets[i]) {
            arr[idx++] = val;
        }
    }
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<float> arr(n);
    cout << "Enter elements (in range 0 to 1): ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    bucketSort(arr);

    cout << "Sorted array: ";
    for (float val : arr) cout << val << " ";
    cout << endl;

    return 0;
}
