#include <bits/stdc++.h>
using namespace std;

using ll=long long;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n1;
        cin >> n1; 
        vector<ll> costs(n1);
        vector<ll> weight(n1);

        for (int i = 0; i<n1; ++i) {
            cin >> costs[i];
        }

        for (int i = 0; i<n1; ++i) {
            cin >> weight[i];
        }

        vector<ll> dp(36, -1);

        for (int i = 0; i<n1; ++i) {
            for (int j = 35; j>=weight[i]; --j) {
                if (j == weight[i]) {
                    dp[j] = max(dp[j], costs[i]);
                } else if (dp[j-weight[i]] != -1) {
                    dp[j] = max(dp[j], dp[j-weight[i]] + costs[i]);
                }
            }
        }

        ll res = 0;
        for (int i = 0; i<=35; ++i) {
            res = max(dp[i], res);
        }

        cout << res << '\n';
    }
}
