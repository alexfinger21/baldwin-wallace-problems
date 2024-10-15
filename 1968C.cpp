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

        vector<ll> x(n-1);
        vector<ll> a(n);

        for (int i = 0; i<n-1; ++i) {
            cin >> x[i];
        }

        a[0] = x[0]+1;

        for (int i = 1; i<n; ++i) {
            if (i < n-1) {
                ll r1 = (x[i]+1)%a[i-1];
                ll other = a[i-1] - r1;
                a[i] = x[i] + 1 + other + x[i-1];
            } else {
                a[i] = x[i-1];
            }
        }

        for (auto x : a) {
            cout << x << ' ';
        }

        cout << '\n';
    }

    return 0;
}
