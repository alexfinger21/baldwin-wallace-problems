#include <bits/stdc++.h>
#include <cmath>

using ll=long long;
using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;

    while (t--) {
        int l, r;

        cin >> l >> r;

        ll res = 0;

        vector<int> s(r-l+1);

        int cnt = 0;
        int diff = r-pow(2,(int)(log2(r)));

        for (int i = 0; i<diff; ++i) {
            s[i] = diff-i;
            res += s[i] | i;
        }

        for (int i = diff; i<=r-diff*2; ++i) {
            int n = r-i;
            s[i] = n;

            res += n | i;
        }

        for (int i = r-diff*2+1; i<=r; ++i) {
            int n = r - (i - (r-diff*2+1));
            s[i] = n;

            res += n | i;
        }

        cout << res << '\n';
        for (auto x : s) {
            cout << x << ' ';
        }
        cout << '\n';
    }

    return 0;
}
