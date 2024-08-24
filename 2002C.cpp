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

        pair<ll, ll> circle[n];

        for (int i = 0; i<n; ++i) {
            int n1, n2;
            cin >> n1 >> n2;

            circle[i] = make_pair(n1, n2);
        }

        ll px, py, gx, gy;

        cin >> px >> py >> gx >> gy;

        ll dSum = abs(px-gx)*abs(px-gx) + abs(py-gy)*abs(py-gy);
        
        int i;

        for (i = 0; i<n; ++i) {
            ll dx = abs(gx - circle[i].first);
            ll dy = abs(gy - circle[i].second);

            if (dSum >= dx*dx+dy*dy) {
                cout << "nO\n";
                break;
            }
        }

        if (i == n) {
            cout << "yES\n";
        }
    }

    return 0;
}
