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

        set<char> d;
        int res = 0;

        for (int i = 0; i<n; ++i) {
            d.insert(s[i]);

            res += d.size();
        }

        cout << res << '\n';
    }

    return 0;
}
