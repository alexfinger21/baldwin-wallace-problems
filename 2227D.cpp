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

        vector<pair<int, int>> ind(n, {-1, 0});

        for (int i = 0; i<2*n; ++i) {
            int p;
            cin >> p;

            if (ind[p].first == -1) {
                ind[p].first = i;
            } else {
                ind[p].second = i;
            }
        } 
    }

    return 0;
}
