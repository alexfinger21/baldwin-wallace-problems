#include <bits/stdc++.h>

using ll=long long;
using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;

    while (t--) {
        int n;
        ll ax, ay, bx, by;

        cin >> n >> ax >> ay >> bx >> by;

        map<ll, set<ll>> paths;
        vector<ll> x_arr(n+1);

        map<ll, ll> gaps_min;
        map<ll, ll> gaps_max;

        for (int i = 0; i<n; ++i) {
            ll x;
            cin >> x;

            x_arr[i] = x;
        }

        x_arr[n] = bx;

        for (int i = 0; i<n; ++i) {
            ll y;
            cin >> y;

            paths[x_arr[i]].insert(y);

            if (!gaps_min.count(x_arr[i])) {
                gaps_min[x_arr[i]] = 1e9+1;
            }

            gaps_min[x_arr[i]] = min(gaps_min[x_arr[i]], y);
            gaps_max[x_arr[i]] = max(gaps_max[x_arr[i]], y);
        }

        paths[bx].insert(by);

        if (!gaps_min.count(bx)) {
            gaps_min[bx] = 1e9+1;
        }

        gaps_min[bx] = min(gaps_min[bx], by);
        gaps_max[bx] = max(gaps_max[bx], by);

        paths[ax].insert(ay);

        ll best_y = ay;
        ll dp_res = 0;
        ll cnt = -1;
        ll last_x = ax;

        if (gaps_min.count(ax)) {
            ll y_min = ay;
            ll y_max = ay;

            for (auto y : paths[ax]) {
                y_min = min(y_min, y);
                y_max = max(y_max, y);
            } 


            for (auto y : paths[ax]) {
                if (y > ay) {
                    ll res = (ay-y_min) * 2 + (y_max - y) * 2 + y - ay;
                    if (cnt == -1 || res < cnt) {
                        cnt = res;
                        best_y = y;
                    }
                } else {
                    ll res = (y - y_min) * 2 + (y_max - ay) * 2 + ay - y;
                    if (cnt == -1 || res < cnt) {
                        cnt = res;
                        best_y = y;
                    }
                } 
            }

        }

        if (cnt > 0) {
            cout << cnt << endl;
            dp_res += cnt;
        }

        for (auto x : paths) {
            if (last_x == x.first) {
                continue;
            } 
            dp_res += x.first - last_x;

            ll cnt = -1;
            ll y_min = gaps_min[x.first];
            ll y_max = gaps_max[x.first];
            ll y_c = y_min;
            if (y_min > best_y) {
                dp_res += y_min - best_y;
                best_y = y_min;
            } else if (y_max < best_y) {
                dp_res += best_y - y_max;
                best_y = y_max;
            }
            cout << "best y: " << best_y << endl;
            cout << "y_min " << y_min << endl;
            cout << "y_max " << y_max << endl;

            for (auto y : x.second) {
                if (y > best_y) {
                    ll res = (best_y-y_min) * 2 + (y_max - y) * 2 + y - best_y;
                    if (cnt == -1 || res < cnt) {
                        cout << "result from max: " << res << endl;
                        cnt = res;
                        y_c = y;
                    }
                } else {
                    ll res = (y - y_min) * 2 + (y_max - best_y) * 2 + best_y - y;
                    if (cnt == -1 || res < cnt) {
                        cnt = res;
                        y_c = y;
                    }
                } 
            }
            cout << cnt << endl;
            cout << x.first - last_x << endl;

            cout << dp_res << endl;
            cout << "------------" << endl;
            last_x = x.first;
            dp_res += cnt;
            best_y = y_c;
            cout << dp_res << endl;
        }

        cout << dp_res << endl;
    }

    return 0;
}
