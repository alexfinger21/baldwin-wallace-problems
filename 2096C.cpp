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

        vector<vector<ll>> h(n, vector<ll>(n));

        for (int i = 0; i<n; ++i) {
            for (int j = 0; j<n; ++j) {
                cin >> h[i][j];
            }
        }

        vector<ll> a(n), b(n);

        for (int i = 0; i<n; ++i) {
            cin >> a[i];
        }

        for (int i = 0; i<n; ++i) {
            cin >> b[i];
        }
            
        vector<vector<ll>> dp(n, vector<ll>(2));

        ll res = 0;

        dp[0][0] = 0;
        dp[0][1] = a[0];
        
        ll prev = 0;

        for (int i = 1; i<n; ++i) {
        
        }
        if (res != -1) {
            if (dp[n-1][0] == -1) {
                res += dp[n-1][1];
            } else if (dp[n-1][1] == -1) {
                res += dp[n-1][0];
            } else {
                res += min(dp[n-1][0], dp[n-1][1]);
            }
        }

        cout << res << '\n';
    }

    return 0;
}
