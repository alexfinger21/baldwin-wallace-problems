#include <bits/stdc++.h>

using ll=long long;
using namespace std;
ll count_div(ll a, ll b, ll c) {
    ll res = 0;

    if (!(a % c)) {
        ++res;
    }

    return (res + b / c - a / c);
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;

    while (t--) {
        ll l, r;
        cin >> l >> r;

        ll c3 = count_div(l, r, 3), c5 = count_div(l, r, 5), c7 = count_div(l, r, 7), c2 = count_div(l, r, 2);

        ll res = (r - l + 1) - (c2 + c3 + c5 + c7);

        res += count_div(l, r, 6);
        res += count_div(l, r, 10);
        res += count_div(l, r, 14);
        res += count_div(l, r, 15);
        res += count_div(l, r, 21);
        res += count_div(l, r, 35);
        res -= count_div(l, r, 2 * 3 * 5);
        res -= count_div(l, r, 2 * 3 * 7);
        res -= count_div(l, r, 2 * 7 * 5);
        res -= count_div(l, r, 3 * 7 * 5);
        res += count_div(l, r, 2 * 3 * 7 * 5);
        
        cout << res << '\n';
    }

    return 0;
}
