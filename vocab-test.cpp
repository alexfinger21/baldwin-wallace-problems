#include <bits/stdc++.h>

using ll=long long;
using namespace std;

int32_t main() {

    string a;
    string b;
    cin >> a;
    cin >> b;

    vector<vector<int>> dp(a.size() + 1, vector<int>(b.size() + 1));

    for (int i = 1; i<=a.size(); ++i) {
        for (int j = 1; j<=b.size(); ++j) {
            dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            dp[i][j] = max(dp[i][j], dp[i-1][j-1] + ((a[i-1] == b[j-1]) ? 1 : 0));
        }
    }

    for (auto x : dp) {
        for (auto g : x) {
            cout << g << ' ';
        }
        cout << endl;
    }

    cout << dp[a.size()][b.size()] << endl;

    return 0;
}
