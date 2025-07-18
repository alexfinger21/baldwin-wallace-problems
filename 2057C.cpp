#include <bits/stdc++.h>

using ll=long long;
using namespace std;
 
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;

    while (t--) {
        
        ll l, r;
        cin >> l >> r;

        int powe = 31 - __builtin_clz(r ^ l);
        int a = (((1 << powe) - 1) | l) + 1, b = a - 1, c = (a == r ? l : r);
        cout << a << ' ' << b << ' '<< c << '\n';
    }

    return 0;
}
