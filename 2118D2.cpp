#include <bits/stdc++.h>

using ll=long long;
using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        vector<ll> p(n);
        vector<ll> d(n);

        ll min_p = 1e15 + 1, max_p = 0;

        for (int i = 0; i<n; ++i) {
            cin >> p[i];

            min_p = min(min_p, p[i]);
            max_p = max(max_p, p[i]);
        }

        for (int i = 0; i<n; ++i) {
            cin >> d[i];
        }


        int q;
        cin >> q;

        for (int i = 0; i<q; ++i) {
            ll pos;
            cin >> pos;

            int res = 0;

            int idx = lower_bound(p.begin(), p.end(), pos) - p.begin();
            if (idx == p.size()) {
                cout << "YES\n";
                continue;
            }
            int dir = 1;
            ll t = p[idx] - pos;
            pos = p[idx];

            vector<array<int, 2>> triggers(n, {0, 0});

            while (res == 0) {
                //cout << pos << ' ';
                if ((t - d[idx]) >= 0 && !((t-d[idx]) % k)) {
                    dir = !dir;
                    if (triggers[idx][dir]) {
                        res = -1;
                        break;
                    } else {
                        triggers[idx][dir] = 1;
                    }
                }
                
                if (dir) {
                    if (idx < n-1) {
                        ++idx;
                        t += p[idx] - pos;
                        pos = p[idx];
                    } else {
                        res = 1;
                        break;
                    }
                } else {
                    if (idx > 0) {
                        --idx;
                        t += pos - p[idx];
                        pos = p[idx];
                    } else {
                        res = 1;
                        break;
                    }
                }
            }

            if (res > 0) {
                cout << "YES\n"; 
            } else {
                cout << "NO\n"; 
            }
        }

    }

    return 0;
}
