#include <bits/stdc++.h>

using ll=long long;
using namespace std;

const ll MOD = 998244353;


int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;

    while (t--) {
        int n, m;

        cin >> n >> m;

        vector<ll> a(n);
        
        for (int i = 0; i<n; ++i) {
            cin >> a[i];
        }

        vector<vector<int>> g(n);
        vector<pair<int, int>> edges(m);

        for (int i = 0; i<m; ++i) {
            int u, v;

            cin >> u >> v;
            --u;
            --v;

            g[u].push_back(v);

            edges[i].first = u;
            edges[i].second = v;
        }

        sort(edges.begin(), edges.end(), [&a](pair<int, int> p1, pair<int, int> p2) {
            return (a[p1.first] + a[p1.second]) > (a[p2.first] + a[p2.second]);
        });

        vector<map<ll, int>> dp(n);

        ll res = 0;

        for (auto e : edges) {
            ll s = a[e.first] + a[e.second];
            ll cdp = dp[e.second][s];

            cdp = (cdp + 1) % MOD;
            dp[e.first][a[e.second]] = (cdp + dp[e.first][a[e.second]]) % MOD;

            res = (res + cdp) % MOD;
        }

        cout << res << '\n';
    }

    return 0;
}
