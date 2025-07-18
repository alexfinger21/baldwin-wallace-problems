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

        vector<ll> a(n);

        for (int i = 0; i<n; ++i) {
            cin >> a[i];
        }

        bool found = false;
        for (int i = 1; i<n-1; ++i) {
            a[i] -= a[i-1]*2; 
            a[i+1] -= a[i-1];
            a[i-1] = 0;

            if (a[i] < 0) {
                found = true;
                break;
            }
        }

        for (auto x : a) {
            if (x != 0) {
                found = true;
            }
        }

        if (found) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
        }
    }

    return 0;
}
