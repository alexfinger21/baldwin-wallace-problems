#include <bits/stdc++.h>

using ll=long long;
using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;

    while (t--) {
        ll n, x;

        cin >> n >> x;

        map<ll, ll> rem;
        priority_queue <ll, vector<ll>, greater<ll>> pq;

        for (int i = 0; i<n; ++i) {
            ll nm;
            cin >> nm;

            pq.push(nm);
        }
        
        while (!pq.empty()) {
            ll top = pq.top();
            ll rm = top%x;

            //cout << top << ' ' << rem[rm] << endl;

            if (((rem.count(rm) ? rem[rm] : 0) * x + rm) >= top) {
                if (rem.count(rm)) {
                    ++rem[rm];
                } else {
                    rem[rm] = 1;
                }
            }
            pq.pop(); 
        }

        ll midx = 0;
        for (int i = 1; i<x; ++i) {
            ll current = rem.count(i) ? rem[i] : 0;
            if (rem[midx] > current) {
                midx = i;
            }

            if (current == 0) {
                break;
            }
        }
        //cout << midx << ' ' << rem[midx] << endl;

        if (rem.count(midx)) {
            cout << (rem[midx] * x + midx) << '\n';
        } else {
            cout << midx << '\n';
        }
    }

    return 0;
}
