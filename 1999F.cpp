#include <bits/stdc++.h>

using ll=long long;
using namespace std;

const int N = 2e5 + 5, mod = 1e9 + 7;
ll fact[N];

int64_t pw(int64_t a, int64_t b) {
	int64_t r = 1;
	while(b > 0) {
		if(b & 1) r = (r * a) % mod;
		b /= 2;
		a = (a * a) % mod; 
	}
	return r;
}
int64_t C(int64_t n, int64_t k) {
	if(n < k) return 0LL;
	return (fact[n] * pw((fact[n - k] * fact[k]) % mod, mod - 2)) % mod;
}

int32_t main() {
    int t;
    cin >> t;

    fact[0] = 1;

    for (ll i = 1; i<N; ++i) {
        fact[i] = fact[i-1]*i%mod;
    }

    while (t--) {
        int n, k;
        cin >> n >> k;

        int ones = 0;

        for (int i = 0; i<n; ++i) {
            int nn;
            cin >> nn;

            ones += nn;
        }

        ll res = 0;

        for (int one_c = (k+1)/2; one_c<=min(k, ones); ++one_c) {
            res += C(ones, one_c) * C(n-ones, k-one_c) % mod;
            res %= mod;
        }

        cout << res << '\n';
    }

    return 0;
}
