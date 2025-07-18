#include <bits/stdc++.h>

using ll=long long;
using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;

    while (t--) {
        ll n, l, r, k;
        cin >> n >> l >> r >> k;

        if (n % 2) {
            cout << l << '\n';
            continue;
        }

        ll nxt = 0;
        for (int i = 62; i>=0; --i) {
            if (pow(2, i) <= l) {
                nxt = pow(2, i+1);
                break;
            }
        }

        if (nxt > r || n == 2) {
            cout << "-1\n";
        } else {

            if (k < (n-1)) {
                cout << l << '\n';
            } else {
                cout << nxt << '\n';
            }
        }
    }

    return 0;
}
