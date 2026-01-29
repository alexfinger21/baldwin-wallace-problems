#include <bits/stdc++.h>

using ll=long long;
using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t, k;
    cin >> t >> k;

    while (t--) {
        ll l, r;
        cin >> l >> r;
        vector<vector<ll>> dp(r, vector<ll>(k+1));

        dp[0][0] = 1;
        dp[0][1] = 1;
    }

    return 0;
}
