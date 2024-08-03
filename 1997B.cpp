#include <bits/stdc++.h>

using ll=long long;
using namespace std;

int32_t main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        int grid[2][n];

        for (int i = 0; i<n*2; ++i) {
            char c;
            cin >> c;

            grid[i/n][i%n] = c == '.' ? 1 : 0;
        }

        int res = 0;

        for (int i = 0; i<2; ++i) {
            int prevX = -3;
            for (int j = 0; j<n; ++j) {
                if (!grid[i][j]) {
                    if (j - prevX == 2 && grid[(i+1)%2][j] && grid[(i+1)%2][prevX]) {
                        ++res;
                    }
                    prevX = j;
                }
            }
        }

        cout << res << '\n';
    }

    return 0;
}
