#include <bits/stdc++.h>

using ll=long long;
using namespace std;

ll mod = 998244353;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<ll> dp(n+1);
        vector<bool> isL(n);

        ll res = 0;
        int pp = -1;
        int p = -1;

        dp[0] = 1;
        for (int i = 1; i<=n; ++i) {
            ll nn;
            cin >> nn;

            if (p == -1) {
                if (!nn) {
                    ++dp[i];
                }
            } else if (pp == -1) {
                if (nn == 1) {
                    ++dp[i];
                }

                if (p == nn) {
                    dp[i] += dp[i-1];
                }
            } else {
                if (p == nn) {
                    dp[i] = (dp[i] + dp[i-1]) % mod;
                }

                if (pp+1 == nn) {
                    dp[i] = (dp[i] + dp[i-2]) % mod;
                }
            }
            
            pp = p;
            p = nn;
        }

        res = (dp[n] + dp[n-1]) % mod;

        cout << res << '\n';
    }

    return 0;
}
