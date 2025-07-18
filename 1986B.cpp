#include <iostream>

using namespace std;

int32_t main() {
    int t;
    cin >> t;

    while (t--) {
        int r, c;
        cin >> r >> c;

        int matrix[r][c];

        for (int i = 0; i<r; ++i) {
            for (int j = 0; j<c; ++j) {
                int num;
                cin >> num;

                matrix[i][j] = num;
            }
        }

        for (int i = 0; i<r; ++i) {
            for (int j = 0; j<c; ++j) {
                int neighbors = 0;
                
                if (j+1 < c) {
                    neighbors = max(neighbors, matrix[i][j+1]);
                }

                if (j-1 > -1) {
                    neighbors = max(neighbors, matrix[i][j-1]);
                }

                if (i+1 < r) {
                    neighbors = max(neighbors, matrix[i+1][j]);
                }

                if (i-1 > -1) {
                    neighbors = max(neighbors, matrix[i-1][j]);
                }

                if (neighbors < matrix[i][j]) {
                    matrix[i][j] = neighbors;
                }
            }
        }

        for (int i = 0; i<r; ++i) {
            for (int j = 0; j<c; ++j) {
                cout << matrix[i][j] << ' ';
            }

            cout << '\n';
        }
        
    }

    return 0;
}
