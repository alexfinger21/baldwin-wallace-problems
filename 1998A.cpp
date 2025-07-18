#include <bits/stdc++.h>

using ll=long long;
using namespace std;

int32_t main() {
    int t;
    cin >> t;

    while (t--) {
        ll x, y, k;

        cin >> x >> y >> k;

        if ((k % 2)) {
            cout << x << ' ' << y << '\n';
        }

        for (int i = 1; i<=k/2; ++i) {
            cout << x+i << ' ' << y+i << '\n';  
        }

        for (int i = 1; i<=k/2; ++i) {
            cout << x-i << ' ' << y-i << '\n';  
        }

    }

    return 0;
}
