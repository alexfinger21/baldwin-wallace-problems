#include <bits/stdc++.h>
using ll = long long;
using namespace std;
static const int MOD = 998244353;
ll modexp(ll a, ll e = MOD-2) {
    ll r = 1;
    while (e) {
        if (e & 1) r = r * a % MOD;
        a = a * a % MOD;
        e >>= 1;
    }
    return r;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int,int>>> segs(m+1);
    vector<ll> P(n), B(n), W(n);
    for (int i = 0; i < n; i++) {
        int l, r, p, q;
        cin >> l >> r >> p >> q;
        ll invq = modexp(q);
        P[i] = p * invq % MOD;
        B[i] = (MOD + 1 - P[i]) % MOD;
        W[i] = P[i] * modexp(B[i]) % MOD;
        segs[r].emplace_back(l, i);
    }
    ll Ball = 1;
    for (int i = 0; i < n; i++) {
        Ball = Ball * B[i] % MOD;
    }
    vector<ll> dp(m+1);
    dp[0] = 1;
    for (int x = 1; x <= m; x++) {
        ll sum = 0;
        for (auto &pr : segs[x]) {
            int l = pr.first, idx = pr.second;
            sum = (sum + W[idx] * dp[l-1]) % MOD;
        }
        dp[x] = sum;
    }
    cout << Ball * dp[m] % MOD;
    return 0;
}

