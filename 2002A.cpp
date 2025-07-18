#include <bits/stdc++.h>

using ll=long long;
using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;

    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;

        ll res = min(0LL+k, 0LL+n) * min(0LL+k, 0LL+m);

        cout << res << '\n';
    }

    return 0;
}
