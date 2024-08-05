#include <bits/stdc++.h>

using ll=long long;
using namespace std;

int32_t main() {
    int t;
    cin >> t;

    while (t--) {
        int n, x, y;

        cin >> n >> x >> y;

        for (int i = 0; i<y-1; ++i) {
            if ((y-i) % 2) {
                cout << "1 ";
            } else {
                cout << "-1 ";
            }
        }
        
        for (int i = y-1; i<x; ++i) {
            cout << "1 ";
        }

        for (int i = 0; i<n-x; ++i) {
            if (!(i % 2)) {
                cout << "-1 ";
            } else {
                cout << "1 ";
            }
        }

        cout << '\n';
    }

    return 0;
}
