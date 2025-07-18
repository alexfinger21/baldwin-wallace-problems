#include <bits/stdc++.h>

using ll=long long;
using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        vector<int> h(n);
        set<int> b;

        for (int i = 0; i<n; ++i) {
            cin >> h[i];
            b.insert(h[i]);
        }

        int curr_h = h[k-1];

        int lvl = 1;
        bool quit = false;

        for (auto x : b) {
            if (x > curr_h) {
                if (x - curr_h <= (curr_h-lvl + 1)) {
                    lvl += x - curr_h;
                    curr_h = x;
                } else {
                    quit = true;
                    break;
                }
            }
        }

        cout << (quit ? "NO" : "YES") << '\n';
    }

    return 0;
}
