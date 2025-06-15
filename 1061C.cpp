#include <bits/stdc++.h>

using ll=long long;
using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin >> n;

    ll mod = 1e9+7; 

    vector<ll> a(n);

    for (int i = 0; i<n; ++i) {
        cin >> a[i];
    }

    vector<ll> totl(n+1);

    totl[0] = 1;
    totl[1] = 1;

    ll res = 1;

    for (int i = 1; i<n; ++i) {
      
       for (ll j = min((ll)sqrt(a[i]), n); j>=1; --j) {
            if (!(a[i] % j)) {
                if (a[i]/j <= n && a[i]/j != j) {
                    totl[a[i]/j] = (totl[a[i]/j] + (totl[a[i]/j-1])) % mod;
                    //cout << "val: " << a[i] << " divisor: " << a[i]/j << " current combs:" << totl[a[i]/j] << endl;
                    res = (res + totl[a[i]/j-1]) % mod;
                }
                totl[j] = (totl[j] + (totl[j-1])) % mod;
                //cout << "val: " << a[i] << " divisor: " << j << " prev combs:" << totl[j-1] << " current combs:" << totl[j] << endl;
                res = (res + totl[j-1]) % mod;
            }
       }
    }


    cout << res << '\n';

    return 0;
}
