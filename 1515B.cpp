#include <bits/stdc++.h>

using ll=long long;
using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;

    while (t--) {
        ll n;
        cin >> n;

        if (!(n % 2)) {
            if (pow((ll)(sqrt(n/2)), 2) == n/2) {
                cout << "YES\n";
                continue;
            }
        }

        if (!(n % 4)) {
            if (pow((ll)(sqrt(n/4)), 2) == n/4) {
                cout << "YES\n";
                continue;
            }
        }

        cout << "NO\n";
    }

    
    return 0;
}
