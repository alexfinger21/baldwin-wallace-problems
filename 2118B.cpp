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

        cout << (2*n - 1) << '\n';

        cout << "1 1 " << n << '\n';

        for (int i = 2; i<=n; ++i) {
            cout << i << ' ' << "1" << ' ' << i-1 << '\n';
            cout << i << ' ' << i << ' ' << n << '\n';
        }
    }

    return 0;
}
