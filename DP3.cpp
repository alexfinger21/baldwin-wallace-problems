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

        vector<vector<int>> dp(n, vector<int>(n+1, 0));

        vector<int> a(n);

        for (int i = 0; i<n; ++i) {
            cin >> a[i];
        }

        for (int i = 0; i<n; ++i) {
            for (int j = 0; j<=i+1; ++j) {
                int right = n-i+j-1;
                if (j == 0 && i == 0) {
                    dp[i][j] = a[right]*(i+1);
                    continue;
                }
                if (j <= i) {
                    dp[i][j] = a[right]*(i+1) + dp[i-1][j];
                }

                if (j > 0) {
                    dp[i][j] = max(dp[i][j], (i > 0 ? dp[i-1][j-1] : 0) + a[j-1] * (i+1));
                }
             }
        }

        int res = 0;

        for (int i = 0; i<=n; ++i) {
            res = max(res, dp[n-1][i]);
        }

        cout << res << '\n';
    }

    return 0;
}
