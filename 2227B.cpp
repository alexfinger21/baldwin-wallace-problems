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

        string s;

        cin >> n >> s;
        
        int a = 0, b = 0;

        for (int i = 0; i<n; ++i) {
            if (s[i] == '(') {
                ++a;
            } else {
                ++b;
            }
        }

        if (a == b) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}
