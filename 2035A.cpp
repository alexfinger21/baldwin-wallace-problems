#include <bits/stdc++.h>

using ll=long long;
using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;

    while (t--) {
        ll n, m, r, c;
        cin >> n >> m >> r >> c;

        ll res = 0;
        res += m-c;

        res += (n-r)*(m-1) + (n-r)*m;

        cout << res << '\n';
    }

    return 0;
}
