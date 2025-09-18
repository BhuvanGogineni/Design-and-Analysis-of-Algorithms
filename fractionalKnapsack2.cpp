#include <iostream>
#include <vector>
using namespace std;

struct Item {
    int value, weight;
};

// Swap function
void swap(Item &a, Item &b) {
    Item temp = a;
    a = b;
    b = temp;
}

// Sort by profit (value)
void sortByValue(vector<Item> &arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (arr[j].value < arr[j + 1].value) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// Sort by weight (ascending)
void sortByWeight(vector<Item> &arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (arr[j].weight > arr[j + 1].weight) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// Sort by profit/weight ratio (descending)
void sortByRatio(vector<Item> &arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            double r1 = (double)arr[j].value / arr[j].weight;
            double r2 = (double)arr[j + 1].value / arr[j + 1].weight;
            if (r1 < r2) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// Fractional Knapsack function
void fractionalKnapsack(vector<Item> arr, int maxWt, int mode) {
    // Sort based on chosen method
    if (mode == 1) sortByValue(arr);
    else if (mode == 2) sortByWeight(arr);
    else if (mode == 3) sortByRatio(arr);

    vector<Item> res(arr.size(), {0, 0});
    double currWt = 0, currProfit = 0;
    int i = 0;

    // Take items while we can
    while (i < arr.size() && currWt + arr[i].weight <= maxWt) {
        currWt += arr[i].weight;
        currProfit += arr[i].value;
        res[i] = arr[i];
        i++;
    }

    // Take fraction of next item if needed
    if (i < arr.size() && currWt < maxWt) {
        int rem = maxWt - (int)currWt;
        double insertPart = (double)rem / arr[i].weight;
        double remProfit = arr[i].value * insertPart;
        currWt = maxWt;
        currProfit += remProfit;
        res[i].weight = rem;
        res[i].value = (int)remProfit;
    }

    // Print result
    cout << "\nThe maximum weight in the bag is: " << currWt;
    cout << "\nThe profit is: " << currProfit;
    cout << "\nItems in the knapsack are:\n";
    for (int j = 0; j < res.size(); j++) {
        if (res[j].weight > 0) {
            cout << "Element " << j + 1 << ":\n";
            cout << "Weight : " << res[j].weight << "\n";
            cout << "Profit : " << res[j].value << "\n";
        }
    }
}

int main() {
    int n;
    cout << "Enter the number of items: ";
    cin >> n;

    vector<Item> arr(n);
    cout << "Enter the elements (weight and profit):\n";
    for (int i = 0; i < n; i++) {
        cout << "Element " << i + 1 << ":\n";
        cout << "Weight : ";
        cin >> arr[i].weight;
        cout << "Profit : ";
        cin >> arr[i].value;
    }

    int maxWt;
    cout << "Enter the maximum weight of the knapsack: ";
    cin >> maxWt;

    cout << "\nChoose method:\n";
    cout << "1. Placing with Highest Profit\n";
    cout << "2. Placing with Minimum Weight\n";
    cout << "3. Placing with Highest Profit/Weight Ratio\n";
    int mode;
    cin >> mode;

    fractionalKnapsack(arr, maxWt, mode);
    return 0;
}
