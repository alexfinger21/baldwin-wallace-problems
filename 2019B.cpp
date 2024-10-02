#include <bits/stdc++.h>

using ll=long long;
using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;

    while (t--) {
        ll n, q;
        cin >> n >> q;

        vector<ll> x(n);
        map<ll, ll> mapa;


        for (size_t i = 0; i<n; ++i) {
            cin >> x[i];
        }

        for (size_t i = 0; i<n; ++i) {
            if (i != 0 && i != n-1) {
                if (!mapa.count((i+1) * (n-i-1))) {
                    mapa[(i+1) * (n-i-1)] = x[i+1] - x[i] - 1;
                } else {
                    mapa[(i+1) * (n-i-1)] += x[i+1] - x[i] - 1;
                } 
                  
                if (!mapa.count((i+1) * (n-i) - 1)) {
                    mapa[(i+1) * (n-i) - 1] = 1;
                } else {
                    mapa[(i+1) * (n-i) - 1] += 1;
                } 
            } else {
               if (i == 0) {
                if (!mapa.count(n-1)) {
                    mapa[n-1] = x[i+1] - x[i];
                } else {
                    mapa[n-1] += x[i+1] - x[i];
                } 
               } else {
                if (!mapa.count(n-1)) {
                    mapa[n-1] = 1;
                } else {
                    mapa[n-1] += 1;
                } 
               } 
            }
        }

        for (size_t i = 0; i<q; ++i) {
            ll k;
            cin >> k;

            if (mapa.count(k)) {
                cout << mapa[k] << ' ';
            } else {
                cout << "0 ";
            }
        }

        cout << '\n';

    }

    return 0;
}
