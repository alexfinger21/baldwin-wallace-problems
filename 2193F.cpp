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
        ll ax, ay, bx, by;

        cin >> n >> ax >> ay >> bx >> by;

        map<ll, set<ll>> paths;
        vector<ll> x_arr(n);

        map<ll, ll> gaps_min;
        map<ll, ll> gaps_max;

        for (int i = 0; i<n; ++i) {
            ll x;
            cin >> x;

            x_arr[i] = x;
        }

        for (int i = 0; i<n; ++i) {
            ll y;
            cin >> y;

            if (!gaps_min.count(x_arr[i])) {
                gaps_min[x_arr[i]] = 1e9 + 1;
            }

            gaps_min[x_arr[i]] = min(gaps_min[x_arr[i]], y);
            gaps_max[x_arr[i]] = max(gaps_max[x_arr[i]], y);
        }

        gaps_min[bx] = by;
        gaps_max[bx] = by;

        gaps_min[ax] = ay;
        gaps_max[ax] = ay;

        const int s = gaps_max.size();
        vector<vector<ll>> dp(s, vector<ll>(2));

        int i = 0;
        ll prev_x = 0;
        for (auto x : gaps_max) {
            if (i == 0) {
                dp[i][0] = 0;
                dp[i][1] = 0;
            } else {
                ll low = gaps_min[x.first];
                ll gap_y = x.second - low;
                //cout << "GAP: " << gap_y << endl;
                dp[i][0] = min(dp[i-1][0] + abs(x.second - gaps_min[prev_x]), dp[i-1][1] + abs(x.second - gaps_max[prev_x])) + gap_y + x.first - prev_x; 
                dp[i][1] = min(dp[i-1][0] + abs(low - gaps_min[prev_x]), dp[i-1][1] + abs(low - gaps_max[prev_x])) + gap_y + x.first - prev_x; 
                //cout << min(dp[i][0], dp[i][1]) << endl;
            }

            prev_x = x.first;
            ++i;
        }

        cout << min(dp[s-1][0], dp[s-1][1]) << endl;

    }

    return 0;
}
