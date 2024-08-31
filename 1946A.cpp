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

        sort(a.begin(), a.end());
        
        int res = 0;

        for (int i = (n-1)/2; i<n; ++i) {
            if (a[i] == a[(n-1)/2]) {
                ++res;
            } else {
                break;
            }
        }

        cout << res << '\n';
    }

    return 0;
}
