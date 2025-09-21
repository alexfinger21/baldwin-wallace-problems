#include <bits/stdc++.h>

using ll=long long;
using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<set<int>> s(n);
        map<int, int> cnts;
        int not_uniq = n;

        for (int i = 0; i<n; ++i) {
            int h;
            cin >> h;

            for (int j = 0; j<h; ++j) {
                int f;
                cin >> f;

                s[i].insert(f);

                if (!cnts.count(f)) {
                    cnts[f] = i;
                } else {
                    cnts[f] = -1;
                }
            }
        }

        if (cnts.size() < m) {
            cout << "NO\n";
            continue;
        }

        map<int, int> prev;

        for (auto x : cnts) {
            if (x.second != -1 && !prev.count(x.second)) {
                --not_uniq;
                prev[x.second] = 1;
            }
        }

        if (not_uniq > 1) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }

    }

    return 0;
}
