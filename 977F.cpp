#include <bits/stdc++.h>

using ll=long long;
using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;


    vector<ll> a(n);
    map<ll, ll> dp;

    ll maxn = 0;

    for (int i = 0; i<n; ++i) {
        cin >> a[i];


        ll old = dp[a[i]];
        dp[a[i]] = max(dp[a[i]-1] + 1, dp[a[i]]);

        if (dp[a[i]] > dp[maxn]) {
            maxn = a[i];
        }
    }

    cout << dp[maxn] << '\n';

    maxn -= dp[maxn] - 1;

    for (int i = 0; i<n; ++i) {
        if (a[i] == maxn) {
            cout << i+1 << ' ';
            ++maxn;
        }
    }

    cout << '\n';

    return 0;
}
