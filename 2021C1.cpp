#include <bits/stdc++.h>

using ll=long long;
using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;

    while (t--) {
        int n, m, q;
        cin >> n >> m >> q;

        vector<int> a(n);
        vector<int> b(m);

        for (int i = 0; i<n; ++i) {
            int nm;
            cin >> nm;

            a[nm-1] = i;
        }

        for (int i = 0; i<m; ++i) {
            cin >> b[i];
            --b[i];
        }

        bool found = false;
        int lidx = 0;
        for (int i = 0; i<m; ++i) {
            //cout << lidx << " " <<  b[i] << ' ' <<a[b[i]] << endl;
            if (a[b[i]] <= lidx) {
                if (a[b[i]] != -1) {
                    a[b[i]] = -1;
                    ++lidx;
                }
            } else {
                found = true;
                break;
            }
        }

        if (found) {
            cout << "TIDAK\n";
        } else {
            cout << "YA\n";
        }

    }

    return 0;
}
