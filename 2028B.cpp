#include <bits/stdc++.h>

using ll=long long;
using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;

    while (t--) {
        ll n, c, b;
        cin >> n >> b >> c;

        if (b == 0) {
            if ((n - c) <= 2) {
                if (n == 1) {
                    if (c == 0) {
                        cout << "0\n";
                        continue;
                    } else {
                        cout << "1\n";
                        continue;
                    }
                } else {
                    if (c == 0) {
                        cout << "1\n";
                        continue;
                    } else {
                        cout << (c < n ? n-1 : n) << "\n";
                        continue;
                    }
                }
            } else {
                cout << "-1\n";
                continue;
            }
        }

        ll inPerm = max(0LL, (n-c-1)/b);

        if (c < n) {
            ++inPerm;
        }

        cout << n - inPerm << '\n';
    }

    return 0;
}
