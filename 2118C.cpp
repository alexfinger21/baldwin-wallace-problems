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

        vector<int> open_bits(63);

        vector<ll> a(n);

        ll res = 0;

        for (int i = 0; i<n; ++i) {
            cin >> a[i];

            for (int j = 62; j>=0; --j) {
                if (a[i] >= pow(2, j)) {
                    a[i] -= pow(2, j);
                    ++res;
                } else {
                    ++open_bits[j];
                }
            }
        }

        int pos = 0;
        while (k > 0) {
            if (pow(2, pos) * open_bits[pos] <= k) {
                res += open_bits[pos];
                k -= pow(2, pos) * open_bits[pos];
            } else {
                res += k/(pow(2, pos));
                break;
            }
            ++pos;
        }
        cout << res << '\n';
    }

    return 0;
}
