#include <iostream>
#include <cmath>
using namespace std;

// O(n^2): Brute Force
int bruteForceSum(int base, int power) {
    int total = 0;
    for (int i = 0; i <= power; i++) {
        int term = 1;
        for (int j = 1; j <= i; j++) {
            term *= base;
        }
        total += term;
    }
    return total;
}

// O(n): Iterative
int iterativeSum(int base, int power) {
    int total = 0;
    int term = 1;
    for (int i = 0; i <= power; i++) {
        total += term;
        term *= base;
    }
    return total;
}

// O(1): Formula
int formulaSum(int base, int power) {
    if (base == 1) return power + 1;   // Special case: 1+1+1...
    return (pow(base, power + 1) - 1) / (base - 1);
}

int main() {
    int base, power;
    cout << "Enter base: ";
    cin >> base;
    cout << "Enter power: ";
    cin >> power;

    cout << "\nBrute Force: " << bruteForceSum(base, power) << endl;
    cout << "Iterative : " << iterativeSum(base, power) << endl;
    cout << "Formula : " << formulaSum(base, power) << endl;

    return 0;
}
