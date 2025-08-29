#include <bits/stdc++.h>
#include <climits>

using ll=long long;
using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;

    while (t--) {
        int n;
        int k;
        cin >> n;
        cin >> k;

        vector<int> a(n);

        for (int i = 0; i<n; ++i) {
            cin >> a[i];
        }


        vector<int> dp(n, INT_MAX);

        dp[n-1] = 0;
        for (int i = n-2; i>=0; --i) {
            int s = 0;
            for (int j = i; j<n; ++j) {
                s += a[i];

                if (s > k) {
                    break;
                }

                if (j == n-1) {
                    dp[i] = 0;
                } else {
                    dp[i] = min(dp[i], dp[i+1] + static_cast<int>(pow(k - s, 2)));
                }
                ++s;
            } 
        }

        cout << dp[0] << '\n';
    }

    return 0;
}
