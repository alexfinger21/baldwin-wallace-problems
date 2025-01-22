#include <bits/stdc++.h>

using ll=long long;
using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll mod = 1e9+7;

    int n;
    cin >> n;

    vector<ll> dp(n, 1);

    string s;
    cin >> s;

    vector<ll> lims(26);

    for (int i = 0; i<26; ++i) {
        cin >> lims[i];
    }

    int maxL = 1;
    int mS = 1;
    int lastMax = 0;

    for (int i = 1; i<n; ++i) {
        ll mn = min(lims[s[i] - 'a'], lims[s[i-1] - 'a']);
        dp[i] = dp[i-1];

        int j;

        for (j = i-1; j>=0 && (i-j+1) <= mn; --j) {
            maxL = max(maxL, i-j+1);
            if (j == 0) {
                //cout << "zero" << endl;
                ++dp[i];
                continue;
            }
            /*
            if (s[i] == 'd') {
                cout << j << ' ' << dp[j-1] << endl;
            }
            */
            dp[i] = (dp[i] + dp[j-1]) % mod;
            mn = min(mn, lims[s[j-1]-'a']);
        }

        ++j;

        if (j > lastMax) {
            lastMax = i;
            ++mS;
        }
        
        //cout << dp[i] << endl;
    }

    cout << dp[n-1] << '\n';
    cout << maxL << '\n';
    cout << mS << '\n';

    return 0;
}
