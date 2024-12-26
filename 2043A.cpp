#include <bits/stdc++.h>

using ll=long long;
using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;

    while (t--) {
        ll n;
        cin >> n;

        ll res = 1;

        while (n > 3) {
            res *= 2;
            n /= 4;
        }

        cout << res << '\n';
    }

    return 0;
}
