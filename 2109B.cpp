#include <bits/stdc++.h>

using ll=long long;
using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;

    while (t--) {
        ll n, m, a, b;
        cin >> n >> m >> a >> b;

        int res = 1;

        ll og_n = n;
        if ((n - a) >= n/2) {
            n = a;
            res += (int)(ceil(log2(n)) + ceil(log2(m)));
        } else {
            n = n - a + 1;
            res += (int)(ceil(log2(n)) + ceil(log2(m)));
        }

        n = og_n;

        if ((m - b) >= m/2) {
            m = b;
            res = min(res, (int)(1 + ceil(log2(n)) + ceil(log2(m))));
        } else {
            m = m - b + 1;
            res = min(res, (int)(1 + ceil(log2(n)) + ceil(log2(m))));
        }

        cout << res << '\n';
    }

    return 0;
}
