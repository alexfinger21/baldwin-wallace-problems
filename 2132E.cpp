#include <algorithm>
#include <bits/stdc++.h>

using ll=long long;
using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;

    while (t--) {
        int n, m, q;
        cin >> n >> m >> q;

        vector<ll> a(n);
        vector<ll> b(m);
        vector<ll> pa(n);
        vector<ll> pb(m);

        for (int i = 0; i<n; ++i) {
            cin >> a[i];

        }

        for (int i = 0; i<m; ++i) {
            cin >> b[i];
        }

        sort(a.begin(), a.end(), greater<ll>());
        sort(b.begin(), b.end(), greater<ll>());

        vector<pair<ll, int>> best_combs(n+m);
        
        for (int i = 0; i<n; ++i) {
            pa[i] = a[i];

            if (i) {
                pa[i] = pa[i] + pa[i-1];
            }
        }

        for (int i = 0; i<m; ++i) {
            pb[i] = b[i];
            if (i) {
                pb[i] = pb[i] + pb[i-1];
            }
        }

        int i = 0;
        int j = 0;

        while ((i + j) < n+m) {
            //cout << b[j] << ' ' << a[i] << endl;
            if (m <= j || (i < n && a[i] > b[j])) {
                //cout << "a " << i << ' ' << j << endl;
                best_combs[i+j] = {a[i], i+1};
                ++i;
            } else {
                //cout << "b " << i << ' ' << j << endl;
                best_combs[i+j] = {b[j], i};
                ++j;
            }
        }


        for (int i = 0; i<q; ++i) {
            int x, y, z;
            cin >> x >> y >> z;

            if (!z) {
                cout << "0\n";
                continue;
            }

            if (!x) {
                cout << pb[z-1] << '\n';
                continue;
            } 

            if (!y) {
                cout << pa[z-1] << '\n';
                continue;
            } 
            int l = 0, r = z-1;
            ll res = 0;

            while (l < r) {
                int m = (l+r) >> 1;
                int y_c = m - best_combs[m].second+1; 

                if (best_combs[m].second > x || (y_c > y)) {
                    r = m-1; 
                } else if (best_combs[m].second < x && y_c < y) {
                    l = m+1;
                } else {
                    l = m;
                    break;
                }
            }

            //cout << l << ' ' << best_combs[l].second << endl;

            if (best_combs[l].second == min(x, z)) {
                res = pa[best_combs[l].second-1];
                if (z - best_combs[l].second > 0) {
                    res += pb[z - best_combs[l].second - 1];
                }
            } else {
                res = pb[l - best_combs[l].second];
                if (z - (l - best_combs[l].second + 1) > 0) {
                    res += pa[z - (l - best_combs[l].second + 1) - 1];
                }
            }

            cout << res << '\n';
        }
    }

    return 0;
}
