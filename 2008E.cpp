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

        string s;
        cin >> s;

        vector<int> dp(n, 1);

        for (int i = 2; i<n; ++i) {
            if (s[i-2] == s[i]) {
                dp[i] += dp[i-2];
            }
        }

        int m1 = 0;
        int m2 = 1;

        for (int i = 0; i<n; i+=2) {
            if (dp[i] > dp[m1]) {
                m1 = i;    
            }
        }

        for (int i = 1; i<n; i+=2) {
            if (dp[i] > dp[m2]) {
                m2 = i;    
            }
        }

        int c = 0;

        if (!(n%2)) {
            for (int i = 0; i<n; i+=2) {
                if (s[i] != s[m1]) {
                    ++c;
                }
            }
            
            for (int i = 1; i<n; i+=2) {
                if (s[i] != s[m2]) {
                    ++c;
                }
            }
        } else {
            ++c;
            int numSaved = 0, idx = n-1;

            cout << m1 << ' ' << m2 << endl;

            for (int i = 0; i<n; ++i) {
                if (i > 0 && i < n-2 && s[i+2] == s[i-1]) {
                    if (s[i+2] == s[m1] || s[i+2] == s[m2]) {
                        idx = i;
                        break;
                    }
                }
            }
            if (0<n-2 && !(s[0] == s[m1] || s[0] == s[m2]) && (s[2] == s[m1] || s[2] == s[m2])) {
                idx = 0;
            }

            cout << idx << endl;

            for (int i = 0; i<n; i+=2) {
                if (i < idx) {
                    if (s[i] != s[m1]) {
                        ++c;
                    }
                }
                if (i > idx) {
                    if (s[i] != s[m2]) {
                        ++c;
                    }

                }
            }
            
            for (int i = 1; i<n; i+=2) {
                if (i < idx) {
                    if (s[i] != s[m2]) {
                        ++c;
                    }
                }
                if (i > idx) {
                    if (s[i] != s[m1]) {
                        ++c;
                    }
                }
            }
        }

        cout << c << '\n'; 
    }

    return 0;
}
