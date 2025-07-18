#include <bits/stdc++.h>

using ll=long long;
using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;

    while (t--) {
        ll n, k;

        cin >> n >> k;

        map<ll, pair<ll, ll>> cs;

        for (int i = 0; i<n; ++i) {
            ll l, r, ri;

            cin >> l >> r >> ri;

            if (ri > k) {
                if (!cs.count(ri)) {
                    cs[ri] = {l, r};
                } else if (cs[ri].first > l) {
                    cs[ri] = {l, r};
                }
            }
        }
        
        for (auto x : cs) {
            if (k >= x.second.first) {
                k = x.first;
            }
        }

        cout << k << '\n';
    }

    return 0;
}
