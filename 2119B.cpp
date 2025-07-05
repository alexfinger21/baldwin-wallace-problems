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
        ll px, py, qx, qy;
        cin >> px >> py >> qx >> qy;

        ll dist = (px - qx) * (px - qx) + (py - qy) * (py - qy);

        ll mx = 0;
        ll mn = 0;
        ll bg = 0;



        for (int i = 0; i<n; ++i) {
            ll b;
            cin >> b;
            mx += b;

            bg = max(bg, b);
        } 
        if (bg * 2 > mx) {
            mn = bg - (mx - bg);
        }

        mx = mx * mx;
        mn = mn * mn;

        if (dist >= mn && dist <= mx) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }

    return 0;
}
