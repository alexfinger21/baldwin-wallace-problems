#include <bits/stdc++.h>

using ll=long long;
using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);

    int n, x;
    cin >> n >> x;

    vector<int> c(n);

    for (int i = 0; i<n; ++i) {
        cin >> c[i];
    }

    vector<vector<int>> dp(x+1, vector<int>(n));

    for (int i = 1; i<=x; ++i) {
        for (int j = 0; j<n; ++j) {
            if (!j) {
                dp[i][j] = max(dp[i-1][j], (c[j] * (n-j)) <= i ? 1 : 0);
            } else {
                dp[i][j] = max(dp[i][j-1], (c[j] * (n-j)) <= i ? dp[i-c[j]*(n-j)][j-1]+1 : dp[i-1][j]);
            }
        }
    }

    cout << dp[x][n-1] << '\n';

    return 0;
}
