#include <bits/stdc++.h>

using ll=long long;
using namespace std;

int MOD = 998244353;

ll mod_inv(ll x) {
    ll res = 1, y = MOD - 2;
    while (y) {
        if (y & 1) res = res * x % MOD;
        x = x * x % MOD;
        y >>= 1;
    }
    return res;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;

    while (t--) {
        int n, q;
        cin >> n >> q;

        vector<ll> a(n);
        vector<ll> a1(n);
        vector<ll> b(n);
        vector<ll> b1(n);

        for (int i = 0; i<n; ++i) {
            cin >> a[i];
            a1[i] = a[i];
        }

        for (int i = 0; i<n; ++i) {
            cin >> b[i];
            b1[i] = b[i];
        }

        ll res = 1;

        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        for (int i = 0; i<n; ++i) {
            res = (res * min(a[i], b[i])) % MOD;
        }
        cout << res << ' ';

        for (int i = 0; i<q; ++i) {
            int o, x;
            cin >> o >> x;

            if (o - 1) {
                int idx = upper_bound(b.begin(), b.end(), b1[x-1]) - b.begin() - 1;
                if (b[idx] < a[idx]) {
                    res = ((res * mod_inv(b[idx]) % MOD) * (b[idx]+1)) % MOD;
                }
                ++b[idx];
                ++b1[x-1];
            } else {
                int idx = upper_bound(a.begin(), a.end(), a1[x-1]) - a.begin() - 1;
                if (b[idx] > a[idx]) {
                    res = ((res * mod_inv(a[idx]) % MOD) * (a[idx]+1)) % MOD;
                }
                ++a[idx];
                ++a1[x-1];
            }
            cout << res << ' ';
        }

        cout << '\n';
    }

    return 0;
}
