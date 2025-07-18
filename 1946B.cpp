#include <bits/stdc++.h>

using ll=long long;
using namespace std;

ll rem = 1e9+7;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;

    while (t--) {
        ll s = 0;
        ll o = 0;


        int n, k;
        cin >> n >> k;
        vector<ll> dp(n);

        for (int i = 0; i<n; ++i) {
            ll nn;
            cin >> nn;

            dp[i] = max(nn, nn+dp[max(0, i-1)]);

            o += nn;
        }

        for (auto x : dp) {
            s = max(x, s);
        }
        
        ll mult = 1;

        for (int i = 1; i<=k; ++i) {
            mult = (mult*2)%rem;
        }

        ll r = (s%rem)*mult-s+o;

        //can also just do (r%rem+rem)%rem for the same result b/c it will always make a neg a pos and the 
        //formula for rem is num=og*x+rem where rem is pos, for neg its reversed
        //b/c rem has to be pos so the abs of og*x gotta be >= than num, then rem is pos so it makes the abs(og*x) smaller.  

        if (r < 0) {
            cout << (rem - ((abs(r) % rem) == 0 ? rem : (abs(r) % rem))) << '\n';
        } else {
            cout << (r % rem) << '\n';
        }
    }

    return 0;
}
