#include <bits/stdc++.h>

using ll=long long;
using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;

    while (t--) {
        int n, m, w;
        ll k;
        cin >> n >> m >> k >> w;

        priority_queue<int> gorillaz;
        priority_queue<ll> occurs;

        for (int i = 0; i<w; ++i) {
            int gh;
            cin >> gh;
            gorillaz.push(gh);
        }

        for (int i = 0; i<n; ++i) {
            for (int j = 0; j<m; ++j) {
                int top = min(i - 0, n-1-i) + 1;
                int left = min(j - 0, m-1-j) + 1;

                occurs.push(min(1LL*top, min(k, n-k+1))*min(1LL*left, min(k, m-k+1)));
            }
        }

        ll res = 0;

        for (int i = 0; i<w; ++i) {
            res += occurs.top() * gorillaz.top();
            occurs.pop();
            gorillaz.pop();
        }

        cout << res << '\n';

    }

    return 0;
}
