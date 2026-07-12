#include <bits/stdc++.h>

using ll=long long;
using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;

    while (t--) {
        string a, b;
        cin >> a >> b;


        int aidx = 0, bidx = 0;

        vector<int>amod(a.size());
        vector<int>bmod(b.size());

        int prev = 0;
        for (int i = 0; i<a.size(); ++i) {
            amod[i] = ((a[i] - '0') + prev) % 10;
            prev = amod[i];
        }

        prev = 0;
        for (int i = 0; i<b.size(); ++i) {
            bmod[i] = ((b[i] - '0') + prev) % 10;
            prev = bmod[i];
        }

        if (amod[a.size() - 1] != bmod[b.size() - 1]) {
            cout << "-1\n";
            continue;
        }

        vector<vector<int>> dp(a.size() + 1, vector<int>(b.size() + 1));

        for (int i = 1; i<=a.size(); ++i) {
            for (int j = 1; j<=b.size(); ++j) {
                dp[i][j] = max(dp[i][j-1], max(dp[i-1][j], dp[i-1][j-1] + (amod[i-1] == bmod[j-1] ? 1 : 0)));
                // cout << dp[i][j] << ' ';
            }
            // cout << endl;
        }

        cout << dp[a.size()][b.size()] << '\n';

    }

    return 0;
}
