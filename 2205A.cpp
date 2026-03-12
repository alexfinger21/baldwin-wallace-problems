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

        vector<int> perm(n);

        int m_idx = -1;

        for (int i = 0; i<n; ++i) {
            cin >> perm[i];
            if (perm[i] == n) {
                m_idx = i;
            }
        } 

        if (n != 1 && m_idx) {
            perm[m_idx] ^= perm[0];
            perm[0] ^= perm[m_idx];
            perm[m_idx] ^= perm[0];
        }

        for (auto x : perm) {
            cout << x << ' ';
        }

        cout << '\n';
    }

    return 0;
}
