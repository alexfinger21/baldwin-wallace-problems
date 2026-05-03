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

    }

    return 0;
}
