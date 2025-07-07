#include <bits/stdc++.h>

using ll=long long;
using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);

    int n, x;
    cin >> n >> x;

    vector<int> c(n);

    for (int i = 0; i<n; ++i) {
        int b;
        cin >> b;

        c[i] = b * (n - i);
    }

    sort(c.begin(), c.end());

    int s = 0;
    int res = 0;
    for (int i = 0; i<n; ++i) {
        s += c[i];
        if (s <= x) {
            ++res;
        }
    }

    cout << res << endl;

    return 0;
}
