#include <bits/stdc++.h>

using ll=long long;
using namespace std;


bool sort_f(pair<ll, ll> &p1, pair<ll, ll> &p2) {
    ll p1min = min(p1.first, p1.second);
    ll p1max = max(p1.first, p1.second);
    ll p2min = min(p2.first, p2.second);
    ll p2max = max(p2.first, p2.second);

    //cout << p1max << ' ' << p2max << '\n';
    if (p1max == p2max) {
        return p1min < p2min;
    } else {
        return p1max < p2max;
    }
 }

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<pair<ll, ll>> arrs(n);

        for (int i = 0; i<n; ++i) {
            ll n1, n2;
            cin >> n1 >> n2;

            arrs[i] = make_pair(n1, n2);
        }

        //sort(arrs.begin(), arrs.end(), sort_m);
        sort(arrs.begin(), arrs.end(), sort_f);

        /*
        if (4368 - t == 53) {
            for (auto x : arrs) {
                cout << x.first << '_' << x.second << '_';
            }
        }
        */

        for (auto x : arrs) {
            cout << x.first << ' ' << x.second << ' ';
        }
        cout << '\n';

    }

    return 0;
}
