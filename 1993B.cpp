#include <bits/stdc++.h>

using ll=long long;
using namespace std;

int32_t main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        ll maxa = 0, even = 0, biggestOdd = 0;
        bool isOdd = false;

        priority_queue <int, vector<int>, greater<int>> pq;

        for (int i = 0; i<n; ++i) {
            ll num;
            cin >> num;

            if (maxa < num) {
                maxa = num;
            }

            if (!(num % 2)) {
                ++even;
                pq.push(num);
            } else {
                isOdd = true;
                if (num > biggestOdd) {
                    biggestOdd = num;
                }
            }

        }

        if (!isOdd) {
            cout << "0\n";
        } else {
            if (!(maxa % 2)) {
                int s = biggestOdd;

                while (s < maxa && !pq.empty()) {
                    if (s > pq.top()) {
                        s += pq.top();
                        pq.pop();
                    } else {
                        break;
                    }
                }

                if (s < maxa) {
                    ++even;
                }
            }
            cout << even << '\n';
        }
    }

    return 0;
}
