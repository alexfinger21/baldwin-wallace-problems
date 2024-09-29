#include <bits/stdc++.h>

using ll=long long;
using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;

    while (t--) {
        ll b, c, d;
        cin >> b >> c >> d;

        if ((b^c)&c&d) {
            cout << "-1\n";
        } else if (((b ^ c) & b) && (((b^c)&b|d)^d)) { 
            cout << "-1\n";
        } else {
            ll res = (((b | c) & d) ^ d) + (((b & c) ^ d) & (b&c));
            cout << res << '\n';
        }
    }

    return 0;
}
