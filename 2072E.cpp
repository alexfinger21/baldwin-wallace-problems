#include <bits/stdc++.h>

using ll=long long;
using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;

    while (t--) {
        int k;
        cin >> k;

        if (k == 0) {
            cout << "0\n";
            continue;
        }

        vector<pair<int, int>> coords;

        ll x = 0;
        ll y = 0;
        
        while (k) {
            ll elem = sqrt(k*2)-1;
            if (elem < 1) {
                elem = 1;
            }
            //cout << "k: " << k << ' ' << (elem*(elem+1))/2 << endl;

            k -= (elem*(elem+1))/2;

            ll bound = elem+x;
            if (x != 0 && k > 0) {
                --bound;
                --x;
                --k;
            }

            for (ll i=x; i<=bound; ++i) {
                coords.push_back(make_pair(i, y));
                ++x;
            }
            ++y;
        }

        cout << coords.size() << '\n';

        for (auto x : coords) {
            cout << x.first << ' ' << x.second << '\n';
        }
    }

    return 0;
}
