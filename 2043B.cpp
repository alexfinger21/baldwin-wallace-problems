#include <bits/stdc++.h>

using ll=long long;
using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;

    while (t--) {
        int n, d;
        cin >> n >> d;

        cout << "1 ";
        
        if (n >= 3 || !(d % 3)) {
            cout << "3 ";
        }

        if (d == 5) {
            cout << "5 ";
        }

        if (n >= 3 || d == 7) {
            cout << "7 ";
        }

        if (n >= 6 || (!(d % 3) && n >= 3) || (d == 9)) {
            cout << "9 ";
        }
        cout << '\n';
    }

    return 0;
}
