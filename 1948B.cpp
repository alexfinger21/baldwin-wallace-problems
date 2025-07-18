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

        vector<int> dp(n);

        bool found = false;

        for (int i = 0; i<n; ++i) {
            int nm;
            cin >> nm;

            if (!found) {
                if (i > 0 && (nm/10)%10 < dp[i-1]) {
                    dp[i] = nm;
                    if (dp[i-1] > nm) {
                        found = true;
                    }
                } else {
                    if ((nm/10)%10 <= (nm%10)) {
                        dp[i] = nm%10;
                    } else {
                        if (i > 0 && dp[i-1] > nm) {
                            found = true;
                        } else {
                            dp[i] = nm;
                        }
                    }
                }
            }
        }

        if (!found) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }

    }

    return 0;
}
