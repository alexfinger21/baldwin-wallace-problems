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

        vector<short> a(n);

        for (int i = 0; i<n; ++i) {
            string s;
            cin >> s;

            for (int j = 0; j<4; ++j) {
                if (s[j] == '#') {
                    a[i] = j+1;
                    break;
                }
            }
        }

        for (int i = a.size()-1; i>=0; --i) {
            cout << a[i] << ' ';
        }
        cout << '\n';
    }

    return 0;
}
