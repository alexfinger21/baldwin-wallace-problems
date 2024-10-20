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

        ll l = k, h = k+n-1;

        while (l < h) {
            ll mid = (l+h) >> 1;

            ll pos = (k+mid-1)*(mid-k)/2;
            ll neg = (k+n-1+mid)*(k+n-mid)/2;
            ll lv = abs(pos-neg);
            //cout << pos << ' ' << neg << ' ' << lv << endl;
            
            pos = (k+mid)*(mid-k+1)/2;
            neg = (k+n+mid)*(k+n-mid-1)/2;
            ll mv = abs(pos-neg);
            //cout << pos << ' ' << neg << ' ' << mv << endl;

            pos = (k+mid+1)*(mid-k+2)/2;
            neg = (k+n+mid+1)*(k+n-mid-2)/2;
            ll hv = abs(pos-neg);
            //cout << pos << ' ' << neg << ' ' << hv << endl;

            if (mv <= lv && mv <= hv) {
                cout << mv << '\n';
                break;
            } else if (lv <= mv && lv <= hv) {
                h = mid;
            } else {
                l = mid;
            }
        }
    }

    return 0;
}
