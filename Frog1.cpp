#include <bits/stdc++.h>

using ll=long long;
using namespace std;

int32_t main() {
    int n;
    cin >> n;

    vector<ll> dp(n);
    vector<ll> h(n);

    for (int i = 0; i<n; ++i) {
        cin >> h[i];
    }

    dp[0] = 0;
    dp[1] = abs(h[1] - h[0]);

    for (int i = 2; i<n; ++i) {
        dp[i] = min(abs(h[i] - h[i-1])+dp[i-1], abs(h[i]-h[i-2]) + dp[i-2]);
    }

    cout << dp[n-1] << '\n';

    return 0;
}
