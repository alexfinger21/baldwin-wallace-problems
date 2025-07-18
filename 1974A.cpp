#include <bits/stdc++.h>

using ll=long long;
using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;

    while (t--) {
        int x, y;
        cin >> x >> y;

        int res = 0;

        while (x > 0 ||  y > 0) {
            x -= 15 - min(max(0, y), 2) * 4;
            y -= 2;
            ++res;
        }

        cout << res << '\n';
    }

    return 0;
}
