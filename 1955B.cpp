#include <bits/stdc++.h>

using ll=long long;
using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;

    while (t--) {
        ll n, c, d;
        cin >> n >> c >> d;

        vector<ll> arr(n*n);

        priority_queue<ll> a;
        ll mn = 1e9+1;

        for (int i = 0; i<n*n; ++i) {
            ll g;
            cin >> g;
            a.push(g);
            mn = min(mn, g);
        }

        priority_queue<ll> b;

        for (ll i = 0; i<n; ++i) {
            for (ll j = 0; j<n; ++j) {
                b.push(mn + i*c + d*j);
            } 
        }

        bool found = false;
        while (!b.empty()) {
            if (a.top() != b.top()) {
                found = true;
                break;
            } else {
                a.pop();
                b.pop();
            }
        }

        if (!found) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}
