#include <bits/stdc++.h>

using ll=long long;
using namespace std;

int32_t main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        stack<int> open;
        char chars[n];

        for (int i = 0; i<n; ++i) {
            char c;
            cin >> c;

            chars[i] = c;
        }

        int res = 0;

        for (int i = 0; i<n; ++i) {
            if (!(i % 2)) {
                if (!open.empty() && open.top() < i) {
                    int j = open.top();
                    open.pop();
                    res += i - j;
                } else {
                    open.push(i);
                }
            } else if (chars[i] == ')') {
                if (!open.empty() && open.top() < i) {
                    int j = open.top();
                    open.pop();
                    res += i - j;
                }
            } else {
                open.push(i);
            }

        }

        cout << res << '\n';

    }

    return 0;
}
