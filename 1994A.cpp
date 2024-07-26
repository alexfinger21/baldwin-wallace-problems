#include <bits/stdc++.h>

using namespace std;

int32_t main() {
    int t;
    cin >> t;

    while (t--) {
        int r, c;
        cin >> r >> c;

        int mat[r][c];

        for (int i = 0; i<r; ++i) {
            for (int j = 0; j<c; ++j) {
                int n;
                cin >> n;

                mat[i][j] = n;
            }
        }

        if (r*c == 1) {
            cout << "-1\n";
        } else {
            int res[r][c];
            res[0][0] = mat[r-1][c-1];

            for (int i = 0; i<r; ++i) {
                for (int j = 0; j<c; ++j) {
                    if (i != r-1 || j != c-1) {
                        res[(i*c+j+1)/c][(i*c+j+1)%c] = mat[i][j];
                    }
                }
            }

            for (int i = 0; i<r; ++i) {
                for (int j = 0; j<c; ++j) {
                    cout << res[i][j] << ' ';
                }
                cout << '\n';
            }
        }
    }

    return 0;
}
