#include <bits/stdc++.h>

using ll=long long;
using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, k;
    cin >> n >> k;

    map<ll, ll> cnt;
    ll res = 0;
    map<ll, ll> dp;

    for (size_t i = 0; i<n; ++i) {
        ll nm;
        cin >> nm;
        if (cnt.count(nm)) {
            ++cnt[nm];
        } else {
            cnt[nm] = 1LL;
        }

        if (nm != 0) {
            if (!(nm % k)) {
                if (cnt[nm / k]) {
                    //cout << dp[nm / k] << ' ' << cnt[nm] << ' ' << nm << endl;
                    res += dp[nm / k];
                }

                if (dp.count(nm)) {
                    dp[nm] += cnt[nm / k];
                } else {
                    dp[nm] = cnt[nm / k];
                }
            }
        }
    }


    
    if (k == 1) {
        res = 0;
        for (auto x : cnt) {
            if (x.second && x.second >= 3) {
                res += x.second * (x.second - 1) * (x.second - 2) / 6LL;
            }
        }
    }

    if (cnt.count(0) && k != 1) {
        if (cnt[0] >= 3) {
            res += cnt[0] * (cnt[0] - 1) * (cnt[0] - 2) / 6LL;
        }
    }
    

    cout << res << '\n';

    return 0;
}
