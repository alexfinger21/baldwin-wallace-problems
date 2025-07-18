#include <bits/stdc++.h>

using ll=long long;
using namespace std;

int32_t main() {
    int t;
    cin >> t;

    while (t--) {
        int n, s, m;

        cin >> n >> s >> m;

        bool found = false;
        int last = 0;

        for (int i = 0; i<n; ++i) {
            int l, r;
            cin >> l >> r;

            if ((l - last) >= s) {
                found = true;
            }

            last = r;
        }

        if (m - last >= s) {
            found = true;
        }

        if (found) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}
