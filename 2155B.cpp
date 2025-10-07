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

        if (n*n-k == 1) {
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";

        int bad = n*n - k;

        for (int i = 0; i<n; ++i) {
            for (int j = 0; j<n; ++j) {
                if (bad > i*n + j) {
                    if (j == 0 && bad != (i*n + 1)) {
                        cout << 'R';
                    } else if (j == 0) {
                        cout << 'U';
                    } else {
                        cout << 'L';
                    }
                } else {
                    cout << 'D';
                }
            } 
            cout << '\n';
        }
    }

    return 0;
}
