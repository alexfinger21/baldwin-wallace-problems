#include <bits/stdc++.h>

using ll=long long;
using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;

    while (t--) {
        ll n, x, y;
        cin >> n >> x >> y;

        cout << (n%(min(x, y)) == 0 ?n/(min(x, y)) : n/(min(x, y)) + 1) << '\n'; 
    }

    return 0;
}
