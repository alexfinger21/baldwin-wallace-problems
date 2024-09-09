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

        if (n == 1) {
            cout << k << '\n';
        } else {
            ll res = 0;

            for (ll i = 1; i<k; i*=2) {
                res += i;
                k -= i;
            }

            cout << res << ' ' << k << ' ';

            for (int i = 2; i<n; ++i) {
                cout << "0 ";
            }

            cout << '\n';
        }
    }

    return 0;
}
