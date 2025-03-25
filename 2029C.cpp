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

        for (int i = 0; i<n; ++i) {
            cin >> a[i];
        }

        vector<vector<int>> dp(n, vector<int>(3));

        dp[0][0] = 0; //skipped
        dp[0][1] = 1; //not skipped
        dp[0][2] = 0; //skipping

        for (int i = 1; i<n; ++i) {
            dp[i][0] = max(dp[i-1][0], dp[i-1][2]);
            if (dp[i][0] < a[i]) {
                dp[i][0] = dp[i][0] + 1;
            } else if (dp[i][0] > a[i]) {
                dp[i][0] = dp[i][0] - 1;
            } else {
                dp[i][0] = dp[i][0];
            }

            if (dp[i-1][1] < a[i]) {
                dp[i][1] = dp[i-1][1] + 1;
            } else if (dp[i-1][1] > a[i]) {
                dp[i][1] = dp[i-1][1] - 1;
            } else {
                dp[i][1] = dp[i-1][1];
            }
            
            dp[i][2] = max(dp[i-1][2], dp[i-1][1]);
            dp[i][0] = max(dp[i-1][2], dp[i][0]);

            //cout << dp[i][0] << ' ' << dp[i][1] << ' ' << dp[i][2] << endl;
        }

        cout << max(dp[n-1][0], dp[n-1][2]) << '\n';
    }

    return 0;
}
