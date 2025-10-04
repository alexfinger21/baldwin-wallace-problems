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

        set<int> a;

        for (int i = 0; i<n; ++i) {
            int f;
            cin >> f;

            a.insert(f);
        }

        cout << (a.size() * 2 - 1) << '\n';

    }

    return 0;
}
