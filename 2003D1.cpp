#include <bits/stdc++.h>

using ll=long long;
using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;

    while (t--) {
        ll n, m;
        cin >> n >> m;

        ll biggests = 0;
        
        for (int i = 0; i<n; ++i) {
            int l;
            cin >> l;

            set<int> nums;

            for (int j = 0; j<l; ++j) {
                int nm;
                cin >> nm;

                nums.insert(nm);
            }

            ll f = -1, s = -1;
            int last = -1;

            for (auto x : nums) {
                if (x - last > 2) {
                    if (f == -1) {
                        f = last + 1;
                        s = last + 2;
                    } else {
                        s = last + 1;
                    }
                    break;
                } else if (x - last == 2) {
                    if (f == -1) {
                        f = last + 1;
                    } else {
                        s = last + 1;
                        break;
                    }
                }

                last = x;
            }

            if (f == -1) {
                f = last + 1;
                s = last + 2;
            }

            if (s == -1) {
                s = last + 1;
            }

            biggests = max(biggests, s);
        }

        ll res = 0;

        res += min(biggests+1, m+1) * biggests;

        if (biggests+1 <= m) {
            res += (biggests+1+m)*(m-biggests)/2;
        }

        cout << res << '\n';
    }

    return 0;
}
