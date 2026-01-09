#include <bits/stdc++.h>

using ll=long long;
using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;
        priority_queue<ll> alice;
        priority_queue<ll> bob;

        for (int i = 0; i<n; ++i) {
            ll num;
            cin >> num;
            alice.push(num);
        }

        for (int i = 0; i<m; ++i) {
            ll num;
            cin >> num;
            bob.push(num);
        }

        int cnt = 0;
        while (bob.size() && alice.size()) {
            ll a_top = alice.top();
            ll b_top = bob.top();

            if (cnt % 2) {
                alice.pop();

                if (b_top < a_top) {
                    alice.push(a_top - b_top);
                }
            } else {
                bob.pop();

                if (b_top > a_top) {
                    bob.push(b_top - a_top);
                }
            }
            ++cnt;
        }

        if (bob.size()) {
            cout << "Bob\n";
        } else {
            cout << "Alice\n";
        }
    }

    return 0;
}
