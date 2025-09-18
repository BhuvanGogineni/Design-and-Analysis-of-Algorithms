#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Item {
    int value;
    int weight;
};

// ----- Comparators for Sorting -----
bool cmpByValue(Item a, Item b) {
    return a.value > b.value;
}

bool cmpByWeight(Item a, Item b) {
    return a.weight < b.weight;
}

bool cmpByRatio(Item a, Item b) {
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;
    return r1 > r2;
}

// ----- Fractional Knapsack Function -----
void fractionalKnapsack(vector<Item> items, int capacity, int mode) {
    if (mode == 1) sort(items.begin(), items.end(), cmpByValue);
    else if (mode == 2) sort(items.begin(), items.end(), cmpByWeight);
    else if (mode == 3) sort(items.begin(), items.end(), cmpByRatio);

    double totalValue = 0.0;
    int remaining = capacity;

    cout << "\nSelected items:\n";
    for (int i = 0; i < items.size() && remaining > 0; i++) {
        if (items[i].weight <= remaining) {
            cout << "Item " << i + 1 << ": value=" << items[i].value
                 << ", weight=" << items[i].weight << " (100%)\n";
            totalValue += items[i].value;
            remaining -= items[i].weight;
        } else {
            double fraction = (double)remaining / items[i].weight;
            cout << "Item " << i + 1 << ": value=" << items[i].value
                 << ", weight=" << items[i].weight
                 << " (" << fraction * 100 << "%)\n";
            totalValue += items[i].value * fraction;
            remaining = 0;
        }
    }
    cout << "Total value in knapsack = " << totalValue << "\n";
}

// ----- Main Function -----
int main() {
    int n, capacity, mode;
    cout << "Enter number of items: ";
    cin >> n;

    vector<Item> items(n);
    cout << "Enter value and weight of each item:\n";
    for (int i = 0; i < n; i++) {
        cin >> items[i].value >> items[i].weight;
    }

    cout << "Enter knapsack capacity: ";
    cin >> capacity;

    cout << "\nChoose method:\n"
         << "1. By Value\n"
         << "2. By Weight\n"
         << "3. By Value/Weight Ratio (Optimal)\n"
         << "Enter choice: ";
    cin >> mode;

    fractionalKnapsack(items, capacity, mode);

    return 0;
}
