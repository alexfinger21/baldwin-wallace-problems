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
        string r;
        cin >> s >> r;

        int c0 = 0, c1 = 0;

        for (int i = 0; i<n; ++i) {
            if (s[i] == '1') {
                ++c1;
            } else {
                ++c0;
            }
        }

        bool found = false;

        for (int i = 0; i<n-1; ++i) {
            if (min(c0, c1)) {
                --c0;
                --c1;

                if (r[i] == '1') {
                    ++c1;
                } else {
                    ++c0;
                }
            } else {
                found = true;
                break;
            }
        }

        if (found) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
        }
    }

    return 0;
}
