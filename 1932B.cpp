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

        for (int i = 0; i<n; ++i) {
            ll num;
            cin >> num;

            res = (res/num+1LL)*num;
        }

        cout << res << '\n';
    }

    return 0;
}
