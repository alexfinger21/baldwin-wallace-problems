#include <bits/stdc++.h>

using ll=long long;
using namespace std;

const ll mod = 1e9 + 7;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t, k;
    cin >> t >> k;

    vector<ll> sums(1e5 + 1);
    vector<ll> dp(1e5 + 1);

    ll sm = 0;
    sums[0] = sm;
    dp[0] = 1;

    for (int i = 1; i<=1e5; ++i) {
        dp[i] = dp[i-1];
        dp[i] %= mod;

        if (i >= k) {
            dp[i] += dp[i-k];
        }
        sm += dp[i];
        sums[i] = sm;
        dp[i] %= mod;

        //cout << "here: " << dp[i][0] << ' ' << i << endl;

    }

    while (t--) {
        ll l, r;
        cin >> l >> r;

        ll res = (sums[r] - (l >= 2 ? sums[l-1] : 0)) % mod;

        cout << res << '\n';
    }

    return 0;
}
