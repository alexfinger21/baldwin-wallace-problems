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

        map<int, int> top;
        map<int, int> btm;
        int s1 = 0, s2 = 0;

        for (int i = 0; i<n; ++i) {
            int n1, n2;
            cin >> n1 >> n2;

            if (n2) {
                top[n1] = 1;
                ++s1;
            } else {
                btm[n1] = 1;
                ++s2;
            }
        }

        ll res = 0;

        for (auto x : top) {
            if (x.second && btm[x.first]) {
                res += s2 - 1 + s1 - 1;
            }

            if (x.second && btm[x.first - 1] && btm[x.first + 1]) {
                ++res;
            }
        }

        for (auto x : btm) {
            if (x.second && top[x.first - 1] && top[x.first+1]) {
                ++res;
            }
        }

        cout << res << '\n';
    }

    return 0;
}
