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

    map<ll, ll> divs;
    map<ll, ll> totl;

    divs[1] = 1;
    totl[1] = 1;

    ll res = 1;

    for (int i = 1; i<n; ++i) {
       for (int j = 2; j<=n, j<=i+1; ++j) {
            if (divs.count(j-1)) {
                if (!(a[i] % j)) {
                    //cout << "whats up sigmas" << endl;
                    if (!divs.count(j)) {
                        divs[j] = 1;
                    } else {
                        divs[j] += 1;
                    }
                    if (!totl.count(j)) {
                        totl[j] = 0;
                    }
                    totl[j] = (totl[j] + (totl[j-1])) % mod;
                    cout << a[i] << ' ' << j << ' ' << divs[j] << ' ' << totl[j-1] << ' ' << totl[j] << endl;
                    res = (res + totl[j-1]) % mod;
                }
            } else {
                break;
            }
       } 
       totl[1] += 1;
       divs[1] += 1;
       res = (res + 1) % mod;
    }

    cout << res << '\n';

    return 0;
}
