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

        vector<int> a(n), b(n);

        map<int, int> maxes;
        map<int, int> maxes2;
        int nm1 = 0, nmc = 0;
        int res = 0;

        for (int i = 0; i<n; ++i) {
            int nm;
            cin >> nm;

            if (nm == nm1) {
                ++nmc;
            } else {
                nm1 = nm;
                nmc = 1;
            }

            if (maxes.count(nm1)) {
                maxes[nm1] = max(maxes[nm1], nmc);
            } else {
                maxes[nm1] = nmc;
            }

            res = max(res, nmc);
        }

        nm1 = 0; nmc = 0;

        for (int i = 0; i<n; ++i) {
            int nm;
            cin >> nm;

            if (nm == nm1) {
                ++nmc;
            } else {
                nm1 = nm;
                nmc = 1;
            }

            if (maxes2.count(nm1)) {
                maxes2[nm1] = max(maxes2[nm1], nmc);
            } else {
                maxes2[nm1] = nmc;
            }

            res = max(res, nmc);
        }
        
        for (auto x : maxes) {
            if (maxes2.count(x.first)) {
                res = max(res, maxes2[x.first] + x.second);
            }
        }

        cout << res << '\n';

    }

    return 0;
}
