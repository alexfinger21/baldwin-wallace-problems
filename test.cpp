#include <bits/stdc++.h>

using ll=long long;
using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;

    while (t--) {
        ll n;

        cin >> n;

        vector<ll> dp(n+1);

        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i<=n; ++i) {
            dp[i] = dp[i-1] + dp[i-2];
        }

        cout << dp[n] << '\n';
    }

    return 0;
}
