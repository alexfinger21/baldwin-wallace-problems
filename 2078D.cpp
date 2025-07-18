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

        vector<vector<pair<ll, ll>>> dp(n+1, vector<pair<ll, ll>>(2));

        dp[0][0] = {1, 1};
        dp[0][1] = {1, 1};

        for (int i = 1; i<=n; ++i) {
            char op0;
            ll a0;
            char op1;
            ll a1;
            cin >> op0 >> a0 >> op1 >> a1;
            
            ll l_sum = dp[i-1][0].first + dp[i-1][0].second;
            ll r_sum = dp[i-1][1].first + dp[i-1][1].second;


            if (op0 == '+') {
                l_sum += a0;
                r_sum += a0;
            } else {
                l_sum += dp[i-1][0].first * (a0-1);
                r_sum += dp[i-1][1].first * (a0-1);
            }

            if (op1 == '+') {
                l_sum += a1;
                r_sum += a1;
            } else {
                l_sum += dp[i-1][0].second * (a1-1);
                r_sum += dp[i-1][1].second * (a1-1);
            }

            if (l_sum > r_sum) {
                dp[i][0].first = l_sum - dp[i-1][0].second;
                dp[i][0].second = dp[i-1][0].second;

                dp[i][1].first = dp[i-1][0].first;
                dp[i][1].second = l_sum - dp[i-1][0].first;
            } else if (l_sum < r_sum) {
                dp[i][0].first = r_sum - dp[i-1][1].second;
                dp[i][0].second = dp[i-1][1].second;

                dp[i][1].first = dp[i-1][1].first;
                dp[i][1].second = r_sum - dp[i-1][1].first;
            } else {
                //cout << "aragfg" << endl;
                dp[i][0].first = l_sum - dp[i-1][0].second;
                dp[i][0].second = dp[i-1][0].second;

                dp[i][1].first = dp[i-1][1].first;
                dp[i][1].second = r_sum - dp[i-1][1].first;
            }
            //cout << dp[i][0].first << ' ' << dp[i][0].second << endl;
            //cout << dp[i][1].first << ' ' << dp[i][1].second << endl;
        }

        ll s1 = dp[n][0].first + dp[n][0].second;

        cout << s1 << '\n';
    }

    return 0;
}
