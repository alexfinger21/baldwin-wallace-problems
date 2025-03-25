#include <bits/stdc++.h>

using ll=long long;
using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;

    while (t--) {
        ll n, x;
        cin >> n >> x;
        
        vector<ll> a(n);

        ll res = 0;

        for (int i = 0; i<n; ++i) {
            cin >> a[i];
        }

        sort(a.begin(), a.end());

        ll mn = 0;
        ll cnt = 0;
        for (int i = n-1; i>=0; --i) {
            if (mn == 0) {
                mn = a[i];
                cnt = 1;
            }
            mn = min(mn, a[i]);
            if (mn*cnt >= x) {
                mn = 0;
                cnt = 0;
                ++res;
            } else {
                ++cnt;
            }
        }


        cout << res << '\n';
    }

    return 0;
}
