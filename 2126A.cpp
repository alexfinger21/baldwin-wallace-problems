#include <bits/stdc++.h>

using ll=long long;
using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;

    while (t--) {
        string x;
        cin >> x;

        int mn = 9;
        for (int i = 0; i<x.size(); ++i) {
            mn = min(x[i] - '0', mn);
        }

        cout << mn << '\n';
    }

    return 0;
}
