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
        for (int i = 0; i<n; ++i) {
            cout << (i+1)+(i) << ' ';
        }
        cout << '\n';
    }

    return 0;
}
