#include <bits/stdc++.h>

using ll=long long;
using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;

    while (t--) {
        ll a,b,x,y;
        cin >> a >> b >> x >> y;

        if (a > b && (!(a % 2) || (a - b) > 1)) {
            cout << "-1\n";
        } else if (a == b) {
            cout << "0\n";
        } else if ((a - b) == 1 && (a % 2)) {
            cout << y << "\n";
        } else {
            ll res = 0;

            while (a < b) {
                if (a % 2 || (x < y)) {
                    res += x;
                } else {
                    res += y;
                }
                ++a;
            } 

            cout << res << '\n';
        }
    }

    return 0;
}
