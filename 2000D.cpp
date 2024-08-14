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
        string s;

        ll res = 0;
        ll sumT = 0;

        for (int i = 0; i<n; ++i) {
            cin >> a[i];
            sumT += a[i];
        }

        cin >> s;
        
        int l = n, r = -1;

        for (int i = 0; i<n; ++i) {
            if (s[i] == 'L') {
                l = i;
                break;
            }
            sumT -= a[i];
        }

        for (int i = n-1; i>=0; --i) {
            if (s[i] == 'R') {
                r = i;
                break;
            }
            sumT -= a[i];
        }

        while (l<r) {
            res += sumT;

            sumT -= a[l];
            ++l;
            while (l < n && s[l] != 'L') {
                sumT -= a[l];
                ++l;
            }
            
            sumT -= a[r];
            --r;
            while (r >= 0 && s[r] != 'R') {
                sumT -= a[r];
                --r;
            }
        }

        cout << res << '\n';
    }

    return 0;
}
