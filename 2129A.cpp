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

        map<int, int> pos;
        map<pair<int, int>, int> ids;

        for (int i = 0; i<n; ++i) {
            int b, c;
            cin >> b >> c;

            pos[b] = max(c-b, pos[b]);
            ids[make_pair(b, c)] = i+1;
        }

        int prevE = -1;
        vector<int> res;
        for (auto x : pos) {
            if ((x.second - max(0, prevE-x.first)) > 0) {
                res.push_back(ids[{x.first, x.second+x.first}]);
                prevE = x.first+x.second;
            }
        }

        cout << res.size() << '\n';

        for (auto x : res) {
            cout << x << ' ';
        }

        cout << '\n';
    }

    return 0;
}
