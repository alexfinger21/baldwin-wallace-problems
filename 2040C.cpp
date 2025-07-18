#include <bits/stdc++.h>

using ll=long long;
using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;

    while (t--) {
        ll n, k;
        cin >> n >> k;
        
        if (n <= 61 && 1LL << (n-1) < k) {
            cout << "-1\n";
            continue;
        }

        vector<int> res(n);

        int f = 0, b = n-1;

        --k;

        vector<short> d(n);
        for (int i = 1; i<n; ++i) {
            d[i] = k%2;
            k /= 2;
        }

        for (int i = n-1; i>=0; --i) {
            if (d[i]) {
                res[b] = n-i;
                --b;
            } else {
                res[f] = n-i;
                ++f;
            }
        }

        for (auto x : res) {
            cout << x << ' ';
        }

        cout << '\n';
    }

    return 0;
}
