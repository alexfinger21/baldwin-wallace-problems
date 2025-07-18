#include <bits/stdc++.h>

using ll=long long;
using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;

    vector<ll> dp(1e5+1);
    dp[0] = 1;

    for (int i = 1; i<dp.size(); ++i) {
        dp[i] = (dp[i-1] * 2) % ((ll)(1e9) + 7);
    }

    vector<pair<int, int>> nms(t);

    for (int i = 0; i<t; ++i) {
        int n;
        cin >> n;
        nms[i].first = n;
    }
    for (int i = 0; i<t; ++i) {
        int n;
        cin >> n;
        nms[i].second = n;
    }

    for (auto x : nms) {
        cout << dp[x.second] << '\n';
    }

    return 0;
}
