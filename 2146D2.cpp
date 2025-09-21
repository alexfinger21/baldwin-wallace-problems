#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        ll l, r;
        cin >> l >> r;
        int n = int(r - l + 1);
        vector<ll> a(n, -1);
        vector<char> used(n, 0);
        ll ans = 0;

        for (ll x = r; x >= l; --x) {
            int i = int(x - l);
            if (used[i]) continue;
            bool paired = false;
            for (int k = 0; k <= 60; ++k) {
                ll M = ( (k==63) ? (ll)LLONG_MAX : ((1LL << k) - 1) );
                if (M < x + l) continue;
                if (M > x + r) break;
                ll y = M - x;
                int j = int(y - l);
                if (j >= 0 && j < n && !used[j]) {
                    used[i] = 1;
                    used[j] = 1;
                    a[i] = y;
                    a[j] = x;
                    ans += 2LL * M;
                    paired = true;
                    break;
                }
            }
            if (!paired) {
                used[i] = 1;
                a[i] = x;
                ans += x;
            }
        }

        cout << ans << '\n';
        for (int i = 0; i < n; ++i) {
            if (i) cout << ' ';
            cout << a[i];
        }
        cout << '\n';
    }

    return 0;
}

