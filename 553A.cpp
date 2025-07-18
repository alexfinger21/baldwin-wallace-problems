#include <bits/stdc++.h>

using ll=long long;
using namespace std;

ll mod = 1000000007;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<vector<ll>> dp(1010, vector<ll>(1010));

    dp[0][0] = 1;

    for (int i = 1; i<1010; ++i) {
        dp[i][0] = 1;
        dp[i][i] = 1;
        for (int j = 1; j<i; ++j) {
            dp[i][j] = (dp[i-1][j-1] + dp[i-1][j]) % mod; 
        }
    }

    int k;
    cin >> k;

    vector<int> clrs(k);

    ll res = 1;
    int accum = 0;

    for (int i = 0; i<k; ++i) {
        cin >> clrs[i];
        accum += clrs[i];
        //cout << "DP: " << ' ' << dp[accum-1][clrs[i] - 1] << " res: " << res << endl;
        
        res = (res * dp[accum-1][clrs[i] - 1]) % mod;
    }
    
    cout << res << '\n';

    return 0;
}
