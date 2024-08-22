#include <bits/stdc++.h>

using ll=long long;
using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;

    while (t--) {
        int l, r, L, R;
        cin >> l >> r >> L >> R;

        int res = 0;

        if (min(l, L) < max(l, L)) {
            ++res;
        }

        if (min(r, R) < max(r, R)) {
            ++res;
        }

        if (l > L) {
            l ^= L;
            L ^= l;
            l ^= L;
            r ^= R;
            R ^= r;
            r ^= R;
        }

        if (r < L) {
            --res;
        }

        for (int i = max(l, L)+1; i<=min(r, R); ++i) {
            ++res;
        }

        cout << res << '\n';
    }

    return 0;
}
