#include <bits/stdc++.h>

using ll=long long;
using namespace std;

int inf = (int)(1e9);

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;


    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> dp(k+1, inf);

        dp[0] = 0;

        while (n--) {
            vector<int> cost_a(k+1, inf);
            cost_a[0] = 0;
            int a, b, cost = 0, cnt = 0;
            cin >> a >> b;
            
            while (k > cnt && (a > 0 || b > 0)) {
                if (a < b) {
                    swap(a, b);
                }

                cost += b;
                ++cnt;
                cost_a[cnt] = cost;
                --a;
            }

            for (int i = k - 1; i>=0; --i) {
                for (int j = 1; j<=k-i; ++j) {
                    dp[i+j] = min(dp[i+j], dp[i] + cost_a[j]);
                }
            }
        }

        cout << (dp[k] == inf ? -1 : dp[k]) << '\n';
    }

    return 0;
}
