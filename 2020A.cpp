#include <bits/stdc++.h>

using ll=long long;
using namespace std;

ll logab(ll a, ll b)
{
    return log2(a) / log2(b);
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;

    while (t--) {
        ll n, k;
        cin >> n >> k;

        ll res = 0;

        if (k == 1) {
            cout << n << '\n';
            continue;
        }

        while (n >= k) {
            ll sub = 0;

            for (int i = 1; i<=n/k; ++i) {
                if (pow(k, i) <= n) {
                    sub = pow(k, i);
                } else {
                    break;
                }
            }

            n -= sub;
            ++res;
        }

        res += n;

        cout << res << '\n';
    }

    return 0;
}
