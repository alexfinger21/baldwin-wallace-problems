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

        int c0 = 0;
        int c1 = 0;
        int c2 = 0;
        int c3 = 0;
        int c5 = 0;

        int rs = 0;
        for (int i = 0; i<n; ++i) {
            cin >> a[i];
            if (a[i] == 0) {
                ++c0;
            } else if (a[i] == 1) {
                ++c1;
            } else if (a[i] == 2) {
                ++c2;
            } else if (a[i] == 3) {
                ++c3;
            } else if (a[i] == 5) {
                ++c5;
            }

            if (!rs && c0 >= 3 && c1 >= 1 && c2 >= 2 && c3 >= 1 && c5 >= 1) {
                rs = i+1;
            }
        }

        cout << rs << '\n';

    }

    return 0;
}
