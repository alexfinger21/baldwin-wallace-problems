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

        vector<ll> s, t, tw, f;

        for (int i = 0; i<n; ++i) {
            ll k;
            cin >> k;

            if (!(k % 2) && !(k % 3)) {
                s.push_back(k);
            } else if (!(k % 2)) {
                tw.push_back(k);
            } else if (!(k % 3)) {
                t.push_back(k);
            } else {
                f.push_back(k);
            }
        }

        for (int i = 0; i<s.size(); ++i) {
            cout << s[i] << ' ';
        }

        for (int i = 0; i<tw.size(); ++i) {
            cout << tw[i] << ' ';
        }

        for (int i = 0; i<f.size(); ++i) {
            cout << f[i] << ' ';
        }

        for (int i = 0; i<t.size(); ++i) {
            cout << t[i] << ' ';
        }

        cout << '\n';
    }

    return 0;
}
