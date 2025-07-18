#include <bits/stdc++.h>

using ll=long long;
using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;

    while (t--) {
        ll n, m, k;
        cin >> n >> m >> k;

        ll kpern = k/n;

        if (k % n) {
            ++kpern;
        }

        ll space = m - kpern;

        ll res = kpern / (space+1);

        if (kpern % (space+1)) {
            ++res;
        }

        cout << res << '\n';
    }

    return 0;
}
