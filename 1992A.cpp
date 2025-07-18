#include <bits/stdc++.h>

using namespace std;

int32_t main() {
    int t;
    cin >> t;

    while (t--) {
        int a, b, c;
        cin >> a >> b >> c;

        priority_queue <int, vector<int>, greater<int>> mq;

        mq.push(a);
        mq.push(b);
        mq.push(c);

        for (int i = 0; i<5; ++i) {
            int t = mq.top() + 1;
            mq.pop();
            mq.push(t);
        }

        int res = 1;

        for (int i = 0; i<3; ++i) {
            res *= mq.top();
            mq.pop();
        }

        cout << res << '\n';
    }

    return 0;
}
