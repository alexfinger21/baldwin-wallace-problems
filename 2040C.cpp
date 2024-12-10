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

        vector<ll> res(n);

        bool found = false;
        ll prev = 0;
        for (int i = n-1; i>=0; --i) {
            ll comp = 2 * Math.pow(2, min(n - i - 1, i));
            if (k <= prev+comp) {
                found = true;
                ll rl = k - comp;

                for (int i = 0; i<n; ++i) {
                }
                break;
            }
            prev += comp;
        }
    }

    return 0;
}
