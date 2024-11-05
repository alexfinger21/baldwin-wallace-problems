#include <bits/stdc++.h>

using ll=long long;
using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    int n = 2e5;
    vector<int> dp(n+1);
    vector<int> dp2(n+1);
    ll res = 0;
    for (int i = 1; i<=n; ++i) {
        dp[i] = dp[i/10] + i%10;
        res += dp[i];
        dp2[i] = res;
    }
    while (t--) {
        int nn;
        cin >> nn;

        cout << dp2[nn] << '\n';
    }

    return 0;
}
