#include <bits/stdc++.h>
using ll = long long;

using namespace std;

int32_t main() {
    int t;
    cin >> t;

    while (t--) {
        int n, x;

        cin >> n >> x;

        vector<ll> a(n);

        for (int i = 0; i<n; ++i) {
            cin >> a[i];
        }

        int j = 0;
        vector<int> lastInd(n, -1);
        ll sum = 0;

        for (int i = 0; i<n; ++i) {
            while (j<n && sum <= x) {
                sum += a[j];
                ++j;
            }

            lastInd[i] = j-1;

            if (sum <= x) {
                lastInd[i] = -1;
                break;
            }

            sum -= a[i];
        }

        vector<int> vals(n);

        for (int i = 0; i<n; ++i) {
            vals[i] = (lastInd[i] != -1);
        }

        for (int i = n-1; i>=0; --i) {
            if (lastInd[i] == -1 || lastInd[i] == n-1) {
                continue;
            }

            vals[i]+=vals[lastInd[i] + 1];
        }

        ll res = 0;

        for (int i = 0; i<n; ++i) {
            res += n-i-vals[i];
        }

       cout << res << '\n';

    }


    return 0;
}
