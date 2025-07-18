#include <bits/stdc++.h>

using ll=long long;
using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;

    while (t--) {
        string x, y;
        cin >> x >> y;

        int idx = 0;
        while (x[idx] == y[idx] && idx < x.size()) {
            ++idx;
        }

        for (int i = idx+1; i<x.size(); ++i) {
            if (x[idx] > y[idx]) {
                if ((x[i] - '0') > (y[i] - '0')) {
                    char te = x[i];
                    x[i] = y[i];
                    y[i] = te;
                }
            } else {
                if ((x[i] - '0') < (y[i] - '0')) {
                    char te = x[i];
                    x[i] = y[i];
                    y[i] = te;
                }
            }
        }
       
        cout << x << '\n';
        cout << y << '\n';
    }

    return 0;
}
