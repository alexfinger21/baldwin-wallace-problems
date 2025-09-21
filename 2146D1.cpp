#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;

    while (t--) {

        int l, r;
        cin >> l >> r;

        int n = r - l + 1;

        vector<int> a(n, -1);
        vector<char> used(n, 0);

        ll ans = 0;

        for (int x = r; x >= l; --x) {
            int idx = x - l;
            if (used[idx]) continue;

            int k = 0;
            while ((1 << k) <= x) k++;
            int M = (1 << k) - 1;
            int y = M - x;
            int jdx = y - l;

            used[idx] = 1;
            if (jdx >= 0 && jdx < n && !used[jdx]) {
                used[jdx] = 1;
                a[idx] = y;
                a[jdx] = x;
                ans += 2LL * M;
            } else {
                a[idx] = x;
                ans += M;
            }
        }

        cout << ans << '\n';
        for (int i = 0; i < n; ++i) {
            if (i) cout << ' ';
            cout << a[i];
        }
        cout << '\n';
    }

    return 0;
}

