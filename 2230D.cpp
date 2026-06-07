#include <bits/stdc++.h>

using ll=long long;
using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        ll res = 0;

        vector<ll> dp(n + 1);
        vector<int> inc(n + 1);
        vector<ll> a(n);
        vector<ll> b(n);

        for (int i = 0; i<n; ++i) {
            cin >> a[i];
        }

        for (int i = 0; i<n; ++i) {
            cin >> b[i];
        }

        ll sm = 0;

        for (int i = 0; i<n; ++i) {
            int n1 = a[i];
            int n2 = b[i];

            ++dp[0];
            ++sm;

            if (n1 == n2) {
                dp[n1] += dp[n1 - 1];
                dp[n1 - 1] = 0;
            } else {
                sm -= dp[n1 - 1] + dp[n2 - 1];
                dp[n1 - 1] = 0;
                dp[n2 - 1] = 0;
            }

            res += sm;
        }

        cout << res << '\n';
    }

    return 0;
}
