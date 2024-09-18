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
        for (int i = 0; i<n; ++i) {
            cin >> a[i];
        }


        ll s = 0;
        ll m = 0;
        for (auto x : a) {
            m = max(x, m);
        }

        s += m;

        if (m == a[n-1]) {
            m = 0;
            for (int i = 0; i<n-1; ++i) {
                m = max(m, a[i]);                    
            }
            s += m;
        } else {
            s += a[n-1];
        }




        cout << s << '\n';
    }

    return 0;
}
