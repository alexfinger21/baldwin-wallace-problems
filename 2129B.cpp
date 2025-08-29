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

        vector<int> p(n);
        vector<int> bef, aft;

        for (int i = 0; i<n; ++i) {
            cin >> p[i];
            
            auto r = upper_bound(aft.begin(), aft.end(), p[i]);

            if (r == aft.end()) {
                aft.push_back(p[i]);
            } else {
                aft.insert(r, p[i]);
            }
        }

        ll res = 0;

        for (int i = 0; i<n; ++i) {
            /*
            for (auto x : aft) {
                cout << x << '-';
            }
            cout << endl;
            for (auto x : bef) {
                cout << x << '-';
            }
            cout << endl;
            */
            auto idx = upper_bound(aft.begin(), aft.end(), p[i]-1);
            auto idx2 = upper_bound(bef.begin(), bef.end(), p[i]);
            int cnt = idx-aft.begin();
            int cnt2 = bef.end()-idx2;
            int c = 2*n-p[i];
            auto idx3 = upper_bound(aft.begin(), aft.end(), c-1) - (c != p[i] ? 1 : 0);
            auto idx4 = upper_bound(bef.begin(), bef.end(), c);
            int cnt3 = idx3-aft.begin();
            int cnt4 = bef.end()-idx4;

            if ((cnt4+cnt3) < (cnt+cnt2)) {
                res += (cnt4-cnt2);
                res += (cnt3);
                bef.insert(idx4, c);
                aft.erase(idx);
                //cout << "case 1" << endl;
            } else {
                res += cnt;
                bef.insert(idx2, p[i]);
                aft.erase(idx);
                //cout << "case 0" << endl;
            }
            //cout << cnt << ' ' << cnt2 << ' ' << cnt3 << ' ' << cnt4 << ' ' << res << endl;
        }

        cout << res << '\n';
    }

    return 0;
}
