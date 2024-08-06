#include <bits/stdc++.h>

using ll=long long;
using namespace std;

 
ll log_b3(ll a)
{
    return log2(a) / log2(3);
}

int32_t main() {
    int t;
    cin >> t;

    while (t--) {
        ll l, r;
        cin >> l >> r;

        ll res = 0;

        res += log_b3(l) + 1;
        res += log_b3(l+1) + 1 + res;

        ll last_elem = l+1;
        res += (1+log_b3(last_elem))*(min(r, (ll)(pow(3, log_b3(last_elem)+1))-1) - last_elem);
        //last_elem = (ll)(pow(3, log_b3(last_elem)+1))-1;
        for (ll i = (ll)(log_b3(last_elem)) + 1; i<=(ll)(log_b3(r)); ++i) {
            res += (i+1)*(min((ll)(pow(3, i+1))-1, r)+1-(ll)(pow(3, i)));
            //cout << (i+1)*(min((ll)(pow(3, i+1))-1, r)+1-(ll)(pow(3, i))) << endl;
        }

        cout << res << endl;

    }

    return 0;
}
