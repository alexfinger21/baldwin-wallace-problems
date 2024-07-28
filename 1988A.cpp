#include <bits/stdc++.h>

using namespace std;

int32_t main() {
    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        int ops = 0;

        while (n > 1) {
            n -= k-1;
            ++ops;
        }

        cout << ops << '\n';
    }

    return 0;
}
