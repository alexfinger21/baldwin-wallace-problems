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
        ll mean = 0;

        for (int i = 0; i<n; ++i) {
            cin >> a[i];
            mean = max(mean, a[i]);
        }

        mean = mean/2;
        int i;
        bool found = false;
        for (int j = 0; j<n; ++j) {
            if (a[j]) {
                found = true;
                break;
            }
        }

        if (!found) {
            cout << "0\n\n";
            continue;
        }

        vector<ll> means;

        for (i = 0; i<40; ++i) {
            means.push_back(mean);
            found = false;
            ll mean2 = 0;
            for (int j = 0; j<n; ++j) {
                a[j] = abs(a[j] - mean); 
                if (a[j]) {
                    found = true;
                }
                mean2 = max(mean2, a[j]);
            }
            if (!found) {
                cout << i+1 << '\n';
                for (auto x : means) {
                    cout << x << ' ';
                }
                cout << '\n';
                break;
            }
            mean = max(1LL, mean2/2);
        }
        if (found) {
            cout << "-1\n";
        }
    }

    return 0;
}
