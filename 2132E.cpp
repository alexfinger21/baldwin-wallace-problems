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

        vector<int> bgra(n, m+1);
        
        for (int i = 0; i<n; ++i) {
            pa[i] = a[i];
            auto idx = upper_bound(b.rbegin(), b.rend(), a[i]);

            if (idx == b.rend()) {
                bgra[i] = 0;
            } else {
                bgra[i] = (idx).base() - b.begin();
            }
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

        /*
        for (auto x : pa) {
            cout << x << ' ';
        }
        cout << endl;

        for (auto x : pb) {
            cout << x << ' ';
        }
        cout << endl;
        */
    
        for (int i = 0; i<q; ++i) {
            int x, y, z;
            cin >> x >> y >> z;

            if (z && x) {
                int x_bnd = min(x, z);
                ll res = 0;
                if (min(y,z) > 0) res = pb[min(y,z)-1];

                if (x >= z) {
                    res = max(res, pa[z-1]);
                } else {
                    res = max(res, pa[x-1] + (min(z-x_bnd-1, y-1) >= 0 ? pb[min(z-x_bnd-1, y-1)] : 0));
                }

                int l = 0, r = min(x, z)-2;

                while (l < r) {
                    int m = (l + r) >> 1;

                    int bgr = bgra[m];
                    int bgr2 = bgra[m+1];
                    //cout << m << ' ' << bgr << ' ' << bgr2 << endl;
                    //cout << l << ' ' << r << endl;

                    if (1 + m + bgr > z) {
                        r = m-1;
                    } else if ((1 + m + bgr < z && 1 + m + bgr2 <= z)) {
                        l = m+1;
                    } else {
                        if ((m + 1 + max(0, min(y, z - m - 1))) < z) {
                            l = m+1;
                            continue;
                        }
                        //cout << "HERE" << endl;
                        res = max(res, pa[m] + (min(y-1, z - m - 2) >= 0 ? pb[min(y-1, z - m - 2)] : 0));
                        break;
                    }
                }

                res = max(res, pa[l] + (min(y-1, z - l - 2) >= 0 ? pb[min(y-1, z - l - 2)] : 0));

                cout << res << "\n";
            } else if (!z) {
                cout << "0\n";
            } else {
                cout << pb[min(y, z) - 1] << '\n';
            }
        }
    }

    return 0;
}
