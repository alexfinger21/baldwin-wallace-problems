#include <bits/stdc++.h>

using ll=long long;
using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;

    while (t--) {
        int n, s;
        cin >> n >> s;

        int minx = 101, maxx = 0;

        for (int i = 0; i<n; ++i) {
            int b;
            cin >> b;

            minx = min(minx, b);
            maxx = max(maxx, b);
        }

        int res = 0;

        if (maxx == minx) {
            res += abs(s - maxx);
        } else {
            res += min(abs(s-maxx),abs(s-minx));
            res += maxx-minx;
        }

        cout << res << '\n';
    }

    return 0;
}
