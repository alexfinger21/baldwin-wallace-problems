#include <bits/stdc++.h>

using ll=long long;
using namespace std;

//get the popcount (1s count) after the largest bit, if its 0 then only 1 combination, otherwise, the answer is the total popcount + 1
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
