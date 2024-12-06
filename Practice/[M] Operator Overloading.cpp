#include <iostream>
#include <vector>
using namespace std;

class Matrix {
public: 
    vector<vector<int>> a;

    Matrix operator +(const Matrix& b) {
        int n = a.size();
        int m = a[0].size();
        Matrix result;
        result.a.resize(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                result.a[i][j] = a[i][j] + b.a[i][j];
            }
        }
        return result;
    }
};

int main() {
    // Predefined test case
    int cases = 1;

    for (int k = 0; k < cases; k++) {
        Matrix x, y, result;
        int n = 2, m = 2;  // Define matrix dimensions

        // Define matrix x
        x.a = {{1, 2}, {3, 4}};
        
        // Define matrix y
        y.a = {{5, 6}, {7, 8}};
        
        // Add matrices
        result = x + y;

        // Output the result
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << result.a[i][j] << " ";  // Output the sum of the matrices
            }
            cout << endl;
        }
    }

    return 0;
}
