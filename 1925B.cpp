#include <bits/stdc++.h>

using ll=long long;
using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;

    while (t--) {
        ll x, n;
        cin >> x >> n;
        priority_queue<ll> pq;
       
        ll ans = 1;
        for (ll i = 1; i*i<=x; ++i) {
            if (!(x%i)) {
                if (x/i >= n) {
                    ans = max(ans, i);
                }
                if (i >= n) {
                    ans = max(ans, x/i);
                }
            }
        }

        cout << ans << '\n';
    }

    return 0;
}
