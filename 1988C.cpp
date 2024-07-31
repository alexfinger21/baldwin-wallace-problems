#include <bits/stdc++.h>

using ll=long long;
using namespace std;

//basically the first number is one with a bit below the highest bit and anywhere else, and then the numbers progress moving the 0 bit 1 back because after the first number you can make the 2nd biggest bit 0
// and so on, then the 3rd bit, etc

int32_t main() {
    int t;
    cin >> t;

    while (t--) {
        ll n;
        cin >> n;

        vector<ll> bits;

        ll n2 = n;

        for (ll i = log2(n); i >= 0; --i) {
            if ((ll)(pow(2, i)) <= n2) {
                //cout << (ll)(pow(2, i)) << ' ' << i << endl;
                bits.push_back((ll)(pow(2, i)));
                n2 -= (ll)(pow(2, i));
            }
        }
        
        bits.push_back(0);

        bool first = false;

        cout << (bits.size() == 2 ? 1 : bits.size()) << '\n';

        for (ll i = 0; i<(bits.size() == 2 ? 1 : bits.size()); ++i) {
            if (!first) {
                cout << bits[bits.size() == 2 ? i : (i+1)] << ' ';
                first = true;
            } else {
                cout << (n-bits[i]) << ' ';
            }
        }

        cout << '\n';
    }

    return 0;
}
