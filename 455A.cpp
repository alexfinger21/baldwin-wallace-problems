#include <bits/stdc++.h>

using ll=long long;
using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    map<ll, ll> m;

    ll n; 
    cin >> n;

    vector<ll> a(n);

    for (ll i = 0; i<n; ++i) {
        cin >> a[i];
        m[a[i]]++;
    }

    n = m.size();
    vector<pair<ll, ll>> dp(n);

    ll prev = -1;
    ll i = 0;
    for (auto x : m) {
        if (prev == -1) {
            dp[i].first = 0;
            dp[i].second = x.first * x.second;
        } else {
            dp[i].first = max(dp[i-1].first, dp[i-1].second);
            if (x.first - prev == 1) {
                dp[i].second = dp[i-1].first + x.first*x.second;
            } else {
                dp[i].second = dp[i].first + x.first*x.second;
            }
        }
        //cout << dp[i].first << ' ' << dp[i].second << ' ' << prev << endl;
        //cout << x.first << ' ' << x.second << endl;
        ++i;
        prev = x.first;
    }

    cout << max(dp[n-1].first, dp[n-1].second) << '\n';

    return 0;
}
