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

        for (int i = 0; i<n; ++i) {
            cin >> heights[i];

            while (!rng.empty() && heights[rng.back()] < heights[i]) {
                rng.pop_back();
            }

            dp_l[i] = (i - (!rng.empty() ? rng.back() : -1)) * (h - heights[i]) 
                + (!rng.empty() ? dp_l[rng.back()] : 0);

            rng.push_back(i);

            // cout << dp_l[i] << endl;
        }

        rng.clear();

        for (int i = n-1; i>=0; --i) {
            while (!rng.empty() && heights[rng.back()] < heights[i]) {
                rng.pop_back();
            }

            dp_r[i] = ((!rng.empty() ? rng.back() : n) - i) * (h - heights[i])
                + (!rng.empty() ? dp_r[rng.back()] : 0);

            rng.push_back(i);

            // cout << dp_r[i] << endl;
        }


        ll res = max(dp_l[n-1], dp_r[0]);
        // cout << "dp: " << res << endl;

        for (int i = 0; i<n; ++i) {
            heights[i] = h - heights[i];
        }

        for (int i = 0; i<n; ++i) {
            ll max_idx = i;
            ll max_cost = (max_idx < n) 
                ? (dp_l[max_idx] + dp_r[max_idx] - heights[max_idx]) 
                : 0;

            ll c1 = dp_l[i] + dp_r[i] - heights[i];
            // cout << c1 << endl;

            for (int j = i; j<n; ++j) {
                if (heights[max_idx] > heights[j]) {
                    max_idx = j;
                    
                    max_cost = dp_r[max_idx] + dp_l[max_idx] - heights[max_idx];
                }

                // cout << "cost: " << max_cost << endl;

                ll c2 = dp_l[j] + dp_r[j] - heights[j];

                res = max(res, c1 + c2 - max_cost);

                // cout << res << endl;
                // cout << c1 << ' ' << c2 << " idx: " << i << ' ' << j << endl;
            }
        }

        cout << res << '\n';

    }

    return 0;
}
