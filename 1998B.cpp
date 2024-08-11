#include <bits/stdc++.h>

using ll=long long;
using namespace std;

int32_t main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> perm(n);

        for (int i = 0; i<n; ++i) {
            cin >> perm[i];
        }

        cout << perm[n-1] << ' ';

        for (int i = 0; i<n-1; ++i) {
            cout << perm[i] << ' ';
        }

        cout << '\n';
    }

    return 0;
}
