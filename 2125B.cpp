#include <bits/stdc++.h>

using ll=long long;
using namespace std;

ll gcd(ll a, ll b) {
    while (a % b) {
        ll temp = b;
        b = a % b;
        a = temp;
    }

    return b;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;

    while (t--) {
        ll a, b, k;
        cin >> a >> b >> k;

        ll res = 0;

        ll div = gcd(a, b);
        
        if (a/div <= k && b/div <= k) {
            cout << "1\n";
        } else {
            cout << "2\n";
        }
    }

    return 0;
}
