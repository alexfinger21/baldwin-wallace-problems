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

        int max1 = 0;
        for (int i = 0; i<n; i+=2) {
            max1 = max(max1, a[i]);
        }

        int max2 = 0;
        for (int i = 1; i<n; i+=2) {
            max2 = max(max2, a[i]);
        }

        cout << max(max1 + (n+1)/2, max2 + n/2) << '\n';
        



    }

    return 0;
}
