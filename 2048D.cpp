#include <bits/stdc++.h>

using ll = long long;
using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    int og = t;

    while (t--) {
        ll n, m;
        cin >> n >> m;

        priority_queue<ll> a;
        priority_queue<ll> b;

        ll kv;
        cin >> kv;

        for (int i = 1; i < n; ++i) {
            ll nm;
            cin >> nm;
            if (nm > kv) {
                a.push(nm);
            }
        }

        for (int i = 0; i < m; ++i) {
            ll nm;
            cin >> nm;
            if (nm <= kv) {
                nm = 1e9+1;
            }
            b.push(nm);
        }

        vector<ll> hrated;
        hrated.reserve(m);
        while (!b.empty()) {
            hrated.push_back(b.top());
            b.pop();
        }

        vector<ll> plrs;
        plrs.reserve(n);
        vector<ll> hpts(hrated.size());
        
        while (!a.empty()) {
            plrs.push_back(a.top());
            a.pop();
        }

        int p_idx = 0;

        for (int i = 0; i<hrated.size(); ++i) {
            //cout << hrated[i] << ' ' << plrs[p_idx] << endl;
            while (hrated[i] <= plrs[p_idx] && p_idx < plrs.size()) {
                ++p_idx;
            }
            //cout << p_idx << " - IDX" << endl;

            hpts[i] = p_idx;
        }

        for (ll k = 1; k <= m; ++k) {
            ll res = m/k;
            ll rem = m%k;

            for (int i = max(0LL, min(k-1, (ll)(hpts.size())-rem-1LL)); i<(ll)(hpts.size())-rem; i+=k) {
                //cout << "idx: " << i << " # of people " << hpts[i] << endl;
                res += hpts[i];
            }
            cout << res << ' ';
        }

        cout << '\n';
    }

    return 0;
}

