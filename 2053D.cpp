#include <bits/stdc++.h>

using ll=long long;
using namespace std;

ll mod = 998244353;

ll mod_inv(ll x, ll m) {
    ll res = 1, y = m - 2;
    while (y) {
        if (y & 1) res = res * x % m;
        x = x * x % m;
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

        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        vector<ll> a_c(n);
        vector<ll> b_c(n);
        map<ll, ll> latest_idx_a;
        map<ll, ll> latest_idx_b;

        a_c = a;
        b_c = b;

        for (int i = 0; i<n; ++i) {
            auto af = find(a.begin(), a.end(), a1[i]);

            if (!latest_idx_a.count(a1[i])) {
                latest_idx_a[a1[i]] = af - a.begin();
            } else {
                latest_idx_a[a1[i]] = max(latest_idx_a[a1[i]], (ll)(af-a.begin()));
            }

            a1[i] = af - a.begin();
            *af = -1;

            auto bf = find(b.begin(), b.end(), b1[i]);

            if (!latest_idx_b.count(b1[i])) {
                latest_idx_b[b1[i]] = bf - b.begin();
            } else {
                latest_idx_b[b1[i]] = max(latest_idx_b[b1[i]], (ll)(bf-b.begin()));
            }

            b1[i] = bf - b.begin();
            *bf = -1;
        }
        a = a_c;
        b = b_c;

        ll res = 1;

        for (int i = 0; i<n; ++i) {
            res = (res * min(a[i], b[i])) % mod;
        }

        cout << res << ' ';
        
        /*
        for (auto x : a) {
            cout << x << ' ';
        }
        cout << endl;

        for (auto x : b) {
            cout << x << ' ';
        }
        cout << endl;
        */

        for (int i = 0; i<q; ++i) {
            int o, x;
            cin >> o >> x;

            if (o - 1) {
                ll idx = latest_idx_b[b[b1[x-1]]];
                --latest_idx_b[b[b1[x-1]]];
                b1[x-1] = idx;
                ++b[idx];
                //cout << "b " << idx << ' ' << b[idx] << ' ' << a[idx] << endl;
                if (b[idx] <= a[idx]) {
                    res = (res * mod_inv(b[idx] - 1, mod) % mod * b[idx]) % mod;
                }
                if (!latest_idx_b.count(b[idx])) {
                    latest_idx_b[b[idx]] = idx;
                }
            } else {
                ll idx = latest_idx_a[a[a1[x-1]]];
                --latest_idx_a[a[a1[x-1]]];
                a1[x-1] = idx;
                ++a[idx];
                //cout << "a " << idx << ' ' << b[idx] << ' ' << a[idx] << endl;
                if (a[idx] <= b[idx]) {
                    res = (res * mod_inv(a[idx] - 1, mod) % mod * a[idx]) % mod;
                }
                if (!latest_idx_a.count(a[idx])) {
                    latest_idx_a[a[idx]] = idx;
                }
            }
            cout << res << ' ';
            /*
            for (auto x : a) {
                cout << x << ' ';
            }
            cout << endl;

            for (auto x : b) {
                cout << x << ' ';
            }
            cout << endl;
            */
        }
        cout << '\n';
    }

    return 0;
}
