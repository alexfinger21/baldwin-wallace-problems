#include <bits/stdc++.h>

using ll=long long;
using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;

    while (t--) {
        ll n, k;

        cin >> n >> k;

        if (n % 2) {
            if (!((k-1)/2 % 2)) {
                cout << "No\n";
            } else {
                cout << "Yes\n";
            }
        } else {
            if (!(k/2 % 2)) {
                cout << "Yes\n";
            } else {
                cout << "No\n";
            }
        }
    }

    return 0;
}
