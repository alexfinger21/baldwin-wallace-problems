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

        int ac = 0;
        int bc = 0;

        ll b;

        for (int i = 0; i<n; ++i) {
            cin >> b;

            if (b == 1) {
                ++ac;
            } else {
                ++bc;
            }
        }

        if ((bc && (ac % 2)) || (!bc && !(ac % 2))) {
            cout << "Bob\n";
        } else {
            cout << "Alice\n";
        }
    }

    return 0;
}
