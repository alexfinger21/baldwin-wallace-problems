#include <bits/stdc++.h>

using ll=long long;
using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;

    while (t--) {
        set<ll> a;

        int n;
        cin >> n;
        vector<ll> nn(n);


        ll minx = 1e9;
        for (int i = 0; i<n ; ++i) {
            ll nm;
            cin >> nm;

            nn[i] = nm;
            minx = min(nm, minx);
        }

        for (auto x : nn) {
            a.insert(x - minx);
        }

        vector<ll> diffs(a.size());

        int idx = 0;
        for (auto x : a) {
            diffs[idx] = x;
            ++idx;
        }

        int res = 0;

        for (int i = 0; i<diffs.size(); ++i) {
            res = max(res, (int)(upper_bound(diffs.begin(), diffs.end(), diffs[i]+n-1) - diffs.begin() - i));
        }

        cout << res << '\n';

    }

    return 0;
}
