#include <bits/stdc++.h>

using ll=long long;
using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;

    while (t--) {
        ll n, x;
        cin >> n >> x;

        int bc = 0;
        ll og_x = x;
        while (x > 0) {
            if (x % 2) {
                ++bc;
            }
            x /= 2;
        }

        x = og_x;

        if (n == 1 && x == 0) {
            cout << "-1\n";
            continue;
        } else if (bc >= n) {
            cout << x << '\n';
        } else if (x == 0) {
            if (n % 2) {
                cout << (n+3) << '\n';
            } else {
                cout << (n) << '\n';
            }
        } else if (x == 1) {
            if (n % 2) {
                cout << (n) << '\n';
            } else {
                cout << (n+3) << '\n';
            }
        } else {
            if ((n - bc) % 2) {
                cout << (x + (n - bc) + 1) << '\n';
            } else {
                cout << (x + (n - bc)) << '\n';
            }
        }
    }

    return 0;
}
