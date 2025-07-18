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

        map<int, int> a;

        for (int i = 0; i<n; ++i) {
            int num;
            cin >> num;

            if (a.count(num)) {
                ++a[num];
            } else {
                a[num] = 1;
            }
        }

        int mx = 0;

        for (auto x : a) {
            mx = max(x.second, mx);
        }

        cout << n-mx << '\n';
    }

    return 0;
}
