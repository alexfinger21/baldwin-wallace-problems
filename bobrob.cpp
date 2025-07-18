#include <bits/stdc++.h>

using ll=long long;
using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;

    while (t--) {
        int w;
        cin >> w;

        int n;
        cin >> n;

        vector<int> p(n);
        vector<int> m(n);

        for (int i = 0; i<n; ++i) {
            cin >> p[i];
        }

        for (int i = 0; i<n; ++i) {
            cin >> m[i];
        }

        vector<vector<int>> dp(w+1, vector<int>(n));

        for (int i = 1; i<=w; ++i) {
            for (int j = 0; j<n; ++j) {
                cout << j << endl;
                if (!j) {
                    dp[i][j] = ((i - m[j]) >= 0) ? p[j] : 0;
                } else {
                    dp[i][j] = max(dp[i][j-1], ((i - m[j]) >= 0) ? dp[i-m[j]][j-1] + p[j] : 0);
                }
                // max between prev item max and this item + highest prev item max - weight 
            }
        }

        cout << dp[w][n-1] << '\n'; 
    }

    return 0;
}
