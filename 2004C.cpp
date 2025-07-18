#include <bits/stdc++.h>

using ll=long long;
using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        priority_queue<int> a;

        for (int i = 0; i<n; ++i) {
            int num;
            cin >> num;

            a.push(num);
        }

        ll diffs = 0;

        for (int i = 0; i<n-1; i += 2) {
            diffs += a.top();
            a.pop();
            diffs -= a.top();
            a.pop();
        }

        ll res = max(0LL, diffs-k);

        if (n % 2) {
            res += a.top();
        }

        cout << res << '\n';
    }

    return 0;
}
