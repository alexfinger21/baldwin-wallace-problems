#include <bits/stdc++.h>

using ll=long long;
using namespace std;

int32_t main() {
    int t;
    cin >> t;

    while (t--) {
        ll n;
        cin >> n;

        ll k;
        cin >> k;

        vector<ll> lights(n);

        for (int i = 0; i<n; ++i) {
            cin >> lights[i];
        }

        int maxLight = lights[0];

        for (auto x : lights) {
            if (x > maxLight) {
                maxLight = x;
            }
        }

        bool never = false;

        for (int i = 0; i<n; ++i) {
            lights[i] = maxLight - lights[i];

            if ((lights[i] / k) % 2 == 0) {
                lights[i] = lights[i] % k;
            } else {
                if (lights[i] % k == 0) {
                    never = true;
                    break;
                } else {
                    lights[i] = lights[i] % k - k;
                }
            }
        }

        if (!never) {
            bool found = false;
            for (int i = 0; i<k; ++i) {
                bool neg = false;
                for (auto x : lights) {
                    if (x + i < 0 || ((x + i) >= k)) {
                        neg = true;
                        break;
                    }
                }

                if (!neg) {
                    cout << maxLight + i << '\n';
                    found = true;
                    break;
                }
            }

            if (!found) {
                cout << "-1\n";
            }
        } else {
            cout << "-1\n";
        }
    }

    return 0;
}
