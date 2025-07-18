#include <bits/stdc++.h>

using ll=long long;
using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;

    while (t--) {
        int l, r;
        cin >> l >> r;
        if (!(l % 2)) {
            ++l;
        }

        if (!(r % 2)) {
            --r;
        }

        if ((r-l+1)>=3) {
            cout << 1 + (r-l-2)/4 << '\n';
        } else {
            cout << "0\n";
        }
    }

    return 0;
}
