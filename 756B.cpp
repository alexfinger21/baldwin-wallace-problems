#include <bits/stdc++.h>

using ll=long long;
using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<ll> a(n);
    vector<ll> dp(n);

    for (int i = 0; i<n; ++i) {
        cin >> a[i];
        if (i < 1) {
            dp[i] = 20;
        } else {
            ll m = dp[i-1] + 20;
            auto l1 = upper_bound(a.begin(), a.begin() + i, a[i] - 90);
            if (l1 != a.end() && (l1 - a.begin()) != 0) {
                m = min(dp[(l1-a.begin() > i ? i : l1-a.begin()) - 1] + 50, m);
            } else {
                m = min(m, 50LL);
            }

            l1 = upper_bound(a.begin(), a.begin()+i, a[i] - 1440);
            if (l1 != a.end() && (l1 - a.begin()) != 0) {
                m = min(dp[(l1-a.begin() > i ? i : l1-a.begin()) - 1] + 120, m);
            } else {
                m = min(m, 120LL);
            }

            dp[i] = m;
        }

        if (i != 0) {
            cout << dp[i] - dp[i-1] << '\n';
        } else {
            cout << dp[i] << '\n';
        }
    }


    return 0;
}
