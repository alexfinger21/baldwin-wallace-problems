#include <bits/stdc++.h>

using ll=long long;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        unordered_map<int, ll> cs;

        for (int i = 0; i<k; ++i) {
            int b, c;
            cin >> b >> c;

            if (!cs.count(b)) {
                cs[b] = c;
            } else {
                cs[b] += c;
            }
        }

        priority_queue<ll> pq;
        for (auto x : cs) {
            pq.push(x.second);
        }
        int i = 0;
        ll r = 0;
        while (i < n && !(pq.empty())) {
            r += pq.top();
            ++i;
            pq.pop();
        }

        cout << r << '\n';
        
    }
}
