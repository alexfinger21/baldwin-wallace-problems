#include <bits/stdc++.h>

using ll=long long;
using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, k;

    cin >> n >> k;

    if (k > n) {
        cout << "come on man\n";
    }

    vector<ll> dp(k+1);

    for (ll i = 0; i<=n; ++i) {
        for (ll j = k-min(i, k); j<=k; ++j) {
            if ((j == k-min(i, k) && i <= k) || j == k) {
                dp[j] = 1;
            } else {
                dp[j] += dp[j+1]; 
            }
        }
    }

    cout << dp[0] << '\n';

    return 0;
}
