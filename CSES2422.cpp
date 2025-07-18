#include <bits/stdc++.h>

using ll=long long;
using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin >> n;

    ll l = 1, h=n*n;
    ll mid = (n*n+1)/2;

    while (l < h) {
        ll m = (l+h) >> 1;

        ll cnt = 0;


        for (int i = 1; i<=n; ++i) {
            cnt += min(n, m/i);            
        }

        if (cnt >= mid) {
            h = m;
        } else {
            l = m+1;
        }
    }

    cout << h << '\n';

    return 0;
}
