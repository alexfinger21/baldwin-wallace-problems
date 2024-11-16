#include <bits/stdc++.h>

using ll=long long;
using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<ll> a(n);

        ll maxa = 0;

        for (int i = 0; i<n; ++i) {
            cin >> a[i];
        }

        if (n == 2) {
            cout << min(a[0], a[1]) << '\n';
            continue;
        }
        for (int i = 0; i<n; ++i) {
            ll m1, m2;
            if (i == 0) {
                m1 = min(a[i+1], a[i+2]);
                m2 = max(a[i+1], a[i+2]);
            } else if (i == n-1) {
                m1 = min(a[i-1], a[i-2]);
                m2 = max(a[i-1], a[i-2]);
            } else {
                m1 = min(a[i-1], a[i+1]);
                m2 = max(a[i-1], a[i+1]);
            }

            if (m1 <= a[i] && m2 >= a[i]) {
                maxa = max(a[i], maxa);
            } else if (m1 >= a[i] && m1 <= m2) {
                maxa = max(m1, maxa);
            } else {
                maxa = max(m2, maxa);
            }

        }
        cout << maxa << '\n';
    }

    return 0;
}
