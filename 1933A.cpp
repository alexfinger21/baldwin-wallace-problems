#include <bits/stdc++.h>

using ll=long long;
using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;

    while (t--) {
        short n;
        cin >> n;

        short res = 0;

        for (short i = 0; i<n; ++i) {
            short nn;
            cin >> nn;

            res += abs(nn);
        }

        cout << res << '\n';
    }

    return 0;
}
