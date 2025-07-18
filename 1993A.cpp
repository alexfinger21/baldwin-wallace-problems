#include <bits/stdc++.h>

using ll=long long;
using namespace std;

int32_t main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        int arr[4];

        for (int i = 0; i<4; ++i) {
            arr[i] = 0;
        }

        for (int i = 0; i<4*n; ++i) {
            char c;
            cin >> c;
            
            if (c != '?') {
                ++arr[c - 'A'];
            }
        }

        int res = 0;

        for (int i = 0; i<4; ++i) {
            res += min(arr[i], n);
        }

        cout << res << '\n';

    }

    return 0;
}
