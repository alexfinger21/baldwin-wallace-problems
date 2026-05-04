#include <bits/stdc++.h>

using ll=long long;
using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;

    while (t--) {
        ll n, h;

        cin >> n >> h;

        vector<ll> dp_l(n);
        vector<ll> dp_r(n);
        
        vector<ll> rng;

        vector<ll> heights(n);
        vector<ll> possible_drains;

        for (int i = 0; i<n; ++i) {
            cin >> heights[i];

            while (!rng.empty() && heights[rng.back()] < heights[i]) {
                rng.pop_back();
            }

            if ((rng.empty() && i > 0) || (i - rng.back() > 0)) {
                possible_drains.push_back(i-1);
            }

            dp_l[i] = (i - (!rng.empty() ? rng.back() : -1)) * (h - heights[i]) 
                + (!rng.empty() ? dp_l[rng.back()] : 0);

            rng.push_back(i);

            cout << dp_l[i] << endl;
        }

        rng.clear();

        for (int i = n-1; i>=0; --i) {
            while (!rng.empty() && heights[rng.back()] < heights[i]) {
                rng.pop_back();
            }

            dp_r[i] = ((!rng.empty() ? rng.back() : n) - i) * (h - heights[i])
                + (!rng.empty() ? dp_r[rng.back()] : 0);

            rng.emplace_back(i);

            cout << dp_r[i] << endl;
        }


        ll res = max(dp_l[n-1], dp_r[0]);

        for (int i = 0; i<n; ++i) {
            ll max_idx = -1;
            ll max_cost = 0;

            if (i == 1 || i == n-2) {
                res = max(res, dp_l[i-1] + dp_r[i]);
            }
            
            for (int j = i+2; j<n; ++j) {
                
            }
        }

    }

    return 0;
}
