#include <iostream>
#include <vector>
using namespace std;

typedef vector<vector<int>> Matrix;

// Function to add matrices
Matrix add(Matrix A, Matrix B, int n) {
    Matrix C(n, vector<int>(n));
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            C[i][j] = A[i][j] + B[i][j];
    return C;
}

// Function to subtract matrices
Matrix sub(Matrix A, Matrix B, int n) {
    Matrix C(n, vector<int>(n));
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            C[i][j] = A[i][j] - B[i][j];
    return C;
}

// Strassen's Algorithm
Matrix strassen(Matrix A, Matrix B, int n) {
    if(n == 1) {
        return {{A[0][0] * B[0][0]}};
    }

    int k = n/2;
    // Splitting matrices into quadrants
    Matrix A11(k, vector<int>(k)), A12(k, vector<int>(k)),
           A21(k, vector<int>(k)), A22(k, vector<int>(k)),
           B11(k, vector<int>(k)), B12(k, vector<int>(k)),
           B21(k, vector<int>(k)), B22(k, vector<int>(k));

    for(int i=0;i<k;i++) {
        for(int j=0;j<k;j++) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j+k];
            A21[i][j] = A[i+k][j];
            A22[i][j] = A[i+k][j+k];
            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j+k];
            B21[i][j] = B[i+k][j];
            B22[i][j] = B[i+k][j+k];
        }
    }

    // Calculating the 7 products
    Matrix P1 = strassen(A11, sub(B12,B22,k), k);
    Matrix P2 = strassen(add(A11,A12,k), B22, k);
    Matrix P3 = strassen(add(A21,A22,k), B11, k);
    Matrix P4 = strassen(A22, sub(B21,B11,k), k);
    Matrix P5 = strassen(add(A11,A22,k), add(B11,B22,k), k);
    Matrix P6 = strassen(sub(A12,A22,k), add(B21,B22,k), k);
    Matrix P7 = strassen(sub(A11,A21,k), add(B11,B12,k), k);

    // Combining results into final matrix
    Matrix C(n, vector<int>(n));
    for(int i=0;i<k;i++) {
        for(int j=0;j<k;j++) {
            C[i][j]       = P5[i][j] + P4[i][j] - P2[i][j] + P6[i][j];
            C[i][j+k]     = P1[i][j] + P2[i][j];
            C[i+k][j]     = P3[i][j] + P4[i][j];
            C[i+k][j+k]   = P1[i][j] + P5[i][j] - P3[i][j] - P7[i][j];
        }
    }

    return C;
}

// Driver code
int main() {
    int n = 2;
    Matrix A = {{1,2},{3,4}};
    Matrix B = {{5,6},{7,8}};

    Matrix C = strassen(A, B, n);

    cout << "Result matrix:\n";
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++)
            cout << C[i][j] << " ";
        cout << endl;
    }
    return 0;
}
