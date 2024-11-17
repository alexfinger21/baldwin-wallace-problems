#include <bits/stdc++.h>

using ll=long long;
using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;

    while (t--) {
        ll n, m, v;
        cin >> n >> m >> v;

        vector<ll> a(n);
        ll tot = 0;

        for (int i = 0; i<n; ++i) {
            cin >> a[i];
            tot += a[i];
        }

        vector<ll> f_sm(n);
        vector<ll> min_per_m(n+1, -1);
        ll n_fw = 0;

        ll cnt = 0;
        for (int i = 0; i<n; ++i) {
            f_sm[i] = a[i] + (i>0 ? f_sm[i-1] : 0);
            cnt += a[i];

            if (cnt >= v) {
                ++n_fw;
                cnt = 0;
                min_per_m[n_fw] = i; 
            }
        }

        vector<ll> min_per_mb(n+1, -1);
        min_per_mb[0] = -2;
        vector<ll> b_sm(n);
        n_fw = 0;

        cnt = 0;
        for (int i = n-1; i>=0; --i) {
            b_sm[i] = a[i] + (i<n-1 ? b_sm[i+1] : 0);
            cnt += a[i];

             if (cnt >= v) {
                ++n_fw;
                min_per_mb[n_fw] = i; 
                cnt = 0;
            }
        }

        ll res = -1;
        for (int i = 0; i<=m; ++i) {
            ll prev = i != 0 ? min_per_m[i] : 0;
            ll post = min_per_mb[m-(i == -1 ? 0 : i)];
            //cout << prev << ' ' << i << ' ' << post << endl;
            //cout << f_sm[prev] << ' ' << i << ' ' << b_sm[post] << endl;
            if (post != -1 && prev != -1) {
                res = max(res, tot - (i != 0 ? f_sm[prev] : 0) - (post > -1 ? b_sm[post] : 0));

            }
        }

        cout << res << '\n';

    }

    return 0;
}
