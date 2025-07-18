#include <bits/stdc++.h>

using ll=long long;
using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;

    while (t--) {
        string a, b, c;
        cin >> a >> b >> c;
        vector<vector<int>> dp(c.size(), vector<int>(a.size()+1, 1e9));

        for (int i = 0; i<c.size(); ++i) {
            for (int j = 0; j<=i+1, j<=a.size(); ++j) {

                if (i > 0 && j > 0) {
                    int nc = a[j-1] == c[i] ? 0 : 1;
                    dp[i][j] = min(dp[i-1][j-1]+nc, dp[i][j]); 
                } else if (j > 0) {
                    int nc = a[j-1] == c[i] ? 0 : 1;
                    dp[i][j] = nc;
                }
                if (j <= i && i - j < b.size()) {
                    int nc2 = b[i-j] == c[i] ? 0 : 1;
                    dp[i][j] = min((i > 0 ? dp[i-1][j] : 0) + nc2, dp[i][j]);
                }
            } 
        }

        int res = c.size();

        for (auto x : dp[c.size()-1]) {
            res = min(res, x);
        }

        cout << res << '\n';        
    }

    return 0;
}

