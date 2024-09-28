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

        string s;
        cin >> s;

        ll res = 0;

        for (int i = 0; i<n; ++i) {
            res += s[i] - '+' ? -1 : 1;
        }

        res = abs(res);
        
        cout << res << '\n';

    }

    return 0;
}
