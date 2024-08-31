#include <bits/stdc++.h>

using ll=long long;
using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;

    while (t--) {
        ll n, m;
        cin >> n >> m;

        vector<ll> a(n);

        for (int i = 0; i<n; ++i) {
            cin >> a[i];
        }

        sort(a.begin(), a.end());

        int start = 0;
        ll s = 0;

        ll maxS = 0;

        for (int i = 0; i<n; ++i) {
            s += a[i];
            while (start <= i && (s > m || (a[i] - a[start]) > 1)) {
                s -= a[start];
                ++start;
            }
            maxS = max(maxS, s);
        }

        cout << maxS << '\n';
    }

    return 0;
}
