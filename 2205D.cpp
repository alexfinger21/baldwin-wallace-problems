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
        vector<int> indices(n+1);


        for (int i = 0; i<n; ++i) {
            cin >> a[i];
        }

        vector<int> dp(n);
        vector<int> dp1(n);
        dp[0] = 1;
        vector<int> prev;
        prev.push_back(a[0]);

        for (int i = 1; i<n; ++i) {
            while (!prev.empty() && prev.back() <= a[i]) {
                prev.pop_back();
            }

            prev.push_back(a[i]);
            dp[i] = prev.size();
        } 

        dp1[n-1] = 1;
        prev = {a[n-1]};

        for (int i = n-2; i>=0; --i) {
            while (!prev.empty() && prev.back() <= a[i]) {
                prev.pop_back();
            }

            prev.push_back(a[i]);
            dp1[i] = prev.size();
        } 

        int mx = 0;

        for (int i = 0; i<n-1; ++i) {
            // cout << dp[i] << ' ' << dp1[i+1] << endl;
            mx = max(mx, dp[i] + dp1[i+1]);
        }

        cout << n - mx << '\n';

    }

    return 0;
}
