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

        int res = 1;
        int l = a[0];

        for (int i = 1; i<n; ++i) {
            if (a[i] - 1 > l) {
                ++res;
                l = a[i];
            }
        }
        cout << res << '\n';
    }

    return 0;
}
