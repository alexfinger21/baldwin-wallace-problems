#include <bits/stdc++.h>

using ll=long long;
using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;

    while (t--) {
        ll n, s, x;
        cin >> n >> s >> x;

        vector<ll> a(n);

        ll res = 0;

        vector<int> b_idx;
        vector<int> g_idx;

        for (int i = 0; i<n; ++i) {
            cin >> a[i];

            if (a[i] > x) {
                b_idx.push_back(i);
            }
        }

        b_idx.push_back(n);

        int b_b = -1;
        int b_f = -1;


        for (auto c : b_idx) {
            map<ll, ll> prefix;
            map<ll, ll> new_prefix;

            b_b = b_f;
            b_f = c;

            ll latest_max_idx = -1;
            ll sm = 0;

            for (int i = b_b + 1; i<b_f; ++i) {
                if (a[i] == x) {
                    latest_max_idx = i;
                    for (auto x : new_prefix) {
                        prefix[x.first] += x.second;
                        //cout << x.first << ' ' << prefix[x.first] << endl;
                    }
                    new_prefix.clear();
                }

                sm += a[i];

                if (latest_max_idx != -1) {
                    if (prefix.count(sm - s)) {
                        //cout << "rem: " << prefix[sm - s] << ' ' << "sum: " << sm  << " need: "<< (sm - s) << " idx: " << i << endl;
                        res += prefix[sm - s]; 
                    } 

                    if (sm == s) {
                        ++res;
                    }
                }

                new_prefix[sm] += 1;
            }

            prefix.clear();
            prefix[0] = 1;
        }

        cout << res << '\n';
    }

    return 0;
}
