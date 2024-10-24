#include <bits/stdc++.h>

using ll=long long;
using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;

    while (t--) {
        int n, r;
        cin >> n >> r;

        int left = 0;

        vector<int> fams(n);
        
        for (int i = 0; i<n; ++i) {
            cin >> fams[i];

            left += fams[i] % 2;
            fams[i] -= fams[i]%2;
        }

        int st = 0;
        int res = 0;
        for (auto x : fams) {
            st += x;
            res += x;
        }

        res += r*2 - res - left;
        res = min(res, st+left);
        cout << res << '\n';
    }

    return 0;
}
