#include <bits/stdc++.h>

using ll=long long;
using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;

    while (t--) {
        ll n, k;
        cin >> n >> k;

        ll seg = 1;

        ll lastSeg = 0;
        ll res = 0;
        ll lastRes = 0;
        for (ll i = n; i>=1 && i>=k; i /= 2) {
            if (i % 2) {
                res += lastRes + ((i)/2 + 1) * seg;
                lastRes += lastRes + ((i)/2 + 1)*(seg);
            } else {
                lastRes += lastRes + ((i)/2)*(seg);
            }
            seg *= 2;
        }

        //cout << seg << endl;
        cout << res << '\n';
    }

    return 0;
}
/*
if (lastSeg == 0) {
    res = lastRes + (i/2+1)*(seg);
} else { 
    res += res * (lastSeg * seg/2) + (i/2+1)*(seg) + (i)*(seg/lastSeg/2-1)*(seg/lastSeg/2);
}
cout << i << ' ' << seg << ' ' << lastSeg << ' ' << res << endl;
lastSeg = seg;
*/
