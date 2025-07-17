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

        int res = 0;
        for (int i = 0; i<n; ++i) {
            cin >> a[i];
        }

        int lst = 0;

        for (int i = 0; i<n; ++i) {
            if (a[i]) {
                lst = -1;
            } else {
                if (lst == -1) {
                    lst = i;
                } 
                if (i - lst + 1 == k) {
                    ++res;
                    lst = i+2;
                }
            }
        }

        cout << res << '\n';
    }

    return 0;
}
