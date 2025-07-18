#include <bits/stdc++.h>

using ll=long long;
using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<string> a(n);

    for (int i = 0; i<n; ++i) {
        cin >> a[i];
    }

    int l = a[0].size();

    vector<vector<int>> dp(n, vector<int>(l, 1e9));

    for (int i = 0; i<l; ++i) {
        dp[0][i] = i;
    }

    for (int i = 1; i<n; ++i) {
        for (int k = 0; k<l; ++k) {
            string s1 = a[0].substr(k, l-k) + a[0].substr(0, k);
            for (int j = 0; j<l; ++j) {
                string s = a[i].substr(j, l-j) + a[i].substr(0, j);

                if (s1 == s) {
                    //cout << s1 << ' ' << s << endl;
                    //cout << i << ' ' << k << ' ' << dp[i-1][k] << ' ' << j << '\n';
                    dp[i][k] = min(dp[i-1][k] + j, dp[i][k]);
                    break;
                }
            }
        }
    }

    int res = 1e9;

    for (int i = 0; i<l; ++i) {
        res = min(res, dp[n-1][i]);
    }

    if (res == 1e9) {
        cout << "-1\n";
    } else {
        cout << res << '\n';
    }

    return 0;
}
