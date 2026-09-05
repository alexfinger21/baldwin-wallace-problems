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

        vector<ll> a(n);

        for (int i = 0; i<n; ++i) {
             cin >> a[i];
        }

        bool changed = true;
        int first_changed = 0;
        int last_changed = n-1;

        while (changed) {
            changed = false;

            for (int i = max(1, first_changed); i<n-1; ++i) {
                if ((a[i-1] & 1) == (a[i+1] & 1)) {
                    if ((a[i-1] + a[i+1] - a[i]) < a[i]) {
                        a[i] = a[i-1] + a[i+1] - a[i];
                        changed = true;
                        last_changed = i + 2;
                    }
                }
            }

            for (int i = min(last_changed, n-2); i>0; --i) {
                if ((a[i-1] & 1) == (a[i+1] & 1)) {
                    if ((a[i-1] + a[i+1] - a[i]) < a[i]) {
                        a[i] = a[i-1] + a[i+1] - a[i];
                        changed = true;
                        first_changed = i - 2;
                    }
                }
            }
        }

        for (int i = 0; i<n; ++i) {
            cout << a[i] << ' ';
        }

        cout << '\n';
    }

    return 0;
}
