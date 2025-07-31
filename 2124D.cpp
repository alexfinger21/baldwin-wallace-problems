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
        vector<ll> a(n);
        vector<ll> a_c(n);
        unordered_map<ll, ll> cnts;

        for (int i = 0; i<n; ++i) {
            cin >> a[i];    
            a_c[i] = a[i];

        }

        if (k == 1) {
            cout << "YES\n";
            continue;
        }
        
        sort(a_c.begin(), a_c.end());

        ll sml = a_c[k-1];
        int i;
        for (i = 0; i<n; ++i) {
            if (a_c[i] > sml) {
                break;
            }
            cnts[a_c[i]] = i+1;
        }

        vector<ll> b(i);
        int d = 0;
        for (auto x : a) {
            if (x <= sml) {
                b[d] = x;
                ++d;
            }
        }

        int s = 0, e = i-1;
        int l = i;
        int res = 1;

        while (s < e) {
            if (b[s] == b[e]) {
                ++s;
                --e;
            } else if (b[s] == sml && cnts[sml] >= k) {
                ++s;
                --cnts[sml];
                --l;
            } else if (b[e] == sml && cnts[sml] >= k) {
                --e;
                --cnts[sml];
                --l;
            } else {
                res = 0;
                break;
            }
        }

        if (res && l >= k-1) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}
