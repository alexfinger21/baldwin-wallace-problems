#include <bits/stdc++.h>

using ll=long long;
using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;

    while (t--) {
        ll res = 0;
        ll gold = 0;

        int n, k;
        cin >> n >> k;

        for (int i = 0; i<n; ++i) {
            int num;
            cin >> num;

            if (num >= k) {
                gold += num;
            } else if (!num) {
                if (gold) {
                    --gold;
                    ++res;
                }
            }
        }

        cout << res << '\n';
    }

    return 0;
}
