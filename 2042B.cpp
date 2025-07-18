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

        map<int, int> colors;

        for (int i = 0; i<n; ++i) {
            int m;
            cin >> m;

            if (!colors.count(m)) {
                colors[m] = 1;
            } else {
                ++colors[m];
            }
        }

        int res = 0;
        int turn = 1;
        for (auto x : colors) {
            if (x.second) {
                if (x.second == 1) {
                    if (turn) {
                        res += 2;
                    }
                    turn = !turn;
                } else {
                    ++res;
                }
            }
        }
        cout << res << '\n';
    }

    return 0;
}
