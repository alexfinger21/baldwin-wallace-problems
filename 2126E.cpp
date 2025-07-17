#include <bits/stdc++.h>

using ll=long long;
using namespace std;

ll calc_gcd(ll n1, ll n2) {
    while (n1 % n2) {
        ll temp = n2;
        n2 = n1 % n2;
        n1 = temp;
    }

    return n2;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;


    while (t--) {
        int n;
        cin >> n;
        vector<ll> p(n);
        vector<ll> s(n);
        for (int i = 0; i < n; i++) {
            cin >> p[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> s[i];
        }

        bool valid = true;
        for (int i = 1; i < n; i++) {
            if (p[i-1] % p[i] != 0) {
                valid = false;
                break;
            }
        }
        if (!valid) {
            cout << "NO\n";
            continue;
        }

        for (int i = 0; i < n-1; i++) {
            if (s[i+1] % s[i] != 0) {
                valid = false;
                break;
            }
        }
        if (!valid) {
            cout << "NO\n";
            continue;
        }

        if (p[n-1] != s[0]) {
            cout << "NO\n";
            continue;
        }

        vector<ll> a(n);
        for (int i = 0; i < n; i++) {
            ll g = calc_gcd(p[i], s[i]);
            a[i] = (p[i] * s[i]) / g;
        }

        ll current = 0;
        bool prefix_ok = true;
        for (int i = 0; i < n; i++) {
            if (i == 0) {
                current = a[i];
            } else {
                current = calc_gcd(current, a[i]);
            }
            if (current != p[i]) {
                prefix_ok = false;
                break;
            }
        }
        if (!prefix_ok) {
            cout << "NO\n";
            continue;
        }

        ll suf = 0;
        bool suffix_ok = true;
        for (int i = n-1; i >= 0; i--) {
            if (i == n-1) {
                suf = a[i];
            } else {
                suf = calc_gcd(a[i], suf);
            }
            if (suf != s[i]) {
                suffix_ok = false;
                break;
            }
        }
        if (!suffix_ok) {
            cout << "NO\n";
            continue;
        }

        cout << "YES\n";
    }

    return 0;
}
