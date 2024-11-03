#include <iostream>
#include <bits/stdc++.h>

using namespace std;
using ll=long long;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<ll> a(n);

        for (int i = 0; i<n; ++i) {
            cin >> a[i];
        }

        vector<vector<ll>> dp(n+1);

        for (int i = 0; i<n; ++i) {
            dp[i] = vector<ll>(n+1);
        }

        dp[0][n-1] = a[n-1];

        for (int i = 0; i<n; ++i) {
            for (int j = 0; j<=i; ++j) {
                dp[j+1][n-i-1] = max(dp[j+1][n-i-1], dp[j][n-i] + (j+1)*a[j]);
                dp[j+1][n-i-1] = max(dp[j+1][n-i-1], dp[j+1][n-i] + (j+1)*a[j+n-i-1]);
            }
        }

        for (auto x : dp) {
            for (auto z : x) {
                cout << z << ' ';
            }
            cout << endl;
        }
    }
    return 0;
}
