#include <bits/stdc++.h>

using ll=long long;
using namespace std;

int lim = 2e5+2;

vector<int> col(lim);
vector<vector<pair<int, ll>>> neighbors(lim);
vector<bool> was(lim);
vector<ll> last_cost(lim);
vector<map<int, ll>> cnt(lim);
vector<int> parent(lim);
ll costt = 0;

void dfs(int v) {
    was[v] = true;
    for (auto x: neighbors[v]) {
        if (was[x.first]) {
            parent[v] = x.first;
            continue;
        } 
        if (col[v] != col[x.first]) {
            costt += x.second; 
        }
        dfs(x.first);

        last_cost[x.first] = x.second;
        cnt[v][col[x.first]] += last_cost[x.first];
    }
}

void update(int v, int x) {
    if (v != 1) {
        cnt[parent[v]][col[v]] -= last_cost[v];
        cnt[parent[v]][x] += last_cost[v];
        if (col[parent[v]] == col[v]) {
            costt += last_cost[v];
        }
        if (col[parent[v]] == x) {
            costt -= last_cost[v];
        }
    }
    
    // chilldren

    costt -= cnt[v][x]; 
    costt += cnt[v][col[v]]; 
    col[v] = x;
}

void erase(int n) {
    for (int i = 1; i<=n; ++i) {
        neighbors[i].clear(); 
        cnt[i].clear();
        col[i] = 0;
        was[i] = 0;
        last_cost[i] = 0;
        parent[i] = 0;
    }
    costt = 0;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;

    while (t--) {
        int n, q;
        cin >> n >> q;

        for (int i = 0; i<n; ++i) {
            cin >> col[i+1];    
        }

        for (int i = 0; i<n-1; ++i) {
            int u, v;
            ll c;
            cin >> u >> v >> c;

            neighbors[u].push_back({v, c});
            neighbors[v].push_back({u, c});
        }

        dfs(1);

        for (int i = 0; i<q; ++i) {
            int v, x;
            cin >> v >> x;
            update(v, x);
            cout << costt << '\n';
        }

        erase(n); 
    }

    return 0;
}
