#include <bits/stdc++.h>

using ll=long long;
using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;

    while (t--) {
        ll n;
        cin >> n;
        vector<ll> a(n);

        ll midx = 0;

        for (ll i = 0; i<n; ++i) {
            cin >> a[i];

            if (abs(a[i]) != 1) {
                midx = i;
            }
        }

        ll mn0 = 0;
        ll mx0 = 0;

        ll smn = 0LL;
        ll smx = 0LL;
        for (ll i = 0LL; i<midx; ++i) {
            smn = min(0LL, smn += a[i]);
            mn0 = min(mn0, smn);
            smx = max(0LL, smx += a[i]);
            mx0 = max(mx0, smx);
        }

        ll mn1 = 0LL;
        ll mx1 = 0LL;

        smn = 0LL;
        smx = 0LL;
        for (ll i = n-1; i>midx; --i) {
            smn = min(0LL, smn += a[i]);
            mn1 = min(mn1, smn);
            smx = max(0LL, smx += a[i]);
            mx1 = max(mx1, smx);
        }

        ll minfromL = 0LL;
        ll maxfromL = 0LL;
        ll minfromR = 0LL;
        ll maxfromR = 0LL;

        smn = 0LL;
        smx = 0LL;
        for (ll i = midx-1; i>=0LL; --i) {
            smn += a[i];
            minfromL = min(minfromL, smn);
            smx += a[i];
            maxfromL = max(maxfromL, smx);
        }

        smn = 0LL;
        smx = 0LL;
        for (ll i = midx+1; i<n; ++i) {
            smn += a[i];
            minfromR = min(minfromR, smn);
            smx += a[i];
            maxfromR = max(maxfromR, smx);
        }

        vector<ll> res;
        res.reserve(n);
        //cout << min(mn0, mn1) << ' ' << max(mx0, mx1) << endl;
        //cout << minfromL << ' ' << minfromR << endl;
        //cout << maxfromL << ' ' << maxfromR << endl;

        if (min(mn0, mn1) <= minfromL + minfromR + a[midx]) {
            for (ll i = min(mn0, mn1); i<=max(mx0, mx1); ++i) {
                res.push_back(i);
            }

            for (ll i = max(minfromL + minfromR + a[midx], max(mx0, mx1) + 1); i<=a[midx] + maxfromL + maxfromR; ++i) {
                res.push_back(i);
            } 
        } else {
            for (ll i =  minfromL + minfromR + a[midx]; i<=a[midx] + maxfromL + maxfromR; ++i) {
                res.push_back(i);
            } 
            for (ll i = max(a[midx] + maxfromL + maxfromR+1, min(mn0, mn1)); i<=max(mx0, mx1); ++i) {
                res.push_back(i);
            }
        }
        cout << res.size() << '\n';
        for (auto x : res) {
            cout << x << ' ';
        }

        cout << '\n';
    }

    return 0;
}
