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

        ll nms = n / k;
        ll prev = 1;
        ll prev2 = nms + 1;
        for (int i = 1; i<=n; ++i) {
            if (!(i % k)) {
                cout << prev << ' ';
                ++prev;
            } else {
                cout << prev2 << ' ';
                ++prev2;
            }
        }

        cout << '\n';
    }

    return 0;
}
