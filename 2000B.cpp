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

        vector<int> spots(n);

        bool found = false;

        int f;
        cin >> f;
        --f;

        if (f > 0) {
            spots[f-1] = 1; 
        }

        if (f < n-1) {
            spots[f+1] = 1; 
        }

        for (int i = 1; i<n; ++i) {
            int idx;
            cin >> idx;
            --idx;

            if (!found) {
                if (!spots[idx]) {
                    found = true;
                } else {
                    if (idx < n - 1) {
                        spots[idx+1] = 1;
                    }
                    if (idx > 0) {
                        spots[idx-1] = 1;
                    }
                }
            }
        }

        cout << (found ? "NO\n" : "YES\n");
    }

    return 0;
}
