#include <bits/stdc++.h>

using ll=long long;
using namespace std;

int32_t main() {
    int t;
    cin >> t;

    while (t--) {
        int a1, a2, b1, b2;

        cin >> a1 >> a2 >> b1 >> b2;

        int res = 0;

        if (a1 > b1) {
            if (a2 > b2 || (a2 == b2)) {
                ++res;
            }
        }

        if (a2 > b1) {
            if (a1 > b2 || (a1 == b2)) {
                ++res;
            }
        }

        if (a1 > b2) {
            if (a2 > b1 || (a2 == b1)) {
                ++res;
            }
        }

        if (a2 > b2) {
            if (a1 > b1 || (a1 == b1)) {
                ++res;
            }
        }

        if (a1 == b1) {
            if (a2 > b2) {
                ++res;
            }
        }

        if (a2 == b1) {
            if (a1 > b2) {
                ++res;
            }
        }

        if (a1 == b2) {
            if (a2 > b1) {
                ++res;
            }
        }

        if (a2 == b2) {
            if (a1 > b1) {
                ++res;
            }
        }

        cout << res << '\n';
    }

    return 0;
}
