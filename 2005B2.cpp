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
        


        for (int i = 0; i<m; ++i) {
            cin >> teach[i];
        }

        sort(teach.begin(), teach.end());

        for (int i = 0; i<q; ++i) {
            ll closestTop = inf;
            ll closestBottom = inf;
            ll pos;
            cin >> pos;



            auto lower = lower_bound(teach.begin(), teach.end(), pos);
            auto upper = upper_bound(teach.begin(), teach.end(), pos);
            if (lower != teach.begin()) {
                closestBottom = *(lower-1);
            }
            if (upper != teach.end()) {
                closestTop = *upper;
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
