#include <bits/stdc++.h>

using ll=long long;
using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;

    while (t--) {
        int n, q;
        cin >> n >> q;

        vector<int> a(n);

        for (int i = 0; i<n; ++i) {
            cin >> a[i];
        }

        vector<unordered_map<ll, ll>> verts(n);
        vector<ll> sums(n);
        vector<vector<pair<ll, ll>>> adj(n);

        ll res = 0;
        for (int i = 0; i<n-1; ++i) {
            int u, v, c;

            cin >> u >> v >> c;
            --u; --v;

            verts[u][a[v]] += c;
            verts[v][a[u]] += c;
            adj[v].emplace_back(u, c);
            adj[u].emplace_back(v, c);

            if (a[u] != a[v]) {
                sums[a[v]] = c;
                sums[a[u]] = c;
                res += c;
            }
        }


        for (int i = 0; i<q; ++i) {
            int v, x;
            cin >> v >> x;
            --v;

            if (a[v] == x) {
                cout << res << '\n';
                continue;
            }

            ll old_s = sums[v];
            sums[v] -= verts[v][x];
            sums[v] += verts[v][a[v]];
            res += sums[v] - old_s;

            for (auto z : adj[v]) {
                verts[z.first][a[v]] -= z.second;
                verts[z.first][x] += z.second;

                if (x != a[z.first]) {
                    sums[z.first] += z.second;
                }
            }

            a[v] = x;

            cout << res << '\n';
        }
    }

    return 0;
}
