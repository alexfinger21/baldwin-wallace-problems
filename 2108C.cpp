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
        cin >> n;
        vector<ll> a(n);

        for (int i = 0; i<n; ++i) {
            cin >> a[i];
        }

        set<ll> ss;

        for (int i = 0; i<n; ++i) {
            ss.insert(a[i]);
        }

        map<ll, vector<ll>> locs;
        int cnt = 0;

        for (int i = 0; i<n; ++i) {
            if (!locs.count(a[i])) {
                locs[a[i]] = vector<ll>();
            }
            locs[a[i]].push_back(i);
        }

        auto ptr = --ss.end();
        int res = 0;

        for (int i = ss.size() - 1; i>=0; --i) {
            int prev = -1;
            for (auto x : locs[*ptr]) {
                if (x > 0 && a[x-1] == -1) {
                    a[x] = -1;
                }
                if (x < n-1 && a[x+1] == -1) {
                    a[x] = -1;
                }

                if (a[x] != -1 && !(x < n - 1 && a[x+1] == a[x])) {
                    ++res;
                    a[x] = -1;
                } else if (a[x] != -1) {
                    a[x] = -2;
                }
                if (prev != -1) {
                    a[prev] = -1;
                }
                prev = x;
            }
            --ptr;
        }


        cout << max(1, res) << '\n';
    }

    return 0;
}
