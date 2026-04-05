#include <bits/stdc++.h>

using ll=long long;
using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;

    for (int i = 0; i<n; ++i) {
        int h;
        cin >> h;
        for (int j = 0; j<h; ++j) {
            cout << "#";
        }
        cout << '\n';
    }

    return 0;
}
