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

        priority_queue<int> pq;

        ll mid = 0;
        for (int i = 0; i<n; ++i) {
            double a;
            cin >> a;
            mid += a;

            pq.push(a);
        }

        if (n < 3) {
            cout << "-1\n";
            continue;
        }

        ll avg = -1;
        ll top = -1;
        top = pq.top();
        pq.pop();
        if (n%2) {
            for (int i = 0; i<n/2; ++i) {
                avg = pq.top();
                pq.pop();
            }
        } else {
            for (int i = 0; i<n/2-1; ++i) {
                avg = pq.top();
                pq.pop();
            }
        }

        //cout << avg << ' ' << mid << '\n';

        ll res = avg*n*2-mid;
        cout << (res >= 0 ? res + 1 : 0) << '\n';
    }

    return 0;
}
