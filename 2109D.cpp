#include <bits/stdc++.h>

using ll=long long;
using namespace std;

ll max_n = LLONG_MAX;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;

    while (t--) {
        ll n, m, l;
        cin >> n >> m >> l;

        vector<ll> a(l);

        ll s = 0;
        ll s_o = max_n;

        for (int i = 0; i<l; ++i) {
            cin >> a[i];
            s += a[i];
            if (a[i] % 2) {
                s_o = min(s_o, a[i]);
            }
        }

        vector<array<ll, 2>> paths(n, {max_n, max_n});
        map<ll, set<ll>> mapa;

        paths[0][0] = 0;

        for (int i = 0; i<m; ++i) {
            ll e1, e2;
            cin >> e1 >> e2;

            if (!mapa.count(e1)) {
                mapa[e1] = set<ll>();
            } 

            if (!mapa.count(e2)) {
                mapa[e2] = set<ll>();
            } 

            mapa[e1].insert(e2);
            mapa[e2].insert(e1);
        }        
        
        queue<pair<ll, ll>> q;

        for (auto x : mapa[1]) {
            q.push({x, 1});
            paths[x-1][1] = 1; 
        }

        // so basically there are 2 states: even or odd (represented by a remainder), each new node reverses the remainder
        // the confusing part is the bfs imo, it finds a min for each remainder, but it is a little confusing how it does it
        // every node will be reached in the graph, and since the state reverses on every next node, if there is a path of with an odd difference in length,
        // it will result in a different remainder and hence we can minimize it
        while (!q.empty()) {
            auto [vert, rem] = q.front();
            q.pop();
            for (auto x : mapa[vert]) {
                if (paths[x-1][!rem] > paths[vert-1][rem] + 1) {
                    q.push({x, !rem});
                    paths[x-1][!rem] = paths[vert-1][rem] + 1; 
                }
            }
        }

        /*
        for (auto x : paths) {
            cout << x[0] << '-' << x[1] << ' ';
        }
        cout << endl;
        */

        cout << "1";
        for (int i = 1; i<n; ++i) {
            bool found = false;
            if (s % 2) {
                if (paths[i][1] != max_n && s >= paths[i][1]) {
                    found = true;
                } else if (paths[i][0] != max_n && s_o != max_n && (s - s_o) >= paths[i][0]) {
                    found = true;
                }
            } else {
                if (paths[i][0] != max_n && s >= paths[i][0]) {
                    found = true;
                } else if (paths[i][1] != max_n && s_o != max_n && (s - s_o) >= paths[i][1]) {
                    found = true;
                }
            }

            if (found) {
                cout << "1";
            } else {
                cout << "0";
            }
        }

        cout << "\n";

    }

    return 0;
}
