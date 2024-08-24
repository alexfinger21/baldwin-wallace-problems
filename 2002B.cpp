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

        vector<int> a(n);
        vector<int> b(n);

        for (int i = 0; i<n; ++i) {
            cin >> a[i];
        }

        for (int i = 0; i<n; ++i) {
            cin >> b[i];
        }
        
        int l = 0, h = n-1;
        int l2 = 0, h2 = n-1;

        while (l <= h) {
            if (a[l] != b[l2] && a[l] != b[h2]) {
                n = -1;
                cout << "Alice\n";

                break;
            }

            if (a[h] != b[l2] && a[h] != b[h2]) {
                n = -1;
                cout << "Alice\n";

                break;
            }


            if (b[l2] == a[l]) {
                ++l2;
            } else {
                --h2;
            }

            ++l;
        }

        if (n != -1) {
            cout << "Bob\n";
        }
    }

    return 0;
}
