#include <bits/stdc++.h>

using ll=long long;
using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;

    while (t--) {
        ll l, r;
        cin >> l >> r;

        int res = 0;

        int inc = 0;

        for (int i = 0; i<=r-l; ++i) {
            ++res;
            i += inc++;
        }

        cout << res << '\n';
    }

    return 0;
}
