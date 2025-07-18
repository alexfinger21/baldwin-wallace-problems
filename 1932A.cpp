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
        vector<int> dp(n);

        int res = 0;

        for (int i = 0; i<n; ++i) {
            char c;
            cin >> c;

            if (c != '*') {
                if (c == '@') {
                    dp[i] = 1;
                }

                if (i > 1 && dp[i-1] == -1 && dp[i-2] == -1) {
                    dp[i] = -1;
                } else if (i != 0) {
                    dp[i] = max(dp[max(0, i-1)], dp[max(0, i-2)]) + dp[i];
                }

            } else {
                dp[i] = -1;
            }

            res = max(res, dp[i]);
        }

        cout << res << '\n';
    }

    return 0;
}
