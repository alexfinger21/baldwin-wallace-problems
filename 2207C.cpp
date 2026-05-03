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

        vector<ll> drains(1);
        vector<ll> min_h(1);
        vector<ll> max_h(1);

        for (int i = 0; i<n; ++i) {
            ll new_h;
            cin >> new_h;

            ll added_h = h;

            cout << i << "---" << endl;

            for (int j = 0; j<drains.size(); ++j) {
                if (new_h >= max_h[j]) {
                    drains[j] += added_h-new_h;
                    
                    if (!min_h[j] && new_h != max_h[j]) {
                        min_h[j] = max_h[j];
                    }

                    max_h[j] = new_h;
                    added_h = new_h;

                    // break;
                } else {
                    if (!min_h[j]) {
                        max_h[j] = new_h;
                    } else {
                        drains[j] += max(0LL, added_h - max_h[j]);

                        added_h = min(added_h, max_h[j]);
                    }
                }

                cout << j << ' ' << drains[j] << endl;
            }

            if (added_h != new_h) {
                drains.push_back(0);
                max_h.push_back(0);
                min_h.push_back(0);

                int j = drains.size() - 1;

                drains[j] += added_h-new_h;
                
                if (!min_h[j] && new_h != max_h[j]) {
                    min_h[j] = max_h[j];
                }

                max_h[j] = new_h;

                cout << "new " << j << ' ' << drains[j] << endl;
            }
        }

        sort(drains.begin(), drains.end());

        cout << (drains[drains.size() - 1] + drains[max(int(drains.size()) - 2, 0)]) << '\n';
    }

    return 0;
}
