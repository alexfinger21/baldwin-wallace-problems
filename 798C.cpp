#include <bits/stdc++.h>

using ll=long long;
using namespace std;

ll gcd(ll n1, ll n2) {
    while (n1 % n2) {
        ll rem = n1 % n2;
        n1 = n2;
        n2 = rem;
    }

    return n2;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;

    vector<ll> a(n);

    for (int i = 0; i<n; ++i) {
        cin >> a[i];
    }

    ll res = 0;
    ll prev_gcd = a[0];
    int pc = 0;
    bool found = false;

    if (a[0] % 2) {
        ++pc;
    }

    for (int i = 1; i<n; ++i) {
        if (!found) {
            ll gcd_res = gcd(prev_gcd, a[i]);

            if (gcd_res > 1) {
                prev_gcd = gcd_res;
            } else {
                found = true;
            }
        }
        a[i] %= 2;

        if (a[i]) {
            ++pc;
        } else {
            if (pc % 2) {
                res += pc/2 + 2;
            } else {
                res += pc/2;
            }

            pc = 0;
        }
    }

    if (pc % 2) {
        res += pc/2 + 2;
    } else {
        res += pc/2;
    }

    if (found) {
        cout << "YES\n" << res << '\n';
    } else {
        cout << "YES\n0\n";
    }

    return 0;
}
