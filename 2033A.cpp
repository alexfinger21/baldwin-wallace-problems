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

        if (n % 2) {
            cout << "Kosuke\n";
        } else {
            cout << "Sakurako\n";
        }
    }

    return 0;
}
