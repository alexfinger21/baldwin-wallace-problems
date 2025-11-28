#include <bits/stdc++.h>

using ll=long long;
using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;

    while (t--) {
        ll x, y, k;
        cin >> x >> y >> k;

        ll l = 0, r=1e12;
        bool ans = true;

        while (l<r) {
            ll mid = (l+r) >> 1;
            bool f = false;
            ll num = mid;

            for (int i = 0; i<x; ++i) {
                ll rem = num/y;

                if (!(num % y)) {
                    f = true;
                }

                num -= rem;
            }

            if (num < k) {
                l = mid+1;
            } else if ((num > k) || (num == k && f)) {
                r = mid-1;
            } else {
                l = mid;
                r = mid;
            }
        }

        ll num = l;
        for (int i = 0; i<x; ++i) {
            ll rem = num/y;

            if (!(num % y)) {
                ans = false;
            }

            num -= rem;
        }

        if (num != k) {
            ans = false;
        }

        if (ans) {
            cout << l << '\n';
        } else {
            cout << "-1\n";
        }
    }

    return 0;
}
