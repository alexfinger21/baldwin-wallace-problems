#include <bits/stdc++.h>

using ll=long long;
using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;

    vector<string> rws(n);

    for (int i = 0; i<n; ++i) {
        cin >> rws[i];
    }

    int res = 1;

    for (int i = 0; i<n; ++i) {
        int r = 1;
        for (int j = i+1; j<n; ++j) {
            if (rws[i] == rws[j]) {
                ++r;
            }
        }
        res = max(res, r);
    }

    cout << res << '\n';

    return 0;
}
