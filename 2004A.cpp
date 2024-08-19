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

        vector<int> pts(n);

        for (int i = 0; i<n; ++i) {
            cin >> pts[i];
        }

        if (n > 2) {
            cout << "nO\n";
        } else if (abs(pts[0] - pts[1]) > 1) {
            cout << "YeS\n";
        } else {
            cout << "nO\n";
        }
    }

    return 0;
}
