#include <bits/stdc++.h>

using ll=long long;
using namespace std;

ll MOD = 998244353;
ll res = 0;

ll solve(int idx, vector<ll>& dp, vector<bool>& vis, vector<pair<int, int>>& edges, vector<ll>& vals, vector<vector<int>>& vert) {
    if (!vis[idx]) {
        dp[idx] += 1;
        vis[idx] = true;
    } else {
        return dp[idx];
    }

    for (int e : vert[edges[idx].second]) {
        if (vals[edges[e].second] == (vals[edges[idx].first] + vals[edges[idx].second])) {
            dp[idx] = (dp[idx] + solve(e, dp, vis, edges, vals, vert)) % MOD;
        }

    }

    res = (res + dp[idx]) % MOD;
    return dp[idx];
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;

    while (t--) {
        res = 0;

        int n, m;
        cin >> n >> m;

        vector<vector<int>> vert(n);
        vector<pair<int, int>> edges(m);
        vector<ll> vals(n);
        vector<bool> visited(m);
        vector<ll> dp(m);

        for (int i = 0; i<n; ++i) {
            cin >> vals[i];
        }

        for (int i = 0; i<m; ++i) {
            int s, e;
            cin >> s >> e;

            --s;
            --e;

            edges[i].first = s;
            edges[i].second = e;

            vert[s].push_back(i);
        }        


        for (int i = 0; i<m; ++i) {
            if (!visited[i]) {
                solve(i, dp, visited, edges, vals, vert);
            }
        }

        /*
        for (int i = 0; i<m; ++i) {
            // res += dp[i];
            cout << dp[i] << endl;
        }
        */

        cout << (res % MOD) << '\n';
    }

    return 0;
}
