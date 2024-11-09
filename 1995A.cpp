#include <bits/stdc++.h>

using ll=long long;
using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        ll res = 0;

        if (k > 0) {
            ++res;
            k = max(0, k-n);
        }

        for (int i = n-1; i>0; --i) {
            if (k > 0) {
                ++res;
                k = max(0, k-i);
            }
            if (k > 0) {
                ++res;
                k = max(0, k-i);
            } else {
                break;
            }
        }

        cout << res << '\n';
    }

    return 0;
}
