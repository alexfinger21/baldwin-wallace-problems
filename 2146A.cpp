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
        map<int, int> nms;

        for (int i = 0; i<n; ++i) {
            int f;
            cin >> f;
            ++nms[f];
        }


        vector<int> occurs;
        for (auto x: nms) {
            occurs.push_back(x.second);
        }

        sort(occurs.begin(), occurs.end(), greater<int>());

        int res = 0;
        for (int i = 0; i<occurs.size(); ++i) {
            res = max(res, occurs[i] * (i+1)); 
        }


        cout << res << '\n';
    }

    return 0;
}
