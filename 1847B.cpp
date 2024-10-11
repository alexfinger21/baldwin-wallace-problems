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

        vector<ll> a(n);

        ll aRes = -1;

        for (int i = 0; i<n; ++i) {
            cin >> a[i];
            if (aRes == -1) {
                aRes = a[i];
            } else {
                aRes &= a[i];
            }
        }

        ll res = 0;
        ll andRes = -1;
        for (int i = 0; i<n; ++i) {
            if (andRes == -1) {
                andRes = a[i];
            } else {
                andRes &= a[i];
            }

            if (andRes == aRes && res*aRes < aRes || (andRes == 0)) {
                ++res;
                andRes = -1;
            }
        }

        
        cout << res << '\n';

    }

    return 0;
}
