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

        int res = 0;

        for (int i = 0; i<n; ++i) {
            int num;
            cin >> num;
            if (i%2) {
                res -= num;
            } else {
                res += num;
            }
        }

        cout << res << '\n';
    }

    return 0;
}
