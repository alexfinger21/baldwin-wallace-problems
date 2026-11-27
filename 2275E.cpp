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

        vector<int> a(n), b(n);

        for (int i = 0; i<n; ++i) {
            cin >> a[i];
        }

        for (int i = 0; i<n; ++i) {
            cin >> b[i];
        }

        vector<int> z1(n);
        vector<int> z2(n);
        vector<int> td(n);

        td[0] = (a[0] == b[0]) ? 2 : 1;

        for (int i = 1; i<n; ++i) {
            td[i] = td[i-1] + ((a[i] == b[i]) ? 2 : 1);
            td[i] += (a[i] == b[i-1]) ? 2 : 1;

            if (i % 2) {
                z1[i] = z1[i-1] + ((a[i-1] == b[i]) ? 2 : 1);
                z2[i] = z2[i-1] + ((a[i] == b[i-1]) ? 2 : 1);
            } else {
                z1[i] = z1[i-1] + ((a[i] == b[i-1]) ? 2 : 1);
                z2[i] = z2[i-1] + ((a[i-1] == b[i]) ? 2 : 1);
            }
        }

        if (n == 1) {
            cout << td[0] << '\n';
            continue;
        }

        int res = td[n-1];
        int last = (a[n-1] == b[n-1]) ? 2 : 1;

        // cout << res << endl;

        for (int i = n-2; i>=0; --i) {
            res = max(res, z1[n-1] - z1[i] + z2[n-1] - z2[i] + (i > 0 ? (td[i-1] + (a[i] == b[i-1] ? 2 : 1)) : 0) + last);
            /*
            cout << z1[n-1] - z1[i] << endl;
            cout << z2[n-1] - z2[i] << endl;
            cout << last << endl;
            cout << (i > 0 ? td[i-1] : 0) << endl;
            cout << endl;
            */
        }

        cout << res << '\n';

    }

    return 0;
}
