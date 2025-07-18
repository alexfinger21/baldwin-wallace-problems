#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
        }
    }

    vector<vector<pair<int, int>>> adj(n);
    bool possible = true;

    for (int r1 = 0; r1 < n; ++r1) {
        int r2 = n - 1 - r1;
        if (r1 >= r2) break;
        int c = -1;
        bool valid = true;
        for (int j = 0; j < m; ++j) {
            int j2 = m - 1 - j;
            int current = a[r1][j] ^ a[r2][j2];
            if (c == -1) {
                c = current;
            } else if (current != c) {
                valid = false;
                break;
            }
        }
        if (!valid) {
            possible = false;
            break;
        }
        adj[r1].emplace_back(r2, c);
        adj[r2].emplace_back(r1, c);
    }

    if (!possible) {
        cout << -1 << endl;
        return 0;
    }

    vector<int> color(n, -1);
    int total = 0;
    for (int i = 0; i < n; ++i) {
        if (color[i] == -1) {
            queue<int> q;
            q.push(i);
            color[i] = 0;
            int cnt0 = 1, cnt1 = 0;
            bool bipartite = true;
            while (!q.empty() && bipartite) {
                int u = q.front();
                q.pop();
                for (auto [v, c] : adj[u]) {
                    int expected = color[u] ^ c;
                    if (color[v] == -1) {
                        color[v] = expected;
                        if (expected == 0) cnt0++;
                        else cnt1++;
                        q.push(v);
                    } else if (color[v] != expected) {
                        bipartite = false;
                        break;
                    }
                }
            }
            if (!bipartite) {
                cout << -1 << endl;
                return 0;
            }
            total += min(cnt0, cnt1);
        }
    }

    cout << total << endl;
    return 0;
}
