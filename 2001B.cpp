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
        
        if (!(n%2)) {
            cout << "-1\n";
        } else {
            for (int i = 1; i<=n; ++i) {
                if (i < (n+1)/2) {
                    cout << i << ' ';
                } else {
                    cout << n - i + (n+1)/2 << ' ';
                }
            }

            cout << '\n';
        }
    }

    return 0;
}
