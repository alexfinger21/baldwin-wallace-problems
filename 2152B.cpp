#include <bits/stdc++.h>

using ll=long long;
using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;

    while (t--) {
        ll n, rk, ck, rd, cd;
        cin >> n >> rk >> ck >> rd >> cd;
        ll hdiff = rk - rd, xdiff = ck - cd;

        //cout << xdiff << ' ' << hdiff << endl;

        if (abs(xdiff) == 1 && !hdiff) {
            hdiff = 1;
        } else if (hdiff) {
            if (hdiff > 0) {
                hdiff = n-rd;
            } else {
                hdiff = rd;
            }
        } else {
            hdiff = 1;
        }

        if (abs(hdiff) == 1 && !xdiff) {
            xdiff = 1;
        } else if (xdiff) {
            if (xdiff > 0) {
                xdiff = n-cd;
            } else {
                xdiff = cd; 
            }
        } else {
            xdiff = 1;
        }
        //cout << xdiff << ' ' << hdiff << endl;

        cout << max(xdiff, hdiff) << '\n';
    }

    return 0;
}
