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

        vector<int> a(n), b(n);
        vector<int> aa(n), bb(n);
        vector<pair<int, int>> ar(n);
        ll res = 0;
        for (int i = 0; i<n; ++i) {
            cin >> a[i];
        }

        for (int i = 0; i<n; ++i) {
            cin >> b[i];
            if (b[i] < a[i]) {
                a[i] ^= b[i];
                b[i] ^= a[i];
                a[i] ^= b[i];
            }
            res += abs(b[i] - a[i]);
            ar[i] = {b[i], a[i]};
        }
        

        sort(ar.begin(), ar.end());

        int mdif = ar[1].first - ar[0].first;
        for (int i = n-1; i>0; --i) {
            mdif = min(ar[i].second - ar[i-1].first, mdif);
            if (!mdif) {
                break;
            }
        }
        mdif = max(mdif, 0);

        res += mdif*2;

        cout << res << '\n';
    }

    return 0;
}
