#include <bits/stdc++.h>

using ll=long long;
using namespace std;

ll fact[(int)(1e6)];
ll mod = 998244353;

ll facto(ll n) {
    return fact[n-1];
}

int32_t main() {
    fact[0] = 1;

    for (int i = 2; i<=1e6; ++i) {
        fact[i-1] = (fact[i-2] * i)%mod;
    }

    int n;
    cin >> n;

    vector<ll> dp;

    dp.push_back(1);

    for (int i = 1; i<n; ++i) {
        dp.push_back((dp[i-1]+facto(i)-1)*(i+1)%mod);
    }

    cout << dp[dp.size()-1] << '\n';

    return 0;
}
