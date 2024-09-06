#include <bits/stdc++.h>

using ll=long long;
using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;

    while (t--) {
        ll x, y, k;
        cin >> x >> y >> k;

        ll mv1 = x/k + (x%k ? 1 : 0);
        ll mv2 = y/k + (y%k ? 1 : 0);

        if (mv1 > mv2) {
            cout << mv1 + mv2 + (mv1 - mv2 - 1) << '\n';
        } else {
            cout << mv1 + mv2 + (mv2 - mv1) << '\n';
        }
    }

    return 0;
}
