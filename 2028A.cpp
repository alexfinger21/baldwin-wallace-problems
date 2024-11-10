#include <bits/stdc++.h>

using ll=long long;
using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;

    while (t--) {
        int n, a, b;
        cin >> n >> a >> b;

        string s;
        cin >> s;

        int px = 0;
        int py = 0;

        bool found = false;
        for (int j = 0; j<1000; ++j) {
            for (int i = 0; i<n; ++i) {
                if (s[i] == 'N') {
                    py += 1;
                }
                if (s[i] == 'S') {
                    py -= 1;
                }
                if (s[i] == 'W') {
                    px -= 1;
                }
                if (s[i] == 'E') {
                    px += 1;
                }

                if (px == a && py == b) {
                    found = true;
                    break;
                }
            } 
        }
        if (found) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}
