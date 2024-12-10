#include <bits/stdc++.h>

using ll=long long;
using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        vector<int> a(n);

        for (int i = 0; i<n; ++i) {
            cin >> a[i];
        }

        bool found = false;
        int idx = -1;
        for (int i = 0; i<n; ++i) {
            bool fnd = false;
            for (int j = 0; j<n; ++j) {
                if (i != j) {
                    if (!(abs(a[i] - a[j]) % k)) {
                        fnd = true;
                        break;
                    }
                }
            }

            if (!fnd) {
                found = true;
                idx = i+1;
                break;
            }
        }

        if (found) {
            cout << "YES\n";
            cout << idx << '\n';
        } else { 
            cout << "NO\n";
        }

    }

    return 0;
}
