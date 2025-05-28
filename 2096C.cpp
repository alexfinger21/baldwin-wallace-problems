#include <bits/stdc++.h>

using ll=long long;
using namespace std;

ll inf = 1e15;

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
            
        vector<vector<ll>> dp(n, vector<ll>(2, inf));

        ll res = 0;

        dp[0][0] = 0;
        dp[0][1] = a[0];

        for (int i = 1; i<n; ++i) {
            for (int j = 0; j<2; ++j) {
                for (int k = 0; k<2; ++k) {
                    bool found = false;
                    for (int f = 0; f<n; ++f) {
                        if (h[i-1][f] + k == h[i][f] + j) {
                            found = true;
                            break;
                        }
                    }

                    if (!found) {
                        dp[i][j] = min(dp[i-1][k] + a[i] * j, dp[i][j]);
                    }
                }
            }
        }

        res += min(dp[n-1][0], dp[n-1][1]);

        dp = vector<vector<ll>>(n, vector<ll>(2, inf));

        dp[0][0] = 0;
        dp[0][1] = b[0];

        for (int i = 1; i<n; ++i) {
            for (int j = 0; j<2; ++j) {
                for (int k = 0; k<2; ++k) {
                    bool found = false;
                    for (int f = 0; f<n; ++f) {
                        if (h[f][i-1] + k == h[f][i] + j) {
                            found = true;
                            break;
                        }
                    }

                    if (!found) {
                        dp[i][j] = min(dp[i-1][k] + b[i] * j, dp[i][j]);
                    }
                }
            }
        }

        res += min(dp[n-1][0], dp[n-1][1]);

        if (res >= inf) {
            cout << "-1\n";
        } else {
            cout << res << '\n';
        }

    }

    return 0;
}
