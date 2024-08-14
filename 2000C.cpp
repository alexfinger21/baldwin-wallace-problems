#include <bits/stdc++.h>

using ll=long long;
using namespace std;

int32_t main() {
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n;

        vector<int> a(n);
        map<int, vector<int>> mapa;

        for (int i = 0; i<n; ++i) {
            cin >> a[i];

            if (mapa.count(a[i])) {
                mapa[a[i]].push_back(i);
            } else {
                mapa[a[i]] = vector<int> {i};
            }
        }

        cin >> m;

        for (int i = 0; i<m; ++i) {
            string s;
            cin >> s;

            set<char> used;

            bool found = true;
            if (s.size() == n) {
                found = false;
                for (auto x : mapa) {
                    char c = s[x.second[0]];
                    
                    if (used.find(c) != used.end()) {
                        found = true;
                        break;
                    }

                    used.insert(c);

                    for (auto z : x.second) {
                        if (s[z] != c) {
                            found = true;
                            break;
                        }
                    }
                    
                    if (found) {
                        break;
                    }
                }
            } 
            if (!found) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        }
    }

    return 0;
}
