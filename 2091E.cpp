#include <bits/stdc++.h>

using ll=long long;
using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;

    vector<ll> primes;
    vector<ll> p_s(1e7 + 1); 
    for (ll i = 2; i<=1e7; ++i) {
        if (!p_s[i]) {
            primes.push_back(i);
            //cout << i << endl;
            for (ll j = i*i; j<=1e7; j+=i) {
                p_s[j] = i;
            }
        }
    }

    while (t--) {
        ll n;
        cin >> n;

        ll prim = upper_bound(primes.begin(), primes.end(), n) - primes.begin();

        ll res = prim;
        //cout << prim << endl;

        for (int i = 2; i<n; ++i) {
            while ((primes[prim-1] * i) > n && prim > 0) {
                --prim;
            }
            if (prim == 0) {
                break;
            }
            //cout << prim << endl;
            res += prim;
        }
        
        cout << res << '\n';
    }

    return 0;
}
