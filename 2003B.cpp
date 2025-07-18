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

        priority_queue <int, vector<int>, greater<int>> pq;

        for (int i = 0; i<n; ++i) {
            int nm;
            cin >> nm;

            pq.push(nm);
        }

        int i = 0;

        while (i < n/2) {
            pq.pop();
            ++i;
        }


        cout << pq.top() << '\n';
    }

    return 0;
}
