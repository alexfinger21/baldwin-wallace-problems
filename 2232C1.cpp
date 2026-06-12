#include <bits/stdc++.h>

using ll=long long;
using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;

    while (t--) {
        ll n, x, s;
        string mem;

        cin >> n >> x >> s;
        cin >> mem;

        pair<ll, ll> dp_x{0, x};
        pair<ll, ll> dp_y{0, x};

        for (int i = 0; i<n; ++i) {
            if (mem[i] == 'I') {
                if (dp_x.second > 0) {
                    --dp_x.second;
                    dp_x.first += s - 1;
                }

                if (dp_y.second > 0) {
                    --dp_y.second;
                    dp_y.first += s - 1;
                }
            }

            if (mem[i] == 'E') {
                if (dp_x.first > 0) {
                    --dp_x.first;
                }

                if (dp_y.first > 0) {
                    --dp_y.first;
                }
            }

            if (mem[i] == 'A') {
                if (((x - dp_x.second) * s - dp_x.first) > ((x - dp_y.second) * s - dp_y.first)) {
                    if (dp_x.second > 0) {
                        dp_y = dp_x;
                    }
                } else if (((x - dp_x.second) * s - dp_x.first) < ((x - dp_y.second) * s - dp_y.first)) {
                    if (dp_y.first > 0) {
                        dp_x = dp_y;
                    }
                }

                if (dp_x.first > 0) {
                    --dp_x.first;
                }

                if (dp_y.second > 0) {
                    --dp_y.second;
                    dp_y.first += s - 1;
                }
            }

            /*
            cout << dp_y.first << ' ' << dp_y.second << endl;
            cout << dp_x.first << ' ' << dp_x.second << endl;
            cout << "---\n";
            */
        }

        cout << max(x * s - (dp_x.first + dp_x.second * s), x * s - (dp_y.first + dp_y.second * s)) << '\n';
    }

    return 0;
}
