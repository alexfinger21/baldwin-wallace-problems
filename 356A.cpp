#include <algorithm>
#include <bits/stdc++.h>

using ll=long long;
using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;

    cin >> n >> m;

    vector<int> winners(n + 1);

    vector<int> rem(n + 1);

    for (int i = 1; i<=n; ++i) {
        rem[i] = i; 
    }

    for (int i = 0; i<m; ++i) {
        int l, h, w;
        cin >> l >> h >> w;

        int idx = lower_bound(rem.begin(), rem.end(), l) - rem.begin();

        for (int j = idx; j<rem.size(); ++j) {
            if (rem[j] > h) {
                break;
            }

            if (rem[j] != w) {
                winners[rem[j]] = w;
                rem.erase(rem.begin() + j);
                --j;
            }
        }
    }

    for (int i = 1; i<=n; ++i) {
        cout << winners[i] << ' ';
    }

    cout << '\n';

    return 0;
}
