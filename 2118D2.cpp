#include <bits/stdc++.h>

using ll=long long;
using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;

    while (t--) {
        ll m, k;
        cin >> m >> k;

        vector<ll> p(m+1), d(m+1);

        for (int i = 1; i<= m; ++i) {
            cin >> p[i];
        }

        for (int i = 1; i<= m; ++i) {
            cin >> d[i];
        }

        map<ll, vector<ll>> mpl, mpr;
        map<ll, ll> traffic;

        for (int i = 1; i<= m; ++i) {
           traffic[p[i]] = d[i];
           mpl[(d[i] + p[i]) % k].push_back(p[i]);
           mpr[(((d[i] - p[i]) % k) + k) % k].push_back(p[i]);
        }

        auto get_next_left = [&](ll pos, ll t) {
            ll val = (t + pos) % k;
            auto &vec = mpl[val];
            auto it = lower_bound(vec.begin(), vec.end(), pos);
            if (it == vec.begin()) return -1ll;
            --it;
            return *it;
        };

        auto get_next_right = [&](ll pos, ll t) {
            ll val = ((((t - pos) % k) + k) % k);
            auto &vec = mpr[val];
            auto it = lower_bound(vec.begin(), vec.end(), pos+1);
            if (it == vec.end()) return -1ll;
            return *it;
        };


        map<pair<ll, ll>, bool> dp;

        int q;
        cin >> q;

        for (int i = 0; i<q; ++i) {
            ll x;
            cin >> x;

            ll dir = 1, t = 0;

            set<pair<ll, ll>> states;

            bool ok = false;

            if (traffic.count(x) && traffic[x] == 0) {
                dir = !dir;
            }

            for (int j = 0; j<2*m; ++j) {
                ll y = dir ? get_next_right(x, t) : get_next_left(x, t);
                if (y == -1) {
                    ok = true;
                    break;
                } else {
                    t += abs(x-y);
                    x = y;
                    dir = !dir;
                }

                if (states.count({x, dir})) {
                    break;
                }

                states.insert({x, dir});

                if (dp.count({x, dir})) {
                    ok = dp[{x, dir}];
                    break;
                }
            }

            for (auto s : states) {
                dp[{s.first, s.second}] = ok;
            }

            cout << (ok ? "YES\n" : "NO\n");
        }
    }

    return 0;
}
