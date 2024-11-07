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

        if (n == 1 || n == 3) {
            cout << "-1\n";
            continue;
        }

        string res = "";
        for (int i = 0; i<n; ++i) {
            if (i < 2 || (n % 2 && i == 3)) {
                res = '6' + res; 
            } else {
                res = '3' + res;
            }
        }

        cout << res << '\n';
    }

    return 0;
}
