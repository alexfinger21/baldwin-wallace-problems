#include <bits/stdc++.h>

using ll=long long;
using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        ll res = 0;

        ll one = 0;
        ll space = 0;

        ll c;
        for (int i = 0; i<n; ++i) {
            cin >> c;

            if (c > 1) {
                res += c;
                
                space += c / 2 - 1;
            } else {
                ++one;
            }
        }


        if (res > 0 && (n - one) == 1 && one > 0) {
            cout << (res + (min(space + 1, one))) << '\n';
        } else if (res > 2) {
            cout << (res + min(space, one)) << '\n';
        } else {
            cout << "0\n";
        }

    }

    return 0;
}
