#include <bits/stdc++.h>

using ll=long long;
using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;

    ll inf = 1e9+1;
    while (t--) {
        ll n, m, q;
        cin >> n >> m >> q;

        vector<ll> teach(m);
        

        ll closestTop = inf;
        ll closestBottom = inf;

        for (int i = 0; i<m; ++i) {
            cin >> teach[i];
        }

        for (int i = 0; i<q; ++i) {
            ll pos;
            cin >> pos;


            ll bIndx = -1;
            for (auto x : teach) {
                if (pos - x > 0) {
                    closestBottom = min(pos - x, closestBottom);
                    if (closestBottom == pos - x) {
                        bIndx = x;
                    }
                } else if (x - pos > 0) {
                    closestTop = min(x - pos, closestTop);
                }
            }
            if (bIndx != -1) {
                closestBottom = bIndx;
            }
            if (closestTop != inf) {
                closestTop += pos;
            }

            //cout << closestTop << ' ' << closestBottom << endl;
            if (closestTop == inf) {
                cout << (n - pos + pos - closestBottom) << '\n';
            } else if (closestBottom == inf) {
                cout << (pos-1 + closestTop - pos) << '\n';
            } else {
                cout << max(1LL, ((closestTop - closestBottom)/2)) << '\n';
            }
        }



    }

    return 0;
}
