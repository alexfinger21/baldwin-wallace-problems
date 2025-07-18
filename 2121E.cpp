#include <bits/stdc++.h>

using ll=long long;
using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;

    while (t--) {
        string l, r;
        cin >> l;
        cin >> r;

        if (r[0] - l[0] > 1) {
            cout << "0\n";
            continue;
        }

        vector<vector<int>> dp(l.size(), vector<int>(10));
        int res = r[0] == l[0] ? 2 : 1;
        int prev_diff = r[0] - l[0];

        for (int i = 1; i<l.size(); ++i) {
            if ((prev_diff == 1 && r[i] - l[i] != -9) || (prev_diff != 1 && abs(r[i] - l[i]) > 1)) {
                break;
            } else {
                prev_diff = max(prev_diff, r[i] - l[i]);
                if (r[i] == l[i]) {
                    res += 2;
                } else {
                    ++res;
                }
            }
        }

        cout << res << '\n';
    }

    return 0;
}
