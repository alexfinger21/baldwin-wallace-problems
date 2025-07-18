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

        ll l = 0, h = n+k-1;

        ll minn = -1;

        while (l < h) {
            ll mid = (l + h)/2;
            ll num = (1+mid)/2*(mid) - (n+k-1-mid+mid)*(n-mid);

            if (minn == -1) {
                minn = abs(num);
            } else {
                minn = min(minn, abs(num));
            }

            if (mid >= 0) {
                h = mid;
            } else {
                l = mid+1;
            }
        }

        cout << minn << '\n';
    }

    return 0;
}
