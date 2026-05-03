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
        
        vector<pair<ll, ll>> rng;
        ll sm = 0;

        vector<ll> heights(n);

        for (int i = 0; i<n; ++i) {
            cin >> heights[i];

            int new_i = i;

            while (!rng.empty() && rng.back().first < heights[i]) {
                pair<ll, ll> last_h = rng.back();
                rng.pop_back();

                if (!rng.empty()) {
                    sm -= (h - last_h.first) * (new_i - rng.back().second - 1);
                    sm += (h - heights[i]) * (new_i - rng.back().second - 1);

                    new_i = last_h.second;
                } else {
                    sm -= (h - last_h.first) * (new_i);
                    sm += (h - heights[i]) * (new_i);
                }
            }

            sm += h - heights[i];
            dp_l[i] = sm;

            rng.emplace_back(heights[i], i);

            cout << dp_l[i] << endl;
        }

        rng.clear();
        sm = 0;

        for (int i = n-1; i>=0; --i) {
            int new_i = i;

            while (!rng.empty() && rng.back().first < heights[i]) {
                pair<ll, ll> last_h = rng.back();
                rng.pop_back();

                if (!rng.empty()) {
                    sm -= (h - last_h.first) * (rng.back().second - new_i - 1);
                    sm += (h - heights[i]) * (rng.back().second - new_i - 1);

                    new_i = last_h.second;
                } else {
                    cout << "sum: " << sm << endl;
                    sm -= (h - last_h.first) * (n-new_i-1);
                    sm += (h - heights[i]) * (n-new_i-1);

                    cout << "add: " << (h - heights[i]) * (n-new_i-1) << endl;
                }
            }

            sm += h - heights[i];
            dp_r[i] = sm;

            rng.emplace_back(heights[i], i);

            cout << dp_r[i] << endl;
        }

    }

    return 0;
}
