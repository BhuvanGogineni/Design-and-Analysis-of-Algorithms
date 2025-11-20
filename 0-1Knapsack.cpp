#include <iostream>
#include <algorithm>
using namespace std;

int main() {

    int P[5]  = {0, 1, 2, 5, 6};   // profits
    int wt[5] = {0, 2, 3, 4, 5};   // weights

    int m = 8, n = 4;
    int K[5][9];

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {

            if (i == 0 || j == 0) {
                K[i][j] = 0;
            }
            else if (wt[i] <= j) {
                K[i][j] = max(P[i] + K[i - 1][j - wt[i]],
                              K[i - 1][j]);
            }
            else {
                K[i][j] = K[i - 1][j];
            }
        }
    }

    cout << "Maximum Profit = " << K[n][m] << endl;

    int i = n, j = m;
    int x[5] = {0};

    while (i > 0 && j > 0) {

        if (K[i][j] == K[i - 1][j]) {
            cout << "i = " << i << " → 0" << endl;
            x[i] = 0;
            i--;
        }
        else {
            cout << "i = " << i << " → 1" << endl;
            x[i] = 1;
            j = j - wt[i];
            i--;
        }
    }

    cout << "\nx = ";
    for (int k = 1; k <= n; k++) {
        cout << x[k] << " ";
    }
    cout << endl;

    return 0;
}
