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
        cin 
            >> n;

        vector<ll> a(n);

        for (int i = 0; i<n; ++i) {
            cin >> a[i];
        }

        for (int i = 0; i<n-2; ++i) {
            a[n-2] -= a[i];
        }

        cout << a[n-1] - a[n-2] << '\n';
    }

    return 0;
}
