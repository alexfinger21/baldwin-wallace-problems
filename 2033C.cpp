#include <bits/stdc++.h>

using ll=long long;
using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n);

        for (int i = 0; i<n; ++i) {
            cin >> a[i];
        }

        int lastSwap = -2;

        for (int i = n/2-1; i>=1; --i) {
            if (a[i] == a[i-1] || a[n-i-1] == a[n-i]) {
                a[i-1] ^= a[n-i];
                a[n-i] ^= a[i-1];
                a[i-1] ^= a[n-i];
            }
        }
    
        int res = 0;
        /* 
        for (auto x : a) {
            cout << x << ' ';
        }
        cout << endl;
        */
        

        for (int i = 0; i<n; ++i) {
            if (i > 0 && a[i] == a[i-1]) {
                ++res;
            }
        }
        cout << res << '\n';
    }

    return 0;
}
