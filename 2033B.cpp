#include <bits/stdc++.h>

using ll=long long;
using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        int mat[n][n];

        for (int i = 0; i<n; ++i) {
            for (int j = 0; j<n; ++j) {
                cin >> mat[i][j];
            }
        }

        ll res = 0;

        for (int k = 0; k<n; ++k) {
            int biggest = 0;
            int i = 0;
            int j = k;

            while (i<n && j<n) {
                if (mat[i][j] < 0) {
                    biggest = min(biggest, mat[i][j]);
                }          
                ++i;
                ++j;
            }
            res -= biggest;
        }
        for (int p = 1; p<n; ++p) {
            int biggest = 0;
            int i = p;
            int j = 0;
            while (i<n && j<n) {
                if (mat[i][j] < 0) {
                    biggest = min(biggest, mat[i][j]);
                }          
                ++i;
                ++j;
            }
            res -= biggest;
        }

        cout << res << '\n';
    }

    return 0;
}

