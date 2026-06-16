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

        string s;
        cin >> s;

        int cnt = 0;
        vector<int> res(n);

        int lc = 0, rc = 0;
        int last_left = -1, last_right = n;

        for (int i = 0; i<n; ++i) {
            if (s[i] == '(') {
                ++lc;
            } else {
                ++rc;
            } 

            if (lc < rc) {
                last_left = i;
                lc = 0;
                rc = 0;
            }
        }

        lc = 0;
        rc = 0;

        for (int i = n-1; i>=0; --i) {
            if (s[i] == '(') {
                ++lc;
            } else {
                ++rc;
            } 

            if (lc > rc) {
                last_right = i;
                lc = 0;
                rc = 0;
            }
        }

        for (int i = 0; i<=last_left; ++i) {
            if (cnt == k) {
                break;
            }

            if (s[i] == '(') {
                res[i] = 1;
                ++cnt;
            } 
        }

        for (int i = n-1; i>=last_right; --i) {
            if (cnt == k) {
                break;
            }

            if (s[i] == ')') {
                res[i] = 1;
                ++cnt;
            } 
        }

        if (cnt < k) {
            for (int i = 0; i<n; ++i) {
                if (cnt == k) {
                    break;
                }

                if (s[i] == '(' && !res[i]) {
                    res[i] = 1;
                    ++cnt;
                }
            }
        }

        for (int i = 0; i<n; ++i) {
            cout << res[i];
        }

        cout << '\n';
    }

    return 0;
}
